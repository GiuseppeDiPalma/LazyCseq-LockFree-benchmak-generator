import subprocess
from os import SEEK_SET, getenvb

INSERT_TRACE_NAME = "insert_id="
DELETE_TRACE_NAME = "delete_s="
SAFE_TRACE_NAME = "VERIFICATION SUCCESSFUL"
   
def launch_lazy_cseq(input_file,output_dir,include_param,rounds):
   subprocess.call(["./cseq-feeder.py", "-i", f"{output_dir}/{input_file}","-I",include_param
   ,"--unwind","5","--cex","--debug", "--rounds", f"{rounds}"])
   
def generate_stack_state(state_list):
   data_structure = []
   for state in state_list:
     if state == "delete":
         if len(data_structure) == 0:
            continue
         del data_structure[len(data_structure)-1]
     else:
        data_structure.insert(len(data_structure),state)
   return data_structure


def generate_queue_state(state_list):
   data_structure = []
   for state in state_list:
      if state == "delete":
         if len(data_structure) == 0:
            continue
         del data_structure[len(data_structure)-1]
      else:
         data_structure.insert(0,state)
   return data_structure


def get_data_structure_state(pathname,data_structure_type):
   data_structure_states = []
   f = open(pathname)
   lines = [line.rstrip('\n') for line in f]
   #Iterate through the trace and find the lines in which there are pushes and pops
   for x in lines:
      if( INSERT_TRACE_NAME in x ):
         data_structure_states.append(x[x.index("=")+1:x.index("ull")])
      if( DELETE_TRACE_NAME in x ):
         data_structure_states.append("delete")
      if( SAFE_TRACE_NAME in x ):
         data_structure_states.append("SAFE")
         return data_structure_states
   f.close()
   
   if data_structure_type == "stack":
      return generate_stack_state(data_structure_states)
   elif data_structure_type == "queue":
      return generate_queue_state(data_structure_states)


#Function that appends a new assert to "checker.c"
def generate_assert_condition(data_structure):
   if(len(data_structure) == 0):
      return "(is_empty(ss))"
   
   i = 0
   condition = f"(size == {len(data_structure)}"
   for elem in data_structure:
      if(i == len(data_structure)-1):
         condition += f" && ids[{elem}]==1)"
      else:
         condition += f" && ids[{elem}]==1"
      i+=1
   return condition

def dump_structure(data_structure,max_num_elements):
   lines = ""
   lines += f"int ids[{max_num_elements}];\n"
   lines += f"int size = dump_structure(ss,{max_num_elements},ids);\n"
   return lines

#Create or expand the assert in checker.c
def create_assert(checker_name,data_structure,max_num_elements,output_dir):
   with open(f"{output_dir}/{checker_name}","r+") as checker:
      newfile_lines = ""
      lines = [line.rstrip('\n') for line in checker.readlines()]
      # contains_op = []
      for line in lines:
         if "assert(" in line:
            if "assert(0)" in line:
                  newfile_lines += dump_structure(data_structure,max_num_elements)
                  condition = generate_assert_condition(data_structure)
                  newfile_lines += f"assert({condition});\n"
            else:
               assert_closure_index = line.rindex(")") #penultimo character
               assert_condtions = line[:assert_closure_index]
               generated_condition = generate_assert_condition(data_structure)
               assert_condtions += f" || {generated_condition});\n"
               newfile_lines += assert_condtions
         else:
            newfile_lines += f"{line}\n"
         
         checker.seek(0,SEEK_SET)
         checker.truncate(0)
         checker.write(newfile_lines)


def is_safe(data_structure_state):
   return len(data_structure_state) > 0 and data_structure_state[0] == "SAFE"


def disable_atomic_operations(filename,output_dir):
   with open(f"{output_dir}/{filename}","r+") as file:
      lines = ""
      filelines = file.readlines()
      for line in filelines:
         if "int volatile ATOMIC_OPERATION" in line:
            lines += "int volatile ATOMIC_OPERATION = 0;\n"
         else:
            lines += line
      file.truncate(0)
      file.seek(0,SEEK_SET)
      file.write(lines)
   

def run_benchmark(filename,checker_name,output_dir,data_structure_type,include_params,max_num_elements,rounds): 

   # Capture all possible state of this configuration
   while True:
      launch_lazy_cseq(filename,output_dir,include_params,rounds)
      data_structure_state = get_data_structure_state(f"{output_dir}/_cs_{filename}.cbmc.log",data_structure_type)
      if is_safe(data_structure_state):
         break
      else:
         create_assert(checker_name,data_structure_state,max_num_elements,output_dir)
   
   # Test with lock-free behaviour
   disable_atomic_operations(filename,output_dir)
   launch_lazy_cseq(filename,output_dir,include_params,rounds)
   data_structure_state = get_data_structure_state(f"{output_dir}/_cs_{filename}.cbmc.log",data_structure_type)
   if is_safe(data_structure_state):
      return True
   else:
      return False
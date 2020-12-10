
# 1 "<previous_module>"
unsigned __CPROVER_bitvector[1] __cs_active_thread[3] = {1};

# 2 "<previous_module>"
unsigned __CPROVER_bitvector[10] __cs_pc[3];

# 3 "<previous_module>"
unsigned __CPROVER_bitvector[11] __cs_pc_cs[3];

# 4 "<previous_module>"
unsigned __CPROVER_bitvector[2] __cs_last_thread;

# 5 "<previous_module>"
unsigned __CPROVER_bitvector[10] __cs_thread_lines[3] = {623, 122, 156};

# 7 "<previous_module>"
void *__cs_safe_malloc(unsigned int __cs_size)
{
        
# 8 "<previous_module>"
void *__cs_ptr = (malloc(__cs_size));
        
# 9 "<previous_module>"
return __cs_ptr;
}


# 12 "<previous_module>"
void __cs_init_scalar(void *__cs_var, unsigned int __cs_size)
{
        
# 13 "<previous_module>"
if (__cs_size == (sizeof(int)))
                
# 14 "<previous_module>"
*((int *) __cs_var) = nondet_int();
        else

# 15 "<previous_module>"
        {
                
# 16 "<previous_module>"
__cs_var = malloc(__cs_size);
        }

}


# 20 "<previous_module>"
void __CSEQ_message(char *__cs_message)
{
        ;
}


# 22 "<previous_module>"
typedef int __cs_t;

# 24 "<previous_module>"
void *__cs_threadargs[3];

# 25 "<previous_module>"
void *__cs_thread_joinargs[3];

# 27 "<previous_module>"
int __cs_create(__cs_t *__cs_new_thread_id, void *__cs_attr, void *(*__cs_thread_function)(void *), void *__cs_arg, int __cs_threadID)
{
        
# 28 "<previous_module>"
if (__cs_threadID > THREADS)
                return 0;

        
# 29 "<previous_module>"
*__cs_new_thread_id = __cs_threadID;
        
# 30 "<previous_module>"
__cs_active_thread[__cs_threadID] = 1;
        
# 31 "<previous_module>"
__cs_threadargs[__cs_threadID] = __cs_arg;
        
# 32 "<previous_module>"
__CSEQ_message("thread spawned");
        
# 33 "<previous_module>"
return 0;
}


# 36 "<previous_module>"
int __cs_join(__cs_t __cs_id, void **__cs_value_ptr)
{
        
# 37 "<previous_module>"
__CPROVER_assume(__cs_pc[__cs_id] == __cs_thread_lines[__cs_id]);
        
# 38 "<previous_module>"
*__cs_value_ptr = __cs_thread_joinargs[__cs_id];
        
# 39 "<previous_module>"
return 0;
}


# 42 "<previous_module>"
int __cs_exit(void *__cs_value_ptr, unsigned int __cs_thread_index)
{
        
# 43 "<previous_module>"
__cs_thread_joinargs[__cs_thread_index] = __cs_value_ptr;
        
# 44 "<previous_module>"
return 0;
}


# 47 "<previous_module>"
int __cs_self(void)
{
        return 1;
}


# 49 "<previous_module>"
typedef int __cs_mutex_t;

# 51 "<previous_module>"
int __cs_mutex_init(__cs_mutex_t *__cs_m, int __cs_val)
{
        
# 52 "<previous_module>"
*__cs_m = -1;
        
# 53 "<previous_module>"
return 0;
}


# 56 "<previous_module>"
int __cs_mutex_destroy(__cs_mutex_t *__cs_mutex_to_destroy)
{
        
# 57 "<previous_module>"
__CPROVER_assert((*__cs_mutex_to_destroy) != 0, "attempt to destroy an uninitialized mutex");
        
# 58 "<previous_module>"
__CPROVER_assert((*__cs_mutex_to_destroy) != (-2), "attempt to destroy a previously destroyed mutex");
        
# 59 "<previous_module>"
__CPROVER_assert((*__cs_mutex_to_destroy) == (-1), "attempt to destroy a locked mutex");
        
# 60 "<previous_module>"
*__cs_mutex_to_destroy = -2;
        
# 61 "<previous_module>"
__CSEQ_message("lock destroyed");
        
# 62 "<previous_module>"
return 0;
}


# 65 "<previous_module>"
int __cs_mutex_lock(__cs_mutex_t *__cs_mutex_to_lock, unsigned __CPROVER_bitvector[2] __cs_thread_index)
{
        
# 66 "<previous_module>"
__CPROVER_assert((*__cs_mutex_to_lock) != 0, "attempt to lock an uninitialized mutex");
        
# 67 "<previous_module>"
__CPROVER_assert((*__cs_mutex_to_lock) != (-2), "attempt to lock a destroyed mutex");
        
# 68 "<previous_module>"
__CPROVER_assume((*__cs_mutex_to_lock) == (-1));
        
# 69 "<previous_module>"
*__cs_mutex_to_lock = __cs_thread_index + 1;
        
# 70 "<previous_module>"
__CSEQ_message("lock acquired");
        
# 71 "<previous_module>"
return 0;
}


# 74 "<previous_module>"
int __cs_mutex_unlock(__cs_mutex_t *__cs_mutex_to_unlock, unsigned __CPROVER_bitvector[2] __cs_thread_index)
{
        
# 75 "<previous_module>"
__CPROVER_assert((*__cs_mutex_to_unlock) != 0, "attempt to unlock an uninitialized mutex");
        
# 76 "<previous_module>"
__CPROVER_assert((*__cs_mutex_to_unlock) != (-2), "attempt to unlock a destroyed mutex");
        
# 77 "<previous_module>"
__CPROVER_assume((*__cs_mutex_to_unlock) == (__cs_thread_index + 1));
        
# 78 "<previous_module>"
*__cs_mutex_to_unlock = -1;
        
# 79 "<previous_module>"
__CSEQ_message("lock released");
        
# 80 "<previous_module>"
return 0;
}


# 83 "<previous_module>"
typedef int __cs_cond_t;

# 85 "<previous_module>"
int __cs_cond_init(__cs_cond_t *__cs_cond_to_init, void *__cs_attr)
{
        
# 86 "<previous_module>"
*__cs_cond_to_init = -1;
        
# 87 "<previous_module>"
return 0;
}


# 90 "<previous_module>"
int __cs_cond_destroy(__cs_cond_t *__cs_cond_to_destroy)
{
        
# 91 "<previous_module>"
*__cs_cond_to_destroy = -2;
        
# 92 "<previous_module>"
return 0;
}


# 95 "<previous_module>"
int __cs_cond_wait_1(__cs_cond_t *__cs_cond_to_wait_for, __cs_mutex_t *__cs_m, unsigned int __cs_thread_index)
{
        
# 96 "<previous_module>"
__CPROVER_assert((*__cs_cond_to_wait_for) != 0, "attempt to use an uninitialized conditional variable");
        
# 97 "<previous_module>"
__CPROVER_assert((*__cs_cond_to_wait_for) != (-2), "attempt to use a destroyed conditional variable");
        
# 98 "<previous_module>"
__cs_mutex_unlock(__cs_m, __cs_thread_index);
        
# 99 "<previous_module>"
return 0;
}


# 102 "<previous_module>"
int __cs_cond_wait_2(__cs_cond_t *__cs_cond_to_wait_for, __cs_mutex_t *__cs_m, unsigned int __cs_thread_index)
{
        
# 103 "<previous_module>"
__CPROVER_assume((*__cs_cond_to_wait_for) == 1);
        
# 104 "<previous_module>"
__cs_mutex_lock(__cs_m, __cs_thread_index);
        
# 105 "<previous_module>"
return 0;
}


# 108 "<previous_module>"
int __cs_cond_signal(__cs_cond_t *__cs_cond_to_signal)
{
        
# 109 "<previous_module>"
*__cs_cond_to_signal = 1;
        
# 110 "<previous_module>"
__CSEQ_message("conditional variable signal");
        
# 111 "<previous_module>"
return 0;
}


# 114 "<previous_module>"
int __cs_cond_broadcast(__cs_cond_t *__cs_cond_to_broadcast)
{
        
# 115 "<previous_module>"
*__cs_cond_to_broadcast = 1;
        
# 116 "<previous_module>"
__CSEQ_message("conditional variable broadcast");
        
# 117 "<previous_module>"
return 0;
}


# 123 "<previous_module>"
typedef struct __cs_barrier_t
{
        
# 121 "<previous_module>"
unsigned int init;
        
# 122 "<previous_module>"
unsigned int current;
} __cs_barrier_t;

# 125 "<previous_module>"
int __cs_barrier_init(__cs_barrier_t *__cs_barrier_to_init, void *__cs_attr, unsigned int count)
{
        
# 126 "<previous_module>"
__CPROVER_assert(count > 0, "count must be greater than 0");
        
# 127 "<previous_module>"
__cs_barrier_to_init->current = count;
        
# 128 "<previous_module>"
__cs_barrier_to_init->init = count;
        
# 129 "<previous_module>"
return 0;
}


# 132 "<previous_module>"
int __cs_barrier_destroy(__cs_barrier_t *__cs_barrier_to_destroy)
{
        
# 133 "<previous_module>"
__cs_barrier_to_destroy->init = -1;
        
# 134 "<previous_module>"
__cs_barrier_to_destroy->current = -1;
        
# 135 "<previous_module>"
return 0;
}


# 139 "<previous_module>"
int __cs_barrier_wait_1(__cs_barrier_t *__cs_barrier_to_wait)
{
        
# 140 "<previous_module>"
__CPROVER_assert(__cs_barrier_to_wait->init > 0, "attempt to use an uninitialized barrier variable");
        
# 141 "<previous_module>"
__cs_barrier_to_wait->current--;
        
# 142 "<previous_module>"
return 0;
}


# 145 "<previous_module>"
int __cs_barrier_wait_2(__cs_barrier_t *__cs_barrier_to_wait)
{
        
# 146 "<previous_module>"
__CPROVER_assert(__cs_barrier_to_wait->init > 0, "attempt to use an uninitialized barrier variable");
        
# 147 "<previous_module>"
__CPROVER_assume(__cs_barrier_to_wait->current == 0);
        
# 148 "<previous_module>"
__cs_barrier_to_wait->current = __cs_barrier_to_wait->init;
        
# 149 "<previous_module>"
return 0;
}


# 152 "<previous_module>"
typedef int __cs_attr_t;

# 153 "<previous_module>"
struct sched_param
{
        
# 154 "<previous_module>"
int sched_priority;
};

# 156 "<previous_module>"
int __cs_attr_init(__cs_attr_t *t)
{
        return 0;
}


# 157 "<previous_module>"
int __cs_attr_destroy(__cs_attr_t *t)
{
        return 0;
}


# 158 "<previous_module>"
int __cs_attr_getdetachstate(const __cs_attr_t *t, int *s)
{
        return 0;
}


# 159 "<previous_module>"
int __cs_attr_getguardsize(const __cs_attr_t *t, unsigned int *s)
{
        return 0;
}


# 160 "<previous_module>"
int __cs_attr_getinheritsched(const __cs_attr_t *t, int *s)
{
        return 0;
}


# 161 "<previous_module>"
int __cs_attr_getschedparam(const __cs_attr_t *t, struct sched_param *s)
{
        return 0;
}


# 162 "<previous_module>"
int __cs_attr_getschedpolicy(const __cs_attr_t *t, int *s)
{
        return 0;
}


# 163 "<previous_module>"
int __cs_attr_getscope(const __cs_attr_t *t, int *s)
{
        return 0;
}


# 164 "<previous_module>"
int __cs_attr_getstackaddr(const __cs_attr_t *t, void **s)
{
        return 0;
}


# 165 "<previous_module>"
int __cs_attr_getstacksize(const __cs_attr_t *t, unsigned int *s)
{
        return 0;
}


# 166 "<previous_module>"
int __cs_attr_setdetachstate(__cs_attr_t *t, int s)
{
        return 0;
}


# 167 "<previous_module>"
int __cs_attr_setguardsize(__cs_attr_t *t, unsigned int s)
{
        return 0;
}


# 168 "<previous_module>"
int __cs_attr_setinheritsched(__cs_attr_t *t, int s)
{
        return 0;
}


# 169 "<previous_module>"
int __cs_attr_setschedparam(__cs_attr_t *t, const struct sched_param *s)
{
        return 0;
}


# 170 "<previous_module>"
int __cs_attr_setschedpolicy(__cs_attr_t *t, int s)
{
        return 0;
}


# 171 "<previous_module>"
int __cs_attr_setscope(__cs_attr_t *t, int s)
{
        return 0;
}


# 172 "<previous_module>"
int __cs_attr_setstackaddr(__cs_attr_t *t, void *s)
{
        return 0;
}


# 173 "<previous_module>"
int __cs_attr_setstacksize(__cs_attr_t *t, unsigned int s)
{
        return 0;
}


# 174 "<previous_module>"
typedef int _____STARTSTRIPPINGFROMHERE_____;

# 175 "<previous_module>"
typedef int __cs_barrier_t;

# 176 "<previous_module>"
typedef int __cs_barrierattr_t;

# 177 "<previous_module>"
typedef int __cs_attr_t;

# 178 "<previous_module>"
typedef int __cs_cond_t;

# 179 "<previous_module>"
typedef int __cs_condattr_t;

# 180 "<previous_module>"
typedef int __cs_key_t;

# 181 "<previous_module>"
typedef int __cs_mutex_t;

# 182 "<previous_module>"
typedef int __cs_mutexattr_t;

# 183 "<previous_module>"
typedef int __cs_once_t;

# 184 "<previous_module>"
typedef int __cs_rwlock_t;

# 185 "<previous_module>"
typedef int __cs_rwlockattr_t;

# 186 "<previous_module>"
typedef int __cs_t;

# 187 "<previous_module>"
typedef int size_t;

# 188 "<previous_module>"
typedef int __builtin_va_list;

# 189 "<previous_module>"
typedef int __gnuc_va_list;

# 190 "<previous_module>"
typedef int __int8_t;

# 191 "<previous_module>"
typedef int __uint8_t;

# 192 "<previous_module>"
typedef int __int16_t;

# 193 "<previous_module>"
typedef int __uint16_t;

# 194 "<previous_module>"
typedef int __int_least16_t;

# 195 "<previous_module>"
typedef int __uint_least16_t;

# 196 "<previous_module>"
typedef int __int32_t;

# 197 "<previous_module>"
typedef int __uint32_t;

# 198 "<previous_module>"
typedef int __int64_t;

# 199 "<previous_module>"
typedef int __uint64_t;

# 200 "<previous_module>"
typedef int __int_least32_t;

# 201 "<previous_module>"
typedef int __uint_least32_t;

# 202 "<previous_module>"
typedef int __s8;

# 203 "<previous_module>"
typedef int __u8;

# 204 "<previous_module>"
typedef int __s16;

# 205 "<previous_module>"
typedef int __u16;

# 206 "<previous_module>"
typedef int __s32;

# 207 "<previous_module>"
typedef int __u32;

# 208 "<previous_module>"
typedef int __s64;

# 209 "<previous_module>"
typedef int __u64;

# 210 "<previous_module>"
typedef int _LOCK_T;

# 211 "<previous_module>"
typedef int _LOCK_RECURSIVE_T;

# 212 "<previous_module>"
typedef int _off_t;

# 213 "<previous_module>"
typedef int __dev_t;

# 214 "<previous_module>"
typedef int __uid_t;

# 215 "<previous_module>"
typedef int __gid_t;

# 216 "<previous_module>"
typedef int _off64_t;

# 217 "<previous_module>"
typedef int _fpos_t;

# 218 "<previous_module>"
typedef int _ssize_t;

# 219 "<previous_module>"
typedef int wint_t;

# 220 "<previous_module>"
typedef int _mbstate_t;

# 221 "<previous_module>"
typedef int _flock_t;

# 222 "<previous_module>"
typedef int _iconv_t;

# 223 "<previous_module>"
typedef int __ULong;

# 224 "<previous_module>"
typedef int __FILE;

# 225 "<previous_module>"
typedef int ptrdiff_t;

# 226 "<previous_module>"
typedef int wchar_t;

# 227 "<previous_module>"
typedef int __off_t;

# 228 "<previous_module>"
typedef int __pid_t;

# 229 "<previous_module>"
typedef int __loff_t;

# 230 "<previous_module>"
typedef int u_char;

# 231 "<previous_module>"
typedef int u_short;

# 232 "<previous_module>"
typedef int u_int;

# 233 "<previous_module>"
typedef int u_long;

# 234 "<previous_module>"
typedef int ushort;

# 235 "<previous_module>"
typedef int uint;

# 236 "<previous_module>"
typedef int clock_t;

# 237 "<previous_module>"
typedef int time_t;

# 238 "<previous_module>"
typedef int daddr_t;

# 239 "<previous_module>"
typedef int caddr_t;

# 240 "<previous_module>"
typedef int ino_t;

# 241 "<previous_module>"
typedef int off_t;

# 242 "<previous_module>"
typedef int dev_t;

# 243 "<previous_module>"
typedef int uid_t;

# 244 "<previous_module>"
typedef int gid_t;

# 245 "<previous_module>"
typedef int pid_t;

# 246 "<previous_module>"
typedef int key_t;

# 247 "<previous_module>"
typedef int ssize_t;

# 248 "<previous_module>"
typedef int mode_t;

# 249 "<previous_module>"
typedef int nlink_t;

# 250 "<previous_module>"
typedef int fd_mask;

# 251 "<previous_module>"
typedef int _types_fd_set;

# 252 "<previous_module>"
typedef int fd_set;

# 253 "<previous_module>"
typedef int clockid_t;

# 254 "<previous_module>"
typedef int timer_t;

# 255 "<previous_module>"
typedef int useconds_t;

# 256 "<previous_module>"
typedef int suseconds_t;

# 257 "<previous_module>"
typedef int FILE;

# 258 "<previous_module>"
typedef int fpos_t;

# 259 "<previous_module>"
typedef int cookie_read_function_t;

# 260 "<previous_module>"
typedef int cookie_write_function_t;

# 261 "<previous_module>"
typedef int cookie_seek_function_t;

# 262 "<previous_module>"
typedef int cookie_close_function_t;

# 263 "<previous_module>"
typedef int cookie_io_functions_t;

# 264 "<previous_module>"
typedef int div_t;

# 265 "<previous_module>"
typedef int ldiv_t;

# 266 "<previous_module>"
typedef int lldiv_t;

# 267 "<previous_module>"
typedef int sigset_t;

# 268 "<previous_module>"
typedef int __sigset_t;

# 269 "<previous_module>"
typedef int _sig_func_ptr;

# 270 "<previous_module>"
typedef int sig_atomic_t;

# 271 "<previous_module>"
typedef int __tzrule_type;

# 272 "<previous_module>"
typedef int __tzinfo_type;

# 273 "<previous_module>"
typedef int mbstate_t;

# 274 "<previous_module>"
typedef int sem_t;

# 275 "<previous_module>"
typedef int pthread_t;

# 276 "<previous_module>"
typedef int pthread_attr_t;

# 277 "<previous_module>"
typedef int pthread_mutex_t;

# 278 "<previous_module>"
typedef int pthread_mutexattr_t;

# 279 "<previous_module>"
typedef int pthread_cond_t;

# 280 "<previous_module>"
typedef int pthread_condattr_t;

# 281 "<previous_module>"
typedef int pthread_key_t;

# 282 "<previous_module>"
typedef int pthread_once_t;

# 283 "<previous_module>"
typedef int pthread_rwlock_t;

# 284 "<previous_module>"
typedef int pthread_rwlockattr_t;

# 285 "<previous_module>"
typedef int pthread_spinlock_t;

# 286 "<previous_module>"
typedef int pthread_barrier_t;

# 287 "<previous_module>"
typedef int pthread_barrierattr_t;

# 288 "<previous_module>"
typedef int jmp_buf;

# 289 "<previous_module>"
typedef int rlim_t;

# 290 "<previous_module>"
typedef int sa_family_t;

# 291 "<previous_module>"
typedef int sigjmp_buf;

# 292 "<previous_module>"
typedef int stack_t;

# 293 "<previous_module>"
typedef int siginfo_t;

# 294 "<previous_module>"
typedef int z_stream;

# 295 "<previous_module>"
typedef int int8_t;

# 296 "<previous_module>"
typedef int uint8_t;

# 297 "<previous_module>"
typedef int int16_t;

# 298 "<previous_module>"
typedef int uint16_t;

# 299 "<previous_module>"
typedef int int32_t;

# 300 "<previous_module>"
typedef int uint32_t;

# 301 "<previous_module>"
typedef int int64_t;

# 302 "<previous_module>"
typedef int uint64_t;

# 303 "<previous_module>"
typedef int int_least8_t;

# 304 "<previous_module>"
typedef int uint_least8_t;

# 305 "<previous_module>"
typedef int int_least16_t;

# 306 "<previous_module>"
typedef int uint_least16_t;

# 307 "<previous_module>"
typedef int int_least32_t;

# 308 "<previous_module>"
typedef int uint_least32_t;

# 309 "<previous_module>"
typedef int int_least64_t;

# 310 "<previous_module>"
typedef int uint_least64_t;

# 311 "<previous_module>"
typedef int int_fast8_t;

# 312 "<previous_module>"
typedef int uint_fast8_t;

# 313 "<previous_module>"
typedef int int_fast16_t;

# 314 "<previous_module>"
typedef int uint_fast16_t;

# 315 "<previous_module>"
typedef int int_fast32_t;

# 316 "<previous_module>"
typedef int uint_fast32_t;

# 317 "<previous_module>"
typedef int int_fast64_t;

# 318 "<previous_module>"
typedef int uint_fast64_t;

# 319 "<previous_module>"
typedef int intptr_t;

# 320 "<previous_module>"
typedef int uintptr_t;

# 321 "<previous_module>"
typedef int intmax_t;

# 322 "<previous_module>"
typedef int uintmax_t;

# 323 "<previous_module>"
typedef _Bool bool;

# 324 "<previous_module>"
typedef void BZFILE;

# 325 "<previous_module>"
typedef int va_list;

# 326 "<previous_module>"
typedef int loff_t;

# 327 "<previous_module>"
typedef int _____STOPSTRIPPINGFROMHERE_____;

# 328 "<previous_module>"
#pragma warning( push )

# 329 "<previous_module>"
#pragma warning( disable : 4324 )

# 330 "<previous_module>"
#pragma prefast( disable : 28113 28182 28183, "blah" )

# 331 "<previous_module>"
typedef int long long lfds711_pal_int_t;

# 332 "<previous_module>"
typedef int long long unsigned lfds711_pal_uint_t;

# 333 "<previous_module>"
struct lfds711_prng_state
{
        
# 335 "<previous_module>"
lfds711_pal_uint_t entropy;
};

# 337 "<previous_module>"
struct lfds711_prng_st_state
{
        
# 339 "<previous_module>"
lfds711_pal_uint_t entropy;
};

# 341 "<previous_module>"
void lfds711_prng_init_valid_on_current_logical_core(struct lfds711_prng_state *__cs_param__ps, lfds711_pal_uint_t __cs_param__seed);

# 342 "<previous_module>"
void lfds711_prng_st_init(struct lfds711_prng_st_state *__cs_param__psts, lfds711_pal_uint_t __cs_param__seed);

# 343 "<previous_module>"
enum lfds711_misc_cas_strength {LFDS711_MISC_CAS_STRENGTH_STRONG = 
# 344 "<previous_module>"
0, LFDS711_MISC_CAS_STRENGTH_WEAK = 
# 345 "<previous_module>"
1};

# 346 "<previous_module>"
enum lfds711_misc_validity {LFDS711_MISC_VALIDITY_UNKNOWN, LFDS711_MISC_VALIDITY_VALID, LFDS711_MISC_VALIDITY_INVALID_LOOP, LFDS711_MISC_VALIDITY_INVALID_MISSING_ELEMENTS, LFDS711_MISC_VALIDITY_INVALID_ADDITIONAL_ELEMENTS, LFDS711_MISC_VALIDITY_INVALID_TEST_DATA, LFDS711_MISC_VALIDITY_INVALID_ORDER, LFDS711_MISC_VALIDITY_INVALID_ATOMIC_FAILED, LFDS711_MISC_VALIDITY_INDETERMINATE_NONATOMIC_PASSED};

# 347 "<previous_module>"
enum lfds711_misc_flag {LFDS711_MISC_FLAG_LOWERED, LFDS711_MISC_FLAG_RAISED};

# 348 "<previous_module>"
enum lfds711_misc_query {LFDS711_MISC_QUERY_GET_BUILD_AND_VERSION_STRING};

# 349 "<previous_module>"
enum lfds711_misc_data_structure {LFDS711_MISC_DATA_STRUCTURE_BTREE_AU, LFDS711_MISC_DATA_STRUCTURE_FREELIST, LFDS711_MISC_DATA_STRUCTURE_HASH_A, LFDS711_MISC_DATA_STRUCTURE_LIST_AOS, LFDS711_MISC_DATA_STRUCTURE_LIST_ASU, LFDS711_MISC_DATA_STRUCTURE_QUEUE_BMM, LFDS711_MISC_DATA_STRUCTURE_QUEUE_BSS, LFDS711_MISC_DATA_STRUCTURE_QUEUE_UMM, LFDS711_MISC_DATA_STRUCTURE_RINGBUFFER, LFDS711_MISC_DATA_STRUCTURE_STACK, LFDS711_MISC_DATA_STRUCTURE_COUNT};

# 350 "<previous_module>"
struct lfds711_misc_backoff_state
{
        
# 352 "<previous_module>"
lfds711_pal_uint_t lock;
        
# 353 "<previous_module>"
lfds711_pal_uint_t backoff_iteration_frequency_counters[2];
        
# 354 "<previous_module>"
lfds711_pal_uint_t metric;
        
# 355 "<previous_module>"
lfds711_pal_uint_t total_operations;
};

# 357 "<previous_module>"
struct lfds711_misc_globals
{
        
# 359 "<previous_module>"
struct lfds711_prng_state ps;
};

# 361 "<previous_module>"
struct lfds711_misc_validation_info
{
        
# 363 "<previous_module>"
lfds711_pal_uint_t min_elements;
        
# 364 "<previous_module>"
lfds711_pal_uint_t max_elements;
};

# 366 "<previous_module>"
struct lfds711_misc_globals lfds711_misc_globals;

# 367 "<previous_module>"
static void lfds711_misc_force_store(void);

# 368 "<previous_module>"
void lfds711_misc_query(enum lfds711_misc_query __cs_param__query_type, void *__cs_param__query_input, void *__cs_param__query_output);

# 369 "<previous_module>"
#pragma prefast( disable : 28112, "blah" )

# 370 "<previous_module>"
enum lfds711_btree_au_absolute_position {LFDS711_BTREE_AU_ABSOLUTE_POSITION_ROOT, LFDS711_BTREE_AU_ABSOLUTE_POSITION_SMALLEST_IN_TREE, LFDS711_BTREE_AU_ABSOLUTE_POSITION_LARGEST_IN_TREE};

# 371 "<previous_module>"
enum lfds711_btree_au_existing_key {LFDS711_BTREE_AU_EXISTING_KEY_OVERWRITE, LFDS711_BTREE_AU_EXISTING_KEY_FAIL};

# 372 "<previous_module>"
enum lfds711_btree_au_insert_result {LFDS711_BTREE_AU_INSERT_RESULT_FAILURE_EXISTING_KEY, LFDS711_BTREE_AU_INSERT_RESULT_SUCCESS_OVERWRITE, LFDS711_BTREE_AU_INSERT_RESULT_SUCCESS};

# 373 "<previous_module>"
enum lfds711_btree_au_query {LFDS711_BTREE_AU_QUERY_GET_POTENTIALLY_INACCURATE_COUNT, LFDS711_BTREE_AU_QUERY_SINGLETHREADED_VALIDATE};

# 374 "<previous_module>"
enum lfds711_btree_au_relative_position {LFDS711_BTREE_AU_RELATIVE_POSITION_UP, LFDS711_BTREE_AU_RELATIVE_POSITION_LEFT, LFDS711_BTREE_AU_RELATIVE_POSITION_RIGHT, LFDS711_BTREE_AU_RELATIVE_POSITION_SMALLEST_ELEMENT_BELOW_CURRENT_ELEMENT, LFDS711_BTREE_AU_RELATIVE_POSITION_LARGEST_ELEMENT_BELOW_CURRENT_ELEMENT, LFDS711_BTREE_AU_RELATIVE_POSITION_NEXT_SMALLER_ELEMENT_IN_ENTIRE_TREE, LFDS711_BTREE_AU_RELATIVE_POSITION_NEXT_LARGER_ELEMENT_IN_ENTIRE_TREE};

# 375 "<previous_module>"
struct lfds711_btree_au_element
{
        
# 377 "<previous_module>"
struct lfds711_btree_au_element * volatile left;
        
# 378 "<previous_module>"
struct lfds711_btree_au_element * volatile right;
        
# 379 "<previous_module>"
struct lfds711_btree_au_element * volatile up;
        
# 380 "<previous_module>"
void * volatile value;
        
# 381 "<previous_module>"
void *key;
};

# 383 "<previous_module>"
struct lfds711_btree_au_state
{
        
# 385 "<previous_module>"
struct lfds711_btree_au_element * volatile root;
        
# 386 "<previous_module>"
int (*key_compare_function)(const void *__cs_param__new_key, const void *__cs_param__existing_key);
        
# 387 "<previous_module>"
enum lfds711_btree_au_existing_key existing_key;
        
# 388 "<previous_module>"
void *user_state;
        
# 389 "<previous_module>"
struct lfds711_misc_backoff_state insert_backoff;
};

# 391 "<previous_module>"
void lfds711_btree_au_init_valid_on_current_logical_core(struct lfds711_btree_au_state *__cs_param__baus, 
# 392 "<previous_module>"
int (*__cs_param__key_compare_function)(const void *new_key, const void *existing_key), 
# 393 "<previous_module>"
enum lfds711_btree_au_existing_key __cs_param__existing_key, 
# 394 "<previous_module>"
void *__cs_param__user_state);

# 395 "<previous_module>"
void lfds711_btree_au_cleanup(struct lfds711_btree_au_state *__cs_param__baus, 
# 396 "<previous_module>"
void (*__cs_param__element_cleanup_callback)(struct lfds711_btree_au_state *baus, struct lfds711_btree_au_element *baue));

# 397 "<previous_module>"
enum lfds711_btree_au_insert_result lfds711_btree_au_insert(struct lfds711_btree_au_state *__cs_param__baus, 
# 398 "<previous_module>"
struct lfds711_btree_au_element *__cs_param__baue, 
# 399 "<previous_module>"
struct lfds711_btree_au_element **__cs_param__existing_baue);

# 400 "<previous_module>"
int lfds711_btree_au_get_by_key(struct lfds711_btree_au_state *__cs_param__baus, 
# 401 "<previous_module>"
int (*__cs_param__key_compare_function)(const void *new_key, const void *existing_key), 
# 402 "<previous_module>"
void *__cs_param__key, 
# 403 "<previous_module>"
struct lfds711_btree_au_element **__cs_param__baue);

# 404 "<previous_module>"
int lfds711_btree_au_get_by_absolute_position_and_then_by_relative_position(struct lfds711_btree_au_state *__cs_param__baus, 
# 405 "<previous_module>"
struct lfds711_btree_au_element **__cs_param__baue, 
# 406 "<previous_module>"
enum lfds711_btree_au_absolute_position __cs_param__absolute_position, 
# 407 "<previous_module>"
enum lfds711_btree_au_relative_position __cs_param__relative_position);

# 408 "<previous_module>"
int lfds711_btree_au_get_by_absolute_position(struct lfds711_btree_au_state *__cs_param__baus, 
# 409 "<previous_module>"
struct lfds711_btree_au_element **__cs_param__baue, 
# 410 "<previous_module>"
enum lfds711_btree_au_absolute_position __cs_param__absolute_position);

# 411 "<previous_module>"
int lfds711_btree_au_get_by_relative_position(struct lfds711_btree_au_element **__cs_param__baue, 
# 412 "<previous_module>"
enum lfds711_btree_au_relative_position __cs_param__relative_position);

# 413 "<previous_module>"
void lfds711_btree_au_query(struct lfds711_btree_au_state *__cs_param__baus, 
# 414 "<previous_module>"
enum lfds711_btree_au_query __cs_param__query_type, 
# 415 "<previous_module>"
void *__cs_param__query_input, 
# 416 "<previous_module>"
void *__cs_param__query_output);

# 417 "<previous_module>"
enum lfds711_freelist_query {LFDS711_FREELIST_QUERY_SINGLETHREADED_GET_COUNT, LFDS711_FREELIST_QUERY_SINGLETHREADED_VALIDATE, LFDS711_FREELIST_QUERY_GET_ELIMINATION_ARRAY_EXTRA_ELEMENTS_IN_FREELIST_ELEMENTS};

# 418 "<previous_module>"
struct lfds711_freelist_element
{
        
# 420 "<previous_module>"
struct lfds711_freelist_element *next;
        
# 421 "<previous_module>"
void *key;
        
# 422 "<previous_module>"
void *value;
};

# 424 "<previous_module>"
struct lfds711_freelist_state
{
        
# 426 "<previous_module>"
struct lfds711_freelist_element * volatile top[2];
        
# 427 "<previous_module>"
lfds711_pal_uint_t elimination_array_size_in_elements;
        
# 428 "<previous_module>"
struct lfds711_freelist_element * volatile (*elimination_array)[128 / (sizeof(struct lfds711_freelist_element *))];
        
# 429 "<previous_module>"
void *user_state;
        
# 430 "<previous_module>"
struct lfds711_misc_backoff_state pop_backoff;
        
# 431 "<previous_module>"
struct lfds711_misc_backoff_state push_backoff;
};

# 433 "<previous_module>"
void lfds711_freelist_init_valid_on_current_logical_core(struct lfds711_freelist_state *__cs_param__fs, 
# 434 "<previous_module>"
struct lfds711_freelist_element * volatile (*__cs_param__elimination_array)[128 / (sizeof(struct lfds711_freelist_element *))], 
# 435 "<previous_module>"
lfds711_pal_uint_t __cs_param__elimination_array_size_in_elements, 
# 436 "<previous_module>"
void *__cs_param__user_state);

# 437 "<previous_module>"
void lfds711_freelist_cleanup(struct lfds711_freelist_state *__cs_param__fs, 
# 438 "<previous_module>"
void (*__cs_param__element_cleanup_callback)(struct lfds711_freelist_state *fs, struct lfds711_freelist_element *fe));

# 439 "<previous_module>"
void lfds711_freelist_push(struct lfds711_freelist_state *__cs_param__fs, 
# 440 "<previous_module>"
struct lfds711_freelist_element *__cs_param__fe, 
# 441 "<previous_module>"
struct lfds711_prng_st_state *__cs_param__psts);

# 442 "<previous_module>"
int lfds711_freelist_pop(struct lfds711_freelist_state *__cs_param__fs, 
# 443 "<previous_module>"
struct lfds711_freelist_element **__cs_param__fe, 
# 444 "<previous_module>"
struct lfds711_prng_st_state *__cs_param__psts);

# 445 "<previous_module>"
void lfds711_freelist_query(struct lfds711_freelist_state *__cs_param__fs, 
# 446 "<previous_module>"
enum lfds711_freelist_query __cs_param__query_type, 
# 447 "<previous_module>"
void *__cs_param__query_input, 
# 448 "<previous_module>"
void *__cs_param__query_output);

# 449 "<previous_module>"
enum lfds711_hash_a_existing_key {LFDS711_HASH_A_EXISTING_KEY_OVERWRITE, LFDS711_HASH_A_EXISTING_KEY_FAIL};

# 450 "<previous_module>"
enum lfds711_hash_a_insert_result {LFDS711_HASH_A_PUT_RESULT_FAILURE_EXISTING_KEY, LFDS711_HASH_A_PUT_RESULT_SUCCESS_OVERWRITE, LFDS711_HASH_A_PUT_RESULT_SUCCESS};

# 451 "<previous_module>"
enum lfds711_hash_a_query {LFDS711_HASH_A_QUERY_GET_POTENTIALLY_INACCURATE_COUNT, LFDS711_HASH_A_QUERY_SINGLETHREADED_VALIDATE};

# 452 "<previous_module>"
struct lfds711_hash_a_element
{
        
# 454 "<previous_module>"
struct lfds711_btree_au_element baue;
        
# 455 "<previous_module>"
void *key;
        
# 456 "<previous_module>"
void * volatile value;
};

# 458 "<previous_module>"
struct lfds711_hash_a_iterate
{
        
# 460 "<previous_module>"
struct lfds711_btree_au_element *baue;
        
# 461 "<previous_module>"
struct lfds711_btree_au_state *baus;
        
# 462 "<previous_module>"
struct lfds711_btree_au_state *baus_end;
};

# 464 "<previous_module>"
struct lfds711_hash_a_state
{
        
# 466 "<previous_module>"
enum lfds711_hash_a_existing_key existing_key;
        
# 467 "<previous_module>"
int (*key_compare_function)(const void *__cs_param__new_key, const void *__cs_param__existing_key);
        
# 468 "<previous_module>"
lfds711_pal_uint_t array_size;
        
# 469 "<previous_module>"
struct lfds711_btree_au_state *baus_array;
        
# 470 "<previous_module>"
void (*element_cleanup_callback)(struct lfds711_hash_a_state *__cs_param__has, struct lfds711_hash_a_element *__cs_param__hae);
        
# 471 "<previous_module>"
void (*key_hash_function)(const void *__cs_param__key, lfds711_pal_uint_t *__cs_param__hash);
        
# 472 "<previous_module>"
void *user_state;
};

# 474 "<previous_module>"
void lfds711_hash_a_init_valid_on_current_logical_core(struct lfds711_hash_a_state *__cs_param__has, 
# 475 "<previous_module>"
struct lfds711_btree_au_state *__cs_param__baus_array, 
# 476 "<previous_module>"
lfds711_pal_uint_t __cs_param__array_size, 
# 477 "<previous_module>"
int (*__cs_param__key_compare_function)(const void *new_key, const void *existing_key), 
# 478 "<previous_module>"
void (*__cs_param__key_hash_function)(const void *key, lfds711_pal_uint_t *hash), 
# 479 "<previous_module>"
enum lfds711_hash_a_existing_key __cs_param__existing_key, 
# 480 "<previous_module>"
void *__cs_param__user_state);

# 481 "<previous_module>"
void lfds711_hash_a_cleanup(struct lfds711_hash_a_state *__cs_param__has, 
# 482 "<previous_module>"
void (*__cs_param__element_cleanup_function)(struct lfds711_hash_a_state *has, struct lfds711_hash_a_element *hae));

# 483 "<previous_module>"
enum lfds711_hash_a_insert_result lfds711_hash_a_insert(struct lfds711_hash_a_state *__cs_param__has, 
# 484 "<previous_module>"
struct lfds711_hash_a_element *__cs_param__hae, 
# 485 "<previous_module>"
struct lfds711_hash_a_element **__cs_param__existing_hae);

# 486 "<previous_module>"
int lfds711_hash_a_get_by_key(struct lfds711_hash_a_state *__cs_param__has, 
# 487 "<previous_module>"
int (*__cs_param__key_compare_function)(const void *new_key, const void *existing_key), 
# 488 "<previous_module>"
void (*__cs_param__key_hash_function)(const void *key, lfds711_pal_uint_t *hash), 
# 489 "<previous_module>"
void *__cs_param__key, 
# 490 "<previous_module>"
struct lfds711_hash_a_element **__cs_param__hae);

# 491 "<previous_module>"
void lfds711_hash_a_iterate_init(struct lfds711_hash_a_state *__cs_param__has, struct lfds711_hash_a_iterate *__cs_param__hai);

# 492 "<previous_module>"
int lfds711_hash_a_iterate(struct lfds711_hash_a_iterate *__cs_param__hai, struct lfds711_hash_a_element **__cs_param__hae);

# 493 "<previous_module>"
void lfds711_hash_a_query(struct lfds711_hash_a_state *__cs_param__has, 
# 494 "<previous_module>"
enum lfds711_hash_a_query __cs_param__query_type, 
# 495 "<previous_module>"
void *__cs_param__query_input, 
# 496 "<previous_module>"
void *__cs_param__query_output);

# 497 "<previous_module>"
enum lfds711_list_aso_existing_key {LFDS711_LIST_ASO_EXISTING_KEY_OVERWRITE, LFDS711_LIST_ASO_EXISTING_KEY_FAIL};

# 498 "<previous_module>"
enum lfds711_list_aso_insert_result {LFDS711_LIST_ASO_INSERT_RESULT_FAILURE_EXISTING_KEY, LFDS711_LIST_ASO_INSERT_RESULT_SUCCESS_OVERWRITE, LFDS711_LIST_ASO_INSERT_RESULT_SUCCESS};

# 499 "<previous_module>"
enum lfds711_list_aso_query {LFDS711_LIST_ASO_QUERY_GET_POTENTIALLY_INACCURATE_COUNT, LFDS711_LIST_ASO_QUERY_SINGLETHREADED_VALIDATE};

# 500 "<previous_module>"
struct lfds711_list_aso_element
{
        
# 502 "<previous_module>"
struct lfds711_list_aso_element * volatile next;
        
# 503 "<previous_module>"
void * volatile value;
        
# 504 "<previous_module>"
void *key;
};

# 506 "<previous_module>"
struct lfds711_list_aso_state
{
        
# 508 "<previous_module>"
struct lfds711_list_aso_element dummy_element;
        
# 509 "<previous_module>"
struct lfds711_list_aso_element *start;
        
# 510 "<previous_module>"
int (*key_compare_function)(const void *__cs_param__new_key, const void *__cs_param__existing_key);
        
# 511 "<previous_module>"
enum lfds711_list_aso_existing_key existing_key;
        
# 512 "<previous_module>"
void *user_state;
        
# 513 "<previous_module>"
struct lfds711_misc_backoff_state insert_backoff;
};

# 515 "<previous_module>"
void lfds711_list_aso_init_valid_on_current_logical_core(struct lfds711_list_aso_state *__cs_param__lasos, 
# 516 "<previous_module>"
int (*__cs_param__key_compare_function)(const void *new_key, const void *existing_key), 
# 517 "<previous_module>"
enum lfds711_list_aso_existing_key __cs_param__existing_key, 
# 518 "<previous_module>"
void *__cs_param__user_state);

# 519 "<previous_module>"
void lfds711_list_aso_cleanup(struct lfds711_list_aso_state *__cs_param__lasos, 
# 520 "<previous_module>"
void (*__cs_param__element_cleanup_callback)(struct lfds711_list_aso_state *lasos, struct lfds711_list_aso_element *lasoe));

# 521 "<previous_module>"
enum lfds711_list_aso_insert_result lfds711_list_aso_insert(struct lfds711_list_aso_state *__cs_param__lasos, 
# 522 "<previous_module>"
struct lfds711_list_aso_element *__cs_param__lasoe, 
# 523 "<previous_module>"
struct lfds711_list_aso_element **__cs_param__existing_lasoe);

# 524 "<previous_module>"
int lfds711_list_aso_get_by_key(struct lfds711_list_aso_state *__cs_param__lasos, 
# 525 "<previous_module>"
void *__cs_param__key, 
# 526 "<previous_module>"
struct lfds711_list_aso_element **__cs_param__lasoe);

# 527 "<previous_module>"
void lfds711_list_aso_query(struct lfds711_list_aso_state *__cs_param__lasos, 
# 528 "<previous_module>"
enum lfds711_list_aso_query __cs_param__query_type, 
# 529 "<previous_module>"
void *__cs_param__query_input, 
# 530 "<previous_module>"
void *__cs_param__query_output);

# 531 "<previous_module>"
enum lfds711_list_asu_position {LFDS711_LIST_ASU_POSITION_START, LFDS711_LIST_ASU_POSITION_END, LFDS711_LIST_ASU_POSITION_AFTER};

# 532 "<previous_module>"
enum lfds711_list_asu_query {LFDS711_LIST_ASU_QUERY_GET_POTENTIALLY_INACCURATE_COUNT, LFDS711_LIST_ASU_QUERY_SINGLETHREADED_VALIDATE};

# 533 "<previous_module>"
struct lfds711_list_asu_element
{
        
# 535 "<previous_module>"
struct lfds711_list_asu_element * volatile next;
        
# 536 "<previous_module>"
void * volatile value;
        
# 537 "<previous_module>"
void *key;
};

# 539 "<previous_module>"
struct lfds711_list_asu_state
{
        
# 541 "<previous_module>"
struct lfds711_list_asu_element dummy_element;
        
# 542 "<previous_module>"
struct lfds711_list_asu_element * volatile end;
        
# 543 "<previous_module>"
struct lfds711_list_asu_element *start;
        
# 544 "<previous_module>"
void *user_state;
        
# 545 "<previous_module>"
struct lfds711_misc_backoff_state after_backoff;
        
# 546 "<previous_module>"
struct lfds711_misc_backoff_state end_backoff;
        
# 547 "<previous_module>"
struct lfds711_misc_backoff_state start_backoff;
};

# 549 "<previous_module>"
void lfds711_list_asu_init_valid_on_current_logical_core(struct lfds711_list_asu_state *__cs_param__lasus, 
# 550 "<previous_module>"
void *__cs_param__user_state);

# 551 "<previous_module>"
void lfds711_list_asu_cleanup(struct lfds711_list_asu_state *__cs_param__lasus, 
# 552 "<previous_module>"
void (*__cs_param__element_cleanup_callback)(struct lfds711_list_asu_state *lasus, struct lfds711_list_asu_element *lasue));

# 553 "<previous_module>"
void lfds711_list_asu_insert_at_position(struct lfds711_list_asu_state *__cs_param__lasus, 
# 554 "<previous_module>"
struct lfds711_list_asu_element *__cs_param__lasue, 
# 555 "<previous_module>"
struct lfds711_list_asu_element *__cs_param__lasue_predecessor, 
# 556 "<previous_module>"
enum lfds711_list_asu_position __cs_param__position);

# 557 "<previous_module>"
void lfds711_list_asu_insert_at_start(struct lfds711_list_asu_state *__cs_param__lasus, 
# 558 "<previous_module>"
struct lfds711_list_asu_element *__cs_param__lasue);

# 559 "<previous_module>"
void lfds711_list_asu_insert_at_end(struct lfds711_list_asu_state *__cs_param__lasus, 
# 560 "<previous_module>"
struct lfds711_list_asu_element *__cs_param__lasue);

# 561 "<previous_module>"
void lfds711_list_asu_insert_after_element(struct lfds711_list_asu_state *__cs_param__lasus, 
# 562 "<previous_module>"
struct lfds711_list_asu_element *__cs_param__lasue, 
# 563 "<previous_module>"
struct lfds711_list_asu_element *__cs_param__lasue_predecessor);

# 564 "<previous_module>"
int lfds711_list_asu_get_by_key(struct lfds711_list_asu_state *__cs_param__lasus, 
# 565 "<previous_module>"
int (*__cs_param__key_compare_function)(const void *new_key, const void *existing_key), 
# 566 "<previous_module>"
void *__cs_param__key, 
# 567 "<previous_module>"
struct lfds711_list_asu_element **__cs_param__lasue);

# 568 "<previous_module>"
void lfds711_list_asu_query(struct lfds711_list_asu_state *__cs_param__lasus, 
# 569 "<previous_module>"
enum lfds711_list_asu_query __cs_param__query_type, 
# 570 "<previous_module>"
void *__cs_param__query_input, 
# 571 "<previous_module>"
void *__cs_param__query_output);

# 572 "<previous_module>"
enum lfds711_queue_bmm_query {LFDS711_QUEUE_BMM_QUERY_GET_POTENTIALLY_INACCURATE_COUNT, LFDS711_QUEUE_BMM_QUERY_SINGLETHREADED_VALIDATE};

# 573 "<previous_module>"
struct lfds711_queue_bmm_element
{
        
# 575 "<previous_module>"
lfds711_pal_uint_t sequence_number;
        
# 576 "<previous_module>"
void * volatile key;
        
# 577 "<previous_module>"
void * volatile value;
};

# 579 "<previous_module>"
struct lfds711_queue_bmm_state
{
        
# 581 "<previous_module>"
lfds711_pal_uint_t number_elements;
        
# 582 "<previous_module>"
lfds711_pal_uint_t mask;
        
# 583 "<previous_module>"
lfds711_pal_uint_t read_index;
        
# 584 "<previous_module>"
lfds711_pal_uint_t write_index;
        
# 585 "<previous_module>"
struct lfds711_queue_bmm_element *element_array;
        
# 586 "<previous_module>"
void *user_state;
        
# 587 "<previous_module>"
struct lfds711_misc_backoff_state dequeue_backoff;
        
# 588 "<previous_module>"
struct lfds711_misc_backoff_state enqueue_backoff;
};

# 590 "<previous_module>"
void lfds711_queue_bmm_init_valid_on_current_logical_core(struct lfds711_queue_bmm_state *__cs_param__qbmms, 
# 591 "<previous_module>"
struct lfds711_queue_bmm_element *__cs_param__element_array, 
# 592 "<previous_module>"
lfds711_pal_uint_t __cs_param__number_elements, 
# 593 "<previous_module>"
void *__cs_param__user_state);

# 594 "<previous_module>"
void lfds711_queue_bmm_cleanup(struct lfds711_queue_bmm_state *__cs_param__qbmms, 
# 595 "<previous_module>"
void (*__cs_param__element_cleanup_callback)(struct lfds711_queue_bmm_state *qbmms, 
# 596 "<previous_module>"
void *key, 
# 597 "<previous_module>"
void *value));

# 598 "<previous_module>"
int lfds711_queue_bmm_enqueue(struct lfds711_queue_bmm_state *__cs_param__qbmms, 
# 599 "<previous_module>"
void *__cs_param__key, 
# 600 "<previous_module>"
void *__cs_param__value);

# 601 "<previous_module>"
int lfds711_queue_bmm_dequeue(struct lfds711_queue_bmm_state *__cs_param__qbmms, 
# 602 "<previous_module>"
void **__cs_param__key, 
# 603 "<previous_module>"
void **__cs_param__value);

# 604 "<previous_module>"
void lfds711_queue_bmm_query(struct lfds711_queue_bmm_state *__cs_param__qbmms, 
# 605 "<previous_module>"
enum lfds711_queue_bmm_query __cs_param__query_type, 
# 606 "<previous_module>"
void *__cs_param__query_input, 
# 607 "<previous_module>"
void *__cs_param__query_output);

# 608 "<previous_module>"
enum lfds711_queue_bss_query {LFDS711_QUEUE_BSS_QUERY_GET_POTENTIALLY_INACCURATE_COUNT, LFDS711_QUEUE_BSS_QUERY_VALIDATE};

# 609 "<previous_module>"
struct lfds711_queue_bss_element
{
        
# 611 "<previous_module>"
void * volatile key;
        
# 612 "<previous_module>"
void * volatile value;
};

# 614 "<previous_module>"
struct lfds711_queue_bss_state
{
        
# 616 "<previous_module>"
lfds711_pal_uint_t number_elements;
        
# 617 "<previous_module>"
lfds711_pal_uint_t mask;
        
# 618 "<previous_module>"
lfds711_pal_uint_t read_index;
        
# 619 "<previous_module>"
lfds711_pal_uint_t write_index;
        
# 620 "<previous_module>"
struct lfds711_queue_bss_element *element_array;
        
# 621 "<previous_module>"
void *user_state;
};

# 623 "<previous_module>"
void lfds711_queue_bss_init_valid_on_current_logical_core(struct lfds711_queue_bss_state *__cs_param__qbsss, 
# 624 "<previous_module>"
struct lfds711_queue_bss_element *__cs_param__element_array, 
# 625 "<previous_module>"
lfds711_pal_uint_t __cs_param__number_elements, 
# 626 "<previous_module>"
void *__cs_param__user_state);

# 627 "<previous_module>"
void lfds711_queue_bss_cleanup(struct lfds711_queue_bss_state *__cs_param__qbsss, 
# 628 "<previous_module>"
void (*__cs_param__element_cleanup_callback)(struct lfds711_queue_bss_state *qbsss, void *key, void *value));

# 629 "<previous_module>"
int lfds711_queue_bss_enqueue(struct lfds711_queue_bss_state *__cs_param__qbsss, 
# 630 "<previous_module>"
void *__cs_param__key, 
# 631 "<previous_module>"
void *__cs_param__value);

# 632 "<previous_module>"
int lfds711_queue_bss_dequeue(struct lfds711_queue_bss_state *__cs_param__qbsss, 
# 633 "<previous_module>"
void **__cs_param__key, 
# 634 "<previous_module>"
void **__cs_param__value);

# 635 "<previous_module>"
void lfds711_queue_bss_query(struct lfds711_queue_bss_state *__cs_param__qbsss, 
# 636 "<previous_module>"
enum lfds711_queue_bss_query __cs_param__query_type, 
# 637 "<previous_module>"
void *__cs_param__query_input, 
# 638 "<previous_module>"
void *__cs_param__query_output);

# 639 "<previous_module>"
enum lfds711_queue_umm_query {LFDS711_QUEUE_UMM_QUERY_SINGLETHREADED_GET_COUNT, LFDS711_QUEUE_UMM_QUERY_SINGLETHREADED_VALIDATE};

# 640 "<previous_module>"
struct lfds711_queue_umm_element
{
        
# 642 "<previous_module>"
struct lfds711_queue_umm_element * volatile next[2];
        
# 643 "<previous_module>"
void *key;
        
# 644 "<previous_module>"
void *value;
};

# 646 "<previous_module>"
struct lfds711_queue_umm_state
{
        
# 648 "<previous_module>"
struct lfds711_queue_umm_element * volatile enqueue[2];
        
# 649 "<previous_module>"
struct lfds711_queue_umm_element * volatile dequeue[2];
        
# 650 "<previous_module>"
lfds711_pal_uint_t aba_counter;
        
# 651 "<previous_module>"
void *user_state;
        
# 652 "<previous_module>"
struct lfds711_misc_backoff_state dequeue_backoff;
        
# 653 "<previous_module>"
struct lfds711_misc_backoff_state enqueue_backoff;
};

# 655 "<previous_module>"
void lfds711_queue_umm_init_valid_on_current_logical_core(struct lfds711_queue_umm_state *__cs_param__qumms, 
# 656 "<previous_module>"
struct lfds711_queue_umm_element *__cs_param__qumme_dummy, 
# 657 "<previous_module>"
void *__cs_param__user_state);

# 658 "<previous_module>"
void lfds711_queue_umm_cleanup(struct lfds711_queue_umm_state *__cs_param__qumms, 
# 659 "<previous_module>"
void (*__cs_param__element_cleanup_callback)(struct lfds711_queue_umm_state *qumms, struct lfds711_queue_umm_element *qumme, enum lfds711_misc_flag dummy_element_flag));

# 660 "<previous_module>"
void lfds711_queue_umm_enqueue(struct lfds711_queue_umm_state *__cs_param__qumms, 
# 661 "<previous_module>"
struct lfds711_queue_umm_element *__cs_param__qumme);

# 662 "<previous_module>"
int lfds711_queue_umm_dequeue(struct lfds711_queue_umm_state *__cs_param__qumms, 
# 663 "<previous_module>"
struct lfds711_queue_umm_element **__cs_param__qumme);

# 664 "<previous_module>"
void lfds711_queue_umm_query(struct lfds711_queue_umm_state *__cs_param__qumms, 
# 665 "<previous_module>"
enum lfds711_queue_umm_query __cs_param__query_type, 
# 666 "<previous_module>"
void *__cs_param__query_input, 
# 667 "<previous_module>"
void *__cs_param__query_output);

# 668 "<previous_module>"
enum lfds711_ringbuffer_query {LFDS711_RINGBUFFER_QUERY_SINGLETHREADED_GET_COUNT, LFDS711_RINGBUFFER_QUERY_SINGLETHREADED_VALIDATE};

# 669 "<previous_module>"
struct lfds711_ringbuffer_element
{
        
# 671 "<previous_module>"
struct lfds711_freelist_element fe;
        
# 672 "<previous_module>"
struct lfds711_queue_umm_element qumme;
        
# 673 "<previous_module>"
struct lfds711_queue_umm_element *qumme_use;
        
# 674 "<previous_module>"
void *key;
        
# 675 "<previous_module>"
void *value;
};

# 677 "<previous_module>"
struct lfds711_ringbuffer_state
{
        
# 679 "<previous_module>"
struct lfds711_freelist_state fs;
        
# 680 "<previous_module>"
struct lfds711_queue_umm_state qumms;
        
# 681 "<previous_module>"
void (*element_cleanup_callback)(struct lfds711_ringbuffer_state *__cs_param__rs, void *__cs_param__key, void *__cs_param__value, enum lfds711_misc_flag __cs_param__unread_flag);
        
# 682 "<previous_module>"
void *user_state;
};

# 684 "<previous_module>"
void lfds711_ringbuffer_init_valid_on_current_logical_core(struct lfds711_ringbuffer_state *__cs_param__rs, 
# 685 "<previous_module>"
struct lfds711_ringbuffer_element *__cs_param__re_array_inc_dummy, 
# 686 "<previous_module>"
lfds711_pal_uint_t __cs_param__number_elements_inc_dummy, 
# 687 "<previous_module>"
void *__cs_param__user_state);

# 688 "<previous_module>"
void lfds711_ringbuffer_cleanup(struct lfds711_ringbuffer_state *__cs_param__rs, 
# 689 "<previous_module>"
void (*__cs_param__element_cleanup_callback)(struct lfds711_ringbuffer_state *rs, void *key, void *value, enum lfds711_misc_flag unread_flag));

# 690 "<previous_module>"
int lfds711_ringbuffer_read(struct lfds711_ringbuffer_state *__cs_param__rs, 
# 691 "<previous_module>"
void **__cs_param__key, 
# 692 "<previous_module>"
void **__cs_param__value);

# 693 "<previous_module>"
void lfds711_ringbuffer_write(struct lfds711_ringbuffer_state *__cs_param__rs, 
# 694 "<previous_module>"
void *__cs_param__key, 
# 695 "<previous_module>"
void *__cs_param__value, 
# 696 "<previous_module>"
enum lfds711_misc_flag *__cs_param__overwrite_occurred_flag, 
# 697 "<previous_module>"
void **__cs_param__overwritten_key, 
# 698 "<previous_module>"
void **__cs_param__overwritten_value);

# 699 "<previous_module>"
void lfds711_ringbuffer_query(struct lfds711_ringbuffer_state *__cs_param__rs, 
# 700 "<previous_module>"
enum lfds711_ringbuffer_query __cs_param__query_type, 
# 701 "<previous_module>"
void *__cs_param__query_input, 
# 702 "<previous_module>"
void *__cs_param__query_output);

# 703 "<previous_module>"
enum lfds711_stack_query {LFDS711_STACK_QUERY_SINGLETHREADED_GET_COUNT, LFDS711_STACK_QUERY_SINGLETHREADED_VALIDATE};

# 704 "<previous_module>"
struct lfds711_stack_element
{
        
# 706 "<previous_module>"
struct lfds711_stack_element *next;
        
# 707 "<previous_module>"
void *key;
        
# 708 "<previous_module>"
void *value;
};

# 710 "<previous_module>"
struct lfds711_stack_state
{
        
# 712 "<previous_module>"
struct lfds711_stack_element * volatile top[2];
        
# 713 "<previous_module>"
void *user_state;
        
# 714 "<previous_module>"
struct lfds711_misc_backoff_state pop_backoff;
        
# 715 "<previous_module>"
struct lfds711_misc_backoff_state push_backoff;
};

# 717 "<previous_module>"
void lfds711_stack_init_valid_on_current_logical_core(struct lfds711_stack_state *__cs_param__ss, 
# 718 "<previous_module>"
void *__cs_param__user_state);

# 719 "<previous_module>"
void lfds711_stack_cleanup(struct lfds711_stack_state *__cs_param__ss, 
# 720 "<previous_module>"
void (*__cs_param__element_cleanup_callback)(struct lfds711_stack_state *ss, struct lfds711_stack_element *se));

# 721 "<previous_module>"
void lfds711_stack_push(struct lfds711_stack_state *__cs_param__ss, 
# 722 "<previous_module>"
struct lfds711_stack_element *__cs_param__se);

# 723 "<previous_module>"
int lfds711_stack_pop(struct lfds711_stack_state *__cs_param__ss, 
# 724 "<previous_module>"
struct lfds711_stack_element **__cs_param__se);

# 725 "<previous_module>"
void lfds711_stack_query(struct lfds711_stack_state *__cs_param__ss, 
# 726 "<previous_module>"
enum lfds711_stack_query __cs_param__query_type, 
# 727 "<previous_module>"
void *__cs_param__query_input, 
# 728 "<previous_module>"
void *__cs_param__query_output);

# 729 "<previous_module>"
#pragma warning( pop )

# 730 "<previous_module>"
void lfds711_misc_internal_backoff_init(struct lfds711_misc_backoff_state *__cs_param__bs);

# 731 "<previous_module>"
__cs_mutex_t library_lock;

# 732 "<previous_module>"
int __CSEQ_atomic_swap_stack_top(struct lfds711_stack_element * volatile *__cs_param___CSEQ_atomic_swap_stack_top_top, struct lfds711_stack_element * volatile *__cs_param___CSEQ_atomic_swap_stack_top_oldtop, 
# 733 "<previous_module>"
struct lfds711_stack_element **__cs_param___CSEQ_atomic_swap_stack_top_newtop)

# 734 "<previous_module>"
{
        
# 735 "<previous_module>"
;
        ;
        
# 736 "<previous_module>"
static _Bool __cs_local___CSEQ_atomic_swap_stack_top___cs_tmp_if_cond_0;
        
# 737 "<previous_module>"
__cs_local___CSEQ_atomic_swap_stack_top___cs_tmp_if_cond_0 = (*__cs_param___CSEQ_atomic_swap_stack_top_oldtop) == (*__cs_param___CSEQ_atomic_swap_stack_top_top);
        
# 738 "<previous_module>"
if (__cs_local___CSEQ_atomic_swap_stack_top___cs_tmp_if_cond_0)

# 739 "<previous_module>"
        {
                
# 740 "<previous_module>"
*__cs_param___CSEQ_atomic_swap_stack_top_top = *__cs_param___CSEQ_atomic_swap_stack_top_newtop;
                
# 741 "<previous_module>"
return 1;
                ;
        }
        else

# 744 "<previous_module>"
        {
                
# 745 "<previous_module>"
*__cs_param___CSEQ_atomic_swap_stack_top_oldtop = *__cs_param___CSEQ_atomic_swap_stack_top_top;
                
# 746 "<previous_module>"
return 0;
                ;
        }

        
# 748 "<previous_module>"
;
}


# 750 "<previous_module>"
_Bool __CSEQ_atomic_compare_and_exchange(int long long unsigned *__cs_param___CSEQ_atomic_compare_and_exchange_mptr, int long long unsigned *__cs_param___CSEQ_atomic_compare_and_exchange_eptr, int long long unsigned __cs_param___CSEQ_atomic_compare_and_exchange_newval, _Bool __cs_param___CSEQ_atomic_compare_and_exchange_weak_p, int __cs_param___CSEQ_atomic_compare_and_exchange_sm, int __cs_param___CSEQ_atomic_compare_and_exchange_fm)

# 751 "<previous_module>"
{
        
# 752 "<previous_module>"
;
        ;
        
# 753 "<previous_module>"
static _Bool __cs_local___CSEQ_atomic_compare_and_exchange___cs_tmp_if_cond_18;
        
# 754 "<previous_module>"
__cs_local___CSEQ_atomic_compare_and_exchange___cs_tmp_if_cond_18 = (*__cs_param___CSEQ_atomic_compare_and_exchange_mptr) == (*__cs_param___CSEQ_atomic_compare_and_exchange_eptr);
        
# 755 "<previous_module>"
if (__cs_local___CSEQ_atomic_compare_and_exchange___cs_tmp_if_cond_18)

# 756 "<previous_module>"
        {
                
# 757 "<previous_module>"
*__cs_param___CSEQ_atomic_compare_and_exchange_mptr = __cs_param___CSEQ_atomic_compare_and_exchange_newval;
                
# 758 "<previous_module>"
return 1;
                ;
        }
        else

# 761 "<previous_module>"
        {
                
# 762 "<previous_module>"
*__cs_param___CSEQ_atomic_compare_and_exchange_eptr = __cs_param___CSEQ_atomic_compare_and_exchange_newval;
                
# 763 "<previous_module>"
return 0;
                ;
        }

        
# 765 "<previous_module>"
;
}


# 767 "<previous_module>"
unsigned long __CSEQ_atomic_exchange(int long long unsigned *__cs_param___CSEQ_atomic_exchange_previous, int long long unsigned __cs_param___CSEQ_atomic_exchange_new, int __cs_param___CSEQ_atomic_exchange_memorder)

# 768 "<previous_module>"
{
        
# 769 "<previous_module>"
static unsigned long int __cs_local___CSEQ_atomic_exchange_old;
        
# 770 "<previous_module>"
__cs_local___CSEQ_atomic_exchange_old = *__cs_param___CSEQ_atomic_exchange_previous;
        
# 771 "<previous_module>"
*__cs_param___CSEQ_atomic_exchange_previous = __cs_param___CSEQ_atomic_exchange_new;
        
# 772 "<previous_module>"
return __cs_local___CSEQ_atomic_exchange_old;
        ;
}


# 774 "<previous_module>"
struct lfds711_stack_state mystack;

# 775 "<previous_module>"
struct test_data
{
        
# 777 "<previous_module>"
struct lfds711_stack_element se;
        
# 778 "<previous_module>"
int long long unsigned user_id;
};

# 780 "<previous_module>"
int ATOMIC_OPERATION = (0);

# 781 "<previous_module>"
void *ss;

# 782 "<previous_module>"
__cs_mutex_t lock;

# 783 "<previous_module>"
void *push_0(void *__cs_param_push___cs_unused)

# 784 "<previous_module>"
{
        
# 785 "<previous_module>"
static int long long unsigned __cs_local_push_loop;
        
# 786 "<previous_module>"
IF(1,0,tpush_0_1)__CSEQ_removeindent;
        
# 787 "<previous_module>"
__cs_local_push_loop = 0;

# 788 "<previous_module>"
        {
                
# 789 "<previous_module>"
;
                ;
                
# 790 "<previous_module>"
static _Bool __cs_local_push___cs_tmp_if_cond_24;
                
# 791 "<previous_module>"
tpush_0_1: IF(1,1,tpush_0_2)__CSEQ_removeindent;
                
# 792 "<previous_module>"
__cs_local_push___cs_tmp_if_cond_24 = ATOMIC_OPERATION;
                
# 793 "<previous_module>"
if (__cs_local_push___cs_tmp_if_cond_24)

# 794 "<previous_module>"
                {
                        
# 795 "<previous_module>"
tpush_0_2: IF(1,2,tpush_0_3)__CSEQ_removeindent;
                        
# 796 "<previous_module>"
__cs_mutex_lock(&lock, 1);
                }

                
# 798 "<previous_module>"
__CPROVER_assume(__cs_pc_cs[1] >= 3);
                ;
                
# 799 "<previous_module>"
;
                ;

# 800 "<previous_module>"
                {
                        
# 801 "<previous_module>"
static struct lfds711_stack_state *__cs_param_insert_s;
                        
# 802 "<previous_module>"
tpush_0_3: IF(1,3,tpush_0_4)__CSEQ_removeindent;
                        
# 803 "<previous_module>"
__cs_param_insert_s = ss;
                        
# 804 "<previous_module>"
static int long long unsigned __cs_param_insert_id;
                        
# 805 "<previous_module>"
__cs_param_insert_id = __cs_local_push_loop;
                        
# 806 "<previous_module>"
static struct test_data *__cs_local_insert_td;
                        
# 807 "<previous_module>"
tpush_0_4: IF(1,4,tpush_0_5)__CSEQ_removeindent;
                        
# 808 "<previous_module>"
__cs_local_insert_td = __cs_safe_malloc(sizeof(struct test_data));
                        
# 809 "<previous_module>"
tpush_0_5: IF(1,5,tpush_0_6)__CSEQ_removeindent;
                        
# 810 "<previous_module>"
(*__cs_local_insert_td).user_id = __cs_param_insert_id;
                        
# 811 "<previous_module>"
tpush_0_6: IF(1,6,tpush_0_7)__CSEQ_removeindent;
                        
# 812 "<previous_module>"
(*__cs_local_insert_td).se.value = (void *) ((lfds711_pal_uint_t) __cs_local_insert_td);

# 813 "<previous_module>"
                        {
                                
# 814 "<previous_module>"
static struct lfds711_stack_state *__cs_param_lfds711_stack_push_ss;
                                
# 815 "<previous_module>"
tpush_0_7: IF(1,7,tpush_0_8)__CSEQ_removeindent;
                                
# 816 "<previous_module>"
__cs_param_lfds711_stack_push_ss = (struct lfds711_stack_state *) __cs_param_insert_s;
                                
# 817 "<previous_module>"
static struct lfds711_stack_element *__cs_param_lfds711_stack_push_se;
                                
# 818 "<previous_module>"
tpush_0_8: IF(1,8,tpush_0_9)__CSEQ_removeindent;
                                
# 819 "<previous_module>"
__cs_param_lfds711_stack_push_se = &(*__cs_local_insert_td).se;
                                
# 820 "<previous_module>"
static char unsigned __cs_local_lfds711_stack_push_result;
                                
# 821 "<previous_module>"
static lfds711_pal_uint_t __cs_local_lfds711_stack_push_backoff_iteration;
                                
# 822 "<previous_module>"
__cs_local_lfds711_stack_push_backoff_iteration = 0;
                                
# 823 "<previous_module>"
static struct lfds711_stack_element *__cs_local_lfds711_stack_push_new_top[2];
                                
# 824 "<previous_module>"
static struct lfds711_stack_element * volatile __cs_local_lfds711_stack_push_original_top[2];
                                
# 825 "<previous_module>"
;
                                ;
                                
# 826 "<previous_module>"
static _Bool __cs_local_lfds711_stack_push___cs_tmp_if_cond_14;
                                
# 827 "<previous_module>"
tpush_0_9: IF(1,9,tpush_0_10)__CSEQ_removeindent;
                                
# 828 "<previous_module>"
__cs_local_lfds711_stack_push___cs_tmp_if_cond_14 = !(__cs_param_lfds711_stack_push_ss != 0);
                                
# 829 "<previous_module>"
if (__cs_local_lfds711_stack_push___cs_tmp_if_cond_14)

# 830 "<previous_module>"
                                {
                                        
# 831 "<previous_module>"
static char *__cs_local_lfds711_stack_push_c;
                                        
# 832 "<previous_module>"
tpush_0_10: IF(1,10,tpush_0_11)__CSEQ_removeindent;
                                        
# 833 "<previous_module>"
__cs_local_lfds711_stack_push_c = 0;
                                        
# 834 "<previous_module>"
tpush_0_11: IF(1,11,tpush_0_12)__CSEQ_removeindent;
                                        
# 835 "<previous_module>"
*__cs_local_lfds711_stack_push_c = 0;
                                }

                                
# 837 "<previous_module>"
__CPROVER_assume(__cs_pc_cs[1] >= 12);
                                ;
                                
# 838 "<previous_module>"
;
                                ;
                                
# 839 "<previous_module>"
;
                                ;
                                
# 840 "<previous_module>"
;
                                ;
                                
# 841 "<previous_module>"
static _Bool __cs_local_lfds711_stack_push___cs_tmp_if_cond_15;
                                
# 842 "<previous_module>"
tpush_0_12: IF(1,12,tpush_0_13)__CSEQ_removeindent;
                                
# 843 "<previous_module>"
__cs_local_lfds711_stack_push___cs_tmp_if_cond_15 = !(__cs_param_lfds711_stack_push_se != 0);
                                
# 844 "<previous_module>"
if (__cs_local_lfds711_stack_push___cs_tmp_if_cond_15)

# 845 "<previous_module>"
                                {
                                        
# 846 "<previous_module>"
static char *__cs_local_lfds711_stack_push_c;
                                        
# 847 "<previous_module>"
tpush_0_13: IF(1,13,tpush_0_14)__CSEQ_removeindent;
                                        
# 848 "<previous_module>"
__cs_local_lfds711_stack_push_c = 0;
                                        
# 849 "<previous_module>"
tpush_0_14: IF(1,14,tpush_0_15)__CSEQ_removeindent;
                                        
# 850 "<previous_module>"
*__cs_local_lfds711_stack_push_c = 0;
                                }

                                
# 852 "<previous_module>"
__CPROVER_assume(__cs_pc_cs[1] >= 15);
                                ;
                                
# 853 "<previous_module>"
;
                                ;
                                
# 854 "<previous_module>"
;
                                ;
                                
# 855 "<previous_module>"
tpush_0_15: IF(1,15,tpush_0_16)__CSEQ_removeindent;
                                
# 856 "<previous_module>"
__cs_local_lfds711_stack_push_new_top[0] = __cs_param_lfds711_stack_push_se;
                                
# 857 "<previous_module>"
tpush_0_16: IF(1,16,tpush_0_17)__CSEQ_removeindent;
                                
# 858 "<previous_module>"
__cs_local_lfds711_stack_push_original_top[1] = (*__cs_param_lfds711_stack_push_ss).top[1];
                                
# 859 "<previous_module>"
tpush_0_17: IF(1,17,tpush_0_18)__CSEQ_removeindent;
                                
# 860 "<previous_module>"
__cs_local_lfds711_stack_push_original_top[0] = (*__cs_param_lfds711_stack_push_ss).top[0];
                                
# 861 "<previous_module>"
__cs_local_lfds711_stack_push_result = 0;
                                
# 862 "<previous_module>"
static int __cs_local_lfds711_stack_push_i;
                                
# 863 "<previous_module>"
__cs_local_lfds711_stack_push_i = 0;
                                
# 864 "<previous_module>"
if (!(__cs_local_lfds711_stack_push_result == 0))

# 865 "<previous_module>"
                                {
                                        
# 866 "<previous_module>"
goto __exit_loop_2;
                                        ;
                                }

                                
# 868 "<previous_module>"
;

# 869 "<previous_module>"
                                {
                                        
# 870 "<previous_module>"
tpush_0_18: IF(1,18,tpush_0_19)__CSEQ_removeindent;
                                        
# 871 "<previous_module>"
__cs_mutex_lock(&library_lock, 1);
                                        
# 872 "<previous_module>"
tpush_0_19: IF(1,19,tpush_0_20)__CSEQ_removeindent;
                                        
# 873 "<previous_module>"
(*__cs_param_lfds711_stack_push_se).next = __cs_local_lfds711_stack_push_original_top[0];
                                        
# 874 "<previous_module>"
tpush_0_20: IF(1,20,tpush_0_21)__CSEQ_removeindent;
                                        
# 875 "<previous_module>"
__cs_mutex_unlock(&library_lock, 1);
                                        
# 876 "<previous_module>"
tpush_0_21: IF(1,21,tpush_0_22)__CSEQ_removeindent;
                                        
# 877 "<previous_module>"
__cs_local_lfds711_stack_push_new_top[1] = __cs_local_lfds711_stack_push_original_top[1] + 1;
                                        
# 878 "<previous_module>"
tpush_0_22: IF(1,22,tpush_0_23)__CSEQ_removeindent;
                                        
# 879 "<previous_module>"
__cs_mutex_lock(&library_lock, 1);
                                        
# 880 "<previous_module>"
tpush_0_23: IF(1,23,tpush_0_24)__CSEQ_removeindent;
                                        
# 881 "<previous_module>"
__cs_local_lfds711_stack_push_result = __CSEQ_atomic_swap_stack_top(&(*__cs_param_lfds711_stack_push_ss).top[0], &__cs_local_lfds711_stack_push_original_top[0], &__cs_local_lfds711_stack_push_new_top[0]);
                                        
# 882 "<previous_module>"
tpush_0_24: IF(1,24,tpush_0_25)__CSEQ_removeindent;
                                        
# 883 "<previous_module>"
__cs_mutex_unlock(&library_lock, 1);
                                        
# 884 "<previous_module>"
;
                                        ;
                                        
# 885 "<previous_module>"
static _Bool __cs_local_lfds711_stack_push___cs_tmp_if_cond_16;
                                        
# 886 "<previous_module>"
__cs_local_lfds711_stack_push___cs_tmp_if_cond_16 = __cs_local_lfds711_stack_push_result == 0;
                                        
# 887 "<previous_module>"
if (__cs_local_lfds711_stack_push___cs_tmp_if_cond_16)

# 888 "<previous_module>"
                                        {

# 889 "<previous_module>"
                                                {
                                                        
# 890 "<previous_module>"
static int __cs_local_exponential_backoff_loop;
                                                        
# 891 "<previous_module>"
__cs_local_exponential_backoff_loop = 0;

# 892 "<previous_module>"
                                                        {
                                                                
# 893 "<previous_module>"
;
                                                                ;
                                                        }
                                                        
# 895 "<previous_module>"
;
                                                        
# 896 "<previous_module>"
__cs_local_exponential_backoff_loop++;

# 897 "<previous_module>"
                                                        {
                                                                
# 898 "<previous_module>"
;
                                                                ;
                                                        }
                                                        
# 900 "<previous_module>"
;
                                                        
# 901 "<previous_module>"
__cs_local_exponential_backoff_loop++;

# 902 "<previous_module>"
                                                        {
                                                                
# 903 "<previous_module>"
;
                                                                ;
                                                        }
                                                        
# 905 "<previous_module>"
;
                                                        
# 906 "<previous_module>"
__cs_local_exponential_backoff_loop++;
                                                        
# 907 "<previous_module>"
tpush_0_25: IF(1,25,tpush_0_26)__CSEQ_removeindent;
                                                        
# 908 "<previous_module>"
__CPROVER_assume(!(__cs_local_exponential_backoff_loop < 3));
                                                        
# 909 "<previous_module>"
__exit_loop_3:
                                                        __CPROVER_assume(__cs_pc_cs[1] >= 26);

                                                        
# 910 "<previous_module>"
;
                                                        ;
                                                        
# 911 "<previous_module>"
__exit__exponential_backoff_1_0:
                                                        __CPROVER_assume(__cs_pc_cs[1] >= 26);

                                                        
# 912 "<previous_module>"
;
                                                        ;
                                                }
                                                
# 914 "<previous_module>"
;
                                        }

                                        
# 916 "<previous_module>"
__CPROVER_assume(__cs_pc_cs[1] >= 26);
                                        ;
                                        
# 917 "<previous_module>"
__cs_local_lfds711_stack_push_i++;
                                        
# 918 "<previous_module>"
;
                                        ;
                                        
# 919 "<previous_module>"
static _Bool __cs_local_lfds711_stack_push___cs_tmp_if_cond_17;
                                        
# 920 "<previous_module>"
__cs_local_lfds711_stack_push___cs_tmp_if_cond_17 = __cs_local_lfds711_stack_push_i > 1000;
                                        
# 921 "<previous_module>"
if (__cs_local_lfds711_stack_push___cs_tmp_if_cond_17)

# 922 "<previous_module>"
                                        {
                                                
# 923 "<previous_module>"
goto __exit_loop_2;
                                                ;
                                        }

                                        
# 925 "<previous_module>"
;
                                }
                                
# 927 "<previous_module>"
;
                                
# 928 "<previous_module>"
if (!(__cs_local_lfds711_stack_push_result == 0))

# 929 "<previous_module>"
                                {
                                        
# 930 "<previous_module>"
goto __exit_loop_2;
                                        ;
                                }

                                
# 932 "<previous_module>"
;

# 933 "<previous_module>"
                                {
                                        
# 934 "<previous_module>"
tpush_0_26: IF(1,26,tpush_0_27)__CSEQ_removeindent;
                                        
# 935 "<previous_module>"
__cs_mutex_lock(&library_lock, 1);
                                        
# 936 "<previous_module>"
tpush_0_27: IF(1,27,tpush_0_28)__CSEQ_removeindent;
                                        
# 937 "<previous_module>"
(*__cs_param_lfds711_stack_push_se).next = __cs_local_lfds711_stack_push_original_top[0];
                                        
# 938 "<previous_module>"
tpush_0_28: IF(1,28,tpush_0_29)__CSEQ_removeindent;
                                        
# 939 "<previous_module>"
__cs_mutex_unlock(&library_lock, 1);
                                        
# 940 "<previous_module>"
tpush_0_29: IF(1,29,tpush_0_30)__CSEQ_removeindent;
                                        
# 941 "<previous_module>"
__cs_local_lfds711_stack_push_new_top[1] = __cs_local_lfds711_stack_push_original_top[1] + 1;
                                        
# 942 "<previous_module>"
tpush_0_30: IF(1,30,tpush_0_31)__CSEQ_removeindent;
                                        
# 943 "<previous_module>"
__cs_mutex_lock(&library_lock, 1);
                                        
# 944 "<previous_module>"
tpush_0_31: IF(1,31,tpush_0_32)__CSEQ_removeindent;
                                        
# 945 "<previous_module>"
__cs_local_lfds711_stack_push_result = __CSEQ_atomic_swap_stack_top(&(*__cs_param_lfds711_stack_push_ss).top[0], &__cs_local_lfds711_stack_push_original_top[0], &__cs_local_lfds711_stack_push_new_top[0]);
                                        
# 946 "<previous_module>"
tpush_0_32: IF(1,32,tpush_0_33)__CSEQ_removeindent;
                                        
# 947 "<previous_module>"
__cs_mutex_unlock(&library_lock, 1);
                                        
# 948 "<previous_module>"
;
                                        ;
                                        
# 949 "<previous_module>"
static _Bool __cs_local_lfds711_stack_push___cs_tmp_if_cond_16;
                                        
# 950 "<previous_module>"
__cs_local_lfds711_stack_push___cs_tmp_if_cond_16 = __cs_local_lfds711_stack_push_result == 0;
                                        
# 951 "<previous_module>"
if (__cs_local_lfds711_stack_push___cs_tmp_if_cond_16)

# 952 "<previous_module>"
                                        {

# 953 "<previous_module>"
                                                {
                                                        
# 954 "<previous_module>"
static int __cs_local_exponential_backoff_loop;
                                                        
# 955 "<previous_module>"
__cs_local_exponential_backoff_loop = 0;

# 956 "<previous_module>"
                                                        {
                                                                
# 957 "<previous_module>"
;
                                                                ;
                                                        }
                                                        
# 959 "<previous_module>"
;
                                                        
# 960 "<previous_module>"
__cs_local_exponential_backoff_loop++;

# 961 "<previous_module>"
                                                        {
                                                                
# 962 "<previous_module>"
;
                                                                ;
                                                        }
                                                        
# 964 "<previous_module>"
;
                                                        
# 965 "<previous_module>"
__cs_local_exponential_backoff_loop++;

# 966 "<previous_module>"
                                                        {
                                                                
# 967 "<previous_module>"
;
                                                                ;
                                                        }
                                                        
# 969 "<previous_module>"
;
                                                        
# 970 "<previous_module>"
__cs_local_exponential_backoff_loop++;
                                                        
# 971 "<previous_module>"
tpush_0_33: IF(1,33,tpush_0_34)__CSEQ_removeindent;
                                                        
# 972 "<previous_module>"
__CPROVER_assume(!(__cs_local_exponential_backoff_loop < 3));
                                                        
# 973 "<previous_module>"
__exit_loop_4:
                                                        __CPROVER_assume(__cs_pc_cs[1] >= 34);

                                                        
# 974 "<previous_module>"
;
                                                        ;
                                                        
# 975 "<previous_module>"
__exit__exponential_backoff_1_1:
                                                        __CPROVER_assume(__cs_pc_cs[1] >= 34);

                                                        
# 976 "<previous_module>"
;
                                                        ;
                                                }
                                                
# 978 "<previous_module>"
;
                                        }

                                        
# 980 "<previous_module>"
__CPROVER_assume(__cs_pc_cs[1] >= 34);
                                        ;
                                        
# 981 "<previous_module>"
__cs_local_lfds711_stack_push_i++;
                                        
# 982 "<previous_module>"
;
                                        ;
                                        
# 983 "<previous_module>"
static _Bool __cs_local_lfds711_stack_push___cs_tmp_if_cond_17;
                                        
# 984 "<previous_module>"
__cs_local_lfds711_stack_push___cs_tmp_if_cond_17 = __cs_local_lfds711_stack_push_i > 1000;
                                        
# 985 "<previous_module>"
if (__cs_local_lfds711_stack_push___cs_tmp_if_cond_17)

# 986 "<previous_module>"
                                        {
                                                
# 987 "<previous_module>"
goto __exit_loop_2;
                                                ;
                                        }

                                        
# 989 "<previous_module>"
;
                                }
                                
# 991 "<previous_module>"
;
                                
# 992 "<previous_module>"
if (!(__cs_local_lfds711_stack_push_result == 0))

# 993 "<previous_module>"
                                {
                                        
# 994 "<previous_module>"
goto __exit_loop_2;
                                        ;
                                }

                                
# 996 "<previous_module>"
;

# 997 "<previous_module>"
                                {
                                        
# 998 "<previous_module>"
tpush_0_34: IF(1,34,tpush_0_35)__CSEQ_removeindent;
                                        
# 999 "<previous_module>"
__cs_mutex_lock(&library_lock, 1);
                                        
# 1000 "<previous_module>"
tpush_0_35: IF(1,35,tpush_0_36)__CSEQ_removeindent;
                                        
# 1001 "<previous_module>"
(*__cs_param_lfds711_stack_push_se).next = __cs_local_lfds711_stack_push_original_top[0];
                                        
# 1002 "<previous_module>"
tpush_0_36: IF(1,36,tpush_0_37)__CSEQ_removeindent;
                                        
# 1003 "<previous_module>"
__cs_mutex_unlock(&library_lock, 1);
                                        
# 1004 "<previous_module>"
tpush_0_37: IF(1,37,tpush_0_38)__CSEQ_removeindent;
                                        
# 1005 "<previous_module>"
__cs_local_lfds711_stack_push_new_top[1] = __cs_local_lfds711_stack_push_original_top[1] + 1;
                                        
# 1006 "<previous_module>"
tpush_0_38: IF(1,38,tpush_0_39)__CSEQ_removeindent;
                                        
# 1007 "<previous_module>"
__cs_mutex_lock(&library_lock, 1);
                                        
# 1008 "<previous_module>"
tpush_0_39: IF(1,39,tpush_0_40)__CSEQ_removeindent;
                                        
# 1009 "<previous_module>"
__cs_local_lfds711_stack_push_result = __CSEQ_atomic_swap_stack_top(&(*__cs_param_lfds711_stack_push_ss).top[0], &__cs_local_lfds711_stack_push_original_top[0], &__cs_local_lfds711_stack_push_new_top[0]);
                                        
# 1010 "<previous_module>"
tpush_0_40: IF(1,40,tpush_0_41)__CSEQ_removeindent;
                                        
# 1011 "<previous_module>"
__cs_mutex_unlock(&library_lock, 1);
                                        
# 1012 "<previous_module>"
;
                                        ;
                                        
# 1013 "<previous_module>"
static _Bool __cs_local_lfds711_stack_push___cs_tmp_if_cond_16;
                                        
# 1014 "<previous_module>"
__cs_local_lfds711_stack_push___cs_tmp_if_cond_16 = __cs_local_lfds711_stack_push_result == 0;
                                        
# 1015 "<previous_module>"
if (__cs_local_lfds711_stack_push___cs_tmp_if_cond_16)

# 1016 "<previous_module>"
                                        {

# 1017 "<previous_module>"
                                                {
                                                        
# 1018 "<previous_module>"
static int __cs_local_exponential_backoff_loop;
                                                        
# 1019 "<previous_module>"
__cs_local_exponential_backoff_loop = 0;

# 1020 "<previous_module>"
                                                        {
                                                                
# 1021 "<previous_module>"
;
                                                                ;
                                                        }
                                                        
# 1023 "<previous_module>"
;
                                                        
# 1024 "<previous_module>"
__cs_local_exponential_backoff_loop++;

# 1025 "<previous_module>"
                                                        {
                                                                
# 1026 "<previous_module>"
;
                                                                ;
                                                        }
                                                        
# 1028 "<previous_module>"
;
                                                        
# 1029 "<previous_module>"
__cs_local_exponential_backoff_loop++;

# 1030 "<previous_module>"
                                                        {
                                                                
# 1031 "<previous_module>"
;
                                                                ;
                                                        }
                                                        
# 1033 "<previous_module>"
;
                                                        
# 1034 "<previous_module>"
__cs_local_exponential_backoff_loop++;
                                                        
# 1035 "<previous_module>"
tpush_0_41: IF(1,41,tpush_0_42)__CSEQ_removeindent;
                                                        
# 1036 "<previous_module>"
__CPROVER_assume(!(__cs_local_exponential_backoff_loop < 3));
                                                        
# 1037 "<previous_module>"
__exit_loop_5:
                                                        __CPROVER_assume(__cs_pc_cs[1] >= 42);

                                                        
# 1038 "<previous_module>"
;
                                                        ;
                                                        
# 1039 "<previous_module>"
__exit__exponential_backoff_1_2:
                                                        __CPROVER_assume(__cs_pc_cs[1] >= 42);

                                                        
# 1040 "<previous_module>"
;
                                                        ;
                                                }
                                                
# 1042 "<previous_module>"
;
                                        }

                                        
# 1044 "<previous_module>"
__CPROVER_assume(__cs_pc_cs[1] >= 42);
                                        ;
                                        
# 1045 "<previous_module>"
__cs_local_lfds711_stack_push_i++;
                                        
# 1046 "<previous_module>"
;
                                        ;
                                        
# 1047 "<previous_module>"
static _Bool __cs_local_lfds711_stack_push___cs_tmp_if_cond_17;
                                        
# 1048 "<previous_module>"
__cs_local_lfds711_stack_push___cs_tmp_if_cond_17 = __cs_local_lfds711_stack_push_i > 1000;
                                        
# 1049 "<previous_module>"
if (__cs_local_lfds711_stack_push___cs_tmp_if_cond_17)

# 1050 "<previous_module>"
                                        {
                                                
# 1051 "<previous_module>"
goto __exit_loop_2;
                                                ;
                                        }

                                        
# 1053 "<previous_module>"
;
                                }
                                
# 1055 "<previous_module>"
;
                                
# 1056 "<previous_module>"
if (!(__cs_local_lfds711_stack_push_result == 0))

# 1057 "<previous_module>"
                                {
                                        
# 1058 "<previous_module>"
goto __exit_loop_2;
                                        ;
                                }

                                
# 1060 "<previous_module>"
;

# 1061 "<previous_module>"
                                {
                                        
# 1062 "<previous_module>"
tpush_0_42: IF(1,42,tpush_0_43)__CSEQ_removeindent;
                                        
# 1063 "<previous_module>"
__cs_mutex_lock(&library_lock, 1);
                                        
# 1064 "<previous_module>"
tpush_0_43: IF(1,43,tpush_0_44)__CSEQ_removeindent;
                                        
# 1065 "<previous_module>"
(*__cs_param_lfds711_stack_push_se).next = __cs_local_lfds711_stack_push_original_top[0];
                                        
# 1066 "<previous_module>"
tpush_0_44: IF(1,44,tpush_0_45)__CSEQ_removeindent;
                                        
# 1067 "<previous_module>"
__cs_mutex_unlock(&library_lock, 1);
                                        
# 1068 "<previous_module>"
tpush_0_45: IF(1,45,tpush_0_46)__CSEQ_removeindent;
                                        
# 1069 "<previous_module>"
__cs_local_lfds711_stack_push_new_top[1] = __cs_local_lfds711_stack_push_original_top[1] + 1;
                                        
# 1070 "<previous_module>"
tpush_0_46: IF(1,46,tpush_0_47)__CSEQ_removeindent;
                                        
# 1071 "<previous_module>"
__cs_mutex_lock(&library_lock, 1);
                                        
# 1072 "<previous_module>"
tpush_0_47: IF(1,47,tpush_0_48)__CSEQ_removeindent;
                                        
# 1073 "<previous_module>"
__cs_local_lfds711_stack_push_result = __CSEQ_atomic_swap_stack_top(&(*__cs_param_lfds711_stack_push_ss).top[0], &__cs_local_lfds711_stack_push_original_top[0], &__cs_local_lfds711_stack_push_new_top[0]);
                                        
# 1074 "<previous_module>"
tpush_0_48: IF(1,48,tpush_0_49)__CSEQ_removeindent;
                                        
# 1075 "<previous_module>"
__cs_mutex_unlock(&library_lock, 1);
                                        
# 1076 "<previous_module>"
;
                                        ;
                                        
# 1077 "<previous_module>"
static _Bool __cs_local_lfds711_stack_push___cs_tmp_if_cond_16;
                                        
# 1078 "<previous_module>"
__cs_local_lfds711_stack_push___cs_tmp_if_cond_16 = __cs_local_lfds711_stack_push_result == 0;
                                        
# 1079 "<previous_module>"
if (__cs_local_lfds711_stack_push___cs_tmp_if_cond_16)

# 1080 "<previous_module>"
                                        {

# 1081 "<previous_module>"
                                                {
                                                        
# 1082 "<previous_module>"
static int __cs_local_exponential_backoff_loop;
                                                        
# 1083 "<previous_module>"
__cs_local_exponential_backoff_loop = 0;

# 1084 "<previous_module>"
                                                        {
                                                                
# 1085 "<previous_module>"
;
                                                                ;
                                                        }
                                                        
# 1087 "<previous_module>"
;
                                                        
# 1088 "<previous_module>"
__cs_local_exponential_backoff_loop++;

# 1089 "<previous_module>"
                                                        {
                                                                
# 1090 "<previous_module>"
;
                                                                ;
                                                        }
                                                        
# 1092 "<previous_module>"
;
                                                        
# 1093 "<previous_module>"
__cs_local_exponential_backoff_loop++;

# 1094 "<previous_module>"
                                                        {
                                                                
# 1095 "<previous_module>"
;
                                                                ;
                                                        }
                                                        
# 1097 "<previous_module>"
;
                                                        
# 1098 "<previous_module>"
__cs_local_exponential_backoff_loop++;
                                                        
# 1099 "<previous_module>"
tpush_0_49: IF(1,49,tpush_0_50)__CSEQ_removeindent;
                                                        
# 1100 "<previous_module>"
__CPROVER_assume(!(__cs_local_exponential_backoff_loop < 3));
                                                        
# 1101 "<previous_module>"
__exit_loop_6:
                                                        __CPROVER_assume(__cs_pc_cs[1] >= 50);

                                                        
# 1102 "<previous_module>"
;
                                                        ;
                                                        
# 1103 "<previous_module>"
__exit__exponential_backoff_1_3:
                                                        __CPROVER_assume(__cs_pc_cs[1] >= 50);

                                                        
# 1104 "<previous_module>"
;
                                                        ;
                                                }
                                                
# 1106 "<previous_module>"
;
                                        }

                                        
# 1108 "<previous_module>"
__CPROVER_assume(__cs_pc_cs[1] >= 50);
                                        ;
                                        
# 1109 "<previous_module>"
__cs_local_lfds711_stack_push_i++;
                                        
# 1110 "<previous_module>"
;
                                        ;
                                        
# 1111 "<previous_module>"
static _Bool __cs_local_lfds711_stack_push___cs_tmp_if_cond_17;
                                        
# 1112 "<previous_module>"
__cs_local_lfds711_stack_push___cs_tmp_if_cond_17 = __cs_local_lfds711_stack_push_i > 1000;
                                        
# 1113 "<previous_module>"
if (__cs_local_lfds711_stack_push___cs_tmp_if_cond_17)

# 1114 "<previous_module>"
                                        {
                                                
# 1115 "<previous_module>"
goto __exit_loop_2;
                                                ;
                                        }

                                        
# 1117 "<previous_module>"
;
                                }
                                
# 1119 "<previous_module>"
;
                                
# 1120 "<previous_module>"
if (!(__cs_local_lfds711_stack_push_result == 0))

# 1121 "<previous_module>"
                                {
                                        
# 1122 "<previous_module>"
goto __exit_loop_2;
                                        ;
                                }

                                
# 1124 "<previous_module>"
;

# 1125 "<previous_module>"
                                {
                                        
# 1126 "<previous_module>"
tpush_0_50: IF(1,50,tpush_0_51)__CSEQ_removeindent;
                                        
# 1127 "<previous_module>"
__cs_mutex_lock(&library_lock, 1);
                                        
# 1128 "<previous_module>"
tpush_0_51: IF(1,51,tpush_0_52)__CSEQ_removeindent;
                                        
# 1129 "<previous_module>"
(*__cs_param_lfds711_stack_push_se).next = __cs_local_lfds711_stack_push_original_top[0];
                                        
# 1130 "<previous_module>"
tpush_0_52: IF(1,52,tpush_0_53)__CSEQ_removeindent;
                                        
# 1131 "<previous_module>"
__cs_mutex_unlock(&library_lock, 1);
                                        
# 1132 "<previous_module>"
tpush_0_53: IF(1,53,tpush_0_54)__CSEQ_removeindent;
                                        
# 1133 "<previous_module>"
__cs_local_lfds711_stack_push_new_top[1] = __cs_local_lfds711_stack_push_original_top[1] + 1;
                                        
# 1134 "<previous_module>"
tpush_0_54: IF(1,54,tpush_0_55)__CSEQ_removeindent;
                                        
# 1135 "<previous_module>"
__cs_mutex_lock(&library_lock, 1);
                                        
# 1136 "<previous_module>"
tpush_0_55: IF(1,55,tpush_0_56)__CSEQ_removeindent;
                                        
# 1137 "<previous_module>"
__cs_local_lfds711_stack_push_result = __CSEQ_atomic_swap_stack_top(&(*__cs_param_lfds711_stack_push_ss).top[0], &__cs_local_lfds711_stack_push_original_top[0], &__cs_local_lfds711_stack_push_new_top[0]);
                                        
# 1138 "<previous_module>"
tpush_0_56: IF(1,56,tpush_0_57)__CSEQ_removeindent;
                                        
# 1139 "<previous_module>"
__cs_mutex_unlock(&library_lock, 1);
                                        
# 1140 "<previous_module>"
;
                                        ;
                                        
# 1141 "<previous_module>"
static _Bool __cs_local_lfds711_stack_push___cs_tmp_if_cond_16;
                                        
# 1142 "<previous_module>"
__cs_local_lfds711_stack_push___cs_tmp_if_cond_16 = __cs_local_lfds711_stack_push_result == 0;
                                        
# 1143 "<previous_module>"
if (__cs_local_lfds711_stack_push___cs_tmp_if_cond_16)

# 1144 "<previous_module>"
                                        {

# 1145 "<previous_module>"
                                                {
                                                        
# 1146 "<previous_module>"
static int __cs_local_exponential_backoff_loop;
                                                        
# 1147 "<previous_module>"
__cs_local_exponential_backoff_loop = 0;

# 1148 "<previous_module>"
                                                        {
                                                                
# 1149 "<previous_module>"
;
                                                                ;
                                                        }
                                                        
# 1151 "<previous_module>"
;
                                                        
# 1152 "<previous_module>"
__cs_local_exponential_backoff_loop++;

# 1153 "<previous_module>"
                                                        {
                                                                
# 1154 "<previous_module>"
;
                                                                ;
                                                        }
                                                        
# 1156 "<previous_module>"
;
                                                        
# 1157 "<previous_module>"
__cs_local_exponential_backoff_loop++;

# 1158 "<previous_module>"
                                                        {
                                                                
# 1159 "<previous_module>"
;
                                                                ;
                                                        }
                                                        
# 1161 "<previous_module>"
;
                                                        
# 1162 "<previous_module>"
__cs_local_exponential_backoff_loop++;
                                                        
# 1163 "<previous_module>"
tpush_0_57: IF(1,57,tpush_0_58)__CSEQ_removeindent;
                                                        
# 1164 "<previous_module>"
__CPROVER_assume(!(__cs_local_exponential_backoff_loop < 3));
                                                        
# 1165 "<previous_module>"
__exit_loop_7:
                                                        __CPROVER_assume(__cs_pc_cs[1] >= 58);

                                                        
# 1166 "<previous_module>"
;
                                                        ;
                                                        
# 1167 "<previous_module>"
__exit__exponential_backoff_1_4:
                                                        __CPROVER_assume(__cs_pc_cs[1] >= 58);

                                                        
# 1168 "<previous_module>"
;
                                                        ;
                                                }
                                                
# 1170 "<previous_module>"
;
                                        }

                                        
# 1172 "<previous_module>"
__CPROVER_assume(__cs_pc_cs[1] >= 58);
                                        ;
                                        
# 1173 "<previous_module>"
__cs_local_lfds711_stack_push_i++;
                                        
# 1174 "<previous_module>"
;
                                        ;
                                        
# 1175 "<previous_module>"
static _Bool __cs_local_lfds711_stack_push___cs_tmp_if_cond_17;
                                        
# 1176 "<previous_module>"
__cs_local_lfds711_stack_push___cs_tmp_if_cond_17 = __cs_local_lfds711_stack_push_i > 1000;
                                        
# 1177 "<previous_module>"
if (__cs_local_lfds711_stack_push___cs_tmp_if_cond_17)

# 1178 "<previous_module>"
                                        {
                                                
# 1179 "<previous_module>"
goto __exit_loop_2;
                                                ;
                                        }

                                        
# 1181 "<previous_module>"
;
                                }
                                
# 1183 "<previous_module>"
;
                                
# 1184 "<previous_module>"
tpush_0_58: IF(1,58,tpush_0_59)__CSEQ_removeindent;
                                
# 1185 "<previous_module>"
__CPROVER_assume(!(__cs_local_lfds711_stack_push_result == 0));
                                
# 1186 "<previous_module>"
__exit_loop_2:
                                __CPROVER_assume(__cs_pc_cs[1] >= 59);

                                
# 1187 "<previous_module>"
;
                                ;
                                
# 1188 "<previous_module>"
goto __exit__lfds711_stack_push_1_0;
                                ;
                                
# 1189 "<previous_module>"
__exit__lfds711_stack_push_1_0:
                                __CPROVER_assume(__cs_pc_cs[1] >= 59);

                                
# 1190 "<previous_module>"
;
                                ;
                        }
                        
# 1192 "<previous_module>"
;
                        
# 1193 "<previous_module>"
__exit__insert_1_0:
                        __CPROVER_assume(__cs_pc_cs[1] >= 59);

                        
# 1194 "<previous_module>"
;
                        ;
                }
                
# 1196 "<previous_module>"
;
                
# 1197 "<previous_module>"
;
                ;
                
# 1198 "<previous_module>"
static _Bool __cs_local_push___cs_tmp_if_cond_25;
                
# 1199 "<previous_module>"
tpush_0_59: IF(1,59,tpush_0_60)__CSEQ_removeindent;
                
# 1200 "<previous_module>"
__cs_local_push___cs_tmp_if_cond_25 = ATOMIC_OPERATION;
                
# 1201 "<previous_module>"
if (__cs_local_push___cs_tmp_if_cond_25)

# 1202 "<previous_module>"
                {
                        
# 1203 "<previous_module>"
tpush_0_60: IF(1,60,tpush_0_61)__CSEQ_removeindent;
                        
# 1204 "<previous_module>"
__cs_mutex_unlock(&lock, 1);
                }

                
# 1206 "<previous_module>"
__CPROVER_assume(__cs_pc_cs[1] >= 61);
                ;
                
# 1207 "<previous_module>"
;
                ;
        }
        
# 1209 "<previous_module>"
;
        
# 1210 "<previous_module>"
__cs_local_push_loop++;

# 1211 "<previous_module>"
        {
                
# 1212 "<previous_module>"
;
                ;
                
# 1213 "<previous_module>"
static _Bool __cs_local_push___cs_tmp_if_cond_24;
                
# 1214 "<previous_module>"
tpush_0_61: IF(1,61,tpush_0_62)__CSEQ_removeindent;
                
# 1215 "<previous_module>"
__cs_local_push___cs_tmp_if_cond_24 = ATOMIC_OPERATION;
                
# 1216 "<previous_module>"
if (__cs_local_push___cs_tmp_if_cond_24)

# 1217 "<previous_module>"
                {
                        
# 1218 "<previous_module>"
tpush_0_62: IF(1,62,tpush_0_63)__CSEQ_removeindent;
                        
# 1219 "<previous_module>"
__cs_mutex_lock(&lock, 1);
                }

                
# 1221 "<previous_module>"
__CPROVER_assume(__cs_pc_cs[1] >= 63);
                ;
                
# 1222 "<previous_module>"
;
                ;

# 1223 "<previous_module>"
                {
                        
# 1224 "<previous_module>"
static struct lfds711_stack_state *__cs_param_insert_s;
                        
# 1225 "<previous_module>"
tpush_0_63: IF(1,63,tpush_0_64)__CSEQ_removeindent;
                        
# 1226 "<previous_module>"
__cs_param_insert_s = ss;
                        
# 1227 "<previous_module>"
static int long long unsigned __cs_param_insert_id;
                        
# 1228 "<previous_module>"
__cs_param_insert_id = __cs_local_push_loop;
                        
# 1229 "<previous_module>"
static struct test_data *__cs_local_insert_td;
                        
# 1230 "<previous_module>"
tpush_0_64: IF(1,64,tpush_0_65)__CSEQ_removeindent;
                        
# 1231 "<previous_module>"
__cs_local_insert_td = __cs_safe_malloc(sizeof(struct test_data));
                        
# 1232 "<previous_module>"
tpush_0_65: IF(1,65,tpush_0_66)__CSEQ_removeindent;
                        
# 1233 "<previous_module>"
(*__cs_local_insert_td).user_id = __cs_param_insert_id;
                        
# 1234 "<previous_module>"
tpush_0_66: IF(1,66,tpush_0_67)__CSEQ_removeindent;
                        
# 1235 "<previous_module>"
(*__cs_local_insert_td).se.value = (void *) ((lfds711_pal_uint_t) __cs_local_insert_td);

# 1236 "<previous_module>"
                        {
                                
# 1237 "<previous_module>"
static struct lfds711_stack_state *__cs_param_lfds711_stack_push_ss;
                                
# 1238 "<previous_module>"
tpush_0_67: IF(1,67,tpush_0_68)__CSEQ_removeindent;
                                
# 1239 "<previous_module>"
__cs_param_lfds711_stack_push_ss = (struct lfds711_stack_state *) __cs_param_insert_s;
                                
# 1240 "<previous_module>"
static struct lfds711_stack_element *__cs_param_lfds711_stack_push_se;
                                
# 1241 "<previous_module>"
tpush_0_68: IF(1,68,tpush_0_69)__CSEQ_removeindent;
                                
# 1242 "<previous_module>"
__cs_param_lfds711_stack_push_se = &(*__cs_local_insert_td).se;
                                
# 1243 "<previous_module>"
static char unsigned __cs_local_lfds711_stack_push_result;
                                
# 1244 "<previous_module>"
static lfds711_pal_uint_t __cs_local_lfds711_stack_push_backoff_iteration;
                                
# 1245 "<previous_module>"
__cs_local_lfds711_stack_push_backoff_iteration = 0;
                                
# 1246 "<previous_module>"
static struct lfds711_stack_element *__cs_local_lfds711_stack_push_new_top[2];
                                
# 1247 "<previous_module>"
static struct lfds711_stack_element * volatile __cs_local_lfds711_stack_push_original_top[2];
                                
# 1248 "<previous_module>"
;
                                ;
                                
# 1249 "<previous_module>"
static _Bool __cs_local_lfds711_stack_push___cs_tmp_if_cond_14;
                                
# 1250 "<previous_module>"
tpush_0_69: IF(1,69,tpush_0_70)__CSEQ_removeindent;
                                
# 1251 "<previous_module>"
__cs_local_lfds711_stack_push___cs_tmp_if_cond_14 = !(__cs_param_lfds711_stack_push_ss != 0);
                                
# 1252 "<previous_module>"
if (__cs_local_lfds711_stack_push___cs_tmp_if_cond_14)

# 1253 "<previous_module>"
                                {
                                        
# 1254 "<previous_module>"
static char *__cs_local_lfds711_stack_push_c;
                                        
# 1255 "<previous_module>"
tpush_0_70: IF(1,70,tpush_0_71)__CSEQ_removeindent;
                                        
# 1256 "<previous_module>"
__cs_local_lfds711_stack_push_c = 0;
                                        
# 1257 "<previous_module>"
tpush_0_71: IF(1,71,tpush_0_72)__CSEQ_removeindent;
                                        
# 1258 "<previous_module>"
*__cs_local_lfds711_stack_push_c = 0;
                                }

                                
# 1260 "<previous_module>"
__CPROVER_assume(__cs_pc_cs[1] >= 72);
                                ;
                                
# 1261 "<previous_module>"
;
                                ;
                                
# 1262 "<previous_module>"
;
                                ;
                                
# 1263 "<previous_module>"
;
                                ;
                                
# 1264 "<previous_module>"
static _Bool __cs_local_lfds711_stack_push___cs_tmp_if_cond_15;
                                
# 1265 "<previous_module>"
tpush_0_72: IF(1,72,tpush_0_73)__CSEQ_removeindent;
                                
# 1266 "<previous_module>"
__cs_local_lfds711_stack_push___cs_tmp_if_cond_15 = !(__cs_param_lfds711_stack_push_se != 0);
                                
# 1267 "<previous_module>"
if (__cs_local_lfds711_stack_push___cs_tmp_if_cond_15)

# 1268 "<previous_module>"
                                {
                                        
# 1269 "<previous_module>"
static char *__cs_local_lfds711_stack_push_c;
                                        
# 1270 "<previous_module>"
tpush_0_73: IF(1,73,tpush_0_74)__CSEQ_removeindent;
                                        
# 1271 "<previous_module>"
__cs_local_lfds711_stack_push_c = 0;
                                        
# 1272 "<previous_module>"
tpush_0_74: IF(1,74,tpush_0_75)__CSEQ_removeindent;
                                        
# 1273 "<previous_module>"
*__cs_local_lfds711_stack_push_c = 0;
                                }

                                
# 1275 "<previous_module>"
__CPROVER_assume(__cs_pc_cs[1] >= 75);
                                ;
                                
# 1276 "<previous_module>"
;
                                ;
                                
# 1277 "<previous_module>"
;
                                ;
                                
# 1278 "<previous_module>"
tpush_0_75: IF(1,75,tpush_0_76)__CSEQ_removeindent;
                                
# 1279 "<previous_module>"
__cs_local_lfds711_stack_push_new_top[0] = __cs_param_lfds711_stack_push_se;
                                
# 1280 "<previous_module>"
tpush_0_76: IF(1,76,tpush_0_77)__CSEQ_removeindent;
                                
# 1281 "<previous_module>"
__cs_local_lfds711_stack_push_original_top[1] = (*__cs_param_lfds711_stack_push_ss).top[1];
                                
# 1282 "<previous_module>"
tpush_0_77: IF(1,77,tpush_0_78)__CSEQ_removeindent;
                                
# 1283 "<previous_module>"
__cs_local_lfds711_stack_push_original_top[0] = (*__cs_param_lfds711_stack_push_ss).top[0];
                                
# 1284 "<previous_module>"
__cs_local_lfds711_stack_push_result = 0;
                                
# 1285 "<previous_module>"
static int __cs_local_lfds711_stack_push_i;
                                
# 1286 "<previous_module>"
__cs_local_lfds711_stack_push_i = 0;
                                
# 1287 "<previous_module>"
if (!(__cs_local_lfds711_stack_push_result == 0))

# 1288 "<previous_module>"
                                {
                                        
# 1289 "<previous_module>"
goto __exit_loop_8;
                                        ;
                                }

                                
# 1291 "<previous_module>"
;

# 1292 "<previous_module>"
                                {
                                        
# 1293 "<previous_module>"
tpush_0_78: IF(1,78,tpush_0_79)__CSEQ_removeindent;
                                        
# 1294 "<previous_module>"
__cs_mutex_lock(&library_lock, 1);
                                        
# 1295 "<previous_module>"
tpush_0_79: IF(1,79,tpush_0_80)__CSEQ_removeindent;
                                        
# 1296 "<previous_module>"
(*__cs_param_lfds711_stack_push_se).next = __cs_local_lfds711_stack_push_original_top[0];
                                        
# 1297 "<previous_module>"
tpush_0_80: IF(1,80,tpush_0_81)__CSEQ_removeindent;
                                        
# 1298 "<previous_module>"
__cs_mutex_unlock(&library_lock, 1);
                                        
# 1299 "<previous_module>"
tpush_0_81: IF(1,81,tpush_0_82)__CSEQ_removeindent;
                                        
# 1300 "<previous_module>"
__cs_local_lfds711_stack_push_new_top[1] = __cs_local_lfds711_stack_push_original_top[1] + 1;
                                        
# 1301 "<previous_module>"
tpush_0_82: IF(1,82,tpush_0_83)__CSEQ_removeindent;
                                        
# 1302 "<previous_module>"
__cs_mutex_lock(&library_lock, 1);
                                        
# 1303 "<previous_module>"
tpush_0_83: IF(1,83,tpush_0_84)__CSEQ_removeindent;
                                        
# 1304 "<previous_module>"
__cs_local_lfds711_stack_push_result = __CSEQ_atomic_swap_stack_top(&(*__cs_param_lfds711_stack_push_ss).top[0], &__cs_local_lfds711_stack_push_original_top[0], &__cs_local_lfds711_stack_push_new_top[0]);
                                        
# 1305 "<previous_module>"
tpush_0_84: IF(1,84,tpush_0_85)__CSEQ_removeindent;
                                        
# 1306 "<previous_module>"
__cs_mutex_unlock(&library_lock, 1);
                                        
# 1307 "<previous_module>"
;
                                        ;
                                        
# 1308 "<previous_module>"
static _Bool __cs_local_lfds711_stack_push___cs_tmp_if_cond_16;
                                        
# 1309 "<previous_module>"
__cs_local_lfds711_stack_push___cs_tmp_if_cond_16 = __cs_local_lfds711_stack_push_result == 0;
                                        
# 1310 "<previous_module>"
if (__cs_local_lfds711_stack_push___cs_tmp_if_cond_16)

# 1311 "<previous_module>"
                                        {

# 1312 "<previous_module>"
                                                {
                                                        
# 1313 "<previous_module>"
static int __cs_local_exponential_backoff_loop;
                                                        
# 1314 "<previous_module>"
__cs_local_exponential_backoff_loop = 0;

# 1315 "<previous_module>"
                                                        {
                                                                
# 1316 "<previous_module>"
;
                                                                ;
                                                        }
                                                        
# 1318 "<previous_module>"
;
                                                        
# 1319 "<previous_module>"
__cs_local_exponential_backoff_loop++;

# 1320 "<previous_module>"
                                                        {
                                                                
# 1321 "<previous_module>"
;
                                                                ;
                                                        }
                                                        
# 1323 "<previous_module>"
;
                                                        
# 1324 "<previous_module>"
__cs_local_exponential_backoff_loop++;

# 1325 "<previous_module>"
                                                        {
                                                                
# 1326 "<previous_module>"
;
                                                                ;
                                                        }
                                                        
# 1328 "<previous_module>"
;
                                                        
# 1329 "<previous_module>"
__cs_local_exponential_backoff_loop++;
                                                        
# 1330 "<previous_module>"
tpush_0_85: IF(1,85,tpush_0_86)__CSEQ_removeindent;
                                                        
# 1331 "<previous_module>"
__CPROVER_assume(!(__cs_local_exponential_backoff_loop < 3));
                                                        
# 1332 "<previous_module>"
__exit_loop_9:
                                                        __CPROVER_assume(__cs_pc_cs[1] >= 86);

                                                        
# 1333 "<previous_module>"
;
                                                        ;
                                                        
# 1334 "<previous_module>"
__exit__exponential_backoff_1_5:
                                                        __CPROVER_assume(__cs_pc_cs[1] >= 86);

                                                        
# 1335 "<previous_module>"
;
                                                        ;
                                                }
                                                
# 1337 "<previous_module>"
;
                                        }

                                        
# 1339 "<previous_module>"
__CPROVER_assume(__cs_pc_cs[1] >= 86);
                                        ;
                                        
# 1340 "<previous_module>"
__cs_local_lfds711_stack_push_i++;
                                        
# 1341 "<previous_module>"
;
                                        ;
                                        
# 1342 "<previous_module>"
static _Bool __cs_local_lfds711_stack_push___cs_tmp_if_cond_17;
                                        
# 1343 "<previous_module>"
__cs_local_lfds711_stack_push___cs_tmp_if_cond_17 = __cs_local_lfds711_stack_push_i > 1000;
                                        
# 1344 "<previous_module>"
if (__cs_local_lfds711_stack_push___cs_tmp_if_cond_17)

# 1345 "<previous_module>"
                                        {
                                                
# 1346 "<previous_module>"
goto __exit_loop_8;
                                                ;
                                        }

                                        
# 1348 "<previous_module>"
;
                                }
                                
# 1350 "<previous_module>"
;
                                
# 1351 "<previous_module>"
if (!(__cs_local_lfds711_stack_push_result == 0))

# 1352 "<previous_module>"
                                {
                                        
# 1353 "<previous_module>"
goto __exit_loop_8;
                                        ;
                                }

                                
# 1355 "<previous_module>"
;

# 1356 "<previous_module>"
                                {
                                        
# 1357 "<previous_module>"
tpush_0_86: IF(1,86,tpush_0_87)__CSEQ_removeindent;
                                        
# 1358 "<previous_module>"
__cs_mutex_lock(&library_lock, 1);
                                        
# 1359 "<previous_module>"
tpush_0_87: IF(1,87,tpush_0_88)__CSEQ_removeindent;
                                        
# 1360 "<previous_module>"
(*__cs_param_lfds711_stack_push_se).next = __cs_local_lfds711_stack_push_original_top[0];
                                        
# 1361 "<previous_module>"
tpush_0_88: IF(1,88,tpush_0_89)__CSEQ_removeindent;
                                        
# 1362 "<previous_module>"
__cs_mutex_unlock(&library_lock, 1);
                                        
# 1363 "<previous_module>"
tpush_0_89: IF(1,89,tpush_0_90)__CSEQ_removeindent;
                                        
# 1364 "<previous_module>"
__cs_local_lfds711_stack_push_new_top[1] = __cs_local_lfds711_stack_push_original_top[1] + 1;
                                        
# 1365 "<previous_module>"
tpush_0_90: IF(1,90,tpush_0_91)__CSEQ_removeindent;
                                        
# 1366 "<previous_module>"
__cs_mutex_lock(&library_lock, 1);
                                        
# 1367 "<previous_module>"
tpush_0_91: IF(1,91,tpush_0_92)__CSEQ_removeindent;
                                        
# 1368 "<previous_module>"
__cs_local_lfds711_stack_push_result = __CSEQ_atomic_swap_stack_top(&(*__cs_param_lfds711_stack_push_ss).top[0], &__cs_local_lfds711_stack_push_original_top[0], &__cs_local_lfds711_stack_push_new_top[0]);
                                        
# 1369 "<previous_module>"
tpush_0_92: IF(1,92,tpush_0_93)__CSEQ_removeindent;
                                        
# 1370 "<previous_module>"
__cs_mutex_unlock(&library_lock, 1);
                                        
# 1371 "<previous_module>"
;
                                        ;
                                        
# 1372 "<previous_module>"
static _Bool __cs_local_lfds711_stack_push___cs_tmp_if_cond_16;
                                        
# 1373 "<previous_module>"
__cs_local_lfds711_stack_push___cs_tmp_if_cond_16 = __cs_local_lfds711_stack_push_result == 0;
                                        
# 1374 "<previous_module>"
if (__cs_local_lfds711_stack_push___cs_tmp_if_cond_16)

# 1375 "<previous_module>"
                                        {

# 1376 "<previous_module>"
                                                {
                                                        
# 1377 "<previous_module>"
static int __cs_local_exponential_backoff_loop;
                                                        
# 1378 "<previous_module>"
__cs_local_exponential_backoff_loop = 0;

# 1379 "<previous_module>"
                                                        {
                                                                
# 1380 "<previous_module>"
;
                                                                ;
                                                        }
                                                        
# 1382 "<previous_module>"
;
                                                        
# 1383 "<previous_module>"
__cs_local_exponential_backoff_loop++;

# 1384 "<previous_module>"
                                                        {
                                                                
# 1385 "<previous_module>"
;
                                                                ;
                                                        }
                                                        
# 1387 "<previous_module>"
;
                                                        
# 1388 "<previous_module>"
__cs_local_exponential_backoff_loop++;

# 1389 "<previous_module>"
                                                        {
                                                                
# 1390 "<previous_module>"
;
                                                                ;
                                                        }
                                                        
# 1392 "<previous_module>"
;
                                                        
# 1393 "<previous_module>"
__cs_local_exponential_backoff_loop++;
                                                        
# 1394 "<previous_module>"
tpush_0_93: IF(1,93,tpush_0_94)__CSEQ_removeindent;
                                                        
# 1395 "<previous_module>"
__CPROVER_assume(!(__cs_local_exponential_backoff_loop < 3));
                                                        
# 1396 "<previous_module>"
__exit_loop_10:
                                                        __CPROVER_assume(__cs_pc_cs[1] >= 94);

                                                        
# 1397 "<previous_module>"
;
                                                        ;
                                                        
# 1398 "<previous_module>"
__exit__exponential_backoff_1_6:
                                                        __CPROVER_assume(__cs_pc_cs[1] >= 94);

                                                        
# 1399 "<previous_module>"
;
                                                        ;
                                                }
                                                
# 1401 "<previous_module>"
;
                                        }

                                        
# 1403 "<previous_module>"
__CPROVER_assume(__cs_pc_cs[1] >= 94);
                                        ;
                                        
# 1404 "<previous_module>"
__cs_local_lfds711_stack_push_i++;
                                        
# 1405 "<previous_module>"
;
                                        ;
                                        
# 1406 "<previous_module>"
static _Bool __cs_local_lfds711_stack_push___cs_tmp_if_cond_17;
                                        
# 1407 "<previous_module>"
__cs_local_lfds711_stack_push___cs_tmp_if_cond_17 = __cs_local_lfds711_stack_push_i > 1000;
                                        
# 1408 "<previous_module>"
if (__cs_local_lfds711_stack_push___cs_tmp_if_cond_17)

# 1409 "<previous_module>"
                                        {
                                                
# 1410 "<previous_module>"
goto __exit_loop_8;
                                                ;
                                        }

                                        
# 1412 "<previous_module>"
;
                                }
                                
# 1414 "<previous_module>"
;
                                
# 1415 "<previous_module>"
if (!(__cs_local_lfds711_stack_push_result == 0))

# 1416 "<previous_module>"
                                {
                                        
# 1417 "<previous_module>"
goto __exit_loop_8;
                                        ;
                                }

                                
# 1419 "<previous_module>"
;

# 1420 "<previous_module>"
                                {
                                        
# 1421 "<previous_module>"
tpush_0_94: IF(1,94,tpush_0_95)__CSEQ_removeindent;
                                        
# 1422 "<previous_module>"
__cs_mutex_lock(&library_lock, 1);
                                        
# 1423 "<previous_module>"
tpush_0_95: IF(1,95,tpush_0_96)__CSEQ_removeindent;
                                        
# 1424 "<previous_module>"
(*__cs_param_lfds711_stack_push_se).next = __cs_local_lfds711_stack_push_original_top[0];
                                        
# 1425 "<previous_module>"
tpush_0_96: IF(1,96,tpush_0_97)__CSEQ_removeindent;
                                        
# 1426 "<previous_module>"
__cs_mutex_unlock(&library_lock, 1);
                                        
# 1427 "<previous_module>"
tpush_0_97: IF(1,97,tpush_0_98)__CSEQ_removeindent;
                                        
# 1428 "<previous_module>"
__cs_local_lfds711_stack_push_new_top[1] = __cs_local_lfds711_stack_push_original_top[1] + 1;
                                        
# 1429 "<previous_module>"
tpush_0_98: IF(1,98,tpush_0_99)__CSEQ_removeindent;
                                        
# 1430 "<previous_module>"
__cs_mutex_lock(&library_lock, 1);
                                        
# 1431 "<previous_module>"
tpush_0_99: IF(1,99,tpush_0_100)__CSEQ_removeindent;
                                        
# 1432 "<previous_module>"
__cs_local_lfds711_stack_push_result = __CSEQ_atomic_swap_stack_top(&(*__cs_param_lfds711_stack_push_ss).top[0], &__cs_local_lfds711_stack_push_original_top[0], &__cs_local_lfds711_stack_push_new_top[0]);
                                        
# 1433 "<previous_module>"
tpush_0_100: IF(1,100,tpush_0_101)__CSEQ_removeindent;
                                        
# 1434 "<previous_module>"
__cs_mutex_unlock(&library_lock, 1);
                                        
# 1435 "<previous_module>"
;
                                        ;
                                        
# 1436 "<previous_module>"
static _Bool __cs_local_lfds711_stack_push___cs_tmp_if_cond_16;
                                        
# 1437 "<previous_module>"
__cs_local_lfds711_stack_push___cs_tmp_if_cond_16 = __cs_local_lfds711_stack_push_result == 0;
                                        
# 1438 "<previous_module>"
if (__cs_local_lfds711_stack_push___cs_tmp_if_cond_16)

# 1439 "<previous_module>"
                                        {

# 1440 "<previous_module>"
                                                {
                                                        
# 1441 "<previous_module>"
static int __cs_local_exponential_backoff_loop;
                                                        
# 1442 "<previous_module>"
__cs_local_exponential_backoff_loop = 0;

# 1443 "<previous_module>"
                                                        {
                                                                
# 1444 "<previous_module>"
;
                                                                ;
                                                        }
                                                        
# 1446 "<previous_module>"
;
                                                        
# 1447 "<previous_module>"
__cs_local_exponential_backoff_loop++;

# 1448 "<previous_module>"
                                                        {
                                                                
# 1449 "<previous_module>"
;
                                                                ;
                                                        }
                                                        
# 1451 "<previous_module>"
;
                                                        
# 1452 "<previous_module>"
__cs_local_exponential_backoff_loop++;

# 1453 "<previous_module>"
                                                        {
                                                                
# 1454 "<previous_module>"
;
                                                                ;
                                                        }
                                                        
# 1456 "<previous_module>"
;
                                                        
# 1457 "<previous_module>"
__cs_local_exponential_backoff_loop++;
                                                        
# 1458 "<previous_module>"
tpush_0_101: IF(1,101,tpush_0_102)__CSEQ_removeindent;
                                                        
# 1459 "<previous_module>"
__CPROVER_assume(!(__cs_local_exponential_backoff_loop < 3));
                                                        
# 1460 "<previous_module>"
__exit_loop_11:
                                                        __CPROVER_assume(__cs_pc_cs[1] >= 102);

                                                        
# 1461 "<previous_module>"
;
                                                        ;
                                                        
# 1462 "<previous_module>"
__exit__exponential_backoff_1_7:
                                                        __CPROVER_assume(__cs_pc_cs[1] >= 102);

                                                        
# 1463 "<previous_module>"
;
                                                        ;
                                                }
                                                
# 1465 "<previous_module>"
;
                                        }

                                        
# 1467 "<previous_module>"
__CPROVER_assume(__cs_pc_cs[1] >= 102);
                                        ;
                                        
# 1468 "<previous_module>"
__cs_local_lfds711_stack_push_i++;
                                        
# 1469 "<previous_module>"
;
                                        ;
                                        
# 1470 "<previous_module>"
static _Bool __cs_local_lfds711_stack_push___cs_tmp_if_cond_17;
                                        
# 1471 "<previous_module>"
__cs_local_lfds711_stack_push___cs_tmp_if_cond_17 = __cs_local_lfds711_stack_push_i > 1000;
                                        
# 1472 "<previous_module>"
if (__cs_local_lfds711_stack_push___cs_tmp_if_cond_17)

# 1473 "<previous_module>"
                                        {
                                                
# 1474 "<previous_module>"
goto __exit_loop_8;
                                                ;
                                        }

                                        
# 1476 "<previous_module>"
;
                                }
                                
# 1478 "<previous_module>"
;
                                
# 1479 "<previous_module>"
if (!(__cs_local_lfds711_stack_push_result == 0))

# 1480 "<previous_module>"
                                {
                                        
# 1481 "<previous_module>"
goto __exit_loop_8;
                                        ;
                                }

                                
# 1483 "<previous_module>"
;

# 1484 "<previous_module>"
                                {
                                        
# 1485 "<previous_module>"
tpush_0_102: IF(1,102,tpush_0_103)__CSEQ_removeindent;
                                        
# 1486 "<previous_module>"
__cs_mutex_lock(&library_lock, 1);
                                        
# 1487 "<previous_module>"
tpush_0_103: IF(1,103,tpush_0_104)__CSEQ_removeindent;
                                        
# 1488 "<previous_module>"
(*__cs_param_lfds711_stack_push_se).next = __cs_local_lfds711_stack_push_original_top[0];
                                        
# 1489 "<previous_module>"
tpush_0_104: IF(1,104,tpush_0_105)__CSEQ_removeindent;
                                        
# 1490 "<previous_module>"
__cs_mutex_unlock(&library_lock, 1);
                                        
# 1491 "<previous_module>"
tpush_0_105: IF(1,105,tpush_0_106)__CSEQ_removeindent;
                                        
# 1492 "<previous_module>"
__cs_local_lfds711_stack_push_new_top[1] = __cs_local_lfds711_stack_push_original_top[1] + 1;
                                        
# 1493 "<previous_module>"
tpush_0_106: IF(1,106,tpush_0_107)__CSEQ_removeindent;
                                        
# 1494 "<previous_module>"
__cs_mutex_lock(&library_lock, 1);
                                        
# 1495 "<previous_module>"
tpush_0_107: IF(1,107,tpush_0_108)__CSEQ_removeindent;
                                        
# 1496 "<previous_module>"
__cs_local_lfds711_stack_push_result = __CSEQ_atomic_swap_stack_top(&(*__cs_param_lfds711_stack_push_ss).top[0], &__cs_local_lfds711_stack_push_original_top[0], &__cs_local_lfds711_stack_push_new_top[0]);
                                        
# 1497 "<previous_module>"
tpush_0_108: IF(1,108,tpush_0_109)__CSEQ_removeindent;
                                        
# 1498 "<previous_module>"
__cs_mutex_unlock(&library_lock, 1);
                                        
# 1499 "<previous_module>"
;
                                        ;
                                        
# 1500 "<previous_module>"
static _Bool __cs_local_lfds711_stack_push___cs_tmp_if_cond_16;
                                        
# 1501 "<previous_module>"
__cs_local_lfds711_stack_push___cs_tmp_if_cond_16 = __cs_local_lfds711_stack_push_result == 0;
                                        
# 1502 "<previous_module>"
if (__cs_local_lfds711_stack_push___cs_tmp_if_cond_16)

# 1503 "<previous_module>"
                                        {

# 1504 "<previous_module>"
                                                {
                                                        
# 1505 "<previous_module>"
static int __cs_local_exponential_backoff_loop;
                                                        
# 1506 "<previous_module>"
__cs_local_exponential_backoff_loop = 0;

# 1507 "<previous_module>"
                                                        {
                                                                
# 1508 "<previous_module>"
;
                                                                ;
                                                        }
                                                        
# 1510 "<previous_module>"
;
                                                        
# 1511 "<previous_module>"
__cs_local_exponential_backoff_loop++;

# 1512 "<previous_module>"
                                                        {
                                                                
# 1513 "<previous_module>"
;
                                                                ;
                                                        }
                                                        
# 1515 "<previous_module>"
;
                                                        
# 1516 "<previous_module>"
__cs_local_exponential_backoff_loop++;

# 1517 "<previous_module>"
                                                        {
                                                                
# 1518 "<previous_module>"
;
                                                                ;
                                                        }
                                                        
# 1520 "<previous_module>"
;
                                                        
# 1521 "<previous_module>"
__cs_local_exponential_backoff_loop++;
                                                        
# 1522 "<previous_module>"
tpush_0_109: IF(1,109,tpush_0_110)__CSEQ_removeindent;
                                                        
# 1523 "<previous_module>"
__CPROVER_assume(!(__cs_local_exponential_backoff_loop < 3));
                                                        
# 1524 "<previous_module>"
__exit_loop_12:
                                                        __CPROVER_assume(__cs_pc_cs[1] >= 110);

                                                        
# 1525 "<previous_module>"
;
                                                        ;
                                                        
# 1526 "<previous_module>"
__exit__exponential_backoff_1_8:
                                                        __CPROVER_assume(__cs_pc_cs[1] >= 110);

                                                        
# 1527 "<previous_module>"
;
                                                        ;
                                                }
                                                
# 1529 "<previous_module>"
;
                                        }

                                        
# 1531 "<previous_module>"
__CPROVER_assume(__cs_pc_cs[1] >= 110);
                                        ;
                                        
# 1532 "<previous_module>"
__cs_local_lfds711_stack_push_i++;
                                        
# 1533 "<previous_module>"
;
                                        ;
                                        
# 1534 "<previous_module>"
static _Bool __cs_local_lfds711_stack_push___cs_tmp_if_cond_17;
                                        
# 1535 "<previous_module>"
__cs_local_lfds711_stack_push___cs_tmp_if_cond_17 = __cs_local_lfds711_stack_push_i > 1000;
                                        
# 1536 "<previous_module>"
if (__cs_local_lfds711_stack_push___cs_tmp_if_cond_17)

# 1537 "<previous_module>"
                                        {
                                                
# 1538 "<previous_module>"
goto __exit_loop_8;
                                                ;
                                        }

                                        
# 1540 "<previous_module>"
;
                                }
                                
# 1542 "<previous_module>"
;
                                
# 1543 "<previous_module>"
if (!(__cs_local_lfds711_stack_push_result == 0))

# 1544 "<previous_module>"
                                {
                                        
# 1545 "<previous_module>"
goto __exit_loop_8;
                                        ;
                                }

                                
# 1547 "<previous_module>"
;

# 1548 "<previous_module>"
                                {
                                        
# 1549 "<previous_module>"
tpush_0_110: IF(1,110,tpush_0_111)__CSEQ_removeindent;
                                        
# 1550 "<previous_module>"
__cs_mutex_lock(&library_lock, 1);
                                        
# 1551 "<previous_module>"
tpush_0_111: IF(1,111,tpush_0_112)__CSEQ_removeindent;
                                        
# 1552 "<previous_module>"
(*__cs_param_lfds711_stack_push_se).next = __cs_local_lfds711_stack_push_original_top[0];
                                        
# 1553 "<previous_module>"
tpush_0_112: IF(1,112,tpush_0_113)__CSEQ_removeindent;
                                        
# 1554 "<previous_module>"
__cs_mutex_unlock(&library_lock, 1);
                                        
# 1555 "<previous_module>"
tpush_0_113: IF(1,113,tpush_0_114)__CSEQ_removeindent;
                                        
# 1556 "<previous_module>"
__cs_local_lfds711_stack_push_new_top[1] = __cs_local_lfds711_stack_push_original_top[1] + 1;
                                        
# 1557 "<previous_module>"
tpush_0_114: IF(1,114,tpush_0_115)__CSEQ_removeindent;
                                        
# 1558 "<previous_module>"
__cs_mutex_lock(&library_lock, 1);
                                        
# 1559 "<previous_module>"
tpush_0_115: IF(1,115,tpush_0_116)__CSEQ_removeindent;
                                        
# 1560 "<previous_module>"
__cs_local_lfds711_stack_push_result = __CSEQ_atomic_swap_stack_top(&(*__cs_param_lfds711_stack_push_ss).top[0], &__cs_local_lfds711_stack_push_original_top[0], &__cs_local_lfds711_stack_push_new_top[0]);
                                        
# 1561 "<previous_module>"
tpush_0_116: IF(1,116,tpush_0_117)__CSEQ_removeindent;
                                        
# 1562 "<previous_module>"
__cs_mutex_unlock(&library_lock, 1);
                                        
# 1563 "<previous_module>"
;
                                        ;
                                        
# 1564 "<previous_module>"
static _Bool __cs_local_lfds711_stack_push___cs_tmp_if_cond_16;
                                        
# 1565 "<previous_module>"
__cs_local_lfds711_stack_push___cs_tmp_if_cond_16 = __cs_local_lfds711_stack_push_result == 0;
                                        
# 1566 "<previous_module>"
if (__cs_local_lfds711_stack_push___cs_tmp_if_cond_16)

# 1567 "<previous_module>"
                                        {

# 1568 "<previous_module>"
                                                {
                                                        
# 1569 "<previous_module>"
static int __cs_local_exponential_backoff_loop;
                                                        
# 1570 "<previous_module>"
__cs_local_exponential_backoff_loop = 0;

# 1571 "<previous_module>"
                                                        {
                                                                
# 1572 "<previous_module>"
;
                                                                ;
                                                        }
                                                        
# 1574 "<previous_module>"
;
                                                        
# 1575 "<previous_module>"
__cs_local_exponential_backoff_loop++;

# 1576 "<previous_module>"
                                                        {
                                                                
# 1577 "<previous_module>"
;
                                                                ;
                                                        }
                                                        
# 1579 "<previous_module>"
;
                                                        
# 1580 "<previous_module>"
__cs_local_exponential_backoff_loop++;

# 1581 "<previous_module>"
                                                        {
                                                                
# 1582 "<previous_module>"
;
                                                                ;
                                                        }
                                                        
# 1584 "<previous_module>"
;
                                                        
# 1585 "<previous_module>"
__cs_local_exponential_backoff_loop++;
                                                        
# 1586 "<previous_module>"
tpush_0_117: IF(1,117,tpush_0_118)__CSEQ_removeindent;
                                                        
# 1587 "<previous_module>"
__CPROVER_assume(!(__cs_local_exponential_backoff_loop < 3));
                                                        
# 1588 "<previous_module>"
__exit_loop_13:
                                                        __CPROVER_assume(__cs_pc_cs[1] >= 118);

                                                        
# 1589 "<previous_module>"
;
                                                        ;
                                                        
# 1590 "<previous_module>"
__exit__exponential_backoff_1_9:
                                                        __CPROVER_assume(__cs_pc_cs[1] >= 118);

                                                        
# 1591 "<previous_module>"
;
                                                        ;
                                                }
                                                
# 1593 "<previous_module>"
;
                                        }

                                        
# 1595 "<previous_module>"
__CPROVER_assume(__cs_pc_cs[1] >= 118);
                                        ;
                                        
# 1596 "<previous_module>"
__cs_local_lfds711_stack_push_i++;
                                        
# 1597 "<previous_module>"
;
                                        ;
                                        
# 1598 "<previous_module>"
static _Bool __cs_local_lfds711_stack_push___cs_tmp_if_cond_17;
                                        
# 1599 "<previous_module>"
__cs_local_lfds711_stack_push___cs_tmp_if_cond_17 = __cs_local_lfds711_stack_push_i > 1000;
                                        
# 1600 "<previous_module>"
if (__cs_local_lfds711_stack_push___cs_tmp_if_cond_17)

# 1601 "<previous_module>"
                                        {
                                                
# 1602 "<previous_module>"
goto __exit_loop_8;
                                                ;
                                        }

                                        
# 1604 "<previous_module>"
;
                                }
                                
# 1606 "<previous_module>"
;
                                
# 1607 "<previous_module>"
tpush_0_118: IF(1,118,tpush_0_119)__CSEQ_removeindent;
                                
# 1608 "<previous_module>"
__CPROVER_assume(!(__cs_local_lfds711_stack_push_result == 0));
                                
# 1609 "<previous_module>"
__exit_loop_8:
                                __CPROVER_assume(__cs_pc_cs[1] >= 119);

                                
# 1610 "<previous_module>"
;
                                ;
                                
# 1611 "<previous_module>"
goto __exit__lfds711_stack_push_1_1;
                                ;
                                
# 1612 "<previous_module>"
__exit__lfds711_stack_push_1_1:
                                __CPROVER_assume(__cs_pc_cs[1] >= 119);

                                
# 1613 "<previous_module>"
;
                                ;
                        }
                        
# 1615 "<previous_module>"
;
                        
# 1616 "<previous_module>"
__exit__insert_1_1:
                        __CPROVER_assume(__cs_pc_cs[1] >= 119);

                        
# 1617 "<previous_module>"
;
                        ;
                }
                
# 1619 "<previous_module>"
;
                
# 1620 "<previous_module>"
;
                ;
                
# 1621 "<previous_module>"
static _Bool __cs_local_push___cs_tmp_if_cond_25;
                
# 1622 "<previous_module>"
tpush_0_119: IF(1,119,tpush_0_120)__CSEQ_removeindent;
                
# 1623 "<previous_module>"
__cs_local_push___cs_tmp_if_cond_25 = ATOMIC_OPERATION;
                
# 1624 "<previous_module>"
if (__cs_local_push___cs_tmp_if_cond_25)

# 1625 "<previous_module>"
                {
                        
# 1626 "<previous_module>"
tpush_0_120: IF(1,120,tpush_0_121)__CSEQ_removeindent;
                        
# 1627 "<previous_module>"
__cs_mutex_unlock(&lock, 1);
                }

                
# 1629 "<previous_module>"
__CPROVER_assume(__cs_pc_cs[1] >= 121);
                ;
                
# 1630 "<previous_module>"
;
                ;
        }
        
# 1632 "<previous_module>"
;
        
# 1633 "<previous_module>"
__cs_local_push_loop++;
        
# 1634 "<previous_module>"
tpush_0_121: IF(1,121,tpush_0_122)__CSEQ_removeindent;
        
# 1635 "<previous_module>"
__CPROVER_assume(!(__cs_local_push_loop < 2));
        
# 1636 "<previous_module>"
__exit_loop_1:
        __CPROVER_assume(__cs_pc_cs[1] >= 122);

        
# 1637 "<previous_module>"
;
        ;
        
# 1638 "<previous_module>"
__exit_push:
        __CPROVER_assume(__cs_pc_cs[1] >= 122);

        
# 1639 "<previous_module>"
;
        ;
        
# 1640 "<previous_module>"
tpush_0_122: __CSEQ_removeindent;
        
# 1641 "<previous_module>"
__cs_exit(0, 1);
}


# 1643 "<previous_module>"
void *pop_0(void *__cs_param_pop___cs_unused)

# 1644 "<previous_module>"
{
        
# 1645 "<previous_module>"
static int __cs_local_pop_res;
        
# 1646 "<previous_module>"
IF(2,0,tpop_0_1)__CSEQ_removeindent;
        
# 1647 "<previous_module>"
__cs_local_pop_res = nondet_int();
        
# 1648 "<previous_module>"
static int __cs_local_pop_count;
        
# 1649 "<previous_module>"
__cs_local_pop_count = 0;
        
# 1650 "<previous_module>"
static int __cs_local_pop_loop;
        
# 1651 "<previous_module>"
__cs_local_pop_loop = 0;

# 1652 "<previous_module>"
        {
                
# 1653 "<previous_module>"
;
                ;
                
# 1654 "<previous_module>"
static _Bool __cs_local_pop___cs_tmp_if_cond_26;
                
# 1655 "<previous_module>"
tpop_0_1: IF(2,1,tpop_0_2)__CSEQ_removeindent;
                
# 1656 "<previous_module>"
__cs_local_pop___cs_tmp_if_cond_26 = ATOMIC_OPERATION;
                
# 1657 "<previous_module>"
if (__cs_local_pop___cs_tmp_if_cond_26)

# 1658 "<previous_module>"
                {
                        
# 1659 "<previous_module>"
tpop_0_2: IF(2,2,tpop_0_3)__CSEQ_removeindent;
                        
# 1660 "<previous_module>"
__cs_mutex_lock(&lock, 2);
                }

                
# 1662 "<previous_module>"
__CPROVER_assume(__cs_pc_cs[2] >= 3);
                ;
                
# 1663 "<previous_module>"
;
                ;
                
# 1664 "<previous_module>"
static int __cs_retval__delete_1;

# 1665 "<previous_module>"
                {
                        
# 1666 "<previous_module>"
static struct lfds711_stack_state *__cs_param_delete_s;
                        
# 1667 "<previous_module>"
tpop_0_3: IF(2,3,tpop_0_4)__CSEQ_removeindent;
                        
# 1668 "<previous_module>"
__cs_param_delete_s = ss;
                        
# 1669 "<previous_module>"
static struct lfds711_stack_element *__cs_local_delete_se;
                        
# 1670 "<previous_module>"
static struct test_data *__cs_local_delete_temp_td;
                        
# 1671 "<previous_module>"
static int __cs_local_delete_res;
                        
# 1672 "<previous_module>"
static int __cs_retval__lfds711_stack_pop_1;

# 1673 "<previous_module>"
                        {
                                
# 1674 "<previous_module>"
static struct lfds711_stack_state *__cs_param_lfds711_stack_pop_ss;
                                
# 1675 "<previous_module>"
tpop_0_4: IF(2,4,tpop_0_5)__CSEQ_removeindent;
                                
# 1676 "<previous_module>"
__cs_param_lfds711_stack_pop_ss = &mystack;
                                
# 1677 "<previous_module>"
static struct lfds711_stack_element **__cs_param_lfds711_stack_pop_se;
                                
# 1678 "<previous_module>"
tpop_0_5: IF(2,5,tpop_0_6)__CSEQ_removeindent;
                                
# 1679 "<previous_module>"
__cs_param_lfds711_stack_pop_se = &__cs_local_delete_se;
                                
# 1680 "<previous_module>"
static char unsigned __cs_local_lfds711_stack_pop_result;
                                
# 1681 "<previous_module>"
static lfds711_pal_uint_t __cs_local_lfds711_stack_pop_backoff_iteration;
                                
# 1682 "<previous_module>"
__cs_local_lfds711_stack_pop_backoff_iteration = 0;
                                
# 1683 "<previous_module>"
static struct lfds711_stack_element *__cs_local_lfds711_stack_pop_new_top[2];
                                
# 1684 "<previous_module>"
static struct lfds711_stack_element * volatile __cs_local_lfds711_stack_pop_original_top[2];
                                
# 1685 "<previous_module>"
;
                                ;
                                
# 1686 "<previous_module>"
static _Bool __cs_local_lfds711_stack_pop___cs_tmp_if_cond_6;
                                
# 1687 "<previous_module>"
tpop_0_6: IF(2,6,tpop_0_7)__CSEQ_removeindent;
                                
# 1688 "<previous_module>"
__cs_local_lfds711_stack_pop___cs_tmp_if_cond_6 = !(__cs_param_lfds711_stack_pop_ss != 0);
                                
# 1689 "<previous_module>"
if (__cs_local_lfds711_stack_pop___cs_tmp_if_cond_6)

# 1690 "<previous_module>"
                                {
                                        
# 1691 "<previous_module>"
static char *__cs_local_lfds711_stack_pop_c;
                                        
# 1692 "<previous_module>"
tpop_0_7: IF(2,7,tpop_0_8)__CSEQ_removeindent;
                                        
# 1693 "<previous_module>"
__cs_local_lfds711_stack_pop_c = 0;
                                        
# 1694 "<previous_module>"
tpop_0_8: IF(2,8,tpop_0_9)__CSEQ_removeindent;
                                        
# 1695 "<previous_module>"
*__cs_local_lfds711_stack_pop_c = 0;
                                }

                                
# 1697 "<previous_module>"
__CPROVER_assume(__cs_pc_cs[2] >= 9);
                                ;
                                
# 1698 "<previous_module>"
;
                                ;
                                
# 1699 "<previous_module>"
;
                                ;
                                
# 1700 "<previous_module>"
;
                                ;
                                
# 1701 "<previous_module>"
static _Bool __cs_local_lfds711_stack_pop___cs_tmp_if_cond_7;
                                
# 1702 "<previous_module>"
tpop_0_9: IF(2,9,tpop_0_10)__CSEQ_removeindent;
                                
# 1703 "<previous_module>"
__cs_local_lfds711_stack_pop___cs_tmp_if_cond_7 = !(__cs_param_lfds711_stack_pop_se != 0);
                                
# 1704 "<previous_module>"
if (__cs_local_lfds711_stack_pop___cs_tmp_if_cond_7)

# 1705 "<previous_module>"
                                {
                                        
# 1706 "<previous_module>"
static char *__cs_local_lfds711_stack_pop_c;
                                        
# 1707 "<previous_module>"
tpop_0_10: IF(2,10,tpop_0_11)__CSEQ_removeindent;
                                        
# 1708 "<previous_module>"
__cs_local_lfds711_stack_pop_c = 0;
                                        
# 1709 "<previous_module>"
tpop_0_11: IF(2,11,tpop_0_12)__CSEQ_removeindent;
                                        
# 1710 "<previous_module>"
*__cs_local_lfds711_stack_pop_c = 0;
                                }

                                
# 1712 "<previous_module>"
__CPROVER_assume(__cs_pc_cs[2] >= 12);
                                ;
                                
# 1713 "<previous_module>"
;
                                ;
                                
# 1714 "<previous_module>"
;
                                ;
                                
# 1715 "<previous_module>"
tpop_0_12: IF(2,12,tpop_0_13)__CSEQ_removeindent;
                                
# 1716 "<previous_module>"
__cs_mutex_lock(&library_lock, 2);
                                
# 1717 "<previous_module>"
tpop_0_13: IF(2,13,tpop_0_14)__CSEQ_removeindent;
                                
# 1718 "<previous_module>"
__cs_mutex_unlock(&library_lock, 2);
                                
# 1719 "<previous_module>"
tpop_0_14: IF(2,14,tpop_0_15)__CSEQ_removeindent;
                                
# 1720 "<previous_module>"
__cs_local_lfds711_stack_pop_original_top[1] = (*__cs_param_lfds711_stack_pop_ss).top[1];
                                
# 1721 "<previous_module>"
tpop_0_15: IF(2,15,tpop_0_16)__CSEQ_removeindent;
                                
# 1722 "<previous_module>"
__cs_local_lfds711_stack_pop_original_top[0] = (*__cs_param_lfds711_stack_pop_ss).top[0];
                                
# 1723 "<previous_module>"
static int __cs_local_lfds711_stack_pop_i;
                                
# 1724 "<previous_module>"
__cs_local_lfds711_stack_pop_i = 0;
                                
# 1725 "<previous_module>"
;
                                ;
                                
# 1726 "<previous_module>"
static int __cs_local_lfds711_stack_pop___cs_dowhile_onetime_1;
                                
# 1727 "<previous_module>"
__cs_local_lfds711_stack_pop___cs_dowhile_onetime_1 = 0;

# 1728 "<previous_module>"
                                {
                                        
# 1729 "<previous_module>"
;
                                        ;
                                        
# 1730 "<previous_module>"
static _Bool __cs_local_lfds711_stack_pop___cs_tmp_if_cond_8;
                                        
# 1731 "<previous_module>"
__cs_local_lfds711_stack_pop___cs_tmp_if_cond_8 = __cs_local_lfds711_stack_pop_original_top[0] == 0;
                                        
# 1732 "<previous_module>"
if (__cs_local_lfds711_stack_pop___cs_tmp_if_cond_8)

# 1733 "<previous_module>"
                                        {
                                                
# 1734 "<previous_module>"
tpop_0_16: IF(2,16,tpop_0_17)__CSEQ_removeindent;
                                                
# 1735 "<previous_module>"
*__cs_param_lfds711_stack_pop_se = 0;
                                                
# 1736 "<previous_module>"
__cs_retval__lfds711_stack_pop_1 = 0;
                                                
# 1737 "<previous_module>"
goto __exit__lfds711_stack_pop_1_0;
                                                ;
                                        }

                                        
# 1739 "<previous_module>"
__CPROVER_assume(__cs_pc_cs[2] >= 17);
                                        ;
                                        
# 1740 "<previous_module>"
tpop_0_17: IF(2,17,tpop_0_18)__CSEQ_removeindent;
                                        
# 1741 "<previous_module>"
__cs_local_lfds711_stack_pop_new_top[1] = __cs_local_lfds711_stack_pop_original_top[1] + 1;
                                        
# 1742 "<previous_module>"
tpop_0_18: IF(2,18,tpop_0_19)__CSEQ_removeindent;
                                        
# 1743 "<previous_module>"
__cs_local_lfds711_stack_pop_new_top[0] = (*__cs_local_lfds711_stack_pop_original_top[0]).next;
                                        
# 1744 "<previous_module>"
tpop_0_19: IF(2,19,tpop_0_20)__CSEQ_removeindent;
                                        
# 1745 "<previous_module>"
__cs_mutex_lock(&library_lock, 2);
                                        
# 1746 "<previous_module>"
tpop_0_20: IF(2,20,tpop_0_21)__CSEQ_removeindent;
                                        
# 1747 "<previous_module>"
__cs_local_lfds711_stack_pop_result = __CSEQ_atomic_swap_stack_top(&(*__cs_param_lfds711_stack_pop_ss).top[0], &__cs_local_lfds711_stack_pop_original_top[0], &__cs_local_lfds711_stack_pop_new_top[0]);
                                        
# 1748 "<previous_module>"
tpop_0_21: IF(2,21,tpop_0_22)__CSEQ_removeindent;
                                        
# 1749 "<previous_module>"
__cs_mutex_unlock(&library_lock, 2);
                                        
# 1750 "<previous_module>"
;
                                        ;
                                        
# 1751 "<previous_module>"
static _Bool __cs_local_lfds711_stack_pop___cs_tmp_if_cond_9;
                                        
# 1752 "<previous_module>"
__cs_local_lfds711_stack_pop___cs_tmp_if_cond_9 = __cs_local_lfds711_stack_pop_result == 0;
                                        
# 1753 "<previous_module>"
if (__cs_local_lfds711_stack_pop___cs_tmp_if_cond_9)

# 1754 "<previous_module>"
                                        {

# 1755 "<previous_module>"
                                                {
                                                        
# 1756 "<previous_module>"
static int __cs_local_exponential_backoff_loop;
                                                        
# 1757 "<previous_module>"
__cs_local_exponential_backoff_loop = 0;

# 1758 "<previous_module>"
                                                        {
                                                                
# 1759 "<previous_module>"
;
                                                                ;
                                                        }
                                                        
# 1761 "<previous_module>"
;
                                                        
# 1762 "<previous_module>"
__cs_local_exponential_backoff_loop++;

# 1763 "<previous_module>"
                                                        {
                                                                
# 1764 "<previous_module>"
;
                                                                ;
                                                        }
                                                        
# 1766 "<previous_module>"
;
                                                        
# 1767 "<previous_module>"
__cs_local_exponential_backoff_loop++;

# 1768 "<previous_module>"
                                                        {
                                                                
# 1769 "<previous_module>"
;
                                                                ;
                                                        }
                                                        
# 1771 "<previous_module>"
;
                                                        
# 1772 "<previous_module>"
__cs_local_exponential_backoff_loop++;
                                                        
# 1773 "<previous_module>"
tpop_0_22: IF(2,22,tpop_0_23)__CSEQ_removeindent;
                                                        
# 1774 "<previous_module>"
__CPROVER_assume(!(__cs_local_exponential_backoff_loop < 3));
                                                        
# 1775 "<previous_module>"
__exit_loop_16:
                                                        __CPROVER_assume(__cs_pc_cs[2] >= 23);

                                                        
# 1776 "<previous_module>"
;
                                                        ;
                                                        
# 1777 "<previous_module>"
__exit__exponential_backoff_2_0:
                                                        __CPROVER_assume(__cs_pc_cs[2] >= 23);

                                                        
# 1778 "<previous_module>"
;
                                                        ;
                                                }
                                                
# 1780 "<previous_module>"
;
                                                
# 1781 "<previous_module>"
tpop_0_23: IF(2,23,tpop_0_24)__CSEQ_removeindent;
                                                
# 1782 "<previous_module>"
__cs_mutex_lock(&library_lock, 2);
                                                
# 1783 "<previous_module>"
tpop_0_24: IF(2,24,tpop_0_25)__CSEQ_removeindent;
                                                
# 1784 "<previous_module>"
__cs_mutex_unlock(&library_lock, 2);
                                        }

                                        
# 1786 "<previous_module>"
__CPROVER_assume(__cs_pc_cs[2] >= 25);
                                        ;
                                        
# 1787 "<previous_module>"
__cs_local_lfds711_stack_pop_i++;
                                        
# 1788 "<previous_module>"
;
                                        ;
                                        
# 1789 "<previous_module>"
static _Bool __cs_local_lfds711_stack_pop___cs_tmp_if_cond_10;
                                        
# 1790 "<previous_module>"
__cs_local_lfds711_stack_pop___cs_tmp_if_cond_10 = __cs_local_lfds711_stack_pop_i > 1000;
                                        
# 1791 "<previous_module>"
if (__cs_local_lfds711_stack_pop___cs_tmp_if_cond_10)

# 1792 "<previous_module>"
                                        {
                                                
# 1793 "<previous_module>"
goto __exit_loop_15;
                                                ;
                                        }

                                        
# 1795 "<previous_module>"
;
                                }
                                
# 1797 "<previous_module>"
;
                                
# 1798 "<previous_module>"
__cs_local_lfds711_stack_pop___cs_dowhile_onetime_1++;
                                
# 1799 "<previous_module>"
tpop_0_25: IF(2,25,tpop_0_26)__CSEQ_removeindent;
                                
# 1800 "<previous_module>"
__CPROVER_assume(!(__cs_local_lfds711_stack_pop___cs_dowhile_onetime_1 < 1));
                                
# 1801 "<previous_module>"
__exit_loop_15:
                                __CPROVER_assume(__cs_pc_cs[2] >= 26);

                                
# 1802 "<previous_module>"
;
                                ;
                                
# 1803 "<previous_module>"
if (
# 1804 "<previous_module>"
!(__cs_local_lfds711_stack_pop_result == 0))

# 1805 "<previous_module>"
                                {
                                        
# 1806 "<previous_module>"
goto __exit_loop_17;
                                        ;
                                }

                                
# 1808 "<previous_module>"
;

# 1809 "<previous_module>"
                                {
                                        
# 1810 "<previous_module>"
;
                                        ;
                                        
# 1811 "<previous_module>"
static _Bool __cs_local_lfds711_stack_pop___cs_tmp_if_cond_11;
                                        
# 1812 "<previous_module>"
__cs_local_lfds711_stack_pop___cs_tmp_if_cond_11 = __cs_local_lfds711_stack_pop_original_top[0] == 0;
                                        
# 1813 "<previous_module>"
if (__cs_local_lfds711_stack_pop___cs_tmp_if_cond_11)

# 1814 "<previous_module>"
                                        {
                                                
# 1815 "<previous_module>"
tpop_0_26: IF(2,26,tpop_0_27)__CSEQ_removeindent;
                                                
# 1816 "<previous_module>"
*__cs_param_lfds711_stack_pop_se = 0;
                                                
# 1817 "<previous_module>"
__cs_retval__lfds711_stack_pop_1 = 0;
                                                
# 1818 "<previous_module>"
goto __exit__lfds711_stack_pop_1_0;
                                                ;
                                        }

                                        
# 1820 "<previous_module>"
__CPROVER_assume(__cs_pc_cs[2] >= 27);
                                        ;
                                        
# 1821 "<previous_module>"
tpop_0_27: IF(2,27,tpop_0_28)__CSEQ_removeindent;
                                        
# 1822 "<previous_module>"
__cs_local_lfds711_stack_pop_new_top[1] = __cs_local_lfds711_stack_pop_original_top[1] + 1;
                                        
# 1823 "<previous_module>"
tpop_0_28: IF(2,28,tpop_0_29)__CSEQ_removeindent;
                                        
# 1824 "<previous_module>"
__cs_local_lfds711_stack_pop_new_top[0] = (*__cs_local_lfds711_stack_pop_original_top[0]).next;
                                        
# 1825 "<previous_module>"
tpop_0_29: IF(2,29,tpop_0_30)__CSEQ_removeindent;
                                        
# 1826 "<previous_module>"
__cs_mutex_lock(&library_lock, 2);
                                        
# 1827 "<previous_module>"
tpop_0_30: IF(2,30,tpop_0_31)__CSEQ_removeindent;
                                        
# 1828 "<previous_module>"
__cs_local_lfds711_stack_pop_result = __CSEQ_atomic_swap_stack_top(&(*__cs_param_lfds711_stack_pop_ss).top[0], &__cs_local_lfds711_stack_pop_original_top[0], &__cs_local_lfds711_stack_pop_new_top[0]);
                                        
# 1829 "<previous_module>"
tpop_0_31: IF(2,31,tpop_0_32)__CSEQ_removeindent;
                                        
# 1830 "<previous_module>"
__cs_mutex_unlock(&library_lock, 2);
                                        
# 1831 "<previous_module>"
;
                                        ;
                                        
# 1832 "<previous_module>"
static _Bool __cs_local_lfds711_stack_pop___cs_tmp_if_cond_12;
                                        
# 1833 "<previous_module>"
__cs_local_lfds711_stack_pop___cs_tmp_if_cond_12 = __cs_local_lfds711_stack_pop_result == 0;
                                        
# 1834 "<previous_module>"
if (__cs_local_lfds711_stack_pop___cs_tmp_if_cond_12)

# 1835 "<previous_module>"
                                        {

# 1836 "<previous_module>"
                                                {
                                                        
# 1837 "<previous_module>"
static int __cs_local_exponential_backoff_loop;
                                                        
# 1838 "<previous_module>"
__cs_local_exponential_backoff_loop = 0;

# 1839 "<previous_module>"
                                                        {
                                                                
# 1840 "<previous_module>"
;
                                                                ;
                                                        }
                                                        
# 1842 "<previous_module>"
;
                                                        
# 1843 "<previous_module>"
__cs_local_exponential_backoff_loop++;

# 1844 "<previous_module>"
                                                        {
                                                                
# 1845 "<previous_module>"
;
                                                                ;
                                                        }
                                                        
# 1847 "<previous_module>"
;
                                                        
# 1848 "<previous_module>"
__cs_local_exponential_backoff_loop++;

# 1849 "<previous_module>"
                                                        {
                                                                
# 1850 "<previous_module>"
;
                                                                ;
                                                        }
                                                        
# 1852 "<previous_module>"
;
                                                        
# 1853 "<previous_module>"
__cs_local_exponential_backoff_loop++;
                                                        
# 1854 "<previous_module>"
tpop_0_32: IF(2,32,tpop_0_33)__CSEQ_removeindent;
                                                        
# 1855 "<previous_module>"
__CPROVER_assume(!(__cs_local_exponential_backoff_loop < 3));
                                                        
# 1856 "<previous_module>"
__exit_loop_18:
                                                        __CPROVER_assume(__cs_pc_cs[2] >= 33);

                                                        
# 1857 "<previous_module>"
;
                                                        ;
                                                        
# 1858 "<previous_module>"
__exit__exponential_backoff_3_0:
                                                        __CPROVER_assume(__cs_pc_cs[2] >= 33);

                                                        
# 1859 "<previous_module>"
;
                                                        ;
                                                }
                                                
# 1861 "<previous_module>"
;
                                                
# 1862 "<previous_module>"
tpop_0_33: IF(2,33,tpop_0_34)__CSEQ_removeindent;
                                                
# 1863 "<previous_module>"
__cs_mutex_lock(&library_lock, 2);
                                                
# 1864 "<previous_module>"
tpop_0_34: IF(2,34,tpop_0_35)__CSEQ_removeindent;
                                                
# 1865 "<previous_module>"
__cs_mutex_unlock(&library_lock, 2);
                                        }

                                        
# 1867 "<previous_module>"
__CPROVER_assume(__cs_pc_cs[2] >= 35);
                                        ;
                                        
# 1868 "<previous_module>"
__cs_local_lfds711_stack_pop_i++;
                                        
# 1869 "<previous_module>"
;
                                        ;
                                        
# 1870 "<previous_module>"
static _Bool __cs_local_lfds711_stack_pop___cs_tmp_if_cond_13;
                                        
# 1871 "<previous_module>"
__cs_local_lfds711_stack_pop___cs_tmp_if_cond_13 = __cs_local_lfds711_stack_pop_i > 1000;
                                        
# 1872 "<previous_module>"
if (__cs_local_lfds711_stack_pop___cs_tmp_if_cond_13)

# 1873 "<previous_module>"
                                        {
                                                
# 1874 "<previous_module>"
goto __exit_loop_17;
                                                ;
                                        }

                                        
# 1876 "<previous_module>"
;
                                }
                                
# 1878 "<previous_module>"
;
                                
# 1879 "<previous_module>"
if (
# 1880 "<previous_module>"
!(__cs_local_lfds711_stack_pop_result == 0))

# 1881 "<previous_module>"
                                {
                                        
# 1882 "<previous_module>"
goto __exit_loop_17;
                                        ;
                                }

                                
# 1884 "<previous_module>"
;

# 1885 "<previous_module>"
                                {
                                        
# 1886 "<previous_module>"
;
                                        ;
                                        
# 1887 "<previous_module>"
static _Bool __cs_local_lfds711_stack_pop___cs_tmp_if_cond_11;
                                        
# 1888 "<previous_module>"
__cs_local_lfds711_stack_pop___cs_tmp_if_cond_11 = __cs_local_lfds711_stack_pop_original_top[0] == 0;
                                        
# 1889 "<previous_module>"
if (__cs_local_lfds711_stack_pop___cs_tmp_if_cond_11)

# 1890 "<previous_module>"
                                        {
                                                
# 1891 "<previous_module>"
tpop_0_35: IF(2,35,tpop_0_36)__CSEQ_removeindent;
                                                
# 1892 "<previous_module>"
*__cs_param_lfds711_stack_pop_se = 0;
                                                
# 1893 "<previous_module>"
__cs_retval__lfds711_stack_pop_1 = 0;
                                                
# 1894 "<previous_module>"
goto __exit__lfds711_stack_pop_1_0;
                                                ;
                                        }

                                        
# 1896 "<previous_module>"
__CPROVER_assume(__cs_pc_cs[2] >= 36);
                                        ;
                                        
# 1897 "<previous_module>"
tpop_0_36: IF(2,36,tpop_0_37)__CSEQ_removeindent;
                                        
# 1898 "<previous_module>"
__cs_local_lfds711_stack_pop_new_top[1] = __cs_local_lfds711_stack_pop_original_top[1] + 1;
                                        
# 1899 "<previous_module>"
tpop_0_37: IF(2,37,tpop_0_38)__CSEQ_removeindent;
                                        
# 1900 "<previous_module>"
__cs_local_lfds711_stack_pop_new_top[0] = (*__cs_local_lfds711_stack_pop_original_top[0]).next;
                                        
# 1901 "<previous_module>"
tpop_0_38: IF(2,38,tpop_0_39)__CSEQ_removeindent;
                                        
# 1902 "<previous_module>"
__cs_mutex_lock(&library_lock, 2);
                                        
# 1903 "<previous_module>"
tpop_0_39: IF(2,39,tpop_0_40)__CSEQ_removeindent;
                                        
# 1904 "<previous_module>"
__cs_local_lfds711_stack_pop_result = __CSEQ_atomic_swap_stack_top(&(*__cs_param_lfds711_stack_pop_ss).top[0], &__cs_local_lfds711_stack_pop_original_top[0], &__cs_local_lfds711_stack_pop_new_top[0]);
                                        
# 1905 "<previous_module>"
tpop_0_40: IF(2,40,tpop_0_41)__CSEQ_removeindent;
                                        
# 1906 "<previous_module>"
__cs_mutex_unlock(&library_lock, 2);
                                        
# 1907 "<previous_module>"
;
                                        ;
                                        
# 1908 "<previous_module>"
static _Bool __cs_local_lfds711_stack_pop___cs_tmp_if_cond_12;
                                        
# 1909 "<previous_module>"
__cs_local_lfds711_stack_pop___cs_tmp_if_cond_12 = __cs_local_lfds711_stack_pop_result == 0;
                                        
# 1910 "<previous_module>"
if (__cs_local_lfds711_stack_pop___cs_tmp_if_cond_12)

# 1911 "<previous_module>"
                                        {

# 1912 "<previous_module>"
                                                {
                                                        
# 1913 "<previous_module>"
static int __cs_local_exponential_backoff_loop;
                                                        
# 1914 "<previous_module>"
__cs_local_exponential_backoff_loop = 0;

# 1915 "<previous_module>"
                                                        {
                                                                
# 1916 "<previous_module>"
;
                                                                ;
                                                        }
                                                        
# 1918 "<previous_module>"
;
                                                        
# 1919 "<previous_module>"
__cs_local_exponential_backoff_loop++;

# 1920 "<previous_module>"
                                                        {
                                                                
# 1921 "<previous_module>"
;
                                                                ;
                                                        }
                                                        
# 1923 "<previous_module>"
;
                                                        
# 1924 "<previous_module>"
__cs_local_exponential_backoff_loop++;

# 1925 "<previous_module>"
                                                        {
                                                                
# 1926 "<previous_module>"
;
                                                                ;
                                                        }
                                                        
# 1928 "<previous_module>"
;
                                                        
# 1929 "<previous_module>"
__cs_local_exponential_backoff_loop++;
                                                        
# 1930 "<previous_module>"
tpop_0_41: IF(2,41,tpop_0_42)__CSEQ_removeindent;
                                                        
# 1931 "<previous_module>"
__CPROVER_assume(!(__cs_local_exponential_backoff_loop < 3));
                                                        
# 1932 "<previous_module>"
__exit_loop_19:
                                                        __CPROVER_assume(__cs_pc_cs[2] >= 42);

                                                        
# 1933 "<previous_module>"
;
                                                        ;
                                                        
# 1934 "<previous_module>"
__exit__exponential_backoff_3_1:
                                                        __CPROVER_assume(__cs_pc_cs[2] >= 42);

                                                        
# 1935 "<previous_module>"
;
                                                        ;
                                                }
                                                
# 1937 "<previous_module>"
;
                                                
# 1938 "<previous_module>"
tpop_0_42: IF(2,42,tpop_0_43)__CSEQ_removeindent;
                                                
# 1939 "<previous_module>"
__cs_mutex_lock(&library_lock, 2);
                                                
# 1940 "<previous_module>"
tpop_0_43: IF(2,43,tpop_0_44)__CSEQ_removeindent;
                                                
# 1941 "<previous_module>"
__cs_mutex_unlock(&library_lock, 2);
                                        }

                                        
# 1943 "<previous_module>"
__CPROVER_assume(__cs_pc_cs[2] >= 44);
                                        ;
                                        
# 1944 "<previous_module>"
__cs_local_lfds711_stack_pop_i++;
                                        
# 1945 "<previous_module>"
;
                                        ;
                                        
# 1946 "<previous_module>"
static _Bool __cs_local_lfds711_stack_pop___cs_tmp_if_cond_13;
                                        
# 1947 "<previous_module>"
__cs_local_lfds711_stack_pop___cs_tmp_if_cond_13 = __cs_local_lfds711_stack_pop_i > 1000;
                                        
# 1948 "<previous_module>"
if (__cs_local_lfds711_stack_pop___cs_tmp_if_cond_13)

# 1949 "<previous_module>"
                                        {
                                                
# 1950 "<previous_module>"
goto __exit_loop_17;
                                                ;
                                        }

                                        
# 1952 "<previous_module>"
;
                                }
                                
# 1954 "<previous_module>"
;
                                
# 1955 "<previous_module>"
if (
# 1956 "<previous_module>"
!(__cs_local_lfds711_stack_pop_result == 0))

# 1957 "<previous_module>"
                                {
                                        
# 1958 "<previous_module>"
goto __exit_loop_17;
                                        ;
                                }

                                
# 1960 "<previous_module>"
;

# 1961 "<previous_module>"
                                {
                                        
# 1962 "<previous_module>"
;
                                        ;
                                        
# 1963 "<previous_module>"
static _Bool __cs_local_lfds711_stack_pop___cs_tmp_if_cond_11;
                                        
# 1964 "<previous_module>"
__cs_local_lfds711_stack_pop___cs_tmp_if_cond_11 = __cs_local_lfds711_stack_pop_original_top[0] == 0;
                                        
# 1965 "<previous_module>"
if (__cs_local_lfds711_stack_pop___cs_tmp_if_cond_11)

# 1966 "<previous_module>"
                                        {
                                                
# 1967 "<previous_module>"
tpop_0_44: IF(2,44,tpop_0_45)__CSEQ_removeindent;
                                                
# 1968 "<previous_module>"
*__cs_param_lfds711_stack_pop_se = 0;
                                                
# 1969 "<previous_module>"
__cs_retval__lfds711_stack_pop_1 = 0;
                                                
# 1970 "<previous_module>"
goto __exit__lfds711_stack_pop_1_0;
                                                ;
                                        }

                                        
# 1972 "<previous_module>"
__CPROVER_assume(__cs_pc_cs[2] >= 45);
                                        ;
                                        
# 1973 "<previous_module>"
tpop_0_45: IF(2,45,tpop_0_46)__CSEQ_removeindent;
                                        
# 1974 "<previous_module>"
__cs_local_lfds711_stack_pop_new_top[1] = __cs_local_lfds711_stack_pop_original_top[1] + 1;
                                        
# 1975 "<previous_module>"
tpop_0_46: IF(2,46,tpop_0_47)__CSEQ_removeindent;
                                        
# 1976 "<previous_module>"
__cs_local_lfds711_stack_pop_new_top[0] = (*__cs_local_lfds711_stack_pop_original_top[0]).next;
                                        
# 1977 "<previous_module>"
tpop_0_47: IF(2,47,tpop_0_48)__CSEQ_removeindent;
                                        
# 1978 "<previous_module>"
__cs_mutex_lock(&library_lock, 2);
                                        
# 1979 "<previous_module>"
tpop_0_48: IF(2,48,tpop_0_49)__CSEQ_removeindent;
                                        
# 1980 "<previous_module>"
__cs_local_lfds711_stack_pop_result = __CSEQ_atomic_swap_stack_top(&(*__cs_param_lfds711_stack_pop_ss).top[0], &__cs_local_lfds711_stack_pop_original_top[0], &__cs_local_lfds711_stack_pop_new_top[0]);
                                        
# 1981 "<previous_module>"
tpop_0_49: IF(2,49,tpop_0_50)__CSEQ_removeindent;
                                        
# 1982 "<previous_module>"
__cs_mutex_unlock(&library_lock, 2);
                                        
# 1983 "<previous_module>"
;
                                        ;
                                        
# 1984 "<previous_module>"
static _Bool __cs_local_lfds711_stack_pop___cs_tmp_if_cond_12;
                                        
# 1985 "<previous_module>"
__cs_local_lfds711_stack_pop___cs_tmp_if_cond_12 = __cs_local_lfds711_stack_pop_result == 0;
                                        
# 1986 "<previous_module>"
if (__cs_local_lfds711_stack_pop___cs_tmp_if_cond_12)

# 1987 "<previous_module>"
                                        {

# 1988 "<previous_module>"
                                                {
                                                        
# 1989 "<previous_module>"
static int __cs_local_exponential_backoff_loop;
                                                        
# 1990 "<previous_module>"
__cs_local_exponential_backoff_loop = 0;

# 1991 "<previous_module>"
                                                        {
                                                                
# 1992 "<previous_module>"
;
                                                                ;
                                                        }
                                                        
# 1994 "<previous_module>"
;
                                                        
# 1995 "<previous_module>"
__cs_local_exponential_backoff_loop++;

# 1996 "<previous_module>"
                                                        {
                                                                
# 1997 "<previous_module>"
;
                                                                ;
                                                        }
                                                        
# 1999 "<previous_module>"
;
                                                        
# 2000 "<previous_module>"
__cs_local_exponential_backoff_loop++;

# 2001 "<previous_module>"
                                                        {
                                                                
# 2002 "<previous_module>"
;
                                                                ;
                                                        }
                                                        
# 2004 "<previous_module>"
;
                                                        
# 2005 "<previous_module>"
__cs_local_exponential_backoff_loop++;
                                                        
# 2006 "<previous_module>"
tpop_0_50: IF(2,50,tpop_0_51)__CSEQ_removeindent;
                                                        
# 2007 "<previous_module>"
__CPROVER_assume(!(__cs_local_exponential_backoff_loop < 3));
                                                        
# 2008 "<previous_module>"
__exit_loop_20:
                                                        __CPROVER_assume(__cs_pc_cs[2] >= 51);

                                                        
# 2009 "<previous_module>"
;
                                                        ;
                                                        
# 2010 "<previous_module>"
__exit__exponential_backoff_3_2:
                                                        __CPROVER_assume(__cs_pc_cs[2] >= 51);

                                                        
# 2011 "<previous_module>"
;
                                                        ;
                                                }
                                                
# 2013 "<previous_module>"
;
                                                
# 2014 "<previous_module>"
tpop_0_51: IF(2,51,tpop_0_52)__CSEQ_removeindent;
                                                
# 2015 "<previous_module>"
__cs_mutex_lock(&library_lock, 2);
                                                
# 2016 "<previous_module>"
tpop_0_52: IF(2,52,tpop_0_53)__CSEQ_removeindent;
                                                
# 2017 "<previous_module>"
__cs_mutex_unlock(&library_lock, 2);
                                        }

                                        
# 2019 "<previous_module>"
__CPROVER_assume(__cs_pc_cs[2] >= 53);
                                        ;
                                        
# 2020 "<previous_module>"
__cs_local_lfds711_stack_pop_i++;
                                        
# 2021 "<previous_module>"
;
                                        ;
                                        
# 2022 "<previous_module>"
static _Bool __cs_local_lfds711_stack_pop___cs_tmp_if_cond_13;
                                        
# 2023 "<previous_module>"
__cs_local_lfds711_stack_pop___cs_tmp_if_cond_13 = __cs_local_lfds711_stack_pop_i > 1000;
                                        
# 2024 "<previous_module>"
if (__cs_local_lfds711_stack_pop___cs_tmp_if_cond_13)

# 2025 "<previous_module>"
                                        {
                                                
# 2026 "<previous_module>"
goto __exit_loop_17;
                                                ;
                                        }

                                        
# 2028 "<previous_module>"
;
                                }
                                
# 2030 "<previous_module>"
;
                                
# 2031 "<previous_module>"
if (
# 2032 "<previous_module>"
!(__cs_local_lfds711_stack_pop_result == 0))

# 2033 "<previous_module>"
                                {
                                        
# 2034 "<previous_module>"
goto __exit_loop_17;
                                        ;
                                }

                                
# 2036 "<previous_module>"
;

# 2037 "<previous_module>"
                                {
                                        
# 2038 "<previous_module>"
;
                                        ;
                                        
# 2039 "<previous_module>"
static _Bool __cs_local_lfds711_stack_pop___cs_tmp_if_cond_11;
                                        
# 2040 "<previous_module>"
__cs_local_lfds711_stack_pop___cs_tmp_if_cond_11 = __cs_local_lfds711_stack_pop_original_top[0] == 0;
                                        
# 2041 "<previous_module>"
if (__cs_local_lfds711_stack_pop___cs_tmp_if_cond_11)

# 2042 "<previous_module>"
                                        {
                                                
# 2043 "<previous_module>"
tpop_0_53: IF(2,53,tpop_0_54)__CSEQ_removeindent;
                                                
# 2044 "<previous_module>"
*__cs_param_lfds711_stack_pop_se = 0;
                                                
# 2045 "<previous_module>"
__cs_retval__lfds711_stack_pop_1 = 0;
                                                
# 2046 "<previous_module>"
goto __exit__lfds711_stack_pop_1_0;
                                                ;
                                        }

                                        
# 2048 "<previous_module>"
__CPROVER_assume(__cs_pc_cs[2] >= 54);
                                        ;
                                        
# 2049 "<previous_module>"
tpop_0_54: IF(2,54,tpop_0_55)__CSEQ_removeindent;
                                        
# 2050 "<previous_module>"
__cs_local_lfds711_stack_pop_new_top[1] = __cs_local_lfds711_stack_pop_original_top[1] + 1;
                                        
# 2051 "<previous_module>"
tpop_0_55: IF(2,55,tpop_0_56)__CSEQ_removeindent;
                                        
# 2052 "<previous_module>"
__cs_local_lfds711_stack_pop_new_top[0] = (*__cs_local_lfds711_stack_pop_original_top[0]).next;
                                        
# 2053 "<previous_module>"
tpop_0_56: IF(2,56,tpop_0_57)__CSEQ_removeindent;
                                        
# 2054 "<previous_module>"
__cs_mutex_lock(&library_lock, 2);
                                        
# 2055 "<previous_module>"
tpop_0_57: IF(2,57,tpop_0_58)__CSEQ_removeindent;
                                        
# 2056 "<previous_module>"
__cs_local_lfds711_stack_pop_result = __CSEQ_atomic_swap_stack_top(&(*__cs_param_lfds711_stack_pop_ss).top[0], &__cs_local_lfds711_stack_pop_original_top[0], &__cs_local_lfds711_stack_pop_new_top[0]);
                                        
# 2057 "<previous_module>"
tpop_0_58: IF(2,58,tpop_0_59)__CSEQ_removeindent;
                                        
# 2058 "<previous_module>"
__cs_mutex_unlock(&library_lock, 2);
                                        
# 2059 "<previous_module>"
;
                                        ;
                                        
# 2060 "<previous_module>"
static _Bool __cs_local_lfds711_stack_pop___cs_tmp_if_cond_12;
                                        
# 2061 "<previous_module>"
__cs_local_lfds711_stack_pop___cs_tmp_if_cond_12 = __cs_local_lfds711_stack_pop_result == 0;
                                        
# 2062 "<previous_module>"
if (__cs_local_lfds711_stack_pop___cs_tmp_if_cond_12)

# 2063 "<previous_module>"
                                        {

# 2064 "<previous_module>"
                                                {
                                                        
# 2065 "<previous_module>"
static int __cs_local_exponential_backoff_loop;
                                                        
# 2066 "<previous_module>"
__cs_local_exponential_backoff_loop = 0;

# 2067 "<previous_module>"
                                                        {
                                                                
# 2068 "<previous_module>"
;
                                                                ;
                                                        }
                                                        
# 2070 "<previous_module>"
;
                                                        
# 2071 "<previous_module>"
__cs_local_exponential_backoff_loop++;

# 2072 "<previous_module>"
                                                        {
                                                                
# 2073 "<previous_module>"
;
                                                                ;
                                                        }
                                                        
# 2075 "<previous_module>"
;
                                                        
# 2076 "<previous_module>"
__cs_local_exponential_backoff_loop++;

# 2077 "<previous_module>"
                                                        {
                                                                
# 2078 "<previous_module>"
;
                                                                ;
                                                        }
                                                        
# 2080 "<previous_module>"
;
                                                        
# 2081 "<previous_module>"
__cs_local_exponential_backoff_loop++;
                                                        
# 2082 "<previous_module>"
tpop_0_59: IF(2,59,tpop_0_60)__CSEQ_removeindent;
                                                        
# 2083 "<previous_module>"
__CPROVER_assume(!(__cs_local_exponential_backoff_loop < 3));
                                                        
# 2084 "<previous_module>"
__exit_loop_21:
                                                        __CPROVER_assume(__cs_pc_cs[2] >= 60);

                                                        
# 2085 "<previous_module>"
;
                                                        ;
                                                        
# 2086 "<previous_module>"
__exit__exponential_backoff_3_3:
                                                        __CPROVER_assume(__cs_pc_cs[2] >= 60);

                                                        
# 2087 "<previous_module>"
;
                                                        ;
                                                }
                                                
# 2089 "<previous_module>"
;
                                                
# 2090 "<previous_module>"
tpop_0_60: IF(2,60,tpop_0_61)__CSEQ_removeindent;
                                                
# 2091 "<previous_module>"
__cs_mutex_lock(&library_lock, 2);
                                                
# 2092 "<previous_module>"
tpop_0_61: IF(2,61,tpop_0_62)__CSEQ_removeindent;
                                                
# 2093 "<previous_module>"
__cs_mutex_unlock(&library_lock, 2);
                                        }

                                        
# 2095 "<previous_module>"
__CPROVER_assume(__cs_pc_cs[2] >= 62);
                                        ;
                                        
# 2096 "<previous_module>"
__cs_local_lfds711_stack_pop_i++;
                                        
# 2097 "<previous_module>"
;
                                        ;
                                        
# 2098 "<previous_module>"
static _Bool __cs_local_lfds711_stack_pop___cs_tmp_if_cond_13;
                                        
# 2099 "<previous_module>"
__cs_local_lfds711_stack_pop___cs_tmp_if_cond_13 = __cs_local_lfds711_stack_pop_i > 1000;
                                        
# 2100 "<previous_module>"
if (__cs_local_lfds711_stack_pop___cs_tmp_if_cond_13)

# 2101 "<previous_module>"
                                        {
                                                
# 2102 "<previous_module>"
goto __exit_loop_17;
                                                ;
                                        }

                                        
# 2104 "<previous_module>"
;
                                }
                                
# 2106 "<previous_module>"
;
                                
# 2107 "<previous_module>"
if (
# 2108 "<previous_module>"
!(__cs_local_lfds711_stack_pop_result == 0))

# 2109 "<previous_module>"
                                {
                                        
# 2110 "<previous_module>"
goto __exit_loop_17;
                                        ;
                                }

                                
# 2112 "<previous_module>"
;

# 2113 "<previous_module>"
                                {
                                        
# 2114 "<previous_module>"
;
                                        ;
                                        
# 2115 "<previous_module>"
static _Bool __cs_local_lfds711_stack_pop___cs_tmp_if_cond_11;
                                        
# 2116 "<previous_module>"
__cs_local_lfds711_stack_pop___cs_tmp_if_cond_11 = __cs_local_lfds711_stack_pop_original_top[0] == 0;
                                        
# 2117 "<previous_module>"
if (__cs_local_lfds711_stack_pop___cs_tmp_if_cond_11)

# 2118 "<previous_module>"
                                        {
                                                
# 2119 "<previous_module>"
tpop_0_62: IF(2,62,tpop_0_63)__CSEQ_removeindent;
                                                
# 2120 "<previous_module>"
*__cs_param_lfds711_stack_pop_se = 0;
                                                
# 2121 "<previous_module>"
__cs_retval__lfds711_stack_pop_1 = 0;
                                                
# 2122 "<previous_module>"
goto __exit__lfds711_stack_pop_1_0;
                                                ;
                                        }

                                        
# 2124 "<previous_module>"
__CPROVER_assume(__cs_pc_cs[2] >= 63);
                                        ;
                                        
# 2125 "<previous_module>"
tpop_0_63: IF(2,63,tpop_0_64)__CSEQ_removeindent;
                                        
# 2126 "<previous_module>"
__cs_local_lfds711_stack_pop_new_top[1] = __cs_local_lfds711_stack_pop_original_top[1] + 1;
                                        
# 2127 "<previous_module>"
tpop_0_64: IF(2,64,tpop_0_65)__CSEQ_removeindent;
                                        
# 2128 "<previous_module>"
__cs_local_lfds711_stack_pop_new_top[0] = (*__cs_local_lfds711_stack_pop_original_top[0]).next;
                                        
# 2129 "<previous_module>"
tpop_0_65: IF(2,65,tpop_0_66)__CSEQ_removeindent;
                                        
# 2130 "<previous_module>"
__cs_mutex_lock(&library_lock, 2);
                                        
# 2131 "<previous_module>"
tpop_0_66: IF(2,66,tpop_0_67)__CSEQ_removeindent;
                                        
# 2132 "<previous_module>"
__cs_local_lfds711_stack_pop_result = __CSEQ_atomic_swap_stack_top(&(*__cs_param_lfds711_stack_pop_ss).top[0], &__cs_local_lfds711_stack_pop_original_top[0], &__cs_local_lfds711_stack_pop_new_top[0]);
                                        
# 2133 "<previous_module>"
tpop_0_67: IF(2,67,tpop_0_68)__CSEQ_removeindent;
                                        
# 2134 "<previous_module>"
__cs_mutex_unlock(&library_lock, 2);
                                        
# 2135 "<previous_module>"
;
                                        ;
                                        
# 2136 "<previous_module>"
static _Bool __cs_local_lfds711_stack_pop___cs_tmp_if_cond_12;
                                        
# 2137 "<previous_module>"
__cs_local_lfds711_stack_pop___cs_tmp_if_cond_12 = __cs_local_lfds711_stack_pop_result == 0;
                                        
# 2138 "<previous_module>"
if (__cs_local_lfds711_stack_pop___cs_tmp_if_cond_12)

# 2139 "<previous_module>"
                                        {

# 2140 "<previous_module>"
                                                {
                                                        
# 2141 "<previous_module>"
static int __cs_local_exponential_backoff_loop;
                                                        
# 2142 "<previous_module>"
__cs_local_exponential_backoff_loop = 0;

# 2143 "<previous_module>"
                                                        {
                                                                
# 2144 "<previous_module>"
;
                                                                ;
                                                        }
                                                        
# 2146 "<previous_module>"
;
                                                        
# 2147 "<previous_module>"
__cs_local_exponential_backoff_loop++;

# 2148 "<previous_module>"
                                                        {
                                                                
# 2149 "<previous_module>"
;
                                                                ;
                                                        }
                                                        
# 2151 "<previous_module>"
;
                                                        
# 2152 "<previous_module>"
__cs_local_exponential_backoff_loop++;

# 2153 "<previous_module>"
                                                        {
                                                                
# 2154 "<previous_module>"
;
                                                                ;
                                                        }
                                                        
# 2156 "<previous_module>"
;
                                                        
# 2157 "<previous_module>"
__cs_local_exponential_backoff_loop++;
                                                        
# 2158 "<previous_module>"
tpop_0_68: IF(2,68,tpop_0_69)__CSEQ_removeindent;
                                                        
# 2159 "<previous_module>"
__CPROVER_assume(!(__cs_local_exponential_backoff_loop < 3));
                                                        
# 2160 "<previous_module>"
__exit_loop_22:
                                                        __CPROVER_assume(__cs_pc_cs[2] >= 69);

                                                        
# 2161 "<previous_module>"
;
                                                        ;
                                                        
# 2162 "<previous_module>"
__exit__exponential_backoff_3_4:
                                                        __CPROVER_assume(__cs_pc_cs[2] >= 69);

                                                        
# 2163 "<previous_module>"
;
                                                        ;
                                                }
                                                
# 2165 "<previous_module>"
;
                                                
# 2166 "<previous_module>"
tpop_0_69: IF(2,69,tpop_0_70)__CSEQ_removeindent;
                                                
# 2167 "<previous_module>"
__cs_mutex_lock(&library_lock, 2);
                                                
# 2168 "<previous_module>"
tpop_0_70: IF(2,70,tpop_0_71)__CSEQ_removeindent;
                                                
# 2169 "<previous_module>"
__cs_mutex_unlock(&library_lock, 2);
                                        }

                                        
# 2171 "<previous_module>"
__CPROVER_assume(__cs_pc_cs[2] >= 71);
                                        ;
                                        
# 2172 "<previous_module>"
__cs_local_lfds711_stack_pop_i++;
                                        
# 2173 "<previous_module>"
;
                                        ;
                                        
# 2174 "<previous_module>"
static _Bool __cs_local_lfds711_stack_pop___cs_tmp_if_cond_13;
                                        
# 2175 "<previous_module>"
__cs_local_lfds711_stack_pop___cs_tmp_if_cond_13 = __cs_local_lfds711_stack_pop_i > 1000;
                                        
# 2176 "<previous_module>"
if (__cs_local_lfds711_stack_pop___cs_tmp_if_cond_13)

# 2177 "<previous_module>"
                                        {
                                                
# 2178 "<previous_module>"
goto __exit_loop_17;
                                                ;
                                        }

                                        
# 2180 "<previous_module>"
;
                                }
                                
# 2182 "<previous_module>"
;
                                
# 2183 "<previous_module>"
tpop_0_71: IF(2,71,tpop_0_72)__CSEQ_removeindent;
                                
# 2184 "<previous_module>"
__CPROVER_assume(
# 2185 "<previous_module>"
!(__cs_local_lfds711_stack_pop_result == 0));
                                
# 2186 "<previous_module>"
__exit_loop_17:
                                __CPROVER_assume(__cs_pc_cs[2] >= 72);

                                
# 2187 "<previous_module>"
;
                                ;
                                
# 2188 "<previous_module>"
tpop_0_72: IF(2,72,tpop_0_73)__CSEQ_removeindent;
                                
# 2189 "<previous_module>"
*__cs_param_lfds711_stack_pop_se = __cs_local_lfds711_stack_pop_original_top[0];
                                
# 2190 "<previous_module>"
__cs_retval__lfds711_stack_pop_1 = __cs_local_lfds711_stack_pop_result;
                                
# 2191 "<previous_module>"
goto __exit__lfds711_stack_pop_1_0;
                                ;
                                
# 2192 "<previous_module>"
__exit__lfds711_stack_pop_1_0:
                                __CPROVER_assume(__cs_pc_cs[2] >= 73);

                                
# 2193 "<previous_module>"
;
                                ;
                        }
                        
# 2195 "<previous_module>"
;
                        
# 2196 "<previous_module>"
__cs_local_delete_res = __cs_retval__lfds711_stack_pop_1;
                        
# 2197 "<previous_module>"
;
                        ;
                        
# 2198 "<previous_module>"
static _Bool __cs_local_delete___cs_tmp_if_cond_19;
                        
# 2199 "<previous_module>"
__cs_local_delete___cs_tmp_if_cond_19 = __cs_local_delete_res == 0;
                        
# 2200 "<previous_module>"
if (__cs_local_delete___cs_tmp_if_cond_19)

# 2201 "<previous_module>"
                        {
                                
# 2202 "<previous_module>"
__cs_retval__delete_1 = __cs_local_delete_res;
                                
# 2203 "<previous_module>"
goto __exit__delete_1_0;
                                ;
                        }

                        
# 2205 "<previous_module>"
;
                        
# 2206 "<previous_module>"
tpop_0_73: IF(2,73,tpop_0_74)__CSEQ_removeindent;
                        
# 2207 "<previous_module>"
__cs_local_delete_temp_td = (*__cs_local_delete_se).value;
                        
# 2208 "<previous_module>"
static int __cs_local_delete_id_popped;
                        
# 2209 "<previous_module>"
tpop_0_74: IF(2,74,tpop_0_75)__CSEQ_removeindent;
                        
# 2210 "<previous_module>"
__cs_local_delete_id_popped = (*__cs_local_delete_temp_td).user_id;
                        
# 2211 "<previous_module>"
tpop_0_75: IF(2,75,tpop_0_76)__CSEQ_removeindent;
                        
# 2212 "<previous_module>"
printf("%llu\n", (*__cs_local_delete_temp_td).user_id);
                        
# 2213 "<previous_module>"
__cs_retval__delete_1 = __cs_local_delete_res;
                        
# 2214 "<previous_module>"
goto __exit__delete_1_0;
                        ;
                        
# 2215 "<previous_module>"
__exit__delete_1_0:
                        __CPROVER_assume(__cs_pc_cs[2] >= 76);

                        
# 2216 "<previous_module>"
;
                        ;
                }
                
# 2218 "<previous_module>"
;
                
# 2219 "<previous_module>"
__cs_retval__delete_1;
                
# 2220 "<previous_module>"
;
                ;
                
# 2221 "<previous_module>"
static _Bool __cs_local_pop___cs_tmp_if_cond_27;
                
# 2222 "<previous_module>"
tpop_0_76: IF(2,76,tpop_0_77)__CSEQ_removeindent;
                
# 2223 "<previous_module>"
__cs_local_pop___cs_tmp_if_cond_27 = ATOMIC_OPERATION;
                
# 2224 "<previous_module>"
if (__cs_local_pop___cs_tmp_if_cond_27)

# 2225 "<previous_module>"
                {
                        
# 2226 "<previous_module>"
tpop_0_77: IF(2,77,tpop_0_78)__CSEQ_removeindent;
                        
# 2227 "<previous_module>"
__cs_mutex_unlock(&lock, 2);
                }

                
# 2229 "<previous_module>"
__CPROVER_assume(__cs_pc_cs[2] >= 78);
                ;
                
# 2230 "<previous_module>"
;
                ;
        }
        
# 2232 "<previous_module>"
;
        
# 2233 "<previous_module>"
__cs_local_pop_loop++;

# 2234 "<previous_module>"
        {
                
# 2235 "<previous_module>"
;
                ;
                
# 2236 "<previous_module>"
static _Bool __cs_local_pop___cs_tmp_if_cond_26;
                
# 2237 "<previous_module>"
tpop_0_78: IF(2,78,tpop_0_79)__CSEQ_removeindent;
                
# 2238 "<previous_module>"
__cs_local_pop___cs_tmp_if_cond_26 = ATOMIC_OPERATION;
                
# 2239 "<previous_module>"
if (__cs_local_pop___cs_tmp_if_cond_26)

# 2240 "<previous_module>"
                {
                        
# 2241 "<previous_module>"
tpop_0_79: IF(2,79,tpop_0_80)__CSEQ_removeindent;
                        
# 2242 "<previous_module>"
__cs_mutex_lock(&lock, 2);
                }

                
# 2244 "<previous_module>"
__CPROVER_assume(__cs_pc_cs[2] >= 80);
                ;
                
# 2245 "<previous_module>"
;
                ;
                
# 2246 "<previous_module>"
static int __cs_retval__delete_1;

# 2247 "<previous_module>"
                {
                        
# 2248 "<previous_module>"
static struct lfds711_stack_state *__cs_param_delete_s;
                        
# 2249 "<previous_module>"
tpop_0_80: IF(2,80,tpop_0_81)__CSEQ_removeindent;
                        
# 2250 "<previous_module>"
__cs_param_delete_s = ss;
                        
# 2251 "<previous_module>"
static struct lfds711_stack_element *__cs_local_delete_se;
                        
# 2252 "<previous_module>"
static struct test_data *__cs_local_delete_temp_td;
                        
# 2253 "<previous_module>"
static int __cs_local_delete_res;
                        
# 2254 "<previous_module>"
static int __cs_retval__lfds711_stack_pop_1;

# 2255 "<previous_module>"
                        {
                                
# 2256 "<previous_module>"
static struct lfds711_stack_state *__cs_param_lfds711_stack_pop_ss;
                                
# 2257 "<previous_module>"
tpop_0_81: IF(2,81,tpop_0_82)__CSEQ_removeindent;
                                
# 2258 "<previous_module>"
__cs_param_lfds711_stack_pop_ss = &mystack;
                                
# 2259 "<previous_module>"
static struct lfds711_stack_element **__cs_param_lfds711_stack_pop_se;
                                
# 2260 "<previous_module>"
tpop_0_82: IF(2,82,tpop_0_83)__CSEQ_removeindent;
                                
# 2261 "<previous_module>"
__cs_param_lfds711_stack_pop_se = &__cs_local_delete_se;
                                
# 2262 "<previous_module>"
static char unsigned __cs_local_lfds711_stack_pop_result;
                                
# 2263 "<previous_module>"
static lfds711_pal_uint_t __cs_local_lfds711_stack_pop_backoff_iteration;
                                
# 2264 "<previous_module>"
__cs_local_lfds711_stack_pop_backoff_iteration = 0;
                                
# 2265 "<previous_module>"
static struct lfds711_stack_element *__cs_local_lfds711_stack_pop_new_top[2];
                                
# 2266 "<previous_module>"
static struct lfds711_stack_element * volatile __cs_local_lfds711_stack_pop_original_top[2];
                                
# 2267 "<previous_module>"
;
                                ;
                                
# 2268 "<previous_module>"
static _Bool __cs_local_lfds711_stack_pop___cs_tmp_if_cond_6;
                                
# 2269 "<previous_module>"
tpop_0_83: IF(2,83,tpop_0_84)__CSEQ_removeindent;
                                
# 2270 "<previous_module>"
__cs_local_lfds711_stack_pop___cs_tmp_if_cond_6 = !(__cs_param_lfds711_stack_pop_ss != 0);
                                
# 2271 "<previous_module>"
if (__cs_local_lfds711_stack_pop___cs_tmp_if_cond_6)

# 2272 "<previous_module>"
                                {
                                        
# 2273 "<previous_module>"
static char *__cs_local_lfds711_stack_pop_c;
                                        
# 2274 "<previous_module>"
tpop_0_84: IF(2,84,tpop_0_85)__CSEQ_removeindent;
                                        
# 2275 "<previous_module>"
__cs_local_lfds711_stack_pop_c = 0;
                                        
# 2276 "<previous_module>"
tpop_0_85: IF(2,85,tpop_0_86)__CSEQ_removeindent;
                                        
# 2277 "<previous_module>"
*__cs_local_lfds711_stack_pop_c = 0;
                                }

                                
# 2279 "<previous_module>"
__CPROVER_assume(__cs_pc_cs[2] >= 86);
                                ;
                                
# 2280 "<previous_module>"
;
                                ;
                                
# 2281 "<previous_module>"
;
                                ;
                                
# 2282 "<previous_module>"
;
                                ;
                                
# 2283 "<previous_module>"
static _Bool __cs_local_lfds711_stack_pop___cs_tmp_if_cond_7;
                                
# 2284 "<previous_module>"
tpop_0_86: IF(2,86,tpop_0_87)__CSEQ_removeindent;
                                
# 2285 "<previous_module>"
__cs_local_lfds711_stack_pop___cs_tmp_if_cond_7 = !(__cs_param_lfds711_stack_pop_se != 0);
                                
# 2286 "<previous_module>"
if (__cs_local_lfds711_stack_pop___cs_tmp_if_cond_7)

# 2287 "<previous_module>"
                                {
                                        
# 2288 "<previous_module>"
static char *__cs_local_lfds711_stack_pop_c;
                                        
# 2289 "<previous_module>"
tpop_0_87: IF(2,87,tpop_0_88)__CSEQ_removeindent;
                                        
# 2290 "<previous_module>"
__cs_local_lfds711_stack_pop_c = 0;
                                        
# 2291 "<previous_module>"
tpop_0_88: IF(2,88,tpop_0_89)__CSEQ_removeindent;
                                        
# 2292 "<previous_module>"
*__cs_local_lfds711_stack_pop_c = 0;
                                }

                                
# 2294 "<previous_module>"
__CPROVER_assume(__cs_pc_cs[2] >= 89);
                                ;
                                
# 2295 "<previous_module>"
;
                                ;
                                
# 2296 "<previous_module>"
;
                                ;
                                
# 2297 "<previous_module>"
tpop_0_89: IF(2,89,tpop_0_90)__CSEQ_removeindent;
                                
# 2298 "<previous_module>"
__cs_mutex_lock(&library_lock, 2);
                                
# 2299 "<previous_module>"
tpop_0_90: IF(2,90,tpop_0_91)__CSEQ_removeindent;
                                
# 2300 "<previous_module>"
__cs_mutex_unlock(&library_lock, 2);
                                
# 2301 "<previous_module>"
tpop_0_91: IF(2,91,tpop_0_92)__CSEQ_removeindent;
                                
# 2302 "<previous_module>"
__cs_local_lfds711_stack_pop_original_top[1] = (*__cs_param_lfds711_stack_pop_ss).top[1];
                                
# 2303 "<previous_module>"
tpop_0_92: IF(2,92,tpop_0_93)__CSEQ_removeindent;
                                
# 2304 "<previous_module>"
__cs_local_lfds711_stack_pop_original_top[0] = (*__cs_param_lfds711_stack_pop_ss).top[0];
                                
# 2305 "<previous_module>"
static int __cs_local_lfds711_stack_pop_i;
                                
# 2306 "<previous_module>"
__cs_local_lfds711_stack_pop_i = 0;
                                
# 2307 "<previous_module>"
;
                                ;
                                
# 2308 "<previous_module>"
static int __cs_local_lfds711_stack_pop___cs_dowhile_onetime_1;
                                
# 2309 "<previous_module>"
__cs_local_lfds711_stack_pop___cs_dowhile_onetime_1 = 0;

# 2310 "<previous_module>"
                                {
                                        
# 2311 "<previous_module>"
;
                                        ;
                                        
# 2312 "<previous_module>"
static _Bool __cs_local_lfds711_stack_pop___cs_tmp_if_cond_8;
                                        
# 2313 "<previous_module>"
__cs_local_lfds711_stack_pop___cs_tmp_if_cond_8 = __cs_local_lfds711_stack_pop_original_top[0] == 0;
                                        
# 2314 "<previous_module>"
if (__cs_local_lfds711_stack_pop___cs_tmp_if_cond_8)

# 2315 "<previous_module>"
                                        {
                                                
# 2316 "<previous_module>"
tpop_0_93: IF(2,93,tpop_0_94)__CSEQ_removeindent;
                                                
# 2317 "<previous_module>"
*__cs_param_lfds711_stack_pop_se = 0;
                                                
# 2318 "<previous_module>"
__cs_retval__lfds711_stack_pop_1 = 0;
                                                
# 2319 "<previous_module>"
goto __exit__lfds711_stack_pop_1_1;
                                                ;
                                        }

                                        
# 2321 "<previous_module>"
__CPROVER_assume(__cs_pc_cs[2] >= 94);
                                        ;
                                        
# 2322 "<previous_module>"
tpop_0_94: IF(2,94,tpop_0_95)__CSEQ_removeindent;
                                        
# 2323 "<previous_module>"
__cs_local_lfds711_stack_pop_new_top[1] = __cs_local_lfds711_stack_pop_original_top[1] + 1;
                                        
# 2324 "<previous_module>"
tpop_0_95: IF(2,95,tpop_0_96)__CSEQ_removeindent;
                                        
# 2325 "<previous_module>"
__cs_local_lfds711_stack_pop_new_top[0] = (*__cs_local_lfds711_stack_pop_original_top[0]).next;
                                        
# 2326 "<previous_module>"
tpop_0_96: IF(2,96,tpop_0_97)__CSEQ_removeindent;
                                        
# 2327 "<previous_module>"
__cs_mutex_lock(&library_lock, 2);
                                        
# 2328 "<previous_module>"
tpop_0_97: IF(2,97,tpop_0_98)__CSEQ_removeindent;
                                        
# 2329 "<previous_module>"
__cs_local_lfds711_stack_pop_result = __CSEQ_atomic_swap_stack_top(&(*__cs_param_lfds711_stack_pop_ss).top[0], &__cs_local_lfds711_stack_pop_original_top[0], &__cs_local_lfds711_stack_pop_new_top[0]);
                                        
# 2330 "<previous_module>"
tpop_0_98: IF(2,98,tpop_0_99)__CSEQ_removeindent;
                                        
# 2331 "<previous_module>"
__cs_mutex_unlock(&library_lock, 2);
                                        
# 2332 "<previous_module>"
;
                                        ;
                                        
# 2333 "<previous_module>"
static _Bool __cs_local_lfds711_stack_pop___cs_tmp_if_cond_9;
                                        
# 2334 "<previous_module>"
__cs_local_lfds711_stack_pop___cs_tmp_if_cond_9 = __cs_local_lfds711_stack_pop_result == 0;
                                        
# 2335 "<previous_module>"
if (__cs_local_lfds711_stack_pop___cs_tmp_if_cond_9)

# 2336 "<previous_module>"
                                        {

# 2337 "<previous_module>"
                                                {
                                                        
# 2338 "<previous_module>"
static int __cs_local_exponential_backoff_loop;
                                                        
# 2339 "<previous_module>"
__cs_local_exponential_backoff_loop = 0;

# 2340 "<previous_module>"
                                                        {
                                                                
# 2341 "<previous_module>"
;
                                                                ;
                                                        }
                                                        
# 2343 "<previous_module>"
;
                                                        
# 2344 "<previous_module>"
__cs_local_exponential_backoff_loop++;

# 2345 "<previous_module>"
                                                        {
                                                                
# 2346 "<previous_module>"
;
                                                                ;
                                                        }
                                                        
# 2348 "<previous_module>"
;
                                                        
# 2349 "<previous_module>"
__cs_local_exponential_backoff_loop++;

# 2350 "<previous_module>"
                                                        {
                                                                
# 2351 "<previous_module>"
;
                                                                ;
                                                        }
                                                        
# 2353 "<previous_module>"
;
                                                        
# 2354 "<previous_module>"
__cs_local_exponential_backoff_loop++;
                                                        
# 2355 "<previous_module>"
tpop_0_99: IF(2,99,tpop_0_100)__CSEQ_removeindent;
                                                        
# 2356 "<previous_module>"
__CPROVER_assume(!(__cs_local_exponential_backoff_loop < 3));
                                                        
# 2357 "<previous_module>"
__exit_loop_24:
                                                        __CPROVER_assume(__cs_pc_cs[2] >= 100);

                                                        
# 2358 "<previous_module>"
;
                                                        ;
                                                        
# 2359 "<previous_module>"
__exit__exponential_backoff_2_1:
                                                        __CPROVER_assume(__cs_pc_cs[2] >= 100);

                                                        
# 2360 "<previous_module>"
;
                                                        ;
                                                }
                                                
# 2362 "<previous_module>"
;
                                                
# 2363 "<previous_module>"
tpop_0_100: IF(2,100,tpop_0_101)__CSEQ_removeindent;
                                                
# 2364 "<previous_module>"
__cs_mutex_lock(&library_lock, 2);
                                                
# 2365 "<previous_module>"
tpop_0_101: IF(2,101,tpop_0_102)__CSEQ_removeindent;
                                                
# 2366 "<previous_module>"
__cs_mutex_unlock(&library_lock, 2);
                                        }

                                        
# 2368 "<previous_module>"
__CPROVER_assume(__cs_pc_cs[2] >= 102);
                                        ;
                                        
# 2369 "<previous_module>"
__cs_local_lfds711_stack_pop_i++;
                                        
# 2370 "<previous_module>"
;
                                        ;
                                        
# 2371 "<previous_module>"
static _Bool __cs_local_lfds711_stack_pop___cs_tmp_if_cond_10;
                                        
# 2372 "<previous_module>"
__cs_local_lfds711_stack_pop___cs_tmp_if_cond_10 = __cs_local_lfds711_stack_pop_i > 1000;
                                        
# 2373 "<previous_module>"
if (__cs_local_lfds711_stack_pop___cs_tmp_if_cond_10)

# 2374 "<previous_module>"
                                        {
                                                
# 2375 "<previous_module>"
goto __exit_loop_23;
                                                ;
                                        }

                                        
# 2377 "<previous_module>"
;
                                }
                                
# 2379 "<previous_module>"
;
                                
# 2380 "<previous_module>"
__cs_local_lfds711_stack_pop___cs_dowhile_onetime_1++;
                                
# 2381 "<previous_module>"
tpop_0_102: IF(2,102,tpop_0_103)__CSEQ_removeindent;
                                
# 2382 "<previous_module>"
__CPROVER_assume(!(__cs_local_lfds711_stack_pop___cs_dowhile_onetime_1 < 1));
                                
# 2383 "<previous_module>"
__exit_loop_23:
                                __CPROVER_assume(__cs_pc_cs[2] >= 103);

                                
# 2384 "<previous_module>"
;
                                ;
                                
# 2385 "<previous_module>"
if (
# 2386 "<previous_module>"
!(__cs_local_lfds711_stack_pop_result == 0))

# 2387 "<previous_module>"
                                {
                                        
# 2388 "<previous_module>"
goto __exit_loop_25;
                                        ;
                                }

                                
# 2390 "<previous_module>"
;

# 2391 "<previous_module>"
                                {
                                        
# 2392 "<previous_module>"
;
                                        ;
                                        
# 2393 "<previous_module>"
static _Bool __cs_local_lfds711_stack_pop___cs_tmp_if_cond_11;
                                        
# 2394 "<previous_module>"
__cs_local_lfds711_stack_pop___cs_tmp_if_cond_11 = __cs_local_lfds711_stack_pop_original_top[0] == 0;
                                        
# 2395 "<previous_module>"
if (__cs_local_lfds711_stack_pop___cs_tmp_if_cond_11)

# 2396 "<previous_module>"
                                        {
                                                
# 2397 "<previous_module>"
tpop_0_103: IF(2,103,tpop_0_104)__CSEQ_removeindent;
                                                
# 2398 "<previous_module>"
*__cs_param_lfds711_stack_pop_se = 0;
                                                
# 2399 "<previous_module>"
__cs_retval__lfds711_stack_pop_1 = 0;
                                                
# 2400 "<previous_module>"
goto __exit__lfds711_stack_pop_1_1;
                                                ;
                                        }

                                        
# 2402 "<previous_module>"
__CPROVER_assume(__cs_pc_cs[2] >= 104);
                                        ;
                                        
# 2403 "<previous_module>"
tpop_0_104: IF(2,104,tpop_0_105)__CSEQ_removeindent;
                                        
# 2404 "<previous_module>"
__cs_local_lfds711_stack_pop_new_top[1] = __cs_local_lfds711_stack_pop_original_top[1] + 1;
                                        
# 2405 "<previous_module>"
tpop_0_105: IF(2,105,tpop_0_106)__CSEQ_removeindent;
                                        
# 2406 "<previous_module>"
__cs_local_lfds711_stack_pop_new_top[0] = (*__cs_local_lfds711_stack_pop_original_top[0]).next;
                                        
# 2407 "<previous_module>"
tpop_0_106: IF(2,106,tpop_0_107)__CSEQ_removeindent;
                                        
# 2408 "<previous_module>"
__cs_mutex_lock(&library_lock, 2);
                                        
# 2409 "<previous_module>"
tpop_0_107: IF(2,107,tpop_0_108)__CSEQ_removeindent;
                                        
# 2410 "<previous_module>"
__cs_local_lfds711_stack_pop_result = __CSEQ_atomic_swap_stack_top(&(*__cs_param_lfds711_stack_pop_ss).top[0], &__cs_local_lfds711_stack_pop_original_top[0], &__cs_local_lfds711_stack_pop_new_top[0]);
                                        
# 2411 "<previous_module>"
tpop_0_108: IF(2,108,tpop_0_109)__CSEQ_removeindent;
                                        
# 2412 "<previous_module>"
__cs_mutex_unlock(&library_lock, 2);
                                        
# 2413 "<previous_module>"
;
                                        ;
                                        
# 2414 "<previous_module>"
static _Bool __cs_local_lfds711_stack_pop___cs_tmp_if_cond_12;
                                        
# 2415 "<previous_module>"
__cs_local_lfds711_stack_pop___cs_tmp_if_cond_12 = __cs_local_lfds711_stack_pop_result == 0;
                                        
# 2416 "<previous_module>"
if (__cs_local_lfds711_stack_pop___cs_tmp_if_cond_12)

# 2417 "<previous_module>"
                                        {

# 2418 "<previous_module>"
                                                {
                                                        
# 2419 "<previous_module>"
static int __cs_local_exponential_backoff_loop;
                                                        
# 2420 "<previous_module>"
__cs_local_exponential_backoff_loop = 0;

# 2421 "<previous_module>"
                                                        {
                                                                
# 2422 "<previous_module>"
;
                                                                ;
                                                        }
                                                        
# 2424 "<previous_module>"
;
                                                        
# 2425 "<previous_module>"
__cs_local_exponential_backoff_loop++;

# 2426 "<previous_module>"
                                                        {
                                                                
# 2427 "<previous_module>"
;
                                                                ;
                                                        }
                                                        
# 2429 "<previous_module>"
;
                                                        
# 2430 "<previous_module>"
__cs_local_exponential_backoff_loop++;

# 2431 "<previous_module>"
                                                        {
                                                                
# 2432 "<previous_module>"
;
                                                                ;
                                                        }
                                                        
# 2434 "<previous_module>"
;
                                                        
# 2435 "<previous_module>"
__cs_local_exponential_backoff_loop++;
                                                        
# 2436 "<previous_module>"
tpop_0_109: IF(2,109,tpop_0_110)__CSEQ_removeindent;
                                                        
# 2437 "<previous_module>"
__CPROVER_assume(!(__cs_local_exponential_backoff_loop < 3));
                                                        
# 2438 "<previous_module>"
__exit_loop_26:
                                                        __CPROVER_assume(__cs_pc_cs[2] >= 110);

                                                        
# 2439 "<previous_module>"
;
                                                        ;
                                                        
# 2440 "<previous_module>"
__exit__exponential_backoff_3_5:
                                                        __CPROVER_assume(__cs_pc_cs[2] >= 110);

                                                        
# 2441 "<previous_module>"
;
                                                        ;
                                                }
                                                
# 2443 "<previous_module>"
;
                                                
# 2444 "<previous_module>"
tpop_0_110: IF(2,110,tpop_0_111)__CSEQ_removeindent;
                                                
# 2445 "<previous_module>"
__cs_mutex_lock(&library_lock, 2);
                                                
# 2446 "<previous_module>"
tpop_0_111: IF(2,111,tpop_0_112)__CSEQ_removeindent;
                                                
# 2447 "<previous_module>"
__cs_mutex_unlock(&library_lock, 2);
                                        }

                                        
# 2449 "<previous_module>"
__CPROVER_assume(__cs_pc_cs[2] >= 112);
                                        ;
                                        
# 2450 "<previous_module>"
__cs_local_lfds711_stack_pop_i++;
                                        
# 2451 "<previous_module>"
;
                                        ;
                                        
# 2452 "<previous_module>"
static _Bool __cs_local_lfds711_stack_pop___cs_tmp_if_cond_13;
                                        
# 2453 "<previous_module>"
__cs_local_lfds711_stack_pop___cs_tmp_if_cond_13 = __cs_local_lfds711_stack_pop_i > 1000;
                                        
# 2454 "<previous_module>"
if (__cs_local_lfds711_stack_pop___cs_tmp_if_cond_13)

# 2455 "<previous_module>"
                                        {
                                                
# 2456 "<previous_module>"
goto __exit_loop_25;
                                                ;
                                        }

                                        
# 2458 "<previous_module>"
;
                                }
                                
# 2460 "<previous_module>"
;
                                
# 2461 "<previous_module>"
if (
# 2462 "<previous_module>"
!(__cs_local_lfds711_stack_pop_result == 0))

# 2463 "<previous_module>"
                                {
                                        
# 2464 "<previous_module>"
goto __exit_loop_25;
                                        ;
                                }

                                
# 2466 "<previous_module>"
;

# 2467 "<previous_module>"
                                {
                                        
# 2468 "<previous_module>"
;
                                        ;
                                        
# 2469 "<previous_module>"
static _Bool __cs_local_lfds711_stack_pop___cs_tmp_if_cond_11;
                                        
# 2470 "<previous_module>"
__cs_local_lfds711_stack_pop___cs_tmp_if_cond_11 = __cs_local_lfds711_stack_pop_original_top[0] == 0;
                                        
# 2471 "<previous_module>"
if (__cs_local_lfds711_stack_pop___cs_tmp_if_cond_11)

# 2472 "<previous_module>"
                                        {
                                                
# 2473 "<previous_module>"
tpop_0_112: IF(2,112,tpop_0_113)__CSEQ_removeindent;
                                                
# 2474 "<previous_module>"
*__cs_param_lfds711_stack_pop_se = 0;
                                                
# 2475 "<previous_module>"
__cs_retval__lfds711_stack_pop_1 = 0;
                                                
# 2476 "<previous_module>"
goto __exit__lfds711_stack_pop_1_1;
                                                ;
                                        }

                                        
# 2478 "<previous_module>"
__CPROVER_assume(__cs_pc_cs[2] >= 113);
                                        ;
                                        
# 2479 "<previous_module>"
tpop_0_113: IF(2,113,tpop_0_114)__CSEQ_removeindent;
                                        
# 2480 "<previous_module>"
__cs_local_lfds711_stack_pop_new_top[1] = __cs_local_lfds711_stack_pop_original_top[1] + 1;
                                        
# 2481 "<previous_module>"
tpop_0_114: IF(2,114,tpop_0_115)__CSEQ_removeindent;
                                        
# 2482 "<previous_module>"
__cs_local_lfds711_stack_pop_new_top[0] = (*__cs_local_lfds711_stack_pop_original_top[0]).next;
                                        
# 2483 "<previous_module>"
tpop_0_115: IF(2,115,tpop_0_116)__CSEQ_removeindent;
                                        
# 2484 "<previous_module>"
__cs_mutex_lock(&library_lock, 2);
                                        
# 2485 "<previous_module>"
tpop_0_116: IF(2,116,tpop_0_117)__CSEQ_removeindent;
                                        
# 2486 "<previous_module>"
__cs_local_lfds711_stack_pop_result = __CSEQ_atomic_swap_stack_top(&(*__cs_param_lfds711_stack_pop_ss).top[0], &__cs_local_lfds711_stack_pop_original_top[0], &__cs_local_lfds711_stack_pop_new_top[0]);
                                        
# 2487 "<previous_module>"
tpop_0_117: IF(2,117,tpop_0_118)__CSEQ_removeindent;
                                        
# 2488 "<previous_module>"
__cs_mutex_unlock(&library_lock, 2);
                                        
# 2489 "<previous_module>"
;
                                        ;
                                        
# 2490 "<previous_module>"
static _Bool __cs_local_lfds711_stack_pop___cs_tmp_if_cond_12;
                                        
# 2491 "<previous_module>"
__cs_local_lfds711_stack_pop___cs_tmp_if_cond_12 = __cs_local_lfds711_stack_pop_result == 0;
                                        
# 2492 "<previous_module>"
if (__cs_local_lfds711_stack_pop___cs_tmp_if_cond_12)

# 2493 "<previous_module>"
                                        {

# 2494 "<previous_module>"
                                                {
                                                        
# 2495 "<previous_module>"
static int __cs_local_exponential_backoff_loop;
                                                        
# 2496 "<previous_module>"
__cs_local_exponential_backoff_loop = 0;

# 2497 "<previous_module>"
                                                        {
                                                                
# 2498 "<previous_module>"
;
                                                                ;
                                                        }
                                                        
# 2500 "<previous_module>"
;
                                                        
# 2501 "<previous_module>"
__cs_local_exponential_backoff_loop++;

# 2502 "<previous_module>"
                                                        {
                                                                
# 2503 "<previous_module>"
;
                                                                ;
                                                        }
                                                        
# 2505 "<previous_module>"
;
                                                        
# 2506 "<previous_module>"
__cs_local_exponential_backoff_loop++;

# 2507 "<previous_module>"
                                                        {
                                                                
# 2508 "<previous_module>"
;
                                                                ;
                                                        }
                                                        
# 2510 "<previous_module>"
;
                                                        
# 2511 "<previous_module>"
__cs_local_exponential_backoff_loop++;
                                                        
# 2512 "<previous_module>"
tpop_0_118: IF(2,118,tpop_0_119)__CSEQ_removeindent;
                                                        
# 2513 "<previous_module>"
__CPROVER_assume(!(__cs_local_exponential_backoff_loop < 3));
                                                        
# 2514 "<previous_module>"
__exit_loop_27:
                                                        __CPROVER_assume(__cs_pc_cs[2] >= 119);

                                                        
# 2515 "<previous_module>"
;
                                                        ;
                                                        
# 2516 "<previous_module>"
__exit__exponential_backoff_3_6:
                                                        __CPROVER_assume(__cs_pc_cs[2] >= 119);

                                                        
# 2517 "<previous_module>"
;
                                                        ;
                                                }
                                                
# 2519 "<previous_module>"
;
                                                
# 2520 "<previous_module>"
tpop_0_119: IF(2,119,tpop_0_120)__CSEQ_removeindent;
                                                
# 2521 "<previous_module>"
__cs_mutex_lock(&library_lock, 2);
                                                
# 2522 "<previous_module>"
tpop_0_120: IF(2,120,tpop_0_121)__CSEQ_removeindent;
                                                
# 2523 "<previous_module>"
__cs_mutex_unlock(&library_lock, 2);
                                        }

                                        
# 2525 "<previous_module>"
__CPROVER_assume(__cs_pc_cs[2] >= 121);
                                        ;
                                        
# 2526 "<previous_module>"
__cs_local_lfds711_stack_pop_i++;
                                        
# 2527 "<previous_module>"
;
                                        ;
                                        
# 2528 "<previous_module>"
static _Bool __cs_local_lfds711_stack_pop___cs_tmp_if_cond_13;
                                        
# 2529 "<previous_module>"
__cs_local_lfds711_stack_pop___cs_tmp_if_cond_13 = __cs_local_lfds711_stack_pop_i > 1000;
                                        
# 2530 "<previous_module>"
if (__cs_local_lfds711_stack_pop___cs_tmp_if_cond_13)

# 2531 "<previous_module>"
                                        {
                                                
# 2532 "<previous_module>"
goto __exit_loop_25;
                                                ;
                                        }

                                        
# 2534 "<previous_module>"
;
                                }
                                
# 2536 "<previous_module>"
;
                                
# 2537 "<previous_module>"
if (
# 2538 "<previous_module>"
!(__cs_local_lfds711_stack_pop_result == 0))

# 2539 "<previous_module>"
                                {
                                        
# 2540 "<previous_module>"
goto __exit_loop_25;
                                        ;
                                }

                                
# 2542 "<previous_module>"
;

# 2543 "<previous_module>"
                                {
                                        
# 2544 "<previous_module>"
;
                                        ;
                                        
# 2545 "<previous_module>"
static _Bool __cs_local_lfds711_stack_pop___cs_tmp_if_cond_11;
                                        
# 2546 "<previous_module>"
__cs_local_lfds711_stack_pop___cs_tmp_if_cond_11 = __cs_local_lfds711_stack_pop_original_top[0] == 0;
                                        
# 2547 "<previous_module>"
if (__cs_local_lfds711_stack_pop___cs_tmp_if_cond_11)

# 2548 "<previous_module>"
                                        {
                                                
# 2549 "<previous_module>"
tpop_0_121: IF(2,121,tpop_0_122)__CSEQ_removeindent;
                                                
# 2550 "<previous_module>"
*__cs_param_lfds711_stack_pop_se = 0;
                                                
# 2551 "<previous_module>"
__cs_retval__lfds711_stack_pop_1 = 0;
                                                
# 2552 "<previous_module>"
goto __exit__lfds711_stack_pop_1_1;
                                                ;
                                        }

                                        
# 2554 "<previous_module>"
__CPROVER_assume(__cs_pc_cs[2] >= 122);
                                        ;
                                        
# 2555 "<previous_module>"
tpop_0_122: IF(2,122,tpop_0_123)__CSEQ_removeindent;
                                        
# 2556 "<previous_module>"
__cs_local_lfds711_stack_pop_new_top[1] = __cs_local_lfds711_stack_pop_original_top[1] + 1;
                                        
# 2557 "<previous_module>"
tpop_0_123: IF(2,123,tpop_0_124)__CSEQ_removeindent;
                                        
# 2558 "<previous_module>"
__cs_local_lfds711_stack_pop_new_top[0] = (*__cs_local_lfds711_stack_pop_original_top[0]).next;
                                        
# 2559 "<previous_module>"
tpop_0_124: IF(2,124,tpop_0_125)__CSEQ_removeindent;
                                        
# 2560 "<previous_module>"
__cs_mutex_lock(&library_lock, 2);
                                        
# 2561 "<previous_module>"
tpop_0_125: IF(2,125,tpop_0_126)__CSEQ_removeindent;
                                        
# 2562 "<previous_module>"
__cs_local_lfds711_stack_pop_result = __CSEQ_atomic_swap_stack_top(&(*__cs_param_lfds711_stack_pop_ss).top[0], &__cs_local_lfds711_stack_pop_original_top[0], &__cs_local_lfds711_stack_pop_new_top[0]);
                                        
# 2563 "<previous_module>"
tpop_0_126: IF(2,126,tpop_0_127)__CSEQ_removeindent;
                                        
# 2564 "<previous_module>"
__cs_mutex_unlock(&library_lock, 2);
                                        
# 2565 "<previous_module>"
;
                                        ;
                                        
# 2566 "<previous_module>"
static _Bool __cs_local_lfds711_stack_pop___cs_tmp_if_cond_12;
                                        
# 2567 "<previous_module>"
__cs_local_lfds711_stack_pop___cs_tmp_if_cond_12 = __cs_local_lfds711_stack_pop_result == 0;
                                        
# 2568 "<previous_module>"
if (__cs_local_lfds711_stack_pop___cs_tmp_if_cond_12)

# 2569 "<previous_module>"
                                        {

# 2570 "<previous_module>"
                                                {
                                                        
# 2571 "<previous_module>"
static int __cs_local_exponential_backoff_loop;
                                                        
# 2572 "<previous_module>"
__cs_local_exponential_backoff_loop = 0;

# 2573 "<previous_module>"
                                                        {
                                                                
# 2574 "<previous_module>"
;
                                                                ;
                                                        }
                                                        
# 2576 "<previous_module>"
;
                                                        
# 2577 "<previous_module>"
__cs_local_exponential_backoff_loop++;

# 2578 "<previous_module>"
                                                        {
                                                                
# 2579 "<previous_module>"
;
                                                                ;
                                                        }
                                                        
# 2581 "<previous_module>"
;
                                                        
# 2582 "<previous_module>"
__cs_local_exponential_backoff_loop++;

# 2583 "<previous_module>"
                                                        {
                                                                
# 2584 "<previous_module>"
;
                                                                ;
                                                        }
                                                        
# 2586 "<previous_module>"
;
                                                        
# 2587 "<previous_module>"
__cs_local_exponential_backoff_loop++;
                                                        
# 2588 "<previous_module>"
tpop_0_127: IF(2,127,tpop_0_128)__CSEQ_removeindent;
                                                        
# 2589 "<previous_module>"
__CPROVER_assume(!(__cs_local_exponential_backoff_loop < 3));
                                                        
# 2590 "<previous_module>"
__exit_loop_28:
                                                        __CPROVER_assume(__cs_pc_cs[2] >= 128);

                                                        
# 2591 "<previous_module>"
;
                                                        ;
                                                        
# 2592 "<previous_module>"
__exit__exponential_backoff_3_7:
                                                        __CPROVER_assume(__cs_pc_cs[2] >= 128);

                                                        
# 2593 "<previous_module>"
;
                                                        ;
                                                }
                                                
# 2595 "<previous_module>"
;
                                                
# 2596 "<previous_module>"
tpop_0_128: IF(2,128,tpop_0_129)__CSEQ_removeindent;
                                                
# 2597 "<previous_module>"
__cs_mutex_lock(&library_lock, 2);
                                                
# 2598 "<previous_module>"
tpop_0_129: IF(2,129,tpop_0_130)__CSEQ_removeindent;
                                                
# 2599 "<previous_module>"
__cs_mutex_unlock(&library_lock, 2);
                                        }

                                        
# 2601 "<previous_module>"
__CPROVER_assume(__cs_pc_cs[2] >= 130);
                                        ;
                                        
# 2602 "<previous_module>"
__cs_local_lfds711_stack_pop_i++;
                                        
# 2603 "<previous_module>"
;
                                        ;
                                        
# 2604 "<previous_module>"
static _Bool __cs_local_lfds711_stack_pop___cs_tmp_if_cond_13;
                                        
# 2605 "<previous_module>"
__cs_local_lfds711_stack_pop___cs_tmp_if_cond_13 = __cs_local_lfds711_stack_pop_i > 1000;
                                        
# 2606 "<previous_module>"
if (__cs_local_lfds711_stack_pop___cs_tmp_if_cond_13)

# 2607 "<previous_module>"
                                        {
                                                
# 2608 "<previous_module>"
goto __exit_loop_25;
                                                ;
                                        }

                                        
# 2610 "<previous_module>"
;
                                }
                                
# 2612 "<previous_module>"
;
                                
# 2613 "<previous_module>"
if (
# 2614 "<previous_module>"
!(__cs_local_lfds711_stack_pop_result == 0))

# 2615 "<previous_module>"
                                {
                                        
# 2616 "<previous_module>"
goto __exit_loop_25;
                                        ;
                                }

                                
# 2618 "<previous_module>"
;

# 2619 "<previous_module>"
                                {
                                        
# 2620 "<previous_module>"
;
                                        ;
                                        
# 2621 "<previous_module>"
static _Bool __cs_local_lfds711_stack_pop___cs_tmp_if_cond_11;
                                        
# 2622 "<previous_module>"
__cs_local_lfds711_stack_pop___cs_tmp_if_cond_11 = __cs_local_lfds711_stack_pop_original_top[0] == 0;
                                        
# 2623 "<previous_module>"
if (__cs_local_lfds711_stack_pop___cs_tmp_if_cond_11)

# 2624 "<previous_module>"
                                        {
                                                
# 2625 "<previous_module>"
tpop_0_130: IF(2,130,tpop_0_131)__CSEQ_removeindent;
                                                
# 2626 "<previous_module>"
*__cs_param_lfds711_stack_pop_se = 0;
                                                
# 2627 "<previous_module>"
__cs_retval__lfds711_stack_pop_1 = 0;
                                                
# 2628 "<previous_module>"
goto __exit__lfds711_stack_pop_1_1;
                                                ;
                                        }

                                        
# 2630 "<previous_module>"
__CPROVER_assume(__cs_pc_cs[2] >= 131);
                                        ;
                                        
# 2631 "<previous_module>"
tpop_0_131: IF(2,131,tpop_0_132)__CSEQ_removeindent;
                                        
# 2632 "<previous_module>"
__cs_local_lfds711_stack_pop_new_top[1] = __cs_local_lfds711_stack_pop_original_top[1] + 1;
                                        
# 2633 "<previous_module>"
tpop_0_132: IF(2,132,tpop_0_133)__CSEQ_removeindent;
                                        
# 2634 "<previous_module>"
__cs_local_lfds711_stack_pop_new_top[0] = (*__cs_local_lfds711_stack_pop_original_top[0]).next;
                                        
# 2635 "<previous_module>"
tpop_0_133: IF(2,133,tpop_0_134)__CSEQ_removeindent;
                                        
# 2636 "<previous_module>"
__cs_mutex_lock(&library_lock, 2);
                                        
# 2637 "<previous_module>"
tpop_0_134: IF(2,134,tpop_0_135)__CSEQ_removeindent;
                                        
# 2638 "<previous_module>"
__cs_local_lfds711_stack_pop_result = __CSEQ_atomic_swap_stack_top(&(*__cs_param_lfds711_stack_pop_ss).top[0], &__cs_local_lfds711_stack_pop_original_top[0], &__cs_local_lfds711_stack_pop_new_top[0]);
                                        
# 2639 "<previous_module>"
tpop_0_135: IF(2,135,tpop_0_136)__CSEQ_removeindent;
                                        
# 2640 "<previous_module>"
__cs_mutex_unlock(&library_lock, 2);
                                        
# 2641 "<previous_module>"
;
                                        ;
                                        
# 2642 "<previous_module>"
static _Bool __cs_local_lfds711_stack_pop___cs_tmp_if_cond_12;
                                        
# 2643 "<previous_module>"
__cs_local_lfds711_stack_pop___cs_tmp_if_cond_12 = __cs_local_lfds711_stack_pop_result == 0;
                                        
# 2644 "<previous_module>"
if (__cs_local_lfds711_stack_pop___cs_tmp_if_cond_12)

# 2645 "<previous_module>"
                                        {

# 2646 "<previous_module>"
                                                {
                                                        
# 2647 "<previous_module>"
static int __cs_local_exponential_backoff_loop;
                                                        
# 2648 "<previous_module>"
__cs_local_exponential_backoff_loop = 0;

# 2649 "<previous_module>"
                                                        {
                                                                
# 2650 "<previous_module>"
;
                                                                ;
                                                        }
                                                        
# 2652 "<previous_module>"
;
                                                        
# 2653 "<previous_module>"
__cs_local_exponential_backoff_loop++;

# 2654 "<previous_module>"
                                                        {
                                                                
# 2655 "<previous_module>"
;
                                                                ;
                                                        }
                                                        
# 2657 "<previous_module>"
;
                                                        
# 2658 "<previous_module>"
__cs_local_exponential_backoff_loop++;

# 2659 "<previous_module>"
                                                        {
                                                                
# 2660 "<previous_module>"
;
                                                                ;
                                                        }
                                                        
# 2662 "<previous_module>"
;
                                                        
# 2663 "<previous_module>"
__cs_local_exponential_backoff_loop++;
                                                        
# 2664 "<previous_module>"
tpop_0_136: IF(2,136,tpop_0_137)__CSEQ_removeindent;
                                                        
# 2665 "<previous_module>"
__CPROVER_assume(!(__cs_local_exponential_backoff_loop < 3));
                                                        
# 2666 "<previous_module>"
__exit_loop_29:
                                                        __CPROVER_assume(__cs_pc_cs[2] >= 137);

                                                        
# 2667 "<previous_module>"
;
                                                        ;
                                                        
# 2668 "<previous_module>"
__exit__exponential_backoff_3_8:
                                                        __CPROVER_assume(__cs_pc_cs[2] >= 137);

                                                        
# 2669 "<previous_module>"
;
                                                        ;
                                                }
                                                
# 2671 "<previous_module>"
;
                                                
# 2672 "<previous_module>"
tpop_0_137: IF(2,137,tpop_0_138)__CSEQ_removeindent;
                                                
# 2673 "<previous_module>"
__cs_mutex_lock(&library_lock, 2);
                                                
# 2674 "<previous_module>"
tpop_0_138: IF(2,138,tpop_0_139)__CSEQ_removeindent;
                                                
# 2675 "<previous_module>"
__cs_mutex_unlock(&library_lock, 2);
                                        }

                                        
# 2677 "<previous_module>"
__CPROVER_assume(__cs_pc_cs[2] >= 139);
                                        ;
                                        
# 2678 "<previous_module>"
__cs_local_lfds711_stack_pop_i++;
                                        
# 2679 "<previous_module>"
;
                                        ;
                                        
# 2680 "<previous_module>"
static _Bool __cs_local_lfds711_stack_pop___cs_tmp_if_cond_13;
                                        
# 2681 "<previous_module>"
__cs_local_lfds711_stack_pop___cs_tmp_if_cond_13 = __cs_local_lfds711_stack_pop_i > 1000;
                                        
# 2682 "<previous_module>"
if (__cs_local_lfds711_stack_pop___cs_tmp_if_cond_13)

# 2683 "<previous_module>"
                                        {
                                                
# 2684 "<previous_module>"
goto __exit_loop_25;
                                                ;
                                        }

                                        
# 2686 "<previous_module>"
;
                                }
                                
# 2688 "<previous_module>"
;
                                
# 2689 "<previous_module>"
if (
# 2690 "<previous_module>"
!(__cs_local_lfds711_stack_pop_result == 0))

# 2691 "<previous_module>"
                                {
                                        
# 2692 "<previous_module>"
goto __exit_loop_25;
                                        ;
                                }

                                
# 2694 "<previous_module>"
;

# 2695 "<previous_module>"
                                {
                                        
# 2696 "<previous_module>"
;
                                        ;
                                        
# 2697 "<previous_module>"
static _Bool __cs_local_lfds711_stack_pop___cs_tmp_if_cond_11;
                                        
# 2698 "<previous_module>"
__cs_local_lfds711_stack_pop___cs_tmp_if_cond_11 = __cs_local_lfds711_stack_pop_original_top[0] == 0;
                                        
# 2699 "<previous_module>"
if (__cs_local_lfds711_stack_pop___cs_tmp_if_cond_11)

# 2700 "<previous_module>"
                                        {
                                                
# 2701 "<previous_module>"
tpop_0_139: IF(2,139,tpop_0_140)__CSEQ_removeindent;
                                                
# 2702 "<previous_module>"
*__cs_param_lfds711_stack_pop_se = 0;
                                                
# 2703 "<previous_module>"
__cs_retval__lfds711_stack_pop_1 = 0;
                                                
# 2704 "<previous_module>"
goto __exit__lfds711_stack_pop_1_1;
                                                ;
                                        }

                                        
# 2706 "<previous_module>"
__CPROVER_assume(__cs_pc_cs[2] >= 140);
                                        ;
                                        
# 2707 "<previous_module>"
tpop_0_140: IF(2,140,tpop_0_141)__CSEQ_removeindent;
                                        
# 2708 "<previous_module>"
__cs_local_lfds711_stack_pop_new_top[1] = __cs_local_lfds711_stack_pop_original_top[1] + 1;
                                        
# 2709 "<previous_module>"
tpop_0_141: IF(2,141,tpop_0_142)__CSEQ_removeindent;
                                        
# 2710 "<previous_module>"
__cs_local_lfds711_stack_pop_new_top[0] = (*__cs_local_lfds711_stack_pop_original_top[0]).next;
                                        
# 2711 "<previous_module>"
tpop_0_142: IF(2,142,tpop_0_143)__CSEQ_removeindent;
                                        
# 2712 "<previous_module>"
__cs_mutex_lock(&library_lock, 2);
                                        
# 2713 "<previous_module>"
tpop_0_143: IF(2,143,tpop_0_144)__CSEQ_removeindent;
                                        
# 2714 "<previous_module>"
__cs_local_lfds711_stack_pop_result = __CSEQ_atomic_swap_stack_top(&(*__cs_param_lfds711_stack_pop_ss).top[0], &__cs_local_lfds711_stack_pop_original_top[0], &__cs_local_lfds711_stack_pop_new_top[0]);
                                        
# 2715 "<previous_module>"
tpop_0_144: IF(2,144,tpop_0_145)__CSEQ_removeindent;
                                        
# 2716 "<previous_module>"
__cs_mutex_unlock(&library_lock, 2);
                                        
# 2717 "<previous_module>"
;
                                        ;
                                        
# 2718 "<previous_module>"
static _Bool __cs_local_lfds711_stack_pop___cs_tmp_if_cond_12;
                                        
# 2719 "<previous_module>"
__cs_local_lfds711_stack_pop___cs_tmp_if_cond_12 = __cs_local_lfds711_stack_pop_result == 0;
                                        
# 2720 "<previous_module>"
if (__cs_local_lfds711_stack_pop___cs_tmp_if_cond_12)

# 2721 "<previous_module>"
                                        {

# 2722 "<previous_module>"
                                                {
                                                        
# 2723 "<previous_module>"
static int __cs_local_exponential_backoff_loop;
                                                        
# 2724 "<previous_module>"
__cs_local_exponential_backoff_loop = 0;

# 2725 "<previous_module>"
                                                        {
                                                                
# 2726 "<previous_module>"
;
                                                                ;
                                                        }
                                                        
# 2728 "<previous_module>"
;
                                                        
# 2729 "<previous_module>"
__cs_local_exponential_backoff_loop++;

# 2730 "<previous_module>"
                                                        {
                                                                
# 2731 "<previous_module>"
;
                                                                ;
                                                        }
                                                        
# 2733 "<previous_module>"
;
                                                        
# 2734 "<previous_module>"
__cs_local_exponential_backoff_loop++;

# 2735 "<previous_module>"
                                                        {
                                                                
# 2736 "<previous_module>"
;
                                                                ;
                                                        }
                                                        
# 2738 "<previous_module>"
;
                                                        
# 2739 "<previous_module>"
__cs_local_exponential_backoff_loop++;
                                                        
# 2740 "<previous_module>"
tpop_0_145: IF(2,145,tpop_0_146)__CSEQ_removeindent;
                                                        
# 2741 "<previous_module>"
__CPROVER_assume(!(__cs_local_exponential_backoff_loop < 3));
                                                        
# 2742 "<previous_module>"
__exit_loop_30:
                                                        __CPROVER_assume(__cs_pc_cs[2] >= 146);

                                                        
# 2743 "<previous_module>"
;
                                                        ;
                                                        
# 2744 "<previous_module>"
__exit__exponential_backoff_3_9:
                                                        __CPROVER_assume(__cs_pc_cs[2] >= 146);

                                                        
# 2745 "<previous_module>"
;
                                                        ;
                                                }
                                                
# 2747 "<previous_module>"
;
                                                
# 2748 "<previous_module>"
tpop_0_146: IF(2,146,tpop_0_147)__CSEQ_removeindent;
                                                
# 2749 "<previous_module>"
__cs_mutex_lock(&library_lock, 2);
                                                
# 2750 "<previous_module>"
tpop_0_147: IF(2,147,tpop_0_148)__CSEQ_removeindent;
                                                
# 2751 "<previous_module>"
__cs_mutex_unlock(&library_lock, 2);
                                        }

                                        
# 2753 "<previous_module>"
__CPROVER_assume(__cs_pc_cs[2] >= 148);
                                        ;
                                        
# 2754 "<previous_module>"
__cs_local_lfds711_stack_pop_i++;
                                        
# 2755 "<previous_module>"
;
                                        ;
                                        
# 2756 "<previous_module>"
static _Bool __cs_local_lfds711_stack_pop___cs_tmp_if_cond_13;
                                        
# 2757 "<previous_module>"
__cs_local_lfds711_stack_pop___cs_tmp_if_cond_13 = __cs_local_lfds711_stack_pop_i > 1000;
                                        
# 2758 "<previous_module>"
if (__cs_local_lfds711_stack_pop___cs_tmp_if_cond_13)

# 2759 "<previous_module>"
                                        {
                                                
# 2760 "<previous_module>"
goto __exit_loop_25;
                                                ;
                                        }

                                        
# 2762 "<previous_module>"
;
                                }
                                
# 2764 "<previous_module>"
;
                                
# 2765 "<previous_module>"
tpop_0_148: IF(2,148,tpop_0_149)__CSEQ_removeindent;
                                
# 2766 "<previous_module>"
__CPROVER_assume(
# 2767 "<previous_module>"
!(__cs_local_lfds711_stack_pop_result == 0));
                                
# 2768 "<previous_module>"
__exit_loop_25:
                                __CPROVER_assume(__cs_pc_cs[2] >= 149);

                                
# 2769 "<previous_module>"
;
                                ;
                                
# 2770 "<previous_module>"
tpop_0_149: IF(2,149,tpop_0_150)__CSEQ_removeindent;
                                
# 2771 "<previous_module>"
*__cs_param_lfds711_stack_pop_se = __cs_local_lfds711_stack_pop_original_top[0];
                                
# 2772 "<previous_module>"
__cs_retval__lfds711_stack_pop_1 = __cs_local_lfds711_stack_pop_result;
                                
# 2773 "<previous_module>"
goto __exit__lfds711_stack_pop_1_1;
                                ;
                                
# 2774 "<previous_module>"
__exit__lfds711_stack_pop_1_1:
                                __CPROVER_assume(__cs_pc_cs[2] >= 150);

                                
# 2775 "<previous_module>"
;
                                ;
                        }
                        
# 2777 "<previous_module>"
;
                        
# 2778 "<previous_module>"
__cs_local_delete_res = __cs_retval__lfds711_stack_pop_1;
                        
# 2779 "<previous_module>"
;
                        ;
                        
# 2780 "<previous_module>"
static _Bool __cs_local_delete___cs_tmp_if_cond_19;
                        
# 2781 "<previous_module>"
__cs_local_delete___cs_tmp_if_cond_19 = __cs_local_delete_res == 0;
                        
# 2782 "<previous_module>"
if (__cs_local_delete___cs_tmp_if_cond_19)

# 2783 "<previous_module>"
                        {
                                
# 2784 "<previous_module>"
__cs_retval__delete_1 = __cs_local_delete_res;
                                
# 2785 "<previous_module>"
goto __exit__delete_1_1;
                                ;
                        }

                        
# 2787 "<previous_module>"
;
                        
# 2788 "<previous_module>"
tpop_0_150: IF(2,150,tpop_0_151)__CSEQ_removeindent;
                        
# 2789 "<previous_module>"
__cs_local_delete_temp_td = (*__cs_local_delete_se).value;
                        
# 2790 "<previous_module>"
static int __cs_local_delete_id_popped;
                        
# 2791 "<previous_module>"
tpop_0_151: IF(2,151,tpop_0_152)__CSEQ_removeindent;
                        
# 2792 "<previous_module>"
__cs_local_delete_id_popped = (*__cs_local_delete_temp_td).user_id;
                        
# 2793 "<previous_module>"
tpop_0_152: IF(2,152,tpop_0_153)__CSEQ_removeindent;
                        
# 2794 "<previous_module>"
printf("%llu\n", (*__cs_local_delete_temp_td).user_id);
                        
# 2795 "<previous_module>"
__cs_retval__delete_1 = __cs_local_delete_res;
                        
# 2796 "<previous_module>"
goto __exit__delete_1_1;
                        ;
                        
# 2797 "<previous_module>"
__exit__delete_1_1:
                        __CPROVER_assume(__cs_pc_cs[2] >= 153);

                        
# 2798 "<previous_module>"
;
                        ;
                }
                
# 2800 "<previous_module>"
;
                
# 2801 "<previous_module>"
__cs_retval__delete_1;
                
# 2802 "<previous_module>"
;
                ;
                
# 2803 "<previous_module>"
static _Bool __cs_local_pop___cs_tmp_if_cond_27;
                
# 2804 "<previous_module>"
tpop_0_153: IF(2,153,tpop_0_154)__CSEQ_removeindent;
                
# 2805 "<previous_module>"
__cs_local_pop___cs_tmp_if_cond_27 = ATOMIC_OPERATION;
                
# 2806 "<previous_module>"
if (__cs_local_pop___cs_tmp_if_cond_27)

# 2807 "<previous_module>"
                {
                        
# 2808 "<previous_module>"
tpop_0_154: IF(2,154,tpop_0_155)__CSEQ_removeindent;
                        
# 2809 "<previous_module>"
__cs_mutex_unlock(&lock, 2);
                }

                
# 2811 "<previous_module>"
__CPROVER_assume(__cs_pc_cs[2] >= 155);
                ;
                
# 2812 "<previous_module>"
;
                ;
        }
        
# 2814 "<previous_module>"
;
        
# 2815 "<previous_module>"
__cs_local_pop_loop++;
        
# 2816 "<previous_module>"
tpop_0_155: IF(2,155,tpop_0_156)__CSEQ_removeindent;
        
# 2817 "<previous_module>"
__CPROVER_assume(!(__cs_local_pop_loop < 2));
        
# 2818 "<previous_module>"
__exit_loop_14:
        __CPROVER_assume(__cs_pc_cs[2] >= 156);

        
# 2819 "<previous_module>"
;
        ;
        
# 2820 "<previous_module>"
__exit_pop:
        __CPROVER_assume(__cs_pc_cs[2] >= 156);

        
# 2821 "<previous_module>"
;
        ;
        
# 2822 "<previous_module>"
tpop_0_156: __CSEQ_removeindent;
        
# 2823 "<previous_module>"
__cs_exit(0, 2);
}


# 2825 "<previous_module>"
int main_thread(void)

# 2826 "<previous_module>"
{
        
# 2827 "<previous_module>"
IF(0,0,tmain_1)__CSEQ_removeindent;
        
# 2828 "<previous_module>"
__cs_mutex_init(&lock, 0);
        
# 2829 "<previous_module>"
static void *__cs_retval__init_1;

# 2830 "<previous_module>"
        {

# 2831 "<previous_module>"
                {
                        
# 2832 "<previous_module>"
static struct lfds711_stack_state *__cs_param_lfds711_stack_init_valid_on_current_logical_core_ss;
                        
# 2833 "<previous_module>"
__cs_param_lfds711_stack_init_valid_on_current_logical_core_ss = &mystack;
                        
# 2834 "<previous_module>"
static void *__cs_param_lfds711_stack_init_valid_on_current_logical_core_user_state;
                        
# 2835 "<previous_module>"
__cs_param_lfds711_stack_init_valid_on_current_logical_core_user_state = 0;
                        
# 2836 "<previous_module>"
__cs_mutex_init(&library_lock, 0);
                        
# 2837 "<previous_module>"
;
                        ;
                        
# 2838 "<previous_module>"
static _Bool __cs_local_lfds711_stack_init_valid_on_current_logical_core___cs_tmp_if_cond_3;
                        
# 2839 "<previous_module>"
__cs_local_lfds711_stack_init_valid_on_current_logical_core___cs_tmp_if_cond_3 = !(__cs_param_lfds711_stack_init_valid_on_current_logical_core_ss != 0);
                        
# 2840 "<previous_module>"
if (__cs_local_lfds711_stack_init_valid_on_current_logical_core___cs_tmp_if_cond_3)

# 2841 "<previous_module>"
                        {
                                
# 2842 "<previous_module>"
static char *__cs_local_lfds711_stack_init_valid_on_current_logical_core_c;
                                
# 2843 "<previous_module>"
__cs_local_lfds711_stack_init_valid_on_current_logical_core_c = 0;
                                
# 2844 "<previous_module>"
*__cs_local_lfds711_stack_init_valid_on_current_logical_core_c = 0;
                        }

                        
# 2846 "<previous_module>"
;
                        
# 2847 "<previous_module>"
;
                        ;
                        
# 2848 "<previous_module>"
;
                        ;
                        
# 2849 "<previous_module>"
;
                        ;
                        
# 2850 "<previous_module>"
static _Bool __cs_local_lfds711_stack_init_valid_on_current_logical_core___cs_tmp_if_cond_4;
                        
# 2851 "<previous_module>"
__cs_local_lfds711_stack_init_valid_on_current_logical_core___cs_tmp_if_cond_4 = !((((lfds711_pal_uint_t) (*__cs_param_lfds711_stack_init_valid_on_current_logical_core_ss).top) % 128) == 0);
                        
# 2852 "<previous_module>"
if (__cs_local_lfds711_stack_init_valid_on_current_logical_core___cs_tmp_if_cond_4)

# 2853 "<previous_module>"
                        {
                                
# 2854 "<previous_module>"
static char *__cs_local_lfds711_stack_init_valid_on_current_logical_core_c;
                                
# 2855 "<previous_module>"
__cs_local_lfds711_stack_init_valid_on_current_logical_core_c = 0;
                                
# 2856 "<previous_module>"
*__cs_local_lfds711_stack_init_valid_on_current_logical_core_c = 0;
                        }

                        
# 2858 "<previous_module>"
;
                        
# 2859 "<previous_module>"
;
                        ;
                        
# 2860 "<previous_module>"
;
                        ;
                        
# 2861 "<previous_module>"
;
                        ;
                        
# 2862 "<previous_module>"
static _Bool __cs_local_lfds711_stack_init_valid_on_current_logical_core___cs_tmp_if_cond_5;
                        
# 2863 "<previous_module>"
__cs_local_lfds711_stack_init_valid_on_current_logical_core___cs_tmp_if_cond_5 = !((((lfds711_pal_uint_t) (&(*__cs_param_lfds711_stack_init_valid_on_current_logical_core_ss).user_state)) % 128) == 0);
                        
# 2864 "<previous_module>"
if (__cs_local_lfds711_stack_init_valid_on_current_logical_core___cs_tmp_if_cond_5)

# 2865 "<previous_module>"
                        {
                                
# 2866 "<previous_module>"
static char *__cs_local_lfds711_stack_init_valid_on_current_logical_core_c;
                                
# 2867 "<previous_module>"
__cs_local_lfds711_stack_init_valid_on_current_logical_core_c = 0;
                                
# 2868 "<previous_module>"
*__cs_local_lfds711_stack_init_valid_on_current_logical_core_c = 0;
                        }

                        
# 2870 "<previous_module>"
;
                        
# 2871 "<previous_module>"
;
                        ;
                        
# 2872 "<previous_module>"
;
                        ;
                        
# 2873 "<previous_module>"
__cs_mutex_lock(&library_lock, 0);
                        
# 2874 "<previous_module>"
(*__cs_param_lfds711_stack_init_valid_on_current_logical_core_ss).top[0] = 0;
                        
# 2875 "<previous_module>"
(*__cs_param_lfds711_stack_init_valid_on_current_logical_core_ss).top[1] = 0;
                        
# 2876 "<previous_module>"
(*__cs_param_lfds711_stack_init_valid_on_current_logical_core_ss).user_state = __cs_param_lfds711_stack_init_valid_on_current_logical_core_user_state;

# 2877 "<previous_module>"
                        {
                                
# 2878 "<previous_module>"
static struct lfds711_misc_backoff_state *__cs_param_lfds711_misc_internal_backoff_init_bs;
                                
# 2879 "<previous_module>"
__cs_param_lfds711_misc_internal_backoff_init_bs = &(*__cs_param_lfds711_stack_init_valid_on_current_logical_core_ss).pop_backoff;
                                
# 2880 "<previous_module>"
;
                                ;
                                
# 2881 "<previous_module>"
static _Bool __cs_local_lfds711_misc_internal_backoff_init___cs_tmp_if_cond_1;
                                
# 2882 "<previous_module>"
__cs_local_lfds711_misc_internal_backoff_init___cs_tmp_if_cond_1 = !(__cs_param_lfds711_misc_internal_backoff_init_bs != 0);
                                
# 2883 "<previous_module>"
if (__cs_local_lfds711_misc_internal_backoff_init___cs_tmp_if_cond_1)

# 2884 "<previous_module>"
                                {
                                        
# 2885 "<previous_module>"
static char *__cs_local_lfds711_misc_internal_backoff_init_c;
                                        
# 2886 "<previous_module>"
__cs_local_lfds711_misc_internal_backoff_init_c = 0;
                                        
# 2887 "<previous_module>"
*__cs_local_lfds711_misc_internal_backoff_init_c = 0;
                                }

                                
# 2889 "<previous_module>"
;
                                
# 2890 "<previous_module>"
;
                                ;
                                
# 2891 "<previous_module>"
;
                                ;
                                
# 2892 "<previous_module>"
;
                                ;
                                
# 2893 "<previous_module>"
static _Bool __cs_local_lfds711_misc_internal_backoff_init___cs_tmp_if_cond_2;
                                
# 2894 "<previous_module>"
__cs_local_lfds711_misc_internal_backoff_init___cs_tmp_if_cond_2 = !((((lfds711_pal_uint_t) (&(*__cs_param_lfds711_misc_internal_backoff_init_bs).lock)) % 128) == 0);
                                
# 2895 "<previous_module>"
if (__cs_local_lfds711_misc_internal_backoff_init___cs_tmp_if_cond_2)

# 2896 "<previous_module>"
                                {
                                        
# 2897 "<previous_module>"
static char *__cs_local_lfds711_misc_internal_backoff_init_c;
                                        
# 2898 "<previous_module>"
__cs_local_lfds711_misc_internal_backoff_init_c = 0;
                                        
# 2899 "<previous_module>"
*__cs_local_lfds711_misc_internal_backoff_init_c = 0;
                                }

                                
# 2901 "<previous_module>"
;
                                
# 2902 "<previous_module>"
;
                                ;
                                
# 2903 "<previous_module>"
;
                                ;
                                
# 2904 "<previous_module>"
(*__cs_param_lfds711_misc_internal_backoff_init_bs).lock = LFDS711_MISC_FLAG_LOWERED;
                                
# 2905 "<previous_module>"
(*__cs_param_lfds711_misc_internal_backoff_init_bs).backoff_iteration_frequency_counters[0] = 0;
                                
# 2906 "<previous_module>"
(*__cs_param_lfds711_misc_internal_backoff_init_bs).backoff_iteration_frequency_counters[1] = 0;
                                
# 2907 "<previous_module>"
(*__cs_param_lfds711_misc_internal_backoff_init_bs).metric = 1;
                                
# 2908 "<previous_module>"
(*__cs_param_lfds711_misc_internal_backoff_init_bs).total_operations = 0;
                                
# 2909 "<previous_module>"
goto __exit__lfds711_misc_internal_backoff_init_1;
                                ;
                                
# 2910 "<previous_module>"
__exit__lfds711_misc_internal_backoff_init_1:
                                __CPROVER_assume(__cs_pc_cs[0] >= 1);

                                
# 2911 "<previous_module>"
;
                                ;
                        }
                        
# 2913 "<previous_module>"
;

# 2914 "<previous_module>"
                        {
                                
# 2915 "<previous_module>"
static struct lfds711_misc_backoff_state *__cs_param_lfds711_misc_internal_backoff_init_bs;
                                
# 2916 "<previous_module>"
__cs_param_lfds711_misc_internal_backoff_init_bs = &(*__cs_param_lfds711_stack_init_valid_on_current_logical_core_ss).push_backoff;
                                
# 2917 "<previous_module>"
;
                                ;
                                
# 2918 "<previous_module>"
static _Bool __cs_local_lfds711_misc_internal_backoff_init___cs_tmp_if_cond_1;
                                
# 2919 "<previous_module>"
__cs_local_lfds711_misc_internal_backoff_init___cs_tmp_if_cond_1 = !(__cs_param_lfds711_misc_internal_backoff_init_bs != 0);
                                
# 2920 "<previous_module>"
if (__cs_local_lfds711_misc_internal_backoff_init___cs_tmp_if_cond_1)

# 2921 "<previous_module>"
                                {
                                        
# 2922 "<previous_module>"
static char *__cs_local_lfds711_misc_internal_backoff_init_c;
                                        
# 2923 "<previous_module>"
__cs_local_lfds711_misc_internal_backoff_init_c = 0;
                                        
# 2924 "<previous_module>"
*__cs_local_lfds711_misc_internal_backoff_init_c = 0;
                                }

                                
# 2926 "<previous_module>"
;
                                
# 2927 "<previous_module>"
;
                                ;
                                
# 2928 "<previous_module>"
;
                                ;
                                
# 2929 "<previous_module>"
;
                                ;
                                
# 2930 "<previous_module>"
static _Bool __cs_local_lfds711_misc_internal_backoff_init___cs_tmp_if_cond_2;
                                
# 2931 "<previous_module>"
__cs_local_lfds711_misc_internal_backoff_init___cs_tmp_if_cond_2 = !((((lfds711_pal_uint_t) (&(*__cs_param_lfds711_misc_internal_backoff_init_bs).lock)) % 128) == 0);
                                
# 2932 "<previous_module>"
if (__cs_local_lfds711_misc_internal_backoff_init___cs_tmp_if_cond_2)

# 2933 "<previous_module>"
                                {
                                        
# 2934 "<previous_module>"
static char *__cs_local_lfds711_misc_internal_backoff_init_c;
                                        
# 2935 "<previous_module>"
__cs_local_lfds711_misc_internal_backoff_init_c = 0;
                                        
# 2936 "<previous_module>"
*__cs_local_lfds711_misc_internal_backoff_init_c = 0;
                                }

                                
# 2938 "<previous_module>"
;
                                
# 2939 "<previous_module>"
;
                                ;
                                
# 2940 "<previous_module>"
;
                                ;
                                
# 2941 "<previous_module>"
(*__cs_param_lfds711_misc_internal_backoff_init_bs).lock = LFDS711_MISC_FLAG_LOWERED;
                                
# 2942 "<previous_module>"
(*__cs_param_lfds711_misc_internal_backoff_init_bs).backoff_iteration_frequency_counters[0] = 0;
                                
# 2943 "<previous_module>"
(*__cs_param_lfds711_misc_internal_backoff_init_bs).backoff_iteration_frequency_counters[1] = 0;
                                
# 2944 "<previous_module>"
(*__cs_param_lfds711_misc_internal_backoff_init_bs).metric = 1;
                                
# 2945 "<previous_module>"
(*__cs_param_lfds711_misc_internal_backoff_init_bs).total_operations = 0;
                                
# 2946 "<previous_module>"
goto __exit__lfds711_misc_internal_backoff_init_2;
                                ;
                                
# 2947 "<previous_module>"
__exit__lfds711_misc_internal_backoff_init_2:
                                __CPROVER_assume(__cs_pc_cs[0] >= 1);

                                
# 2948 "<previous_module>"
;
                                ;
                        }
                        
# 2950 "<previous_module>"
;

# 2951 "<previous_module>"
                        {
                                
# 2952 "<previous_module>"
static lfds711_pal_uint_t __cs_local_lfds711_misc_force_store_destination;
                                
# 2953 "<previous_module>"
__cs_init_scalar(&__cs_local_lfds711_misc_force_store_destination, sizeof(lfds711_pal_uint_t));

# 2954 "<previous_module>"
                                {
                                        
# 2955 "<previous_module>"
static unsigned long __cs_retval____atomic_exchange_n_1;

# 2956 "<previous_module>"
                                        {
                                                
# 2957 "<previous_module>"
static int long long unsigned *__cs_param___atomic_exchange_n_previous;
                                                
# 2958 "<previous_module>"
__cs_param___atomic_exchange_n_previous = &__cs_local_lfds711_misc_force_store_destination;
                                                
# 2959 "<previous_module>"
static int long long unsigned __cs_param___atomic_exchange_n_new;
                                                
# 2960 "<previous_module>"
__cs_param___atomic_exchange_n_new = 0;
                                                
# 2961 "<previous_module>"
static int __cs_param___atomic_exchange_n_memorder;
                                                
# 2962 "<previous_module>"
__cs_param___atomic_exchange_n_memorder = 0;
                                                
# 2963 "<previous_module>"
static int __cs_local___atomic_exchange_n_res;
                                                
# 2964 "<previous_module>"
__cs_local___atomic_exchange_n_res = __CSEQ_atomic_exchange(__cs_param___atomic_exchange_n_previous, __cs_param___atomic_exchange_n_new, __cs_param___atomic_exchange_n_memorder);
                                                
# 2965 "<previous_module>"
__cs_retval____atomic_exchange_n_1 = __cs_local___atomic_exchange_n_res;
                                                
# 2966 "<previous_module>"
goto __exit____atomic_exchange_n_1;
                                                ;
                                                
# 2967 "<previous_module>"
__exit____atomic_exchange_n_1:
                                                __CPROVER_assume(__cs_pc_cs[0] >= 1);

                                                
# 2968 "<previous_module>"
;
                                                ;
                                        }
                                        
# 2970 "<previous_module>"
;
                                        
# 2971 "<previous_module>"
(void) __cs_retval____atomic_exchange_n_1;
                                }
                                
# 2973 "<previous_module>"
;
                                
# 2974 "<previous_module>"
;
                                ;
                                
# 2975 "<previous_module>"
goto __exit__lfds711_misc_force_store_1;
                                ;
                                
# 2976 "<previous_module>"
__exit__lfds711_misc_force_store_1:
                                __CPROVER_assume(__cs_pc_cs[0] >= 1);

                                
# 2977 "<previous_module>"
;
                                ;
                        }
                        
# 2979 "<previous_module>"
;
                        
# 2980 "<previous_module>"
__cs_mutex_unlock(&library_lock, 0);
                        
# 2981 "<previous_module>"
goto __exit__lfds711_stack_init_valid_on_current_logical_core_1;
                        ;
                        
# 2982 "<previous_module>"
__exit__lfds711_stack_init_valid_on_current_logical_core_1:
                        __CPROVER_assume(__cs_pc_cs[0] >= 1);

                        
# 2983 "<previous_module>"
;
                        ;
                }
                
# 2985 "<previous_module>"
;
                
# 2986 "<previous_module>"
__cs_retval__init_1 = (void *) (&mystack);
                
# 2987 "<previous_module>"
goto __exit__init_1;
                ;
                
# 2988 "<previous_module>"
__exit__init_1:
                __CPROVER_assume(__cs_pc_cs[0] >= 1);

                
# 2989 "<previous_module>"
;
                ;
        }
        
# 2991 "<previous_module>"
;
        
# 2992 "<previous_module>"
ss = __cs_retval__init_1;
        
# 2993 "<previous_module>"
static __cs_t __cs_local_main_t1;
        
# 2994 "<previous_module>"
;
        ;
        
# 2995 "<previous_module>"
static __cs_t __cs_local_main_t2;
        
# 2996 "<previous_module>"
;
        ;
        
# 2997 "<previous_module>"
static __cs_t __cs_local_main_t3;
        
# 2998 "<previous_module>"
;
        ;
        
# 2999 "<previous_module>"
static __cs_t __cs_local_main_t4;
        
# 3000 "<previous_module>"
;
        ;
        
# 3001 "<previous_module>"
static __cs_t __cs_local_main_t5;
        
# 3002 "<previous_module>"
;
        ;
        
# 3003 "<previous_module>"
static __cs_t __cs_local_main_t6;
        
# 3004 "<previous_module>"
;
        ;
        
# 3005 "<previous_module>"
static __cs_t __cs_local_main_t7;
        
# 3006 "<previous_module>"
;
        ;
        
# 3007 "<previous_module>"
static __cs_t __cs_local_main_t8;
        
# 3008 "<previous_module>"
;
        ;
        
# 3009 "<previous_module>"
static __cs_t __cs_local_main_t9;
        
# 3010 "<previous_module>"
;
        ;
        
# 3011 "<previous_module>"
static __cs_t __cs_local_main_t10;
        
# 3012 "<previous_module>"
;
        ;
        
# 3013 "<previous_module>"
__cs_create(&__cs_local_main_t1, 0, push_0, 0, 1);
        
# 3014 "<previous_module>"
tmain_1: IF(0,1,tmain_2)__CSEQ_removeindent;
        
# 3015 "<previous_module>"
__cs_create(&__cs_local_main_t6, 0, pop_0, 0, 2);
        
# 3016 "<previous_module>"
tmain_2: IF(0,2,tmain_3)__CSEQ_removeindent;
        
# 3017 "<previous_module>"
__cs_join(__cs_local_main_t1, 0);
        
# 3018 "<previous_module>"
tmain_3: IF(0,3,tmain_4)__CSEQ_removeindent;
        
# 3019 "<previous_module>"
__cs_join(__cs_local_main_t6, 0);
        
# 3020 "<previous_module>"
static int __cs_retval__contains_1;

# 3021 "<previous_module>"
        {
                
# 3022 "<previous_module>"
static struct lfds711_stack_state *__cs_param_contains_s;
                
# 3023 "<previous_module>"
tmain_4: IF(0,4,tmain_5)__CSEQ_removeindent;
                
# 3024 "<previous_module>"
__cs_param_contains_s = ss;
                
# 3025 "<previous_module>"
static unsigned long long int __cs_param_contains_id;
                
# 3026 "<previous_module>"
__cs_param_contains_id = 0;
                
# 3027 "<previous_module>"
static int __cs_local_contains_max_size;
                
# 3028 "<previous_module>"
__cs_local_contains_max_size = 2;
                
# 3029 "<previous_module>"
static int __cs_local_contains_actual_size;
                
# 3030 "<previous_module>"
__cs_local_contains_actual_size = 0;
                
# 3031 "<previous_module>"
static int __cs_local_contains_res;
                
# 3032 "<previous_module>"
__cs_local_contains_res = 1;
                
# 3033 "<previous_module>"
static int __cs_local_contains_found;
                
# 3034 "<previous_module>"
__cs_local_contains_found = 0;
                
# 3035 "<previous_module>"
static int __cs_local_contains_dimension;
                
# 3036 "<previous_module>"
__cs_local_contains_dimension = 2;
                
# 3037 "<previous_module>"
static struct test_data **__cs_local_contains_datas;
                
# 3038 "<previous_module>"
tmain_5: IF(0,5,tmain_6)__CSEQ_removeindent;
                
# 3039 "<previous_module>"
__cs_local_contains_datas = __cs_safe_malloc((sizeof(struct test_data *)) * __cs_local_contains_max_size);
                
# 3040 "<previous_module>"
static struct lfds711_stack_element *__cs_local_contains_se;
                
# 3041 "<previous_module>"
if (!(__cs_local_contains_actual_size < 2))

# 3042 "<previous_module>"
                {
                        
# 3043 "<previous_module>"
goto __exit_loop_31;
                        ;
                }

                
# 3045 "<previous_module>"
;

# 3046 "<previous_module>"
                {
                        
# 3047 "<previous_module>"
static int __cs_retval__lfds711_stack_pop_2;

# 3048 "<previous_module>"
                        {
                                
# 3049 "<previous_module>"
static struct lfds711_stack_state *__cs_param_lfds711_stack_pop_ss;
                                
# 3050 "<previous_module>"
tmain_6: IF(0,6,tmain_7)__CSEQ_removeindent;
                                
# 3051 "<previous_module>"
__cs_param_lfds711_stack_pop_ss = __cs_param_contains_s;
                                
# 3052 "<previous_module>"
static struct lfds711_stack_element **__cs_param_lfds711_stack_pop_se;
                                
# 3053 "<previous_module>"
tmain_7: IF(0,7,tmain_8)__CSEQ_removeindent;
                                
# 3054 "<previous_module>"
__cs_param_lfds711_stack_pop_se = &__cs_local_contains_se;
                                
# 3055 "<previous_module>"
static char unsigned __cs_local_lfds711_stack_pop_result;
                                
# 3056 "<previous_module>"
static lfds711_pal_uint_t __cs_local_lfds711_stack_pop_backoff_iteration;
                                
# 3057 "<previous_module>"
__cs_local_lfds711_stack_pop_backoff_iteration = 0;
                                
# 3058 "<previous_module>"
static struct lfds711_stack_element *__cs_local_lfds711_stack_pop_new_top[2];
                                
# 3059 "<previous_module>"
static struct lfds711_stack_element * volatile __cs_local_lfds711_stack_pop_original_top[2];
                                
# 3060 "<previous_module>"
;
                                ;
                                
# 3061 "<previous_module>"
static _Bool __cs_local_lfds711_stack_pop___cs_tmp_if_cond_6;
                                
# 3062 "<previous_module>"
tmain_8: IF(0,8,tmain_9)__CSEQ_removeindent;
                                
# 3063 "<previous_module>"
__cs_local_lfds711_stack_pop___cs_tmp_if_cond_6 = !(__cs_param_lfds711_stack_pop_ss != 0);
                                
# 3064 "<previous_module>"
if (__cs_local_lfds711_stack_pop___cs_tmp_if_cond_6)

# 3065 "<previous_module>"
                                {
                                        
# 3066 "<previous_module>"
static char *__cs_local_lfds711_stack_pop_c;
                                        
# 3067 "<previous_module>"
tmain_9: IF(0,9,tmain_10)__CSEQ_removeindent;
                                        
# 3068 "<previous_module>"
__cs_local_lfds711_stack_pop_c = 0;
                                        
# 3069 "<previous_module>"
tmain_10: IF(0,10,tmain_11)__CSEQ_removeindent;
                                        
# 3070 "<previous_module>"
*__cs_local_lfds711_stack_pop_c = 0;
                                }

                                
# 3072 "<previous_module>"
__CPROVER_assume(__cs_pc_cs[0] >= 11);
                                ;
                                
# 3073 "<previous_module>"
;
                                ;
                                
# 3074 "<previous_module>"
;
                                ;
                                
# 3075 "<previous_module>"
;
                                ;
                                
# 3076 "<previous_module>"
static _Bool __cs_local_lfds711_stack_pop___cs_tmp_if_cond_7;
                                
# 3077 "<previous_module>"
tmain_11: IF(0,11,tmain_12)__CSEQ_removeindent;
                                
# 3078 "<previous_module>"
__cs_local_lfds711_stack_pop___cs_tmp_if_cond_7 = !(__cs_param_lfds711_stack_pop_se != 0);
                                
# 3079 "<previous_module>"
if (__cs_local_lfds711_stack_pop___cs_tmp_if_cond_7)

# 3080 "<previous_module>"
                                {
                                        
# 3081 "<previous_module>"
static char *__cs_local_lfds711_stack_pop_c;
                                        
# 3082 "<previous_module>"
tmain_12: IF(0,12,tmain_13)__CSEQ_removeindent;
                                        
# 3083 "<previous_module>"
__cs_local_lfds711_stack_pop_c = 0;
                                        
# 3084 "<previous_module>"
tmain_13: IF(0,13,tmain_14)__CSEQ_removeindent;
                                        
# 3085 "<previous_module>"
*__cs_local_lfds711_stack_pop_c = 0;
                                }

                                
# 3087 "<previous_module>"
__CPROVER_assume(__cs_pc_cs[0] >= 14);
                                ;
                                
# 3088 "<previous_module>"
;
                                ;
                                
# 3089 "<previous_module>"
;
                                ;
                                
# 3090 "<previous_module>"
tmain_14: IF(0,14,tmain_15)__CSEQ_removeindent;
                                
# 3091 "<previous_module>"
__cs_mutex_lock(&library_lock, 0);
                                
# 3092 "<previous_module>"
tmain_15: IF(0,15,tmain_16)__CSEQ_removeindent;
                                
# 3093 "<previous_module>"
__cs_mutex_unlock(&library_lock, 0);
                                
# 3094 "<previous_module>"
tmain_16: IF(0,16,tmain_17)__CSEQ_removeindent;
                                
# 3095 "<previous_module>"
__cs_local_lfds711_stack_pop_original_top[1] = (*__cs_param_lfds711_stack_pop_ss).top[1];
                                
# 3096 "<previous_module>"
tmain_17: IF(0,17,tmain_18)__CSEQ_removeindent;
                                
# 3097 "<previous_module>"
__cs_local_lfds711_stack_pop_original_top[0] = (*__cs_param_lfds711_stack_pop_ss).top[0];
                                
# 3098 "<previous_module>"
static int __cs_local_lfds711_stack_pop_i;
                                
# 3099 "<previous_module>"
__cs_local_lfds711_stack_pop_i = 0;
                                
# 3100 "<previous_module>"
;
                                ;
                                
# 3101 "<previous_module>"
static int __cs_local_lfds711_stack_pop___cs_dowhile_onetime_1;
                                
# 3102 "<previous_module>"
__cs_local_lfds711_stack_pop___cs_dowhile_onetime_1 = 0;

# 3103 "<previous_module>"
                                {
                                        
# 3104 "<previous_module>"
;
                                        ;
                                        
# 3105 "<previous_module>"
static _Bool __cs_local_lfds711_stack_pop___cs_tmp_if_cond_8;
                                        
# 3106 "<previous_module>"
__cs_local_lfds711_stack_pop___cs_tmp_if_cond_8 = __cs_local_lfds711_stack_pop_original_top[0] == 0;
                                        
# 3107 "<previous_module>"
if (__cs_local_lfds711_stack_pop___cs_tmp_if_cond_8)

# 3108 "<previous_module>"
                                        {
                                                
# 3109 "<previous_module>"
tmain_18: IF(0,18,tmain_19)__CSEQ_removeindent;
                                                
# 3110 "<previous_module>"
*__cs_param_lfds711_stack_pop_se = 0;
                                                
# 3111 "<previous_module>"
__cs_retval__lfds711_stack_pop_2 = 0;
                                                
# 3112 "<previous_module>"
goto __exit__lfds711_stack_pop_2_0;
                                                ;
                                        }

                                        
# 3114 "<previous_module>"
__CPROVER_assume(__cs_pc_cs[0] >= 19);
                                        ;
                                        
# 3115 "<previous_module>"
tmain_19: IF(0,19,tmain_20)__CSEQ_removeindent;
                                        
# 3116 "<previous_module>"
__cs_local_lfds711_stack_pop_new_top[1] = __cs_local_lfds711_stack_pop_original_top[1] + 1;
                                        
# 3117 "<previous_module>"
tmain_20: IF(0,20,tmain_21)__CSEQ_removeindent;
                                        
# 3118 "<previous_module>"
__cs_local_lfds711_stack_pop_new_top[0] = (*__cs_local_lfds711_stack_pop_original_top[0]).next;
                                        
# 3119 "<previous_module>"
tmain_21: IF(0,21,tmain_22)__CSEQ_removeindent;
                                        
# 3120 "<previous_module>"
__cs_mutex_lock(&library_lock, 0);
                                        
# 3121 "<previous_module>"
tmain_22: IF(0,22,tmain_23)__CSEQ_removeindent;
                                        
# 3122 "<previous_module>"
__cs_local_lfds711_stack_pop_result = __CSEQ_atomic_swap_stack_top(&(*__cs_param_lfds711_stack_pop_ss).top[0], &__cs_local_lfds711_stack_pop_original_top[0], &__cs_local_lfds711_stack_pop_new_top[0]);
                                        
# 3123 "<previous_module>"
tmain_23: IF(0,23,tmain_24)__CSEQ_removeindent;
                                        
# 3124 "<previous_module>"
__cs_mutex_unlock(&library_lock, 0);
                                        
# 3125 "<previous_module>"
;
                                        ;
                                        
# 3126 "<previous_module>"
static _Bool __cs_local_lfds711_stack_pop___cs_tmp_if_cond_9;
                                        
# 3127 "<previous_module>"
__cs_local_lfds711_stack_pop___cs_tmp_if_cond_9 = __cs_local_lfds711_stack_pop_result == 0;
                                        
# 3128 "<previous_module>"
if (__cs_local_lfds711_stack_pop___cs_tmp_if_cond_9)

# 3129 "<previous_module>"
                                        {

# 3130 "<previous_module>"
                                                {
                                                        
# 3131 "<previous_module>"
static int __cs_local_exponential_backoff_loop;
                                                        
# 3132 "<previous_module>"
__cs_local_exponential_backoff_loop = 0;

# 3133 "<previous_module>"
                                                        {
                                                                
# 3134 "<previous_module>"
;
                                                                ;
                                                        }
                                                        
# 3136 "<previous_module>"
;
                                                        
# 3137 "<previous_module>"
__cs_local_exponential_backoff_loop++;

# 3138 "<previous_module>"
                                                        {
                                                                
# 3139 "<previous_module>"
;
                                                                ;
                                                        }
                                                        
# 3141 "<previous_module>"
;
                                                        
# 3142 "<previous_module>"
__cs_local_exponential_backoff_loop++;

# 3143 "<previous_module>"
                                                        {
                                                                
# 3144 "<previous_module>"
;
                                                                ;
                                                        }
                                                        
# 3146 "<previous_module>"
;
                                                        
# 3147 "<previous_module>"
__cs_local_exponential_backoff_loop++;
                                                        
# 3148 "<previous_module>"
tmain_24: IF(0,24,tmain_25)__CSEQ_removeindent;
                                                        
# 3149 "<previous_module>"
__CPROVER_assume(!(__cs_local_exponential_backoff_loop < 3));
                                                        
# 3150 "<previous_module>"
__exit_loop_33:
                                                        __CPROVER_assume(__cs_pc_cs[0] >= 25);

                                                        
# 3151 "<previous_module>"
;
                                                        ;
                                                        
# 3152 "<previous_module>"
__exit__exponential_backoff_4_0:
                                                        __CPROVER_assume(__cs_pc_cs[0] >= 25);

                                                        
# 3153 "<previous_module>"
;
                                                        ;
                                                }
                                                
# 3155 "<previous_module>"
;
                                                
# 3156 "<previous_module>"
tmain_25: IF(0,25,tmain_26)__CSEQ_removeindent;
                                                
# 3157 "<previous_module>"
__cs_mutex_lock(&library_lock, 0);
                                                
# 3158 "<previous_module>"
tmain_26: IF(0,26,tmain_27)__CSEQ_removeindent;
                                                
# 3159 "<previous_module>"
__cs_mutex_unlock(&library_lock, 0);
                                        }

                                        
# 3161 "<previous_module>"
__CPROVER_assume(__cs_pc_cs[0] >= 27);
                                        ;
                                        
# 3162 "<previous_module>"
__cs_local_lfds711_stack_pop_i++;
                                        
# 3163 "<previous_module>"
;
                                        ;
                                        
# 3164 "<previous_module>"
static _Bool __cs_local_lfds711_stack_pop___cs_tmp_if_cond_10;
                                        
# 3165 "<previous_module>"
__cs_local_lfds711_stack_pop___cs_tmp_if_cond_10 = __cs_local_lfds711_stack_pop_i > 1000;
                                        
# 3166 "<previous_module>"
if (__cs_local_lfds711_stack_pop___cs_tmp_if_cond_10)

# 3167 "<previous_module>"
                                        {
                                                
# 3168 "<previous_module>"
goto __exit_loop_32;
                                                ;
                                        }

                                        
# 3170 "<previous_module>"
;
                                }
                                
# 3172 "<previous_module>"
;
                                
# 3173 "<previous_module>"
__cs_local_lfds711_stack_pop___cs_dowhile_onetime_1++;
                                
# 3174 "<previous_module>"
tmain_27: IF(0,27,tmain_28)__CSEQ_removeindent;
                                
# 3175 "<previous_module>"
__CPROVER_assume(!(__cs_local_lfds711_stack_pop___cs_dowhile_onetime_1 < 1));
                                
# 3176 "<previous_module>"
__exit_loop_32:
                                __CPROVER_assume(__cs_pc_cs[0] >= 28);

                                
# 3177 "<previous_module>"
;
                                ;
                                
# 3178 "<previous_module>"
if (
# 3179 "<previous_module>"
!(__cs_local_lfds711_stack_pop_result == 0))

# 3180 "<previous_module>"
                                {
                                        
# 3181 "<previous_module>"
goto __exit_loop_34;
                                        ;
                                }

                                
# 3183 "<previous_module>"
;

# 3184 "<previous_module>"
                                {
                                        
# 3185 "<previous_module>"
;
                                        ;
                                        
# 3186 "<previous_module>"
static _Bool __cs_local_lfds711_stack_pop___cs_tmp_if_cond_11;
                                        
# 3187 "<previous_module>"
__cs_local_lfds711_stack_pop___cs_tmp_if_cond_11 = __cs_local_lfds711_stack_pop_original_top[0] == 0;
                                        
# 3188 "<previous_module>"
if (__cs_local_lfds711_stack_pop___cs_tmp_if_cond_11)

# 3189 "<previous_module>"
                                        {
                                                
# 3190 "<previous_module>"
tmain_28: IF(0,28,tmain_29)__CSEQ_removeindent;
                                                
# 3191 "<previous_module>"
*__cs_param_lfds711_stack_pop_se = 0;
                                                
# 3192 "<previous_module>"
__cs_retval__lfds711_stack_pop_2 = 0;
                                                
# 3193 "<previous_module>"
goto __exit__lfds711_stack_pop_2_0;
                                                ;
                                        }

                                        
# 3195 "<previous_module>"
__CPROVER_assume(__cs_pc_cs[0] >= 29);
                                        ;
                                        
# 3196 "<previous_module>"
tmain_29: IF(0,29,tmain_30)__CSEQ_removeindent;
                                        
# 3197 "<previous_module>"
__cs_local_lfds711_stack_pop_new_top[1] = __cs_local_lfds711_stack_pop_original_top[1] + 1;
                                        
# 3198 "<previous_module>"
tmain_30: IF(0,30,tmain_31)__CSEQ_removeindent;
                                        
# 3199 "<previous_module>"
__cs_local_lfds711_stack_pop_new_top[0] = (*__cs_local_lfds711_stack_pop_original_top[0]).next;
                                        
# 3200 "<previous_module>"
tmain_31: IF(0,31,tmain_32)__CSEQ_removeindent;
                                        
# 3201 "<previous_module>"
__cs_mutex_lock(&library_lock, 0);
                                        
# 3202 "<previous_module>"
tmain_32: IF(0,32,tmain_33)__CSEQ_removeindent;
                                        
# 3203 "<previous_module>"
__cs_local_lfds711_stack_pop_result = __CSEQ_atomic_swap_stack_top(&(*__cs_param_lfds711_stack_pop_ss).top[0], &__cs_local_lfds711_stack_pop_original_top[0], &__cs_local_lfds711_stack_pop_new_top[0]);
                                        
# 3204 "<previous_module>"
tmain_33: IF(0,33,tmain_34)__CSEQ_removeindent;
                                        
# 3205 "<previous_module>"
__cs_mutex_unlock(&library_lock, 0);
                                        
# 3206 "<previous_module>"
;
                                        ;
                                        
# 3207 "<previous_module>"
static _Bool __cs_local_lfds711_stack_pop___cs_tmp_if_cond_12;
                                        
# 3208 "<previous_module>"
__cs_local_lfds711_stack_pop___cs_tmp_if_cond_12 = __cs_local_lfds711_stack_pop_result == 0;
                                        
# 3209 "<previous_module>"
if (__cs_local_lfds711_stack_pop___cs_tmp_if_cond_12)

# 3210 "<previous_module>"
                                        {

# 3211 "<previous_module>"
                                                {
                                                        
# 3212 "<previous_module>"
static int __cs_local_exponential_backoff_loop;
                                                        
# 3213 "<previous_module>"
__cs_local_exponential_backoff_loop = 0;

# 3214 "<previous_module>"
                                                        {
                                                                
# 3215 "<previous_module>"
;
                                                                ;
                                                        }
                                                        
# 3217 "<previous_module>"
;
                                                        
# 3218 "<previous_module>"
__cs_local_exponential_backoff_loop++;

# 3219 "<previous_module>"
                                                        {
                                                                
# 3220 "<previous_module>"
;
                                                                ;
                                                        }
                                                        
# 3222 "<previous_module>"
;
                                                        
# 3223 "<previous_module>"
__cs_local_exponential_backoff_loop++;

# 3224 "<previous_module>"
                                                        {
                                                                
# 3225 "<previous_module>"
;
                                                                ;
                                                        }
                                                        
# 3227 "<previous_module>"
;
                                                        
# 3228 "<previous_module>"
__cs_local_exponential_backoff_loop++;
                                                        
# 3229 "<previous_module>"
tmain_34: IF(0,34,tmain_35)__CSEQ_removeindent;
                                                        
# 3230 "<previous_module>"
__CPROVER_assume(!(__cs_local_exponential_backoff_loop < 3));
                                                        
# 3231 "<previous_module>"
__exit_loop_35:
                                                        __CPROVER_assume(__cs_pc_cs[0] >= 35);

                                                        
# 3232 "<previous_module>"
;
                                                        ;
                                                        
# 3233 "<previous_module>"
__exit__exponential_backoff_5_0:
                                                        __CPROVER_assume(__cs_pc_cs[0] >= 35);

                                                        
# 3234 "<previous_module>"
;
                                                        ;
                                                }
                                                
# 3236 "<previous_module>"
;
                                                
# 3237 "<previous_module>"
tmain_35: IF(0,35,tmain_36)__CSEQ_removeindent;
                                                
# 3238 "<previous_module>"
__cs_mutex_lock(&library_lock, 0);
                                                
# 3239 "<previous_module>"
tmain_36: IF(0,36,tmain_37)__CSEQ_removeindent;
                                                
# 3240 "<previous_module>"
__cs_mutex_unlock(&library_lock, 0);
                                        }

                                        
# 3242 "<previous_module>"
__CPROVER_assume(__cs_pc_cs[0] >= 37);
                                        ;
                                        
# 3243 "<previous_module>"
__cs_local_lfds711_stack_pop_i++;
                                        
# 3244 "<previous_module>"
;
                                        ;
                                        
# 3245 "<previous_module>"
static _Bool __cs_local_lfds711_stack_pop___cs_tmp_if_cond_13;
                                        
# 3246 "<previous_module>"
__cs_local_lfds711_stack_pop___cs_tmp_if_cond_13 = __cs_local_lfds711_stack_pop_i > 1000;
                                        
# 3247 "<previous_module>"
if (__cs_local_lfds711_stack_pop___cs_tmp_if_cond_13)

# 3248 "<previous_module>"
                                        {
                                                
# 3249 "<previous_module>"
goto __exit_loop_34;
                                                ;
                                        }

                                        
# 3251 "<previous_module>"
;
                                }
                                
# 3253 "<previous_module>"
;
                                
# 3254 "<previous_module>"
if (
# 3255 "<previous_module>"
!(__cs_local_lfds711_stack_pop_result == 0))

# 3256 "<previous_module>"
                                {
                                        
# 3257 "<previous_module>"
goto __exit_loop_34;
                                        ;
                                }

                                
# 3259 "<previous_module>"
;

# 3260 "<previous_module>"
                                {
                                        
# 3261 "<previous_module>"
;
                                        ;
                                        
# 3262 "<previous_module>"
static _Bool __cs_local_lfds711_stack_pop___cs_tmp_if_cond_11;
                                        
# 3263 "<previous_module>"
__cs_local_lfds711_stack_pop___cs_tmp_if_cond_11 = __cs_local_lfds711_stack_pop_original_top[0] == 0;
                                        
# 3264 "<previous_module>"
if (__cs_local_lfds711_stack_pop___cs_tmp_if_cond_11)

# 3265 "<previous_module>"
                                        {
                                                
# 3266 "<previous_module>"
tmain_37: IF(0,37,tmain_38)__CSEQ_removeindent;
                                                
# 3267 "<previous_module>"
*__cs_param_lfds711_stack_pop_se = 0;
                                                
# 3268 "<previous_module>"
__cs_retval__lfds711_stack_pop_2 = 0;
                                                
# 3269 "<previous_module>"
goto __exit__lfds711_stack_pop_2_0;
                                                ;
                                        }

                                        
# 3271 "<previous_module>"
__CPROVER_assume(__cs_pc_cs[0] >= 38);
                                        ;
                                        
# 3272 "<previous_module>"
tmain_38: IF(0,38,tmain_39)__CSEQ_removeindent;
                                        
# 3273 "<previous_module>"
__cs_local_lfds711_stack_pop_new_top[1] = __cs_local_lfds711_stack_pop_original_top[1] + 1;
                                        
# 3274 "<previous_module>"
tmain_39: IF(0,39,tmain_40)__CSEQ_removeindent;
                                        
# 3275 "<previous_module>"
__cs_local_lfds711_stack_pop_new_top[0] = (*__cs_local_lfds711_stack_pop_original_top[0]).next;
                                        
# 3276 "<previous_module>"
tmain_40: IF(0,40,tmain_41)__CSEQ_removeindent;
                                        
# 3277 "<previous_module>"
__cs_mutex_lock(&library_lock, 0);
                                        
# 3278 "<previous_module>"
tmain_41: IF(0,41,tmain_42)__CSEQ_removeindent;
                                        
# 3279 "<previous_module>"
__cs_local_lfds711_stack_pop_result = __CSEQ_atomic_swap_stack_top(&(*__cs_param_lfds711_stack_pop_ss).top[0], &__cs_local_lfds711_stack_pop_original_top[0], &__cs_local_lfds711_stack_pop_new_top[0]);
                                        
# 3280 "<previous_module>"
tmain_42: IF(0,42,tmain_43)__CSEQ_removeindent;
                                        
# 3281 "<previous_module>"
__cs_mutex_unlock(&library_lock, 0);
                                        
# 3282 "<previous_module>"
;
                                        ;
                                        
# 3283 "<previous_module>"
static _Bool __cs_local_lfds711_stack_pop___cs_tmp_if_cond_12;
                                        
# 3284 "<previous_module>"
__cs_local_lfds711_stack_pop___cs_tmp_if_cond_12 = __cs_local_lfds711_stack_pop_result == 0;
                                        
# 3285 "<previous_module>"
if (__cs_local_lfds711_stack_pop___cs_tmp_if_cond_12)

# 3286 "<previous_module>"
                                        {

# 3287 "<previous_module>"
                                                {
                                                        
# 3288 "<previous_module>"
static int __cs_local_exponential_backoff_loop;
                                                        
# 3289 "<previous_module>"
__cs_local_exponential_backoff_loop = 0;

# 3290 "<previous_module>"
                                                        {
                                                                
# 3291 "<previous_module>"
;
                                                                ;
                                                        }
                                                        
# 3293 "<previous_module>"
;
                                                        
# 3294 "<previous_module>"
__cs_local_exponential_backoff_loop++;

# 3295 "<previous_module>"
                                                        {
                                                                
# 3296 "<previous_module>"
;
                                                                ;
                                                        }
                                                        
# 3298 "<previous_module>"
;
                                                        
# 3299 "<previous_module>"
__cs_local_exponential_backoff_loop++;

# 3300 "<previous_module>"
                                                        {
                                                                
# 3301 "<previous_module>"
;
                                                                ;
                                                        }
                                                        
# 3303 "<previous_module>"
;
                                                        
# 3304 "<previous_module>"
__cs_local_exponential_backoff_loop++;
                                                        
# 3305 "<previous_module>"
tmain_43: IF(0,43,tmain_44)__CSEQ_removeindent;
                                                        
# 3306 "<previous_module>"
__CPROVER_assume(!(__cs_local_exponential_backoff_loop < 3));
                                                        
# 3307 "<previous_module>"
__exit_loop_36:
                                                        __CPROVER_assume(__cs_pc_cs[0] >= 44);

                                                        
# 3308 "<previous_module>"
;
                                                        ;
                                                        
# 3309 "<previous_module>"
__exit__exponential_backoff_5_1:
                                                        __CPROVER_assume(__cs_pc_cs[0] >= 44);

                                                        
# 3310 "<previous_module>"
;
                                                        ;
                                                }
                                                
# 3312 "<previous_module>"
;
                                                
# 3313 "<previous_module>"
tmain_44: IF(0,44,tmain_45)__CSEQ_removeindent;
                                                
# 3314 "<previous_module>"
__cs_mutex_lock(&library_lock, 0);
                                                
# 3315 "<previous_module>"
tmain_45: IF(0,45,tmain_46)__CSEQ_removeindent;
                                                
# 3316 "<previous_module>"
__cs_mutex_unlock(&library_lock, 0);
                                        }

                                        
# 3318 "<previous_module>"
__CPROVER_assume(__cs_pc_cs[0] >= 46);
                                        ;
                                        
# 3319 "<previous_module>"
__cs_local_lfds711_stack_pop_i++;
                                        
# 3320 "<previous_module>"
;
                                        ;
                                        
# 3321 "<previous_module>"
static _Bool __cs_local_lfds711_stack_pop___cs_tmp_if_cond_13;
                                        
# 3322 "<previous_module>"
__cs_local_lfds711_stack_pop___cs_tmp_if_cond_13 = __cs_local_lfds711_stack_pop_i > 1000;
                                        
# 3323 "<previous_module>"
if (__cs_local_lfds711_stack_pop___cs_tmp_if_cond_13)

# 3324 "<previous_module>"
                                        {
                                                
# 3325 "<previous_module>"
goto __exit_loop_34;
                                                ;
                                        }

                                        
# 3327 "<previous_module>"
;
                                }
                                
# 3329 "<previous_module>"
;
                                
# 3330 "<previous_module>"
if (
# 3331 "<previous_module>"
!(__cs_local_lfds711_stack_pop_result == 0))

# 3332 "<previous_module>"
                                {
                                        
# 3333 "<previous_module>"
goto __exit_loop_34;
                                        ;
                                }

                                
# 3335 "<previous_module>"
;

# 3336 "<previous_module>"
                                {
                                        
# 3337 "<previous_module>"
;
                                        ;
                                        
# 3338 "<previous_module>"
static _Bool __cs_local_lfds711_stack_pop___cs_tmp_if_cond_11;
                                        
# 3339 "<previous_module>"
__cs_local_lfds711_stack_pop___cs_tmp_if_cond_11 = __cs_local_lfds711_stack_pop_original_top[0] == 0;
                                        
# 3340 "<previous_module>"
if (__cs_local_lfds711_stack_pop___cs_tmp_if_cond_11)

# 3341 "<previous_module>"
                                        {
                                                
# 3342 "<previous_module>"
tmain_46: IF(0,46,tmain_47)__CSEQ_removeindent;
                                                
# 3343 "<previous_module>"
*__cs_param_lfds711_stack_pop_se = 0;
                                                
# 3344 "<previous_module>"
__cs_retval__lfds711_stack_pop_2 = 0;
                                                
# 3345 "<previous_module>"
goto __exit__lfds711_stack_pop_2_0;
                                                ;
                                        }

                                        
# 3347 "<previous_module>"
__CPROVER_assume(__cs_pc_cs[0] >= 47);
                                        ;
                                        
# 3348 "<previous_module>"
tmain_47: IF(0,47,tmain_48)__CSEQ_removeindent;
                                        
# 3349 "<previous_module>"
__cs_local_lfds711_stack_pop_new_top[1] = __cs_local_lfds711_stack_pop_original_top[1] + 1;
                                        
# 3350 "<previous_module>"
tmain_48: IF(0,48,tmain_49)__CSEQ_removeindent;
                                        
# 3351 "<previous_module>"
__cs_local_lfds711_stack_pop_new_top[0] = (*__cs_local_lfds711_stack_pop_original_top[0]).next;
                                        
# 3352 "<previous_module>"
tmain_49: IF(0,49,tmain_50)__CSEQ_removeindent;
                                        
# 3353 "<previous_module>"
__cs_mutex_lock(&library_lock, 0);
                                        
# 3354 "<previous_module>"
tmain_50: IF(0,50,tmain_51)__CSEQ_removeindent;
                                        
# 3355 "<previous_module>"
__cs_local_lfds711_stack_pop_result = __CSEQ_atomic_swap_stack_top(&(*__cs_param_lfds711_stack_pop_ss).top[0], &__cs_local_lfds711_stack_pop_original_top[0], &__cs_local_lfds711_stack_pop_new_top[0]);
                                        
# 3356 "<previous_module>"
tmain_51: IF(0,51,tmain_52)__CSEQ_removeindent;
                                        
# 3357 "<previous_module>"
__cs_mutex_unlock(&library_lock, 0);
                                        
# 3358 "<previous_module>"
;
                                        ;
                                        
# 3359 "<previous_module>"
static _Bool __cs_local_lfds711_stack_pop___cs_tmp_if_cond_12;
                                        
# 3360 "<previous_module>"
__cs_local_lfds711_stack_pop___cs_tmp_if_cond_12 = __cs_local_lfds711_stack_pop_result == 0;
                                        
# 3361 "<previous_module>"
if (__cs_local_lfds711_stack_pop___cs_tmp_if_cond_12)

# 3362 "<previous_module>"
                                        {

# 3363 "<previous_module>"
                                                {
                                                        
# 3364 "<previous_module>"
static int __cs_local_exponential_backoff_loop;
                                                        
# 3365 "<previous_module>"
__cs_local_exponential_backoff_loop = 0;

# 3366 "<previous_module>"
                                                        {
                                                                
# 3367 "<previous_module>"
;
                                                                ;
                                                        }
                                                        
# 3369 "<previous_module>"
;
                                                        
# 3370 "<previous_module>"
__cs_local_exponential_backoff_loop++;

# 3371 "<previous_module>"
                                                        {
                                                                
# 3372 "<previous_module>"
;
                                                                ;
                                                        }
                                                        
# 3374 "<previous_module>"
;
                                                        
# 3375 "<previous_module>"
__cs_local_exponential_backoff_loop++;

# 3376 "<previous_module>"
                                                        {
                                                                
# 3377 "<previous_module>"
;
                                                                ;
                                                        }
                                                        
# 3379 "<previous_module>"
;
                                                        
# 3380 "<previous_module>"
__cs_local_exponential_backoff_loop++;
                                                        
# 3381 "<previous_module>"
tmain_52: IF(0,52,tmain_53)__CSEQ_removeindent;
                                                        
# 3382 "<previous_module>"
__CPROVER_assume(!(__cs_local_exponential_backoff_loop < 3));
                                                        
# 3383 "<previous_module>"
__exit_loop_37:
                                                        __CPROVER_assume(__cs_pc_cs[0] >= 53);

                                                        
# 3384 "<previous_module>"
;
                                                        ;
                                                        
# 3385 "<previous_module>"
__exit__exponential_backoff_5_2:
                                                        __CPROVER_assume(__cs_pc_cs[0] >= 53);

                                                        
# 3386 "<previous_module>"
;
                                                        ;
                                                }
                                                
# 3388 "<previous_module>"
;
                                                
# 3389 "<previous_module>"
tmain_53: IF(0,53,tmain_54)__CSEQ_removeindent;
                                                
# 3390 "<previous_module>"
__cs_mutex_lock(&library_lock, 0);
                                                
# 3391 "<previous_module>"
tmain_54: IF(0,54,tmain_55)__CSEQ_removeindent;
                                                
# 3392 "<previous_module>"
__cs_mutex_unlock(&library_lock, 0);
                                        }

                                        
# 3394 "<previous_module>"
__CPROVER_assume(__cs_pc_cs[0] >= 55);
                                        ;
                                        
# 3395 "<previous_module>"
__cs_local_lfds711_stack_pop_i++;
                                        
# 3396 "<previous_module>"
;
                                        ;
                                        
# 3397 "<previous_module>"
static _Bool __cs_local_lfds711_stack_pop___cs_tmp_if_cond_13;
                                        
# 3398 "<previous_module>"
__cs_local_lfds711_stack_pop___cs_tmp_if_cond_13 = __cs_local_lfds711_stack_pop_i > 1000;
                                        
# 3399 "<previous_module>"
if (__cs_local_lfds711_stack_pop___cs_tmp_if_cond_13)

# 3400 "<previous_module>"
                                        {
                                                
# 3401 "<previous_module>"
goto __exit_loop_34;
                                                ;
                                        }

                                        
# 3403 "<previous_module>"
;
                                }
                                
# 3405 "<previous_module>"
;
                                
# 3406 "<previous_module>"
if (
# 3407 "<previous_module>"
!(__cs_local_lfds711_stack_pop_result == 0))

# 3408 "<previous_module>"
                                {
                                        
# 3409 "<previous_module>"
goto __exit_loop_34;
                                        ;
                                }

                                
# 3411 "<previous_module>"
;

# 3412 "<previous_module>"
                                {
                                        
# 3413 "<previous_module>"
;
                                        ;
                                        
# 3414 "<previous_module>"
static _Bool __cs_local_lfds711_stack_pop___cs_tmp_if_cond_11;
                                        
# 3415 "<previous_module>"
__cs_local_lfds711_stack_pop___cs_tmp_if_cond_11 = __cs_local_lfds711_stack_pop_original_top[0] == 0;
                                        
# 3416 "<previous_module>"
if (__cs_local_lfds711_stack_pop___cs_tmp_if_cond_11)

# 3417 "<previous_module>"
                                        {
                                                
# 3418 "<previous_module>"
tmain_55: IF(0,55,tmain_56)__CSEQ_removeindent;
                                                
# 3419 "<previous_module>"
*__cs_param_lfds711_stack_pop_se = 0;
                                                
# 3420 "<previous_module>"
__cs_retval__lfds711_stack_pop_2 = 0;
                                                
# 3421 "<previous_module>"
goto __exit__lfds711_stack_pop_2_0;
                                                ;
                                        }

                                        
# 3423 "<previous_module>"
__CPROVER_assume(__cs_pc_cs[0] >= 56);
                                        ;
                                        
# 3424 "<previous_module>"
tmain_56: IF(0,56,tmain_57)__CSEQ_removeindent;
                                        
# 3425 "<previous_module>"
__cs_local_lfds711_stack_pop_new_top[1] = __cs_local_lfds711_stack_pop_original_top[1] + 1;
                                        
# 3426 "<previous_module>"
tmain_57: IF(0,57,tmain_58)__CSEQ_removeindent;
                                        
# 3427 "<previous_module>"
__cs_local_lfds711_stack_pop_new_top[0] = (*__cs_local_lfds711_stack_pop_original_top[0]).next;
                                        
# 3428 "<previous_module>"
tmain_58: IF(0,58,tmain_59)__CSEQ_removeindent;
                                        
# 3429 "<previous_module>"
__cs_mutex_lock(&library_lock, 0);
                                        
# 3430 "<previous_module>"
tmain_59: IF(0,59,tmain_60)__CSEQ_removeindent;
                                        
# 3431 "<previous_module>"
__cs_local_lfds711_stack_pop_result = __CSEQ_atomic_swap_stack_top(&(*__cs_param_lfds711_stack_pop_ss).top[0], &__cs_local_lfds711_stack_pop_original_top[0], &__cs_local_lfds711_stack_pop_new_top[0]);
                                        
# 3432 "<previous_module>"
tmain_60: IF(0,60,tmain_61)__CSEQ_removeindent;
                                        
# 3433 "<previous_module>"
__cs_mutex_unlock(&library_lock, 0);
                                        
# 3434 "<previous_module>"
;
                                        ;
                                        
# 3435 "<previous_module>"
static _Bool __cs_local_lfds711_stack_pop___cs_tmp_if_cond_12;
                                        
# 3436 "<previous_module>"
__cs_local_lfds711_stack_pop___cs_tmp_if_cond_12 = __cs_local_lfds711_stack_pop_result == 0;
                                        
# 3437 "<previous_module>"
if (__cs_local_lfds711_stack_pop___cs_tmp_if_cond_12)

# 3438 "<previous_module>"
                                        {

# 3439 "<previous_module>"
                                                {
                                                        
# 3440 "<previous_module>"
static int __cs_local_exponential_backoff_loop;
                                                        
# 3441 "<previous_module>"
__cs_local_exponential_backoff_loop = 0;

# 3442 "<previous_module>"
                                                        {
                                                                
# 3443 "<previous_module>"
;
                                                                ;
                                                        }
                                                        
# 3445 "<previous_module>"
;
                                                        
# 3446 "<previous_module>"
__cs_local_exponential_backoff_loop++;

# 3447 "<previous_module>"
                                                        {
                                                                
# 3448 "<previous_module>"
;
                                                                ;
                                                        }
                                                        
# 3450 "<previous_module>"
;
                                                        
# 3451 "<previous_module>"
__cs_local_exponential_backoff_loop++;

# 3452 "<previous_module>"
                                                        {
                                                                
# 3453 "<previous_module>"
;
                                                                ;
                                                        }
                                                        
# 3455 "<previous_module>"
;
                                                        
# 3456 "<previous_module>"
__cs_local_exponential_backoff_loop++;
                                                        
# 3457 "<previous_module>"
tmain_61: IF(0,61,tmain_62)__CSEQ_removeindent;
                                                        
# 3458 "<previous_module>"
__CPROVER_assume(!(__cs_local_exponential_backoff_loop < 3));
                                                        
# 3459 "<previous_module>"
__exit_loop_38:
                                                        __CPROVER_assume(__cs_pc_cs[0] >= 62);

                                                        
# 3460 "<previous_module>"
;
                                                        ;
                                                        
# 3461 "<previous_module>"
__exit__exponential_backoff_5_3:
                                                        __CPROVER_assume(__cs_pc_cs[0] >= 62);

                                                        
# 3462 "<previous_module>"
;
                                                        ;
                                                }
                                                
# 3464 "<previous_module>"
;
                                                
# 3465 "<previous_module>"
tmain_62: IF(0,62,tmain_63)__CSEQ_removeindent;
                                                
# 3466 "<previous_module>"
__cs_mutex_lock(&library_lock, 0);
                                                
# 3467 "<previous_module>"
tmain_63: IF(0,63,tmain_64)__CSEQ_removeindent;
                                                
# 3468 "<previous_module>"
__cs_mutex_unlock(&library_lock, 0);
                                        }

                                        
# 3470 "<previous_module>"
__CPROVER_assume(__cs_pc_cs[0] >= 64);
                                        ;
                                        
# 3471 "<previous_module>"
__cs_local_lfds711_stack_pop_i++;
                                        
# 3472 "<previous_module>"
;
                                        ;
                                        
# 3473 "<previous_module>"
static _Bool __cs_local_lfds711_stack_pop___cs_tmp_if_cond_13;
                                        
# 3474 "<previous_module>"
__cs_local_lfds711_stack_pop___cs_tmp_if_cond_13 = __cs_local_lfds711_stack_pop_i > 1000;
                                        
# 3475 "<previous_module>"
if (__cs_local_lfds711_stack_pop___cs_tmp_if_cond_13)

# 3476 "<previous_module>"
                                        {
                                                
# 3477 "<previous_module>"
goto __exit_loop_34;
                                                ;
                                        }

                                        
# 3479 "<previous_module>"
;
                                }
                                
# 3481 "<previous_module>"
;
                                
# 3482 "<previous_module>"
if (
# 3483 "<previous_module>"
!(__cs_local_lfds711_stack_pop_result == 0))

# 3484 "<previous_module>"
                                {
                                        
# 3485 "<previous_module>"
goto __exit_loop_34;
                                        ;
                                }

                                
# 3487 "<previous_module>"
;

# 3488 "<previous_module>"
                                {
                                        
# 3489 "<previous_module>"
;
                                        ;
                                        
# 3490 "<previous_module>"
static _Bool __cs_local_lfds711_stack_pop___cs_tmp_if_cond_11;
                                        
# 3491 "<previous_module>"
__cs_local_lfds711_stack_pop___cs_tmp_if_cond_11 = __cs_local_lfds711_stack_pop_original_top[0] == 0;
                                        
# 3492 "<previous_module>"
if (__cs_local_lfds711_stack_pop___cs_tmp_if_cond_11)

# 3493 "<previous_module>"
                                        {
                                                
# 3494 "<previous_module>"
tmain_64: IF(0,64,tmain_65)__CSEQ_removeindent;
                                                
# 3495 "<previous_module>"
*__cs_param_lfds711_stack_pop_se = 0;
                                                
# 3496 "<previous_module>"
__cs_retval__lfds711_stack_pop_2 = 0;
                                                
# 3497 "<previous_module>"
goto __exit__lfds711_stack_pop_2_0;
                                                ;
                                        }

                                        
# 3499 "<previous_module>"
__CPROVER_assume(__cs_pc_cs[0] >= 65);
                                        ;
                                        
# 3500 "<previous_module>"
tmain_65: IF(0,65,tmain_66)__CSEQ_removeindent;
                                        
# 3501 "<previous_module>"
__cs_local_lfds711_stack_pop_new_top[1] = __cs_local_lfds711_stack_pop_original_top[1] + 1;
                                        
# 3502 "<previous_module>"
tmain_66: IF(0,66,tmain_67)__CSEQ_removeindent;
                                        
# 3503 "<previous_module>"
__cs_local_lfds711_stack_pop_new_top[0] = (*__cs_local_lfds711_stack_pop_original_top[0]).next;
                                        
# 3504 "<previous_module>"
tmain_67: IF(0,67,tmain_68)__CSEQ_removeindent;
                                        
# 3505 "<previous_module>"
__cs_mutex_lock(&library_lock, 0);
                                        
# 3506 "<previous_module>"
tmain_68: IF(0,68,tmain_69)__CSEQ_removeindent;
                                        
# 3507 "<previous_module>"
__cs_local_lfds711_stack_pop_result = __CSEQ_atomic_swap_stack_top(&(*__cs_param_lfds711_stack_pop_ss).top[0], &__cs_local_lfds711_stack_pop_original_top[0], &__cs_local_lfds711_stack_pop_new_top[0]);
                                        
# 3508 "<previous_module>"
tmain_69: IF(0,69,tmain_70)__CSEQ_removeindent;
                                        
# 3509 "<previous_module>"
__cs_mutex_unlock(&library_lock, 0);
                                        
# 3510 "<previous_module>"
;
                                        ;
                                        
# 3511 "<previous_module>"
static _Bool __cs_local_lfds711_stack_pop___cs_tmp_if_cond_12;
                                        
# 3512 "<previous_module>"
__cs_local_lfds711_stack_pop___cs_tmp_if_cond_12 = __cs_local_lfds711_stack_pop_result == 0;
                                        
# 3513 "<previous_module>"
if (__cs_local_lfds711_stack_pop___cs_tmp_if_cond_12)

# 3514 "<previous_module>"
                                        {

# 3515 "<previous_module>"
                                                {
                                                        
# 3516 "<previous_module>"
static int __cs_local_exponential_backoff_loop;
                                                        
# 3517 "<previous_module>"
__cs_local_exponential_backoff_loop = 0;

# 3518 "<previous_module>"
                                                        {
                                                                
# 3519 "<previous_module>"
;
                                                                ;
                                                        }
                                                        
# 3521 "<previous_module>"
;
                                                        
# 3522 "<previous_module>"
__cs_local_exponential_backoff_loop++;

# 3523 "<previous_module>"
                                                        {
                                                                
# 3524 "<previous_module>"
;
                                                                ;
                                                        }
                                                        
# 3526 "<previous_module>"
;
                                                        
# 3527 "<previous_module>"
__cs_local_exponential_backoff_loop++;

# 3528 "<previous_module>"
                                                        {
                                                                
# 3529 "<previous_module>"
;
                                                                ;
                                                        }
                                                        
# 3531 "<previous_module>"
;
                                                        
# 3532 "<previous_module>"
__cs_local_exponential_backoff_loop++;
                                                        
# 3533 "<previous_module>"
tmain_70: IF(0,70,tmain_71)__CSEQ_removeindent;
                                                        
# 3534 "<previous_module>"
__CPROVER_assume(!(__cs_local_exponential_backoff_loop < 3));
                                                        
# 3535 "<previous_module>"
__exit_loop_39:
                                                        __CPROVER_assume(__cs_pc_cs[0] >= 71);

                                                        
# 3536 "<previous_module>"
;
                                                        ;
                                                        
# 3537 "<previous_module>"
__exit__exponential_backoff_5_4:
                                                        __CPROVER_assume(__cs_pc_cs[0] >= 71);

                                                        
# 3538 "<previous_module>"
;
                                                        ;
                                                }
                                                
# 3540 "<previous_module>"
;
                                                
# 3541 "<previous_module>"
tmain_71: IF(0,71,tmain_72)__CSEQ_removeindent;
                                                
# 3542 "<previous_module>"
__cs_mutex_lock(&library_lock, 0);
                                                
# 3543 "<previous_module>"
tmain_72: IF(0,72,tmain_73)__CSEQ_removeindent;
                                                
# 3544 "<previous_module>"
__cs_mutex_unlock(&library_lock, 0);
                                        }

                                        
# 3546 "<previous_module>"
__CPROVER_assume(__cs_pc_cs[0] >= 73);
                                        ;
                                        
# 3547 "<previous_module>"
__cs_local_lfds711_stack_pop_i++;
                                        
# 3548 "<previous_module>"
;
                                        ;
                                        
# 3549 "<previous_module>"
static _Bool __cs_local_lfds711_stack_pop___cs_tmp_if_cond_13;
                                        
# 3550 "<previous_module>"
__cs_local_lfds711_stack_pop___cs_tmp_if_cond_13 = __cs_local_lfds711_stack_pop_i > 1000;
                                        
# 3551 "<previous_module>"
if (__cs_local_lfds711_stack_pop___cs_tmp_if_cond_13)

# 3552 "<previous_module>"
                                        {
                                                
# 3553 "<previous_module>"
goto __exit_loop_34;
                                                ;
                                        }

                                        
# 3555 "<previous_module>"
;
                                }
                                
# 3557 "<previous_module>"
;
                                
# 3558 "<previous_module>"
tmain_73: IF(0,73,tmain_74)__CSEQ_removeindent;
                                
# 3559 "<previous_module>"
__CPROVER_assume(
# 3560 "<previous_module>"
!(__cs_local_lfds711_stack_pop_result == 0));
                                
# 3561 "<previous_module>"
__exit_loop_34:
                                __CPROVER_assume(__cs_pc_cs[0] >= 74);

                                
# 3562 "<previous_module>"
;
                                ;
                                
# 3563 "<previous_module>"
tmain_74: IF(0,74,tmain_75)__CSEQ_removeindent;
                                
# 3564 "<previous_module>"
*__cs_param_lfds711_stack_pop_se = __cs_local_lfds711_stack_pop_original_top[0];
                                
# 3565 "<previous_module>"
__cs_retval__lfds711_stack_pop_2 = __cs_local_lfds711_stack_pop_result;
                                
# 3566 "<previous_module>"
goto __exit__lfds711_stack_pop_2_0;
                                ;
                                
# 3567 "<previous_module>"
__exit__lfds711_stack_pop_2_0:
                                __CPROVER_assume(__cs_pc_cs[0] >= 75);

                                
# 3568 "<previous_module>"
;
                                ;
                        }
                        
# 3570 "<previous_module>"
;
                        
# 3571 "<previous_module>"
__cs_local_contains_res = __cs_retval__lfds711_stack_pop_2;
                        
# 3572 "<previous_module>"
;
                        ;
                        
# 3573 "<previous_module>"
static _Bool __cs_local_contains___cs_tmp_if_cond_20;
                        
# 3574 "<previous_module>"
__cs_local_contains___cs_tmp_if_cond_20 = __cs_local_contains_res == 0;
                        
# 3575 "<previous_module>"
if (__cs_local_contains___cs_tmp_if_cond_20)

# 3576 "<previous_module>"
                        {
                                
# 3577 "<previous_module>"
goto __exit_loop_31;
                                ;
                        }

                        
# 3579 "<previous_module>"
;
                        
# 3580 "<previous_module>"
tmain_75: IF(0,75,tmain_76)__CSEQ_removeindent;
                        
# 3581 "<previous_module>"
__cs_local_contains_datas[__cs_local_contains_actual_size] = (*__cs_local_contains_se).value;
                        
# 3582 "<previous_module>"
;
                        ;
                        
# 3583 "<previous_module>"
static _Bool __cs_local_contains___cs_tmp_if_cond_21;
                        
# 3584 "<previous_module>"
tmain_76: IF(0,76,tmain_77)__CSEQ_removeindent;
                        
# 3585 "<previous_module>"
__cs_local_contains___cs_tmp_if_cond_21 = (*__cs_local_contains_datas[__cs_local_contains_actual_size]).user_id == __cs_param_contains_id;
                        
# 3586 "<previous_module>"
if (__cs_local_contains___cs_tmp_if_cond_21)

# 3587 "<previous_module>"
                        {
                                
# 3588 "<previous_module>"
__cs_local_contains_found = 1;
                        }

                        
# 3590 "<previous_module>"
;
                        
# 3591 "<previous_module>"
__cs_local_contains_actual_size = __cs_local_contains_actual_size + 1;
                }
                
# 3593 "<previous_module>"
;
                
# 3594 "<previous_module>"
if (!(__cs_local_contains_actual_size < 2))

# 3595 "<previous_module>"
                {
                        
# 3596 "<previous_module>"
goto __exit_loop_31;
                        ;
                }

                
# 3598 "<previous_module>"
;

# 3599 "<previous_module>"
                {
                        
# 3600 "<previous_module>"
static int __cs_retval__lfds711_stack_pop_2;

# 3601 "<previous_module>"
                        {
                                
# 3602 "<previous_module>"
static struct lfds711_stack_state *__cs_param_lfds711_stack_pop_ss;
                                
# 3603 "<previous_module>"
tmain_77: IF(0,77,tmain_78)__CSEQ_removeindent;
                                
# 3604 "<previous_module>"
__cs_param_lfds711_stack_pop_ss = __cs_param_contains_s;
                                
# 3605 "<previous_module>"
static struct lfds711_stack_element **__cs_param_lfds711_stack_pop_se;
                                
# 3606 "<previous_module>"
tmain_78: IF(0,78,tmain_79)__CSEQ_removeindent;
                                
# 3607 "<previous_module>"
__cs_param_lfds711_stack_pop_se = &__cs_local_contains_se;
                                
# 3608 "<previous_module>"
static char unsigned __cs_local_lfds711_stack_pop_result;
                                
# 3609 "<previous_module>"
static lfds711_pal_uint_t __cs_local_lfds711_stack_pop_backoff_iteration;
                                
# 3610 "<previous_module>"
__cs_local_lfds711_stack_pop_backoff_iteration = 0;
                                
# 3611 "<previous_module>"
static struct lfds711_stack_element *__cs_local_lfds711_stack_pop_new_top[2];
                                
# 3612 "<previous_module>"
static struct lfds711_stack_element * volatile __cs_local_lfds711_stack_pop_original_top[2];
                                
# 3613 "<previous_module>"
;
                                ;
                                
# 3614 "<previous_module>"
static _Bool __cs_local_lfds711_stack_pop___cs_tmp_if_cond_6;
                                
# 3615 "<previous_module>"
tmain_79: IF(0,79,tmain_80)__CSEQ_removeindent;
                                
# 3616 "<previous_module>"
__cs_local_lfds711_stack_pop___cs_tmp_if_cond_6 = !(__cs_param_lfds711_stack_pop_ss != 0);
                                
# 3617 "<previous_module>"
if (__cs_local_lfds711_stack_pop___cs_tmp_if_cond_6)

# 3618 "<previous_module>"
                                {
                                        
# 3619 "<previous_module>"
static char *__cs_local_lfds711_stack_pop_c;
                                        
# 3620 "<previous_module>"
tmain_80: IF(0,80,tmain_81)__CSEQ_removeindent;
                                        
# 3621 "<previous_module>"
__cs_local_lfds711_stack_pop_c = 0;
                                        
# 3622 "<previous_module>"
tmain_81: IF(0,81,tmain_82)__CSEQ_removeindent;
                                        
# 3623 "<previous_module>"
*__cs_local_lfds711_stack_pop_c = 0;
                                }

                                
# 3625 "<previous_module>"
__CPROVER_assume(__cs_pc_cs[0] >= 82);
                                ;
                                
# 3626 "<previous_module>"
;
                                ;
                                
# 3627 "<previous_module>"
;
                                ;
                                
# 3628 "<previous_module>"
;
                                ;
                                
# 3629 "<previous_module>"
static _Bool __cs_local_lfds711_stack_pop___cs_tmp_if_cond_7;
                                
# 3630 "<previous_module>"
tmain_82: IF(0,82,tmain_83)__CSEQ_removeindent;
                                
# 3631 "<previous_module>"
__cs_local_lfds711_stack_pop___cs_tmp_if_cond_7 = !(__cs_param_lfds711_stack_pop_se != 0);
                                
# 3632 "<previous_module>"
if (__cs_local_lfds711_stack_pop___cs_tmp_if_cond_7)

# 3633 "<previous_module>"
                                {
                                        
# 3634 "<previous_module>"
static char *__cs_local_lfds711_stack_pop_c;
                                        
# 3635 "<previous_module>"
tmain_83: IF(0,83,tmain_84)__CSEQ_removeindent;
                                        
# 3636 "<previous_module>"
__cs_local_lfds711_stack_pop_c = 0;
                                        
# 3637 "<previous_module>"
tmain_84: IF(0,84,tmain_85)__CSEQ_removeindent;
                                        
# 3638 "<previous_module>"
*__cs_local_lfds711_stack_pop_c = 0;
                                }

                                
# 3640 "<previous_module>"
__CPROVER_assume(__cs_pc_cs[0] >= 85);
                                ;
                                
# 3641 "<previous_module>"
;
                                ;
                                
# 3642 "<previous_module>"
;
                                ;
                                
# 3643 "<previous_module>"
tmain_85: IF(0,85,tmain_86)__CSEQ_removeindent;
                                
# 3644 "<previous_module>"
__cs_mutex_lock(&library_lock, 0);
                                
# 3645 "<previous_module>"
tmain_86: IF(0,86,tmain_87)__CSEQ_removeindent;
                                
# 3646 "<previous_module>"
__cs_mutex_unlock(&library_lock, 0);
                                
# 3647 "<previous_module>"
tmain_87: IF(0,87,tmain_88)__CSEQ_removeindent;
                                
# 3648 "<previous_module>"
__cs_local_lfds711_stack_pop_original_top[1] = (*__cs_param_lfds711_stack_pop_ss).top[1];
                                
# 3649 "<previous_module>"
tmain_88: IF(0,88,tmain_89)__CSEQ_removeindent;
                                
# 3650 "<previous_module>"
__cs_local_lfds711_stack_pop_original_top[0] = (*__cs_param_lfds711_stack_pop_ss).top[0];
                                
# 3651 "<previous_module>"
static int __cs_local_lfds711_stack_pop_i;
                                
# 3652 "<previous_module>"
__cs_local_lfds711_stack_pop_i = 0;
                                
# 3653 "<previous_module>"
;
                                ;
                                
# 3654 "<previous_module>"
static int __cs_local_lfds711_stack_pop___cs_dowhile_onetime_1;
                                
# 3655 "<previous_module>"
__cs_local_lfds711_stack_pop___cs_dowhile_onetime_1 = 0;

# 3656 "<previous_module>"
                                {
                                        
# 3657 "<previous_module>"
;
                                        ;
                                        
# 3658 "<previous_module>"
static _Bool __cs_local_lfds711_stack_pop___cs_tmp_if_cond_8;
                                        
# 3659 "<previous_module>"
__cs_local_lfds711_stack_pop___cs_tmp_if_cond_8 = __cs_local_lfds711_stack_pop_original_top[0] == 0;
                                        
# 3660 "<previous_module>"
if (__cs_local_lfds711_stack_pop___cs_tmp_if_cond_8)

# 3661 "<previous_module>"
                                        {
                                                
# 3662 "<previous_module>"
tmain_89: IF(0,89,tmain_90)__CSEQ_removeindent;
                                                
# 3663 "<previous_module>"
*__cs_param_lfds711_stack_pop_se = 0;
                                                
# 3664 "<previous_module>"
__cs_retval__lfds711_stack_pop_2 = 0;
                                                
# 3665 "<previous_module>"
goto __exit__lfds711_stack_pop_2_1;
                                                ;
                                        }

                                        
# 3667 "<previous_module>"
__CPROVER_assume(__cs_pc_cs[0] >= 90);
                                        ;
                                        
# 3668 "<previous_module>"
tmain_90: IF(0,90,tmain_91)__CSEQ_removeindent;
                                        
# 3669 "<previous_module>"
__cs_local_lfds711_stack_pop_new_top[1] = __cs_local_lfds711_stack_pop_original_top[1] + 1;
                                        
# 3670 "<previous_module>"
tmain_91: IF(0,91,tmain_92)__CSEQ_removeindent;
                                        
# 3671 "<previous_module>"
__cs_local_lfds711_stack_pop_new_top[0] = (*__cs_local_lfds711_stack_pop_original_top[0]).next;
                                        
# 3672 "<previous_module>"
tmain_92: IF(0,92,tmain_93)__CSEQ_removeindent;
                                        
# 3673 "<previous_module>"
__cs_mutex_lock(&library_lock, 0);
                                        
# 3674 "<previous_module>"
tmain_93: IF(0,93,tmain_94)__CSEQ_removeindent;
                                        
# 3675 "<previous_module>"
__cs_local_lfds711_stack_pop_result = __CSEQ_atomic_swap_stack_top(&(*__cs_param_lfds711_stack_pop_ss).top[0], &__cs_local_lfds711_stack_pop_original_top[0], &__cs_local_lfds711_stack_pop_new_top[0]);
                                        
# 3676 "<previous_module>"
tmain_94: IF(0,94,tmain_95)__CSEQ_removeindent;
                                        
# 3677 "<previous_module>"
__cs_mutex_unlock(&library_lock, 0);
                                        
# 3678 "<previous_module>"
;
                                        ;
                                        
# 3679 "<previous_module>"
static _Bool __cs_local_lfds711_stack_pop___cs_tmp_if_cond_9;
                                        
# 3680 "<previous_module>"
__cs_local_lfds711_stack_pop___cs_tmp_if_cond_9 = __cs_local_lfds711_stack_pop_result == 0;
                                        
# 3681 "<previous_module>"
if (__cs_local_lfds711_stack_pop___cs_tmp_if_cond_9)

# 3682 "<previous_module>"
                                        {

# 3683 "<previous_module>"
                                                {
                                                        
# 3684 "<previous_module>"
static int __cs_local_exponential_backoff_loop;
                                                        
# 3685 "<previous_module>"
__cs_local_exponential_backoff_loop = 0;

# 3686 "<previous_module>"
                                                        {
                                                                
# 3687 "<previous_module>"
;
                                                                ;
                                                        }
                                                        
# 3689 "<previous_module>"
;
                                                        
# 3690 "<previous_module>"
__cs_local_exponential_backoff_loop++;

# 3691 "<previous_module>"
                                                        {
                                                                
# 3692 "<previous_module>"
;
                                                                ;
                                                        }
                                                        
# 3694 "<previous_module>"
;
                                                        
# 3695 "<previous_module>"
__cs_local_exponential_backoff_loop++;

# 3696 "<previous_module>"
                                                        {
                                                                
# 3697 "<previous_module>"
;
                                                                ;
                                                        }
                                                        
# 3699 "<previous_module>"
;
                                                        
# 3700 "<previous_module>"
__cs_local_exponential_backoff_loop++;
                                                        
# 3701 "<previous_module>"
tmain_95: IF(0,95,tmain_96)__CSEQ_removeindent;
                                                        
# 3702 "<previous_module>"
__CPROVER_assume(!(__cs_local_exponential_backoff_loop < 3));
                                                        
# 3703 "<previous_module>"
__exit_loop_41:
                                                        __CPROVER_assume(__cs_pc_cs[0] >= 96);

                                                        
# 3704 "<previous_module>"
;
                                                        ;
                                                        
# 3705 "<previous_module>"
__exit__exponential_backoff_4_1:
                                                        __CPROVER_assume(__cs_pc_cs[0] >= 96);

                                                        
# 3706 "<previous_module>"
;
                                                        ;
                                                }
                                                
# 3708 "<previous_module>"
;
                                                
# 3709 "<previous_module>"
tmain_96: IF(0,96,tmain_97)__CSEQ_removeindent;
                                                
# 3710 "<previous_module>"
__cs_mutex_lock(&library_lock, 0);
                                                
# 3711 "<previous_module>"
tmain_97: IF(0,97,tmain_98)__CSEQ_removeindent;
                                                
# 3712 "<previous_module>"
__cs_mutex_unlock(&library_lock, 0);
                                        }

                                        
# 3714 "<previous_module>"
__CPROVER_assume(__cs_pc_cs[0] >= 98);
                                        ;
                                        
# 3715 "<previous_module>"
__cs_local_lfds711_stack_pop_i++;
                                        
# 3716 "<previous_module>"
;
                                        ;
                                        
# 3717 "<previous_module>"
static _Bool __cs_local_lfds711_stack_pop___cs_tmp_if_cond_10;
                                        
# 3718 "<previous_module>"
__cs_local_lfds711_stack_pop___cs_tmp_if_cond_10 = __cs_local_lfds711_stack_pop_i > 1000;
                                        
# 3719 "<previous_module>"
if (__cs_local_lfds711_stack_pop___cs_tmp_if_cond_10)

# 3720 "<previous_module>"
                                        {
                                                
# 3721 "<previous_module>"
goto __exit_loop_40;
                                                ;
                                        }

                                        
# 3723 "<previous_module>"
;
                                }
                                
# 3725 "<previous_module>"
;
                                
# 3726 "<previous_module>"
__cs_local_lfds711_stack_pop___cs_dowhile_onetime_1++;
                                
# 3727 "<previous_module>"
tmain_98: IF(0,98,tmain_99)__CSEQ_removeindent;
                                
# 3728 "<previous_module>"
__CPROVER_assume(!(__cs_local_lfds711_stack_pop___cs_dowhile_onetime_1 < 1));
                                
# 3729 "<previous_module>"
__exit_loop_40:
                                __CPROVER_assume(__cs_pc_cs[0] >= 99);

                                
# 3730 "<previous_module>"
;
                                ;
                                
# 3731 "<previous_module>"
if (
# 3732 "<previous_module>"
!(__cs_local_lfds711_stack_pop_result == 0))

# 3733 "<previous_module>"
                                {
                                        
# 3734 "<previous_module>"
goto __exit_loop_42;
                                        ;
                                }

                                
# 3736 "<previous_module>"
;

# 3737 "<previous_module>"
                                {
                                        
# 3738 "<previous_module>"
;
                                        ;
                                        
# 3739 "<previous_module>"
static _Bool __cs_local_lfds711_stack_pop___cs_tmp_if_cond_11;
                                        
# 3740 "<previous_module>"
__cs_local_lfds711_stack_pop___cs_tmp_if_cond_11 = __cs_local_lfds711_stack_pop_original_top[0] == 0;
                                        
# 3741 "<previous_module>"
if (__cs_local_lfds711_stack_pop___cs_tmp_if_cond_11)

# 3742 "<previous_module>"
                                        {
                                                
# 3743 "<previous_module>"
tmain_99: IF(0,99,tmain_100)__CSEQ_removeindent;
                                                
# 3744 "<previous_module>"
*__cs_param_lfds711_stack_pop_se = 0;
                                                
# 3745 "<previous_module>"
__cs_retval__lfds711_stack_pop_2 = 0;
                                                
# 3746 "<previous_module>"
goto __exit__lfds711_stack_pop_2_1;
                                                ;
                                        }

                                        
# 3748 "<previous_module>"
__CPROVER_assume(__cs_pc_cs[0] >= 100);
                                        ;
                                        
# 3749 "<previous_module>"
tmain_100: IF(0,100,tmain_101)__CSEQ_removeindent;
                                        
# 3750 "<previous_module>"
__cs_local_lfds711_stack_pop_new_top[1] = __cs_local_lfds711_stack_pop_original_top[1] + 1;
                                        
# 3751 "<previous_module>"
tmain_101: IF(0,101,tmain_102)__CSEQ_removeindent;
                                        
# 3752 "<previous_module>"
__cs_local_lfds711_stack_pop_new_top[0] = (*__cs_local_lfds711_stack_pop_original_top[0]).next;
                                        
# 3753 "<previous_module>"
tmain_102: IF(0,102,tmain_103)__CSEQ_removeindent;
                                        
# 3754 "<previous_module>"
__cs_mutex_lock(&library_lock, 0);
                                        
# 3755 "<previous_module>"
tmain_103: IF(0,103,tmain_104)__CSEQ_removeindent;
                                        
# 3756 "<previous_module>"
__cs_local_lfds711_stack_pop_result = __CSEQ_atomic_swap_stack_top(&(*__cs_param_lfds711_stack_pop_ss).top[0], &__cs_local_lfds711_stack_pop_original_top[0], &__cs_local_lfds711_stack_pop_new_top[0]);
                                        
# 3757 "<previous_module>"
tmain_104: IF(0,104,tmain_105)__CSEQ_removeindent;
                                        
# 3758 "<previous_module>"
__cs_mutex_unlock(&library_lock, 0);
                                        
# 3759 "<previous_module>"
;
                                        ;
                                        
# 3760 "<previous_module>"
static _Bool __cs_local_lfds711_stack_pop___cs_tmp_if_cond_12;
                                        
# 3761 "<previous_module>"
__cs_local_lfds711_stack_pop___cs_tmp_if_cond_12 = __cs_local_lfds711_stack_pop_result == 0;
                                        
# 3762 "<previous_module>"
if (__cs_local_lfds711_stack_pop___cs_tmp_if_cond_12)

# 3763 "<previous_module>"
                                        {

# 3764 "<previous_module>"
                                                {
                                                        
# 3765 "<previous_module>"
static int __cs_local_exponential_backoff_loop;
                                                        
# 3766 "<previous_module>"
__cs_local_exponential_backoff_loop = 0;

# 3767 "<previous_module>"
                                                        {
                                                                
# 3768 "<previous_module>"
;
                                                                ;
                                                        }
                                                        
# 3770 "<previous_module>"
;
                                                        
# 3771 "<previous_module>"
__cs_local_exponential_backoff_loop++;

# 3772 "<previous_module>"
                                                        {
                                                                
# 3773 "<previous_module>"
;
                                                                ;
                                                        }
                                                        
# 3775 "<previous_module>"
;
                                                        
# 3776 "<previous_module>"
__cs_local_exponential_backoff_loop++;

# 3777 "<previous_module>"
                                                        {
                                                                
# 3778 "<previous_module>"
;
                                                                ;
                                                        }
                                                        
# 3780 "<previous_module>"
;
                                                        
# 3781 "<previous_module>"
__cs_local_exponential_backoff_loop++;
                                                        
# 3782 "<previous_module>"
tmain_105: IF(0,105,tmain_106)__CSEQ_removeindent;
                                                        
# 3783 "<previous_module>"
__CPROVER_assume(!(__cs_local_exponential_backoff_loop < 3));
                                                        
# 3784 "<previous_module>"
__exit_loop_43:
                                                        __CPROVER_assume(__cs_pc_cs[0] >= 106);

                                                        
# 3785 "<previous_module>"
;
                                                        ;
                                                        
# 3786 "<previous_module>"
__exit__exponential_backoff_5_5:
                                                        __CPROVER_assume(__cs_pc_cs[0] >= 106);

                                                        
# 3787 "<previous_module>"
;
                                                        ;
                                                }
                                                
# 3789 "<previous_module>"
;
                                                
# 3790 "<previous_module>"
tmain_106: IF(0,106,tmain_107)__CSEQ_removeindent;
                                                
# 3791 "<previous_module>"
__cs_mutex_lock(&library_lock, 0);
                                                
# 3792 "<previous_module>"
tmain_107: IF(0,107,tmain_108)__CSEQ_removeindent;
                                                
# 3793 "<previous_module>"
__cs_mutex_unlock(&library_lock, 0);
                                        }

                                        
# 3795 "<previous_module>"
__CPROVER_assume(__cs_pc_cs[0] >= 108);
                                        ;
                                        
# 3796 "<previous_module>"
__cs_local_lfds711_stack_pop_i++;
                                        
# 3797 "<previous_module>"
;
                                        ;
                                        
# 3798 "<previous_module>"
static _Bool __cs_local_lfds711_stack_pop___cs_tmp_if_cond_13;
                                        
# 3799 "<previous_module>"
__cs_local_lfds711_stack_pop___cs_tmp_if_cond_13 = __cs_local_lfds711_stack_pop_i > 1000;
                                        
# 3800 "<previous_module>"
if (__cs_local_lfds711_stack_pop___cs_tmp_if_cond_13)

# 3801 "<previous_module>"
                                        {
                                                
# 3802 "<previous_module>"
goto __exit_loop_42;
                                                ;
                                        }

                                        
# 3804 "<previous_module>"
;
                                }
                                
# 3806 "<previous_module>"
;
                                
# 3807 "<previous_module>"
if (
# 3808 "<previous_module>"
!(__cs_local_lfds711_stack_pop_result == 0))

# 3809 "<previous_module>"
                                {
                                        
# 3810 "<previous_module>"
goto __exit_loop_42;
                                        ;
                                }

                                
# 3812 "<previous_module>"
;

# 3813 "<previous_module>"
                                {
                                        
# 3814 "<previous_module>"
;
                                        ;
                                        
# 3815 "<previous_module>"
static _Bool __cs_local_lfds711_stack_pop___cs_tmp_if_cond_11;
                                        
# 3816 "<previous_module>"
__cs_local_lfds711_stack_pop___cs_tmp_if_cond_11 = __cs_local_lfds711_stack_pop_original_top[0] == 0;
                                        
# 3817 "<previous_module>"
if (__cs_local_lfds711_stack_pop___cs_tmp_if_cond_11)

# 3818 "<previous_module>"
                                        {
                                                
# 3819 "<previous_module>"
tmain_108: IF(0,108,tmain_109)__CSEQ_removeindent;
                                                
# 3820 "<previous_module>"
*__cs_param_lfds711_stack_pop_se = 0;
                                                
# 3821 "<previous_module>"
__cs_retval__lfds711_stack_pop_2 = 0;
                                                
# 3822 "<previous_module>"
goto __exit__lfds711_stack_pop_2_1;
                                                ;
                                        }

                                        
# 3824 "<previous_module>"
__CPROVER_assume(__cs_pc_cs[0] >= 109);
                                        ;
                                        
# 3825 "<previous_module>"
tmain_109: IF(0,109,tmain_110)__CSEQ_removeindent;
                                        
# 3826 "<previous_module>"
__cs_local_lfds711_stack_pop_new_top[1] = __cs_local_lfds711_stack_pop_original_top[1] + 1;
                                        
# 3827 "<previous_module>"
tmain_110: IF(0,110,tmain_111)__CSEQ_removeindent;
                                        
# 3828 "<previous_module>"
__cs_local_lfds711_stack_pop_new_top[0] = (*__cs_local_lfds711_stack_pop_original_top[0]).next;
                                        
# 3829 "<previous_module>"
tmain_111: IF(0,111,tmain_112)__CSEQ_removeindent;
                                        
# 3830 "<previous_module>"
__cs_mutex_lock(&library_lock, 0);
                                        
# 3831 "<previous_module>"
tmain_112: IF(0,112,tmain_113)__CSEQ_removeindent;
                                        
# 3832 "<previous_module>"
__cs_local_lfds711_stack_pop_result = __CSEQ_atomic_swap_stack_top(&(*__cs_param_lfds711_stack_pop_ss).top[0], &__cs_local_lfds711_stack_pop_original_top[0], &__cs_local_lfds711_stack_pop_new_top[0]);
                                        
# 3833 "<previous_module>"
tmain_113: IF(0,113,tmain_114)__CSEQ_removeindent;
                                        
# 3834 "<previous_module>"
__cs_mutex_unlock(&library_lock, 0);
                                        
# 3835 "<previous_module>"
;
                                        ;
                                        
# 3836 "<previous_module>"
static _Bool __cs_local_lfds711_stack_pop___cs_tmp_if_cond_12;
                                        
# 3837 "<previous_module>"
__cs_local_lfds711_stack_pop___cs_tmp_if_cond_12 = __cs_local_lfds711_stack_pop_result == 0;
                                        
# 3838 "<previous_module>"
if (__cs_local_lfds711_stack_pop___cs_tmp_if_cond_12)

# 3839 "<previous_module>"
                                        {

# 3840 "<previous_module>"
                                                {
                                                        
# 3841 "<previous_module>"
static int __cs_local_exponential_backoff_loop;
                                                        
# 3842 "<previous_module>"
__cs_local_exponential_backoff_loop = 0;

# 3843 "<previous_module>"
                                                        {
                                                                
# 3844 "<previous_module>"
;
                                                                ;
                                                        }
                                                        
# 3846 "<previous_module>"
;
                                                        
# 3847 "<previous_module>"
__cs_local_exponential_backoff_loop++;

# 3848 "<previous_module>"
                                                        {
                                                                
# 3849 "<previous_module>"
;
                                                                ;
                                                        }
                                                        
# 3851 "<previous_module>"
;
                                                        
# 3852 "<previous_module>"
__cs_local_exponential_backoff_loop++;

# 3853 "<previous_module>"
                                                        {
                                                                
# 3854 "<previous_module>"
;
                                                                ;
                                                        }
                                                        
# 3856 "<previous_module>"
;
                                                        
# 3857 "<previous_module>"
__cs_local_exponential_backoff_loop++;
                                                        
# 3858 "<previous_module>"
tmain_114: IF(0,114,tmain_115)__CSEQ_removeindent;
                                                        
# 3859 "<previous_module>"
__CPROVER_assume(!(__cs_local_exponential_backoff_loop < 3));
                                                        
# 3860 "<previous_module>"
__exit_loop_44:
                                                        __CPROVER_assume(__cs_pc_cs[0] >= 115);

                                                        
# 3861 "<previous_module>"
;
                                                        ;
                                                        
# 3862 "<previous_module>"
__exit__exponential_backoff_5_6:
                                                        __CPROVER_assume(__cs_pc_cs[0] >= 115);

                                                        
# 3863 "<previous_module>"
;
                                                        ;
                                                }
                                                
# 3865 "<previous_module>"
;
                                                
# 3866 "<previous_module>"
tmain_115: IF(0,115,tmain_116)__CSEQ_removeindent;
                                                
# 3867 "<previous_module>"
__cs_mutex_lock(&library_lock, 0);
                                                
# 3868 "<previous_module>"
tmain_116: IF(0,116,tmain_117)__CSEQ_removeindent;
                                                
# 3869 "<previous_module>"
__cs_mutex_unlock(&library_lock, 0);
                                        }

                                        
# 3871 "<previous_module>"
__CPROVER_assume(__cs_pc_cs[0] >= 117);
                                        ;
                                        
# 3872 "<previous_module>"
__cs_local_lfds711_stack_pop_i++;
                                        
# 3873 "<previous_module>"
;
                                        ;
                                        
# 3874 "<previous_module>"
static _Bool __cs_local_lfds711_stack_pop___cs_tmp_if_cond_13;
                                        
# 3875 "<previous_module>"
__cs_local_lfds711_stack_pop___cs_tmp_if_cond_13 = __cs_local_lfds711_stack_pop_i > 1000;
                                        
# 3876 "<previous_module>"
if (__cs_local_lfds711_stack_pop___cs_tmp_if_cond_13)

# 3877 "<previous_module>"
                                        {
                                                
# 3878 "<previous_module>"
goto __exit_loop_42;
                                                ;
                                        }

                                        
# 3880 "<previous_module>"
;
                                }
                                
# 3882 "<previous_module>"
;
                                
# 3883 "<previous_module>"
if (
# 3884 "<previous_module>"
!(__cs_local_lfds711_stack_pop_result == 0))

# 3885 "<previous_module>"
                                {
                                        
# 3886 "<previous_module>"
goto __exit_loop_42;
                                        ;
                                }

                                
# 3888 "<previous_module>"
;

# 3889 "<previous_module>"
                                {
                                        
# 3890 "<previous_module>"
;
                                        ;
                                        
# 3891 "<previous_module>"
static _Bool __cs_local_lfds711_stack_pop___cs_tmp_if_cond_11;
                                        
# 3892 "<previous_module>"
__cs_local_lfds711_stack_pop___cs_tmp_if_cond_11 = __cs_local_lfds711_stack_pop_original_top[0] == 0;
                                        
# 3893 "<previous_module>"
if (__cs_local_lfds711_stack_pop___cs_tmp_if_cond_11)

# 3894 "<previous_module>"
                                        {
                                                
# 3895 "<previous_module>"
tmain_117: IF(0,117,tmain_118)__CSEQ_removeindent;
                                                
# 3896 "<previous_module>"
*__cs_param_lfds711_stack_pop_se = 0;
                                                
# 3897 "<previous_module>"
__cs_retval__lfds711_stack_pop_2 = 0;
                                                
# 3898 "<previous_module>"
goto __exit__lfds711_stack_pop_2_1;
                                                ;
                                        }

                                        
# 3900 "<previous_module>"
__CPROVER_assume(__cs_pc_cs[0] >= 118);
                                        ;
                                        
# 3901 "<previous_module>"
tmain_118: IF(0,118,tmain_119)__CSEQ_removeindent;
                                        
# 3902 "<previous_module>"
__cs_local_lfds711_stack_pop_new_top[1] = __cs_local_lfds711_stack_pop_original_top[1] + 1;
                                        
# 3903 "<previous_module>"
tmain_119: IF(0,119,tmain_120)__CSEQ_removeindent;
                                        
# 3904 "<previous_module>"
__cs_local_lfds711_stack_pop_new_top[0] = (*__cs_local_lfds711_stack_pop_original_top[0]).next;
                                        
# 3905 "<previous_module>"
tmain_120: IF(0,120,tmain_121)__CSEQ_removeindent;
                                        
# 3906 "<previous_module>"
__cs_mutex_lock(&library_lock, 0);
                                        
# 3907 "<previous_module>"
tmain_121: IF(0,121,tmain_122)__CSEQ_removeindent;
                                        
# 3908 "<previous_module>"
__cs_local_lfds711_stack_pop_result = __CSEQ_atomic_swap_stack_top(&(*__cs_param_lfds711_stack_pop_ss).top[0], &__cs_local_lfds711_stack_pop_original_top[0], &__cs_local_lfds711_stack_pop_new_top[0]);
                                        
# 3909 "<previous_module>"
tmain_122: IF(0,122,tmain_123)__CSEQ_removeindent;
                                        
# 3910 "<previous_module>"
__cs_mutex_unlock(&library_lock, 0);
                                        
# 3911 "<previous_module>"
;
                                        ;
                                        
# 3912 "<previous_module>"
static _Bool __cs_local_lfds711_stack_pop___cs_tmp_if_cond_12;
                                        
# 3913 "<previous_module>"
__cs_local_lfds711_stack_pop___cs_tmp_if_cond_12 = __cs_local_lfds711_stack_pop_result == 0;
                                        
# 3914 "<previous_module>"
if (__cs_local_lfds711_stack_pop___cs_tmp_if_cond_12)

# 3915 "<previous_module>"
                                        {

# 3916 "<previous_module>"
                                                {
                                                        
# 3917 "<previous_module>"
static int __cs_local_exponential_backoff_loop;
                                                        
# 3918 "<previous_module>"
__cs_local_exponential_backoff_loop = 0;

# 3919 "<previous_module>"
                                                        {
                                                                
# 3920 "<previous_module>"
;
                                                                ;
                                                        }
                                                        
# 3922 "<previous_module>"
;
                                                        
# 3923 "<previous_module>"
__cs_local_exponential_backoff_loop++;

# 3924 "<previous_module>"
                                                        {
                                                                
# 3925 "<previous_module>"
;
                                                                ;
                                                        }
                                                        
# 3927 "<previous_module>"
;
                                                        
# 3928 "<previous_module>"
__cs_local_exponential_backoff_loop++;

# 3929 "<previous_module>"
                                                        {
                                                                
# 3930 "<previous_module>"
;
                                                                ;
                                                        }
                                                        
# 3932 "<previous_module>"
;
                                                        
# 3933 "<previous_module>"
__cs_local_exponential_backoff_loop++;
                                                        
# 3934 "<previous_module>"
tmain_123: IF(0,123,tmain_124)__CSEQ_removeindent;
                                                        
# 3935 "<previous_module>"
__CPROVER_assume(!(__cs_local_exponential_backoff_loop < 3));
                                                        
# 3936 "<previous_module>"
__exit_loop_45:
                                                        __CPROVER_assume(__cs_pc_cs[0] >= 124);

                                                        
# 3937 "<previous_module>"
;
                                                        ;
                                                        
# 3938 "<previous_module>"
__exit__exponential_backoff_5_7:
                                                        __CPROVER_assume(__cs_pc_cs[0] >= 124);

                                                        
# 3939 "<previous_module>"
;
                                                        ;
                                                }
                                                
# 3941 "<previous_module>"
;
                                                
# 3942 "<previous_module>"
tmain_124: IF(0,124,tmain_125)__CSEQ_removeindent;
                                                
# 3943 "<previous_module>"
__cs_mutex_lock(&library_lock, 0);
                                                
# 3944 "<previous_module>"
tmain_125: IF(0,125,tmain_126)__CSEQ_removeindent;
                                                
# 3945 "<previous_module>"
__cs_mutex_unlock(&library_lock, 0);
                                        }

                                        
# 3947 "<previous_module>"
__CPROVER_assume(__cs_pc_cs[0] >= 126);
                                        ;
                                        
# 3948 "<previous_module>"
__cs_local_lfds711_stack_pop_i++;
                                        
# 3949 "<previous_module>"
;
                                        ;
                                        
# 3950 "<previous_module>"
static _Bool __cs_local_lfds711_stack_pop___cs_tmp_if_cond_13;
                                        
# 3951 "<previous_module>"
__cs_local_lfds711_stack_pop___cs_tmp_if_cond_13 = __cs_local_lfds711_stack_pop_i > 1000;
                                        
# 3952 "<previous_module>"
if (__cs_local_lfds711_stack_pop___cs_tmp_if_cond_13)

# 3953 "<previous_module>"
                                        {
                                                
# 3954 "<previous_module>"
goto __exit_loop_42;
                                                ;
                                        }

                                        
# 3956 "<previous_module>"
;
                                }
                                
# 3958 "<previous_module>"
;
                                
# 3959 "<previous_module>"
if (
# 3960 "<previous_module>"
!(__cs_local_lfds711_stack_pop_result == 0))

# 3961 "<previous_module>"
                                {
                                        
# 3962 "<previous_module>"
goto __exit_loop_42;
                                        ;
                                }

                                
# 3964 "<previous_module>"
;

# 3965 "<previous_module>"
                                {
                                        
# 3966 "<previous_module>"
;
                                        ;
                                        
# 3967 "<previous_module>"
static _Bool __cs_local_lfds711_stack_pop___cs_tmp_if_cond_11;
                                        
# 3968 "<previous_module>"
__cs_local_lfds711_stack_pop___cs_tmp_if_cond_11 = __cs_local_lfds711_stack_pop_original_top[0] == 0;
                                        
# 3969 "<previous_module>"
if (__cs_local_lfds711_stack_pop___cs_tmp_if_cond_11)

# 3970 "<previous_module>"
                                        {
                                                
# 3971 "<previous_module>"
tmain_126: IF(0,126,tmain_127)__CSEQ_removeindent;
                                                
# 3972 "<previous_module>"
*__cs_param_lfds711_stack_pop_se = 0;
                                                
# 3973 "<previous_module>"
__cs_retval__lfds711_stack_pop_2 = 0;
                                                
# 3974 "<previous_module>"
goto __exit__lfds711_stack_pop_2_1;
                                                ;
                                        }

                                        
# 3976 "<previous_module>"
__CPROVER_assume(__cs_pc_cs[0] >= 127);
                                        ;
                                        
# 3977 "<previous_module>"
tmain_127: IF(0,127,tmain_128)__CSEQ_removeindent;
                                        
# 3978 "<previous_module>"
__cs_local_lfds711_stack_pop_new_top[1] = __cs_local_lfds711_stack_pop_original_top[1] + 1;
                                        
# 3979 "<previous_module>"
tmain_128: IF(0,128,tmain_129)__CSEQ_removeindent;
                                        
# 3980 "<previous_module>"
__cs_local_lfds711_stack_pop_new_top[0] = (*__cs_local_lfds711_stack_pop_original_top[0]).next;
                                        
# 3981 "<previous_module>"
tmain_129: IF(0,129,tmain_130)__CSEQ_removeindent;
                                        
# 3982 "<previous_module>"
__cs_mutex_lock(&library_lock, 0);
                                        
# 3983 "<previous_module>"
tmain_130: IF(0,130,tmain_131)__CSEQ_removeindent;
                                        
# 3984 "<previous_module>"
__cs_local_lfds711_stack_pop_result = __CSEQ_atomic_swap_stack_top(&(*__cs_param_lfds711_stack_pop_ss).top[0], &__cs_local_lfds711_stack_pop_original_top[0], &__cs_local_lfds711_stack_pop_new_top[0]);
                                        
# 3985 "<previous_module>"
tmain_131: IF(0,131,tmain_132)__CSEQ_removeindent;
                                        
# 3986 "<previous_module>"
__cs_mutex_unlock(&library_lock, 0);
                                        
# 3987 "<previous_module>"
;
                                        ;
                                        
# 3988 "<previous_module>"
static _Bool __cs_local_lfds711_stack_pop___cs_tmp_if_cond_12;
                                        
# 3989 "<previous_module>"
__cs_local_lfds711_stack_pop___cs_tmp_if_cond_12 = __cs_local_lfds711_stack_pop_result == 0;
                                        
# 3990 "<previous_module>"
if (__cs_local_lfds711_stack_pop___cs_tmp_if_cond_12)

# 3991 "<previous_module>"
                                        {

# 3992 "<previous_module>"
                                                {
                                                        
# 3993 "<previous_module>"
static int __cs_local_exponential_backoff_loop;
                                                        
# 3994 "<previous_module>"
__cs_local_exponential_backoff_loop = 0;

# 3995 "<previous_module>"
                                                        {
                                                                
# 3996 "<previous_module>"
;
                                                                ;
                                                        }
                                                        
# 3998 "<previous_module>"
;
                                                        
# 3999 "<previous_module>"
__cs_local_exponential_backoff_loop++;

# 4000 "<previous_module>"
                                                        {
                                                                
# 4001 "<previous_module>"
;
                                                                ;
                                                        }
                                                        
# 4003 "<previous_module>"
;
                                                        
# 4004 "<previous_module>"
__cs_local_exponential_backoff_loop++;

# 4005 "<previous_module>"
                                                        {
                                                                
# 4006 "<previous_module>"
;
                                                                ;
                                                        }
                                                        
# 4008 "<previous_module>"
;
                                                        
# 4009 "<previous_module>"
__cs_local_exponential_backoff_loop++;
                                                        
# 4010 "<previous_module>"
tmain_132: IF(0,132,tmain_133)__CSEQ_removeindent;
                                                        
# 4011 "<previous_module>"
__CPROVER_assume(!(__cs_local_exponential_backoff_loop < 3));
                                                        
# 4012 "<previous_module>"
__exit_loop_46:
                                                        __CPROVER_assume(__cs_pc_cs[0] >= 133);

                                                        
# 4013 "<previous_module>"
;
                                                        ;
                                                        
# 4014 "<previous_module>"
__exit__exponential_backoff_5_8:
                                                        __CPROVER_assume(__cs_pc_cs[0] >= 133);

                                                        
# 4015 "<previous_module>"
;
                                                        ;
                                                }
                                                
# 4017 "<previous_module>"
;
                                                
# 4018 "<previous_module>"
tmain_133: IF(0,133,tmain_134)__CSEQ_removeindent;
                                                
# 4019 "<previous_module>"
__cs_mutex_lock(&library_lock, 0);
                                                
# 4020 "<previous_module>"
tmain_134: IF(0,134,tmain_135)__CSEQ_removeindent;
                                                
# 4021 "<previous_module>"
__cs_mutex_unlock(&library_lock, 0);
                                        }

                                        
# 4023 "<previous_module>"
__CPROVER_assume(__cs_pc_cs[0] >= 135);
                                        ;
                                        
# 4024 "<previous_module>"
__cs_local_lfds711_stack_pop_i++;
                                        
# 4025 "<previous_module>"
;
                                        ;
                                        
# 4026 "<previous_module>"
static _Bool __cs_local_lfds711_stack_pop___cs_tmp_if_cond_13;
                                        
# 4027 "<previous_module>"
__cs_local_lfds711_stack_pop___cs_tmp_if_cond_13 = __cs_local_lfds711_stack_pop_i > 1000;
                                        
# 4028 "<previous_module>"
if (__cs_local_lfds711_stack_pop___cs_tmp_if_cond_13)

# 4029 "<previous_module>"
                                        {
                                                
# 4030 "<previous_module>"
goto __exit_loop_42;
                                                ;
                                        }

                                        
# 4032 "<previous_module>"
;
                                }
                                
# 4034 "<previous_module>"
;
                                
# 4035 "<previous_module>"
if (
# 4036 "<previous_module>"
!(__cs_local_lfds711_stack_pop_result == 0))

# 4037 "<previous_module>"
                                {
                                        
# 4038 "<previous_module>"
goto __exit_loop_42;
                                        ;
                                }

                                
# 4040 "<previous_module>"
;

# 4041 "<previous_module>"
                                {
                                        
# 4042 "<previous_module>"
;
                                        ;
                                        
# 4043 "<previous_module>"
static _Bool __cs_local_lfds711_stack_pop___cs_tmp_if_cond_11;
                                        
# 4044 "<previous_module>"
__cs_local_lfds711_stack_pop___cs_tmp_if_cond_11 = __cs_local_lfds711_stack_pop_original_top[0] == 0;
                                        
# 4045 "<previous_module>"
if (__cs_local_lfds711_stack_pop___cs_tmp_if_cond_11)

# 4046 "<previous_module>"
                                        {
                                                
# 4047 "<previous_module>"
tmain_135: IF(0,135,tmain_136)__CSEQ_removeindent;
                                                
# 4048 "<previous_module>"
*__cs_param_lfds711_stack_pop_se = 0;
                                                
# 4049 "<previous_module>"
__cs_retval__lfds711_stack_pop_2 = 0;
                                                
# 4050 "<previous_module>"
goto __exit__lfds711_stack_pop_2_1;
                                                ;
                                        }

                                        
# 4052 "<previous_module>"
__CPROVER_assume(__cs_pc_cs[0] >= 136);
                                        ;
                                        
# 4053 "<previous_module>"
tmain_136: IF(0,136,tmain_137)__CSEQ_removeindent;
                                        
# 4054 "<previous_module>"
__cs_local_lfds711_stack_pop_new_top[1] = __cs_local_lfds711_stack_pop_original_top[1] + 1;
                                        
# 4055 "<previous_module>"
tmain_137: IF(0,137,tmain_138)__CSEQ_removeindent;
                                        
# 4056 "<previous_module>"
__cs_local_lfds711_stack_pop_new_top[0] = (*__cs_local_lfds711_stack_pop_original_top[0]).next;
                                        
# 4057 "<previous_module>"
tmain_138: IF(0,138,tmain_139)__CSEQ_removeindent;
                                        
# 4058 "<previous_module>"
__cs_mutex_lock(&library_lock, 0);
                                        
# 4059 "<previous_module>"
tmain_139: IF(0,139,tmain_140)__CSEQ_removeindent;
                                        
# 4060 "<previous_module>"
__cs_local_lfds711_stack_pop_result = __CSEQ_atomic_swap_stack_top(&(*__cs_param_lfds711_stack_pop_ss).top[0], &__cs_local_lfds711_stack_pop_original_top[0], &__cs_local_lfds711_stack_pop_new_top[0]);
                                        
# 4061 "<previous_module>"
tmain_140: IF(0,140,tmain_141)__CSEQ_removeindent;
                                        
# 4062 "<previous_module>"
__cs_mutex_unlock(&library_lock, 0);
                                        
# 4063 "<previous_module>"
;
                                        ;
                                        
# 4064 "<previous_module>"
static _Bool __cs_local_lfds711_stack_pop___cs_tmp_if_cond_12;
                                        
# 4065 "<previous_module>"
__cs_local_lfds711_stack_pop___cs_tmp_if_cond_12 = __cs_local_lfds711_stack_pop_result == 0;
                                        
# 4066 "<previous_module>"
if (__cs_local_lfds711_stack_pop___cs_tmp_if_cond_12)

# 4067 "<previous_module>"
                                        {

# 4068 "<previous_module>"
                                                {
                                                        
# 4069 "<previous_module>"
static int __cs_local_exponential_backoff_loop;
                                                        
# 4070 "<previous_module>"
__cs_local_exponential_backoff_loop = 0;

# 4071 "<previous_module>"
                                                        {
                                                                
# 4072 "<previous_module>"
;
                                                                ;
                                                        }
                                                        
# 4074 "<previous_module>"
;
                                                        
# 4075 "<previous_module>"
__cs_local_exponential_backoff_loop++;

# 4076 "<previous_module>"
                                                        {
                                                                
# 4077 "<previous_module>"
;
                                                                ;
                                                        }
                                                        
# 4079 "<previous_module>"
;
                                                        
# 4080 "<previous_module>"
__cs_local_exponential_backoff_loop++;

# 4081 "<previous_module>"
                                                        {
                                                                
# 4082 "<previous_module>"
;
                                                                ;
                                                        }
                                                        
# 4084 "<previous_module>"
;
                                                        
# 4085 "<previous_module>"
__cs_local_exponential_backoff_loop++;
                                                        
# 4086 "<previous_module>"
tmain_141: IF(0,141,tmain_142)__CSEQ_removeindent;
                                                        
# 4087 "<previous_module>"
__CPROVER_assume(!(__cs_local_exponential_backoff_loop < 3));
                                                        
# 4088 "<previous_module>"
__exit_loop_47:
                                                        __CPROVER_assume(__cs_pc_cs[0] >= 142);

                                                        
# 4089 "<previous_module>"
;
                                                        ;
                                                        
# 4090 "<previous_module>"
__exit__exponential_backoff_5_9:
                                                        __CPROVER_assume(__cs_pc_cs[0] >= 142);

                                                        
# 4091 "<previous_module>"
;
                                                        ;
                                                }
                                                
# 4093 "<previous_module>"
;
                                                
# 4094 "<previous_module>"
tmain_142: IF(0,142,tmain_143)__CSEQ_removeindent;
                                                
# 4095 "<previous_module>"
__cs_mutex_lock(&library_lock, 0);
                                                
# 4096 "<previous_module>"
tmain_143: IF(0,143,tmain_144)__CSEQ_removeindent;
                                                
# 4097 "<previous_module>"
__cs_mutex_unlock(&library_lock, 0);
                                        }

                                        
# 4099 "<previous_module>"
__CPROVER_assume(__cs_pc_cs[0] >= 144);
                                        ;
                                        
# 4100 "<previous_module>"
__cs_local_lfds711_stack_pop_i++;
                                        
# 4101 "<previous_module>"
;
                                        ;
                                        
# 4102 "<previous_module>"
static _Bool __cs_local_lfds711_stack_pop___cs_tmp_if_cond_13;
                                        
# 4103 "<previous_module>"
__cs_local_lfds711_stack_pop___cs_tmp_if_cond_13 = __cs_local_lfds711_stack_pop_i > 1000;
                                        
# 4104 "<previous_module>"
if (__cs_local_lfds711_stack_pop___cs_tmp_if_cond_13)

# 4105 "<previous_module>"
                                        {
                                                
# 4106 "<previous_module>"
goto __exit_loop_42;
                                                ;
                                        }

                                        
# 4108 "<previous_module>"
;
                                }
                                
# 4110 "<previous_module>"
;
                                
# 4111 "<previous_module>"
tmain_144: IF(0,144,tmain_145)__CSEQ_removeindent;
                                
# 4112 "<previous_module>"
__CPROVER_assume(
# 4113 "<previous_module>"
!(__cs_local_lfds711_stack_pop_result == 0));
                                
# 4114 "<previous_module>"
__exit_loop_42:
                                __CPROVER_assume(__cs_pc_cs[0] >= 145);

                                
# 4115 "<previous_module>"
;
                                ;
                                
# 4116 "<previous_module>"
tmain_145: IF(0,145,tmain_146)__CSEQ_removeindent;
                                
# 4117 "<previous_module>"
*__cs_param_lfds711_stack_pop_se = __cs_local_lfds711_stack_pop_original_top[0];
                                
# 4118 "<previous_module>"
__cs_retval__lfds711_stack_pop_2 = __cs_local_lfds711_stack_pop_result;
                                
# 4119 "<previous_module>"
goto __exit__lfds711_stack_pop_2_1;
                                ;
                                
# 4120 "<previous_module>"
__exit__lfds711_stack_pop_2_1:
                                __CPROVER_assume(__cs_pc_cs[0] >= 146);

                                
# 4121 "<previous_module>"
;
                                ;
                        }
                        
# 4123 "<previous_module>"
;
                        
# 4124 "<previous_module>"
__cs_local_contains_res = __cs_retval__lfds711_stack_pop_2;
                        
# 4125 "<previous_module>"
;
                        ;
                        
# 4126 "<previous_module>"
static _Bool __cs_local_contains___cs_tmp_if_cond_20;
                        
# 4127 "<previous_module>"
__cs_local_contains___cs_tmp_if_cond_20 = __cs_local_contains_res == 0;
                        
# 4128 "<previous_module>"
if (__cs_local_contains___cs_tmp_if_cond_20)

# 4129 "<previous_module>"
                        {
                                
# 4130 "<previous_module>"
goto __exit_loop_31;
                                ;
                        }

                        
# 4132 "<previous_module>"
;
                        
# 4133 "<previous_module>"
tmain_146: IF(0,146,tmain_147)__CSEQ_removeindent;
                        
# 4134 "<previous_module>"
__cs_local_contains_datas[__cs_local_contains_actual_size] = (*__cs_local_contains_se).value;
                        
# 4135 "<previous_module>"
;
                        ;
                        
# 4136 "<previous_module>"
static _Bool __cs_local_contains___cs_tmp_if_cond_21;
                        
# 4137 "<previous_module>"
tmain_147: IF(0,147,tmain_148)__CSEQ_removeindent;
                        
# 4138 "<previous_module>"
__cs_local_contains___cs_tmp_if_cond_21 = (*__cs_local_contains_datas[__cs_local_contains_actual_size]).user_id == __cs_param_contains_id;
                        
# 4139 "<previous_module>"
if (__cs_local_contains___cs_tmp_if_cond_21)

# 4140 "<previous_module>"
                        {
                                
# 4141 "<previous_module>"
__cs_local_contains_found = 1;
                        }

                        
# 4143 "<previous_module>"
;
                        
# 4144 "<previous_module>"
__cs_local_contains_actual_size = __cs_local_contains_actual_size + 1;
                }
                
# 4146 "<previous_module>"
;
                
# 4147 "<previous_module>"
if (!(__cs_local_contains_actual_size < 2))

# 4148 "<previous_module>"
                {
                        
# 4149 "<previous_module>"
goto __exit_loop_31;
                        ;
                }

                
# 4151 "<previous_module>"
;

# 4152 "<previous_module>"
                {
                        
# 4153 "<previous_module>"
static int __cs_retval__lfds711_stack_pop_2;

# 4154 "<previous_module>"
                        {
                                
# 4155 "<previous_module>"
static struct lfds711_stack_state *__cs_param_lfds711_stack_pop_ss;
                                
# 4156 "<previous_module>"
tmain_148: IF(0,148,tmain_149)__CSEQ_removeindent;
                                
# 4157 "<previous_module>"
__cs_param_lfds711_stack_pop_ss = __cs_param_contains_s;
                                
# 4158 "<previous_module>"
static struct lfds711_stack_element **__cs_param_lfds711_stack_pop_se;
                                
# 4159 "<previous_module>"
tmain_149: IF(0,149,tmain_150)__CSEQ_removeindent;
                                
# 4160 "<previous_module>"
__cs_param_lfds711_stack_pop_se = &__cs_local_contains_se;
                                
# 4161 "<previous_module>"
static char unsigned __cs_local_lfds711_stack_pop_result;
                                
# 4162 "<previous_module>"
static lfds711_pal_uint_t __cs_local_lfds711_stack_pop_backoff_iteration;
                                
# 4163 "<previous_module>"
__cs_local_lfds711_stack_pop_backoff_iteration = 0;
                                
# 4164 "<previous_module>"
static struct lfds711_stack_element *__cs_local_lfds711_stack_pop_new_top[2];
                                
# 4165 "<previous_module>"
static struct lfds711_stack_element * volatile __cs_local_lfds711_stack_pop_original_top[2];
                                
# 4166 "<previous_module>"
;
                                ;
                                
# 4167 "<previous_module>"
static _Bool __cs_local_lfds711_stack_pop___cs_tmp_if_cond_6;
                                
# 4168 "<previous_module>"
tmain_150: IF(0,150,tmain_151)__CSEQ_removeindent;
                                
# 4169 "<previous_module>"
__cs_local_lfds711_stack_pop___cs_tmp_if_cond_6 = !(__cs_param_lfds711_stack_pop_ss != 0);
                                
# 4170 "<previous_module>"
if (__cs_local_lfds711_stack_pop___cs_tmp_if_cond_6)

# 4171 "<previous_module>"
                                {
                                        
# 4172 "<previous_module>"
static char *__cs_local_lfds711_stack_pop_c;
                                        
# 4173 "<previous_module>"
tmain_151: IF(0,151,tmain_152)__CSEQ_removeindent;
                                        
# 4174 "<previous_module>"
__cs_local_lfds711_stack_pop_c = 0;
                                        
# 4175 "<previous_module>"
tmain_152: IF(0,152,tmain_153)__CSEQ_removeindent;
                                        
# 4176 "<previous_module>"
*__cs_local_lfds711_stack_pop_c = 0;
                                }

                                
# 4178 "<previous_module>"
__CPROVER_assume(__cs_pc_cs[0] >= 153);
                                ;
                                
# 4179 "<previous_module>"
;
                                ;
                                
# 4180 "<previous_module>"
;
                                ;
                                
# 4181 "<previous_module>"
;
                                ;
                                
# 4182 "<previous_module>"
static _Bool __cs_local_lfds711_stack_pop___cs_tmp_if_cond_7;
                                
# 4183 "<previous_module>"
tmain_153: IF(0,153,tmain_154)__CSEQ_removeindent;
                                
# 4184 "<previous_module>"
__cs_local_lfds711_stack_pop___cs_tmp_if_cond_7 = !(__cs_param_lfds711_stack_pop_se != 0);
                                
# 4185 "<previous_module>"
if (__cs_local_lfds711_stack_pop___cs_tmp_if_cond_7)

# 4186 "<previous_module>"
                                {
                                        
# 4187 "<previous_module>"
static char *__cs_local_lfds711_stack_pop_c;
                                        
# 4188 "<previous_module>"
tmain_154: IF(0,154,tmain_155)__CSEQ_removeindent;
                                        
# 4189 "<previous_module>"
__cs_local_lfds711_stack_pop_c = 0;
                                        
# 4190 "<previous_module>"
tmain_155: IF(0,155,tmain_156)__CSEQ_removeindent;
                                        
# 4191 "<previous_module>"
*__cs_local_lfds711_stack_pop_c = 0;
                                }

                                
# 4193 "<previous_module>"
__CPROVER_assume(__cs_pc_cs[0] >= 156);
                                ;
                                
# 4194 "<previous_module>"
;
                                ;
                                
# 4195 "<previous_module>"
;
                                ;
                                
# 4196 "<previous_module>"
tmain_156: IF(0,156,tmain_157)__CSEQ_removeindent;
                                
# 4197 "<previous_module>"
__cs_mutex_lock(&library_lock, 0);
                                
# 4198 "<previous_module>"
tmain_157: IF(0,157,tmain_158)__CSEQ_removeindent;
                                
# 4199 "<previous_module>"
__cs_mutex_unlock(&library_lock, 0);
                                
# 4200 "<previous_module>"
tmain_158: IF(0,158,tmain_159)__CSEQ_removeindent;
                                
# 4201 "<previous_module>"
__cs_local_lfds711_stack_pop_original_top[1] = (*__cs_param_lfds711_stack_pop_ss).top[1];
                                
# 4202 "<previous_module>"
tmain_159: IF(0,159,tmain_160)__CSEQ_removeindent;
                                
# 4203 "<previous_module>"
__cs_local_lfds711_stack_pop_original_top[0] = (*__cs_param_lfds711_stack_pop_ss).top[0];
                                
# 4204 "<previous_module>"
static int __cs_local_lfds711_stack_pop_i;
                                
# 4205 "<previous_module>"
__cs_local_lfds711_stack_pop_i = 0;
                                
# 4206 "<previous_module>"
;
                                ;
                                
# 4207 "<previous_module>"
static int __cs_local_lfds711_stack_pop___cs_dowhile_onetime_1;
                                
# 4208 "<previous_module>"
__cs_local_lfds711_stack_pop___cs_dowhile_onetime_1 = 0;

# 4209 "<previous_module>"
                                {
                                        
# 4210 "<previous_module>"
;
                                        ;
                                        
# 4211 "<previous_module>"
static _Bool __cs_local_lfds711_stack_pop___cs_tmp_if_cond_8;
                                        
# 4212 "<previous_module>"
__cs_local_lfds711_stack_pop___cs_tmp_if_cond_8 = __cs_local_lfds711_stack_pop_original_top[0] == 0;
                                        
# 4213 "<previous_module>"
if (__cs_local_lfds711_stack_pop___cs_tmp_if_cond_8)

# 4214 "<previous_module>"
                                        {
                                                
# 4215 "<previous_module>"
tmain_160: IF(0,160,tmain_161)__CSEQ_removeindent;
                                                
# 4216 "<previous_module>"
*__cs_param_lfds711_stack_pop_se = 0;
                                                
# 4217 "<previous_module>"
__cs_retval__lfds711_stack_pop_2 = 0;
                                                
# 4218 "<previous_module>"
goto __exit__lfds711_stack_pop_2_2;
                                                ;
                                        }

                                        
# 4220 "<previous_module>"
__CPROVER_assume(__cs_pc_cs[0] >= 161);
                                        ;
                                        
# 4221 "<previous_module>"
tmain_161: IF(0,161,tmain_162)__CSEQ_removeindent;
                                        
# 4222 "<previous_module>"
__cs_local_lfds711_stack_pop_new_top[1] = __cs_local_lfds711_stack_pop_original_top[1] + 1;
                                        
# 4223 "<previous_module>"
tmain_162: IF(0,162,tmain_163)__CSEQ_removeindent;
                                        
# 4224 "<previous_module>"
__cs_local_lfds711_stack_pop_new_top[0] = (*__cs_local_lfds711_stack_pop_original_top[0]).next;
                                        
# 4225 "<previous_module>"
tmain_163: IF(0,163,tmain_164)__CSEQ_removeindent;
                                        
# 4226 "<previous_module>"
__cs_mutex_lock(&library_lock, 0);
                                        
# 4227 "<previous_module>"
tmain_164: IF(0,164,tmain_165)__CSEQ_removeindent;
                                        
# 4228 "<previous_module>"
__cs_local_lfds711_stack_pop_result = __CSEQ_atomic_swap_stack_top(&(*__cs_param_lfds711_stack_pop_ss).top[0], &__cs_local_lfds711_stack_pop_original_top[0], &__cs_local_lfds711_stack_pop_new_top[0]);
                                        
# 4229 "<previous_module>"
tmain_165: IF(0,165,tmain_166)__CSEQ_removeindent;
                                        
# 4230 "<previous_module>"
__cs_mutex_unlock(&library_lock, 0);
                                        
# 4231 "<previous_module>"
;
                                        ;
                                        
# 4232 "<previous_module>"
static _Bool __cs_local_lfds711_stack_pop___cs_tmp_if_cond_9;
                                        
# 4233 "<previous_module>"
__cs_local_lfds711_stack_pop___cs_tmp_if_cond_9 = __cs_local_lfds711_stack_pop_result == 0;
                                        
# 4234 "<previous_module>"
if (__cs_local_lfds711_stack_pop___cs_tmp_if_cond_9)

# 4235 "<previous_module>"
                                        {

# 4236 "<previous_module>"
                                                {
                                                        
# 4237 "<previous_module>"
static int __cs_local_exponential_backoff_loop;
                                                        
# 4238 "<previous_module>"
__cs_local_exponential_backoff_loop = 0;

# 4239 "<previous_module>"
                                                        {
                                                                
# 4240 "<previous_module>"
;
                                                                ;
                                                        }
                                                        
# 4242 "<previous_module>"
;
                                                        
# 4243 "<previous_module>"
__cs_local_exponential_backoff_loop++;

# 4244 "<previous_module>"
                                                        {
                                                                
# 4245 "<previous_module>"
;
                                                                ;
                                                        }
                                                        
# 4247 "<previous_module>"
;
                                                        
# 4248 "<previous_module>"
__cs_local_exponential_backoff_loop++;

# 4249 "<previous_module>"
                                                        {
                                                                
# 4250 "<previous_module>"
;
                                                                ;
                                                        }
                                                        
# 4252 "<previous_module>"
;
                                                        
# 4253 "<previous_module>"
__cs_local_exponential_backoff_loop++;
                                                        
# 4254 "<previous_module>"
tmain_166: IF(0,166,tmain_167)__CSEQ_removeindent;
                                                        
# 4255 "<previous_module>"
__CPROVER_assume(!(__cs_local_exponential_backoff_loop < 3));
                                                        
# 4256 "<previous_module>"
__exit_loop_49:
                                                        __CPROVER_assume(__cs_pc_cs[0] >= 167);

                                                        
# 4257 "<previous_module>"
;
                                                        ;
                                                        
# 4258 "<previous_module>"
__exit__exponential_backoff_4_2:
                                                        __CPROVER_assume(__cs_pc_cs[0] >= 167);

                                                        
# 4259 "<previous_module>"
;
                                                        ;
                                                }
                                                
# 4261 "<previous_module>"
;
                                                
# 4262 "<previous_module>"
tmain_167: IF(0,167,tmain_168)__CSEQ_removeindent;
                                                
# 4263 "<previous_module>"
__cs_mutex_lock(&library_lock, 0);
                                                
# 4264 "<previous_module>"
tmain_168: IF(0,168,tmain_169)__CSEQ_removeindent;
                                                
# 4265 "<previous_module>"
__cs_mutex_unlock(&library_lock, 0);
                                        }

                                        
# 4267 "<previous_module>"
__CPROVER_assume(__cs_pc_cs[0] >= 169);
                                        ;
                                        
# 4268 "<previous_module>"
__cs_local_lfds711_stack_pop_i++;
                                        
# 4269 "<previous_module>"
;
                                        ;
                                        
# 4270 "<previous_module>"
static _Bool __cs_local_lfds711_stack_pop___cs_tmp_if_cond_10;
                                        
# 4271 "<previous_module>"
__cs_local_lfds711_stack_pop___cs_tmp_if_cond_10 = __cs_local_lfds711_stack_pop_i > 1000;
                                        
# 4272 "<previous_module>"
if (__cs_local_lfds711_stack_pop___cs_tmp_if_cond_10)

# 4273 "<previous_module>"
                                        {
                                                
# 4274 "<previous_module>"
goto __exit_loop_48;
                                                ;
                                        }

                                        
# 4276 "<previous_module>"
;
                                }
                                
# 4278 "<previous_module>"
;
                                
# 4279 "<previous_module>"
__cs_local_lfds711_stack_pop___cs_dowhile_onetime_1++;
                                
# 4280 "<previous_module>"
tmain_169: IF(0,169,tmain_170)__CSEQ_removeindent;
                                
# 4281 "<previous_module>"
__CPROVER_assume(!(__cs_local_lfds711_stack_pop___cs_dowhile_onetime_1 < 1));
                                
# 4282 "<previous_module>"
__exit_loop_48:
                                __CPROVER_assume(__cs_pc_cs[0] >= 170);

                                
# 4283 "<previous_module>"
;
                                ;
                                
# 4284 "<previous_module>"
if (
# 4285 "<previous_module>"
!(__cs_local_lfds711_stack_pop_result == 0))

# 4286 "<previous_module>"
                                {
                                        
# 4287 "<previous_module>"
goto __exit_loop_50;
                                        ;
                                }

                                
# 4289 "<previous_module>"
;

# 4290 "<previous_module>"
                                {
                                        
# 4291 "<previous_module>"
;
                                        ;
                                        
# 4292 "<previous_module>"
static _Bool __cs_local_lfds711_stack_pop___cs_tmp_if_cond_11;
                                        
# 4293 "<previous_module>"
__cs_local_lfds711_stack_pop___cs_tmp_if_cond_11 = __cs_local_lfds711_stack_pop_original_top[0] == 0;
                                        
# 4294 "<previous_module>"
if (__cs_local_lfds711_stack_pop___cs_tmp_if_cond_11)

# 4295 "<previous_module>"
                                        {
                                                
# 4296 "<previous_module>"
tmain_170: IF(0,170,tmain_171)__CSEQ_removeindent;
                                                
# 4297 "<previous_module>"
*__cs_param_lfds711_stack_pop_se = 0;
                                                
# 4298 "<previous_module>"
__cs_retval__lfds711_stack_pop_2 = 0;
                                                
# 4299 "<previous_module>"
goto __exit__lfds711_stack_pop_2_2;
                                                ;
                                        }

                                        
# 4301 "<previous_module>"
__CPROVER_assume(__cs_pc_cs[0] >= 171);
                                        ;
                                        
# 4302 "<previous_module>"
tmain_171: IF(0,171,tmain_172)__CSEQ_removeindent;
                                        
# 4303 "<previous_module>"
__cs_local_lfds711_stack_pop_new_top[1] = __cs_local_lfds711_stack_pop_original_top[1] + 1;
                                        
# 4304 "<previous_module>"
tmain_172: IF(0,172,tmain_173)__CSEQ_removeindent;
                                        
# 4305 "<previous_module>"
__cs_local_lfds711_stack_pop_new_top[0] = (*__cs_local_lfds711_stack_pop_original_top[0]).next;
                                        
# 4306 "<previous_module>"
tmain_173: IF(0,173,tmain_174)__CSEQ_removeindent;
                                        
# 4307 "<previous_module>"
__cs_mutex_lock(&library_lock, 0);
                                        
# 4308 "<previous_module>"
tmain_174: IF(0,174,tmain_175)__CSEQ_removeindent;
                                        
# 4309 "<previous_module>"
__cs_local_lfds711_stack_pop_result = __CSEQ_atomic_swap_stack_top(&(*__cs_param_lfds711_stack_pop_ss).top[0], &__cs_local_lfds711_stack_pop_original_top[0], &__cs_local_lfds711_stack_pop_new_top[0]);
                                        
# 4310 "<previous_module>"
tmain_175: IF(0,175,tmain_176)__CSEQ_removeindent;
                                        
# 4311 "<previous_module>"
__cs_mutex_unlock(&library_lock, 0);
                                        
# 4312 "<previous_module>"
;
                                        ;
                                        
# 4313 "<previous_module>"
static _Bool __cs_local_lfds711_stack_pop___cs_tmp_if_cond_12;
                                        
# 4314 "<previous_module>"
__cs_local_lfds711_stack_pop___cs_tmp_if_cond_12 = __cs_local_lfds711_stack_pop_result == 0;
                                        
# 4315 "<previous_module>"
if (__cs_local_lfds711_stack_pop___cs_tmp_if_cond_12)

# 4316 "<previous_module>"
                                        {

# 4317 "<previous_module>"
                                                {
                                                        
# 4318 "<previous_module>"
static int __cs_local_exponential_backoff_loop;
                                                        
# 4319 "<previous_module>"
__cs_local_exponential_backoff_loop = 0;

# 4320 "<previous_module>"
                                                        {
                                                                
# 4321 "<previous_module>"
;
                                                                ;
                                                        }
                                                        
# 4323 "<previous_module>"
;
                                                        
# 4324 "<previous_module>"
__cs_local_exponential_backoff_loop++;

# 4325 "<previous_module>"
                                                        {
                                                                
# 4326 "<previous_module>"
;
                                                                ;
                                                        }
                                                        
# 4328 "<previous_module>"
;
                                                        
# 4329 "<previous_module>"
__cs_local_exponential_backoff_loop++;

# 4330 "<previous_module>"
                                                        {
                                                                
# 4331 "<previous_module>"
;
                                                                ;
                                                        }
                                                        
# 4333 "<previous_module>"
;
                                                        
# 4334 "<previous_module>"
__cs_local_exponential_backoff_loop++;
                                                        
# 4335 "<previous_module>"
tmain_176: IF(0,176,tmain_177)__CSEQ_removeindent;
                                                        
# 4336 "<previous_module>"
__CPROVER_assume(!(__cs_local_exponential_backoff_loop < 3));
                                                        
# 4337 "<previous_module>"
__exit_loop_51:
                                                        __CPROVER_assume(__cs_pc_cs[0] >= 177);

                                                        
# 4338 "<previous_module>"
;
                                                        ;
                                                        
# 4339 "<previous_module>"
__exit__exponential_backoff_5_10:
                                                        __CPROVER_assume(__cs_pc_cs[0] >= 177);

                                                        
# 4340 "<previous_module>"
;
                                                        ;
                                                }
                                                
# 4342 "<previous_module>"
;
                                                
# 4343 "<previous_module>"
tmain_177: IF(0,177,tmain_178)__CSEQ_removeindent;
                                                
# 4344 "<previous_module>"
__cs_mutex_lock(&library_lock, 0);
                                                
# 4345 "<previous_module>"
tmain_178: IF(0,178,tmain_179)__CSEQ_removeindent;
                                                
# 4346 "<previous_module>"
__cs_mutex_unlock(&library_lock, 0);
                                        }

                                        
# 4348 "<previous_module>"
__CPROVER_assume(__cs_pc_cs[0] >= 179);
                                        ;
                                        
# 4349 "<previous_module>"
__cs_local_lfds711_stack_pop_i++;
                                        
# 4350 "<previous_module>"
;
                                        ;
                                        
# 4351 "<previous_module>"
static _Bool __cs_local_lfds711_stack_pop___cs_tmp_if_cond_13;
                                        
# 4352 "<previous_module>"
__cs_local_lfds711_stack_pop___cs_tmp_if_cond_13 = __cs_local_lfds711_stack_pop_i > 1000;
                                        
# 4353 "<previous_module>"
if (__cs_local_lfds711_stack_pop___cs_tmp_if_cond_13)

# 4354 "<previous_module>"
                                        {
                                                
# 4355 "<previous_module>"
goto __exit_loop_50;
                                                ;
                                        }

                                        
# 4357 "<previous_module>"
;
                                }
                                
# 4359 "<previous_module>"
;
                                
# 4360 "<previous_module>"
if (
# 4361 "<previous_module>"
!(__cs_local_lfds711_stack_pop_result == 0))

# 4362 "<previous_module>"
                                {
                                        
# 4363 "<previous_module>"
goto __exit_loop_50;
                                        ;
                                }

                                
# 4365 "<previous_module>"
;

# 4366 "<previous_module>"
                                {
                                        
# 4367 "<previous_module>"
;
                                        ;
                                        
# 4368 "<previous_module>"
static _Bool __cs_local_lfds711_stack_pop___cs_tmp_if_cond_11;
                                        
# 4369 "<previous_module>"
__cs_local_lfds711_stack_pop___cs_tmp_if_cond_11 = __cs_local_lfds711_stack_pop_original_top[0] == 0;
                                        
# 4370 "<previous_module>"
if (__cs_local_lfds711_stack_pop___cs_tmp_if_cond_11)

# 4371 "<previous_module>"
                                        {
                                                
# 4372 "<previous_module>"
tmain_179: IF(0,179,tmain_180)__CSEQ_removeindent;
                                                
# 4373 "<previous_module>"
*__cs_param_lfds711_stack_pop_se = 0;
                                                
# 4374 "<previous_module>"
__cs_retval__lfds711_stack_pop_2 = 0;
                                                
# 4375 "<previous_module>"
goto __exit__lfds711_stack_pop_2_2;
                                                ;
                                        }

                                        
# 4377 "<previous_module>"
__CPROVER_assume(__cs_pc_cs[0] >= 180);
                                        ;
                                        
# 4378 "<previous_module>"
tmain_180: IF(0,180,tmain_181)__CSEQ_removeindent;
                                        
# 4379 "<previous_module>"
__cs_local_lfds711_stack_pop_new_top[1] = __cs_local_lfds711_stack_pop_original_top[1] + 1;
                                        
# 4380 "<previous_module>"
tmain_181: IF(0,181,tmain_182)__CSEQ_removeindent;
                                        
# 4381 "<previous_module>"
__cs_local_lfds711_stack_pop_new_top[0] = (*__cs_local_lfds711_stack_pop_original_top[0]).next;
                                        
# 4382 "<previous_module>"
tmain_182: IF(0,182,tmain_183)__CSEQ_removeindent;
                                        
# 4383 "<previous_module>"
__cs_mutex_lock(&library_lock, 0);
                                        
# 4384 "<previous_module>"
tmain_183: IF(0,183,tmain_184)__CSEQ_removeindent;
                                        
# 4385 "<previous_module>"
__cs_local_lfds711_stack_pop_result = __CSEQ_atomic_swap_stack_top(&(*__cs_param_lfds711_stack_pop_ss).top[0], &__cs_local_lfds711_stack_pop_original_top[0], &__cs_local_lfds711_stack_pop_new_top[0]);
                                        
# 4386 "<previous_module>"
tmain_184: IF(0,184,tmain_185)__CSEQ_removeindent;
                                        
# 4387 "<previous_module>"
__cs_mutex_unlock(&library_lock, 0);
                                        
# 4388 "<previous_module>"
;
                                        ;
                                        
# 4389 "<previous_module>"
static _Bool __cs_local_lfds711_stack_pop___cs_tmp_if_cond_12;
                                        
# 4390 "<previous_module>"
__cs_local_lfds711_stack_pop___cs_tmp_if_cond_12 = __cs_local_lfds711_stack_pop_result == 0;
                                        
# 4391 "<previous_module>"
if (__cs_local_lfds711_stack_pop___cs_tmp_if_cond_12)

# 4392 "<previous_module>"
                                        {

# 4393 "<previous_module>"
                                                {
                                                        
# 4394 "<previous_module>"
static int __cs_local_exponential_backoff_loop;
                                                        
# 4395 "<previous_module>"
__cs_local_exponential_backoff_loop = 0;

# 4396 "<previous_module>"
                                                        {
                                                                
# 4397 "<previous_module>"
;
                                                                ;
                                                        }
                                                        
# 4399 "<previous_module>"
;
                                                        
# 4400 "<previous_module>"
__cs_local_exponential_backoff_loop++;

# 4401 "<previous_module>"
                                                        {
                                                                
# 4402 "<previous_module>"
;
                                                                ;
                                                        }
                                                        
# 4404 "<previous_module>"
;
                                                        
# 4405 "<previous_module>"
__cs_local_exponential_backoff_loop++;

# 4406 "<previous_module>"
                                                        {
                                                                
# 4407 "<previous_module>"
;
                                                                ;
                                                        }
                                                        
# 4409 "<previous_module>"
;
                                                        
# 4410 "<previous_module>"
__cs_local_exponential_backoff_loop++;
                                                        
# 4411 "<previous_module>"
tmain_185: IF(0,185,tmain_186)__CSEQ_removeindent;
                                                        
# 4412 "<previous_module>"
__CPROVER_assume(!(__cs_local_exponential_backoff_loop < 3));
                                                        
# 4413 "<previous_module>"
__exit_loop_52:
                                                        __CPROVER_assume(__cs_pc_cs[0] >= 186);

                                                        
# 4414 "<previous_module>"
;
                                                        ;
                                                        
# 4415 "<previous_module>"
__exit__exponential_backoff_5_11:
                                                        __CPROVER_assume(__cs_pc_cs[0] >= 186);

                                                        
# 4416 "<previous_module>"
;
                                                        ;
                                                }
                                                
# 4418 "<previous_module>"
;
                                                
# 4419 "<previous_module>"
tmain_186: IF(0,186,tmain_187)__CSEQ_removeindent;
                                                
# 4420 "<previous_module>"
__cs_mutex_lock(&library_lock, 0);
                                                
# 4421 "<previous_module>"
tmain_187: IF(0,187,tmain_188)__CSEQ_removeindent;
                                                
# 4422 "<previous_module>"
__cs_mutex_unlock(&library_lock, 0);
                                        }

                                        
# 4424 "<previous_module>"
__CPROVER_assume(__cs_pc_cs[0] >= 188);
                                        ;
                                        
# 4425 "<previous_module>"
__cs_local_lfds711_stack_pop_i++;
                                        
# 4426 "<previous_module>"
;
                                        ;
                                        
# 4427 "<previous_module>"
static _Bool __cs_local_lfds711_stack_pop___cs_tmp_if_cond_13;
                                        
# 4428 "<previous_module>"
__cs_local_lfds711_stack_pop___cs_tmp_if_cond_13 = __cs_local_lfds711_stack_pop_i > 1000;
                                        
# 4429 "<previous_module>"
if (__cs_local_lfds711_stack_pop___cs_tmp_if_cond_13)

# 4430 "<previous_module>"
                                        {
                                                
# 4431 "<previous_module>"
goto __exit_loop_50;
                                                ;
                                        }

                                        
# 4433 "<previous_module>"
;
                                }
                                
# 4435 "<previous_module>"
;
                                
# 4436 "<previous_module>"
if (
# 4437 "<previous_module>"
!(__cs_local_lfds711_stack_pop_result == 0))

# 4438 "<previous_module>"
                                {
                                        
# 4439 "<previous_module>"
goto __exit_loop_50;
                                        ;
                                }

                                
# 4441 "<previous_module>"
;

# 4442 "<previous_module>"
                                {
                                        
# 4443 "<previous_module>"
;
                                        ;
                                        
# 4444 "<previous_module>"
static _Bool __cs_local_lfds711_stack_pop___cs_tmp_if_cond_11;
                                        
# 4445 "<previous_module>"
__cs_local_lfds711_stack_pop___cs_tmp_if_cond_11 = __cs_local_lfds711_stack_pop_original_top[0] == 0;
                                        
# 4446 "<previous_module>"
if (__cs_local_lfds711_stack_pop___cs_tmp_if_cond_11)

# 4447 "<previous_module>"
                                        {
                                                
# 4448 "<previous_module>"
tmain_188: IF(0,188,tmain_189)__CSEQ_removeindent;
                                                
# 4449 "<previous_module>"
*__cs_param_lfds711_stack_pop_se = 0;
                                                
# 4450 "<previous_module>"
__cs_retval__lfds711_stack_pop_2 = 0;
                                                
# 4451 "<previous_module>"
goto __exit__lfds711_stack_pop_2_2;
                                                ;
                                        }

                                        
# 4453 "<previous_module>"
__CPROVER_assume(__cs_pc_cs[0] >= 189);
                                        ;
                                        
# 4454 "<previous_module>"
tmain_189: IF(0,189,tmain_190)__CSEQ_removeindent;
                                        
# 4455 "<previous_module>"
__cs_local_lfds711_stack_pop_new_top[1] = __cs_local_lfds711_stack_pop_original_top[1] + 1;
                                        
# 4456 "<previous_module>"
tmain_190: IF(0,190,tmain_191)__CSEQ_removeindent;
                                        
# 4457 "<previous_module>"
__cs_local_lfds711_stack_pop_new_top[0] = (*__cs_local_lfds711_stack_pop_original_top[0]).next;
                                        
# 4458 "<previous_module>"
tmain_191: IF(0,191,tmain_192)__CSEQ_removeindent;
                                        
# 4459 "<previous_module>"
__cs_mutex_lock(&library_lock, 0);
                                        
# 4460 "<previous_module>"
tmain_192: IF(0,192,tmain_193)__CSEQ_removeindent;
                                        
# 4461 "<previous_module>"
__cs_local_lfds711_stack_pop_result = __CSEQ_atomic_swap_stack_top(&(*__cs_param_lfds711_stack_pop_ss).top[0], &__cs_local_lfds711_stack_pop_original_top[0], &__cs_local_lfds711_stack_pop_new_top[0]);
                                        
# 4462 "<previous_module>"
tmain_193: IF(0,193,tmain_194)__CSEQ_removeindent;
                                        
# 4463 "<previous_module>"
__cs_mutex_unlock(&library_lock, 0);
                                        
# 4464 "<previous_module>"
;
                                        ;
                                        
# 4465 "<previous_module>"
static _Bool __cs_local_lfds711_stack_pop___cs_tmp_if_cond_12;
                                        
# 4466 "<previous_module>"
__cs_local_lfds711_stack_pop___cs_tmp_if_cond_12 = __cs_local_lfds711_stack_pop_result == 0;
                                        
# 4467 "<previous_module>"
if (__cs_local_lfds711_stack_pop___cs_tmp_if_cond_12)

# 4468 "<previous_module>"
                                        {

# 4469 "<previous_module>"
                                                {
                                                        
# 4470 "<previous_module>"
static int __cs_local_exponential_backoff_loop;
                                                        
# 4471 "<previous_module>"
__cs_local_exponential_backoff_loop = 0;

# 4472 "<previous_module>"
                                                        {
                                                                
# 4473 "<previous_module>"
;
                                                                ;
                                                        }
                                                        
# 4475 "<previous_module>"
;
                                                        
# 4476 "<previous_module>"
__cs_local_exponential_backoff_loop++;

# 4477 "<previous_module>"
                                                        {
                                                                
# 4478 "<previous_module>"
;
                                                                ;
                                                        }
                                                        
# 4480 "<previous_module>"
;
                                                        
# 4481 "<previous_module>"
__cs_local_exponential_backoff_loop++;

# 4482 "<previous_module>"
                                                        {
                                                                
# 4483 "<previous_module>"
;
                                                                ;
                                                        }
                                                        
# 4485 "<previous_module>"
;
                                                        
# 4486 "<previous_module>"
__cs_local_exponential_backoff_loop++;
                                                        
# 4487 "<previous_module>"
tmain_194: IF(0,194,tmain_195)__CSEQ_removeindent;
                                                        
# 4488 "<previous_module>"
__CPROVER_assume(!(__cs_local_exponential_backoff_loop < 3));
                                                        
# 4489 "<previous_module>"
__exit_loop_53:
                                                        __CPROVER_assume(__cs_pc_cs[0] >= 195);

                                                        
# 4490 "<previous_module>"
;
                                                        ;
                                                        
# 4491 "<previous_module>"
__exit__exponential_backoff_5_12:
                                                        __CPROVER_assume(__cs_pc_cs[0] >= 195);

                                                        
# 4492 "<previous_module>"
;
                                                        ;
                                                }
                                                
# 4494 "<previous_module>"
;
                                                
# 4495 "<previous_module>"
tmain_195: IF(0,195,tmain_196)__CSEQ_removeindent;
                                                
# 4496 "<previous_module>"
__cs_mutex_lock(&library_lock, 0);
                                                
# 4497 "<previous_module>"
tmain_196: IF(0,196,tmain_197)__CSEQ_removeindent;
                                                
# 4498 "<previous_module>"
__cs_mutex_unlock(&library_lock, 0);
                                        }

                                        
# 4500 "<previous_module>"
__CPROVER_assume(__cs_pc_cs[0] >= 197);
                                        ;
                                        
# 4501 "<previous_module>"
__cs_local_lfds711_stack_pop_i++;
                                        
# 4502 "<previous_module>"
;
                                        ;
                                        
# 4503 "<previous_module>"
static _Bool __cs_local_lfds711_stack_pop___cs_tmp_if_cond_13;
                                        
# 4504 "<previous_module>"
__cs_local_lfds711_stack_pop___cs_tmp_if_cond_13 = __cs_local_lfds711_stack_pop_i > 1000;
                                        
# 4505 "<previous_module>"
if (__cs_local_lfds711_stack_pop___cs_tmp_if_cond_13)

# 4506 "<previous_module>"
                                        {
                                                
# 4507 "<previous_module>"
goto __exit_loop_50;
                                                ;
                                        }

                                        
# 4509 "<previous_module>"
;
                                }
                                
# 4511 "<previous_module>"
;
                                
# 4512 "<previous_module>"
if (
# 4513 "<previous_module>"
!(__cs_local_lfds711_stack_pop_result == 0))

# 4514 "<previous_module>"
                                {
                                        
# 4515 "<previous_module>"
goto __exit_loop_50;
                                        ;
                                }

                                
# 4517 "<previous_module>"
;

# 4518 "<previous_module>"
                                {
                                        
# 4519 "<previous_module>"
;
                                        ;
                                        
# 4520 "<previous_module>"
static _Bool __cs_local_lfds711_stack_pop___cs_tmp_if_cond_11;
                                        
# 4521 "<previous_module>"
__cs_local_lfds711_stack_pop___cs_tmp_if_cond_11 = __cs_local_lfds711_stack_pop_original_top[0] == 0;
                                        
# 4522 "<previous_module>"
if (__cs_local_lfds711_stack_pop___cs_tmp_if_cond_11)

# 4523 "<previous_module>"
                                        {
                                                
# 4524 "<previous_module>"
tmain_197: IF(0,197,tmain_198)__CSEQ_removeindent;
                                                
# 4525 "<previous_module>"
*__cs_param_lfds711_stack_pop_se = 0;
                                                
# 4526 "<previous_module>"
__cs_retval__lfds711_stack_pop_2 = 0;
                                                
# 4527 "<previous_module>"
goto __exit__lfds711_stack_pop_2_2;
                                                ;
                                        }

                                        
# 4529 "<previous_module>"
__CPROVER_assume(__cs_pc_cs[0] >= 198);
                                        ;
                                        
# 4530 "<previous_module>"
tmain_198: IF(0,198,tmain_199)__CSEQ_removeindent;
                                        
# 4531 "<previous_module>"
__cs_local_lfds711_stack_pop_new_top[1] = __cs_local_lfds711_stack_pop_original_top[1] + 1;
                                        
# 4532 "<previous_module>"
tmain_199: IF(0,199,tmain_200)__CSEQ_removeindent;
                                        
# 4533 "<previous_module>"
__cs_local_lfds711_stack_pop_new_top[0] = (*__cs_local_lfds711_stack_pop_original_top[0]).next;
                                        
# 4534 "<previous_module>"
tmain_200: IF(0,200,tmain_201)__CSEQ_removeindent;
                                        
# 4535 "<previous_module>"
__cs_mutex_lock(&library_lock, 0);
                                        
# 4536 "<previous_module>"
tmain_201: IF(0,201,tmain_202)__CSEQ_removeindent;
                                        
# 4537 "<previous_module>"
__cs_local_lfds711_stack_pop_result = __CSEQ_atomic_swap_stack_top(&(*__cs_param_lfds711_stack_pop_ss).top[0], &__cs_local_lfds711_stack_pop_original_top[0], &__cs_local_lfds711_stack_pop_new_top[0]);
                                        
# 4538 "<previous_module>"
tmain_202: IF(0,202,tmain_203)__CSEQ_removeindent;
                                        
# 4539 "<previous_module>"
__cs_mutex_unlock(&library_lock, 0);
                                        
# 4540 "<previous_module>"
;
                                        ;
                                        
# 4541 "<previous_module>"
static _Bool __cs_local_lfds711_stack_pop___cs_tmp_if_cond_12;
                                        
# 4542 "<previous_module>"
__cs_local_lfds711_stack_pop___cs_tmp_if_cond_12 = __cs_local_lfds711_stack_pop_result == 0;
                                        
# 4543 "<previous_module>"
if (__cs_local_lfds711_stack_pop___cs_tmp_if_cond_12)

# 4544 "<previous_module>"
                                        {

# 4545 "<previous_module>"
                                                {
                                                        
# 4546 "<previous_module>"
static int __cs_local_exponential_backoff_loop;
                                                        
# 4547 "<previous_module>"
__cs_local_exponential_backoff_loop = 0;

# 4548 "<previous_module>"
                                                        {
                                                                
# 4549 "<previous_module>"
;
                                                                ;
                                                        }
                                                        
# 4551 "<previous_module>"
;
                                                        
# 4552 "<previous_module>"
__cs_local_exponential_backoff_loop++;

# 4553 "<previous_module>"
                                                        {
                                                                
# 4554 "<previous_module>"
;
                                                                ;
                                                        }
                                                        
# 4556 "<previous_module>"
;
                                                        
# 4557 "<previous_module>"
__cs_local_exponential_backoff_loop++;

# 4558 "<previous_module>"
                                                        {
                                                                
# 4559 "<previous_module>"
;
                                                                ;
                                                        }
                                                        
# 4561 "<previous_module>"
;
                                                        
# 4562 "<previous_module>"
__cs_local_exponential_backoff_loop++;
                                                        
# 4563 "<previous_module>"
tmain_203: IF(0,203,tmain_204)__CSEQ_removeindent;
                                                        
# 4564 "<previous_module>"
__CPROVER_assume(!(__cs_local_exponential_backoff_loop < 3));
                                                        
# 4565 "<previous_module>"
__exit_loop_54:
                                                        __CPROVER_assume(__cs_pc_cs[0] >= 204);

                                                        
# 4566 "<previous_module>"
;
                                                        ;
                                                        
# 4567 "<previous_module>"
__exit__exponential_backoff_5_13:
                                                        __CPROVER_assume(__cs_pc_cs[0] >= 204);

                                                        
# 4568 "<previous_module>"
;
                                                        ;
                                                }
                                                
# 4570 "<previous_module>"
;
                                                
# 4571 "<previous_module>"
tmain_204: IF(0,204,tmain_205)__CSEQ_removeindent;
                                                
# 4572 "<previous_module>"
__cs_mutex_lock(&library_lock, 0);
                                                
# 4573 "<previous_module>"
tmain_205: IF(0,205,tmain_206)__CSEQ_removeindent;
                                                
# 4574 "<previous_module>"
__cs_mutex_unlock(&library_lock, 0);
                                        }

                                        
# 4576 "<previous_module>"
__CPROVER_assume(__cs_pc_cs[0] >= 206);
                                        ;
                                        
# 4577 "<previous_module>"
__cs_local_lfds711_stack_pop_i++;
                                        
# 4578 "<previous_module>"
;
                                        ;
                                        
# 4579 "<previous_module>"
static _Bool __cs_local_lfds711_stack_pop___cs_tmp_if_cond_13;
                                        
# 4580 "<previous_module>"
__cs_local_lfds711_stack_pop___cs_tmp_if_cond_13 = __cs_local_lfds711_stack_pop_i > 1000;
                                        
# 4581 "<previous_module>"
if (__cs_local_lfds711_stack_pop___cs_tmp_if_cond_13)

# 4582 "<previous_module>"
                                        {
                                                
# 4583 "<previous_module>"
goto __exit_loop_50;
                                                ;
                                        }

                                        
# 4585 "<previous_module>"
;
                                }
                                
# 4587 "<previous_module>"
;
                                
# 4588 "<previous_module>"
if (
# 4589 "<previous_module>"
!(__cs_local_lfds711_stack_pop_result == 0))

# 4590 "<previous_module>"
                                {
                                        
# 4591 "<previous_module>"
goto __exit_loop_50;
                                        ;
                                }

                                
# 4593 "<previous_module>"
;

# 4594 "<previous_module>"
                                {
                                        
# 4595 "<previous_module>"
;
                                        ;
                                        
# 4596 "<previous_module>"
static _Bool __cs_local_lfds711_stack_pop___cs_tmp_if_cond_11;
                                        
# 4597 "<previous_module>"
__cs_local_lfds711_stack_pop___cs_tmp_if_cond_11 = __cs_local_lfds711_stack_pop_original_top[0] == 0;
                                        
# 4598 "<previous_module>"
if (__cs_local_lfds711_stack_pop___cs_tmp_if_cond_11)

# 4599 "<previous_module>"
                                        {
                                                
# 4600 "<previous_module>"
tmain_206: IF(0,206,tmain_207)__CSEQ_removeindent;
                                                
# 4601 "<previous_module>"
*__cs_param_lfds711_stack_pop_se = 0;
                                                
# 4602 "<previous_module>"
__cs_retval__lfds711_stack_pop_2 = 0;
                                                
# 4603 "<previous_module>"
goto __exit__lfds711_stack_pop_2_2;
                                                ;
                                        }

                                        
# 4605 "<previous_module>"
__CPROVER_assume(__cs_pc_cs[0] >= 207);
                                        ;
                                        
# 4606 "<previous_module>"
tmain_207: IF(0,207,tmain_208)__CSEQ_removeindent;
                                        
# 4607 "<previous_module>"
__cs_local_lfds711_stack_pop_new_top[1] = __cs_local_lfds711_stack_pop_original_top[1] + 1;
                                        
# 4608 "<previous_module>"
tmain_208: IF(0,208,tmain_209)__CSEQ_removeindent;
                                        
# 4609 "<previous_module>"
__cs_local_lfds711_stack_pop_new_top[0] = (*__cs_local_lfds711_stack_pop_original_top[0]).next;
                                        
# 4610 "<previous_module>"
tmain_209: IF(0,209,tmain_210)__CSEQ_removeindent;
                                        
# 4611 "<previous_module>"
__cs_mutex_lock(&library_lock, 0);
                                        
# 4612 "<previous_module>"
tmain_210: IF(0,210,tmain_211)__CSEQ_removeindent;
                                        
# 4613 "<previous_module>"
__cs_local_lfds711_stack_pop_result = __CSEQ_atomic_swap_stack_top(&(*__cs_param_lfds711_stack_pop_ss).top[0], &__cs_local_lfds711_stack_pop_original_top[0], &__cs_local_lfds711_stack_pop_new_top[0]);
                                        
# 4614 "<previous_module>"
tmain_211: IF(0,211,tmain_212)__CSEQ_removeindent;
                                        
# 4615 "<previous_module>"
__cs_mutex_unlock(&library_lock, 0);
                                        
# 4616 "<previous_module>"
;
                                        ;
                                        
# 4617 "<previous_module>"
static _Bool __cs_local_lfds711_stack_pop___cs_tmp_if_cond_12;
                                        
# 4618 "<previous_module>"
__cs_local_lfds711_stack_pop___cs_tmp_if_cond_12 = __cs_local_lfds711_stack_pop_result == 0;
                                        
# 4619 "<previous_module>"
if (__cs_local_lfds711_stack_pop___cs_tmp_if_cond_12)

# 4620 "<previous_module>"
                                        {

# 4621 "<previous_module>"
                                                {
                                                        
# 4622 "<previous_module>"
static int __cs_local_exponential_backoff_loop;
                                                        
# 4623 "<previous_module>"
__cs_local_exponential_backoff_loop = 0;

# 4624 "<previous_module>"
                                                        {
                                                                
# 4625 "<previous_module>"
;
                                                                ;
                                                        }
                                                        
# 4627 "<previous_module>"
;
                                                        
# 4628 "<previous_module>"
__cs_local_exponential_backoff_loop++;

# 4629 "<previous_module>"
                                                        {
                                                                
# 4630 "<previous_module>"
;
                                                                ;
                                                        }
                                                        
# 4632 "<previous_module>"
;
                                                        
# 4633 "<previous_module>"
__cs_local_exponential_backoff_loop++;

# 4634 "<previous_module>"
                                                        {
                                                                
# 4635 "<previous_module>"
;
                                                                ;
                                                        }
                                                        
# 4637 "<previous_module>"
;
                                                        
# 4638 "<previous_module>"
__cs_local_exponential_backoff_loop++;
                                                        
# 4639 "<previous_module>"
tmain_212: IF(0,212,tmain_213)__CSEQ_removeindent;
                                                        
# 4640 "<previous_module>"
__CPROVER_assume(!(__cs_local_exponential_backoff_loop < 3));
                                                        
# 4641 "<previous_module>"
__exit_loop_55:
                                                        __CPROVER_assume(__cs_pc_cs[0] >= 213);

                                                        
# 4642 "<previous_module>"
;
                                                        ;
                                                        
# 4643 "<previous_module>"
__exit__exponential_backoff_5_14:
                                                        __CPROVER_assume(__cs_pc_cs[0] >= 213);

                                                        
# 4644 "<previous_module>"
;
                                                        ;
                                                }
                                                
# 4646 "<previous_module>"
;
                                                
# 4647 "<previous_module>"
tmain_213: IF(0,213,tmain_214)__CSEQ_removeindent;
                                                
# 4648 "<previous_module>"
__cs_mutex_lock(&library_lock, 0);
                                                
# 4649 "<previous_module>"
tmain_214: IF(0,214,tmain_215)__CSEQ_removeindent;
                                                
# 4650 "<previous_module>"
__cs_mutex_unlock(&library_lock, 0);
                                        }

                                        
# 4652 "<previous_module>"
__CPROVER_assume(__cs_pc_cs[0] >= 215);
                                        ;
                                        
# 4653 "<previous_module>"
__cs_local_lfds711_stack_pop_i++;
                                        
# 4654 "<previous_module>"
;
                                        ;
                                        
# 4655 "<previous_module>"
static _Bool __cs_local_lfds711_stack_pop___cs_tmp_if_cond_13;
                                        
# 4656 "<previous_module>"
__cs_local_lfds711_stack_pop___cs_tmp_if_cond_13 = __cs_local_lfds711_stack_pop_i > 1000;
                                        
# 4657 "<previous_module>"
if (__cs_local_lfds711_stack_pop___cs_tmp_if_cond_13)

# 4658 "<previous_module>"
                                        {
                                                
# 4659 "<previous_module>"
goto __exit_loop_50;
                                                ;
                                        }

                                        
# 4661 "<previous_module>"
;
                                }
                                
# 4663 "<previous_module>"
;
                                
# 4664 "<previous_module>"
tmain_215: IF(0,215,tmain_216)__CSEQ_removeindent;
                                
# 4665 "<previous_module>"
__CPROVER_assume(
# 4666 "<previous_module>"
!(__cs_local_lfds711_stack_pop_result == 0));
                                
# 4667 "<previous_module>"
__exit_loop_50:
                                __CPROVER_assume(__cs_pc_cs[0] >= 216);

                                
# 4668 "<previous_module>"
;
                                ;
                                
# 4669 "<previous_module>"
tmain_216: IF(0,216,tmain_217)__CSEQ_removeindent;
                                
# 4670 "<previous_module>"
*__cs_param_lfds711_stack_pop_se = __cs_local_lfds711_stack_pop_original_top[0];
                                
# 4671 "<previous_module>"
__cs_retval__lfds711_stack_pop_2 = __cs_local_lfds711_stack_pop_result;
                                
# 4672 "<previous_module>"
goto __exit__lfds711_stack_pop_2_2;
                                ;
                                
# 4673 "<previous_module>"
__exit__lfds711_stack_pop_2_2:
                                __CPROVER_assume(__cs_pc_cs[0] >= 217);

                                
# 4674 "<previous_module>"
;
                                ;
                        }
                        
# 4676 "<previous_module>"
;
                        
# 4677 "<previous_module>"
__cs_local_contains_res = __cs_retval__lfds711_stack_pop_2;
                        
# 4678 "<previous_module>"
;
                        ;
                        
# 4679 "<previous_module>"
static _Bool __cs_local_contains___cs_tmp_if_cond_20;
                        
# 4680 "<previous_module>"
__cs_local_contains___cs_tmp_if_cond_20 = __cs_local_contains_res == 0;
                        
# 4681 "<previous_module>"
if (__cs_local_contains___cs_tmp_if_cond_20)

# 4682 "<previous_module>"
                        {
                                
# 4683 "<previous_module>"
goto __exit_loop_31;
                                ;
                        }

                        
# 4685 "<previous_module>"
;
                        
# 4686 "<previous_module>"
tmain_217: IF(0,217,tmain_218)__CSEQ_removeindent;
                        
# 4687 "<previous_module>"
__cs_local_contains_datas[__cs_local_contains_actual_size] = (*__cs_local_contains_se).value;
                        
# 4688 "<previous_module>"
;
                        ;
                        
# 4689 "<previous_module>"
static _Bool __cs_local_contains___cs_tmp_if_cond_21;
                        
# 4690 "<previous_module>"
tmain_218: IF(0,218,tmain_219)__CSEQ_removeindent;
                        
# 4691 "<previous_module>"
__cs_local_contains___cs_tmp_if_cond_21 = (*__cs_local_contains_datas[__cs_local_contains_actual_size]).user_id == __cs_param_contains_id;
                        
# 4692 "<previous_module>"
if (__cs_local_contains___cs_tmp_if_cond_21)

# 4693 "<previous_module>"
                        {
                                
# 4694 "<previous_module>"
__cs_local_contains_found = 1;
                        }

                        
# 4696 "<previous_module>"
;
                        
# 4697 "<previous_module>"
__cs_local_contains_actual_size = __cs_local_contains_actual_size + 1;
                }
                
# 4699 "<previous_module>"
;
                
# 4700 "<previous_module>"
if (!(__cs_local_contains_actual_size < 2))

# 4701 "<previous_module>"
                {
                        
# 4702 "<previous_module>"
goto __exit_loop_31;
                        ;
                }

                
# 4704 "<previous_module>"
;

# 4705 "<previous_module>"
                {
                        
# 4706 "<previous_module>"
static int __cs_retval__lfds711_stack_pop_2;

# 4707 "<previous_module>"
                        {
                                
# 4708 "<previous_module>"
static struct lfds711_stack_state *__cs_param_lfds711_stack_pop_ss;
                                
# 4709 "<previous_module>"
tmain_219: IF(0,219,tmain_220)__CSEQ_removeindent;
                                
# 4710 "<previous_module>"
__cs_param_lfds711_stack_pop_ss = __cs_param_contains_s;
                                
# 4711 "<previous_module>"
static struct lfds711_stack_element **__cs_param_lfds711_stack_pop_se;
                                
# 4712 "<previous_module>"
tmain_220: IF(0,220,tmain_221)__CSEQ_removeindent;
                                
# 4713 "<previous_module>"
__cs_param_lfds711_stack_pop_se = &__cs_local_contains_se;
                                
# 4714 "<previous_module>"
static char unsigned __cs_local_lfds711_stack_pop_result;
                                
# 4715 "<previous_module>"
static lfds711_pal_uint_t __cs_local_lfds711_stack_pop_backoff_iteration;
                                
# 4716 "<previous_module>"
__cs_local_lfds711_stack_pop_backoff_iteration = 0;
                                
# 4717 "<previous_module>"
static struct lfds711_stack_element *__cs_local_lfds711_stack_pop_new_top[2];
                                
# 4718 "<previous_module>"
static struct lfds711_stack_element * volatile __cs_local_lfds711_stack_pop_original_top[2];
                                
# 4719 "<previous_module>"
;
                                ;
                                
# 4720 "<previous_module>"
static _Bool __cs_local_lfds711_stack_pop___cs_tmp_if_cond_6;
                                
# 4721 "<previous_module>"
tmain_221: IF(0,221,tmain_222)__CSEQ_removeindent;
                                
# 4722 "<previous_module>"
__cs_local_lfds711_stack_pop___cs_tmp_if_cond_6 = !(__cs_param_lfds711_stack_pop_ss != 0);
                                
# 4723 "<previous_module>"
if (__cs_local_lfds711_stack_pop___cs_tmp_if_cond_6)

# 4724 "<previous_module>"
                                {
                                        
# 4725 "<previous_module>"
static char *__cs_local_lfds711_stack_pop_c;
                                        
# 4726 "<previous_module>"
tmain_222: IF(0,222,tmain_223)__CSEQ_removeindent;
                                        
# 4727 "<previous_module>"
__cs_local_lfds711_stack_pop_c = 0;
                                        
# 4728 "<previous_module>"
tmain_223: IF(0,223,tmain_224)__CSEQ_removeindent;
                                        
# 4729 "<previous_module>"
*__cs_local_lfds711_stack_pop_c = 0;
                                }

                                
# 4731 "<previous_module>"
__CPROVER_assume(__cs_pc_cs[0] >= 224);
                                ;
                                
# 4732 "<previous_module>"
;
                                ;
                                
# 4733 "<previous_module>"
;
                                ;
                                
# 4734 "<previous_module>"
;
                                ;
                                
# 4735 "<previous_module>"
static _Bool __cs_local_lfds711_stack_pop___cs_tmp_if_cond_7;
                                
# 4736 "<previous_module>"
tmain_224: IF(0,224,tmain_225)__CSEQ_removeindent;
                                
# 4737 "<previous_module>"
__cs_local_lfds711_stack_pop___cs_tmp_if_cond_7 = !(__cs_param_lfds711_stack_pop_se != 0);
                                
# 4738 "<previous_module>"
if (__cs_local_lfds711_stack_pop___cs_tmp_if_cond_7)

# 4739 "<previous_module>"
                                {
                                        
# 4740 "<previous_module>"
static char *__cs_local_lfds711_stack_pop_c;
                                        
# 4741 "<previous_module>"
tmain_225: IF(0,225,tmain_226)__CSEQ_removeindent;
                                        
# 4742 "<previous_module>"
__cs_local_lfds711_stack_pop_c = 0;
                                        
# 4743 "<previous_module>"
tmain_226: IF(0,226,tmain_227)__CSEQ_removeindent;
                                        
# 4744 "<previous_module>"
*__cs_local_lfds711_stack_pop_c = 0;
                                }

                                
# 4746 "<previous_module>"
__CPROVER_assume(__cs_pc_cs[0] >= 227);
                                ;
                                
# 4747 "<previous_module>"
;
                                ;
                                
# 4748 "<previous_module>"
;
                                ;
                                
# 4749 "<previous_module>"
tmain_227: IF(0,227,tmain_228)__CSEQ_removeindent;
                                
# 4750 "<previous_module>"
__cs_mutex_lock(&library_lock, 0);
                                
# 4751 "<previous_module>"
tmain_228: IF(0,228,tmain_229)__CSEQ_removeindent;
                                
# 4752 "<previous_module>"
__cs_mutex_unlock(&library_lock, 0);
                                
# 4753 "<previous_module>"
tmain_229: IF(0,229,tmain_230)__CSEQ_removeindent;
                                
# 4754 "<previous_module>"
__cs_local_lfds711_stack_pop_original_top[1] = (*__cs_param_lfds711_stack_pop_ss).top[1];
                                
# 4755 "<previous_module>"
tmain_230: IF(0,230,tmain_231)__CSEQ_removeindent;
                                
# 4756 "<previous_module>"
__cs_local_lfds711_stack_pop_original_top[0] = (*__cs_param_lfds711_stack_pop_ss).top[0];
                                
# 4757 "<previous_module>"
static int __cs_local_lfds711_stack_pop_i;
                                
# 4758 "<previous_module>"
__cs_local_lfds711_stack_pop_i = 0;
                                
# 4759 "<previous_module>"
;
                                ;
                                
# 4760 "<previous_module>"
static int __cs_local_lfds711_stack_pop___cs_dowhile_onetime_1;
                                
# 4761 "<previous_module>"
__cs_local_lfds711_stack_pop___cs_dowhile_onetime_1 = 0;

# 4762 "<previous_module>"
                                {
                                        
# 4763 "<previous_module>"
;
                                        ;
                                        
# 4764 "<previous_module>"
static _Bool __cs_local_lfds711_stack_pop___cs_tmp_if_cond_8;
                                        
# 4765 "<previous_module>"
__cs_local_lfds711_stack_pop___cs_tmp_if_cond_8 = __cs_local_lfds711_stack_pop_original_top[0] == 0;
                                        
# 4766 "<previous_module>"
if (__cs_local_lfds711_stack_pop___cs_tmp_if_cond_8)

# 4767 "<previous_module>"
                                        {
                                                
# 4768 "<previous_module>"
tmain_231: IF(0,231,tmain_232)__CSEQ_removeindent;
                                                
# 4769 "<previous_module>"
*__cs_param_lfds711_stack_pop_se = 0;
                                                
# 4770 "<previous_module>"
__cs_retval__lfds711_stack_pop_2 = 0;
                                                
# 4771 "<previous_module>"
goto __exit__lfds711_stack_pop_2_3;
                                                ;
                                        }

                                        
# 4773 "<previous_module>"
__CPROVER_assume(__cs_pc_cs[0] >= 232);
                                        ;
                                        
# 4774 "<previous_module>"
tmain_232: IF(0,232,tmain_233)__CSEQ_removeindent;
                                        
# 4775 "<previous_module>"
__cs_local_lfds711_stack_pop_new_top[1] = __cs_local_lfds711_stack_pop_original_top[1] + 1;
                                        
# 4776 "<previous_module>"
tmain_233: IF(0,233,tmain_234)__CSEQ_removeindent;
                                        
# 4777 "<previous_module>"
__cs_local_lfds711_stack_pop_new_top[0] = (*__cs_local_lfds711_stack_pop_original_top[0]).next;
                                        
# 4778 "<previous_module>"
tmain_234: IF(0,234,tmain_235)__CSEQ_removeindent;
                                        
# 4779 "<previous_module>"
__cs_mutex_lock(&library_lock, 0);
                                        
# 4780 "<previous_module>"
tmain_235: IF(0,235,tmain_236)__CSEQ_removeindent;
                                        
# 4781 "<previous_module>"
__cs_local_lfds711_stack_pop_result = __CSEQ_atomic_swap_stack_top(&(*__cs_param_lfds711_stack_pop_ss).top[0], &__cs_local_lfds711_stack_pop_original_top[0], &__cs_local_lfds711_stack_pop_new_top[0]);
                                        
# 4782 "<previous_module>"
tmain_236: IF(0,236,tmain_237)__CSEQ_removeindent;
                                        
# 4783 "<previous_module>"
__cs_mutex_unlock(&library_lock, 0);
                                        
# 4784 "<previous_module>"
;
                                        ;
                                        
# 4785 "<previous_module>"
static _Bool __cs_local_lfds711_stack_pop___cs_tmp_if_cond_9;
                                        
# 4786 "<previous_module>"
__cs_local_lfds711_stack_pop___cs_tmp_if_cond_9 = __cs_local_lfds711_stack_pop_result == 0;
                                        
# 4787 "<previous_module>"
if (__cs_local_lfds711_stack_pop___cs_tmp_if_cond_9)

# 4788 "<previous_module>"
                                        {

# 4789 "<previous_module>"
                                                {
                                                        
# 4790 "<previous_module>"
static int __cs_local_exponential_backoff_loop;
                                                        
# 4791 "<previous_module>"
__cs_local_exponential_backoff_loop = 0;

# 4792 "<previous_module>"
                                                        {
                                                                
# 4793 "<previous_module>"
;
                                                                ;
                                                        }
                                                        
# 4795 "<previous_module>"
;
                                                        
# 4796 "<previous_module>"
__cs_local_exponential_backoff_loop++;

# 4797 "<previous_module>"
                                                        {
                                                                
# 4798 "<previous_module>"
;
                                                                ;
                                                        }
                                                        
# 4800 "<previous_module>"
;
                                                        
# 4801 "<previous_module>"
__cs_local_exponential_backoff_loop++;

# 4802 "<previous_module>"
                                                        {
                                                                
# 4803 "<previous_module>"
;
                                                                ;
                                                        }
                                                        
# 4805 "<previous_module>"
;
                                                        
# 4806 "<previous_module>"
__cs_local_exponential_backoff_loop++;
                                                        
# 4807 "<previous_module>"
tmain_237: IF(0,237,tmain_238)__CSEQ_removeindent;
                                                        
# 4808 "<previous_module>"
__CPROVER_assume(!(__cs_local_exponential_backoff_loop < 3));
                                                        
# 4809 "<previous_module>"
__exit_loop_57:
                                                        __CPROVER_assume(__cs_pc_cs[0] >= 238);

                                                        
# 4810 "<previous_module>"
;
                                                        ;
                                                        
# 4811 "<previous_module>"
__exit__exponential_backoff_4_3:
                                                        __CPROVER_assume(__cs_pc_cs[0] >= 238);

                                                        
# 4812 "<previous_module>"
;
                                                        ;
                                                }
                                                
# 4814 "<previous_module>"
;
                                                
# 4815 "<previous_module>"
tmain_238: IF(0,238,tmain_239)__CSEQ_removeindent;
                                                
# 4816 "<previous_module>"
__cs_mutex_lock(&library_lock, 0);
                                                
# 4817 "<previous_module>"
tmain_239: IF(0,239,tmain_240)__CSEQ_removeindent;
                                                
# 4818 "<previous_module>"
__cs_mutex_unlock(&library_lock, 0);
                                        }

                                        
# 4820 "<previous_module>"
__CPROVER_assume(__cs_pc_cs[0] >= 240);
                                        ;
                                        
# 4821 "<previous_module>"
__cs_local_lfds711_stack_pop_i++;
                                        
# 4822 "<previous_module>"
;
                                        ;
                                        
# 4823 "<previous_module>"
static _Bool __cs_local_lfds711_stack_pop___cs_tmp_if_cond_10;
                                        
# 4824 "<previous_module>"
__cs_local_lfds711_stack_pop___cs_tmp_if_cond_10 = __cs_local_lfds711_stack_pop_i > 1000;
                                        
# 4825 "<previous_module>"
if (__cs_local_lfds711_stack_pop___cs_tmp_if_cond_10)

# 4826 "<previous_module>"
                                        {
                                                
# 4827 "<previous_module>"
goto __exit_loop_56;
                                                ;
                                        }

                                        
# 4829 "<previous_module>"
;
                                }
                                
# 4831 "<previous_module>"
;
                                
# 4832 "<previous_module>"
__cs_local_lfds711_stack_pop___cs_dowhile_onetime_1++;
                                
# 4833 "<previous_module>"
tmain_240: IF(0,240,tmain_241)__CSEQ_removeindent;
                                
# 4834 "<previous_module>"
__CPROVER_assume(!(__cs_local_lfds711_stack_pop___cs_dowhile_onetime_1 < 1));
                                
# 4835 "<previous_module>"
__exit_loop_56:
                                __CPROVER_assume(__cs_pc_cs[0] >= 241);

                                
# 4836 "<previous_module>"
;
                                ;
                                
# 4837 "<previous_module>"
if (
# 4838 "<previous_module>"
!(__cs_local_lfds711_stack_pop_result == 0))

# 4839 "<previous_module>"
                                {
                                        
# 4840 "<previous_module>"
goto __exit_loop_58;
                                        ;
                                }

                                
# 4842 "<previous_module>"
;

# 4843 "<previous_module>"
                                {
                                        
# 4844 "<previous_module>"
;
                                        ;
                                        
# 4845 "<previous_module>"
static _Bool __cs_local_lfds711_stack_pop___cs_tmp_if_cond_11;
                                        
# 4846 "<previous_module>"
__cs_local_lfds711_stack_pop___cs_tmp_if_cond_11 = __cs_local_lfds711_stack_pop_original_top[0] == 0;
                                        
# 4847 "<previous_module>"
if (__cs_local_lfds711_stack_pop___cs_tmp_if_cond_11)

# 4848 "<previous_module>"
                                        {
                                                
# 4849 "<previous_module>"
tmain_241: IF(0,241,tmain_242)__CSEQ_removeindent;
                                                
# 4850 "<previous_module>"
*__cs_param_lfds711_stack_pop_se = 0;
                                                
# 4851 "<previous_module>"
__cs_retval__lfds711_stack_pop_2 = 0;
                                                
# 4852 "<previous_module>"
goto __exit__lfds711_stack_pop_2_3;
                                                ;
                                        }

                                        
# 4854 "<previous_module>"
__CPROVER_assume(__cs_pc_cs[0] >= 242);
                                        ;
                                        
# 4855 "<previous_module>"
tmain_242: IF(0,242,tmain_243)__CSEQ_removeindent;
                                        
# 4856 "<previous_module>"
__cs_local_lfds711_stack_pop_new_top[1] = __cs_local_lfds711_stack_pop_original_top[1] + 1;
                                        
# 4857 "<previous_module>"
tmain_243: IF(0,243,tmain_244)__CSEQ_removeindent;
                                        
# 4858 "<previous_module>"
__cs_local_lfds711_stack_pop_new_top[0] = (*__cs_local_lfds711_stack_pop_original_top[0]).next;
                                        
# 4859 "<previous_module>"
tmain_244: IF(0,244,tmain_245)__CSEQ_removeindent;
                                        
# 4860 "<previous_module>"
__cs_mutex_lock(&library_lock, 0);
                                        
# 4861 "<previous_module>"
tmain_245: IF(0,245,tmain_246)__CSEQ_removeindent;
                                        
# 4862 "<previous_module>"
__cs_local_lfds711_stack_pop_result = __CSEQ_atomic_swap_stack_top(&(*__cs_param_lfds711_stack_pop_ss).top[0], &__cs_local_lfds711_stack_pop_original_top[0], &__cs_local_lfds711_stack_pop_new_top[0]);
                                        
# 4863 "<previous_module>"
tmain_246: IF(0,246,tmain_247)__CSEQ_removeindent;
                                        
# 4864 "<previous_module>"
__cs_mutex_unlock(&library_lock, 0);
                                        
# 4865 "<previous_module>"
;
                                        ;
                                        
# 4866 "<previous_module>"
static _Bool __cs_local_lfds711_stack_pop___cs_tmp_if_cond_12;
                                        
# 4867 "<previous_module>"
__cs_local_lfds711_stack_pop___cs_tmp_if_cond_12 = __cs_local_lfds711_stack_pop_result == 0;
                                        
# 4868 "<previous_module>"
if (__cs_local_lfds711_stack_pop___cs_tmp_if_cond_12)

# 4869 "<previous_module>"
                                        {

# 4870 "<previous_module>"
                                                {
                                                        
# 4871 "<previous_module>"
static int __cs_local_exponential_backoff_loop;
                                                        
# 4872 "<previous_module>"
__cs_local_exponential_backoff_loop = 0;

# 4873 "<previous_module>"
                                                        {
                                                                
# 4874 "<previous_module>"
;
                                                                ;
                                                        }
                                                        
# 4876 "<previous_module>"
;
                                                        
# 4877 "<previous_module>"
__cs_local_exponential_backoff_loop++;

# 4878 "<previous_module>"
                                                        {
                                                                
# 4879 "<previous_module>"
;
                                                                ;
                                                        }
                                                        
# 4881 "<previous_module>"
;
                                                        
# 4882 "<previous_module>"
__cs_local_exponential_backoff_loop++;

# 4883 "<previous_module>"
                                                        {
                                                                
# 4884 "<previous_module>"
;
                                                                ;
                                                        }
                                                        
# 4886 "<previous_module>"
;
                                                        
# 4887 "<previous_module>"
__cs_local_exponential_backoff_loop++;
                                                        
# 4888 "<previous_module>"
tmain_247: IF(0,247,tmain_248)__CSEQ_removeindent;
                                                        
# 4889 "<previous_module>"
__CPROVER_assume(!(__cs_local_exponential_backoff_loop < 3));
                                                        
# 4890 "<previous_module>"
__exit_loop_59:
                                                        __CPROVER_assume(__cs_pc_cs[0] >= 248);

                                                        
# 4891 "<previous_module>"
;
                                                        ;
                                                        
# 4892 "<previous_module>"
__exit__exponential_backoff_5_15:
                                                        __CPROVER_assume(__cs_pc_cs[0] >= 248);

                                                        
# 4893 "<previous_module>"
;
                                                        ;
                                                }
                                                
# 4895 "<previous_module>"
;
                                                
# 4896 "<previous_module>"
tmain_248: IF(0,248,tmain_249)__CSEQ_removeindent;
                                                
# 4897 "<previous_module>"
__cs_mutex_lock(&library_lock, 0);
                                                
# 4898 "<previous_module>"
tmain_249: IF(0,249,tmain_250)__CSEQ_removeindent;
                                                
# 4899 "<previous_module>"
__cs_mutex_unlock(&library_lock, 0);
                                        }

                                        
# 4901 "<previous_module>"
__CPROVER_assume(__cs_pc_cs[0] >= 250);
                                        ;
                                        
# 4902 "<previous_module>"
__cs_local_lfds711_stack_pop_i++;
                                        
# 4903 "<previous_module>"
;
                                        ;
                                        
# 4904 "<previous_module>"
static _Bool __cs_local_lfds711_stack_pop___cs_tmp_if_cond_13;
                                        
# 4905 "<previous_module>"
__cs_local_lfds711_stack_pop___cs_tmp_if_cond_13 = __cs_local_lfds711_stack_pop_i > 1000;
                                        
# 4906 "<previous_module>"
if (__cs_local_lfds711_stack_pop___cs_tmp_if_cond_13)

# 4907 "<previous_module>"
                                        {
                                                
# 4908 "<previous_module>"
goto __exit_loop_58;
                                                ;
                                        }

                                        
# 4910 "<previous_module>"
;
                                }
                                
# 4912 "<previous_module>"
;
                                
# 4913 "<previous_module>"
if (
# 4914 "<previous_module>"
!(__cs_local_lfds711_stack_pop_result == 0))

# 4915 "<previous_module>"
                                {
                                        
# 4916 "<previous_module>"
goto __exit_loop_58;
                                        ;
                                }

                                
# 4918 "<previous_module>"
;

# 4919 "<previous_module>"
                                {
                                        
# 4920 "<previous_module>"
;
                                        ;
                                        
# 4921 "<previous_module>"
static _Bool __cs_local_lfds711_stack_pop___cs_tmp_if_cond_11;
                                        
# 4922 "<previous_module>"
__cs_local_lfds711_stack_pop___cs_tmp_if_cond_11 = __cs_local_lfds711_stack_pop_original_top[0] == 0;
                                        
# 4923 "<previous_module>"
if (__cs_local_lfds711_stack_pop___cs_tmp_if_cond_11)

# 4924 "<previous_module>"
                                        {
                                                
# 4925 "<previous_module>"
tmain_250: IF(0,250,tmain_251)__CSEQ_removeindent;
                                                
# 4926 "<previous_module>"
*__cs_param_lfds711_stack_pop_se = 0;
                                                
# 4927 "<previous_module>"
__cs_retval__lfds711_stack_pop_2 = 0;
                                                
# 4928 "<previous_module>"
goto __exit__lfds711_stack_pop_2_3;
                                                ;
                                        }

                                        
# 4930 "<previous_module>"
__CPROVER_assume(__cs_pc_cs[0] >= 251);
                                        ;
                                        
# 4931 "<previous_module>"
tmain_251: IF(0,251,tmain_252)__CSEQ_removeindent;
                                        
# 4932 "<previous_module>"
__cs_local_lfds711_stack_pop_new_top[1] = __cs_local_lfds711_stack_pop_original_top[1] + 1;
                                        
# 4933 "<previous_module>"
tmain_252: IF(0,252,tmain_253)__CSEQ_removeindent;
                                        
# 4934 "<previous_module>"
__cs_local_lfds711_stack_pop_new_top[0] = (*__cs_local_lfds711_stack_pop_original_top[0]).next;
                                        
# 4935 "<previous_module>"
tmain_253: IF(0,253,tmain_254)__CSEQ_removeindent;
                                        
# 4936 "<previous_module>"
__cs_mutex_lock(&library_lock, 0);
                                        
# 4937 "<previous_module>"
tmain_254: IF(0,254,tmain_255)__CSEQ_removeindent;
                                        
# 4938 "<previous_module>"
__cs_local_lfds711_stack_pop_result = __CSEQ_atomic_swap_stack_top(&(*__cs_param_lfds711_stack_pop_ss).top[0], &__cs_local_lfds711_stack_pop_original_top[0], &__cs_local_lfds711_stack_pop_new_top[0]);
                                        
# 4939 "<previous_module>"
tmain_255: IF(0,255,tmain_256)__CSEQ_removeindent;
                                        
# 4940 "<previous_module>"
__cs_mutex_unlock(&library_lock, 0);
                                        
# 4941 "<previous_module>"
;
                                        ;
                                        
# 4942 "<previous_module>"
static _Bool __cs_local_lfds711_stack_pop___cs_tmp_if_cond_12;
                                        
# 4943 "<previous_module>"
__cs_local_lfds711_stack_pop___cs_tmp_if_cond_12 = __cs_local_lfds711_stack_pop_result == 0;
                                        
# 4944 "<previous_module>"
if (__cs_local_lfds711_stack_pop___cs_tmp_if_cond_12)

# 4945 "<previous_module>"
                                        {

# 4946 "<previous_module>"
                                                {
                                                        
# 4947 "<previous_module>"
static int __cs_local_exponential_backoff_loop;
                                                        
# 4948 "<previous_module>"
__cs_local_exponential_backoff_loop = 0;

# 4949 "<previous_module>"
                                                        {
                                                                
# 4950 "<previous_module>"
;
                                                                ;
                                                        }
                                                        
# 4952 "<previous_module>"
;
                                                        
# 4953 "<previous_module>"
__cs_local_exponential_backoff_loop++;

# 4954 "<previous_module>"
                                                        {
                                                                
# 4955 "<previous_module>"
;
                                                                ;
                                                        }
                                                        
# 4957 "<previous_module>"
;
                                                        
# 4958 "<previous_module>"
__cs_local_exponential_backoff_loop++;

# 4959 "<previous_module>"
                                                        {
                                                                
# 4960 "<previous_module>"
;
                                                                ;
                                                        }
                                                        
# 4962 "<previous_module>"
;
                                                        
# 4963 "<previous_module>"
__cs_local_exponential_backoff_loop++;
                                                        
# 4964 "<previous_module>"
tmain_256: IF(0,256,tmain_257)__CSEQ_removeindent;
                                                        
# 4965 "<previous_module>"
__CPROVER_assume(!(__cs_local_exponential_backoff_loop < 3));
                                                        
# 4966 "<previous_module>"
__exit_loop_60:
                                                        __CPROVER_assume(__cs_pc_cs[0] >= 257);

                                                        
# 4967 "<previous_module>"
;
                                                        ;
                                                        
# 4968 "<previous_module>"
__exit__exponential_backoff_5_16:
                                                        __CPROVER_assume(__cs_pc_cs[0] >= 257);

                                                        
# 4969 "<previous_module>"
;
                                                        ;
                                                }
                                                
# 4971 "<previous_module>"
;
                                                
# 4972 "<previous_module>"
tmain_257: IF(0,257,tmain_258)__CSEQ_removeindent;
                                                
# 4973 "<previous_module>"
__cs_mutex_lock(&library_lock, 0);
                                                
# 4974 "<previous_module>"
tmain_258: IF(0,258,tmain_259)__CSEQ_removeindent;
                                                
# 4975 "<previous_module>"
__cs_mutex_unlock(&library_lock, 0);
                                        }

                                        
# 4977 "<previous_module>"
__CPROVER_assume(__cs_pc_cs[0] >= 259);
                                        ;
                                        
# 4978 "<previous_module>"
__cs_local_lfds711_stack_pop_i++;
                                        
# 4979 "<previous_module>"
;
                                        ;
                                        
# 4980 "<previous_module>"
static _Bool __cs_local_lfds711_stack_pop___cs_tmp_if_cond_13;
                                        
# 4981 "<previous_module>"
__cs_local_lfds711_stack_pop___cs_tmp_if_cond_13 = __cs_local_lfds711_stack_pop_i > 1000;
                                        
# 4982 "<previous_module>"
if (__cs_local_lfds711_stack_pop___cs_tmp_if_cond_13)

# 4983 "<previous_module>"
                                        {
                                                
# 4984 "<previous_module>"
goto __exit_loop_58;
                                                ;
                                        }

                                        
# 4986 "<previous_module>"
;
                                }
                                
# 4988 "<previous_module>"
;
                                
# 4989 "<previous_module>"
if (
# 4990 "<previous_module>"
!(__cs_local_lfds711_stack_pop_result == 0))

# 4991 "<previous_module>"
                                {
                                        
# 4992 "<previous_module>"
goto __exit_loop_58;
                                        ;
                                }

                                
# 4994 "<previous_module>"
;

# 4995 "<previous_module>"
                                {
                                        
# 4996 "<previous_module>"
;
                                        ;
                                        
# 4997 "<previous_module>"
static _Bool __cs_local_lfds711_stack_pop___cs_tmp_if_cond_11;
                                        
# 4998 "<previous_module>"
__cs_local_lfds711_stack_pop___cs_tmp_if_cond_11 = __cs_local_lfds711_stack_pop_original_top[0] == 0;
                                        
# 4999 "<previous_module>"
if (__cs_local_lfds711_stack_pop___cs_tmp_if_cond_11)

# 5000 "<previous_module>"
                                        {
                                                
# 5001 "<previous_module>"
tmain_259: IF(0,259,tmain_260)__CSEQ_removeindent;
                                                
# 5002 "<previous_module>"
*__cs_param_lfds711_stack_pop_se = 0;
                                                
# 5003 "<previous_module>"
__cs_retval__lfds711_stack_pop_2 = 0;
                                                
# 5004 "<previous_module>"
goto __exit__lfds711_stack_pop_2_3;
                                                ;
                                        }

                                        
# 5006 "<previous_module>"
__CPROVER_assume(__cs_pc_cs[0] >= 260);
                                        ;
                                        
# 5007 "<previous_module>"
tmain_260: IF(0,260,tmain_261)__CSEQ_removeindent;
                                        
# 5008 "<previous_module>"
__cs_local_lfds711_stack_pop_new_top[1] = __cs_local_lfds711_stack_pop_original_top[1] + 1;
                                        
# 5009 "<previous_module>"
tmain_261: IF(0,261,tmain_262)__CSEQ_removeindent;
                                        
# 5010 "<previous_module>"
__cs_local_lfds711_stack_pop_new_top[0] = (*__cs_local_lfds711_stack_pop_original_top[0]).next;
                                        
# 5011 "<previous_module>"
tmain_262: IF(0,262,tmain_263)__CSEQ_removeindent;
                                        
# 5012 "<previous_module>"
__cs_mutex_lock(&library_lock, 0);
                                        
# 5013 "<previous_module>"
tmain_263: IF(0,263,tmain_264)__CSEQ_removeindent;
                                        
# 5014 "<previous_module>"
__cs_local_lfds711_stack_pop_result = __CSEQ_atomic_swap_stack_top(&(*__cs_param_lfds711_stack_pop_ss).top[0], &__cs_local_lfds711_stack_pop_original_top[0], &__cs_local_lfds711_stack_pop_new_top[0]);
                                        
# 5015 "<previous_module>"
tmain_264: IF(0,264,tmain_265)__CSEQ_removeindent;
                                        
# 5016 "<previous_module>"
__cs_mutex_unlock(&library_lock, 0);
                                        
# 5017 "<previous_module>"
;
                                        ;
                                        
# 5018 "<previous_module>"
static _Bool __cs_local_lfds711_stack_pop___cs_tmp_if_cond_12;
                                        
# 5019 "<previous_module>"
__cs_local_lfds711_stack_pop___cs_tmp_if_cond_12 = __cs_local_lfds711_stack_pop_result == 0;
                                        
# 5020 "<previous_module>"
if (__cs_local_lfds711_stack_pop___cs_tmp_if_cond_12)

# 5021 "<previous_module>"
                                        {

# 5022 "<previous_module>"
                                                {
                                                        
# 5023 "<previous_module>"
static int __cs_local_exponential_backoff_loop;
                                                        
# 5024 "<previous_module>"
__cs_local_exponential_backoff_loop = 0;

# 5025 "<previous_module>"
                                                        {
                                                                
# 5026 "<previous_module>"
;
                                                                ;
                                                        }
                                                        
# 5028 "<previous_module>"
;
                                                        
# 5029 "<previous_module>"
__cs_local_exponential_backoff_loop++;

# 5030 "<previous_module>"
                                                        {
                                                                
# 5031 "<previous_module>"
;
                                                                ;
                                                        }
                                                        
# 5033 "<previous_module>"
;
                                                        
# 5034 "<previous_module>"
__cs_local_exponential_backoff_loop++;

# 5035 "<previous_module>"
                                                        {
                                                                
# 5036 "<previous_module>"
;
                                                                ;
                                                        }
                                                        
# 5038 "<previous_module>"
;
                                                        
# 5039 "<previous_module>"
__cs_local_exponential_backoff_loop++;
                                                        
# 5040 "<previous_module>"
tmain_265: IF(0,265,tmain_266)__CSEQ_removeindent;
                                                        
# 5041 "<previous_module>"
__CPROVER_assume(!(__cs_local_exponential_backoff_loop < 3));
                                                        
# 5042 "<previous_module>"
__exit_loop_61:
                                                        __CPROVER_assume(__cs_pc_cs[0] >= 266);

                                                        
# 5043 "<previous_module>"
;
                                                        ;
                                                        
# 5044 "<previous_module>"
__exit__exponential_backoff_5_17:
                                                        __CPROVER_assume(__cs_pc_cs[0] >= 266);

                                                        
# 5045 "<previous_module>"
;
                                                        ;
                                                }
                                                
# 5047 "<previous_module>"
;
                                                
# 5048 "<previous_module>"
tmain_266: IF(0,266,tmain_267)__CSEQ_removeindent;
                                                
# 5049 "<previous_module>"
__cs_mutex_lock(&library_lock, 0);
                                                
# 5050 "<previous_module>"
tmain_267: IF(0,267,tmain_268)__CSEQ_removeindent;
                                                
# 5051 "<previous_module>"
__cs_mutex_unlock(&library_lock, 0);
                                        }

                                        
# 5053 "<previous_module>"
__CPROVER_assume(__cs_pc_cs[0] >= 268);
                                        ;
                                        
# 5054 "<previous_module>"
__cs_local_lfds711_stack_pop_i++;
                                        
# 5055 "<previous_module>"
;
                                        ;
                                        
# 5056 "<previous_module>"
static _Bool __cs_local_lfds711_stack_pop___cs_tmp_if_cond_13;
                                        
# 5057 "<previous_module>"
__cs_local_lfds711_stack_pop___cs_tmp_if_cond_13 = __cs_local_lfds711_stack_pop_i > 1000;
                                        
# 5058 "<previous_module>"
if (__cs_local_lfds711_stack_pop___cs_tmp_if_cond_13)

# 5059 "<previous_module>"
                                        {
                                                
# 5060 "<previous_module>"
goto __exit_loop_58;
                                                ;
                                        }

                                        
# 5062 "<previous_module>"
;
                                }
                                
# 5064 "<previous_module>"
;
                                
# 5065 "<previous_module>"
if (
# 5066 "<previous_module>"
!(__cs_local_lfds711_stack_pop_result == 0))

# 5067 "<previous_module>"
                                {
                                        
# 5068 "<previous_module>"
goto __exit_loop_58;
                                        ;
                                }

                                
# 5070 "<previous_module>"
;

# 5071 "<previous_module>"
                                {
                                        
# 5072 "<previous_module>"
;
                                        ;
                                        
# 5073 "<previous_module>"
static _Bool __cs_local_lfds711_stack_pop___cs_tmp_if_cond_11;
                                        
# 5074 "<previous_module>"
__cs_local_lfds711_stack_pop___cs_tmp_if_cond_11 = __cs_local_lfds711_stack_pop_original_top[0] == 0;
                                        
# 5075 "<previous_module>"
if (__cs_local_lfds711_stack_pop___cs_tmp_if_cond_11)

# 5076 "<previous_module>"
                                        {
                                                
# 5077 "<previous_module>"
tmain_268: IF(0,268,tmain_269)__CSEQ_removeindent;
                                                
# 5078 "<previous_module>"
*__cs_param_lfds711_stack_pop_se = 0;
                                                
# 5079 "<previous_module>"
__cs_retval__lfds711_stack_pop_2 = 0;
                                                
# 5080 "<previous_module>"
goto __exit__lfds711_stack_pop_2_3;
                                                ;
                                        }

                                        
# 5082 "<previous_module>"
__CPROVER_assume(__cs_pc_cs[0] >= 269);
                                        ;
                                        
# 5083 "<previous_module>"
tmain_269: IF(0,269,tmain_270)__CSEQ_removeindent;
                                        
# 5084 "<previous_module>"
__cs_local_lfds711_stack_pop_new_top[1] = __cs_local_lfds711_stack_pop_original_top[1] + 1;
                                        
# 5085 "<previous_module>"
tmain_270: IF(0,270,tmain_271)__CSEQ_removeindent;
                                        
# 5086 "<previous_module>"
__cs_local_lfds711_stack_pop_new_top[0] = (*__cs_local_lfds711_stack_pop_original_top[0]).next;
                                        
# 5087 "<previous_module>"
tmain_271: IF(0,271,tmain_272)__CSEQ_removeindent;
                                        
# 5088 "<previous_module>"
__cs_mutex_lock(&library_lock, 0);
                                        
# 5089 "<previous_module>"
tmain_272: IF(0,272,tmain_273)__CSEQ_removeindent;
                                        
# 5090 "<previous_module>"
__cs_local_lfds711_stack_pop_result = __CSEQ_atomic_swap_stack_top(&(*__cs_param_lfds711_stack_pop_ss).top[0], &__cs_local_lfds711_stack_pop_original_top[0], &__cs_local_lfds711_stack_pop_new_top[0]);
                                        
# 5091 "<previous_module>"
tmain_273: IF(0,273,tmain_274)__CSEQ_removeindent;
                                        
# 5092 "<previous_module>"
__cs_mutex_unlock(&library_lock, 0);
                                        
# 5093 "<previous_module>"
;
                                        ;
                                        
# 5094 "<previous_module>"
static _Bool __cs_local_lfds711_stack_pop___cs_tmp_if_cond_12;
                                        
# 5095 "<previous_module>"
__cs_local_lfds711_stack_pop___cs_tmp_if_cond_12 = __cs_local_lfds711_stack_pop_result == 0;
                                        
# 5096 "<previous_module>"
if (__cs_local_lfds711_stack_pop___cs_tmp_if_cond_12)

# 5097 "<previous_module>"
                                        {

# 5098 "<previous_module>"
                                                {
                                                        
# 5099 "<previous_module>"
static int __cs_local_exponential_backoff_loop;
                                                        
# 5100 "<previous_module>"
__cs_local_exponential_backoff_loop = 0;

# 5101 "<previous_module>"
                                                        {
                                                                
# 5102 "<previous_module>"
;
                                                                ;
                                                        }
                                                        
# 5104 "<previous_module>"
;
                                                        
# 5105 "<previous_module>"
__cs_local_exponential_backoff_loop++;

# 5106 "<previous_module>"
                                                        {
                                                                
# 5107 "<previous_module>"
;
                                                                ;
                                                        }
                                                        
# 5109 "<previous_module>"
;
                                                        
# 5110 "<previous_module>"
__cs_local_exponential_backoff_loop++;

# 5111 "<previous_module>"
                                                        {
                                                                
# 5112 "<previous_module>"
;
                                                                ;
                                                        }
                                                        
# 5114 "<previous_module>"
;
                                                        
# 5115 "<previous_module>"
__cs_local_exponential_backoff_loop++;
                                                        
# 5116 "<previous_module>"
tmain_274: IF(0,274,tmain_275)__CSEQ_removeindent;
                                                        
# 5117 "<previous_module>"
__CPROVER_assume(!(__cs_local_exponential_backoff_loop < 3));
                                                        
# 5118 "<previous_module>"
__exit_loop_62:
                                                        __CPROVER_assume(__cs_pc_cs[0] >= 275);

                                                        
# 5119 "<previous_module>"
;
                                                        ;
                                                        
# 5120 "<previous_module>"
__exit__exponential_backoff_5_18:
                                                        __CPROVER_assume(__cs_pc_cs[0] >= 275);

                                                        
# 5121 "<previous_module>"
;
                                                        ;
                                                }
                                                
# 5123 "<previous_module>"
;
                                                
# 5124 "<previous_module>"
tmain_275: IF(0,275,tmain_276)__CSEQ_removeindent;
                                                
# 5125 "<previous_module>"
__cs_mutex_lock(&library_lock, 0);
                                                
# 5126 "<previous_module>"
tmain_276: IF(0,276,tmain_277)__CSEQ_removeindent;
                                                
# 5127 "<previous_module>"
__cs_mutex_unlock(&library_lock, 0);
                                        }

                                        
# 5129 "<previous_module>"
__CPROVER_assume(__cs_pc_cs[0] >= 277);
                                        ;
                                        
# 5130 "<previous_module>"
__cs_local_lfds711_stack_pop_i++;
                                        
# 5131 "<previous_module>"
;
                                        ;
                                        
# 5132 "<previous_module>"
static _Bool __cs_local_lfds711_stack_pop___cs_tmp_if_cond_13;
                                        
# 5133 "<previous_module>"
__cs_local_lfds711_stack_pop___cs_tmp_if_cond_13 = __cs_local_lfds711_stack_pop_i > 1000;
                                        
# 5134 "<previous_module>"
if (__cs_local_lfds711_stack_pop___cs_tmp_if_cond_13)

# 5135 "<previous_module>"
                                        {
                                                
# 5136 "<previous_module>"
goto __exit_loop_58;
                                                ;
                                        }

                                        
# 5138 "<previous_module>"
;
                                }
                                
# 5140 "<previous_module>"
;
                                
# 5141 "<previous_module>"
if (
# 5142 "<previous_module>"
!(__cs_local_lfds711_stack_pop_result == 0))

# 5143 "<previous_module>"
                                {
                                        
# 5144 "<previous_module>"
goto __exit_loop_58;
                                        ;
                                }

                                
# 5146 "<previous_module>"
;

# 5147 "<previous_module>"
                                {
                                        
# 5148 "<previous_module>"
;
                                        ;
                                        
# 5149 "<previous_module>"
static _Bool __cs_local_lfds711_stack_pop___cs_tmp_if_cond_11;
                                        
# 5150 "<previous_module>"
__cs_local_lfds711_stack_pop___cs_tmp_if_cond_11 = __cs_local_lfds711_stack_pop_original_top[0] == 0;
                                        
# 5151 "<previous_module>"
if (__cs_local_lfds711_stack_pop___cs_tmp_if_cond_11)

# 5152 "<previous_module>"
                                        {
                                                
# 5153 "<previous_module>"
tmain_277: IF(0,277,tmain_278)__CSEQ_removeindent;
                                                
# 5154 "<previous_module>"
*__cs_param_lfds711_stack_pop_se = 0;
                                                
# 5155 "<previous_module>"
__cs_retval__lfds711_stack_pop_2 = 0;
                                                
# 5156 "<previous_module>"
goto __exit__lfds711_stack_pop_2_3;
                                                ;
                                        }

                                        
# 5158 "<previous_module>"
__CPROVER_assume(__cs_pc_cs[0] >= 278);
                                        ;
                                        
# 5159 "<previous_module>"
tmain_278: IF(0,278,tmain_279)__CSEQ_removeindent;
                                        
# 5160 "<previous_module>"
__cs_local_lfds711_stack_pop_new_top[1] = __cs_local_lfds711_stack_pop_original_top[1] + 1;
                                        
# 5161 "<previous_module>"
tmain_279: IF(0,279,tmain_280)__CSEQ_removeindent;
                                        
# 5162 "<previous_module>"
__cs_local_lfds711_stack_pop_new_top[0] = (*__cs_local_lfds711_stack_pop_original_top[0]).next;
                                        
# 5163 "<previous_module>"
tmain_280: IF(0,280,tmain_281)__CSEQ_removeindent;
                                        
# 5164 "<previous_module>"
__cs_mutex_lock(&library_lock, 0);
                                        
# 5165 "<previous_module>"
tmain_281: IF(0,281,tmain_282)__CSEQ_removeindent;
                                        
# 5166 "<previous_module>"
__cs_local_lfds711_stack_pop_result = __CSEQ_atomic_swap_stack_top(&(*__cs_param_lfds711_stack_pop_ss).top[0], &__cs_local_lfds711_stack_pop_original_top[0], &__cs_local_lfds711_stack_pop_new_top[0]);
                                        
# 5167 "<previous_module>"
tmain_282: IF(0,282,tmain_283)__CSEQ_removeindent;
                                        
# 5168 "<previous_module>"
__cs_mutex_unlock(&library_lock, 0);
                                        
# 5169 "<previous_module>"
;
                                        ;
                                        
# 5170 "<previous_module>"
static _Bool __cs_local_lfds711_stack_pop___cs_tmp_if_cond_12;
                                        
# 5171 "<previous_module>"
__cs_local_lfds711_stack_pop___cs_tmp_if_cond_12 = __cs_local_lfds711_stack_pop_result == 0;
                                        
# 5172 "<previous_module>"
if (__cs_local_lfds711_stack_pop___cs_tmp_if_cond_12)

# 5173 "<previous_module>"
                                        {

# 5174 "<previous_module>"
                                                {
                                                        
# 5175 "<previous_module>"
static int __cs_local_exponential_backoff_loop;
                                                        
# 5176 "<previous_module>"
__cs_local_exponential_backoff_loop = 0;

# 5177 "<previous_module>"
                                                        {
                                                                
# 5178 "<previous_module>"
;
                                                                ;
                                                        }
                                                        
# 5180 "<previous_module>"
;
                                                        
# 5181 "<previous_module>"
__cs_local_exponential_backoff_loop++;

# 5182 "<previous_module>"
                                                        {
                                                                
# 5183 "<previous_module>"
;
                                                                ;
                                                        }
                                                        
# 5185 "<previous_module>"
;
                                                        
# 5186 "<previous_module>"
__cs_local_exponential_backoff_loop++;

# 5187 "<previous_module>"
                                                        {
                                                                
# 5188 "<previous_module>"
;
                                                                ;
                                                        }
                                                        
# 5190 "<previous_module>"
;
                                                        
# 5191 "<previous_module>"
__cs_local_exponential_backoff_loop++;
                                                        
# 5192 "<previous_module>"
tmain_283: IF(0,283,tmain_284)__CSEQ_removeindent;
                                                        
# 5193 "<previous_module>"
__CPROVER_assume(!(__cs_local_exponential_backoff_loop < 3));
                                                        
# 5194 "<previous_module>"
__exit_loop_63:
                                                        __CPROVER_assume(__cs_pc_cs[0] >= 284);

                                                        
# 5195 "<previous_module>"
;
                                                        ;
                                                        
# 5196 "<previous_module>"
__exit__exponential_backoff_5_19:
                                                        __CPROVER_assume(__cs_pc_cs[0] >= 284);

                                                        
# 5197 "<previous_module>"
;
                                                        ;
                                                }
                                                
# 5199 "<previous_module>"
;
                                                
# 5200 "<previous_module>"
tmain_284: IF(0,284,tmain_285)__CSEQ_removeindent;
                                                
# 5201 "<previous_module>"
__cs_mutex_lock(&library_lock, 0);
                                                
# 5202 "<previous_module>"
tmain_285: IF(0,285,tmain_286)__CSEQ_removeindent;
                                                
# 5203 "<previous_module>"
__cs_mutex_unlock(&library_lock, 0);
                                        }

                                        
# 5205 "<previous_module>"
__CPROVER_assume(__cs_pc_cs[0] >= 286);
                                        ;
                                        
# 5206 "<previous_module>"
__cs_local_lfds711_stack_pop_i++;
                                        
# 5207 "<previous_module>"
;
                                        ;
                                        
# 5208 "<previous_module>"
static _Bool __cs_local_lfds711_stack_pop___cs_tmp_if_cond_13;
                                        
# 5209 "<previous_module>"
__cs_local_lfds711_stack_pop___cs_tmp_if_cond_13 = __cs_local_lfds711_stack_pop_i > 1000;
                                        
# 5210 "<previous_module>"
if (__cs_local_lfds711_stack_pop___cs_tmp_if_cond_13)

# 5211 "<previous_module>"
                                        {
                                                
# 5212 "<previous_module>"
goto __exit_loop_58;
                                                ;
                                        }

                                        
# 5214 "<previous_module>"
;
                                }
                                
# 5216 "<previous_module>"
;
                                
# 5217 "<previous_module>"
tmain_286: IF(0,286,tmain_287)__CSEQ_removeindent;
                                
# 5218 "<previous_module>"
__CPROVER_assume(
# 5219 "<previous_module>"
!(__cs_local_lfds711_stack_pop_result == 0));
                                
# 5220 "<previous_module>"
__exit_loop_58:
                                __CPROVER_assume(__cs_pc_cs[0] >= 287);

                                
# 5221 "<previous_module>"
;
                                ;
                                
# 5222 "<previous_module>"
tmain_287: IF(0,287,tmain_288)__CSEQ_removeindent;
                                
# 5223 "<previous_module>"
*__cs_param_lfds711_stack_pop_se = __cs_local_lfds711_stack_pop_original_top[0];
                                
# 5224 "<previous_module>"
__cs_retval__lfds711_stack_pop_2 = __cs_local_lfds711_stack_pop_result;
                                
# 5225 "<previous_module>"
goto __exit__lfds711_stack_pop_2_3;
                                ;
                                
# 5226 "<previous_module>"
__exit__lfds711_stack_pop_2_3:
                                __CPROVER_assume(__cs_pc_cs[0] >= 288);

                                
# 5227 "<previous_module>"
;
                                ;
                        }
                        
# 5229 "<previous_module>"
;
                        
# 5230 "<previous_module>"
__cs_local_contains_res = __cs_retval__lfds711_stack_pop_2;
                        
# 5231 "<previous_module>"
;
                        ;
                        
# 5232 "<previous_module>"
static _Bool __cs_local_contains___cs_tmp_if_cond_20;
                        
# 5233 "<previous_module>"
__cs_local_contains___cs_tmp_if_cond_20 = __cs_local_contains_res == 0;
                        
# 5234 "<previous_module>"
if (__cs_local_contains___cs_tmp_if_cond_20)

# 5235 "<previous_module>"
                        {
                                
# 5236 "<previous_module>"
goto __exit_loop_31;
                                ;
                        }

                        
# 5238 "<previous_module>"
;
                        
# 5239 "<previous_module>"
tmain_288: IF(0,288,tmain_289)__CSEQ_removeindent;
                        
# 5240 "<previous_module>"
__cs_local_contains_datas[__cs_local_contains_actual_size] = (*__cs_local_contains_se).value;
                        
# 5241 "<previous_module>"
;
                        ;
                        
# 5242 "<previous_module>"
static _Bool __cs_local_contains___cs_tmp_if_cond_21;
                        
# 5243 "<previous_module>"
tmain_289: IF(0,289,tmain_290)__CSEQ_removeindent;
                        
# 5244 "<previous_module>"
__cs_local_contains___cs_tmp_if_cond_21 = (*__cs_local_contains_datas[__cs_local_contains_actual_size]).user_id == __cs_param_contains_id;
                        
# 5245 "<previous_module>"
if (__cs_local_contains___cs_tmp_if_cond_21)

# 5246 "<previous_module>"
                        {
                                
# 5247 "<previous_module>"
__cs_local_contains_found = 1;
                        }

                        
# 5249 "<previous_module>"
;
                        
# 5250 "<previous_module>"
__cs_local_contains_actual_size = __cs_local_contains_actual_size + 1;
                }
                
# 5252 "<previous_module>"
;
                
# 5253 "<previous_module>"
if (!(__cs_local_contains_actual_size < 2))

# 5254 "<previous_module>"
                {
                        
# 5255 "<previous_module>"
goto __exit_loop_31;
                        ;
                }

                
# 5257 "<previous_module>"
;

# 5258 "<previous_module>"
                {
                        
# 5259 "<previous_module>"
static int __cs_retval__lfds711_stack_pop_2;

# 5260 "<previous_module>"
                        {
                                
# 5261 "<previous_module>"
static struct lfds711_stack_state *__cs_param_lfds711_stack_pop_ss;
                                
# 5262 "<previous_module>"
tmain_290: IF(0,290,tmain_291)__CSEQ_removeindent;
                                
# 5263 "<previous_module>"
__cs_param_lfds711_stack_pop_ss = __cs_param_contains_s;
                                
# 5264 "<previous_module>"
static struct lfds711_stack_element **__cs_param_lfds711_stack_pop_se;
                                
# 5265 "<previous_module>"
tmain_291: IF(0,291,tmain_292)__CSEQ_removeindent;
                                
# 5266 "<previous_module>"
__cs_param_lfds711_stack_pop_se = &__cs_local_contains_se;
                                
# 5267 "<previous_module>"
static char unsigned __cs_local_lfds711_stack_pop_result;
                                
# 5268 "<previous_module>"
static lfds711_pal_uint_t __cs_local_lfds711_stack_pop_backoff_iteration;
                                
# 5269 "<previous_module>"
__cs_local_lfds711_stack_pop_backoff_iteration = 0;
                                
# 5270 "<previous_module>"
static struct lfds711_stack_element *__cs_local_lfds711_stack_pop_new_top[2];
                                
# 5271 "<previous_module>"
static struct lfds711_stack_element * volatile __cs_local_lfds711_stack_pop_original_top[2];
                                
# 5272 "<previous_module>"
;
                                ;
                                
# 5273 "<previous_module>"
static _Bool __cs_local_lfds711_stack_pop___cs_tmp_if_cond_6;
                                
# 5274 "<previous_module>"
tmain_292: IF(0,292,tmain_293)__CSEQ_removeindent;
                                
# 5275 "<previous_module>"
__cs_local_lfds711_stack_pop___cs_tmp_if_cond_6 = !(__cs_param_lfds711_stack_pop_ss != 0);
                                
# 5276 "<previous_module>"
if (__cs_local_lfds711_stack_pop___cs_tmp_if_cond_6)

# 5277 "<previous_module>"
                                {
                                        
# 5278 "<previous_module>"
static char *__cs_local_lfds711_stack_pop_c;
                                        
# 5279 "<previous_module>"
tmain_293: IF(0,293,tmain_294)__CSEQ_removeindent;
                                        
# 5280 "<previous_module>"
__cs_local_lfds711_stack_pop_c = 0;
                                        
# 5281 "<previous_module>"
tmain_294: IF(0,294,tmain_295)__CSEQ_removeindent;
                                        
# 5282 "<previous_module>"
*__cs_local_lfds711_stack_pop_c = 0;
                                }

                                
# 5284 "<previous_module>"
__CPROVER_assume(__cs_pc_cs[0] >= 295);
                                ;
                                
# 5285 "<previous_module>"
;
                                ;
                                
# 5286 "<previous_module>"
;
                                ;
                                
# 5287 "<previous_module>"
;
                                ;
                                
# 5288 "<previous_module>"
static _Bool __cs_local_lfds711_stack_pop___cs_tmp_if_cond_7;
                                
# 5289 "<previous_module>"
tmain_295: IF(0,295,tmain_296)__CSEQ_removeindent;
                                
# 5290 "<previous_module>"
__cs_local_lfds711_stack_pop___cs_tmp_if_cond_7 = !(__cs_param_lfds711_stack_pop_se != 0);
                                
# 5291 "<previous_module>"
if (__cs_local_lfds711_stack_pop___cs_tmp_if_cond_7)

# 5292 "<previous_module>"
                                {
                                        
# 5293 "<previous_module>"
static char *__cs_local_lfds711_stack_pop_c;
                                        
# 5294 "<previous_module>"
tmain_296: IF(0,296,tmain_297)__CSEQ_removeindent;
                                        
# 5295 "<previous_module>"
__cs_local_lfds711_stack_pop_c = 0;
                                        
# 5296 "<previous_module>"
tmain_297: IF(0,297,tmain_298)__CSEQ_removeindent;
                                        
# 5297 "<previous_module>"
*__cs_local_lfds711_stack_pop_c = 0;
                                }

                                
# 5299 "<previous_module>"
__CPROVER_assume(__cs_pc_cs[0] >= 298);
                                ;
                                
# 5300 "<previous_module>"
;
                                ;
                                
# 5301 "<previous_module>"
;
                                ;
                                
# 5302 "<previous_module>"
tmain_298: IF(0,298,tmain_299)__CSEQ_removeindent;
                                
# 5303 "<previous_module>"
__cs_mutex_lock(&library_lock, 0);
                                
# 5304 "<previous_module>"
tmain_299: IF(0,299,tmain_300)__CSEQ_removeindent;
                                
# 5305 "<previous_module>"
__cs_mutex_unlock(&library_lock, 0);
                                
# 5306 "<previous_module>"
tmain_300: IF(0,300,tmain_301)__CSEQ_removeindent;
                                
# 5307 "<previous_module>"
__cs_local_lfds711_stack_pop_original_top[1] = (*__cs_param_lfds711_stack_pop_ss).top[1];
                                
# 5308 "<previous_module>"
tmain_301: IF(0,301,tmain_302)__CSEQ_removeindent;
                                
# 5309 "<previous_module>"
__cs_local_lfds711_stack_pop_original_top[0] = (*__cs_param_lfds711_stack_pop_ss).top[0];
                                
# 5310 "<previous_module>"
static int __cs_local_lfds711_stack_pop_i;
                                
# 5311 "<previous_module>"
__cs_local_lfds711_stack_pop_i = 0;
                                
# 5312 "<previous_module>"
;
                                ;
                                
# 5313 "<previous_module>"
static int __cs_local_lfds711_stack_pop___cs_dowhile_onetime_1;
                                
# 5314 "<previous_module>"
__cs_local_lfds711_stack_pop___cs_dowhile_onetime_1 = 0;

# 5315 "<previous_module>"
                                {
                                        
# 5316 "<previous_module>"
;
                                        ;
                                        
# 5317 "<previous_module>"
static _Bool __cs_local_lfds711_stack_pop___cs_tmp_if_cond_8;
                                        
# 5318 "<previous_module>"
__cs_local_lfds711_stack_pop___cs_tmp_if_cond_8 = __cs_local_lfds711_stack_pop_original_top[0] == 0;
                                        
# 5319 "<previous_module>"
if (__cs_local_lfds711_stack_pop___cs_tmp_if_cond_8)

# 5320 "<previous_module>"
                                        {
                                                
# 5321 "<previous_module>"
tmain_302: IF(0,302,tmain_303)__CSEQ_removeindent;
                                                
# 5322 "<previous_module>"
*__cs_param_lfds711_stack_pop_se = 0;
                                                
# 5323 "<previous_module>"
__cs_retval__lfds711_stack_pop_2 = 0;
                                                
# 5324 "<previous_module>"
goto __exit__lfds711_stack_pop_2_4;
                                                ;
                                        }

                                        
# 5326 "<previous_module>"
__CPROVER_assume(__cs_pc_cs[0] >= 303);
                                        ;
                                        
# 5327 "<previous_module>"
tmain_303: IF(0,303,tmain_304)__CSEQ_removeindent;
                                        
# 5328 "<previous_module>"
__cs_local_lfds711_stack_pop_new_top[1] = __cs_local_lfds711_stack_pop_original_top[1] + 1;
                                        
# 5329 "<previous_module>"
tmain_304: IF(0,304,tmain_305)__CSEQ_removeindent;
                                        
# 5330 "<previous_module>"
__cs_local_lfds711_stack_pop_new_top[0] = (*__cs_local_lfds711_stack_pop_original_top[0]).next;
                                        
# 5331 "<previous_module>"
tmain_305: IF(0,305,tmain_306)__CSEQ_removeindent;
                                        
# 5332 "<previous_module>"
__cs_mutex_lock(&library_lock, 0);
                                        
# 5333 "<previous_module>"
tmain_306: IF(0,306,tmain_307)__CSEQ_removeindent;
                                        
# 5334 "<previous_module>"
__cs_local_lfds711_stack_pop_result = __CSEQ_atomic_swap_stack_top(&(*__cs_param_lfds711_stack_pop_ss).top[0], &__cs_local_lfds711_stack_pop_original_top[0], &__cs_local_lfds711_stack_pop_new_top[0]);
                                        
# 5335 "<previous_module>"
tmain_307: IF(0,307,tmain_308)__CSEQ_removeindent;
                                        
# 5336 "<previous_module>"
__cs_mutex_unlock(&library_lock, 0);
                                        
# 5337 "<previous_module>"
;
                                        ;
                                        
# 5338 "<previous_module>"
static _Bool __cs_local_lfds711_stack_pop___cs_tmp_if_cond_9;
                                        
# 5339 "<previous_module>"
__cs_local_lfds711_stack_pop___cs_tmp_if_cond_9 = __cs_local_lfds711_stack_pop_result == 0;
                                        
# 5340 "<previous_module>"
if (__cs_local_lfds711_stack_pop___cs_tmp_if_cond_9)

# 5341 "<previous_module>"
                                        {

# 5342 "<previous_module>"
                                                {
                                                        
# 5343 "<previous_module>"
static int __cs_local_exponential_backoff_loop;
                                                        
# 5344 "<previous_module>"
__cs_local_exponential_backoff_loop = 0;

# 5345 "<previous_module>"
                                                        {
                                                                
# 5346 "<previous_module>"
;
                                                                ;
                                                        }
                                                        
# 5348 "<previous_module>"
;
                                                        
# 5349 "<previous_module>"
__cs_local_exponential_backoff_loop++;

# 5350 "<previous_module>"
                                                        {
                                                                
# 5351 "<previous_module>"
;
                                                                ;
                                                        }
                                                        
# 5353 "<previous_module>"
;
                                                        
# 5354 "<previous_module>"
__cs_local_exponential_backoff_loop++;

# 5355 "<previous_module>"
                                                        {
                                                                
# 5356 "<previous_module>"
;
                                                                ;
                                                        }
                                                        
# 5358 "<previous_module>"
;
                                                        
# 5359 "<previous_module>"
__cs_local_exponential_backoff_loop++;
                                                        
# 5360 "<previous_module>"
tmain_308: IF(0,308,tmain_309)__CSEQ_removeindent;
                                                        
# 5361 "<previous_module>"
__CPROVER_assume(!(__cs_local_exponential_backoff_loop < 3));
                                                        
# 5362 "<previous_module>"
__exit_loop_65:
                                                        __CPROVER_assume(__cs_pc_cs[0] >= 309);

                                                        
# 5363 "<previous_module>"
;
                                                        ;
                                                        
# 5364 "<previous_module>"
__exit__exponential_backoff_4_4:
                                                        __CPROVER_assume(__cs_pc_cs[0] >= 309);

                                                        
# 5365 "<previous_module>"
;
                                                        ;
                                                }
                                                
# 5367 "<previous_module>"
;
                                                
# 5368 "<previous_module>"
tmain_309: IF(0,309,tmain_310)__CSEQ_removeindent;
                                                
# 5369 "<previous_module>"
__cs_mutex_lock(&library_lock, 0);
                                                
# 5370 "<previous_module>"
tmain_310: IF(0,310,tmain_311)__CSEQ_removeindent;
                                                
# 5371 "<previous_module>"
__cs_mutex_unlock(&library_lock, 0);
                                        }

                                        
# 5373 "<previous_module>"
__CPROVER_assume(__cs_pc_cs[0] >= 311);
                                        ;
                                        
# 5374 "<previous_module>"
__cs_local_lfds711_stack_pop_i++;
                                        
# 5375 "<previous_module>"
;
                                        ;
                                        
# 5376 "<previous_module>"
static _Bool __cs_local_lfds711_stack_pop___cs_tmp_if_cond_10;
                                        
# 5377 "<previous_module>"
__cs_local_lfds711_stack_pop___cs_tmp_if_cond_10 = __cs_local_lfds711_stack_pop_i > 1000;
                                        
# 5378 "<previous_module>"
if (__cs_local_lfds711_stack_pop___cs_tmp_if_cond_10)

# 5379 "<previous_module>"
                                        {
                                                
# 5380 "<previous_module>"
goto __exit_loop_64;
                                                ;
                                        }

                                        
# 5382 "<previous_module>"
;
                                }
                                
# 5384 "<previous_module>"
;
                                
# 5385 "<previous_module>"
__cs_local_lfds711_stack_pop___cs_dowhile_onetime_1++;
                                
# 5386 "<previous_module>"
tmain_311: IF(0,311,tmain_312)__CSEQ_removeindent;
                                
# 5387 "<previous_module>"
__CPROVER_assume(!(__cs_local_lfds711_stack_pop___cs_dowhile_onetime_1 < 1));
                                
# 5388 "<previous_module>"
__exit_loop_64:
                                __CPROVER_assume(__cs_pc_cs[0] >= 312);

                                
# 5389 "<previous_module>"
;
                                ;
                                
# 5390 "<previous_module>"
if (
# 5391 "<previous_module>"
!(__cs_local_lfds711_stack_pop_result == 0))

# 5392 "<previous_module>"
                                {
                                        
# 5393 "<previous_module>"
goto __exit_loop_66;
                                        ;
                                }

                                
# 5395 "<previous_module>"
;

# 5396 "<previous_module>"
                                {
                                        
# 5397 "<previous_module>"
;
                                        ;
                                        
# 5398 "<previous_module>"
static _Bool __cs_local_lfds711_stack_pop___cs_tmp_if_cond_11;
                                        
# 5399 "<previous_module>"
__cs_local_lfds711_stack_pop___cs_tmp_if_cond_11 = __cs_local_lfds711_stack_pop_original_top[0] == 0;
                                        
# 5400 "<previous_module>"
if (__cs_local_lfds711_stack_pop___cs_tmp_if_cond_11)

# 5401 "<previous_module>"
                                        {
                                                
# 5402 "<previous_module>"
tmain_312: IF(0,312,tmain_313)__CSEQ_removeindent;
                                                
# 5403 "<previous_module>"
*__cs_param_lfds711_stack_pop_se = 0;
                                                
# 5404 "<previous_module>"
__cs_retval__lfds711_stack_pop_2 = 0;
                                                
# 5405 "<previous_module>"
goto __exit__lfds711_stack_pop_2_4;
                                                ;
                                        }

                                        
# 5407 "<previous_module>"
__CPROVER_assume(__cs_pc_cs[0] >= 313);
                                        ;
                                        
# 5408 "<previous_module>"
tmain_313: IF(0,313,tmain_314)__CSEQ_removeindent;
                                        
# 5409 "<previous_module>"
__cs_local_lfds711_stack_pop_new_top[1] = __cs_local_lfds711_stack_pop_original_top[1] + 1;
                                        
# 5410 "<previous_module>"
tmain_314: IF(0,314,tmain_315)__CSEQ_removeindent;
                                        
# 5411 "<previous_module>"
__cs_local_lfds711_stack_pop_new_top[0] = (*__cs_local_lfds711_stack_pop_original_top[0]).next;
                                        
# 5412 "<previous_module>"
tmain_315: IF(0,315,tmain_316)__CSEQ_removeindent;
                                        
# 5413 "<previous_module>"
__cs_mutex_lock(&library_lock, 0);
                                        
# 5414 "<previous_module>"
tmain_316: IF(0,316,tmain_317)__CSEQ_removeindent;
                                        
# 5415 "<previous_module>"
__cs_local_lfds711_stack_pop_result = __CSEQ_atomic_swap_stack_top(&(*__cs_param_lfds711_stack_pop_ss).top[0], &__cs_local_lfds711_stack_pop_original_top[0], &__cs_local_lfds711_stack_pop_new_top[0]);
                                        
# 5416 "<previous_module>"
tmain_317: IF(0,317,tmain_318)__CSEQ_removeindent;
                                        
# 5417 "<previous_module>"
__cs_mutex_unlock(&library_lock, 0);
                                        
# 5418 "<previous_module>"
;
                                        ;
                                        
# 5419 "<previous_module>"
static _Bool __cs_local_lfds711_stack_pop___cs_tmp_if_cond_12;
                                        
# 5420 "<previous_module>"
__cs_local_lfds711_stack_pop___cs_tmp_if_cond_12 = __cs_local_lfds711_stack_pop_result == 0;
                                        
# 5421 "<previous_module>"
if (__cs_local_lfds711_stack_pop___cs_tmp_if_cond_12)

# 5422 "<previous_module>"
                                        {

# 5423 "<previous_module>"
                                                {
                                                        
# 5424 "<previous_module>"
static int __cs_local_exponential_backoff_loop;
                                                        
# 5425 "<previous_module>"
__cs_local_exponential_backoff_loop = 0;

# 5426 "<previous_module>"
                                                        {
                                                                
# 5427 "<previous_module>"
;
                                                                ;
                                                        }
                                                        
# 5429 "<previous_module>"
;
                                                        
# 5430 "<previous_module>"
__cs_local_exponential_backoff_loop++;

# 5431 "<previous_module>"
                                                        {
                                                                
# 5432 "<previous_module>"
;
                                                                ;
                                                        }
                                                        
# 5434 "<previous_module>"
;
                                                        
# 5435 "<previous_module>"
__cs_local_exponential_backoff_loop++;

# 5436 "<previous_module>"
                                                        {
                                                                
# 5437 "<previous_module>"
;
                                                                ;
                                                        }
                                                        
# 5439 "<previous_module>"
;
                                                        
# 5440 "<previous_module>"
__cs_local_exponential_backoff_loop++;
                                                        
# 5441 "<previous_module>"
tmain_318: IF(0,318,tmain_319)__CSEQ_removeindent;
                                                        
# 5442 "<previous_module>"
__CPROVER_assume(!(__cs_local_exponential_backoff_loop < 3));
                                                        
# 5443 "<previous_module>"
__exit_loop_67:
                                                        __CPROVER_assume(__cs_pc_cs[0] >= 319);

                                                        
# 5444 "<previous_module>"
;
                                                        ;
                                                        
# 5445 "<previous_module>"
__exit__exponential_backoff_5_20:
                                                        __CPROVER_assume(__cs_pc_cs[0] >= 319);

                                                        
# 5446 "<previous_module>"
;
                                                        ;
                                                }
                                                
# 5448 "<previous_module>"
;
                                                
# 5449 "<previous_module>"
tmain_319: IF(0,319,tmain_320)__CSEQ_removeindent;
                                                
# 5450 "<previous_module>"
__cs_mutex_lock(&library_lock, 0);
                                                
# 5451 "<previous_module>"
tmain_320: IF(0,320,tmain_321)__CSEQ_removeindent;
                                                
# 5452 "<previous_module>"
__cs_mutex_unlock(&library_lock, 0);
                                        }

                                        
# 5454 "<previous_module>"
__CPROVER_assume(__cs_pc_cs[0] >= 321);
                                        ;
                                        
# 5455 "<previous_module>"
__cs_local_lfds711_stack_pop_i++;
                                        
# 5456 "<previous_module>"
;
                                        ;
                                        
# 5457 "<previous_module>"
static _Bool __cs_local_lfds711_stack_pop___cs_tmp_if_cond_13;
                                        
# 5458 "<previous_module>"
__cs_local_lfds711_stack_pop___cs_tmp_if_cond_13 = __cs_local_lfds711_stack_pop_i > 1000;
                                        
# 5459 "<previous_module>"
if (__cs_local_lfds711_stack_pop___cs_tmp_if_cond_13)

# 5460 "<previous_module>"
                                        {
                                                
# 5461 "<previous_module>"
goto __exit_loop_66;
                                                ;
                                        }

                                        
# 5463 "<previous_module>"
;
                                }
                                
# 5465 "<previous_module>"
;
                                
# 5466 "<previous_module>"
if (
# 5467 "<previous_module>"
!(__cs_local_lfds711_stack_pop_result == 0))

# 5468 "<previous_module>"
                                {
                                        
# 5469 "<previous_module>"
goto __exit_loop_66;
                                        ;
                                }

                                
# 5471 "<previous_module>"
;

# 5472 "<previous_module>"
                                {
                                        
# 5473 "<previous_module>"
;
                                        ;
                                        
# 5474 "<previous_module>"
static _Bool __cs_local_lfds711_stack_pop___cs_tmp_if_cond_11;
                                        
# 5475 "<previous_module>"
__cs_local_lfds711_stack_pop___cs_tmp_if_cond_11 = __cs_local_lfds711_stack_pop_original_top[0] == 0;
                                        
# 5476 "<previous_module>"
if (__cs_local_lfds711_stack_pop___cs_tmp_if_cond_11)

# 5477 "<previous_module>"
                                        {
                                                
# 5478 "<previous_module>"
tmain_321: IF(0,321,tmain_322)__CSEQ_removeindent;
                                                
# 5479 "<previous_module>"
*__cs_param_lfds711_stack_pop_se = 0;
                                                
# 5480 "<previous_module>"
__cs_retval__lfds711_stack_pop_2 = 0;
                                                
# 5481 "<previous_module>"
goto __exit__lfds711_stack_pop_2_4;
                                                ;
                                        }

                                        
# 5483 "<previous_module>"
__CPROVER_assume(__cs_pc_cs[0] >= 322);
                                        ;
                                        
# 5484 "<previous_module>"
tmain_322: IF(0,322,tmain_323)__CSEQ_removeindent;
                                        
# 5485 "<previous_module>"
__cs_local_lfds711_stack_pop_new_top[1] = __cs_local_lfds711_stack_pop_original_top[1] + 1;
                                        
# 5486 "<previous_module>"
tmain_323: IF(0,323,tmain_324)__CSEQ_removeindent;
                                        
# 5487 "<previous_module>"
__cs_local_lfds711_stack_pop_new_top[0] = (*__cs_local_lfds711_stack_pop_original_top[0]).next;
                                        
# 5488 "<previous_module>"
tmain_324: IF(0,324,tmain_325)__CSEQ_removeindent;
                                        
# 5489 "<previous_module>"
__cs_mutex_lock(&library_lock, 0);
                                        
# 5490 "<previous_module>"
tmain_325: IF(0,325,tmain_326)__CSEQ_removeindent;
                                        
# 5491 "<previous_module>"
__cs_local_lfds711_stack_pop_result = __CSEQ_atomic_swap_stack_top(&(*__cs_param_lfds711_stack_pop_ss).top[0], &__cs_local_lfds711_stack_pop_original_top[0], &__cs_local_lfds711_stack_pop_new_top[0]);
                                        
# 5492 "<previous_module>"
tmain_326: IF(0,326,tmain_327)__CSEQ_removeindent;
                                        
# 5493 "<previous_module>"
__cs_mutex_unlock(&library_lock, 0);
                                        
# 5494 "<previous_module>"
;
                                        ;
                                        
# 5495 "<previous_module>"
static _Bool __cs_local_lfds711_stack_pop___cs_tmp_if_cond_12;
                                        
# 5496 "<previous_module>"
__cs_local_lfds711_stack_pop___cs_tmp_if_cond_12 = __cs_local_lfds711_stack_pop_result == 0;
                                        
# 5497 "<previous_module>"
if (__cs_local_lfds711_stack_pop___cs_tmp_if_cond_12)

# 5498 "<previous_module>"
                                        {

# 5499 "<previous_module>"
                                                {
                                                        
# 5500 "<previous_module>"
static int __cs_local_exponential_backoff_loop;
                                                        
# 5501 "<previous_module>"
__cs_local_exponential_backoff_loop = 0;

# 5502 "<previous_module>"
                                                        {
                                                                
# 5503 "<previous_module>"
;
                                                                ;
                                                        }
                                                        
# 5505 "<previous_module>"
;
                                                        
# 5506 "<previous_module>"
__cs_local_exponential_backoff_loop++;

# 5507 "<previous_module>"
                                                        {
                                                                
# 5508 "<previous_module>"
;
                                                                ;
                                                        }
                                                        
# 5510 "<previous_module>"
;
                                                        
# 5511 "<previous_module>"
__cs_local_exponential_backoff_loop++;

# 5512 "<previous_module>"
                                                        {
                                                                
# 5513 "<previous_module>"
;
                                                                ;
                                                        }
                                                        
# 5515 "<previous_module>"
;
                                                        
# 5516 "<previous_module>"
__cs_local_exponential_backoff_loop++;
                                                        
# 5517 "<previous_module>"
tmain_327: IF(0,327,tmain_328)__CSEQ_removeindent;
                                                        
# 5518 "<previous_module>"
__CPROVER_assume(!(__cs_local_exponential_backoff_loop < 3));
                                                        
# 5519 "<previous_module>"
__exit_loop_68:
                                                        __CPROVER_assume(__cs_pc_cs[0] >= 328);

                                                        
# 5520 "<previous_module>"
;
                                                        ;
                                                        
# 5521 "<previous_module>"
__exit__exponential_backoff_5_21:
                                                        __CPROVER_assume(__cs_pc_cs[0] >= 328);

                                                        
# 5522 "<previous_module>"
;
                                                        ;
                                                }
                                                
# 5524 "<previous_module>"
;
                                                
# 5525 "<previous_module>"
tmain_328: IF(0,328,tmain_329)__CSEQ_removeindent;
                                                
# 5526 "<previous_module>"
__cs_mutex_lock(&library_lock, 0);
                                                
# 5527 "<previous_module>"
tmain_329: IF(0,329,tmain_330)__CSEQ_removeindent;
                                                
# 5528 "<previous_module>"
__cs_mutex_unlock(&library_lock, 0);
                                        }

                                        
# 5530 "<previous_module>"
__CPROVER_assume(__cs_pc_cs[0] >= 330);
                                        ;
                                        
# 5531 "<previous_module>"
__cs_local_lfds711_stack_pop_i++;
                                        
# 5532 "<previous_module>"
;
                                        ;
                                        
# 5533 "<previous_module>"
static _Bool __cs_local_lfds711_stack_pop___cs_tmp_if_cond_13;
                                        
# 5534 "<previous_module>"
__cs_local_lfds711_stack_pop___cs_tmp_if_cond_13 = __cs_local_lfds711_stack_pop_i > 1000;
                                        
# 5535 "<previous_module>"
if (__cs_local_lfds711_stack_pop___cs_tmp_if_cond_13)

# 5536 "<previous_module>"
                                        {
                                                
# 5537 "<previous_module>"
goto __exit_loop_66;
                                                ;
                                        }

                                        
# 5539 "<previous_module>"
;
                                }
                                
# 5541 "<previous_module>"
;
                                
# 5542 "<previous_module>"
if (
# 5543 "<previous_module>"
!(__cs_local_lfds711_stack_pop_result == 0))

# 5544 "<previous_module>"
                                {
                                        
# 5545 "<previous_module>"
goto __exit_loop_66;
                                        ;
                                }

                                
# 5547 "<previous_module>"
;

# 5548 "<previous_module>"
                                {
                                        
# 5549 "<previous_module>"
;
                                        ;
                                        
# 5550 "<previous_module>"
static _Bool __cs_local_lfds711_stack_pop___cs_tmp_if_cond_11;
                                        
# 5551 "<previous_module>"
__cs_local_lfds711_stack_pop___cs_tmp_if_cond_11 = __cs_local_lfds711_stack_pop_original_top[0] == 0;
                                        
# 5552 "<previous_module>"
if (__cs_local_lfds711_stack_pop___cs_tmp_if_cond_11)

# 5553 "<previous_module>"
                                        {
                                                
# 5554 "<previous_module>"
tmain_330: IF(0,330,tmain_331)__CSEQ_removeindent;
                                                
# 5555 "<previous_module>"
*__cs_param_lfds711_stack_pop_se = 0;
                                                
# 5556 "<previous_module>"
__cs_retval__lfds711_stack_pop_2 = 0;
                                                
# 5557 "<previous_module>"
goto __exit__lfds711_stack_pop_2_4;
                                                ;
                                        }

                                        
# 5559 "<previous_module>"
__CPROVER_assume(__cs_pc_cs[0] >= 331);
                                        ;
                                        
# 5560 "<previous_module>"
tmain_331: IF(0,331,tmain_332)__CSEQ_removeindent;
                                        
# 5561 "<previous_module>"
__cs_local_lfds711_stack_pop_new_top[1] = __cs_local_lfds711_stack_pop_original_top[1] + 1;
                                        
# 5562 "<previous_module>"
tmain_332: IF(0,332,tmain_333)__CSEQ_removeindent;
                                        
# 5563 "<previous_module>"
__cs_local_lfds711_stack_pop_new_top[0] = (*__cs_local_lfds711_stack_pop_original_top[0]).next;
                                        
# 5564 "<previous_module>"
tmain_333: IF(0,333,tmain_334)__CSEQ_removeindent;
                                        
# 5565 "<previous_module>"
__cs_mutex_lock(&library_lock, 0);
                                        
# 5566 "<previous_module>"
tmain_334: IF(0,334,tmain_335)__CSEQ_removeindent;
                                        
# 5567 "<previous_module>"
__cs_local_lfds711_stack_pop_result = __CSEQ_atomic_swap_stack_top(&(*__cs_param_lfds711_stack_pop_ss).top[0], &__cs_local_lfds711_stack_pop_original_top[0], &__cs_local_lfds711_stack_pop_new_top[0]);
                                        
# 5568 "<previous_module>"
tmain_335: IF(0,335,tmain_336)__CSEQ_removeindent;
                                        
# 5569 "<previous_module>"
__cs_mutex_unlock(&library_lock, 0);
                                        
# 5570 "<previous_module>"
;
                                        ;
                                        
# 5571 "<previous_module>"
static _Bool __cs_local_lfds711_stack_pop___cs_tmp_if_cond_12;
                                        
# 5572 "<previous_module>"
__cs_local_lfds711_stack_pop___cs_tmp_if_cond_12 = __cs_local_lfds711_stack_pop_result == 0;
                                        
# 5573 "<previous_module>"
if (__cs_local_lfds711_stack_pop___cs_tmp_if_cond_12)

# 5574 "<previous_module>"
                                        {

# 5575 "<previous_module>"
                                                {
                                                        
# 5576 "<previous_module>"
static int __cs_local_exponential_backoff_loop;
                                                        
# 5577 "<previous_module>"
__cs_local_exponential_backoff_loop = 0;

# 5578 "<previous_module>"
                                                        {
                                                                
# 5579 "<previous_module>"
;
                                                                ;
                                                        }
                                                        
# 5581 "<previous_module>"
;
                                                        
# 5582 "<previous_module>"
__cs_local_exponential_backoff_loop++;

# 5583 "<previous_module>"
                                                        {
                                                                
# 5584 "<previous_module>"
;
                                                                ;
                                                        }
                                                        
# 5586 "<previous_module>"
;
                                                        
# 5587 "<previous_module>"
__cs_local_exponential_backoff_loop++;

# 5588 "<previous_module>"
                                                        {
                                                                
# 5589 "<previous_module>"
;
                                                                ;
                                                        }
                                                        
# 5591 "<previous_module>"
;
                                                        
# 5592 "<previous_module>"
__cs_local_exponential_backoff_loop++;
                                                        
# 5593 "<previous_module>"
tmain_336: IF(0,336,tmain_337)__CSEQ_removeindent;
                                                        
# 5594 "<previous_module>"
__CPROVER_assume(!(__cs_local_exponential_backoff_loop < 3));
                                                        
# 5595 "<previous_module>"
__exit_loop_69:
                                                        __CPROVER_assume(__cs_pc_cs[0] >= 337);

                                                        
# 5596 "<previous_module>"
;
                                                        ;
                                                        
# 5597 "<previous_module>"
__exit__exponential_backoff_5_22:
                                                        __CPROVER_assume(__cs_pc_cs[0] >= 337);

                                                        
# 5598 "<previous_module>"
;
                                                        ;
                                                }
                                                
# 5600 "<previous_module>"
;
                                                
# 5601 "<previous_module>"
tmain_337: IF(0,337,tmain_338)__CSEQ_removeindent;
                                                
# 5602 "<previous_module>"
__cs_mutex_lock(&library_lock, 0);
                                                
# 5603 "<previous_module>"
tmain_338: IF(0,338,tmain_339)__CSEQ_removeindent;
                                                
# 5604 "<previous_module>"
__cs_mutex_unlock(&library_lock, 0);
                                        }

                                        
# 5606 "<previous_module>"
__CPROVER_assume(__cs_pc_cs[0] >= 339);
                                        ;
                                        
# 5607 "<previous_module>"
__cs_local_lfds711_stack_pop_i++;
                                        
# 5608 "<previous_module>"
;
                                        ;
                                        
# 5609 "<previous_module>"
static _Bool __cs_local_lfds711_stack_pop___cs_tmp_if_cond_13;
                                        
# 5610 "<previous_module>"
__cs_local_lfds711_stack_pop___cs_tmp_if_cond_13 = __cs_local_lfds711_stack_pop_i > 1000;
                                        
# 5611 "<previous_module>"
if (__cs_local_lfds711_stack_pop___cs_tmp_if_cond_13)

# 5612 "<previous_module>"
                                        {
                                                
# 5613 "<previous_module>"
goto __exit_loop_66;
                                                ;
                                        }

                                        
# 5615 "<previous_module>"
;
                                }
                                
# 5617 "<previous_module>"
;
                                
# 5618 "<previous_module>"
if (
# 5619 "<previous_module>"
!(__cs_local_lfds711_stack_pop_result == 0))

# 5620 "<previous_module>"
                                {
                                        
# 5621 "<previous_module>"
goto __exit_loop_66;
                                        ;
                                }

                                
# 5623 "<previous_module>"
;

# 5624 "<previous_module>"
                                {
                                        
# 5625 "<previous_module>"
;
                                        ;
                                        
# 5626 "<previous_module>"
static _Bool __cs_local_lfds711_stack_pop___cs_tmp_if_cond_11;
                                        
# 5627 "<previous_module>"
__cs_local_lfds711_stack_pop___cs_tmp_if_cond_11 = __cs_local_lfds711_stack_pop_original_top[0] == 0;
                                        
# 5628 "<previous_module>"
if (__cs_local_lfds711_stack_pop___cs_tmp_if_cond_11)

# 5629 "<previous_module>"
                                        {
                                                
# 5630 "<previous_module>"
tmain_339: IF(0,339,tmain_340)__CSEQ_removeindent;
                                                
# 5631 "<previous_module>"
*__cs_param_lfds711_stack_pop_se = 0;
                                                
# 5632 "<previous_module>"
__cs_retval__lfds711_stack_pop_2 = 0;
                                                
# 5633 "<previous_module>"
goto __exit__lfds711_stack_pop_2_4;
                                                ;
                                        }

                                        
# 5635 "<previous_module>"
__CPROVER_assume(__cs_pc_cs[0] >= 340);
                                        ;
                                        
# 5636 "<previous_module>"
tmain_340: IF(0,340,tmain_341)__CSEQ_removeindent;
                                        
# 5637 "<previous_module>"
__cs_local_lfds711_stack_pop_new_top[1] = __cs_local_lfds711_stack_pop_original_top[1] + 1;
                                        
# 5638 "<previous_module>"
tmain_341: IF(0,341,tmain_342)__CSEQ_removeindent;
                                        
# 5639 "<previous_module>"
__cs_local_lfds711_stack_pop_new_top[0] = (*__cs_local_lfds711_stack_pop_original_top[0]).next;
                                        
# 5640 "<previous_module>"
tmain_342: IF(0,342,tmain_343)__CSEQ_removeindent;
                                        
# 5641 "<previous_module>"
__cs_mutex_lock(&library_lock, 0);
                                        
# 5642 "<previous_module>"
tmain_343: IF(0,343,tmain_344)__CSEQ_removeindent;
                                        
# 5643 "<previous_module>"
__cs_local_lfds711_stack_pop_result = __CSEQ_atomic_swap_stack_top(&(*__cs_param_lfds711_stack_pop_ss).top[0], &__cs_local_lfds711_stack_pop_original_top[0], &__cs_local_lfds711_stack_pop_new_top[0]);
                                        
# 5644 "<previous_module>"
tmain_344: IF(0,344,tmain_345)__CSEQ_removeindent;
                                        
# 5645 "<previous_module>"
__cs_mutex_unlock(&library_lock, 0);
                                        
# 5646 "<previous_module>"
;
                                        ;
                                        
# 5647 "<previous_module>"
static _Bool __cs_local_lfds711_stack_pop___cs_tmp_if_cond_12;
                                        
# 5648 "<previous_module>"
__cs_local_lfds711_stack_pop___cs_tmp_if_cond_12 = __cs_local_lfds711_stack_pop_result == 0;
                                        
# 5649 "<previous_module>"
if (__cs_local_lfds711_stack_pop___cs_tmp_if_cond_12)

# 5650 "<previous_module>"
                                        {

# 5651 "<previous_module>"
                                                {
                                                        
# 5652 "<previous_module>"
static int __cs_local_exponential_backoff_loop;
                                                        
# 5653 "<previous_module>"
__cs_local_exponential_backoff_loop = 0;

# 5654 "<previous_module>"
                                                        {
                                                                
# 5655 "<previous_module>"
;
                                                                ;
                                                        }
                                                        
# 5657 "<previous_module>"
;
                                                        
# 5658 "<previous_module>"
__cs_local_exponential_backoff_loop++;

# 5659 "<previous_module>"
                                                        {
                                                                
# 5660 "<previous_module>"
;
                                                                ;
                                                        }
                                                        
# 5662 "<previous_module>"
;
                                                        
# 5663 "<previous_module>"
__cs_local_exponential_backoff_loop++;

# 5664 "<previous_module>"
                                                        {
                                                                
# 5665 "<previous_module>"
;
                                                                ;
                                                        }
                                                        
# 5667 "<previous_module>"
;
                                                        
# 5668 "<previous_module>"
__cs_local_exponential_backoff_loop++;
                                                        
# 5669 "<previous_module>"
tmain_345: IF(0,345,tmain_346)__CSEQ_removeindent;
                                                        
# 5670 "<previous_module>"
__CPROVER_assume(!(__cs_local_exponential_backoff_loop < 3));
                                                        
# 5671 "<previous_module>"
__exit_loop_70:
                                                        __CPROVER_assume(__cs_pc_cs[0] >= 346);

                                                        
# 5672 "<previous_module>"
;
                                                        ;
                                                        
# 5673 "<previous_module>"
__exit__exponential_backoff_5_23:
                                                        __CPROVER_assume(__cs_pc_cs[0] >= 346);

                                                        
# 5674 "<previous_module>"
;
                                                        ;
                                                }
                                                
# 5676 "<previous_module>"
;
                                                
# 5677 "<previous_module>"
tmain_346: IF(0,346,tmain_347)__CSEQ_removeindent;
                                                
# 5678 "<previous_module>"
__cs_mutex_lock(&library_lock, 0);
                                                
# 5679 "<previous_module>"
tmain_347: IF(0,347,tmain_348)__CSEQ_removeindent;
                                                
# 5680 "<previous_module>"
__cs_mutex_unlock(&library_lock, 0);
                                        }

                                        
# 5682 "<previous_module>"
__CPROVER_assume(__cs_pc_cs[0] >= 348);
                                        ;
                                        
# 5683 "<previous_module>"
__cs_local_lfds711_stack_pop_i++;
                                        
# 5684 "<previous_module>"
;
                                        ;
                                        
# 5685 "<previous_module>"
static _Bool __cs_local_lfds711_stack_pop___cs_tmp_if_cond_13;
                                        
# 5686 "<previous_module>"
__cs_local_lfds711_stack_pop___cs_tmp_if_cond_13 = __cs_local_lfds711_stack_pop_i > 1000;
                                        
# 5687 "<previous_module>"
if (__cs_local_lfds711_stack_pop___cs_tmp_if_cond_13)

# 5688 "<previous_module>"
                                        {
                                                
# 5689 "<previous_module>"
goto __exit_loop_66;
                                                ;
                                        }

                                        
# 5691 "<previous_module>"
;
                                }
                                
# 5693 "<previous_module>"
;
                                
# 5694 "<previous_module>"
if (
# 5695 "<previous_module>"
!(__cs_local_lfds711_stack_pop_result == 0))

# 5696 "<previous_module>"
                                {
                                        
# 5697 "<previous_module>"
goto __exit_loop_66;
                                        ;
                                }

                                
# 5699 "<previous_module>"
;

# 5700 "<previous_module>"
                                {
                                        
# 5701 "<previous_module>"
;
                                        ;
                                        
# 5702 "<previous_module>"
static _Bool __cs_local_lfds711_stack_pop___cs_tmp_if_cond_11;
                                        
# 5703 "<previous_module>"
__cs_local_lfds711_stack_pop___cs_tmp_if_cond_11 = __cs_local_lfds711_stack_pop_original_top[0] == 0;
                                        
# 5704 "<previous_module>"
if (__cs_local_lfds711_stack_pop___cs_tmp_if_cond_11)

# 5705 "<previous_module>"
                                        {
                                                
# 5706 "<previous_module>"
tmain_348: IF(0,348,tmain_349)__CSEQ_removeindent;
                                                
# 5707 "<previous_module>"
*__cs_param_lfds711_stack_pop_se = 0;
                                                
# 5708 "<previous_module>"
__cs_retval__lfds711_stack_pop_2 = 0;
                                                
# 5709 "<previous_module>"
goto __exit__lfds711_stack_pop_2_4;
                                                ;
                                        }

                                        
# 5711 "<previous_module>"
__CPROVER_assume(__cs_pc_cs[0] >= 349);
                                        ;
                                        
# 5712 "<previous_module>"
tmain_349: IF(0,349,tmain_350)__CSEQ_removeindent;
                                        
# 5713 "<previous_module>"
__cs_local_lfds711_stack_pop_new_top[1] = __cs_local_lfds711_stack_pop_original_top[1] + 1;
                                        
# 5714 "<previous_module>"
tmain_350: IF(0,350,tmain_351)__CSEQ_removeindent;
                                        
# 5715 "<previous_module>"
__cs_local_lfds711_stack_pop_new_top[0] = (*__cs_local_lfds711_stack_pop_original_top[0]).next;
                                        
# 5716 "<previous_module>"
tmain_351: IF(0,351,tmain_352)__CSEQ_removeindent;
                                        
# 5717 "<previous_module>"
__cs_mutex_lock(&library_lock, 0);
                                        
# 5718 "<previous_module>"
tmain_352: IF(0,352,tmain_353)__CSEQ_removeindent;
                                        
# 5719 "<previous_module>"
__cs_local_lfds711_stack_pop_result = __CSEQ_atomic_swap_stack_top(&(*__cs_param_lfds711_stack_pop_ss).top[0], &__cs_local_lfds711_stack_pop_original_top[0], &__cs_local_lfds711_stack_pop_new_top[0]);
                                        
# 5720 "<previous_module>"
tmain_353: IF(0,353,tmain_354)__CSEQ_removeindent;
                                        
# 5721 "<previous_module>"
__cs_mutex_unlock(&library_lock, 0);
                                        
# 5722 "<previous_module>"
;
                                        ;
                                        
# 5723 "<previous_module>"
static _Bool __cs_local_lfds711_stack_pop___cs_tmp_if_cond_12;
                                        
# 5724 "<previous_module>"
__cs_local_lfds711_stack_pop___cs_tmp_if_cond_12 = __cs_local_lfds711_stack_pop_result == 0;
                                        
# 5725 "<previous_module>"
if (__cs_local_lfds711_stack_pop___cs_tmp_if_cond_12)

# 5726 "<previous_module>"
                                        {

# 5727 "<previous_module>"
                                                {
                                                        
# 5728 "<previous_module>"
static int __cs_local_exponential_backoff_loop;
                                                        
# 5729 "<previous_module>"
__cs_local_exponential_backoff_loop = 0;

# 5730 "<previous_module>"
                                                        {
                                                                
# 5731 "<previous_module>"
;
                                                                ;
                                                        }
                                                        
# 5733 "<previous_module>"
;
                                                        
# 5734 "<previous_module>"
__cs_local_exponential_backoff_loop++;

# 5735 "<previous_module>"
                                                        {
                                                                
# 5736 "<previous_module>"
;
                                                                ;
                                                        }
                                                        
# 5738 "<previous_module>"
;
                                                        
# 5739 "<previous_module>"
__cs_local_exponential_backoff_loop++;

# 5740 "<previous_module>"
                                                        {
                                                                
# 5741 "<previous_module>"
;
                                                                ;
                                                        }
                                                        
# 5743 "<previous_module>"
;
                                                        
# 5744 "<previous_module>"
__cs_local_exponential_backoff_loop++;
                                                        
# 5745 "<previous_module>"
tmain_354: IF(0,354,tmain_355)__CSEQ_removeindent;
                                                        
# 5746 "<previous_module>"
__CPROVER_assume(!(__cs_local_exponential_backoff_loop < 3));
                                                        
# 5747 "<previous_module>"
__exit_loop_71:
                                                        __CPROVER_assume(__cs_pc_cs[0] >= 355);

                                                        
# 5748 "<previous_module>"
;
                                                        ;
                                                        
# 5749 "<previous_module>"
__exit__exponential_backoff_5_24:
                                                        __CPROVER_assume(__cs_pc_cs[0] >= 355);

                                                        
# 5750 "<previous_module>"
;
                                                        ;
                                                }
                                                
# 5752 "<previous_module>"
;
                                                
# 5753 "<previous_module>"
tmain_355: IF(0,355,tmain_356)__CSEQ_removeindent;
                                                
# 5754 "<previous_module>"
__cs_mutex_lock(&library_lock, 0);
                                                
# 5755 "<previous_module>"
tmain_356: IF(0,356,tmain_357)__CSEQ_removeindent;
                                                
# 5756 "<previous_module>"
__cs_mutex_unlock(&library_lock, 0);
                                        }

                                        
# 5758 "<previous_module>"
__CPROVER_assume(__cs_pc_cs[0] >= 357);
                                        ;
                                        
# 5759 "<previous_module>"
__cs_local_lfds711_stack_pop_i++;
                                        
# 5760 "<previous_module>"
;
                                        ;
                                        
# 5761 "<previous_module>"
static _Bool __cs_local_lfds711_stack_pop___cs_tmp_if_cond_13;
                                        
# 5762 "<previous_module>"
__cs_local_lfds711_stack_pop___cs_tmp_if_cond_13 = __cs_local_lfds711_stack_pop_i > 1000;
                                        
# 5763 "<previous_module>"
if (__cs_local_lfds711_stack_pop___cs_tmp_if_cond_13)

# 5764 "<previous_module>"
                                        {
                                                
# 5765 "<previous_module>"
goto __exit_loop_66;
                                                ;
                                        }

                                        
# 5767 "<previous_module>"
;
                                }
                                
# 5769 "<previous_module>"
;
                                
# 5770 "<previous_module>"
tmain_357: IF(0,357,tmain_358)__CSEQ_removeindent;
                                
# 5771 "<previous_module>"
__CPROVER_assume(
# 5772 "<previous_module>"
!(__cs_local_lfds711_stack_pop_result == 0));
                                
# 5773 "<previous_module>"
__exit_loop_66:
                                __CPROVER_assume(__cs_pc_cs[0] >= 358);

                                
# 5774 "<previous_module>"
;
                                ;
                                
# 5775 "<previous_module>"
tmain_358: IF(0,358,tmain_359)__CSEQ_removeindent;
                                
# 5776 "<previous_module>"
*__cs_param_lfds711_stack_pop_se = __cs_local_lfds711_stack_pop_original_top[0];
                                
# 5777 "<previous_module>"
__cs_retval__lfds711_stack_pop_2 = __cs_local_lfds711_stack_pop_result;
                                
# 5778 "<previous_module>"
goto __exit__lfds711_stack_pop_2_4;
                                ;
                                
# 5779 "<previous_module>"
__exit__lfds711_stack_pop_2_4:
                                __CPROVER_assume(__cs_pc_cs[0] >= 359);

                                
# 5780 "<previous_module>"
;
                                ;
                        }
                        
# 5782 "<previous_module>"
;
                        
# 5783 "<previous_module>"
__cs_local_contains_res = __cs_retval__lfds711_stack_pop_2;
                        
# 5784 "<previous_module>"
;
                        ;
                        
# 5785 "<previous_module>"
static _Bool __cs_local_contains___cs_tmp_if_cond_20;
                        
# 5786 "<previous_module>"
__cs_local_contains___cs_tmp_if_cond_20 = __cs_local_contains_res == 0;
                        
# 5787 "<previous_module>"
if (__cs_local_contains___cs_tmp_if_cond_20)

# 5788 "<previous_module>"
                        {
                                
# 5789 "<previous_module>"
goto __exit_loop_31;
                                ;
                        }

                        
# 5791 "<previous_module>"
;
                        
# 5792 "<previous_module>"
tmain_359: IF(0,359,tmain_360)__CSEQ_removeindent;
                        
# 5793 "<previous_module>"
__cs_local_contains_datas[__cs_local_contains_actual_size] = (*__cs_local_contains_se).value;
                        
# 5794 "<previous_module>"
;
                        ;
                        
# 5795 "<previous_module>"
static _Bool __cs_local_contains___cs_tmp_if_cond_21;
                        
# 5796 "<previous_module>"
tmain_360: IF(0,360,tmain_361)__CSEQ_removeindent;
                        
# 5797 "<previous_module>"
__cs_local_contains___cs_tmp_if_cond_21 = (*__cs_local_contains_datas[__cs_local_contains_actual_size]).user_id == __cs_param_contains_id;
                        
# 5798 "<previous_module>"
if (__cs_local_contains___cs_tmp_if_cond_21)

# 5799 "<previous_module>"
                        {
                                
# 5800 "<previous_module>"
__cs_local_contains_found = 1;
                        }

                        
# 5802 "<previous_module>"
;
                        
# 5803 "<previous_module>"
__cs_local_contains_actual_size = __cs_local_contains_actual_size + 1;
                }
                
# 5805 "<previous_module>"
;
                
# 5806 "<previous_module>"
tmain_361: IF(0,361,tmain_362)__CSEQ_removeindent;
                
# 5807 "<previous_module>"
__CPROVER_assume(!(__cs_local_contains_actual_size < 2));
                
# 5808 "<previous_module>"
__exit_loop_31:
                __CPROVER_assume(__cs_pc_cs[0] >= 362);

                
# 5809 "<previous_module>"
;
                ;
                
# 5810 "<previous_module>"
static int __cs_local_contains_i;
                
# 5811 "<previous_module>"
__cs_local_contains_i = 0;
                
# 5812 "<previous_module>"
if (!(__cs_local_contains_i < __cs_local_contains_actual_size))

# 5813 "<previous_module>"
                {
                        
# 5814 "<previous_module>"
goto __exit_loop_72;
                        ;
                }

                
# 5816 "<previous_module>"
;

# 5817 "<previous_module>"
                {

# 5818 "<previous_module>"
                        {
                                
# 5819 "<previous_module>"
static struct lfds711_stack_state *__cs_param_lfds711_stack_push_ss;
                                
# 5820 "<previous_module>"
tmain_362: IF(0,362,tmain_363)__CSEQ_removeindent;
                                
# 5821 "<previous_module>"
__cs_param_lfds711_stack_push_ss = __cs_param_contains_s;
                                
# 5822 "<previous_module>"
static struct lfds711_stack_element *__cs_param_lfds711_stack_push_se;
                                
# 5823 "<previous_module>"
tmain_363: IF(0,363,tmain_364)__CSEQ_removeindent;
                                
# 5824 "<previous_module>"
__cs_param_lfds711_stack_push_se = &(*__cs_local_contains_datas[__cs_local_contains_i]).se;
                                
# 5825 "<previous_module>"
static char unsigned __cs_local_lfds711_stack_push_result;
                                
# 5826 "<previous_module>"
static lfds711_pal_uint_t __cs_local_lfds711_stack_push_backoff_iteration;
                                
# 5827 "<previous_module>"
__cs_local_lfds711_stack_push_backoff_iteration = 0;
                                
# 5828 "<previous_module>"
static struct lfds711_stack_element *__cs_local_lfds711_stack_push_new_top[2];
                                
# 5829 "<previous_module>"
static struct lfds711_stack_element * volatile __cs_local_lfds711_stack_push_original_top[2];
                                
# 5830 "<previous_module>"
;
                                ;
                                
# 5831 "<previous_module>"
static _Bool __cs_local_lfds711_stack_push___cs_tmp_if_cond_14;
                                
# 5832 "<previous_module>"
tmain_364: IF(0,364,tmain_365)__CSEQ_removeindent;
                                
# 5833 "<previous_module>"
__cs_local_lfds711_stack_push___cs_tmp_if_cond_14 = !(__cs_param_lfds711_stack_push_ss != 0);
                                
# 5834 "<previous_module>"
if (__cs_local_lfds711_stack_push___cs_tmp_if_cond_14)

# 5835 "<previous_module>"
                                {
                                        
# 5836 "<previous_module>"
static char *__cs_local_lfds711_stack_push_c;
                                        
# 5837 "<previous_module>"
tmain_365: IF(0,365,tmain_366)__CSEQ_removeindent;
                                        
# 5838 "<previous_module>"
__cs_local_lfds711_stack_push_c = 0;
                                        
# 5839 "<previous_module>"
tmain_366: IF(0,366,tmain_367)__CSEQ_removeindent;
                                        
# 5840 "<previous_module>"
*__cs_local_lfds711_stack_push_c = 0;
                                }

                                
# 5842 "<previous_module>"
__CPROVER_assume(__cs_pc_cs[0] >= 367);
                                ;
                                
# 5843 "<previous_module>"
;
                                ;
                                
# 5844 "<previous_module>"
;
                                ;
                                
# 5845 "<previous_module>"
;
                                ;
                                
# 5846 "<previous_module>"
static _Bool __cs_local_lfds711_stack_push___cs_tmp_if_cond_15;
                                
# 5847 "<previous_module>"
tmain_367: IF(0,367,tmain_368)__CSEQ_removeindent;
                                
# 5848 "<previous_module>"
__cs_local_lfds711_stack_push___cs_tmp_if_cond_15 = !(__cs_param_lfds711_stack_push_se != 0);
                                
# 5849 "<previous_module>"
if (__cs_local_lfds711_stack_push___cs_tmp_if_cond_15)

# 5850 "<previous_module>"
                                {
                                        
# 5851 "<previous_module>"
static char *__cs_local_lfds711_stack_push_c;
                                        
# 5852 "<previous_module>"
tmain_368: IF(0,368,tmain_369)__CSEQ_removeindent;
                                        
# 5853 "<previous_module>"
__cs_local_lfds711_stack_push_c = 0;
                                        
# 5854 "<previous_module>"
tmain_369: IF(0,369,tmain_370)__CSEQ_removeindent;
                                        
# 5855 "<previous_module>"
*__cs_local_lfds711_stack_push_c = 0;
                                }

                                
# 5857 "<previous_module>"
__CPROVER_assume(__cs_pc_cs[0] >= 370);
                                ;
                                
# 5858 "<previous_module>"
;
                                ;
                                
# 5859 "<previous_module>"
;
                                ;
                                
# 5860 "<previous_module>"
tmain_370: IF(0,370,tmain_371)__CSEQ_removeindent;
                                
# 5861 "<previous_module>"
__cs_local_lfds711_stack_push_new_top[0] = __cs_param_lfds711_stack_push_se;
                                
# 5862 "<previous_module>"
tmain_371: IF(0,371,tmain_372)__CSEQ_removeindent;
                                
# 5863 "<previous_module>"
__cs_local_lfds711_stack_push_original_top[1] = (*__cs_param_lfds711_stack_push_ss).top[1];
                                
# 5864 "<previous_module>"
tmain_372: IF(0,372,tmain_373)__CSEQ_removeindent;
                                
# 5865 "<previous_module>"
__cs_local_lfds711_stack_push_original_top[0] = (*__cs_param_lfds711_stack_push_ss).top[0];
                                
# 5866 "<previous_module>"
__cs_local_lfds711_stack_push_result = 0;
                                
# 5867 "<previous_module>"
static int __cs_local_lfds711_stack_push_i;
                                
# 5868 "<previous_module>"
__cs_local_lfds711_stack_push_i = 0;
                                
# 5869 "<previous_module>"
if (!(__cs_local_lfds711_stack_push_result == 0))

# 5870 "<previous_module>"
                                {
                                        
# 5871 "<previous_module>"
goto __exit_loop_73;
                                        ;
                                }

                                
# 5873 "<previous_module>"
;

# 5874 "<previous_module>"
                                {
                                        
# 5875 "<previous_module>"
tmain_373: IF(0,373,tmain_374)__CSEQ_removeindent;
                                        
# 5876 "<previous_module>"
__cs_mutex_lock(&library_lock, 0);
                                        
# 5877 "<previous_module>"
tmain_374: IF(0,374,tmain_375)__CSEQ_removeindent;
                                        
# 5878 "<previous_module>"
(*__cs_param_lfds711_stack_push_se).next = __cs_local_lfds711_stack_push_original_top[0];
                                        
# 5879 "<previous_module>"
tmain_375: IF(0,375,tmain_376)__CSEQ_removeindent;
                                        
# 5880 "<previous_module>"
__cs_mutex_unlock(&library_lock, 0);
                                        
# 5881 "<previous_module>"
tmain_376: IF(0,376,tmain_377)__CSEQ_removeindent;
                                        
# 5882 "<previous_module>"
__cs_local_lfds711_stack_push_new_top[1] = __cs_local_lfds711_stack_push_original_top[1] + 1;
                                        
# 5883 "<previous_module>"
tmain_377: IF(0,377,tmain_378)__CSEQ_removeindent;
                                        
# 5884 "<previous_module>"
__cs_mutex_lock(&library_lock, 0);
                                        
# 5885 "<previous_module>"
tmain_378: IF(0,378,tmain_379)__CSEQ_removeindent;
                                        
# 5886 "<previous_module>"
__cs_local_lfds711_stack_push_result = __CSEQ_atomic_swap_stack_top(&(*__cs_param_lfds711_stack_push_ss).top[0], &__cs_local_lfds711_stack_push_original_top[0], &__cs_local_lfds711_stack_push_new_top[0]);
                                        
# 5887 "<previous_module>"
tmain_379: IF(0,379,tmain_380)__CSEQ_removeindent;
                                        
# 5888 "<previous_module>"
__cs_mutex_unlock(&library_lock, 0);
                                        
# 5889 "<previous_module>"
;
                                        ;
                                        
# 5890 "<previous_module>"
static _Bool __cs_local_lfds711_stack_push___cs_tmp_if_cond_16;
                                        
# 5891 "<previous_module>"
__cs_local_lfds711_stack_push___cs_tmp_if_cond_16 = __cs_local_lfds711_stack_push_result == 0;
                                        
# 5892 "<previous_module>"
if (__cs_local_lfds711_stack_push___cs_tmp_if_cond_16)

# 5893 "<previous_module>"
                                        {

# 5894 "<previous_module>"
                                                {
                                                        
# 5895 "<previous_module>"
static int __cs_local_exponential_backoff_loop;
                                                        
# 5896 "<previous_module>"
__cs_local_exponential_backoff_loop = 0;

# 5897 "<previous_module>"
                                                        {
                                                                
# 5898 "<previous_module>"
;
                                                                ;
                                                        }
                                                        
# 5900 "<previous_module>"
;
                                                        
# 5901 "<previous_module>"
__cs_local_exponential_backoff_loop++;

# 5902 "<previous_module>"
                                                        {
                                                                
# 5903 "<previous_module>"
;
                                                                ;
                                                        }
                                                        
# 5905 "<previous_module>"
;
                                                        
# 5906 "<previous_module>"
__cs_local_exponential_backoff_loop++;

# 5907 "<previous_module>"
                                                        {
                                                                
# 5908 "<previous_module>"
;
                                                                ;
                                                        }
                                                        
# 5910 "<previous_module>"
;
                                                        
# 5911 "<previous_module>"
__cs_local_exponential_backoff_loop++;
                                                        
# 5912 "<previous_module>"
tmain_380: IF(0,380,tmain_381)__CSEQ_removeindent;
                                                        
# 5913 "<previous_module>"
__CPROVER_assume(!(__cs_local_exponential_backoff_loop < 3));
                                                        
# 5914 "<previous_module>"
__exit_loop_74:
                                                        __CPROVER_assume(__cs_pc_cs[0] >= 381);

                                                        
# 5915 "<previous_module>"
;
                                                        ;
                                                        
# 5916 "<previous_module>"
__exit__exponential_backoff_6_0:
                                                        __CPROVER_assume(__cs_pc_cs[0] >= 381);

                                                        
# 5917 "<previous_module>"
;
                                                        ;
                                                }
                                                
# 5919 "<previous_module>"
;
                                        }

                                        
# 5921 "<previous_module>"
__CPROVER_assume(__cs_pc_cs[0] >= 381);
                                        ;
                                        
# 5922 "<previous_module>"
__cs_local_lfds711_stack_push_i++;
                                        
# 5923 "<previous_module>"
;
                                        ;
                                        
# 5924 "<previous_module>"
static _Bool __cs_local_lfds711_stack_push___cs_tmp_if_cond_17;
                                        
# 5925 "<previous_module>"
__cs_local_lfds711_stack_push___cs_tmp_if_cond_17 = __cs_local_lfds711_stack_push_i > 1000;
                                        
# 5926 "<previous_module>"
if (__cs_local_lfds711_stack_push___cs_tmp_if_cond_17)

# 5927 "<previous_module>"
                                        {
                                                
# 5928 "<previous_module>"
goto __exit_loop_73;
                                                ;
                                        }

                                        
# 5930 "<previous_module>"
;
                                }
                                
# 5932 "<previous_module>"
;
                                
# 5933 "<previous_module>"
if (!(__cs_local_lfds711_stack_push_result == 0))

# 5934 "<previous_module>"
                                {
                                        
# 5935 "<previous_module>"
goto __exit_loop_73;
                                        ;
                                }

                                
# 5937 "<previous_module>"
;

# 5938 "<previous_module>"
                                {
                                        
# 5939 "<previous_module>"
tmain_381: IF(0,381,tmain_382)__CSEQ_removeindent;
                                        
# 5940 "<previous_module>"
__cs_mutex_lock(&library_lock, 0);
                                        
# 5941 "<previous_module>"
tmain_382: IF(0,382,tmain_383)__CSEQ_removeindent;
                                        
# 5942 "<previous_module>"
(*__cs_param_lfds711_stack_push_se).next = __cs_local_lfds711_stack_push_original_top[0];
                                        
# 5943 "<previous_module>"
tmain_383: IF(0,383,tmain_384)__CSEQ_removeindent;
                                        
# 5944 "<previous_module>"
__cs_mutex_unlock(&library_lock, 0);
                                        
# 5945 "<previous_module>"
tmain_384: IF(0,384,tmain_385)__CSEQ_removeindent;
                                        
# 5946 "<previous_module>"
__cs_local_lfds711_stack_push_new_top[1] = __cs_local_lfds711_stack_push_original_top[1] + 1;
                                        
# 5947 "<previous_module>"
tmain_385: IF(0,385,tmain_386)__CSEQ_removeindent;
                                        
# 5948 "<previous_module>"
__cs_mutex_lock(&library_lock, 0);
                                        
# 5949 "<previous_module>"
tmain_386: IF(0,386,tmain_387)__CSEQ_removeindent;
                                        
# 5950 "<previous_module>"
__cs_local_lfds711_stack_push_result = __CSEQ_atomic_swap_stack_top(&(*__cs_param_lfds711_stack_push_ss).top[0], &__cs_local_lfds711_stack_push_original_top[0], &__cs_local_lfds711_stack_push_new_top[0]);
                                        
# 5951 "<previous_module>"
tmain_387: IF(0,387,tmain_388)__CSEQ_removeindent;
                                        
# 5952 "<previous_module>"
__cs_mutex_unlock(&library_lock, 0);
                                        
# 5953 "<previous_module>"
;
                                        ;
                                        
# 5954 "<previous_module>"
static _Bool __cs_local_lfds711_stack_push___cs_tmp_if_cond_16;
                                        
# 5955 "<previous_module>"
__cs_local_lfds711_stack_push___cs_tmp_if_cond_16 = __cs_local_lfds711_stack_push_result == 0;
                                        
# 5956 "<previous_module>"
if (__cs_local_lfds711_stack_push___cs_tmp_if_cond_16)

# 5957 "<previous_module>"
                                        {

# 5958 "<previous_module>"
                                                {
                                                        
# 5959 "<previous_module>"
static int __cs_local_exponential_backoff_loop;
                                                        
# 5960 "<previous_module>"
__cs_local_exponential_backoff_loop = 0;

# 5961 "<previous_module>"
                                                        {
                                                                
# 5962 "<previous_module>"
;
                                                                ;
                                                        }
                                                        
# 5964 "<previous_module>"
;
                                                        
# 5965 "<previous_module>"
__cs_local_exponential_backoff_loop++;

# 5966 "<previous_module>"
                                                        {
                                                                
# 5967 "<previous_module>"
;
                                                                ;
                                                        }
                                                        
# 5969 "<previous_module>"
;
                                                        
# 5970 "<previous_module>"
__cs_local_exponential_backoff_loop++;

# 5971 "<previous_module>"
                                                        {
                                                                
# 5972 "<previous_module>"
;
                                                                ;
                                                        }
                                                        
# 5974 "<previous_module>"
;
                                                        
# 5975 "<previous_module>"
__cs_local_exponential_backoff_loop++;
                                                        
# 5976 "<previous_module>"
tmain_388: IF(0,388,tmain_389)__CSEQ_removeindent;
                                                        
# 5977 "<previous_module>"
__CPROVER_assume(!(__cs_local_exponential_backoff_loop < 3));
                                                        
# 5978 "<previous_module>"
__exit_loop_75:
                                                        __CPROVER_assume(__cs_pc_cs[0] >= 389);

                                                        
# 5979 "<previous_module>"
;
                                                        ;
                                                        
# 5980 "<previous_module>"
__exit__exponential_backoff_6_1:
                                                        __CPROVER_assume(__cs_pc_cs[0] >= 389);

                                                        
# 5981 "<previous_module>"
;
                                                        ;
                                                }
                                                
# 5983 "<previous_module>"
;
                                        }

                                        
# 5985 "<previous_module>"
__CPROVER_assume(__cs_pc_cs[0] >= 389);
                                        ;
                                        
# 5986 "<previous_module>"
__cs_local_lfds711_stack_push_i++;
                                        
# 5987 "<previous_module>"
;
                                        ;
                                        
# 5988 "<previous_module>"
static _Bool __cs_local_lfds711_stack_push___cs_tmp_if_cond_17;
                                        
# 5989 "<previous_module>"
__cs_local_lfds711_stack_push___cs_tmp_if_cond_17 = __cs_local_lfds711_stack_push_i > 1000;
                                        
# 5990 "<previous_module>"
if (__cs_local_lfds711_stack_push___cs_tmp_if_cond_17)

# 5991 "<previous_module>"
                                        {
                                                
# 5992 "<previous_module>"
goto __exit_loop_73;
                                                ;
                                        }

                                        
# 5994 "<previous_module>"
;
                                }
                                
# 5996 "<previous_module>"
;
                                
# 5997 "<previous_module>"
if (!(__cs_local_lfds711_stack_push_result == 0))

# 5998 "<previous_module>"
                                {
                                        
# 5999 "<previous_module>"
goto __exit_loop_73;
                                        ;
                                }

                                
# 6001 "<previous_module>"
;

# 6002 "<previous_module>"
                                {
                                        
# 6003 "<previous_module>"
tmain_389: IF(0,389,tmain_390)__CSEQ_removeindent;
                                        
# 6004 "<previous_module>"
__cs_mutex_lock(&library_lock, 0);
                                        
# 6005 "<previous_module>"
tmain_390: IF(0,390,tmain_391)__CSEQ_removeindent;
                                        
# 6006 "<previous_module>"
(*__cs_param_lfds711_stack_push_se).next = __cs_local_lfds711_stack_push_original_top[0];
                                        
# 6007 "<previous_module>"
tmain_391: IF(0,391,tmain_392)__CSEQ_removeindent;
                                        
# 6008 "<previous_module>"
__cs_mutex_unlock(&library_lock, 0);
                                        
# 6009 "<previous_module>"
tmain_392: IF(0,392,tmain_393)__CSEQ_removeindent;
                                        
# 6010 "<previous_module>"
__cs_local_lfds711_stack_push_new_top[1] = __cs_local_lfds711_stack_push_original_top[1] + 1;
                                        
# 6011 "<previous_module>"
tmain_393: IF(0,393,tmain_394)__CSEQ_removeindent;
                                        
# 6012 "<previous_module>"
__cs_mutex_lock(&library_lock, 0);
                                        
# 6013 "<previous_module>"
tmain_394: IF(0,394,tmain_395)__CSEQ_removeindent;
                                        
# 6014 "<previous_module>"
__cs_local_lfds711_stack_push_result = __CSEQ_atomic_swap_stack_top(&(*__cs_param_lfds711_stack_push_ss).top[0], &__cs_local_lfds711_stack_push_original_top[0], &__cs_local_lfds711_stack_push_new_top[0]);
                                        
# 6015 "<previous_module>"
tmain_395: IF(0,395,tmain_396)__CSEQ_removeindent;
                                        
# 6016 "<previous_module>"
__cs_mutex_unlock(&library_lock, 0);
                                        
# 6017 "<previous_module>"
;
                                        ;
                                        
# 6018 "<previous_module>"
static _Bool __cs_local_lfds711_stack_push___cs_tmp_if_cond_16;
                                        
# 6019 "<previous_module>"
__cs_local_lfds711_stack_push___cs_tmp_if_cond_16 = __cs_local_lfds711_stack_push_result == 0;
                                        
# 6020 "<previous_module>"
if (__cs_local_lfds711_stack_push___cs_tmp_if_cond_16)

# 6021 "<previous_module>"
                                        {

# 6022 "<previous_module>"
                                                {
                                                        
# 6023 "<previous_module>"
static int __cs_local_exponential_backoff_loop;
                                                        
# 6024 "<previous_module>"
__cs_local_exponential_backoff_loop = 0;

# 6025 "<previous_module>"
                                                        {
                                                                
# 6026 "<previous_module>"
;
                                                                ;
                                                        }
                                                        
# 6028 "<previous_module>"
;
                                                        
# 6029 "<previous_module>"
__cs_local_exponential_backoff_loop++;

# 6030 "<previous_module>"
                                                        {
                                                                
# 6031 "<previous_module>"
;
                                                                ;
                                                        }
                                                        
# 6033 "<previous_module>"
;
                                                        
# 6034 "<previous_module>"
__cs_local_exponential_backoff_loop++;

# 6035 "<previous_module>"
                                                        {
                                                                
# 6036 "<previous_module>"
;
                                                                ;
                                                        }
                                                        
# 6038 "<previous_module>"
;
                                                        
# 6039 "<previous_module>"
__cs_local_exponential_backoff_loop++;
                                                        
# 6040 "<previous_module>"
tmain_396: IF(0,396,tmain_397)__CSEQ_removeindent;
                                                        
# 6041 "<previous_module>"
__CPROVER_assume(!(__cs_local_exponential_backoff_loop < 3));
                                                        
# 6042 "<previous_module>"
__exit_loop_76:
                                                        __CPROVER_assume(__cs_pc_cs[0] >= 397);

                                                        
# 6043 "<previous_module>"
;
                                                        ;
                                                        
# 6044 "<previous_module>"
__exit__exponential_backoff_6_2:
                                                        __CPROVER_assume(__cs_pc_cs[0] >= 397);

                                                        
# 6045 "<previous_module>"
;
                                                        ;
                                                }
                                                
# 6047 "<previous_module>"
;
                                        }

                                        
# 6049 "<previous_module>"
__CPROVER_assume(__cs_pc_cs[0] >= 397);
                                        ;
                                        
# 6050 "<previous_module>"
__cs_local_lfds711_stack_push_i++;
                                        
# 6051 "<previous_module>"
;
                                        ;
                                        
# 6052 "<previous_module>"
static _Bool __cs_local_lfds711_stack_push___cs_tmp_if_cond_17;
                                        
# 6053 "<previous_module>"
__cs_local_lfds711_stack_push___cs_tmp_if_cond_17 = __cs_local_lfds711_stack_push_i > 1000;
                                        
# 6054 "<previous_module>"
if (__cs_local_lfds711_stack_push___cs_tmp_if_cond_17)

# 6055 "<previous_module>"
                                        {
                                                
# 6056 "<previous_module>"
goto __exit_loop_73;
                                                ;
                                        }

                                        
# 6058 "<previous_module>"
;
                                }
                                
# 6060 "<previous_module>"
;
                                
# 6061 "<previous_module>"
if (!(__cs_local_lfds711_stack_push_result == 0))

# 6062 "<previous_module>"
                                {
                                        
# 6063 "<previous_module>"
goto __exit_loop_73;
                                        ;
                                }

                                
# 6065 "<previous_module>"
;

# 6066 "<previous_module>"
                                {
                                        
# 6067 "<previous_module>"
tmain_397: IF(0,397,tmain_398)__CSEQ_removeindent;
                                        
# 6068 "<previous_module>"
__cs_mutex_lock(&library_lock, 0);
                                        
# 6069 "<previous_module>"
tmain_398: IF(0,398,tmain_399)__CSEQ_removeindent;
                                        
# 6070 "<previous_module>"
(*__cs_param_lfds711_stack_push_se).next = __cs_local_lfds711_stack_push_original_top[0];
                                        
# 6071 "<previous_module>"
tmain_399: IF(0,399,tmain_400)__CSEQ_removeindent;
                                        
# 6072 "<previous_module>"
__cs_mutex_unlock(&library_lock, 0);
                                        
# 6073 "<previous_module>"
tmain_400: IF(0,400,tmain_401)__CSEQ_removeindent;
                                        
# 6074 "<previous_module>"
__cs_local_lfds711_stack_push_new_top[1] = __cs_local_lfds711_stack_push_original_top[1] + 1;
                                        
# 6075 "<previous_module>"
tmain_401: IF(0,401,tmain_402)__CSEQ_removeindent;
                                        
# 6076 "<previous_module>"
__cs_mutex_lock(&library_lock, 0);
                                        
# 6077 "<previous_module>"
tmain_402: IF(0,402,tmain_403)__CSEQ_removeindent;
                                        
# 6078 "<previous_module>"
__cs_local_lfds711_stack_push_result = __CSEQ_atomic_swap_stack_top(&(*__cs_param_lfds711_stack_push_ss).top[0], &__cs_local_lfds711_stack_push_original_top[0], &__cs_local_lfds711_stack_push_new_top[0]);
                                        
# 6079 "<previous_module>"
tmain_403: IF(0,403,tmain_404)__CSEQ_removeindent;
                                        
# 6080 "<previous_module>"
__cs_mutex_unlock(&library_lock, 0);
                                        
# 6081 "<previous_module>"
;
                                        ;
                                        
# 6082 "<previous_module>"
static _Bool __cs_local_lfds711_stack_push___cs_tmp_if_cond_16;
                                        
# 6083 "<previous_module>"
__cs_local_lfds711_stack_push___cs_tmp_if_cond_16 = __cs_local_lfds711_stack_push_result == 0;
                                        
# 6084 "<previous_module>"
if (__cs_local_lfds711_stack_push___cs_tmp_if_cond_16)

# 6085 "<previous_module>"
                                        {

# 6086 "<previous_module>"
                                                {
                                                        
# 6087 "<previous_module>"
static int __cs_local_exponential_backoff_loop;
                                                        
# 6088 "<previous_module>"
__cs_local_exponential_backoff_loop = 0;

# 6089 "<previous_module>"
                                                        {
                                                                
# 6090 "<previous_module>"
;
                                                                ;
                                                        }
                                                        
# 6092 "<previous_module>"
;
                                                        
# 6093 "<previous_module>"
__cs_local_exponential_backoff_loop++;

# 6094 "<previous_module>"
                                                        {
                                                                
# 6095 "<previous_module>"
;
                                                                ;
                                                        }
                                                        
# 6097 "<previous_module>"
;
                                                        
# 6098 "<previous_module>"
__cs_local_exponential_backoff_loop++;

# 6099 "<previous_module>"
                                                        {
                                                                
# 6100 "<previous_module>"
;
                                                                ;
                                                        }
                                                        
# 6102 "<previous_module>"
;
                                                        
# 6103 "<previous_module>"
__cs_local_exponential_backoff_loop++;
                                                        
# 6104 "<previous_module>"
tmain_404: IF(0,404,tmain_405)__CSEQ_removeindent;
                                                        
# 6105 "<previous_module>"
__CPROVER_assume(!(__cs_local_exponential_backoff_loop < 3));
                                                        
# 6106 "<previous_module>"
__exit_loop_77:
                                                        __CPROVER_assume(__cs_pc_cs[0] >= 405);

                                                        
# 6107 "<previous_module>"
;
                                                        ;
                                                        
# 6108 "<previous_module>"
__exit__exponential_backoff_6_3:
                                                        __CPROVER_assume(__cs_pc_cs[0] >= 405);

                                                        
# 6109 "<previous_module>"
;
                                                        ;
                                                }
                                                
# 6111 "<previous_module>"
;
                                        }

                                        
# 6113 "<previous_module>"
__CPROVER_assume(__cs_pc_cs[0] >= 405);
                                        ;
                                        
# 6114 "<previous_module>"
__cs_local_lfds711_stack_push_i++;
                                        
# 6115 "<previous_module>"
;
                                        ;
                                        
# 6116 "<previous_module>"
static _Bool __cs_local_lfds711_stack_push___cs_tmp_if_cond_17;
                                        
# 6117 "<previous_module>"
__cs_local_lfds711_stack_push___cs_tmp_if_cond_17 = __cs_local_lfds711_stack_push_i > 1000;
                                        
# 6118 "<previous_module>"
if (__cs_local_lfds711_stack_push___cs_tmp_if_cond_17)

# 6119 "<previous_module>"
                                        {
                                                
# 6120 "<previous_module>"
goto __exit_loop_73;
                                                ;
                                        }

                                        
# 6122 "<previous_module>"
;
                                }
                                
# 6124 "<previous_module>"
;
                                
# 6125 "<previous_module>"
if (!(__cs_local_lfds711_stack_push_result == 0))

# 6126 "<previous_module>"
                                {
                                        
# 6127 "<previous_module>"
goto __exit_loop_73;
                                        ;
                                }

                                
# 6129 "<previous_module>"
;

# 6130 "<previous_module>"
                                {
                                        
# 6131 "<previous_module>"
tmain_405: IF(0,405,tmain_406)__CSEQ_removeindent;
                                        
# 6132 "<previous_module>"
__cs_mutex_lock(&library_lock, 0);
                                        
# 6133 "<previous_module>"
tmain_406: IF(0,406,tmain_407)__CSEQ_removeindent;
                                        
# 6134 "<previous_module>"
(*__cs_param_lfds711_stack_push_se).next = __cs_local_lfds711_stack_push_original_top[0];
                                        
# 6135 "<previous_module>"
tmain_407: IF(0,407,tmain_408)__CSEQ_removeindent;
                                        
# 6136 "<previous_module>"
__cs_mutex_unlock(&library_lock, 0);
                                        
# 6137 "<previous_module>"
tmain_408: IF(0,408,tmain_409)__CSEQ_removeindent;
                                        
# 6138 "<previous_module>"
__cs_local_lfds711_stack_push_new_top[1] = __cs_local_lfds711_stack_push_original_top[1] + 1;
                                        
# 6139 "<previous_module>"
tmain_409: IF(0,409,tmain_410)__CSEQ_removeindent;
                                        
# 6140 "<previous_module>"
__cs_mutex_lock(&library_lock, 0);
                                        
# 6141 "<previous_module>"
tmain_410: IF(0,410,tmain_411)__CSEQ_removeindent;
                                        
# 6142 "<previous_module>"
__cs_local_lfds711_stack_push_result = __CSEQ_atomic_swap_stack_top(&(*__cs_param_lfds711_stack_push_ss).top[0], &__cs_local_lfds711_stack_push_original_top[0], &__cs_local_lfds711_stack_push_new_top[0]);
                                        
# 6143 "<previous_module>"
tmain_411: IF(0,411,tmain_412)__CSEQ_removeindent;
                                        
# 6144 "<previous_module>"
__cs_mutex_unlock(&library_lock, 0);
                                        
# 6145 "<previous_module>"
;
                                        ;
                                        
# 6146 "<previous_module>"
static _Bool __cs_local_lfds711_stack_push___cs_tmp_if_cond_16;
                                        
# 6147 "<previous_module>"
__cs_local_lfds711_stack_push___cs_tmp_if_cond_16 = __cs_local_lfds711_stack_push_result == 0;
                                        
# 6148 "<previous_module>"
if (__cs_local_lfds711_stack_push___cs_tmp_if_cond_16)

# 6149 "<previous_module>"
                                        {

# 6150 "<previous_module>"
                                                {
                                                        
# 6151 "<previous_module>"
static int __cs_local_exponential_backoff_loop;
                                                        
# 6152 "<previous_module>"
__cs_local_exponential_backoff_loop = 0;

# 6153 "<previous_module>"
                                                        {
                                                                
# 6154 "<previous_module>"
;
                                                                ;
                                                        }
                                                        
# 6156 "<previous_module>"
;
                                                        
# 6157 "<previous_module>"
__cs_local_exponential_backoff_loop++;

# 6158 "<previous_module>"
                                                        {
                                                                
# 6159 "<previous_module>"
;
                                                                ;
                                                        }
                                                        
# 6161 "<previous_module>"
;
                                                        
# 6162 "<previous_module>"
__cs_local_exponential_backoff_loop++;

# 6163 "<previous_module>"
                                                        {
                                                                
# 6164 "<previous_module>"
;
                                                                ;
                                                        }
                                                        
# 6166 "<previous_module>"
;
                                                        
# 6167 "<previous_module>"
__cs_local_exponential_backoff_loop++;
                                                        
# 6168 "<previous_module>"
tmain_412: IF(0,412,tmain_413)__CSEQ_removeindent;
                                                        
# 6169 "<previous_module>"
__CPROVER_assume(!(__cs_local_exponential_backoff_loop < 3));
                                                        
# 6170 "<previous_module>"
__exit_loop_78:
                                                        __CPROVER_assume(__cs_pc_cs[0] >= 413);

                                                        
# 6171 "<previous_module>"
;
                                                        ;
                                                        
# 6172 "<previous_module>"
__exit__exponential_backoff_6_4:
                                                        __CPROVER_assume(__cs_pc_cs[0] >= 413);

                                                        
# 6173 "<previous_module>"
;
                                                        ;
                                                }
                                                
# 6175 "<previous_module>"
;
                                        }

                                        
# 6177 "<previous_module>"
__CPROVER_assume(__cs_pc_cs[0] >= 413);
                                        ;
                                        
# 6178 "<previous_module>"
__cs_local_lfds711_stack_push_i++;
                                        
# 6179 "<previous_module>"
;
                                        ;
                                        
# 6180 "<previous_module>"
static _Bool __cs_local_lfds711_stack_push___cs_tmp_if_cond_17;
                                        
# 6181 "<previous_module>"
__cs_local_lfds711_stack_push___cs_tmp_if_cond_17 = __cs_local_lfds711_stack_push_i > 1000;
                                        
# 6182 "<previous_module>"
if (__cs_local_lfds711_stack_push___cs_tmp_if_cond_17)

# 6183 "<previous_module>"
                                        {
                                                
# 6184 "<previous_module>"
goto __exit_loop_73;
                                                ;
                                        }

                                        
# 6186 "<previous_module>"
;
                                }
                                
# 6188 "<previous_module>"
;
                                
# 6189 "<previous_module>"
tmain_413: IF(0,413,tmain_414)__CSEQ_removeindent;
                                
# 6190 "<previous_module>"
__CPROVER_assume(!(__cs_local_lfds711_stack_push_result == 0));
                                
# 6191 "<previous_module>"
__exit_loop_73:
                                __CPROVER_assume(__cs_pc_cs[0] >= 414);

                                
# 6192 "<previous_module>"
;
                                ;
                                
# 6193 "<previous_module>"
goto __exit__lfds711_stack_push_2_0;
                                ;
                                
# 6194 "<previous_module>"
__exit__lfds711_stack_push_2_0:
                                __CPROVER_assume(__cs_pc_cs[0] >= 414);

                                
# 6195 "<previous_module>"
;
                                ;
                        }
                        
# 6197 "<previous_module>"
;
                        
# 6198 "<previous_module>"
__cs_local_contains_i++;
                }
                
# 6200 "<previous_module>"
;
                
# 6201 "<previous_module>"
if (!(__cs_local_contains_i < __cs_local_contains_actual_size))

# 6202 "<previous_module>"
                {
                        
# 6203 "<previous_module>"
goto __exit_loop_72;
                        ;
                }

                
# 6205 "<previous_module>"
;

# 6206 "<previous_module>"
                {

# 6207 "<previous_module>"
                        {
                                
# 6208 "<previous_module>"
static struct lfds711_stack_state *__cs_param_lfds711_stack_push_ss;
                                
# 6209 "<previous_module>"
tmain_414: IF(0,414,tmain_415)__CSEQ_removeindent;
                                
# 6210 "<previous_module>"
__cs_param_lfds711_stack_push_ss = __cs_param_contains_s;
                                
# 6211 "<previous_module>"
static struct lfds711_stack_element *__cs_param_lfds711_stack_push_se;
                                
# 6212 "<previous_module>"
tmain_415: IF(0,415,tmain_416)__CSEQ_removeindent;
                                
# 6213 "<previous_module>"
__cs_param_lfds711_stack_push_se = &(*__cs_local_contains_datas[__cs_local_contains_i]).se;
                                
# 6214 "<previous_module>"
static char unsigned __cs_local_lfds711_stack_push_result;
                                
# 6215 "<previous_module>"
static lfds711_pal_uint_t __cs_local_lfds711_stack_push_backoff_iteration;
                                
# 6216 "<previous_module>"
__cs_local_lfds711_stack_push_backoff_iteration = 0;
                                
# 6217 "<previous_module>"
static struct lfds711_stack_element *__cs_local_lfds711_stack_push_new_top[2];
                                
# 6218 "<previous_module>"
static struct lfds711_stack_element * volatile __cs_local_lfds711_stack_push_original_top[2];
                                
# 6219 "<previous_module>"
;
                                ;
                                
# 6220 "<previous_module>"
static _Bool __cs_local_lfds711_stack_push___cs_tmp_if_cond_14;
                                
# 6221 "<previous_module>"
tmain_416: IF(0,416,tmain_417)__CSEQ_removeindent;
                                
# 6222 "<previous_module>"
__cs_local_lfds711_stack_push___cs_tmp_if_cond_14 = !(__cs_param_lfds711_stack_push_ss != 0);
                                
# 6223 "<previous_module>"
if (__cs_local_lfds711_stack_push___cs_tmp_if_cond_14)

# 6224 "<previous_module>"
                                {
                                        
# 6225 "<previous_module>"
static char *__cs_local_lfds711_stack_push_c;
                                        
# 6226 "<previous_module>"
tmain_417: IF(0,417,tmain_418)__CSEQ_removeindent;
                                        
# 6227 "<previous_module>"
__cs_local_lfds711_stack_push_c = 0;
                                        
# 6228 "<previous_module>"
tmain_418: IF(0,418,tmain_419)__CSEQ_removeindent;
                                        
# 6229 "<previous_module>"
*__cs_local_lfds711_stack_push_c = 0;
                                }

                                
# 6231 "<previous_module>"
__CPROVER_assume(__cs_pc_cs[0] >= 419);
                                ;
                                
# 6232 "<previous_module>"
;
                                ;
                                
# 6233 "<previous_module>"
;
                                ;
                                
# 6234 "<previous_module>"
;
                                ;
                                
# 6235 "<previous_module>"
static _Bool __cs_local_lfds711_stack_push___cs_tmp_if_cond_15;
                                
# 6236 "<previous_module>"
tmain_419: IF(0,419,tmain_420)__CSEQ_removeindent;
                                
# 6237 "<previous_module>"
__cs_local_lfds711_stack_push___cs_tmp_if_cond_15 = !(__cs_param_lfds711_stack_push_se != 0);
                                
# 6238 "<previous_module>"
if (__cs_local_lfds711_stack_push___cs_tmp_if_cond_15)

# 6239 "<previous_module>"
                                {
                                        
# 6240 "<previous_module>"
static char *__cs_local_lfds711_stack_push_c;
                                        
# 6241 "<previous_module>"
tmain_420: IF(0,420,tmain_421)__CSEQ_removeindent;
                                        
# 6242 "<previous_module>"
__cs_local_lfds711_stack_push_c = 0;
                                        
# 6243 "<previous_module>"
tmain_421: IF(0,421,tmain_422)__CSEQ_removeindent;
                                        
# 6244 "<previous_module>"
*__cs_local_lfds711_stack_push_c = 0;
                                }

                                
# 6246 "<previous_module>"
__CPROVER_assume(__cs_pc_cs[0] >= 422);
                                ;
                                
# 6247 "<previous_module>"
;
                                ;
                                
# 6248 "<previous_module>"
;
                                ;
                                
# 6249 "<previous_module>"
tmain_422: IF(0,422,tmain_423)__CSEQ_removeindent;
                                
# 6250 "<previous_module>"
__cs_local_lfds711_stack_push_new_top[0] = __cs_param_lfds711_stack_push_se;
                                
# 6251 "<previous_module>"
tmain_423: IF(0,423,tmain_424)__CSEQ_removeindent;
                                
# 6252 "<previous_module>"
__cs_local_lfds711_stack_push_original_top[1] = (*__cs_param_lfds711_stack_push_ss).top[1];
                                
# 6253 "<previous_module>"
tmain_424: IF(0,424,tmain_425)__CSEQ_removeindent;
                                
# 6254 "<previous_module>"
__cs_local_lfds711_stack_push_original_top[0] = (*__cs_param_lfds711_stack_push_ss).top[0];
                                
# 6255 "<previous_module>"
__cs_local_lfds711_stack_push_result = 0;
                                
# 6256 "<previous_module>"
static int __cs_local_lfds711_stack_push_i;
                                
# 6257 "<previous_module>"
__cs_local_lfds711_stack_push_i = 0;
                                
# 6258 "<previous_module>"
if (!(__cs_local_lfds711_stack_push_result == 0))

# 6259 "<previous_module>"
                                {
                                        
# 6260 "<previous_module>"
goto __exit_loop_79;
                                        ;
                                }

                                
# 6262 "<previous_module>"
;

# 6263 "<previous_module>"
                                {
                                        
# 6264 "<previous_module>"
tmain_425: IF(0,425,tmain_426)__CSEQ_removeindent;
                                        
# 6265 "<previous_module>"
__cs_mutex_lock(&library_lock, 0);
                                        
# 6266 "<previous_module>"
tmain_426: IF(0,426,tmain_427)__CSEQ_removeindent;
                                        
# 6267 "<previous_module>"
(*__cs_param_lfds711_stack_push_se).next = __cs_local_lfds711_stack_push_original_top[0];
                                        
# 6268 "<previous_module>"
tmain_427: IF(0,427,tmain_428)__CSEQ_removeindent;
                                        
# 6269 "<previous_module>"
__cs_mutex_unlock(&library_lock, 0);
                                        
# 6270 "<previous_module>"
tmain_428: IF(0,428,tmain_429)__CSEQ_removeindent;
                                        
# 6271 "<previous_module>"
__cs_local_lfds711_stack_push_new_top[1] = __cs_local_lfds711_stack_push_original_top[1] + 1;
                                        
# 6272 "<previous_module>"
tmain_429: IF(0,429,tmain_430)__CSEQ_removeindent;
                                        
# 6273 "<previous_module>"
__cs_mutex_lock(&library_lock, 0);
                                        
# 6274 "<previous_module>"
tmain_430: IF(0,430,tmain_431)__CSEQ_removeindent;
                                        
# 6275 "<previous_module>"
__cs_local_lfds711_stack_push_result = __CSEQ_atomic_swap_stack_top(&(*__cs_param_lfds711_stack_push_ss).top[0], &__cs_local_lfds711_stack_push_original_top[0], &__cs_local_lfds711_stack_push_new_top[0]);
                                        
# 6276 "<previous_module>"
tmain_431: IF(0,431,tmain_432)__CSEQ_removeindent;
                                        
# 6277 "<previous_module>"
__cs_mutex_unlock(&library_lock, 0);
                                        
# 6278 "<previous_module>"
;
                                        ;
                                        
# 6279 "<previous_module>"
static _Bool __cs_local_lfds711_stack_push___cs_tmp_if_cond_16;
                                        
# 6280 "<previous_module>"
__cs_local_lfds711_stack_push___cs_tmp_if_cond_16 = __cs_local_lfds711_stack_push_result == 0;
                                        
# 6281 "<previous_module>"
if (__cs_local_lfds711_stack_push___cs_tmp_if_cond_16)

# 6282 "<previous_module>"
                                        {

# 6283 "<previous_module>"
                                                {
                                                        
# 6284 "<previous_module>"
static int __cs_local_exponential_backoff_loop;
                                                        
# 6285 "<previous_module>"
__cs_local_exponential_backoff_loop = 0;

# 6286 "<previous_module>"
                                                        {
                                                                
# 6287 "<previous_module>"
;
                                                                ;
                                                        }
                                                        
# 6289 "<previous_module>"
;
                                                        
# 6290 "<previous_module>"
__cs_local_exponential_backoff_loop++;

# 6291 "<previous_module>"
                                                        {
                                                                
# 6292 "<previous_module>"
;
                                                                ;
                                                        }
                                                        
# 6294 "<previous_module>"
;
                                                        
# 6295 "<previous_module>"
__cs_local_exponential_backoff_loop++;

# 6296 "<previous_module>"
                                                        {
                                                                
# 6297 "<previous_module>"
;
                                                                ;
                                                        }
                                                        
# 6299 "<previous_module>"
;
                                                        
# 6300 "<previous_module>"
__cs_local_exponential_backoff_loop++;
                                                        
# 6301 "<previous_module>"
tmain_432: IF(0,432,tmain_433)__CSEQ_removeindent;
                                                        
# 6302 "<previous_module>"
__CPROVER_assume(!(__cs_local_exponential_backoff_loop < 3));
                                                        
# 6303 "<previous_module>"
__exit_loop_80:
                                                        __CPROVER_assume(__cs_pc_cs[0] >= 433);

                                                        
# 6304 "<previous_module>"
;
                                                        ;
                                                        
# 6305 "<previous_module>"
__exit__exponential_backoff_6_5:
                                                        __CPROVER_assume(__cs_pc_cs[0] >= 433);

                                                        
# 6306 "<previous_module>"
;
                                                        ;
                                                }
                                                
# 6308 "<previous_module>"
;
                                        }

                                        
# 6310 "<previous_module>"
__CPROVER_assume(__cs_pc_cs[0] >= 433);
                                        ;
                                        
# 6311 "<previous_module>"
__cs_local_lfds711_stack_push_i++;
                                        
# 6312 "<previous_module>"
;
                                        ;
                                        
# 6313 "<previous_module>"
static _Bool __cs_local_lfds711_stack_push___cs_tmp_if_cond_17;
                                        
# 6314 "<previous_module>"
__cs_local_lfds711_stack_push___cs_tmp_if_cond_17 = __cs_local_lfds711_stack_push_i > 1000;
                                        
# 6315 "<previous_module>"
if (__cs_local_lfds711_stack_push___cs_tmp_if_cond_17)

# 6316 "<previous_module>"
                                        {
                                                
# 6317 "<previous_module>"
goto __exit_loop_79;
                                                ;
                                        }

                                        
# 6319 "<previous_module>"
;
                                }
                                
# 6321 "<previous_module>"
;
                                
# 6322 "<previous_module>"
if (!(__cs_local_lfds711_stack_push_result == 0))

# 6323 "<previous_module>"
                                {
                                        
# 6324 "<previous_module>"
goto __exit_loop_79;
                                        ;
                                }

                                
# 6326 "<previous_module>"
;

# 6327 "<previous_module>"
                                {
                                        
# 6328 "<previous_module>"
tmain_433: IF(0,433,tmain_434)__CSEQ_removeindent;
                                        
# 6329 "<previous_module>"
__cs_mutex_lock(&library_lock, 0);
                                        
# 6330 "<previous_module>"
tmain_434: IF(0,434,tmain_435)__CSEQ_removeindent;
                                        
# 6331 "<previous_module>"
(*__cs_param_lfds711_stack_push_se).next = __cs_local_lfds711_stack_push_original_top[0];
                                        
# 6332 "<previous_module>"
tmain_435: IF(0,435,tmain_436)__CSEQ_removeindent;
                                        
# 6333 "<previous_module>"
__cs_mutex_unlock(&library_lock, 0);
                                        
# 6334 "<previous_module>"
tmain_436: IF(0,436,tmain_437)__CSEQ_removeindent;
                                        
# 6335 "<previous_module>"
__cs_local_lfds711_stack_push_new_top[1] = __cs_local_lfds711_stack_push_original_top[1] + 1;
                                        
# 6336 "<previous_module>"
tmain_437: IF(0,437,tmain_438)__CSEQ_removeindent;
                                        
# 6337 "<previous_module>"
__cs_mutex_lock(&library_lock, 0);
                                        
# 6338 "<previous_module>"
tmain_438: IF(0,438,tmain_439)__CSEQ_removeindent;
                                        
# 6339 "<previous_module>"
__cs_local_lfds711_stack_push_result = __CSEQ_atomic_swap_stack_top(&(*__cs_param_lfds711_stack_push_ss).top[0], &__cs_local_lfds711_stack_push_original_top[0], &__cs_local_lfds711_stack_push_new_top[0]);
                                        
# 6340 "<previous_module>"
tmain_439: IF(0,439,tmain_440)__CSEQ_removeindent;
                                        
# 6341 "<previous_module>"
__cs_mutex_unlock(&library_lock, 0);
                                        
# 6342 "<previous_module>"
;
                                        ;
                                        
# 6343 "<previous_module>"
static _Bool __cs_local_lfds711_stack_push___cs_tmp_if_cond_16;
                                        
# 6344 "<previous_module>"
__cs_local_lfds711_stack_push___cs_tmp_if_cond_16 = __cs_local_lfds711_stack_push_result == 0;
                                        
# 6345 "<previous_module>"
if (__cs_local_lfds711_stack_push___cs_tmp_if_cond_16)

# 6346 "<previous_module>"
                                        {

# 6347 "<previous_module>"
                                                {
                                                        
# 6348 "<previous_module>"
static int __cs_local_exponential_backoff_loop;
                                                        
# 6349 "<previous_module>"
__cs_local_exponential_backoff_loop = 0;

# 6350 "<previous_module>"
                                                        {
                                                                
# 6351 "<previous_module>"
;
                                                                ;
                                                        }
                                                        
# 6353 "<previous_module>"
;
                                                        
# 6354 "<previous_module>"
__cs_local_exponential_backoff_loop++;

# 6355 "<previous_module>"
                                                        {
                                                                
# 6356 "<previous_module>"
;
                                                                ;
                                                        }
                                                        
# 6358 "<previous_module>"
;
                                                        
# 6359 "<previous_module>"
__cs_local_exponential_backoff_loop++;

# 6360 "<previous_module>"
                                                        {
                                                                
# 6361 "<previous_module>"
;
                                                                ;
                                                        }
                                                        
# 6363 "<previous_module>"
;
                                                        
# 6364 "<previous_module>"
__cs_local_exponential_backoff_loop++;
                                                        
# 6365 "<previous_module>"
tmain_440: IF(0,440,tmain_441)__CSEQ_removeindent;
                                                        
# 6366 "<previous_module>"
__CPROVER_assume(!(__cs_local_exponential_backoff_loop < 3));
                                                        
# 6367 "<previous_module>"
__exit_loop_81:
                                                        __CPROVER_assume(__cs_pc_cs[0] >= 441);

                                                        
# 6368 "<previous_module>"
;
                                                        ;
                                                        
# 6369 "<previous_module>"
__exit__exponential_backoff_6_6:
                                                        __CPROVER_assume(__cs_pc_cs[0] >= 441);

                                                        
# 6370 "<previous_module>"
;
                                                        ;
                                                }
                                                
# 6372 "<previous_module>"
;
                                        }

                                        
# 6374 "<previous_module>"
__CPROVER_assume(__cs_pc_cs[0] >= 441);
                                        ;
                                        
# 6375 "<previous_module>"
__cs_local_lfds711_stack_push_i++;
                                        
# 6376 "<previous_module>"
;
                                        ;
                                        
# 6377 "<previous_module>"
static _Bool __cs_local_lfds711_stack_push___cs_tmp_if_cond_17;
                                        
# 6378 "<previous_module>"
__cs_local_lfds711_stack_push___cs_tmp_if_cond_17 = __cs_local_lfds711_stack_push_i > 1000;
                                        
# 6379 "<previous_module>"
if (__cs_local_lfds711_stack_push___cs_tmp_if_cond_17)

# 6380 "<previous_module>"
                                        {
                                                
# 6381 "<previous_module>"
goto __exit_loop_79;
                                                ;
                                        }

                                        
# 6383 "<previous_module>"
;
                                }
                                
# 6385 "<previous_module>"
;
                                
# 6386 "<previous_module>"
if (!(__cs_local_lfds711_stack_push_result == 0))

# 6387 "<previous_module>"
                                {
                                        
# 6388 "<previous_module>"
goto __exit_loop_79;
                                        ;
                                }

                                
# 6390 "<previous_module>"
;

# 6391 "<previous_module>"
                                {
                                        
# 6392 "<previous_module>"
tmain_441: IF(0,441,tmain_442)__CSEQ_removeindent;
                                        
# 6393 "<previous_module>"
__cs_mutex_lock(&library_lock, 0);
                                        
# 6394 "<previous_module>"
tmain_442: IF(0,442,tmain_443)__CSEQ_removeindent;
                                        
# 6395 "<previous_module>"
(*__cs_param_lfds711_stack_push_se).next = __cs_local_lfds711_stack_push_original_top[0];
                                        
# 6396 "<previous_module>"
tmain_443: IF(0,443,tmain_444)__CSEQ_removeindent;
                                        
# 6397 "<previous_module>"
__cs_mutex_unlock(&library_lock, 0);
                                        
# 6398 "<previous_module>"
tmain_444: IF(0,444,tmain_445)__CSEQ_removeindent;
                                        
# 6399 "<previous_module>"
__cs_local_lfds711_stack_push_new_top[1] = __cs_local_lfds711_stack_push_original_top[1] + 1;
                                        
# 6400 "<previous_module>"
tmain_445: IF(0,445,tmain_446)__CSEQ_removeindent;
                                        
# 6401 "<previous_module>"
__cs_mutex_lock(&library_lock, 0);
                                        
# 6402 "<previous_module>"
tmain_446: IF(0,446,tmain_447)__CSEQ_removeindent;
                                        
# 6403 "<previous_module>"
__cs_local_lfds711_stack_push_result = __CSEQ_atomic_swap_stack_top(&(*__cs_param_lfds711_stack_push_ss).top[0], &__cs_local_lfds711_stack_push_original_top[0], &__cs_local_lfds711_stack_push_new_top[0]);
                                        
# 6404 "<previous_module>"
tmain_447: IF(0,447,tmain_448)__CSEQ_removeindent;
                                        
# 6405 "<previous_module>"
__cs_mutex_unlock(&library_lock, 0);
                                        
# 6406 "<previous_module>"
;
                                        ;
                                        
# 6407 "<previous_module>"
static _Bool __cs_local_lfds711_stack_push___cs_tmp_if_cond_16;
                                        
# 6408 "<previous_module>"
__cs_local_lfds711_stack_push___cs_tmp_if_cond_16 = __cs_local_lfds711_stack_push_result == 0;
                                        
# 6409 "<previous_module>"
if (__cs_local_lfds711_stack_push___cs_tmp_if_cond_16)

# 6410 "<previous_module>"
                                        {

# 6411 "<previous_module>"
                                                {
                                                        
# 6412 "<previous_module>"
static int __cs_local_exponential_backoff_loop;
                                                        
# 6413 "<previous_module>"
__cs_local_exponential_backoff_loop = 0;

# 6414 "<previous_module>"
                                                        {
                                                                
# 6415 "<previous_module>"
;
                                                                ;
                                                        }
                                                        
# 6417 "<previous_module>"
;
                                                        
# 6418 "<previous_module>"
__cs_local_exponential_backoff_loop++;

# 6419 "<previous_module>"
                                                        {
                                                                
# 6420 "<previous_module>"
;
                                                                ;
                                                        }
                                                        
# 6422 "<previous_module>"
;
                                                        
# 6423 "<previous_module>"
__cs_local_exponential_backoff_loop++;

# 6424 "<previous_module>"
                                                        {
                                                                
# 6425 "<previous_module>"
;
                                                                ;
                                                        }
                                                        
# 6427 "<previous_module>"
;
                                                        
# 6428 "<previous_module>"
__cs_local_exponential_backoff_loop++;
                                                        
# 6429 "<previous_module>"
tmain_448: IF(0,448,tmain_449)__CSEQ_removeindent;
                                                        
# 6430 "<previous_module>"
__CPROVER_assume(!(__cs_local_exponential_backoff_loop < 3));
                                                        
# 6431 "<previous_module>"
__exit_loop_82:
                                                        __CPROVER_assume(__cs_pc_cs[0] >= 449);

                                                        
# 6432 "<previous_module>"
;
                                                        ;
                                                        
# 6433 "<previous_module>"
__exit__exponential_backoff_6_7:
                                                        __CPROVER_assume(__cs_pc_cs[0] >= 449);

                                                        
# 6434 "<previous_module>"
;
                                                        ;
                                                }
                                                
# 6436 "<previous_module>"
;
                                        }

                                        
# 6438 "<previous_module>"
__CPROVER_assume(__cs_pc_cs[0] >= 449);
                                        ;
                                        
# 6439 "<previous_module>"
__cs_local_lfds711_stack_push_i++;
                                        
# 6440 "<previous_module>"
;
                                        ;
                                        
# 6441 "<previous_module>"
static _Bool __cs_local_lfds711_stack_push___cs_tmp_if_cond_17;
                                        
# 6442 "<previous_module>"
__cs_local_lfds711_stack_push___cs_tmp_if_cond_17 = __cs_local_lfds711_stack_push_i > 1000;
                                        
# 6443 "<previous_module>"
if (__cs_local_lfds711_stack_push___cs_tmp_if_cond_17)

# 6444 "<previous_module>"
                                        {
                                                
# 6445 "<previous_module>"
goto __exit_loop_79;
                                                ;
                                        }

                                        
# 6447 "<previous_module>"
;
                                }
                                
# 6449 "<previous_module>"
;
                                
# 6450 "<previous_module>"
if (!(__cs_local_lfds711_stack_push_result == 0))

# 6451 "<previous_module>"
                                {
                                        
# 6452 "<previous_module>"
goto __exit_loop_79;
                                        ;
                                }

                                
# 6454 "<previous_module>"
;

# 6455 "<previous_module>"
                                {
                                        
# 6456 "<previous_module>"
tmain_449: IF(0,449,tmain_450)__CSEQ_removeindent;
                                        
# 6457 "<previous_module>"
__cs_mutex_lock(&library_lock, 0);
                                        
# 6458 "<previous_module>"
tmain_450: IF(0,450,tmain_451)__CSEQ_removeindent;
                                        
# 6459 "<previous_module>"
(*__cs_param_lfds711_stack_push_se).next = __cs_local_lfds711_stack_push_original_top[0];
                                        
# 6460 "<previous_module>"
tmain_451: IF(0,451,tmain_452)__CSEQ_removeindent;
                                        
# 6461 "<previous_module>"
__cs_mutex_unlock(&library_lock, 0);
                                        
# 6462 "<previous_module>"
tmain_452: IF(0,452,tmain_453)__CSEQ_removeindent;
                                        
# 6463 "<previous_module>"
__cs_local_lfds711_stack_push_new_top[1] = __cs_local_lfds711_stack_push_original_top[1] + 1;
                                        
# 6464 "<previous_module>"
tmain_453: IF(0,453,tmain_454)__CSEQ_removeindent;
                                        
# 6465 "<previous_module>"
__cs_mutex_lock(&library_lock, 0);
                                        
# 6466 "<previous_module>"
tmain_454: IF(0,454,tmain_455)__CSEQ_removeindent;
                                        
# 6467 "<previous_module>"
__cs_local_lfds711_stack_push_result = __CSEQ_atomic_swap_stack_top(&(*__cs_param_lfds711_stack_push_ss).top[0], &__cs_local_lfds711_stack_push_original_top[0], &__cs_local_lfds711_stack_push_new_top[0]);
                                        
# 6468 "<previous_module>"
tmain_455: IF(0,455,tmain_456)__CSEQ_removeindent;
                                        
# 6469 "<previous_module>"
__cs_mutex_unlock(&library_lock, 0);
                                        
# 6470 "<previous_module>"
;
                                        ;
                                        
# 6471 "<previous_module>"
static _Bool __cs_local_lfds711_stack_push___cs_tmp_if_cond_16;
                                        
# 6472 "<previous_module>"
__cs_local_lfds711_stack_push___cs_tmp_if_cond_16 = __cs_local_lfds711_stack_push_result == 0;
                                        
# 6473 "<previous_module>"
if (__cs_local_lfds711_stack_push___cs_tmp_if_cond_16)

# 6474 "<previous_module>"
                                        {

# 6475 "<previous_module>"
                                                {
                                                        
# 6476 "<previous_module>"
static int __cs_local_exponential_backoff_loop;
                                                        
# 6477 "<previous_module>"
__cs_local_exponential_backoff_loop = 0;

# 6478 "<previous_module>"
                                                        {
                                                                
# 6479 "<previous_module>"
;
                                                                ;
                                                        }
                                                        
# 6481 "<previous_module>"
;
                                                        
# 6482 "<previous_module>"
__cs_local_exponential_backoff_loop++;

# 6483 "<previous_module>"
                                                        {
                                                                
# 6484 "<previous_module>"
;
                                                                ;
                                                        }
                                                        
# 6486 "<previous_module>"
;
                                                        
# 6487 "<previous_module>"
__cs_local_exponential_backoff_loop++;

# 6488 "<previous_module>"
                                                        {
                                                                
# 6489 "<previous_module>"
;
                                                                ;
                                                        }
                                                        
# 6491 "<previous_module>"
;
                                                        
# 6492 "<previous_module>"
__cs_local_exponential_backoff_loop++;
                                                        
# 6493 "<previous_module>"
tmain_456: IF(0,456,tmain_457)__CSEQ_removeindent;
                                                        
# 6494 "<previous_module>"
__CPROVER_assume(!(__cs_local_exponential_backoff_loop < 3));
                                                        
# 6495 "<previous_module>"
__exit_loop_83:
                                                        __CPROVER_assume(__cs_pc_cs[0] >= 457);

                                                        
# 6496 "<previous_module>"
;
                                                        ;
                                                        
# 6497 "<previous_module>"
__exit__exponential_backoff_6_8:
                                                        __CPROVER_assume(__cs_pc_cs[0] >= 457);

                                                        
# 6498 "<previous_module>"
;
                                                        ;
                                                }
                                                
# 6500 "<previous_module>"
;
                                        }

                                        
# 6502 "<previous_module>"
__CPROVER_assume(__cs_pc_cs[0] >= 457);
                                        ;
                                        
# 6503 "<previous_module>"
__cs_local_lfds711_stack_push_i++;
                                        
# 6504 "<previous_module>"
;
                                        ;
                                        
# 6505 "<previous_module>"
static _Bool __cs_local_lfds711_stack_push___cs_tmp_if_cond_17;
                                        
# 6506 "<previous_module>"
__cs_local_lfds711_stack_push___cs_tmp_if_cond_17 = __cs_local_lfds711_stack_push_i > 1000;
                                        
# 6507 "<previous_module>"
if (__cs_local_lfds711_stack_push___cs_tmp_if_cond_17)

# 6508 "<previous_module>"
                                        {
                                                
# 6509 "<previous_module>"
goto __exit_loop_79;
                                                ;
                                        }

                                        
# 6511 "<previous_module>"
;
                                }
                                
# 6513 "<previous_module>"
;
                                
# 6514 "<previous_module>"
if (!(__cs_local_lfds711_stack_push_result == 0))

# 6515 "<previous_module>"
                                {
                                        
# 6516 "<previous_module>"
goto __exit_loop_79;
                                        ;
                                }

                                
# 6518 "<previous_module>"
;

# 6519 "<previous_module>"
                                {
                                        
# 6520 "<previous_module>"
tmain_457: IF(0,457,tmain_458)__CSEQ_removeindent;
                                        
# 6521 "<previous_module>"
__cs_mutex_lock(&library_lock, 0);
                                        
# 6522 "<previous_module>"
tmain_458: IF(0,458,tmain_459)__CSEQ_removeindent;
                                        
# 6523 "<previous_module>"
(*__cs_param_lfds711_stack_push_se).next = __cs_local_lfds711_stack_push_original_top[0];
                                        
# 6524 "<previous_module>"
tmain_459: IF(0,459,tmain_460)__CSEQ_removeindent;
                                        
# 6525 "<previous_module>"
__cs_mutex_unlock(&library_lock, 0);
                                        
# 6526 "<previous_module>"
tmain_460: IF(0,460,tmain_461)__CSEQ_removeindent;
                                        
# 6527 "<previous_module>"
__cs_local_lfds711_stack_push_new_top[1] = __cs_local_lfds711_stack_push_original_top[1] + 1;
                                        
# 6528 "<previous_module>"
tmain_461: IF(0,461,tmain_462)__CSEQ_removeindent;
                                        
# 6529 "<previous_module>"
__cs_mutex_lock(&library_lock, 0);
                                        
# 6530 "<previous_module>"
tmain_462: IF(0,462,tmain_463)__CSEQ_removeindent;
                                        
# 6531 "<previous_module>"
__cs_local_lfds711_stack_push_result = __CSEQ_atomic_swap_stack_top(&(*__cs_param_lfds711_stack_push_ss).top[0], &__cs_local_lfds711_stack_push_original_top[0], &__cs_local_lfds711_stack_push_new_top[0]);
                                        
# 6532 "<previous_module>"
tmain_463: IF(0,463,tmain_464)__CSEQ_removeindent;
                                        
# 6533 "<previous_module>"
__cs_mutex_unlock(&library_lock, 0);
                                        
# 6534 "<previous_module>"
;
                                        ;
                                        
# 6535 "<previous_module>"
static _Bool __cs_local_lfds711_stack_push___cs_tmp_if_cond_16;
                                        
# 6536 "<previous_module>"
__cs_local_lfds711_stack_push___cs_tmp_if_cond_16 = __cs_local_lfds711_stack_push_result == 0;
                                        
# 6537 "<previous_module>"
if (__cs_local_lfds711_stack_push___cs_tmp_if_cond_16)

# 6538 "<previous_module>"
                                        {

# 6539 "<previous_module>"
                                                {
                                                        
# 6540 "<previous_module>"
static int __cs_local_exponential_backoff_loop;
                                                        
# 6541 "<previous_module>"
__cs_local_exponential_backoff_loop = 0;

# 6542 "<previous_module>"
                                                        {
                                                                
# 6543 "<previous_module>"
;
                                                                ;
                                                        }
                                                        
# 6545 "<previous_module>"
;
                                                        
# 6546 "<previous_module>"
__cs_local_exponential_backoff_loop++;

# 6547 "<previous_module>"
                                                        {
                                                                
# 6548 "<previous_module>"
;
                                                                ;
                                                        }
                                                        
# 6550 "<previous_module>"
;
                                                        
# 6551 "<previous_module>"
__cs_local_exponential_backoff_loop++;

# 6552 "<previous_module>"
                                                        {
                                                                
# 6553 "<previous_module>"
;
                                                                ;
                                                        }
                                                        
# 6555 "<previous_module>"
;
                                                        
# 6556 "<previous_module>"
__cs_local_exponential_backoff_loop++;
                                                        
# 6557 "<previous_module>"
tmain_464: IF(0,464,tmain_465)__CSEQ_removeindent;
                                                        
# 6558 "<previous_module>"
__CPROVER_assume(!(__cs_local_exponential_backoff_loop < 3));
                                                        
# 6559 "<previous_module>"
__exit_loop_84:
                                                        __CPROVER_assume(__cs_pc_cs[0] >= 465);

                                                        
# 6560 "<previous_module>"
;
                                                        ;
                                                        
# 6561 "<previous_module>"
__exit__exponential_backoff_6_9:
                                                        __CPROVER_assume(__cs_pc_cs[0] >= 465);

                                                        
# 6562 "<previous_module>"
;
                                                        ;
                                                }
                                                
# 6564 "<previous_module>"
;
                                        }

                                        
# 6566 "<previous_module>"
__CPROVER_assume(__cs_pc_cs[0] >= 465);
                                        ;
                                        
# 6567 "<previous_module>"
__cs_local_lfds711_stack_push_i++;
                                        
# 6568 "<previous_module>"
;
                                        ;
                                        
# 6569 "<previous_module>"
static _Bool __cs_local_lfds711_stack_push___cs_tmp_if_cond_17;
                                        
# 6570 "<previous_module>"
__cs_local_lfds711_stack_push___cs_tmp_if_cond_17 = __cs_local_lfds711_stack_push_i > 1000;
                                        
# 6571 "<previous_module>"
if (__cs_local_lfds711_stack_push___cs_tmp_if_cond_17)

# 6572 "<previous_module>"
                                        {
                                                
# 6573 "<previous_module>"
goto __exit_loop_79;
                                                ;
                                        }

                                        
# 6575 "<previous_module>"
;
                                }
                                
# 6577 "<previous_module>"
;
                                
# 6578 "<previous_module>"
tmain_465: IF(0,465,tmain_466)__CSEQ_removeindent;
                                
# 6579 "<previous_module>"
__CPROVER_assume(!(__cs_local_lfds711_stack_push_result == 0));
                                
# 6580 "<previous_module>"
__exit_loop_79:
                                __CPROVER_assume(__cs_pc_cs[0] >= 466);

                                
# 6581 "<previous_module>"
;
                                ;
                                
# 6582 "<previous_module>"
goto __exit__lfds711_stack_push_2_1;
                                ;
                                
# 6583 "<previous_module>"
__exit__lfds711_stack_push_2_1:
                                __CPROVER_assume(__cs_pc_cs[0] >= 466);

                                
# 6584 "<previous_module>"
;
                                ;
                        }
                        
# 6586 "<previous_module>"
;
                        
# 6587 "<previous_module>"
__cs_local_contains_i++;
                }
                
# 6589 "<previous_module>"
;
                
# 6590 "<previous_module>"
if (!(__cs_local_contains_i < __cs_local_contains_actual_size))

# 6591 "<previous_module>"
                {
                        
# 6592 "<previous_module>"
goto __exit_loop_72;
                        ;
                }

                
# 6594 "<previous_module>"
;

# 6595 "<previous_module>"
                {

# 6596 "<previous_module>"
                        {
                                
# 6597 "<previous_module>"
static struct lfds711_stack_state *__cs_param_lfds711_stack_push_ss;
                                
# 6598 "<previous_module>"
tmain_466: IF(0,466,tmain_467)__CSEQ_removeindent;
                                
# 6599 "<previous_module>"
__cs_param_lfds711_stack_push_ss = __cs_param_contains_s;
                                
# 6600 "<previous_module>"
static struct lfds711_stack_element *__cs_param_lfds711_stack_push_se;
                                
# 6601 "<previous_module>"
tmain_467: IF(0,467,tmain_468)__CSEQ_removeindent;
                                
# 6602 "<previous_module>"
__cs_param_lfds711_stack_push_se = &(*__cs_local_contains_datas[__cs_local_contains_i]).se;
                                
# 6603 "<previous_module>"
static char unsigned __cs_local_lfds711_stack_push_result;
                                
# 6604 "<previous_module>"
static lfds711_pal_uint_t __cs_local_lfds711_stack_push_backoff_iteration;
                                
# 6605 "<previous_module>"
__cs_local_lfds711_stack_push_backoff_iteration = 0;
                                
# 6606 "<previous_module>"
static struct lfds711_stack_element *__cs_local_lfds711_stack_push_new_top[2];
                                
# 6607 "<previous_module>"
static struct lfds711_stack_element * volatile __cs_local_lfds711_stack_push_original_top[2];
                                
# 6608 "<previous_module>"
;
                                ;
                                
# 6609 "<previous_module>"
static _Bool __cs_local_lfds711_stack_push___cs_tmp_if_cond_14;
                                
# 6610 "<previous_module>"
tmain_468: IF(0,468,tmain_469)__CSEQ_removeindent;
                                
# 6611 "<previous_module>"
__cs_local_lfds711_stack_push___cs_tmp_if_cond_14 = !(__cs_param_lfds711_stack_push_ss != 0);
                                
# 6612 "<previous_module>"
if (__cs_local_lfds711_stack_push___cs_tmp_if_cond_14)

# 6613 "<previous_module>"
                                {
                                        
# 6614 "<previous_module>"
static char *__cs_local_lfds711_stack_push_c;
                                        
# 6615 "<previous_module>"
tmain_469: IF(0,469,tmain_470)__CSEQ_removeindent;
                                        
# 6616 "<previous_module>"
__cs_local_lfds711_stack_push_c = 0;
                                        
# 6617 "<previous_module>"
tmain_470: IF(0,470,tmain_471)__CSEQ_removeindent;
                                        
# 6618 "<previous_module>"
*__cs_local_lfds711_stack_push_c = 0;
                                }

                                
# 6620 "<previous_module>"
__CPROVER_assume(__cs_pc_cs[0] >= 471);
                                ;
                                
# 6621 "<previous_module>"
;
                                ;
                                
# 6622 "<previous_module>"
;
                                ;
                                
# 6623 "<previous_module>"
;
                                ;
                                
# 6624 "<previous_module>"
static _Bool __cs_local_lfds711_stack_push___cs_tmp_if_cond_15;
                                
# 6625 "<previous_module>"
tmain_471: IF(0,471,tmain_472)__CSEQ_removeindent;
                                
# 6626 "<previous_module>"
__cs_local_lfds711_stack_push___cs_tmp_if_cond_15 = !(__cs_param_lfds711_stack_push_se != 0);
                                
# 6627 "<previous_module>"
if (__cs_local_lfds711_stack_push___cs_tmp_if_cond_15)

# 6628 "<previous_module>"
                                {
                                        
# 6629 "<previous_module>"
static char *__cs_local_lfds711_stack_push_c;
                                        
# 6630 "<previous_module>"
tmain_472: IF(0,472,tmain_473)__CSEQ_removeindent;
                                        
# 6631 "<previous_module>"
__cs_local_lfds711_stack_push_c = 0;
                                        
# 6632 "<previous_module>"
tmain_473: IF(0,473,tmain_474)__CSEQ_removeindent;
                                        
# 6633 "<previous_module>"
*__cs_local_lfds711_stack_push_c = 0;
                                }

                                
# 6635 "<previous_module>"
__CPROVER_assume(__cs_pc_cs[0] >= 474);
                                ;
                                
# 6636 "<previous_module>"
;
                                ;
                                
# 6637 "<previous_module>"
;
                                ;
                                
# 6638 "<previous_module>"
tmain_474: IF(0,474,tmain_475)__CSEQ_removeindent;
                                
# 6639 "<previous_module>"
__cs_local_lfds711_stack_push_new_top[0] = __cs_param_lfds711_stack_push_se;
                                
# 6640 "<previous_module>"
tmain_475: IF(0,475,tmain_476)__CSEQ_removeindent;
                                
# 6641 "<previous_module>"
__cs_local_lfds711_stack_push_original_top[1] = (*__cs_param_lfds711_stack_push_ss).top[1];
                                
# 6642 "<previous_module>"
tmain_476: IF(0,476,tmain_477)__CSEQ_removeindent;
                                
# 6643 "<previous_module>"
__cs_local_lfds711_stack_push_original_top[0] = (*__cs_param_lfds711_stack_push_ss).top[0];
                                
# 6644 "<previous_module>"
__cs_local_lfds711_stack_push_result = 0;
                                
# 6645 "<previous_module>"
static int __cs_local_lfds711_stack_push_i;
                                
# 6646 "<previous_module>"
__cs_local_lfds711_stack_push_i = 0;
                                
# 6647 "<previous_module>"
if (!(__cs_local_lfds711_stack_push_result == 0))

# 6648 "<previous_module>"
                                {
                                        
# 6649 "<previous_module>"
goto __exit_loop_85;
                                        ;
                                }

                                
# 6651 "<previous_module>"
;

# 6652 "<previous_module>"
                                {
                                        
# 6653 "<previous_module>"
tmain_477: IF(0,477,tmain_478)__CSEQ_removeindent;
                                        
# 6654 "<previous_module>"
__cs_mutex_lock(&library_lock, 0);
                                        
# 6655 "<previous_module>"
tmain_478: IF(0,478,tmain_479)__CSEQ_removeindent;
                                        
# 6656 "<previous_module>"
(*__cs_param_lfds711_stack_push_se).next = __cs_local_lfds711_stack_push_original_top[0];
                                        
# 6657 "<previous_module>"
tmain_479: IF(0,479,tmain_480)__CSEQ_removeindent;
                                        
# 6658 "<previous_module>"
__cs_mutex_unlock(&library_lock, 0);
                                        
# 6659 "<previous_module>"
tmain_480: IF(0,480,tmain_481)__CSEQ_removeindent;
                                        
# 6660 "<previous_module>"
__cs_local_lfds711_stack_push_new_top[1] = __cs_local_lfds711_stack_push_original_top[1] + 1;
                                        
# 6661 "<previous_module>"
tmain_481: IF(0,481,tmain_482)__CSEQ_removeindent;
                                        
# 6662 "<previous_module>"
__cs_mutex_lock(&library_lock, 0);
                                        
# 6663 "<previous_module>"
tmain_482: IF(0,482,tmain_483)__CSEQ_removeindent;
                                        
# 6664 "<previous_module>"
__cs_local_lfds711_stack_push_result = __CSEQ_atomic_swap_stack_top(&(*__cs_param_lfds711_stack_push_ss).top[0], &__cs_local_lfds711_stack_push_original_top[0], &__cs_local_lfds711_stack_push_new_top[0]);
                                        
# 6665 "<previous_module>"
tmain_483: IF(0,483,tmain_484)__CSEQ_removeindent;
                                        
# 6666 "<previous_module>"
__cs_mutex_unlock(&library_lock, 0);
                                        
# 6667 "<previous_module>"
;
                                        ;
                                        
# 6668 "<previous_module>"
static _Bool __cs_local_lfds711_stack_push___cs_tmp_if_cond_16;
                                        
# 6669 "<previous_module>"
__cs_local_lfds711_stack_push___cs_tmp_if_cond_16 = __cs_local_lfds711_stack_push_result == 0;
                                        
# 6670 "<previous_module>"
if (__cs_local_lfds711_stack_push___cs_tmp_if_cond_16)

# 6671 "<previous_module>"
                                        {

# 6672 "<previous_module>"
                                                {
                                                        
# 6673 "<previous_module>"
static int __cs_local_exponential_backoff_loop;
                                                        
# 6674 "<previous_module>"
__cs_local_exponential_backoff_loop = 0;

# 6675 "<previous_module>"
                                                        {
                                                                
# 6676 "<previous_module>"
;
                                                                ;
                                                        }
                                                        
# 6678 "<previous_module>"
;
                                                        
# 6679 "<previous_module>"
__cs_local_exponential_backoff_loop++;

# 6680 "<previous_module>"
                                                        {
                                                                
# 6681 "<previous_module>"
;
                                                                ;
                                                        }
                                                        
# 6683 "<previous_module>"
;
                                                        
# 6684 "<previous_module>"
__cs_local_exponential_backoff_loop++;

# 6685 "<previous_module>"
                                                        {
                                                                
# 6686 "<previous_module>"
;
                                                                ;
                                                        }
                                                        
# 6688 "<previous_module>"
;
                                                        
# 6689 "<previous_module>"
__cs_local_exponential_backoff_loop++;
                                                        
# 6690 "<previous_module>"
tmain_484: IF(0,484,tmain_485)__CSEQ_removeindent;
                                                        
# 6691 "<previous_module>"
__CPROVER_assume(!(__cs_local_exponential_backoff_loop < 3));
                                                        
# 6692 "<previous_module>"
__exit_loop_86:
                                                        __CPROVER_assume(__cs_pc_cs[0] >= 485);

                                                        
# 6693 "<previous_module>"
;
                                                        ;
                                                        
# 6694 "<previous_module>"
__exit__exponential_backoff_6_10:
                                                        __CPROVER_assume(__cs_pc_cs[0] >= 485);

                                                        
# 6695 "<previous_module>"
;
                                                        ;
                                                }
                                                
# 6697 "<previous_module>"
;
                                        }

                                        
# 6699 "<previous_module>"
__CPROVER_assume(__cs_pc_cs[0] >= 485);
                                        ;
                                        
# 6700 "<previous_module>"
__cs_local_lfds711_stack_push_i++;
                                        
# 6701 "<previous_module>"
;
                                        ;
                                        
# 6702 "<previous_module>"
static _Bool __cs_local_lfds711_stack_push___cs_tmp_if_cond_17;
                                        
# 6703 "<previous_module>"
__cs_local_lfds711_stack_push___cs_tmp_if_cond_17 = __cs_local_lfds711_stack_push_i > 1000;
                                        
# 6704 "<previous_module>"
if (__cs_local_lfds711_stack_push___cs_tmp_if_cond_17)

# 6705 "<previous_module>"
                                        {
                                                
# 6706 "<previous_module>"
goto __exit_loop_85;
                                                ;
                                        }

                                        
# 6708 "<previous_module>"
;
                                }
                                
# 6710 "<previous_module>"
;
                                
# 6711 "<previous_module>"
if (!(__cs_local_lfds711_stack_push_result == 0))

# 6712 "<previous_module>"
                                {
                                        
# 6713 "<previous_module>"
goto __exit_loop_85;
                                        ;
                                }

                                
# 6715 "<previous_module>"
;

# 6716 "<previous_module>"
                                {
                                        
# 6717 "<previous_module>"
tmain_485: IF(0,485,tmain_486)__CSEQ_removeindent;
                                        
# 6718 "<previous_module>"
__cs_mutex_lock(&library_lock, 0);
                                        
# 6719 "<previous_module>"
tmain_486: IF(0,486,tmain_487)__CSEQ_removeindent;
                                        
# 6720 "<previous_module>"
(*__cs_param_lfds711_stack_push_se).next = __cs_local_lfds711_stack_push_original_top[0];
                                        
# 6721 "<previous_module>"
tmain_487: IF(0,487,tmain_488)__CSEQ_removeindent;
                                        
# 6722 "<previous_module>"
__cs_mutex_unlock(&library_lock, 0);
                                        
# 6723 "<previous_module>"
tmain_488: IF(0,488,tmain_489)__CSEQ_removeindent;
                                        
# 6724 "<previous_module>"
__cs_local_lfds711_stack_push_new_top[1] = __cs_local_lfds711_stack_push_original_top[1] + 1;
                                        
# 6725 "<previous_module>"
tmain_489: IF(0,489,tmain_490)__CSEQ_removeindent;
                                        
# 6726 "<previous_module>"
__cs_mutex_lock(&library_lock, 0);
                                        
# 6727 "<previous_module>"
tmain_490: IF(0,490,tmain_491)__CSEQ_removeindent;
                                        
# 6728 "<previous_module>"
__cs_local_lfds711_stack_push_result = __CSEQ_atomic_swap_stack_top(&(*__cs_param_lfds711_stack_push_ss).top[0], &__cs_local_lfds711_stack_push_original_top[0], &__cs_local_lfds711_stack_push_new_top[0]);
                                        
# 6729 "<previous_module>"
tmain_491: IF(0,491,tmain_492)__CSEQ_removeindent;
                                        
# 6730 "<previous_module>"
__cs_mutex_unlock(&library_lock, 0);
                                        
# 6731 "<previous_module>"
;
                                        ;
                                        
# 6732 "<previous_module>"
static _Bool __cs_local_lfds711_stack_push___cs_tmp_if_cond_16;
                                        
# 6733 "<previous_module>"
__cs_local_lfds711_stack_push___cs_tmp_if_cond_16 = __cs_local_lfds711_stack_push_result == 0;
                                        
# 6734 "<previous_module>"
if (__cs_local_lfds711_stack_push___cs_tmp_if_cond_16)

# 6735 "<previous_module>"
                                        {

# 6736 "<previous_module>"
                                                {
                                                        
# 6737 "<previous_module>"
static int __cs_local_exponential_backoff_loop;
                                                        
# 6738 "<previous_module>"
__cs_local_exponential_backoff_loop = 0;

# 6739 "<previous_module>"
                                                        {
                                                                
# 6740 "<previous_module>"
;
                                                                ;
                                                        }
                                                        
# 6742 "<previous_module>"
;
                                                        
# 6743 "<previous_module>"
__cs_local_exponential_backoff_loop++;

# 6744 "<previous_module>"
                                                        {
                                                                
# 6745 "<previous_module>"
;
                                                                ;
                                                        }
                                                        
# 6747 "<previous_module>"
;
                                                        
# 6748 "<previous_module>"
__cs_local_exponential_backoff_loop++;

# 6749 "<previous_module>"
                                                        {
                                                                
# 6750 "<previous_module>"
;
                                                                ;
                                                        }
                                                        
# 6752 "<previous_module>"
;
                                                        
# 6753 "<previous_module>"
__cs_local_exponential_backoff_loop++;
                                                        
# 6754 "<previous_module>"
tmain_492: IF(0,492,tmain_493)__CSEQ_removeindent;
                                                        
# 6755 "<previous_module>"
__CPROVER_assume(!(__cs_local_exponential_backoff_loop < 3));
                                                        
# 6756 "<previous_module>"
__exit_loop_87:
                                                        __CPROVER_assume(__cs_pc_cs[0] >= 493);

                                                        
# 6757 "<previous_module>"
;
                                                        ;
                                                        
# 6758 "<previous_module>"
__exit__exponential_backoff_6_11:
                                                        __CPROVER_assume(__cs_pc_cs[0] >= 493);

                                                        
# 6759 "<previous_module>"
;
                                                        ;
                                                }
                                                
# 6761 "<previous_module>"
;
                                        }

                                        
# 6763 "<previous_module>"
__CPROVER_assume(__cs_pc_cs[0] >= 493);
                                        ;
                                        
# 6764 "<previous_module>"
__cs_local_lfds711_stack_push_i++;
                                        
# 6765 "<previous_module>"
;
                                        ;
                                        
# 6766 "<previous_module>"
static _Bool __cs_local_lfds711_stack_push___cs_tmp_if_cond_17;
                                        
# 6767 "<previous_module>"
__cs_local_lfds711_stack_push___cs_tmp_if_cond_17 = __cs_local_lfds711_stack_push_i > 1000;
                                        
# 6768 "<previous_module>"
if (__cs_local_lfds711_stack_push___cs_tmp_if_cond_17)

# 6769 "<previous_module>"
                                        {
                                                
# 6770 "<previous_module>"
goto __exit_loop_85;
                                                ;
                                        }

                                        
# 6772 "<previous_module>"
;
                                }
                                
# 6774 "<previous_module>"
;
                                
# 6775 "<previous_module>"
if (!(__cs_local_lfds711_stack_push_result == 0))

# 6776 "<previous_module>"
                                {
                                        
# 6777 "<previous_module>"
goto __exit_loop_85;
                                        ;
                                }

                                
# 6779 "<previous_module>"
;

# 6780 "<previous_module>"
                                {
                                        
# 6781 "<previous_module>"
tmain_493: IF(0,493,tmain_494)__CSEQ_removeindent;
                                        
# 6782 "<previous_module>"
__cs_mutex_lock(&library_lock, 0);
                                        
# 6783 "<previous_module>"
tmain_494: IF(0,494,tmain_495)__CSEQ_removeindent;
                                        
# 6784 "<previous_module>"
(*__cs_param_lfds711_stack_push_se).next = __cs_local_lfds711_stack_push_original_top[0];
                                        
# 6785 "<previous_module>"
tmain_495: IF(0,495,tmain_496)__CSEQ_removeindent;
                                        
# 6786 "<previous_module>"
__cs_mutex_unlock(&library_lock, 0);
                                        
# 6787 "<previous_module>"
tmain_496: IF(0,496,tmain_497)__CSEQ_removeindent;
                                        
# 6788 "<previous_module>"
__cs_local_lfds711_stack_push_new_top[1] = __cs_local_lfds711_stack_push_original_top[1] + 1;
                                        
# 6789 "<previous_module>"
tmain_497: IF(0,497,tmain_498)__CSEQ_removeindent;
                                        
# 6790 "<previous_module>"
__cs_mutex_lock(&library_lock, 0);
                                        
# 6791 "<previous_module>"
tmain_498: IF(0,498,tmain_499)__CSEQ_removeindent;
                                        
# 6792 "<previous_module>"
__cs_local_lfds711_stack_push_result = __CSEQ_atomic_swap_stack_top(&(*__cs_param_lfds711_stack_push_ss).top[0], &__cs_local_lfds711_stack_push_original_top[0], &__cs_local_lfds711_stack_push_new_top[0]);
                                        
# 6793 "<previous_module>"
tmain_499: IF(0,499,tmain_500)__CSEQ_removeindent;
                                        
# 6794 "<previous_module>"
__cs_mutex_unlock(&library_lock, 0);
                                        
# 6795 "<previous_module>"
;
                                        ;
                                        
# 6796 "<previous_module>"
static _Bool __cs_local_lfds711_stack_push___cs_tmp_if_cond_16;
                                        
# 6797 "<previous_module>"
__cs_local_lfds711_stack_push___cs_tmp_if_cond_16 = __cs_local_lfds711_stack_push_result == 0;
                                        
# 6798 "<previous_module>"
if (__cs_local_lfds711_stack_push___cs_tmp_if_cond_16)

# 6799 "<previous_module>"
                                        {

# 6800 "<previous_module>"
                                                {
                                                        
# 6801 "<previous_module>"
static int __cs_local_exponential_backoff_loop;
                                                        
# 6802 "<previous_module>"
__cs_local_exponential_backoff_loop = 0;

# 6803 "<previous_module>"
                                                        {
                                                                
# 6804 "<previous_module>"
;
                                                                ;
                                                        }
                                                        
# 6806 "<previous_module>"
;
                                                        
# 6807 "<previous_module>"
__cs_local_exponential_backoff_loop++;

# 6808 "<previous_module>"
                                                        {
                                                                
# 6809 "<previous_module>"
;
                                                                ;
                                                        }
                                                        
# 6811 "<previous_module>"
;
                                                        
# 6812 "<previous_module>"
__cs_local_exponential_backoff_loop++;

# 6813 "<previous_module>"
                                                        {
                                                                
# 6814 "<previous_module>"
;
                                                                ;
                                                        }
                                                        
# 6816 "<previous_module>"
;
                                                        
# 6817 "<previous_module>"
__cs_local_exponential_backoff_loop++;
                                                        
# 6818 "<previous_module>"
tmain_500: IF(0,500,tmain_501)__CSEQ_removeindent;
                                                        
# 6819 "<previous_module>"
__CPROVER_assume(!(__cs_local_exponential_backoff_loop < 3));
                                                        
# 6820 "<previous_module>"
__exit_loop_88:
                                                        __CPROVER_assume(__cs_pc_cs[0] >= 501);

                                                        
# 6821 "<previous_module>"
;
                                                        ;
                                                        
# 6822 "<previous_module>"
__exit__exponential_backoff_6_12:
                                                        __CPROVER_assume(__cs_pc_cs[0] >= 501);

                                                        
# 6823 "<previous_module>"
;
                                                        ;
                                                }
                                                
# 6825 "<previous_module>"
;
                                        }

                                        
# 6827 "<previous_module>"
__CPROVER_assume(__cs_pc_cs[0] >= 501);
                                        ;
                                        
# 6828 "<previous_module>"
__cs_local_lfds711_stack_push_i++;
                                        
# 6829 "<previous_module>"
;
                                        ;
                                        
# 6830 "<previous_module>"
static _Bool __cs_local_lfds711_stack_push___cs_tmp_if_cond_17;
                                        
# 6831 "<previous_module>"
__cs_local_lfds711_stack_push___cs_tmp_if_cond_17 = __cs_local_lfds711_stack_push_i > 1000;
                                        
# 6832 "<previous_module>"
if (__cs_local_lfds711_stack_push___cs_tmp_if_cond_17)

# 6833 "<previous_module>"
                                        {
                                                
# 6834 "<previous_module>"
goto __exit_loop_85;
                                                ;
                                        }

                                        
# 6836 "<previous_module>"
;
                                }
                                
# 6838 "<previous_module>"
;
                                
# 6839 "<previous_module>"
if (!(__cs_local_lfds711_stack_push_result == 0))

# 6840 "<previous_module>"
                                {
                                        
# 6841 "<previous_module>"
goto __exit_loop_85;
                                        ;
                                }

                                
# 6843 "<previous_module>"
;

# 6844 "<previous_module>"
                                {
                                        
# 6845 "<previous_module>"
tmain_501: IF(0,501,tmain_502)__CSEQ_removeindent;
                                        
# 6846 "<previous_module>"
__cs_mutex_lock(&library_lock, 0);
                                        
# 6847 "<previous_module>"
tmain_502: IF(0,502,tmain_503)__CSEQ_removeindent;
                                        
# 6848 "<previous_module>"
(*__cs_param_lfds711_stack_push_se).next = __cs_local_lfds711_stack_push_original_top[0];
                                        
# 6849 "<previous_module>"
tmain_503: IF(0,503,tmain_504)__CSEQ_removeindent;
                                        
# 6850 "<previous_module>"
__cs_mutex_unlock(&library_lock, 0);
                                        
# 6851 "<previous_module>"
tmain_504: IF(0,504,tmain_505)__CSEQ_removeindent;
                                        
# 6852 "<previous_module>"
__cs_local_lfds711_stack_push_new_top[1] = __cs_local_lfds711_stack_push_original_top[1] + 1;
                                        
# 6853 "<previous_module>"
tmain_505: IF(0,505,tmain_506)__CSEQ_removeindent;
                                        
# 6854 "<previous_module>"
__cs_mutex_lock(&library_lock, 0);
                                        
# 6855 "<previous_module>"
tmain_506: IF(0,506,tmain_507)__CSEQ_removeindent;
                                        
# 6856 "<previous_module>"
__cs_local_lfds711_stack_push_result = __CSEQ_atomic_swap_stack_top(&(*__cs_param_lfds711_stack_push_ss).top[0], &__cs_local_lfds711_stack_push_original_top[0], &__cs_local_lfds711_stack_push_new_top[0]);
                                        
# 6857 "<previous_module>"
tmain_507: IF(0,507,tmain_508)__CSEQ_removeindent;
                                        
# 6858 "<previous_module>"
__cs_mutex_unlock(&library_lock, 0);
                                        
# 6859 "<previous_module>"
;
                                        ;
                                        
# 6860 "<previous_module>"
static _Bool __cs_local_lfds711_stack_push___cs_tmp_if_cond_16;
                                        
# 6861 "<previous_module>"
__cs_local_lfds711_stack_push___cs_tmp_if_cond_16 = __cs_local_lfds711_stack_push_result == 0;
                                        
# 6862 "<previous_module>"
if (__cs_local_lfds711_stack_push___cs_tmp_if_cond_16)

# 6863 "<previous_module>"
                                        {

# 6864 "<previous_module>"
                                                {
                                                        
# 6865 "<previous_module>"
static int __cs_local_exponential_backoff_loop;
                                                        
# 6866 "<previous_module>"
__cs_local_exponential_backoff_loop = 0;

# 6867 "<previous_module>"
                                                        {
                                                                
# 6868 "<previous_module>"
;
                                                                ;
                                                        }
                                                        
# 6870 "<previous_module>"
;
                                                        
# 6871 "<previous_module>"
__cs_local_exponential_backoff_loop++;

# 6872 "<previous_module>"
                                                        {
                                                                
# 6873 "<previous_module>"
;
                                                                ;
                                                        }
                                                        
# 6875 "<previous_module>"
;
                                                        
# 6876 "<previous_module>"
__cs_local_exponential_backoff_loop++;

# 6877 "<previous_module>"
                                                        {
                                                                
# 6878 "<previous_module>"
;
                                                                ;
                                                        }
                                                        
# 6880 "<previous_module>"
;
                                                        
# 6881 "<previous_module>"
__cs_local_exponential_backoff_loop++;
                                                        
# 6882 "<previous_module>"
tmain_508: IF(0,508,tmain_509)__CSEQ_removeindent;
                                                        
# 6883 "<previous_module>"
__CPROVER_assume(!(__cs_local_exponential_backoff_loop < 3));
                                                        
# 6884 "<previous_module>"
__exit_loop_89:
                                                        __CPROVER_assume(__cs_pc_cs[0] >= 509);

                                                        
# 6885 "<previous_module>"
;
                                                        ;
                                                        
# 6886 "<previous_module>"
__exit__exponential_backoff_6_13:
                                                        __CPROVER_assume(__cs_pc_cs[0] >= 509);

                                                        
# 6887 "<previous_module>"
;
                                                        ;
                                                }
                                                
# 6889 "<previous_module>"
;
                                        }

                                        
# 6891 "<previous_module>"
__CPROVER_assume(__cs_pc_cs[0] >= 509);
                                        ;
                                        
# 6892 "<previous_module>"
__cs_local_lfds711_stack_push_i++;
                                        
# 6893 "<previous_module>"
;
                                        ;
                                        
# 6894 "<previous_module>"
static _Bool __cs_local_lfds711_stack_push___cs_tmp_if_cond_17;
                                        
# 6895 "<previous_module>"
__cs_local_lfds711_stack_push___cs_tmp_if_cond_17 = __cs_local_lfds711_stack_push_i > 1000;
                                        
# 6896 "<previous_module>"
if (__cs_local_lfds711_stack_push___cs_tmp_if_cond_17)

# 6897 "<previous_module>"
                                        {
                                                
# 6898 "<previous_module>"
goto __exit_loop_85;
                                                ;
                                        }

                                        
# 6900 "<previous_module>"
;
                                }
                                
# 6902 "<previous_module>"
;
                                
# 6903 "<previous_module>"
if (!(__cs_local_lfds711_stack_push_result == 0))

# 6904 "<previous_module>"
                                {
                                        
# 6905 "<previous_module>"
goto __exit_loop_85;
                                        ;
                                }

                                
# 6907 "<previous_module>"
;

# 6908 "<previous_module>"
                                {
                                        
# 6909 "<previous_module>"
tmain_509: IF(0,509,tmain_510)__CSEQ_removeindent;
                                        
# 6910 "<previous_module>"
__cs_mutex_lock(&library_lock, 0);
                                        
# 6911 "<previous_module>"
tmain_510: IF(0,510,tmain_511)__CSEQ_removeindent;
                                        
# 6912 "<previous_module>"
(*__cs_param_lfds711_stack_push_se).next = __cs_local_lfds711_stack_push_original_top[0];
                                        
# 6913 "<previous_module>"
tmain_511: IF(0,511,tmain_512)__CSEQ_removeindent;
                                        
# 6914 "<previous_module>"
__cs_mutex_unlock(&library_lock, 0);
                                        
# 6915 "<previous_module>"
tmain_512: IF(0,512,tmain_513)__CSEQ_removeindent;
                                        
# 6916 "<previous_module>"
__cs_local_lfds711_stack_push_new_top[1] = __cs_local_lfds711_stack_push_original_top[1] + 1;
                                        
# 6917 "<previous_module>"
tmain_513: IF(0,513,tmain_514)__CSEQ_removeindent;
                                        
# 6918 "<previous_module>"
__cs_mutex_lock(&library_lock, 0);
                                        
# 6919 "<previous_module>"
tmain_514: IF(0,514,tmain_515)__CSEQ_removeindent;
                                        
# 6920 "<previous_module>"
__cs_local_lfds711_stack_push_result = __CSEQ_atomic_swap_stack_top(&(*__cs_param_lfds711_stack_push_ss).top[0], &__cs_local_lfds711_stack_push_original_top[0], &__cs_local_lfds711_stack_push_new_top[0]);
                                        
# 6921 "<previous_module>"
tmain_515: IF(0,515,tmain_516)__CSEQ_removeindent;
                                        
# 6922 "<previous_module>"
__cs_mutex_unlock(&library_lock, 0);
                                        
# 6923 "<previous_module>"
;
                                        ;
                                        
# 6924 "<previous_module>"
static _Bool __cs_local_lfds711_stack_push___cs_tmp_if_cond_16;
                                        
# 6925 "<previous_module>"
__cs_local_lfds711_stack_push___cs_tmp_if_cond_16 = __cs_local_lfds711_stack_push_result == 0;
                                        
# 6926 "<previous_module>"
if (__cs_local_lfds711_stack_push___cs_tmp_if_cond_16)

# 6927 "<previous_module>"
                                        {

# 6928 "<previous_module>"
                                                {
                                                        
# 6929 "<previous_module>"
static int __cs_local_exponential_backoff_loop;
                                                        
# 6930 "<previous_module>"
__cs_local_exponential_backoff_loop = 0;

# 6931 "<previous_module>"
                                                        {
                                                                
# 6932 "<previous_module>"
;
                                                                ;
                                                        }
                                                        
# 6934 "<previous_module>"
;
                                                        
# 6935 "<previous_module>"
__cs_local_exponential_backoff_loop++;

# 6936 "<previous_module>"
                                                        {
                                                                
# 6937 "<previous_module>"
;
                                                                ;
                                                        }
                                                        
# 6939 "<previous_module>"
;
                                                        
# 6940 "<previous_module>"
__cs_local_exponential_backoff_loop++;

# 6941 "<previous_module>"
                                                        {
                                                                
# 6942 "<previous_module>"
;
                                                                ;
                                                        }
                                                        
# 6944 "<previous_module>"
;
                                                        
# 6945 "<previous_module>"
__cs_local_exponential_backoff_loop++;
                                                        
# 6946 "<previous_module>"
tmain_516: IF(0,516,tmain_517)__CSEQ_removeindent;
                                                        
# 6947 "<previous_module>"
__CPROVER_assume(!(__cs_local_exponential_backoff_loop < 3));
                                                        
# 6948 "<previous_module>"
__exit_loop_90:
                                                        __CPROVER_assume(__cs_pc_cs[0] >= 517);

                                                        
# 6949 "<previous_module>"
;
                                                        ;
                                                        
# 6950 "<previous_module>"
__exit__exponential_backoff_6_14:
                                                        __CPROVER_assume(__cs_pc_cs[0] >= 517);

                                                        
# 6951 "<previous_module>"
;
                                                        ;
                                                }
                                                
# 6953 "<previous_module>"
;
                                        }

                                        
# 6955 "<previous_module>"
__CPROVER_assume(__cs_pc_cs[0] >= 517);
                                        ;
                                        
# 6956 "<previous_module>"
__cs_local_lfds711_stack_push_i++;
                                        
# 6957 "<previous_module>"
;
                                        ;
                                        
# 6958 "<previous_module>"
static _Bool __cs_local_lfds711_stack_push___cs_tmp_if_cond_17;
                                        
# 6959 "<previous_module>"
__cs_local_lfds711_stack_push___cs_tmp_if_cond_17 = __cs_local_lfds711_stack_push_i > 1000;
                                        
# 6960 "<previous_module>"
if (__cs_local_lfds711_stack_push___cs_tmp_if_cond_17)

# 6961 "<previous_module>"
                                        {
                                                
# 6962 "<previous_module>"
goto __exit_loop_85;
                                                ;
                                        }

                                        
# 6964 "<previous_module>"
;
                                }
                                
# 6966 "<previous_module>"
;
                                
# 6967 "<previous_module>"
tmain_517: IF(0,517,tmain_518)__CSEQ_removeindent;
                                
# 6968 "<previous_module>"
__CPROVER_assume(!(__cs_local_lfds711_stack_push_result == 0));
                                
# 6969 "<previous_module>"
__exit_loop_85:
                                __CPROVER_assume(__cs_pc_cs[0] >= 518);

                                
# 6970 "<previous_module>"
;
                                ;
                                
# 6971 "<previous_module>"
goto __exit__lfds711_stack_push_2_2;
                                ;
                                
# 6972 "<previous_module>"
__exit__lfds711_stack_push_2_2:
                                __CPROVER_assume(__cs_pc_cs[0] >= 518);

                                
# 6973 "<previous_module>"
;
                                ;
                        }
                        
# 6975 "<previous_module>"
;
                        
# 6976 "<previous_module>"
__cs_local_contains_i++;
                }
                
# 6978 "<previous_module>"
;
                
# 6979 "<previous_module>"
if (!(__cs_local_contains_i < __cs_local_contains_actual_size))

# 6980 "<previous_module>"
                {
                        
# 6981 "<previous_module>"
goto __exit_loop_72;
                        ;
                }

                
# 6983 "<previous_module>"
;

# 6984 "<previous_module>"
                {

# 6985 "<previous_module>"
                        {
                                
# 6986 "<previous_module>"
static struct lfds711_stack_state *__cs_param_lfds711_stack_push_ss;
                                
# 6987 "<previous_module>"
tmain_518: IF(0,518,tmain_519)__CSEQ_removeindent;
                                
# 6988 "<previous_module>"
__cs_param_lfds711_stack_push_ss = __cs_param_contains_s;
                                
# 6989 "<previous_module>"
static struct lfds711_stack_element *__cs_param_lfds711_stack_push_se;
                                
# 6990 "<previous_module>"
tmain_519: IF(0,519,tmain_520)__CSEQ_removeindent;
                                
# 6991 "<previous_module>"
__cs_param_lfds711_stack_push_se = &(*__cs_local_contains_datas[__cs_local_contains_i]).se;
                                
# 6992 "<previous_module>"
static char unsigned __cs_local_lfds711_stack_push_result;
                                
# 6993 "<previous_module>"
static lfds711_pal_uint_t __cs_local_lfds711_stack_push_backoff_iteration;
                                
# 6994 "<previous_module>"
__cs_local_lfds711_stack_push_backoff_iteration = 0;
                                
# 6995 "<previous_module>"
static struct lfds711_stack_element *__cs_local_lfds711_stack_push_new_top[2];
                                
# 6996 "<previous_module>"
static struct lfds711_stack_element * volatile __cs_local_lfds711_stack_push_original_top[2];
                                
# 6997 "<previous_module>"
;
                                ;
                                
# 6998 "<previous_module>"
static _Bool __cs_local_lfds711_stack_push___cs_tmp_if_cond_14;
                                
# 6999 "<previous_module>"
tmain_520: IF(0,520,tmain_521)__CSEQ_removeindent;
                                
# 7000 "<previous_module>"
__cs_local_lfds711_stack_push___cs_tmp_if_cond_14 = !(__cs_param_lfds711_stack_push_ss != 0);
                                
# 7001 "<previous_module>"
if (__cs_local_lfds711_stack_push___cs_tmp_if_cond_14)

# 7002 "<previous_module>"
                                {
                                        
# 7003 "<previous_module>"
static char *__cs_local_lfds711_stack_push_c;
                                        
# 7004 "<previous_module>"
tmain_521: IF(0,521,tmain_522)__CSEQ_removeindent;
                                        
# 7005 "<previous_module>"
__cs_local_lfds711_stack_push_c = 0;
                                        
# 7006 "<previous_module>"
tmain_522: IF(0,522,tmain_523)__CSEQ_removeindent;
                                        
# 7007 "<previous_module>"
*__cs_local_lfds711_stack_push_c = 0;
                                }

                                
# 7009 "<previous_module>"
__CPROVER_assume(__cs_pc_cs[0] >= 523);
                                ;
                                
# 7010 "<previous_module>"
;
                                ;
                                
# 7011 "<previous_module>"
;
                                ;
                                
# 7012 "<previous_module>"
;
                                ;
                                
# 7013 "<previous_module>"
static _Bool __cs_local_lfds711_stack_push___cs_tmp_if_cond_15;
                                
# 7014 "<previous_module>"
tmain_523: IF(0,523,tmain_524)__CSEQ_removeindent;
                                
# 7015 "<previous_module>"
__cs_local_lfds711_stack_push___cs_tmp_if_cond_15 = !(__cs_param_lfds711_stack_push_se != 0);
                                
# 7016 "<previous_module>"
if (__cs_local_lfds711_stack_push___cs_tmp_if_cond_15)

# 7017 "<previous_module>"
                                {
                                        
# 7018 "<previous_module>"
static char *__cs_local_lfds711_stack_push_c;
                                        
# 7019 "<previous_module>"
tmain_524: IF(0,524,tmain_525)__CSEQ_removeindent;
                                        
# 7020 "<previous_module>"
__cs_local_lfds711_stack_push_c = 0;
                                        
# 7021 "<previous_module>"
tmain_525: IF(0,525,tmain_526)__CSEQ_removeindent;
                                        
# 7022 "<previous_module>"
*__cs_local_lfds711_stack_push_c = 0;
                                }

                                
# 7024 "<previous_module>"
__CPROVER_assume(__cs_pc_cs[0] >= 526);
                                ;
                                
# 7025 "<previous_module>"
;
                                ;
                                
# 7026 "<previous_module>"
;
                                ;
                                
# 7027 "<previous_module>"
tmain_526: IF(0,526,tmain_527)__CSEQ_removeindent;
                                
# 7028 "<previous_module>"
__cs_local_lfds711_stack_push_new_top[0] = __cs_param_lfds711_stack_push_se;
                                
# 7029 "<previous_module>"
tmain_527: IF(0,527,tmain_528)__CSEQ_removeindent;
                                
# 7030 "<previous_module>"
__cs_local_lfds711_stack_push_original_top[1] = (*__cs_param_lfds711_stack_push_ss).top[1];
                                
# 7031 "<previous_module>"
tmain_528: IF(0,528,tmain_529)__CSEQ_removeindent;
                                
# 7032 "<previous_module>"
__cs_local_lfds711_stack_push_original_top[0] = (*__cs_param_lfds711_stack_push_ss).top[0];
                                
# 7033 "<previous_module>"
__cs_local_lfds711_stack_push_result = 0;
                                
# 7034 "<previous_module>"
static int __cs_local_lfds711_stack_push_i;
                                
# 7035 "<previous_module>"
__cs_local_lfds711_stack_push_i = 0;
                                
# 7036 "<previous_module>"
if (!(__cs_local_lfds711_stack_push_result == 0))

# 7037 "<previous_module>"
                                {
                                        
# 7038 "<previous_module>"
goto __exit_loop_91;
                                        ;
                                }

                                
# 7040 "<previous_module>"
;

# 7041 "<previous_module>"
                                {
                                        
# 7042 "<previous_module>"
tmain_529: IF(0,529,tmain_530)__CSEQ_removeindent;
                                        
# 7043 "<previous_module>"
__cs_mutex_lock(&library_lock, 0);
                                        
# 7044 "<previous_module>"
tmain_530: IF(0,530,tmain_531)__CSEQ_removeindent;
                                        
# 7045 "<previous_module>"
(*__cs_param_lfds711_stack_push_se).next = __cs_local_lfds711_stack_push_original_top[0];
                                        
# 7046 "<previous_module>"
tmain_531: IF(0,531,tmain_532)__CSEQ_removeindent;
                                        
# 7047 "<previous_module>"
__cs_mutex_unlock(&library_lock, 0);
                                        
# 7048 "<previous_module>"
tmain_532: IF(0,532,tmain_533)__CSEQ_removeindent;
                                        
# 7049 "<previous_module>"
__cs_local_lfds711_stack_push_new_top[1] = __cs_local_lfds711_stack_push_original_top[1] + 1;
                                        
# 7050 "<previous_module>"
tmain_533: IF(0,533,tmain_534)__CSEQ_removeindent;
                                        
# 7051 "<previous_module>"
__cs_mutex_lock(&library_lock, 0);
                                        
# 7052 "<previous_module>"
tmain_534: IF(0,534,tmain_535)__CSEQ_removeindent;
                                        
# 7053 "<previous_module>"
__cs_local_lfds711_stack_push_result = __CSEQ_atomic_swap_stack_top(&(*__cs_param_lfds711_stack_push_ss).top[0], &__cs_local_lfds711_stack_push_original_top[0], &__cs_local_lfds711_stack_push_new_top[0]);
                                        
# 7054 "<previous_module>"
tmain_535: IF(0,535,tmain_536)__CSEQ_removeindent;
                                        
# 7055 "<previous_module>"
__cs_mutex_unlock(&library_lock, 0);
                                        
# 7056 "<previous_module>"
;
                                        ;
                                        
# 7057 "<previous_module>"
static _Bool __cs_local_lfds711_stack_push___cs_tmp_if_cond_16;
                                        
# 7058 "<previous_module>"
__cs_local_lfds711_stack_push___cs_tmp_if_cond_16 = __cs_local_lfds711_stack_push_result == 0;
                                        
# 7059 "<previous_module>"
if (__cs_local_lfds711_stack_push___cs_tmp_if_cond_16)

# 7060 "<previous_module>"
                                        {

# 7061 "<previous_module>"
                                                {
                                                        
# 7062 "<previous_module>"
static int __cs_local_exponential_backoff_loop;
                                                        
# 7063 "<previous_module>"
__cs_local_exponential_backoff_loop = 0;

# 7064 "<previous_module>"
                                                        {
                                                                
# 7065 "<previous_module>"
;
                                                                ;
                                                        }
                                                        
# 7067 "<previous_module>"
;
                                                        
# 7068 "<previous_module>"
__cs_local_exponential_backoff_loop++;

# 7069 "<previous_module>"
                                                        {
                                                                
# 7070 "<previous_module>"
;
                                                                ;
                                                        }
                                                        
# 7072 "<previous_module>"
;
                                                        
# 7073 "<previous_module>"
__cs_local_exponential_backoff_loop++;

# 7074 "<previous_module>"
                                                        {
                                                                
# 7075 "<previous_module>"
;
                                                                ;
                                                        }
                                                        
# 7077 "<previous_module>"
;
                                                        
# 7078 "<previous_module>"
__cs_local_exponential_backoff_loop++;
                                                        
# 7079 "<previous_module>"
tmain_536: IF(0,536,tmain_537)__CSEQ_removeindent;
                                                        
# 7080 "<previous_module>"
__CPROVER_assume(!(__cs_local_exponential_backoff_loop < 3));
                                                        
# 7081 "<previous_module>"
__exit_loop_92:
                                                        __CPROVER_assume(__cs_pc_cs[0] >= 537);

                                                        
# 7082 "<previous_module>"
;
                                                        ;
                                                        
# 7083 "<previous_module>"
__exit__exponential_backoff_6_15:
                                                        __CPROVER_assume(__cs_pc_cs[0] >= 537);

                                                        
# 7084 "<previous_module>"
;
                                                        ;
                                                }
                                                
# 7086 "<previous_module>"
;
                                        }

                                        
# 7088 "<previous_module>"
__CPROVER_assume(__cs_pc_cs[0] >= 537);
                                        ;
                                        
# 7089 "<previous_module>"
__cs_local_lfds711_stack_push_i++;
                                        
# 7090 "<previous_module>"
;
                                        ;
                                        
# 7091 "<previous_module>"
static _Bool __cs_local_lfds711_stack_push___cs_tmp_if_cond_17;
                                        
# 7092 "<previous_module>"
__cs_local_lfds711_stack_push___cs_tmp_if_cond_17 = __cs_local_lfds711_stack_push_i > 1000;
                                        
# 7093 "<previous_module>"
if (__cs_local_lfds711_stack_push___cs_tmp_if_cond_17)

# 7094 "<previous_module>"
                                        {
                                                
# 7095 "<previous_module>"
goto __exit_loop_91;
                                                ;
                                        }

                                        
# 7097 "<previous_module>"
;
                                }
                                
# 7099 "<previous_module>"
;
                                
# 7100 "<previous_module>"
if (!(__cs_local_lfds711_stack_push_result == 0))

# 7101 "<previous_module>"
                                {
                                        
# 7102 "<previous_module>"
goto __exit_loop_91;
                                        ;
                                }

                                
# 7104 "<previous_module>"
;

# 7105 "<previous_module>"
                                {
                                        
# 7106 "<previous_module>"
tmain_537: IF(0,537,tmain_538)__CSEQ_removeindent;
                                        
# 7107 "<previous_module>"
__cs_mutex_lock(&library_lock, 0);
                                        
# 7108 "<previous_module>"
tmain_538: IF(0,538,tmain_539)__CSEQ_removeindent;
                                        
# 7109 "<previous_module>"
(*__cs_param_lfds711_stack_push_se).next = __cs_local_lfds711_stack_push_original_top[0];
                                        
# 7110 "<previous_module>"
tmain_539: IF(0,539,tmain_540)__CSEQ_removeindent;
                                        
# 7111 "<previous_module>"
__cs_mutex_unlock(&library_lock, 0);
                                        
# 7112 "<previous_module>"
tmain_540: IF(0,540,tmain_541)__CSEQ_removeindent;
                                        
# 7113 "<previous_module>"
__cs_local_lfds711_stack_push_new_top[1] = __cs_local_lfds711_stack_push_original_top[1] + 1;
                                        
# 7114 "<previous_module>"
tmain_541: IF(0,541,tmain_542)__CSEQ_removeindent;
                                        
# 7115 "<previous_module>"
__cs_mutex_lock(&library_lock, 0);
                                        
# 7116 "<previous_module>"
tmain_542: IF(0,542,tmain_543)__CSEQ_removeindent;
                                        
# 7117 "<previous_module>"
__cs_local_lfds711_stack_push_result = __CSEQ_atomic_swap_stack_top(&(*__cs_param_lfds711_stack_push_ss).top[0], &__cs_local_lfds711_stack_push_original_top[0], &__cs_local_lfds711_stack_push_new_top[0]);
                                        
# 7118 "<previous_module>"
tmain_543: IF(0,543,tmain_544)__CSEQ_removeindent;
                                        
# 7119 "<previous_module>"
__cs_mutex_unlock(&library_lock, 0);
                                        
# 7120 "<previous_module>"
;
                                        ;
                                        
# 7121 "<previous_module>"
static _Bool __cs_local_lfds711_stack_push___cs_tmp_if_cond_16;
                                        
# 7122 "<previous_module>"
__cs_local_lfds711_stack_push___cs_tmp_if_cond_16 = __cs_local_lfds711_stack_push_result == 0;
                                        
# 7123 "<previous_module>"
if (__cs_local_lfds711_stack_push___cs_tmp_if_cond_16)

# 7124 "<previous_module>"
                                        {

# 7125 "<previous_module>"
                                                {
                                                        
# 7126 "<previous_module>"
static int __cs_local_exponential_backoff_loop;
                                                        
# 7127 "<previous_module>"
__cs_local_exponential_backoff_loop = 0;

# 7128 "<previous_module>"
                                                        {
                                                                
# 7129 "<previous_module>"
;
                                                                ;
                                                        }
                                                        
# 7131 "<previous_module>"
;
                                                        
# 7132 "<previous_module>"
__cs_local_exponential_backoff_loop++;

# 7133 "<previous_module>"
                                                        {
                                                                
# 7134 "<previous_module>"
;
                                                                ;
                                                        }
                                                        
# 7136 "<previous_module>"
;
                                                        
# 7137 "<previous_module>"
__cs_local_exponential_backoff_loop++;

# 7138 "<previous_module>"
                                                        {
                                                                
# 7139 "<previous_module>"
;
                                                                ;
                                                        }
                                                        
# 7141 "<previous_module>"
;
                                                        
# 7142 "<previous_module>"
__cs_local_exponential_backoff_loop++;
                                                        
# 7143 "<previous_module>"
tmain_544: IF(0,544,tmain_545)__CSEQ_removeindent;
                                                        
# 7144 "<previous_module>"
__CPROVER_assume(!(__cs_local_exponential_backoff_loop < 3));
                                                        
# 7145 "<previous_module>"
__exit_loop_93:
                                                        __CPROVER_assume(__cs_pc_cs[0] >= 545);

                                                        
# 7146 "<previous_module>"
;
                                                        ;
                                                        
# 7147 "<previous_module>"
__exit__exponential_backoff_6_16:
                                                        __CPROVER_assume(__cs_pc_cs[0] >= 545);

                                                        
# 7148 "<previous_module>"
;
                                                        ;
                                                }
                                                
# 7150 "<previous_module>"
;
                                        }

                                        
# 7152 "<previous_module>"
__CPROVER_assume(__cs_pc_cs[0] >= 545);
                                        ;
                                        
# 7153 "<previous_module>"
__cs_local_lfds711_stack_push_i++;
                                        
# 7154 "<previous_module>"
;
                                        ;
                                        
# 7155 "<previous_module>"
static _Bool __cs_local_lfds711_stack_push___cs_tmp_if_cond_17;
                                        
# 7156 "<previous_module>"
__cs_local_lfds711_stack_push___cs_tmp_if_cond_17 = __cs_local_lfds711_stack_push_i > 1000;
                                        
# 7157 "<previous_module>"
if (__cs_local_lfds711_stack_push___cs_tmp_if_cond_17)

# 7158 "<previous_module>"
                                        {
                                                
# 7159 "<previous_module>"
goto __exit_loop_91;
                                                ;
                                        }

                                        
# 7161 "<previous_module>"
;
                                }
                                
# 7163 "<previous_module>"
;
                                
# 7164 "<previous_module>"
if (!(__cs_local_lfds711_stack_push_result == 0))

# 7165 "<previous_module>"
                                {
                                        
# 7166 "<previous_module>"
goto __exit_loop_91;
                                        ;
                                }

                                
# 7168 "<previous_module>"
;

# 7169 "<previous_module>"
                                {
                                        
# 7170 "<previous_module>"
tmain_545: IF(0,545,tmain_546)__CSEQ_removeindent;
                                        
# 7171 "<previous_module>"
__cs_mutex_lock(&library_lock, 0);
                                        
# 7172 "<previous_module>"
tmain_546: IF(0,546,tmain_547)__CSEQ_removeindent;
                                        
# 7173 "<previous_module>"
(*__cs_param_lfds711_stack_push_se).next = __cs_local_lfds711_stack_push_original_top[0];
                                        
# 7174 "<previous_module>"
tmain_547: IF(0,547,tmain_548)__CSEQ_removeindent;
                                        
# 7175 "<previous_module>"
__cs_mutex_unlock(&library_lock, 0);
                                        
# 7176 "<previous_module>"
tmain_548: IF(0,548,tmain_549)__CSEQ_removeindent;
                                        
# 7177 "<previous_module>"
__cs_local_lfds711_stack_push_new_top[1] = __cs_local_lfds711_stack_push_original_top[1] + 1;
                                        
# 7178 "<previous_module>"
tmain_549: IF(0,549,tmain_550)__CSEQ_removeindent;
                                        
# 7179 "<previous_module>"
__cs_mutex_lock(&library_lock, 0);
                                        
# 7180 "<previous_module>"
tmain_550: IF(0,550,tmain_551)__CSEQ_removeindent;
                                        
# 7181 "<previous_module>"
__cs_local_lfds711_stack_push_result = __CSEQ_atomic_swap_stack_top(&(*__cs_param_lfds711_stack_push_ss).top[0], &__cs_local_lfds711_stack_push_original_top[0], &__cs_local_lfds711_stack_push_new_top[0]);
                                        
# 7182 "<previous_module>"
tmain_551: IF(0,551,tmain_552)__CSEQ_removeindent;
                                        
# 7183 "<previous_module>"
__cs_mutex_unlock(&library_lock, 0);
                                        
# 7184 "<previous_module>"
;
                                        ;
                                        
# 7185 "<previous_module>"
static _Bool __cs_local_lfds711_stack_push___cs_tmp_if_cond_16;
                                        
# 7186 "<previous_module>"
__cs_local_lfds711_stack_push___cs_tmp_if_cond_16 = __cs_local_lfds711_stack_push_result == 0;
                                        
# 7187 "<previous_module>"
if (__cs_local_lfds711_stack_push___cs_tmp_if_cond_16)

# 7188 "<previous_module>"
                                        {

# 7189 "<previous_module>"
                                                {
                                                        
# 7190 "<previous_module>"
static int __cs_local_exponential_backoff_loop;
                                                        
# 7191 "<previous_module>"
__cs_local_exponential_backoff_loop = 0;

# 7192 "<previous_module>"
                                                        {
                                                                
# 7193 "<previous_module>"
;
                                                                ;
                                                        }
                                                        
# 7195 "<previous_module>"
;
                                                        
# 7196 "<previous_module>"
__cs_local_exponential_backoff_loop++;

# 7197 "<previous_module>"
                                                        {
                                                                
# 7198 "<previous_module>"
;
                                                                ;
                                                        }
                                                        
# 7200 "<previous_module>"
;
                                                        
# 7201 "<previous_module>"
__cs_local_exponential_backoff_loop++;

# 7202 "<previous_module>"
                                                        {
                                                                
# 7203 "<previous_module>"
;
                                                                ;
                                                        }
                                                        
# 7205 "<previous_module>"
;
                                                        
# 7206 "<previous_module>"
__cs_local_exponential_backoff_loop++;
                                                        
# 7207 "<previous_module>"
tmain_552: IF(0,552,tmain_553)__CSEQ_removeindent;
                                                        
# 7208 "<previous_module>"
__CPROVER_assume(!(__cs_local_exponential_backoff_loop < 3));
                                                        
# 7209 "<previous_module>"
__exit_loop_94:
                                                        __CPROVER_assume(__cs_pc_cs[0] >= 553);

                                                        
# 7210 "<previous_module>"
;
                                                        ;
                                                        
# 7211 "<previous_module>"
__exit__exponential_backoff_6_17:
                                                        __CPROVER_assume(__cs_pc_cs[0] >= 553);

                                                        
# 7212 "<previous_module>"
;
                                                        ;
                                                }
                                                
# 7214 "<previous_module>"
;
                                        }

                                        
# 7216 "<previous_module>"
__CPROVER_assume(__cs_pc_cs[0] >= 553);
                                        ;
                                        
# 7217 "<previous_module>"
__cs_local_lfds711_stack_push_i++;
                                        
# 7218 "<previous_module>"
;
                                        ;
                                        
# 7219 "<previous_module>"
static _Bool __cs_local_lfds711_stack_push___cs_tmp_if_cond_17;
                                        
# 7220 "<previous_module>"
__cs_local_lfds711_stack_push___cs_tmp_if_cond_17 = __cs_local_lfds711_stack_push_i > 1000;
                                        
# 7221 "<previous_module>"
if (__cs_local_lfds711_stack_push___cs_tmp_if_cond_17)

# 7222 "<previous_module>"
                                        {
                                                
# 7223 "<previous_module>"
goto __exit_loop_91;
                                                ;
                                        }

                                        
# 7225 "<previous_module>"
;
                                }
                                
# 7227 "<previous_module>"
;
                                
# 7228 "<previous_module>"
if (!(__cs_local_lfds711_stack_push_result == 0))

# 7229 "<previous_module>"
                                {
                                        
# 7230 "<previous_module>"
goto __exit_loop_91;
                                        ;
                                }

                                
# 7232 "<previous_module>"
;

# 7233 "<previous_module>"
                                {
                                        
# 7234 "<previous_module>"
tmain_553: IF(0,553,tmain_554)__CSEQ_removeindent;
                                        
# 7235 "<previous_module>"
__cs_mutex_lock(&library_lock, 0);
                                        
# 7236 "<previous_module>"
tmain_554: IF(0,554,tmain_555)__CSEQ_removeindent;
                                        
# 7237 "<previous_module>"
(*__cs_param_lfds711_stack_push_se).next = __cs_local_lfds711_stack_push_original_top[0];
                                        
# 7238 "<previous_module>"
tmain_555: IF(0,555,tmain_556)__CSEQ_removeindent;
                                        
# 7239 "<previous_module>"
__cs_mutex_unlock(&library_lock, 0);
                                        
# 7240 "<previous_module>"
tmain_556: IF(0,556,tmain_557)__CSEQ_removeindent;
                                        
# 7241 "<previous_module>"
__cs_local_lfds711_stack_push_new_top[1] = __cs_local_lfds711_stack_push_original_top[1] + 1;
                                        
# 7242 "<previous_module>"
tmain_557: IF(0,557,tmain_558)__CSEQ_removeindent;
                                        
# 7243 "<previous_module>"
__cs_mutex_lock(&library_lock, 0);
                                        
# 7244 "<previous_module>"
tmain_558: IF(0,558,tmain_559)__CSEQ_removeindent;
                                        
# 7245 "<previous_module>"
__cs_local_lfds711_stack_push_result = __CSEQ_atomic_swap_stack_top(&(*__cs_param_lfds711_stack_push_ss).top[0], &__cs_local_lfds711_stack_push_original_top[0], &__cs_local_lfds711_stack_push_new_top[0]);
                                        
# 7246 "<previous_module>"
tmain_559: IF(0,559,tmain_560)__CSEQ_removeindent;
                                        
# 7247 "<previous_module>"
__cs_mutex_unlock(&library_lock, 0);
                                        
# 7248 "<previous_module>"
;
                                        ;
                                        
# 7249 "<previous_module>"
static _Bool __cs_local_lfds711_stack_push___cs_tmp_if_cond_16;
                                        
# 7250 "<previous_module>"
__cs_local_lfds711_stack_push___cs_tmp_if_cond_16 = __cs_local_lfds711_stack_push_result == 0;
                                        
# 7251 "<previous_module>"
if (__cs_local_lfds711_stack_push___cs_tmp_if_cond_16)

# 7252 "<previous_module>"
                                        {

# 7253 "<previous_module>"
                                                {
                                                        
# 7254 "<previous_module>"
static int __cs_local_exponential_backoff_loop;
                                                        
# 7255 "<previous_module>"
__cs_local_exponential_backoff_loop = 0;

# 7256 "<previous_module>"
                                                        {
                                                                
# 7257 "<previous_module>"
;
                                                                ;
                                                        }
                                                        
# 7259 "<previous_module>"
;
                                                        
# 7260 "<previous_module>"
__cs_local_exponential_backoff_loop++;

# 7261 "<previous_module>"
                                                        {
                                                                
# 7262 "<previous_module>"
;
                                                                ;
                                                        }
                                                        
# 7264 "<previous_module>"
;
                                                        
# 7265 "<previous_module>"
__cs_local_exponential_backoff_loop++;

# 7266 "<previous_module>"
                                                        {
                                                                
# 7267 "<previous_module>"
;
                                                                ;
                                                        }
                                                        
# 7269 "<previous_module>"
;
                                                        
# 7270 "<previous_module>"
__cs_local_exponential_backoff_loop++;
                                                        
# 7271 "<previous_module>"
tmain_560: IF(0,560,tmain_561)__CSEQ_removeindent;
                                                        
# 7272 "<previous_module>"
__CPROVER_assume(!(__cs_local_exponential_backoff_loop < 3));
                                                        
# 7273 "<previous_module>"
__exit_loop_95:
                                                        __CPROVER_assume(__cs_pc_cs[0] >= 561);

                                                        
# 7274 "<previous_module>"
;
                                                        ;
                                                        
# 7275 "<previous_module>"
__exit__exponential_backoff_6_18:
                                                        __CPROVER_assume(__cs_pc_cs[0] >= 561);

                                                        
# 7276 "<previous_module>"
;
                                                        ;
                                                }
                                                
# 7278 "<previous_module>"
;
                                        }

                                        
# 7280 "<previous_module>"
__CPROVER_assume(__cs_pc_cs[0] >= 561);
                                        ;
                                        
# 7281 "<previous_module>"
__cs_local_lfds711_stack_push_i++;
                                        
# 7282 "<previous_module>"
;
                                        ;
                                        
# 7283 "<previous_module>"
static _Bool __cs_local_lfds711_stack_push___cs_tmp_if_cond_17;
                                        
# 7284 "<previous_module>"
__cs_local_lfds711_stack_push___cs_tmp_if_cond_17 = __cs_local_lfds711_stack_push_i > 1000;
                                        
# 7285 "<previous_module>"
if (__cs_local_lfds711_stack_push___cs_tmp_if_cond_17)

# 7286 "<previous_module>"
                                        {
                                                
# 7287 "<previous_module>"
goto __exit_loop_91;
                                                ;
                                        }

                                        
# 7289 "<previous_module>"
;
                                }
                                
# 7291 "<previous_module>"
;
                                
# 7292 "<previous_module>"
if (!(__cs_local_lfds711_stack_push_result == 0))

# 7293 "<previous_module>"
                                {
                                        
# 7294 "<previous_module>"
goto __exit_loop_91;
                                        ;
                                }

                                
# 7296 "<previous_module>"
;

# 7297 "<previous_module>"
                                {
                                        
# 7298 "<previous_module>"
tmain_561: IF(0,561,tmain_562)__CSEQ_removeindent;
                                        
# 7299 "<previous_module>"
__cs_mutex_lock(&library_lock, 0);
                                        
# 7300 "<previous_module>"
tmain_562: IF(0,562,tmain_563)__CSEQ_removeindent;
                                        
# 7301 "<previous_module>"
(*__cs_param_lfds711_stack_push_se).next = __cs_local_lfds711_stack_push_original_top[0];
                                        
# 7302 "<previous_module>"
tmain_563: IF(0,563,tmain_564)__CSEQ_removeindent;
                                        
# 7303 "<previous_module>"
__cs_mutex_unlock(&library_lock, 0);
                                        
# 7304 "<previous_module>"
tmain_564: IF(0,564,tmain_565)__CSEQ_removeindent;
                                        
# 7305 "<previous_module>"
__cs_local_lfds711_stack_push_new_top[1] = __cs_local_lfds711_stack_push_original_top[1] + 1;
                                        
# 7306 "<previous_module>"
tmain_565: IF(0,565,tmain_566)__CSEQ_removeindent;
                                        
# 7307 "<previous_module>"
__cs_mutex_lock(&library_lock, 0);
                                        
# 7308 "<previous_module>"
tmain_566: IF(0,566,tmain_567)__CSEQ_removeindent;
                                        
# 7309 "<previous_module>"
__cs_local_lfds711_stack_push_result = __CSEQ_atomic_swap_stack_top(&(*__cs_param_lfds711_stack_push_ss).top[0], &__cs_local_lfds711_stack_push_original_top[0], &__cs_local_lfds711_stack_push_new_top[0]);
                                        
# 7310 "<previous_module>"
tmain_567: IF(0,567,tmain_568)__CSEQ_removeindent;
                                        
# 7311 "<previous_module>"
__cs_mutex_unlock(&library_lock, 0);
                                        
# 7312 "<previous_module>"
;
                                        ;
                                        
# 7313 "<previous_module>"
static _Bool __cs_local_lfds711_stack_push___cs_tmp_if_cond_16;
                                        
# 7314 "<previous_module>"
__cs_local_lfds711_stack_push___cs_tmp_if_cond_16 = __cs_local_lfds711_stack_push_result == 0;
                                        
# 7315 "<previous_module>"
if (__cs_local_lfds711_stack_push___cs_tmp_if_cond_16)

# 7316 "<previous_module>"
                                        {

# 7317 "<previous_module>"
                                                {
                                                        
# 7318 "<previous_module>"
static int __cs_local_exponential_backoff_loop;
                                                        
# 7319 "<previous_module>"
__cs_local_exponential_backoff_loop = 0;

# 7320 "<previous_module>"
                                                        {
                                                                
# 7321 "<previous_module>"
;
                                                                ;
                                                        }
                                                        
# 7323 "<previous_module>"
;
                                                        
# 7324 "<previous_module>"
__cs_local_exponential_backoff_loop++;

# 7325 "<previous_module>"
                                                        {
                                                                
# 7326 "<previous_module>"
;
                                                                ;
                                                        }
                                                        
# 7328 "<previous_module>"
;
                                                        
# 7329 "<previous_module>"
__cs_local_exponential_backoff_loop++;

# 7330 "<previous_module>"
                                                        {
                                                                
# 7331 "<previous_module>"
;
                                                                ;
                                                        }
                                                        
# 7333 "<previous_module>"
;
                                                        
# 7334 "<previous_module>"
__cs_local_exponential_backoff_loop++;
                                                        
# 7335 "<previous_module>"
tmain_568: IF(0,568,tmain_569)__CSEQ_removeindent;
                                                        
# 7336 "<previous_module>"
__CPROVER_assume(!(__cs_local_exponential_backoff_loop < 3));
                                                        
# 7337 "<previous_module>"
__exit_loop_96:
                                                        __CPROVER_assume(__cs_pc_cs[0] >= 569);

                                                        
# 7338 "<previous_module>"
;
                                                        ;
                                                        
# 7339 "<previous_module>"
__exit__exponential_backoff_6_19:
                                                        __CPROVER_assume(__cs_pc_cs[0] >= 569);

                                                        
# 7340 "<previous_module>"
;
                                                        ;
                                                }
                                                
# 7342 "<previous_module>"
;
                                        }

                                        
# 7344 "<previous_module>"
__CPROVER_assume(__cs_pc_cs[0] >= 569);
                                        ;
                                        
# 7345 "<previous_module>"
__cs_local_lfds711_stack_push_i++;
                                        
# 7346 "<previous_module>"
;
                                        ;
                                        
# 7347 "<previous_module>"
static _Bool __cs_local_lfds711_stack_push___cs_tmp_if_cond_17;
                                        
# 7348 "<previous_module>"
__cs_local_lfds711_stack_push___cs_tmp_if_cond_17 = __cs_local_lfds711_stack_push_i > 1000;
                                        
# 7349 "<previous_module>"
if (__cs_local_lfds711_stack_push___cs_tmp_if_cond_17)

# 7350 "<previous_module>"
                                        {
                                                
# 7351 "<previous_module>"
goto __exit_loop_91;
                                                ;
                                        }

                                        
# 7353 "<previous_module>"
;
                                }
                                
# 7355 "<previous_module>"
;
                                
# 7356 "<previous_module>"
tmain_569: IF(0,569,tmain_570)__CSEQ_removeindent;
                                
# 7357 "<previous_module>"
__CPROVER_assume(!(__cs_local_lfds711_stack_push_result == 0));
                                
# 7358 "<previous_module>"
__exit_loop_91:
                                __CPROVER_assume(__cs_pc_cs[0] >= 570);

                                
# 7359 "<previous_module>"
;
                                ;
                                
# 7360 "<previous_module>"
goto __exit__lfds711_stack_push_2_3;
                                ;
                                
# 7361 "<previous_module>"
__exit__lfds711_stack_push_2_3:
                                __CPROVER_assume(__cs_pc_cs[0] >= 570);

                                
# 7362 "<previous_module>"
;
                                ;
                        }
                        
# 7364 "<previous_module>"
;
                        
# 7365 "<previous_module>"
__cs_local_contains_i++;
                }
                
# 7367 "<previous_module>"
;
                
# 7368 "<previous_module>"
if (!(__cs_local_contains_i < __cs_local_contains_actual_size))

# 7369 "<previous_module>"
                {
                        
# 7370 "<previous_module>"
goto __exit_loop_72;
                        ;
                }

                
# 7372 "<previous_module>"
;

# 7373 "<previous_module>"
                {

# 7374 "<previous_module>"
                        {
                                
# 7375 "<previous_module>"
static struct lfds711_stack_state *__cs_param_lfds711_stack_push_ss;
                                
# 7376 "<previous_module>"
tmain_570: IF(0,570,tmain_571)__CSEQ_removeindent;
                                
# 7377 "<previous_module>"
__cs_param_lfds711_stack_push_ss = __cs_param_contains_s;
                                
# 7378 "<previous_module>"
static struct lfds711_stack_element *__cs_param_lfds711_stack_push_se;
                                
# 7379 "<previous_module>"
tmain_571: IF(0,571,tmain_572)__CSEQ_removeindent;
                                
# 7380 "<previous_module>"
__cs_param_lfds711_stack_push_se = &(*__cs_local_contains_datas[__cs_local_contains_i]).se;
                                
# 7381 "<previous_module>"
static char unsigned __cs_local_lfds711_stack_push_result;
                                
# 7382 "<previous_module>"
static lfds711_pal_uint_t __cs_local_lfds711_stack_push_backoff_iteration;
                                
# 7383 "<previous_module>"
__cs_local_lfds711_stack_push_backoff_iteration = 0;
                                
# 7384 "<previous_module>"
static struct lfds711_stack_element *__cs_local_lfds711_stack_push_new_top[2];
                                
# 7385 "<previous_module>"
static struct lfds711_stack_element * volatile __cs_local_lfds711_stack_push_original_top[2];
                                
# 7386 "<previous_module>"
;
                                ;
                                
# 7387 "<previous_module>"
static _Bool __cs_local_lfds711_stack_push___cs_tmp_if_cond_14;
                                
# 7388 "<previous_module>"
tmain_572: IF(0,572,tmain_573)__CSEQ_removeindent;
                                
# 7389 "<previous_module>"
__cs_local_lfds711_stack_push___cs_tmp_if_cond_14 = !(__cs_param_lfds711_stack_push_ss != 0);
                                
# 7390 "<previous_module>"
if (__cs_local_lfds711_stack_push___cs_tmp_if_cond_14)

# 7391 "<previous_module>"
                                {
                                        
# 7392 "<previous_module>"
static char *__cs_local_lfds711_stack_push_c;
                                        
# 7393 "<previous_module>"
tmain_573: IF(0,573,tmain_574)__CSEQ_removeindent;
                                        
# 7394 "<previous_module>"
__cs_local_lfds711_stack_push_c = 0;
                                        
# 7395 "<previous_module>"
tmain_574: IF(0,574,tmain_575)__CSEQ_removeindent;
                                        
# 7396 "<previous_module>"
*__cs_local_lfds711_stack_push_c = 0;
                                }

                                
# 7398 "<previous_module>"
__CPROVER_assume(__cs_pc_cs[0] >= 575);
                                ;
                                
# 7399 "<previous_module>"
;
                                ;
                                
# 7400 "<previous_module>"
;
                                ;
                                
# 7401 "<previous_module>"
;
                                ;
                                
# 7402 "<previous_module>"
static _Bool __cs_local_lfds711_stack_push___cs_tmp_if_cond_15;
                                
# 7403 "<previous_module>"
tmain_575: IF(0,575,tmain_576)__CSEQ_removeindent;
                                
# 7404 "<previous_module>"
__cs_local_lfds711_stack_push___cs_tmp_if_cond_15 = !(__cs_param_lfds711_stack_push_se != 0);
                                
# 7405 "<previous_module>"
if (__cs_local_lfds711_stack_push___cs_tmp_if_cond_15)

# 7406 "<previous_module>"
                                {
                                        
# 7407 "<previous_module>"
static char *__cs_local_lfds711_stack_push_c;
                                        
# 7408 "<previous_module>"
tmain_576: IF(0,576,tmain_577)__CSEQ_removeindent;
                                        
# 7409 "<previous_module>"
__cs_local_lfds711_stack_push_c = 0;
                                        
# 7410 "<previous_module>"
tmain_577: IF(0,577,tmain_578)__CSEQ_removeindent;
                                        
# 7411 "<previous_module>"
*__cs_local_lfds711_stack_push_c = 0;
                                }

                                
# 7413 "<previous_module>"
__CPROVER_assume(__cs_pc_cs[0] >= 578);
                                ;
                                
# 7414 "<previous_module>"
;
                                ;
                                
# 7415 "<previous_module>"
;
                                ;
                                
# 7416 "<previous_module>"
tmain_578: IF(0,578,tmain_579)__CSEQ_removeindent;
                                
# 7417 "<previous_module>"
__cs_local_lfds711_stack_push_new_top[0] = __cs_param_lfds711_stack_push_se;
                                
# 7418 "<previous_module>"
tmain_579: IF(0,579,tmain_580)__CSEQ_removeindent;
                                
# 7419 "<previous_module>"
__cs_local_lfds711_stack_push_original_top[1] = (*__cs_param_lfds711_stack_push_ss).top[1];
                                
# 7420 "<previous_module>"
tmain_580: IF(0,580,tmain_581)__CSEQ_removeindent;
                                
# 7421 "<previous_module>"
__cs_local_lfds711_stack_push_original_top[0] = (*__cs_param_lfds711_stack_push_ss).top[0];
                                
# 7422 "<previous_module>"
__cs_local_lfds711_stack_push_result = 0;
                                
# 7423 "<previous_module>"
static int __cs_local_lfds711_stack_push_i;
                                
# 7424 "<previous_module>"
__cs_local_lfds711_stack_push_i = 0;
                                
# 7425 "<previous_module>"
if (!(__cs_local_lfds711_stack_push_result == 0))

# 7426 "<previous_module>"
                                {
                                        
# 7427 "<previous_module>"
goto __exit_loop_97;
                                        ;
                                }

                                
# 7429 "<previous_module>"
;

# 7430 "<previous_module>"
                                {
                                        
# 7431 "<previous_module>"
tmain_581: IF(0,581,tmain_582)__CSEQ_removeindent;
                                        
# 7432 "<previous_module>"
__cs_mutex_lock(&library_lock, 0);
                                        
# 7433 "<previous_module>"
tmain_582: IF(0,582,tmain_583)__CSEQ_removeindent;
                                        
# 7434 "<previous_module>"
(*__cs_param_lfds711_stack_push_se).next = __cs_local_lfds711_stack_push_original_top[0];
                                        
# 7435 "<previous_module>"
tmain_583: IF(0,583,tmain_584)__CSEQ_removeindent;
                                        
# 7436 "<previous_module>"
__cs_mutex_unlock(&library_lock, 0);
                                        
# 7437 "<previous_module>"
tmain_584: IF(0,584,tmain_585)__CSEQ_removeindent;
                                        
# 7438 "<previous_module>"
__cs_local_lfds711_stack_push_new_top[1] = __cs_local_lfds711_stack_push_original_top[1] + 1;
                                        
# 7439 "<previous_module>"
tmain_585: IF(0,585,tmain_586)__CSEQ_removeindent;
                                        
# 7440 "<previous_module>"
__cs_mutex_lock(&library_lock, 0);
                                        
# 7441 "<previous_module>"
tmain_586: IF(0,586,tmain_587)__CSEQ_removeindent;
                                        
# 7442 "<previous_module>"
__cs_local_lfds711_stack_push_result = __CSEQ_atomic_swap_stack_top(&(*__cs_param_lfds711_stack_push_ss).top[0], &__cs_local_lfds711_stack_push_original_top[0], &__cs_local_lfds711_stack_push_new_top[0]);
                                        
# 7443 "<previous_module>"
tmain_587: IF(0,587,tmain_588)__CSEQ_removeindent;
                                        
# 7444 "<previous_module>"
__cs_mutex_unlock(&library_lock, 0);
                                        
# 7445 "<previous_module>"
;
                                        ;
                                        
# 7446 "<previous_module>"
static _Bool __cs_local_lfds711_stack_push___cs_tmp_if_cond_16;
                                        
# 7447 "<previous_module>"
__cs_local_lfds711_stack_push___cs_tmp_if_cond_16 = __cs_local_lfds711_stack_push_result == 0;
                                        
# 7448 "<previous_module>"
if (__cs_local_lfds711_stack_push___cs_tmp_if_cond_16)

# 7449 "<previous_module>"
                                        {

# 7450 "<previous_module>"
                                                {
                                                        
# 7451 "<previous_module>"
static int __cs_local_exponential_backoff_loop;
                                                        
# 7452 "<previous_module>"
__cs_local_exponential_backoff_loop = 0;

# 7453 "<previous_module>"
                                                        {
                                                                
# 7454 "<previous_module>"
;
                                                                ;
                                                        }
                                                        
# 7456 "<previous_module>"
;
                                                        
# 7457 "<previous_module>"
__cs_local_exponential_backoff_loop++;

# 7458 "<previous_module>"
                                                        {
                                                                
# 7459 "<previous_module>"
;
                                                                ;
                                                        }
                                                        
# 7461 "<previous_module>"
;
                                                        
# 7462 "<previous_module>"
__cs_local_exponential_backoff_loop++;

# 7463 "<previous_module>"
                                                        {
                                                                
# 7464 "<previous_module>"
;
                                                                ;
                                                        }
                                                        
# 7466 "<previous_module>"
;
                                                        
# 7467 "<previous_module>"
__cs_local_exponential_backoff_loop++;
                                                        
# 7468 "<previous_module>"
tmain_588: IF(0,588,tmain_589)__CSEQ_removeindent;
                                                        
# 7469 "<previous_module>"
__CPROVER_assume(!(__cs_local_exponential_backoff_loop < 3));
                                                        
# 7470 "<previous_module>"
__exit_loop_98:
                                                        __CPROVER_assume(__cs_pc_cs[0] >= 589);

                                                        
# 7471 "<previous_module>"
;
                                                        ;
                                                        
# 7472 "<previous_module>"
__exit__exponential_backoff_6_20:
                                                        __CPROVER_assume(__cs_pc_cs[0] >= 589);

                                                        
# 7473 "<previous_module>"
;
                                                        ;
                                                }
                                                
# 7475 "<previous_module>"
;
                                        }

                                        
# 7477 "<previous_module>"
__CPROVER_assume(__cs_pc_cs[0] >= 589);
                                        ;
                                        
# 7478 "<previous_module>"
__cs_local_lfds711_stack_push_i++;
                                        
# 7479 "<previous_module>"
;
                                        ;
                                        
# 7480 "<previous_module>"
static _Bool __cs_local_lfds711_stack_push___cs_tmp_if_cond_17;
                                        
# 7481 "<previous_module>"
__cs_local_lfds711_stack_push___cs_tmp_if_cond_17 = __cs_local_lfds711_stack_push_i > 1000;
                                        
# 7482 "<previous_module>"
if (__cs_local_lfds711_stack_push___cs_tmp_if_cond_17)

# 7483 "<previous_module>"
                                        {
                                                
# 7484 "<previous_module>"
goto __exit_loop_97;
                                                ;
                                        }

                                        
# 7486 "<previous_module>"
;
                                }
                                
# 7488 "<previous_module>"
;
                                
# 7489 "<previous_module>"
if (!(__cs_local_lfds711_stack_push_result == 0))

# 7490 "<previous_module>"
                                {
                                        
# 7491 "<previous_module>"
goto __exit_loop_97;
                                        ;
                                }

                                
# 7493 "<previous_module>"
;

# 7494 "<previous_module>"
                                {
                                        
# 7495 "<previous_module>"
tmain_589: IF(0,589,tmain_590)__CSEQ_removeindent;
                                        
# 7496 "<previous_module>"
__cs_mutex_lock(&library_lock, 0);
                                        
# 7497 "<previous_module>"
tmain_590: IF(0,590,tmain_591)__CSEQ_removeindent;
                                        
# 7498 "<previous_module>"
(*__cs_param_lfds711_stack_push_se).next = __cs_local_lfds711_stack_push_original_top[0];
                                        
# 7499 "<previous_module>"
tmain_591: IF(0,591,tmain_592)__CSEQ_removeindent;
                                        
# 7500 "<previous_module>"
__cs_mutex_unlock(&library_lock, 0);
                                        
# 7501 "<previous_module>"
tmain_592: IF(0,592,tmain_593)__CSEQ_removeindent;
                                        
# 7502 "<previous_module>"
__cs_local_lfds711_stack_push_new_top[1] = __cs_local_lfds711_stack_push_original_top[1] + 1;
                                        
# 7503 "<previous_module>"
tmain_593: IF(0,593,tmain_594)__CSEQ_removeindent;
                                        
# 7504 "<previous_module>"
__cs_mutex_lock(&library_lock, 0);
                                        
# 7505 "<previous_module>"
tmain_594: IF(0,594,tmain_595)__CSEQ_removeindent;
                                        
# 7506 "<previous_module>"
__cs_local_lfds711_stack_push_result = __CSEQ_atomic_swap_stack_top(&(*__cs_param_lfds711_stack_push_ss).top[0], &__cs_local_lfds711_stack_push_original_top[0], &__cs_local_lfds711_stack_push_new_top[0]);
                                        
# 7507 "<previous_module>"
tmain_595: IF(0,595,tmain_596)__CSEQ_removeindent;
                                        
# 7508 "<previous_module>"
__cs_mutex_unlock(&library_lock, 0);
                                        
# 7509 "<previous_module>"
;
                                        ;
                                        
# 7510 "<previous_module>"
static _Bool __cs_local_lfds711_stack_push___cs_tmp_if_cond_16;
                                        
# 7511 "<previous_module>"
__cs_local_lfds711_stack_push___cs_tmp_if_cond_16 = __cs_local_lfds711_stack_push_result == 0;
                                        
# 7512 "<previous_module>"
if (__cs_local_lfds711_stack_push___cs_tmp_if_cond_16)

# 7513 "<previous_module>"
                                        {

# 7514 "<previous_module>"
                                                {
                                                        
# 7515 "<previous_module>"
static int __cs_local_exponential_backoff_loop;
                                                        
# 7516 "<previous_module>"
__cs_local_exponential_backoff_loop = 0;

# 7517 "<previous_module>"
                                                        {
                                                                
# 7518 "<previous_module>"
;
                                                                ;
                                                        }
                                                        
# 7520 "<previous_module>"
;
                                                        
# 7521 "<previous_module>"
__cs_local_exponential_backoff_loop++;

# 7522 "<previous_module>"
                                                        {
                                                                
# 7523 "<previous_module>"
;
                                                                ;
                                                        }
                                                        
# 7525 "<previous_module>"
;
                                                        
# 7526 "<previous_module>"
__cs_local_exponential_backoff_loop++;

# 7527 "<previous_module>"
                                                        {
                                                                
# 7528 "<previous_module>"
;
                                                                ;
                                                        }
                                                        
# 7530 "<previous_module>"
;
                                                        
# 7531 "<previous_module>"
__cs_local_exponential_backoff_loop++;
                                                        
# 7532 "<previous_module>"
tmain_596: IF(0,596,tmain_597)__CSEQ_removeindent;
                                                        
# 7533 "<previous_module>"
__CPROVER_assume(!(__cs_local_exponential_backoff_loop < 3));
                                                        
# 7534 "<previous_module>"
__exit_loop_99:
                                                        __CPROVER_assume(__cs_pc_cs[0] >= 597);

                                                        
# 7535 "<previous_module>"
;
                                                        ;
                                                        
# 7536 "<previous_module>"
__exit__exponential_backoff_6_21:
                                                        __CPROVER_assume(__cs_pc_cs[0] >= 597);

                                                        
# 7537 "<previous_module>"
;
                                                        ;
                                                }
                                                
# 7539 "<previous_module>"
;
                                        }

                                        
# 7541 "<previous_module>"
__CPROVER_assume(__cs_pc_cs[0] >= 597);
                                        ;
                                        
# 7542 "<previous_module>"
__cs_local_lfds711_stack_push_i++;
                                        
# 7543 "<previous_module>"
;
                                        ;
                                        
# 7544 "<previous_module>"
static _Bool __cs_local_lfds711_stack_push___cs_tmp_if_cond_17;
                                        
# 7545 "<previous_module>"
__cs_local_lfds711_stack_push___cs_tmp_if_cond_17 = __cs_local_lfds711_stack_push_i > 1000;
                                        
# 7546 "<previous_module>"
if (__cs_local_lfds711_stack_push___cs_tmp_if_cond_17)

# 7547 "<previous_module>"
                                        {
                                                
# 7548 "<previous_module>"
goto __exit_loop_97;
                                                ;
                                        }

                                        
# 7550 "<previous_module>"
;
                                }
                                
# 7552 "<previous_module>"
;
                                
# 7553 "<previous_module>"
if (!(__cs_local_lfds711_stack_push_result == 0))

# 7554 "<previous_module>"
                                {
                                        
# 7555 "<previous_module>"
goto __exit_loop_97;
                                        ;
                                }

                                
# 7557 "<previous_module>"
;

# 7558 "<previous_module>"
                                {
                                        
# 7559 "<previous_module>"
tmain_597: IF(0,597,tmain_598)__CSEQ_removeindent;
                                        
# 7560 "<previous_module>"
__cs_mutex_lock(&library_lock, 0);
                                        
# 7561 "<previous_module>"
tmain_598: IF(0,598,tmain_599)__CSEQ_removeindent;
                                        
# 7562 "<previous_module>"
(*__cs_param_lfds711_stack_push_se).next = __cs_local_lfds711_stack_push_original_top[0];
                                        
# 7563 "<previous_module>"
tmain_599: IF(0,599,tmain_600)__CSEQ_removeindent;
                                        
# 7564 "<previous_module>"
__cs_mutex_unlock(&library_lock, 0);
                                        
# 7565 "<previous_module>"
tmain_600: IF(0,600,tmain_601)__CSEQ_removeindent;
                                        
# 7566 "<previous_module>"
__cs_local_lfds711_stack_push_new_top[1] = __cs_local_lfds711_stack_push_original_top[1] + 1;
                                        
# 7567 "<previous_module>"
tmain_601: IF(0,601,tmain_602)__CSEQ_removeindent;
                                        
# 7568 "<previous_module>"
__cs_mutex_lock(&library_lock, 0);
                                        
# 7569 "<previous_module>"
tmain_602: IF(0,602,tmain_603)__CSEQ_removeindent;
                                        
# 7570 "<previous_module>"
__cs_local_lfds711_stack_push_result = __CSEQ_atomic_swap_stack_top(&(*__cs_param_lfds711_stack_push_ss).top[0], &__cs_local_lfds711_stack_push_original_top[0], &__cs_local_lfds711_stack_push_new_top[0]);
                                        
# 7571 "<previous_module>"
tmain_603: IF(0,603,tmain_604)__CSEQ_removeindent;
                                        
# 7572 "<previous_module>"
__cs_mutex_unlock(&library_lock, 0);
                                        
# 7573 "<previous_module>"
;
                                        ;
                                        
# 7574 "<previous_module>"
static _Bool __cs_local_lfds711_stack_push___cs_tmp_if_cond_16;
                                        
# 7575 "<previous_module>"
__cs_local_lfds711_stack_push___cs_tmp_if_cond_16 = __cs_local_lfds711_stack_push_result == 0;
                                        
# 7576 "<previous_module>"
if (__cs_local_lfds711_stack_push___cs_tmp_if_cond_16)

# 7577 "<previous_module>"
                                        {

# 7578 "<previous_module>"
                                                {
                                                        
# 7579 "<previous_module>"
static int __cs_local_exponential_backoff_loop;
                                                        
# 7580 "<previous_module>"
__cs_local_exponential_backoff_loop = 0;

# 7581 "<previous_module>"
                                                        {
                                                                
# 7582 "<previous_module>"
;
                                                                ;
                                                        }
                                                        
# 7584 "<previous_module>"
;
                                                        
# 7585 "<previous_module>"
__cs_local_exponential_backoff_loop++;

# 7586 "<previous_module>"
                                                        {
                                                                
# 7587 "<previous_module>"
;
                                                                ;
                                                        }
                                                        
# 7589 "<previous_module>"
;
                                                        
# 7590 "<previous_module>"
__cs_local_exponential_backoff_loop++;

# 7591 "<previous_module>"
                                                        {
                                                                
# 7592 "<previous_module>"
;
                                                                ;
                                                        }
                                                        
# 7594 "<previous_module>"
;
                                                        
# 7595 "<previous_module>"
__cs_local_exponential_backoff_loop++;
                                                        
# 7596 "<previous_module>"
tmain_604: IF(0,604,tmain_605)__CSEQ_removeindent;
                                                        
# 7597 "<previous_module>"
__CPROVER_assume(!(__cs_local_exponential_backoff_loop < 3));
                                                        
# 7598 "<previous_module>"
__exit_loop_100:
                                                        __CPROVER_assume(__cs_pc_cs[0] >= 605);

                                                        
# 7599 "<previous_module>"
;
                                                        ;
                                                        
# 7600 "<previous_module>"
__exit__exponential_backoff_6_22:
                                                        __CPROVER_assume(__cs_pc_cs[0] >= 605);

                                                        
# 7601 "<previous_module>"
;
                                                        ;
                                                }
                                                
# 7603 "<previous_module>"
;
                                        }

                                        
# 7605 "<previous_module>"
__CPROVER_assume(__cs_pc_cs[0] >= 605);
                                        ;
                                        
# 7606 "<previous_module>"
__cs_local_lfds711_stack_push_i++;
                                        
# 7607 "<previous_module>"
;
                                        ;
                                        
# 7608 "<previous_module>"
static _Bool __cs_local_lfds711_stack_push___cs_tmp_if_cond_17;
                                        
# 7609 "<previous_module>"
__cs_local_lfds711_stack_push___cs_tmp_if_cond_17 = __cs_local_lfds711_stack_push_i > 1000;
                                        
# 7610 "<previous_module>"
if (__cs_local_lfds711_stack_push___cs_tmp_if_cond_17)

# 7611 "<previous_module>"
                                        {
                                                
# 7612 "<previous_module>"
goto __exit_loop_97;
                                                ;
                                        }

                                        
# 7614 "<previous_module>"
;
                                }
                                
# 7616 "<previous_module>"
;
                                
# 7617 "<previous_module>"
if (!(__cs_local_lfds711_stack_push_result == 0))

# 7618 "<previous_module>"
                                {
                                        
# 7619 "<previous_module>"
goto __exit_loop_97;
                                        ;
                                }

                                
# 7621 "<previous_module>"
;

# 7622 "<previous_module>"
                                {
                                        
# 7623 "<previous_module>"
tmain_605: IF(0,605,tmain_606)__CSEQ_removeindent;
                                        
# 7624 "<previous_module>"
__cs_mutex_lock(&library_lock, 0);
                                        
# 7625 "<previous_module>"
tmain_606: IF(0,606,tmain_607)__CSEQ_removeindent;
                                        
# 7626 "<previous_module>"
(*__cs_param_lfds711_stack_push_se).next = __cs_local_lfds711_stack_push_original_top[0];
                                        
# 7627 "<previous_module>"
tmain_607: IF(0,607,tmain_608)__CSEQ_removeindent;
                                        
# 7628 "<previous_module>"
__cs_mutex_unlock(&library_lock, 0);
                                        
# 7629 "<previous_module>"
tmain_608: IF(0,608,tmain_609)__CSEQ_removeindent;
                                        
# 7630 "<previous_module>"
__cs_local_lfds711_stack_push_new_top[1] = __cs_local_lfds711_stack_push_original_top[1] + 1;
                                        
# 7631 "<previous_module>"
tmain_609: IF(0,609,tmain_610)__CSEQ_removeindent;
                                        
# 7632 "<previous_module>"
__cs_mutex_lock(&library_lock, 0);
                                        
# 7633 "<previous_module>"
tmain_610: IF(0,610,tmain_611)__CSEQ_removeindent;
                                        
# 7634 "<previous_module>"
__cs_local_lfds711_stack_push_result = __CSEQ_atomic_swap_stack_top(&(*__cs_param_lfds711_stack_push_ss).top[0], &__cs_local_lfds711_stack_push_original_top[0], &__cs_local_lfds711_stack_push_new_top[0]);
                                        
# 7635 "<previous_module>"
tmain_611: IF(0,611,tmain_612)__CSEQ_removeindent;
                                        
# 7636 "<previous_module>"
__cs_mutex_unlock(&library_lock, 0);
                                        
# 7637 "<previous_module>"
;
                                        ;
                                        
# 7638 "<previous_module>"
static _Bool __cs_local_lfds711_stack_push___cs_tmp_if_cond_16;
                                        
# 7639 "<previous_module>"
__cs_local_lfds711_stack_push___cs_tmp_if_cond_16 = __cs_local_lfds711_stack_push_result == 0;
                                        
# 7640 "<previous_module>"
if (__cs_local_lfds711_stack_push___cs_tmp_if_cond_16)

# 7641 "<previous_module>"
                                        {

# 7642 "<previous_module>"
                                                {
                                                        
# 7643 "<previous_module>"
static int __cs_local_exponential_backoff_loop;
                                                        
# 7644 "<previous_module>"
__cs_local_exponential_backoff_loop = 0;

# 7645 "<previous_module>"
                                                        {
                                                                
# 7646 "<previous_module>"
;
                                                                ;
                                                        }
                                                        
# 7648 "<previous_module>"
;
                                                        
# 7649 "<previous_module>"
__cs_local_exponential_backoff_loop++;

# 7650 "<previous_module>"
                                                        {
                                                                
# 7651 "<previous_module>"
;
                                                                ;
                                                        }
                                                        
# 7653 "<previous_module>"
;
                                                        
# 7654 "<previous_module>"
__cs_local_exponential_backoff_loop++;

# 7655 "<previous_module>"
                                                        {
                                                                
# 7656 "<previous_module>"
;
                                                                ;
                                                        }
                                                        
# 7658 "<previous_module>"
;
                                                        
# 7659 "<previous_module>"
__cs_local_exponential_backoff_loop++;
                                                        
# 7660 "<previous_module>"
tmain_612: IF(0,612,tmain_613)__CSEQ_removeindent;
                                                        
# 7661 "<previous_module>"
__CPROVER_assume(!(__cs_local_exponential_backoff_loop < 3));
                                                        
# 7662 "<previous_module>"
__exit_loop_101:
                                                        __CPROVER_assume(__cs_pc_cs[0] >= 613);

                                                        
# 7663 "<previous_module>"
;
                                                        ;
                                                        
# 7664 "<previous_module>"
__exit__exponential_backoff_6_23:
                                                        __CPROVER_assume(__cs_pc_cs[0] >= 613);

                                                        
# 7665 "<previous_module>"
;
                                                        ;
                                                }
                                                
# 7667 "<previous_module>"
;
                                        }

                                        
# 7669 "<previous_module>"
__CPROVER_assume(__cs_pc_cs[0] >= 613);
                                        ;
                                        
# 7670 "<previous_module>"
__cs_local_lfds711_stack_push_i++;
                                        
# 7671 "<previous_module>"
;
                                        ;
                                        
# 7672 "<previous_module>"
static _Bool __cs_local_lfds711_stack_push___cs_tmp_if_cond_17;
                                        
# 7673 "<previous_module>"
__cs_local_lfds711_stack_push___cs_tmp_if_cond_17 = __cs_local_lfds711_stack_push_i > 1000;
                                        
# 7674 "<previous_module>"
if (__cs_local_lfds711_stack_push___cs_tmp_if_cond_17)

# 7675 "<previous_module>"
                                        {
                                                
# 7676 "<previous_module>"
goto __exit_loop_97;
                                                ;
                                        }

                                        
# 7678 "<previous_module>"
;
                                }
                                
# 7680 "<previous_module>"
;
                                
# 7681 "<previous_module>"
if (!(__cs_local_lfds711_stack_push_result == 0))

# 7682 "<previous_module>"
                                {
                                        
# 7683 "<previous_module>"
goto __exit_loop_97;
                                        ;
                                }

                                
# 7685 "<previous_module>"
;

# 7686 "<previous_module>"
                                {
                                        
# 7687 "<previous_module>"
tmain_613: IF(0,613,tmain_614)__CSEQ_removeindent;
                                        
# 7688 "<previous_module>"
__cs_mutex_lock(&library_lock, 0);
                                        
# 7689 "<previous_module>"
tmain_614: IF(0,614,tmain_615)__CSEQ_removeindent;
                                        
# 7690 "<previous_module>"
(*__cs_param_lfds711_stack_push_se).next = __cs_local_lfds711_stack_push_original_top[0];
                                        
# 7691 "<previous_module>"
tmain_615: IF(0,615,tmain_616)__CSEQ_removeindent;
                                        
# 7692 "<previous_module>"
__cs_mutex_unlock(&library_lock, 0);
                                        
# 7693 "<previous_module>"
tmain_616: IF(0,616,tmain_617)__CSEQ_removeindent;
                                        
# 7694 "<previous_module>"
__cs_local_lfds711_stack_push_new_top[1] = __cs_local_lfds711_stack_push_original_top[1] + 1;
                                        
# 7695 "<previous_module>"
tmain_617: IF(0,617,tmain_618)__CSEQ_removeindent;
                                        
# 7696 "<previous_module>"
__cs_mutex_lock(&library_lock, 0);
                                        
# 7697 "<previous_module>"
tmain_618: IF(0,618,tmain_619)__CSEQ_removeindent;
                                        
# 7698 "<previous_module>"
__cs_local_lfds711_stack_push_result = __CSEQ_atomic_swap_stack_top(&(*__cs_param_lfds711_stack_push_ss).top[0], &__cs_local_lfds711_stack_push_original_top[0], &__cs_local_lfds711_stack_push_new_top[0]);
                                        
# 7699 "<previous_module>"
tmain_619: IF(0,619,tmain_620)__CSEQ_removeindent;
                                        
# 7700 "<previous_module>"
__cs_mutex_unlock(&library_lock, 0);
                                        
# 7701 "<previous_module>"
;
                                        ;
                                        
# 7702 "<previous_module>"
static _Bool __cs_local_lfds711_stack_push___cs_tmp_if_cond_16;
                                        
# 7703 "<previous_module>"
__cs_local_lfds711_stack_push___cs_tmp_if_cond_16 = __cs_local_lfds711_stack_push_result == 0;
                                        
# 7704 "<previous_module>"
if (__cs_local_lfds711_stack_push___cs_tmp_if_cond_16)

# 7705 "<previous_module>"
                                        {

# 7706 "<previous_module>"
                                                {
                                                        
# 7707 "<previous_module>"
static int __cs_local_exponential_backoff_loop;
                                                        
# 7708 "<previous_module>"
__cs_local_exponential_backoff_loop = 0;

# 7709 "<previous_module>"
                                                        {
                                                                
# 7710 "<previous_module>"
;
                                                                ;
                                                        }
                                                        
# 7712 "<previous_module>"
;
                                                        
# 7713 "<previous_module>"
__cs_local_exponential_backoff_loop++;

# 7714 "<previous_module>"
                                                        {
                                                                
# 7715 "<previous_module>"
;
                                                                ;
                                                        }
                                                        
# 7717 "<previous_module>"
;
                                                        
# 7718 "<previous_module>"
__cs_local_exponential_backoff_loop++;

# 7719 "<previous_module>"
                                                        {
                                                                
# 7720 "<previous_module>"
;
                                                                ;
                                                        }
                                                        
# 7722 "<previous_module>"
;
                                                        
# 7723 "<previous_module>"
__cs_local_exponential_backoff_loop++;
                                                        
# 7724 "<previous_module>"
tmain_620: IF(0,620,tmain_621)__CSEQ_removeindent;
                                                        
# 7725 "<previous_module>"
__CPROVER_assume(!(__cs_local_exponential_backoff_loop < 3));
                                                        
# 7726 "<previous_module>"
__exit_loop_102:
                                                        __CPROVER_assume(__cs_pc_cs[0] >= 621);

                                                        
# 7727 "<previous_module>"
;
                                                        ;
                                                        
# 7728 "<previous_module>"
__exit__exponential_backoff_6_24:
                                                        __CPROVER_assume(__cs_pc_cs[0] >= 621);

                                                        
# 7729 "<previous_module>"
;
                                                        ;
                                                }
                                                
# 7731 "<previous_module>"
;
                                        }

                                        
# 7733 "<previous_module>"
__CPROVER_assume(__cs_pc_cs[0] >= 621);
                                        ;
                                        
# 7734 "<previous_module>"
__cs_local_lfds711_stack_push_i++;
                                        
# 7735 "<previous_module>"
;
                                        ;
                                        
# 7736 "<previous_module>"
static _Bool __cs_local_lfds711_stack_push___cs_tmp_if_cond_17;
                                        
# 7737 "<previous_module>"
__cs_local_lfds711_stack_push___cs_tmp_if_cond_17 = __cs_local_lfds711_stack_push_i > 1000;
                                        
# 7738 "<previous_module>"
if (__cs_local_lfds711_stack_push___cs_tmp_if_cond_17)

# 7739 "<previous_module>"
                                        {
                                                
# 7740 "<previous_module>"
goto __exit_loop_97;
                                                ;
                                        }

                                        
# 7742 "<previous_module>"
;
                                }
                                
# 7744 "<previous_module>"
;
                                
# 7745 "<previous_module>"
tmain_621: IF(0,621,tmain_622)__CSEQ_removeindent;
                                
# 7746 "<previous_module>"
__CPROVER_assume(!(__cs_local_lfds711_stack_push_result == 0));
                                
# 7747 "<previous_module>"
__exit_loop_97:
                                __CPROVER_assume(__cs_pc_cs[0] >= 622);

                                
# 7748 "<previous_module>"
;
                                ;
                                
# 7749 "<previous_module>"
goto __exit__lfds711_stack_push_2_4;
                                ;
                                
# 7750 "<previous_module>"
__exit__lfds711_stack_push_2_4:
                                __CPROVER_assume(__cs_pc_cs[0] >= 622);

                                
# 7751 "<previous_module>"
;
                                ;
                        }
                        
# 7753 "<previous_module>"
;
                        
# 7754 "<previous_module>"
__cs_local_contains_i++;
                }
                
# 7756 "<previous_module>"
;
                
# 7757 "<previous_module>"
tmain_622: IF(0,622,tmain_623)__CSEQ_removeindent;
                
# 7758 "<previous_module>"
__CPROVER_assume(!(__cs_local_contains_i < __cs_local_contains_actual_size));
                
# 7759 "<previous_module>"
__exit_loop_72:
                __CPROVER_assume(__cs_pc_cs[0] >= 623);

                
# 7760 "<previous_module>"
;
                ;
                
# 7761 "<previous_module>"
__cs_retval__contains_1 = __cs_local_contains_found;
                
# 7762 "<previous_module>"
goto __exit__contains_1;
                ;
                
# 7763 "<previous_module>"
__exit__contains_1:
                __CPROVER_assume(__cs_pc_cs[0] >= 623);

                
# 7764 "<previous_module>"
;
                ;
        }
        
# 7766 "<previous_module>"
;
        
# 7767 "<previous_module>"
assert(__cs_retval__contains_1);
        
# 7768 "<previous_module>"
goto __exit_main;
        ;
        
# 7769 "<previous_module>"
__exit_main:
        __CPROVER_assume(__cs_pc_cs[0] >= 623);

        
# 7770 "<previous_module>"
;
        ;
        
# 7771 "<previous_module>"
tmain_623: __CSEQ_removeindent;
        
# 7772 "<previous_module>"
__cs_exit(0, 0);
}


# 7774 "<previous_module>"
int main(void)
{
        
# 7775 "<previous_module>"
/* round  0 */__CSEQ_removeindent;
        
# 7776 "<previous_module>"
    /* main */__CSEQ_removeindent;
        
# 7777 "<previous_module>"
unsigned __CPROVER_bitvector[10] __cs_tmp_t0_r0;
        
# 7778 "<previous_module>"
__cs_pc_cs[0] = __cs_tmp_t0_r0;
        
# 7779 "<previous_module>"
__CPROVER_assume(__cs_pc_cs[0] > 0);
        
# 7780 "<previous_module>"
__CPROVER_assume(__cs_pc_cs[0] <= 623);
        
# 7781 "<previous_module>"
main_thread();
        
# 7782 "<previous_module>"
__cs_pc[0] = __cs_pc_cs[0];
        
# 7784 "<previous_module>"
    /* push_0 */__CSEQ_removeindent;
        
# 7785 "<previous_module>"
unsigned __CPROVER_bitvector[7] __cs_tmp_t1_r0;
        
# 7786 "<previous_module>"
if (__cs_active_thread[1])
        {
                
# 7787 "<previous_module>"
__cs_pc_cs[1] = __cs_tmp_t1_r0;
                
# 7788 "<previous_module>"
__CPROVER_assume(__cs_pc_cs[1] <= 122);
                
# 7789 "<previous_module>"
push_0(__cs_threadargs[1]);
                
# 7790 "<previous_module>"
__cs_pc[1] = __cs_pc_cs[1];
        }

        
# 7793 "<previous_module>"
    /* pop_0 */__CSEQ_removeindent;
        
# 7794 "<previous_module>"
unsigned __CPROVER_bitvector[8] __cs_tmp_t2_r0;
        
# 7795 "<previous_module>"
if (__cs_active_thread[2])
        {
                
# 7796 "<previous_module>"
__cs_pc_cs[2] = __cs_tmp_t2_r0;
                
# 7797 "<previous_module>"
__CPROVER_assume(__cs_pc_cs[2] <= 156);
                
# 7798 "<previous_module>"
pop_0(__cs_threadargs[2]);
                
# 7799 "<previous_module>"
__cs_pc[2] = __cs_pc_cs[2];
        }

        
# 7802 "<previous_module>"
unsigned __CPROVER_bitvector[10] __cs_tmp_t0_r1;
        
# 7803 "<previous_module>"
if (__cs_active_thread[0] == 1)
        {
                
# 7804 "<previous_module>"
__cs_pc_cs[0] = __cs_pc[0] + __cs_tmp_t0_r1;
                
# 7805 "<previous_module>"
__CPROVER_assume(__cs_pc_cs[0] >= __cs_pc[0]);
                
# 7806 "<previous_module>"
__CPROVER_assume(__cs_pc_cs[0] <= 623);
                
# 7807 "<previous_module>"
main_thread();
        }

        
# 7809 "<previous_module>"
return 0;
}

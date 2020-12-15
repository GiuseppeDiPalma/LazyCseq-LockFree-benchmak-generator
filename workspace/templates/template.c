// DO NOT MODIFY THIS FILE

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "checker.c"
// INTERFACE GOES THERE

int volatile ATOMIC_OPERATION = 1;
#define LOCK if(ATOMIC_OPERATION){ pthread_mutex_lock(&lock);}
#define UNLOCK if(ATOMIC_OPERATION){ pthread_mutex_unlock(&lock); }

void* ss;
pthread_mutex_t lock;

// THREAD GOES THERE

int main()
{
	pthread_mutex_init(&lock, NULL);
	ss = init();
	
	//THREAD CREATION GOES THERE

	check(ss);
	return (EXIT_SUCCESS);
}
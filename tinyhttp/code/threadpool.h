#ifndef _THREADPOOL_H_
#define _THREADPOOL_H_
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>
struct job
{
	void (*callbackfunction)(int);
	int arg;
	struct job *next;
};
struct threadpool
{
	int thread_num;
	pthread_t *threads;
	struct job *head, *tail;
	int queue_num;
	pthread_mutex_t mutex;
	pthread_cond_t cond;
	int close;
};
struct threadpool *threadpool_init(int n);
int threadpool_destroy(struct threadpool *pool);
void *function(void * arg);
int threadpool_add_job(struct threadpool *pool, void (*callbackfunction)(int), int arg);
#endif

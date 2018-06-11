#include "threadpool.h"
void *function(void *arg)
{
	struct threadpool *pool = (struct threadpool *)arg;
	while(1)
	{
		pthread_mutex_lock(&(pool -> mutex));
		while(pool -> close == 0 && pool -> queue_num == 0)
		{
			pthread_cond_wait(&(pool -> cond), &(pool -> mutex));
		}
		if(pool -> close == 1)
		{

			pthread_mutex_unlock(&(pool -> mutex));
			printf("pid %lu exit!\n", pthread_self());
			pthread_exit(NULL);
		}
		pool -> queue_num --;
		struct job *work = pool -> head;
		pool -> head = work -> next;
		pthread_mutex_unlock(&(pool -> mutex));
		(*(work -> callbackfunction))(work -> arg);
		free(work);
	}
	pthread_exit(NULL);
}
struct threadpool *threadpool_init(int n)
{
	struct threadpool *pool = (struct threadpool *)malloc(sizeof(struct threadpool));
	pthread_mutex_init(&(pool -> mutex), NULL);
	pthread_cond_init(&(pool -> cond), NULL);
	if(pool == NULL)
	{
		printf("malloc pool failed!\n");
		return NULL;
	}
	pool -> threads = (pthread_t *)malloc(sizeof(pthread_t) * n);
	if(pool -> threads == NULL)
	{
		free(pool);
		printf("malloc threads failed!\n");
		return NULL;
	}
	pool -> thread_num = n;
	for(int i = 0; i < n; ++i)
	{
		pthread_create(&(pool -> threads[i]), NULL, function, pool);
	}
	pool -> head = pool -> tail = NULL;
	pool -> queue_num = pool -> close = 0;
	return pool;
}
int threadpool_destroy(struct threadpool *pool)
{
	if(pool == NULL)
		return -1;
	pool -> close = 1;
	pthread_cond_broadcast(&(pool -> cond));
	for(int i = 0; i < pool -> thread_num; i ++)
		pthread_join(pool -> threads[i], NULL), printf("thread %d joined!\n", i);
	free(pool -> threads);
	struct job *p;
	p = pool -> head;
	while(p != NULL)
	{
		pool -> head = p -> next;
		free(p);
		p = pool -> head;
	}
	pthread_mutex_destroy(&(pool -> mutex));
	printf("destroy mutex!\n");
	pthread_cond_destroy(&(pool -> cond));	
	printf("destroy cond\n");
	return 0;
}
int threadpool_add_job(struct threadpool *pool, void (*callbackfunction)(int), int arg)
{
	if(pool == NULL || callbackfunction == NULL)
	{
		printf("add NULL!\n");
		return -1;
	}
	if(pool -> close == 1)
	{
		printf("add close!\n");
		return -1;
	}
	struct job *work = (struct job *)malloc(sizeof(struct job));
	if(work == NULL)
	{
		printf("malloc job failed!\n");
		return -1;
	}
	work -> callbackfunction = callbackfunction;
	work -> arg = arg;
	work -> next = NULL;
	pthread_mutex_lock(&(pool -> mutex));
	if(pool -> head == NULL)
	{
		pool -> head = pool -> tail = work;
	}
	else 
	{
		pool -> tail -> next = work;
		pool -> tail = work;
	}
	pool -> queue_num ++;
	pthread_mutex_unlock(&(pool -> mutex));
	pthread_cond_signal(&(pool -> cond));
	return 0;
}

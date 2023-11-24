#include <stdio.h>
#include <sys/time.h>
#include <pthread.h>
#include <unistd.h>
#include <stdlib.h>

void	*p_funtion(void *data);

int	main()
{
	struct timeval start_time;
	int gettimeofday_result = gettimeofday(&start_time, NULL);
	printf("%d gettiemofday result\n", gettimeofday_result);
	printf("gettiemofday sec : %ld\n", start_time.tv_sec);
	printf("gettiemofday usec : %d\n", start_time.tv_usec);

	usleep(3);
	pthread_t thread[3];
	int thr_id;
	int status;

	char p1[] = "thread_1";
	char p2[] = "thread_2";
	char p3[] = "thread_3";
	// pthread_attr_t attr;

	thr_id = pthread_create(&thread[0], NULL, p_funtion, (void *)p1);
	if(thr_id < 0)
	{
		perror("pthread0 create error");
		exit(EXIT_FAILURE);
	}

	thr_id = pthread_create(&thread[1], NULL, p_funtion, (void *)p2);
	if(thr_id < 0)
	{
		perror("pthread0 create error");
		exit(EXIT_FAILURE);
	}

	p_funtion((void *)p3);

	pthread_join(thread[0], (void **)&status);
	pthread_join(thread[1], (void **)&status);

	printf("end\n");
	return 0;
}

void	*p_funtion(void *data)
{
	pid_t		pid;
	pthread_t	tid;

	pid = getpid();
	tid = pthread_self();

	char * thread_name = (char *)data;
	int i = 0;

	while (i < 3)
	{
		printf("thread name : %s, tid : %x, pid : %u\n", thread_name, (unsigned int)tid, (unsigned int)pid); //5
		i++;
		sleep(1);
	}
	return NULL;
}

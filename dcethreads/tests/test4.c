// vim: ts=4 sw=4:
//
//
//  Some more tests of thread cancellation
//
//  Create a service thread loops in a TRY block.
//  Cancel that thread.
//
//  Join on the thread and see what comes back
//

#include "dce/dcethreads_conf.h"
#include <signal.h>
#include <stdlib.h>

#include <dce/pthread_exc.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>

void *
worker_thd_routine(void *varg)
{
	pthread_addr_t arg = varg;
	printf("worker thread starting\n");
	TRY
	{
		while(1)
		{
			printf("........zzzzz\n");
			sleep(1);
		}
	}
	CATCH_ALL
	{
		printf("worker thd caught exception!!\n");
		RERAISE;
	}
	ENDTRY;
	printf("worker thd normal exit. this shouldnt happen!!");
	arg = NULL;
	varg = NULL;
	return NULL;
}

int main()
{
	pthread_t worker;
	pthread_addr_t exit_value;

	TRY
	{
		pthd4exc_create(&worker, &pthread_attr_default, worker_thd_routine, NULL);
	}
	CATCH_ALL
	{
		printf("error creating worker thd\n");
		pthread_testcancel();
		exit(1);
	}
	ENDTRY;

	//
	// cancel it
	//

	sleep(5);
	printf("cancelling the worker.... \n");
	pthread_cancel(worker);
	printf("joining canceled thd\n");
	pthread_join(worker, &exit_value);
	printf("exit status of worker thd = %p\n", exit_value);
	printf("done. exiting\n");
	return 0;
}

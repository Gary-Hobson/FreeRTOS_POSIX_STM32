/* FreeRTOS includes. */
#include "FreeRTOS_POSIX.h"

/* System headers. */
#include <stdbool.h>
#include <string.h>
#include <stdio.h>

/* FreeRTOS+POSIX. */
#include "FreeRTOS_POSIX/pthread.h"
#include "FreeRTOS_POSIX/mqueue.h"
#include "FreeRTOS_POSIX/time.h"
#include "FreeRTOS_POSIX/fcntl.h"
#include "FreeRTOS_POSIX/errno.h"

typedef struct demo
{
	int (*demo_func)(void);
	const char * demo_name;
}demo_t;


extern int thread_demo(void);
extern int thread_attr(void);
extern int vStartPOSIXDemo(void );
	
demo_t posix_exec_demo_list[]=
{
	{thread_attr, "thread_attr"},
	{thread_demo, "thread"},
	{vStartPOSIXDemo,"vStartPOSIXDemo"},
};

void exit(int no)
{
	printf("exit...\n");
}

char pWriteBuffer[2048];
int posix_test_demo(void)
{
	int i=0;
	
	for(i=0; i<sizeof(posix_exec_demo_list)/sizeof(posix_exec_demo_list[0]);i++)
	{
		/*打印任务栈信息*/
        vTaskList((char *)&pWriteBuffer);	
        printf("\ntask_name       task_state \tpriority \tstack \ttasK_num\n");
        printf("%s\n", pWriteBuffer);   
		
		/*执行测试Demo*/
		printf("\n-------start exec func :%s-------\n",posix_exec_demo_list[i].demo_name);
		posix_exec_demo_list[i].demo_func();
		printf("\n-------demo exec finish-------\n");
	}
	
	printf("\n\n**********POSIX Demo Execution complete********\n");
	return 0;
}

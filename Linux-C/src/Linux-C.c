/*
 ============================================================================
 Name        : Linux-C.c
 Author      : syq
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/time.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//#include <time.h>
#include <pthread.h>
#include "lplyv.c"

#define MAX 10
pthread_t thread[2];
pthread_mutex_t mut;
int number=0,i;

void *thread1(){
	printf("thread1:I'm thread 1\n");
	for(i=0;i!= MAX;i++){
		printf("thread1:number=%d\n",number);
		pthread_mutex_lock(&mut);
			number++;
		pthread_mutex_unlock(&mut);
		sleep(1);
	}
	printf("thread1 :主函数在等我完成任务吗？\n");
	pthread_exit(NULL);
}

void *thread2(){
	printf("thread2:I'm thread 2\n");
	for(i=0;i!= MAX;i++){
		printf("thread2:number=%d\n",number);
		pthread_mutex_lock(&mut);
			number++;
		pthread_mutex_unlock(&mut);
		sleep(1);
	}
	printf("thread2 :主函数在等我完成任务吗？\n");
	pthread_exit(NULL);
}

void thread_create(void){
	int temp;
	memset(&thread,0,sizeof(thread));
	if((temp=pthread_create(&thread[0],NULL,thread1,NULL))!=0){
		printf("create thread 1 failed!!!\n");
	}else
		printf("create thread 1 success!!!\n");

	if((temp=pthread_create(&thread[1],NULL,thread2,NULL))!=0){
		printf("create thread 2 failed!!!\n");
	}else
		printf("create thread 2 success!!!\n");
}

void thread_wait(void){
	if(thread[0]!=0){
		pthread_join(thread[0],NULL);
		printf("thread 1 finished!\n");
	}

	if(thread[1]!=0){
		pthread_join(thread[1],NULL);
		printf("thread 2 finished!\n");
	}
}

int main(void) {
//	float z=2,m1=1;
//	int i,tmp=0;
//	float sum=0.0;
//	for(i=0;i<=50;i++){
//		sum += z/m1;
//		tmp=z;
//		z=m1+z;
//		m1=tmp;
//
//	}
//	printf("result:%f\n",sum);
//
//
//
//	int n,t,m;
//	float a=2,b=1,s=0;
//	scanf("%d",&m);
//	for(n=0;n<=m;n++){
//		s += a/b;
//		t=a;
//		a=a+b;
//		b=t;
//	}
//	printf("result:%f\n",s);
	("!!!Hello World!!!"); /* prints !!!Hello World!!! */
//	printf("syq");


/*
	time_t timep;
	char *wday[]={"Sun","Mon","Tue","Wed","Thu","Fri","Sat"};
	struct tm *p;
	time(&timep);
	printf("%s",asctime(gmtime(&timep)));
	p=localtime(&timep);
	printf("%d - %d - %d \n",(1900+p->tm_year),1+p->tm_mon,p->tm_mday);
	printf("%s %d : %d\n",wday[p->tm_wday],p->tm_hour,p->tm_min,p->tm_sec);
*/

/*	int newret;
	printf("list the info:\n");
	newret=system("pwd");*/



//	int fd;
//	fd=creat("/home/4-6file",S_IRUSR);
//	if(fd==-1){
//		printf("create file failed!!!");
//	}else
//		system("ls /home -lh");

	pthread_mutex_init(&mut,NULL);

	printf("我是主函数哦，我正在创建线程，呵呵\n");
	thread_create();
	printf("我是主函数哦，我正在等待线程完成任务阿，呵呵\n");
	thread_wait();

	return EXIT_SUCCESS;
}

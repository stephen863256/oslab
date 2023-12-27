#include<stdio.h>
#include<unistd.h>
#include<sys/syscall.h>
#include <stdlib.h>
#include <string.h>


typedef   struct task{
    pid_t     pid;  /* The process id of the task. */
    char      comm[16]; /* The name of the task. */
    double       runtime; /* The runtime of the task. */
    int       is_running; /* whether the task is running. */
    double       cpu; /* The CPU usage of the task. */
}task_t; 			/* A task. */

int cmp(const void *a, const void *b) {
    return ((task_t *)a)->cpu < ((task_t *)b)->cpu;
}

int main(int argc,char *argv[]){
    int counter = 0;
    task_t tasks[500]; /* The array of tasks. */
    pid_t pid1[500];
    pid_t pid2[500];
    char comm1[6400];
    char comm2[6400];
    unsigned long long runtime1[500];
    unsigned long long runtime2[500];
    double runtime[500];
    int is_running1[500];
    int is_running2[500];
    double cpu[500];
    int counter1;
    int counter2;
    int opt;
    int second = 1;
    while(opt = getopt(argc,argv,"h")!= -1) /* Parse the command line arguments. */
    {
        if(argc == 1) 	break;
        else if(opt == 'h') {second = atoi(optarg);break;}
    }
    syscall(333,&counter1,pid1,comm1,runtime1,is_running1);
    while(1){
    sleep(second);
    system("clear");
    syscall(333,&counter2,pid2,comm2,runtime2,is_running2);

    int i,j = 0;
    counter = 0;
    while(i < counter1 && j < counter2)
    {
        if(pid1[i] == pid2[j])
        {
            counter ++;
            tasks[i].runtime = runtime2[j] - runtime1[i];
            tasks[i].cpu =  (tasks[i].runtime)/(second*1000000.0);
            tasks[i].is_running = is_running2[j];
            tasks[i].pid = pid1[i];
            i ++;
            j ++;
        }
        else if(pid1[i] < pid2[j])
            i ++;
        else if(pid1[i] > pid2[j])
            j ++;
    }
    //printf("%s\n",comm1+16);
    for(i = 0;i < counter;i ++){
        char name[16];
        for(j = 0;j < 16;j ++)
            name[j] =  comm2[16*i + j];
            //printf("%s\n",name);
        strcpy(tasks[i].comm,name);
    };

    qsort(tasks,counter,sizeof(task_t),cmp); /* Sorts the array of tasks. */
    printf("%-5s %-20s %-10s %-10s %-10s\n", "PID", "COMM", "ISRUNNING", "%CPU", "TIME");

    for(i = 0;i < counter && i < 20;i ++)
        printf("%-5d %-20s %9d %-2.2lf %-10.2lf\n",tasks[i].pid,tasks[i].comm,tasks[i].is_running,tasks[i].cpu,tasks[i].runtime);
    memcpy(pid1, pid2, sizeof(int) * 500);
    memcpy(comm1, comm2, sizeof(char) * 6400);
    memcpy(is_running1, is_running2, sizeof(int) * 500);
    memcpy(runtime1, runtime2, sizeof(unsigned long long) * 500);
    }
    return 0;
}

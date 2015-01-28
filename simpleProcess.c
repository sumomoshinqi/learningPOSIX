//
//  simpleProcess.c
//  A simple program using Pthread - showing how a parent process creates a child process using fork().
//
//  Created by Edam Lee on 15/1/28.
//  Copyleft (c) 2015 Edam Lee. All rights left.
//

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <pthread.h>

int value = 0;
void * runner(void * param);

int main(int argc, const char * argv[]) {
    int pid;
    pthread_t tid;
    pthread_attr_t attr;
    
    pid = fork();
    if (pid == 0) {
        pthread_attr_init(&attr);
        pthread_create(&tid, &attr, runner, NULL);
        pthread_join(tid, NULL);
        printf("CHILD: value = %d\n", value);
    }
    else if (pid > 0) {
        wait(NULL);
        printf("PARENT: value = %d\n", value);
    }
    return 0;
}

void * runner(void * param)
{
    value = 5;
    pthread_exit(0);
}

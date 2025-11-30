#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<sys/types.h>
#include<sys/wait.h>

int main(int argc, char **argv){
    pid_t pid=0;
    pid = fork();
    if(pid==0){
        printf("It is the child process and pid : %d\n",getpid());
        exit(0);
    }
    else if(pid>0){
        printf("It is the parent process and pid : %d\n", getpid());
        wait(NULL);
    }
    else{
        printf("Error while forking\n");
        exit(EXIT_FAILURE);
    }
    return 0;
}

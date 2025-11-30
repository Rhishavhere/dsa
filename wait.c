#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<sys/types.h>
#include<sys/wait.h>

int main(void){
    pid_t pid=0;
    int status;
    pid = fork();

    if(pid==0){
        printf("I am the child\n");
        execl("/bin/ls","ls","-l","/home/rhishh/",(char *)0);
        perror("In exec(): ");
        exit(1);
    }
    if(pid>0){
        printf("I am the parent and the child : %d\n",pid);
        pid= wait(&status);
        printf("End of process: %d\n",pid);
        if(WIFEXITED(status)){
            printf("The process ended with exit(%d)\n",WEXITSTATUS(status));
        }
        if(WIFSIGNALED(status)){
            printf("The process ended will kill - %d\n",WTERMSIG(status));
        }
    }
    if(pid<0){
        perror("In fork()");
    }
    return 0;
}

#include <unistd.h>
#include <stdio.h>
#include <sys/wait.h>

int main(int argc, char **argv) {
    pid_t proc_id;
    proc_id = fork();

    if (proc_id == -1) {
        printf("proc created failed!\n");
        return -1;
    } else {
        // printf("Created new process, pid: %d.\n", proc_id);
    }

    // printf("Current Process ID: %d, and Parent Process ID: %d.\n", getpid(), getppid());
    

    if (proc_id == 0) {  // parent proc
        printf("This is the parent process, process id: %d; The parent process id: %d.\n", getpid(), getppid());
        /*
        sleep(1);
        int status;
        int ret = wait(&status);
        printf("Child process is recycled! Id: %d; Status: %d.\n", ret, status);
        */
    } else {  // child proc
        printf("This is the child process, process id: %d; The parent process id: %d.\n", getpid(), getppid());
    }
    
    
    
    return 0;
}
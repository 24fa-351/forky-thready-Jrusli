// pattern2.c
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <time.h>

void create_pattern2(int index) {
    srand(time(NULL));  // Seed for random sleep times
    printf("** Pattern 2: creating %d processes\n", index);
    
    pid_t pid = fork();
    if (pid == 0) {  // First child process
        int sleep_time = rand() % 8 + 1;  // Random sleep time between 1 and 10 seconds
        printf("Child 0 (pid %d): starting\n", getpid());

        for (int ix = 1; ix < index; ix++) {
            pid_t child = fork();
            sleep_time = rand() % 8 + 1;
            if (child == 0) {  
                printf("Child %d (pid %d), sleeping %d seconds after creating child %d\n", ix-1, getppid(), sleep_time, ix);
            } else if (child > 0) {
                sleep(sleep_time);  // Parent process sleeps after creating child
                printf("Child %d (pid %d), waiting for child %d (pid %d)\n", ix-1, getpid(), ix, child);
                wait(NULL);  // Wait for the child process to finish
                printf("Child %d (pid %d) exiting.\n", ix-1, getpid());
                exit(0);
            } else {
                perror("fork");
                exit(1);
            }
        }
        printf("Child %d (pid %d) [no children created] sleeping %d seconds\n", index-1, getpid(), sleep_time);
        sleep(sleep_time);
        printf("Child %d (pid %d) exiting.\n", index-1, getpid());
        exit(0);
    } else if (pid > 0) {  // Parent process
        printf("Parent: created child 0 (pid %d)\n", pid);
        wait(NULL);  // Parent waits for the first child to finish
        printf("Parent: child 0 (pid %d) has exited\n", pid);
        printf("** Pattern 2: All children have exited\n");
    } else {
        perror("fork");
        exit(1);
    }
}

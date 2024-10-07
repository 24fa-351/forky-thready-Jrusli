// pattern1.c
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <time.h>

void create_pattern1(int index) {  // Renamed n to index
    srand(time(NULL));  // Seed for random sleep times
    printf("** Pattern 1: creating %d processes\n", index);
    
    for (int ix = 0; ix < index; ix++) {  // Renamed i to ix, n to index
        pid_t pid = fork();
        int sleep_time = rand() % 8 + 1;  
        if (pid == 0) {  // Child process
            printf("Process %d (pid %d) created: will sleep for %d seconds\n", ix, getpid(), sleep_time);
            sleep(sleep_time);  // Simulate work
            printf("Process %d (pid %d): exiting\n", ix, getpid());
            exit(0);  // Child exits after completing work
        } else if (pid > 0) {  // Parent process
            printf("Parent: created child %d (pid %d)\n", ix, pid);
        } else {
            perror("fork");
            exit(1);
        }
    }
 
    printf("** Pattern 1: All processes created\n");

    // Parent waits for all children to exit
    for (int ij = 0; ij < index; ij++) {  // Renamed i to ix, n to index
        wait(NULL);  // Wait for each child to finish
    }

    printf("** Pattern 1: All children have exited\n");
}

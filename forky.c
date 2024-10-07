// forky.c
#include <stdio.h>
#include <stdlib.h>

// Function declarations for patterns
void create_pattern1(int n);
void create_pattern2(int n);

int main(int argc, char *argv[]) {
    if (argc != 3) {
        fprintf(stderr, "Usage: %s <number of things> <pattern number (1 or 2)>\n", argv[0]);
        exit(1);
    }

    int num_things = atoi(argv[1]);
    int pattern_num = atoi(argv[2]);

    if (pattern_num == 1) {
        create_pattern1(num_things);
    } else if (pattern_num == 2) {
        create_pattern2(num_things);
    } 
    
    return 0;
}

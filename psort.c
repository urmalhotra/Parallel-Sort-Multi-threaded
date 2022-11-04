#include <stdlib.h>
#include <stdio.h>
#include <pthread.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>
#include <sys/sysinfo.h>
#include <sys/stat.h>
#include <sys/mman.h>

typedef struct rec {
    int key;
    int value[24]; // 96 bytes
} rec_t;

int get_records(struct rec_t **elements, int MAX, FILE* filename){
    printf("ayo\n");
    elements = malloc(MAX * sizeof(struct rec_t *));
    char *instruction;
    while(fgets(instruction, 100, filename)){
        int curr_key =  *(int *)&instruction;
        printf("%i", curr_key);
    }
    fclose(filename);
    return 0;
}

int main(int argc, char *argv[])
{
    FILE* input = argv[1];
    FILE* output;
    struct stat st;
    if(stat(input, &st) == -1){
    exit(0);
    }
    int f_size = st.st_size;
    int MAX = f_size/100;
    input = fopen(argv[1], "r");
    //output = fopen(argv[2], "w");
    if (input == NULL) {
       exit(1);
    }
    struct rec_t **elements;
    get_records(elements, MAX, input);
    return 0;
    }
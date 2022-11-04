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

unsigned int  byte_to_int (unsigned char* buffer){
    return (buffer[0] << 24) + (buffer[1] << 16) + (buffer [2] << 8) + buffer[3];
}

rec_t* get_records(rec_t *elements, FILE* filename, int MAX){
    FILE* input = fopen(filename, "rb");
    elements = malloc(sizeof(rec_t) *MAX);
    if (input == NULL){
        exit(0);
    }

    if(fread(elements, sizeof(rec_t), MAX, input) !=MAX)
    {
        printf("error");
    }
    fclose(input);
    return elements;
}

int write_records(rec_t *elements, FILE* filename, int MAX){
    FILE* output = fopen(filename, "wb");
    if (output == NULL){
        exit(0);
    }
    if(fwrite(elements, sizeof(rec_t), MAX, output) !=MAX)
    {
        printf("error");
    }
    fclose(output);
    return 0;
}

int main(int argc, char *argv[])
{
    FILE* inp = argv[1];
    FILE* out = argv[2];
    struct stat st;
    if(stat(inp, &st) == -1){
    exit(0);
    }
    int f_size = st.st_size;
    int MAX = f_size/100;
    //store records
    rec_t *elements;

    elements = get_records(elements, inp, MAX);
    //sort
    write_records(elements, out, MAX);
    return 0;
    }
#include <sys/sysinfo.h>
#include <pthread.h>


typedef struct rec {
    int key;
    int value[24]; // 96 bytes
} rec_t;

void merge_sort(*rec_t keys, int left, int right){
    
    if(left < right){ //arr len is still larger than 1

    }
}
int main(int argc, char *argv[])
{
    int num_threads = get_nprocs();
    pthread_t threads[num_threads];
    
    for(int i = 0; i < num_threads; i ++){
        pthread_create(&threads[i], NULL, merge_sort_threads, (void *)i);
    }
    for(int i = 0; i < num_threads; i ++){
        pthread_join(threads[i], NULL);
    }

}
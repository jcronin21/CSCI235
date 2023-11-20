#include <stdio.h>
#include <stdlib.h>

#define MEMORY_CAPACITY_WORDS 64
int memory[MEMORY_CAPACITY_WORDS]; // The memory we can allocate
int* end; // A pointer to the last element of memory

int mymalloc_calls = 0;

/* Begin editing the code here! */

void mymalloc_init() {
    // Initialize memory and end here
    memory[0] = MEMORY_CAPACITY_WORDS - 1; // Entire array treated as free block
    end = &memory[MEMORY_CAPACITY_WORDS - 1]; // Set the end pointer
}

void print_memory() {
    for (int i = 0; i < MEMORY_CAPACITY_WORDS; i++) {
        printf("memory[%d]=%d\n", i, memory[i]);
    }
}

void *mymalloc(int bytes_requested) {
    mymalloc_calls++;
    printf("mymalloc_call %d, bytes=%d\n", mymalloc_calls, bytes_requested);

    int *ptr = memory;
    while (ptr <= end) {
        int block_size = *ptr;
        if (block_size >= bytes_requested + 1) {
            *ptr = bytes_requested + 1; // Update header for allocated block
            return ptr + 1; // Return pointer to data after header
        }
        ptr += block_size + 1; // Move to the next block
    }
    printf("Error: Insufficient space\n");
    return NULL;
}

void myfree(int* p) {
    if (p != NULL) {
        p--; // Point to the header
        *p = *p & ~1; // Set allocated flag bit to 0
    }
}

/* End editing the code here */

void fill(int* a, int size, int val) {
    for (int i=0; i<size; i++) {
        *(a+i)=val;
    }
}

int main() {
    mymalloc_init();
    print_memory();
    
    //make some random malloc calls
    int max=10;
    int *data[max];
    int N=3;//how many pointers are being used
    for (int i=0; i<N; i++) {
        int size = rand()%10+1;//random number between 1 and 10
        data[i] = (int*)mymalloc(size*sizeof(int));
        fill(data[i], size, mymalloc_calls);
    }

    //now make some random calls to malloc and free
    for (int i=0; i<10; i++) {
        //choose to malloc or free something with 50/50 probability each
        if (N<max && (double)rand()/RAND_MAX<.5) {
            int size = rand()%10+1;
            data[N] = (int*)mymalloc(size*sizeof(int));
            fill(data[N], size, mymalloc_calls);
            N++;
        }
        if (N>0 && (double)rand()/RAND_MAX<.5) {
            //choose a random pointer to free
            int index = rand()%N;
            printf("freeing index %d\n",index);
            myfree(data[index]);
            //swap last element in data, so first N are the valid pointers
            data[index]=data[N-1];
            N--;
        }
    }
    print_memory();
}

#include <stdio.h>
#include <stdlib.h>
#include <inttypes.h>

#define BUFFER_SIZE 64

int square_multiply(int base, int exponent, int mod){
    int result = 1; 
    int square = base % mod;
    while(exponent>0){
        if(exponent%2 == 1){
            result = (result*square) %mod;
        }
        square = (square * square) % mod;
        exponent /= 2;

    }
    return result;
}

void leak_function(int base, int exponent, int mod){
    int *results = (int *)malloc(BUFFER_SIZE * sizeof(int));
    if(!results)
        return;
    for(int i  = 0; i <BUFFER_SIZE; i++){
        results[i] = square_multiply(base, exponent+i, mod);
    }
    if(exponent% mod == 0){
        printf("Memory leak here");
        return;
    }
    free(results);
}


int LLVMFuzzerTestOneInput(const uint8_t *Data, size_t Size){
    if(Size < 3)
        return 0;
    int base = *((int*)(Data)) +1;
    int exponent = *(int *)(Data +4);
    int mod = *((int *)(Data +8))+1;

    leak_function(base, exponent, mod);

    return 0;

}

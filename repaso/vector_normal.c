#include <stdlib.h>
#include <stdio.h>
#include <time.h>


int main(){

    /*Llenar vector  */
    time_t begin, end;
    float myTime;
    int v[200000];
    int size = sizeof(v)/sizeof(v[0]);
    begin = clock();
    for (int i = 0; i < size; i++){
        v[i] = i;
    }
    end = clock();
    myTime = (float)(end-begin);

    printf("%f\n", myTime/CLOCKS_PER_SEC);
    return 0;
}
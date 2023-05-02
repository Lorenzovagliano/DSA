#include <stdlib.h>
#include <stdio.h>

int main(void){
    int *p;
    int i = 0;
    while(i<20){
        p = malloc(128);
        printf("%ld\n", (long)p);
        free(p);
        i++;
    }
    return (0);
}

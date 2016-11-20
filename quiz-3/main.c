#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <errno.h>
#include <string.h>

int main(){
    errno = 0;
    int *pPtr = 60000;
    printf("%d", pPtr);

    return 0;
}
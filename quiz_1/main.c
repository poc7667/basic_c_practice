#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(){
    int yourAge;
    printf("\nWhat is your age");
    scanf("%d", &yourAge);

    switch (yourAge)
    {
        case 13-19:
            printf ("You are teenager\n");
            break;
        case 50:
            printf ("You are golden\n");
            break;
        default:
            printf("I am not sure, what you are\n");
    }
    return 0;
}
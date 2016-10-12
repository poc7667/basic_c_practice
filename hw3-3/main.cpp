#include "stdio.h"
#include "stdlib.h"
#include "string.h"
#include "math.h"

int main() {


    int a, b, c;
    do {
        printf("Enter three integer for finding the max one  -- separated by a space:");
        scanf("%d %d %d", &a, &b, &c);
        int firstMax, finalMax;
        finalMax = (c > (firstMax = (a > b) ? a : b)) ? c : firstMax;
        printf("max %d\n", finalMax);


        printf("continue? (yes/no):");
        char *userInput;
        userInput = (char *) malloc(10);
        scanf("%s", userInput);
        if (strncmp(userInput, "yes", 3) == 0) {
        } else {
            break;
        }

    } while (1);

    printf("Thanks for using this program");
    return 0;

}
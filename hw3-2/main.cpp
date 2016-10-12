#include "stdio.h"
#include "stdlib.h"
#include "string.h"
#include "math.h"

int main() {

    float firstN;
    float secondN;
    char op;
    do {
        printf("Type a number, operator, number  -- separated by a space:");
        scanf("%f %c  %f", &firstN, &op, &secondN);
        if (op == '+')
            printf("%f  +   %f  =   %f",
                   firstN, secondN, firstN + secondN);
        else if (op == '-')
            printf("%f  - %f =   %f",
                   firstN, secondN, firstN - secondN);
        else if (op == '*')
            printf("%f  *   %f  =   %f",
                   firstN, secondN, firstN * secondN);
        else if (op == '/')
            printf("%f  /   %f  =   %f",
                   firstN, secondN, firstN / secondN);
        else if (op == '%')
            printf("%f  %%  %f  =   %f",
                   firstN, secondN, fmod(firstN, secondN));
        else {
            printf("Unknown operator");
        }
        printf("\n\n");

        printf("continue? (yes/no):");

        char *userInput;
        userInput = (char *) malloc(10);
        scanf("%s", userInput);
        if (strncmp(userInput, "yes", 3) == 0) {
        } else {
            break;
        }

    } while (1);

    return 0;
}
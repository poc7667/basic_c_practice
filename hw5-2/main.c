#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <errno.h>

const int NUM_OF_VALUES = 2;


void showWelcomeMsg() {
    printf("Please enter float number separated by spaces and press enter:");
}

int main() {
    showWelcomeMsg();
    double values[NUM_OF_VALUES];

    while (1) {
        errno = 0;
        char temp[257];
        fgets(temp, 256, stdin);
//        fprintf(stderr, "%s\n", temp); // show what user entered
        char *str = strtok(temp, " ");
        int cnt = 0;
        while (str != NULL && cnt < NUM_OF_VALUES) {
            char *endTemp;
            double val = strtod(str, &endTemp);
            if (*endTemp == 0 || *endTemp =='\n') {
                values[cnt] = val;
                cnt++;
                str = strtok(NULL, " ");
            } else {
                errno = 1;
                break;
            }
        }
        if (errno == 1) {
            printf("\nError.Please enter again!");
        } else {
            break;
        }
    }

    printf("You entered %lf %lf\n", values[0], values[1]);
    printf("Thank you for giving your choice");

    return 0;
}
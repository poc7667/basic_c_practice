#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <errno.h>
#include <string.h>

const int MSG_SIZE = 5;
const int MAX_USER_INPUT_STRING_SIZE = 100;

int getMenuChoice();


int main() {
    errno = 0;
    printf("Welcome to sorting program\n");
    getMenuChoice();
    printf("Thank you and good bye");
    return 0;
}

int getMenuChoice() {
    int valid_input;
    const char *msgs[] = {"Title", "Rank", "Date", "Stars", "Likes"};
    for (int i = 0; i < MSG_SIZE; i++) {
        printf("%d %s\n", i + 1, msgs[i]);
    }
    while (1) {
        char user_input[100];
        printf("Enter your choice between 1 and %d only:", MSG_SIZE);
        scanf("%s", user_input);
        int value = user_input[0] - '0';
        if (value >= 1 && value < MSG_SIZE + 1) {
            valid_input = value;
            break;
        } else {
            printf("You've entered an invalid choice. Try again\n");
        }
    }
}
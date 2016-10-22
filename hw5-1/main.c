#include <stdio.h>
#include <stdlib.h>
#include <math.h>

const int MSG_SIZE = 5;


void showWelcomeMsg() {
    char *items[MSG_SIZE];
    items[0] = "Title";
    items[1] = "Rank";
    items[2] = "Date";
    items[3] = "Stars";
    items[4] = "Likes";

    printf("Welcome to sorting program\n");
    for (int i = 0; i < MSG_SIZE; i++) {
        printf("%d. %s\n", i + 1, items[i]);
    }

}

int main() {
    int valid_input;
    showWelcomeMsg();
    while (1) {
        char user_input[100];
        printf("Enter your choice between 1 and 5 only:");
        scanf("%s", user_input);
        int value = user_input[0] - '0';
        if (value >= 1 && value < MSG_SIZE + 1) {
            valid_input = value;
            break;
        } else {
            printf("You've entered an invalid choice. Try again\n");
        }
    }
    printf("You entered valid choice %d\n", valid_input);
    printf("Thank you for giving your choice");
    return 0;
}
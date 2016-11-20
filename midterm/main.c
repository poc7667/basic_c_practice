#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>

const int NUM_OF_OPTION = 5;
const int MAX_USER_INPUT = 256;
const int DIVISION = 4;
const int EXIT = 5;

static const char *menu[] = {
        "Addition",
        "Subtraction",
        "Multiplication",
        "Division",
        "Exit"
};

void showMenu() {
    printf("\n\nWelcome to Poc’s Handy Calculator\n");
    for (int i = 0; i < NUM_OF_OPTION; i++) {
        printf("%d. %s\n", i + 1, menu[i]);
    }
}

int getUserOption() {
    printf("What would you like to do? ");
    int val;
    double values[NUM_OF_OPTION];
    while (1) {
        errno = 0;
        char temp[MAX_USER_INPUT + 1];
        fgets(temp, MAX_USER_INPUT, stdin);
        char *str = strtok(temp, " ");
        char *endTemp;
        val = strtod(str, &endTemp);
        if (val >= 1 && val <= NUM_OF_OPTION) {
            return val;
        } else {
            printf("\nThat is not a valid choice, please re‐enter:");
            continue;
        }
    }
}

char *getOptionName(int option) {
    return menu[option - 1];
}

static double *getUserInputValues(int option) {
    printf("Please enter two numbers for %s operation, pls separated by a space:", getOptionName(option));
    int NUM_OF_VALUES = 2;
    double values[NUM_OF_VALUES];
    while (1) {
        errno = 0;
        char temp[257];
        fgets(temp, 256, stdin);
        char *str = strtok(temp, " ");
        int cnt = 0;
        while (str != NULL && cnt < NUM_OF_VALUES) {
            char *endTemp;
            double val = strtod(str, &endTemp);
            if (*endTemp == 0 || *endTemp == '\n') {
                values[cnt] = val;
                cnt++;
                str = strtok(NULL, " ");
            } else {
                errno = 1;
                break;
            }
        }
        if (errno == 1) {
            printf("\nError reading your numbers.");
        } else if (option == DIVISION && ((int) values[1] == 0)) {
            printf("You can't divide by zero\n");
        } else {
            break;
        }
        printf("Please re-enter both numbers :");
    }
    return values;
}

void ansTemplate(int option, double *values, double ans) {
    printf("\n\nResult of %s %.2lf by %.2lf is %.2lf.", menu[option - 1], values[0], values[1], ans);
}

void calculateAnswer(int option) {
    double ans;
    double *values = getUserInputValues(option);
    switch (option) {
        case 1:
            ansTemplate(option, values, values[0] + values[1]);
            break;
        case 2:
            ansTemplate(option, values, values[0] - values[1]);
            break;
        case 3:
            ansTemplate(option, values, values[0] * values[1]);
            break;
        case 4:
            ansTemplate(option, values, values[0] / values[1]);
            break;
    }
}

int main() {

    while (1) {
        showMenu();
        int userOption = getUserOption();
        if (userOption == EXIT) {
            break;
        } else {
            calculateAnswer(userOption);
        }
        printf("\nPress enter key to continue …");
        char cont;
        scanf("%c", &cont);
    }

    printf("\nThank you for using WeiCheng's Handy Calculator");
    return 0;
}

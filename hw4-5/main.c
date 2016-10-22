#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <memory.h>

const int USER_INPUT_SIZE_EACH_LINE = 999;

void draw_middle_lines(char *middle_line, int width) {
    printf("%s", middle_line);
    for (int i = 2; i < width; i++) {
        printf(" ");
    }
    printf("%s\n", middle_line);
}

void draw_bound_line(char *bound_char, int width) {
    for (int i = 0; i < width; i++) {
        printf("%s", bound_char);
    }
    printf("\n");
}


void clearNewline(char *line, int max_len) {
    for (int i = 0; i < max_len; i++) {
        if (line[i] == '\n') {
            line[i] = '\0';
        }
    }
}

char **ask_user_preference() {
    const int NUM_OF_PROMPTS = 4;
    char *prompt[] = {
            "please input height:",
            "please input width:",
            "please input horizontal char:",
            "please input vertical char:",
    };
    char **preference;
    preference = malloc(NUM_OF_PROMPTS);
    for (int i = 0; i < NUM_OF_PROMPTS; i++) {
        preference[i] = malloc(USER_INPUT_SIZE_EACH_LINE);
        memset(preference[i], 0, sizeof(char) * USER_INPUT_SIZE_EACH_LINE);
        printf("%s", prompt[i]);
        fgets(preference[i], USER_INPUT_SIZE_EACH_LINE, stdin);
        clearNewline(preference[i], USER_INPUT_SIZE_EACH_LINE);
    }
    return preference;
}

void draw(int w, int h, char *bound_char, char *middle_char) {
    draw_bound_line(bound_char, w);
    for (int i = 2; i < h; i++) {
        draw_middle_lines(middle_char, w);
    }
    draw_bound_line(bound_char, w);
}

int main() {
    char **pref = ask_user_preference();
    int height = atoi(pref[0]);
    int width = atoi(pref[1]);
    char *bound_char = pref[2];
    char *middle_char = pref[3];
    draw(width, height, bound_char, middle_char);
    return 0;
}

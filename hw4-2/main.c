#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void draw_middle_lines(char* middle_line, int cnt){
    for(int i=0;i< cnt;i++){
        printf("%s\n", middle_line);
    }
}

int main(){
    const char horizontal_line[] = "--------------------";
    const char middle_line[] =   "|                  |";

    printf("%s\n", horizontal_line);
    draw_middle_lines(middle_line, 8);
    printf("%s\n", horizontal_line);

    return 0;
}
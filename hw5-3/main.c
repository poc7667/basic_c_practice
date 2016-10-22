#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <errno.h>
#include <string.h>
#include <limits.h>

float get_avg_temp(int sum, int num_of_items){
    return (float)(sum/num_of_items);
}

int main() {
    errno = 0;
    int weeklyTemp[] = {69, 70, 71, 68, 66, 71, 70};
    int i, max = INT_MIN, min = INT_MAX;
    float total = 0, average;
    for(int j=0;j< sizeof(weeklyTemp)/ sizeof(int);j++){
        printf("Day %d, Temp:%d\n", j+1, weeklyTemp[j]);
        int val = weeklyTemp[j];
        total += val;
        if(val > max){
            max = val;
        }
        if(val < min){
            min = val;
        }
    }
    printf("The Min Temp was : %d\n", min);
    printf("The Max Temp was : %d\n", max);
    printf("The Avg Temp was : %f\n", get_avg_temp(total, sizeof(weeklyTemp)/ sizeof(int)));

    printf("Thank you and good bye");

    return 0;
}
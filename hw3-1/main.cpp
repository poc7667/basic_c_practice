#include <stdio.h>

int main() {

    int yourAge;
    printf("How	old	are	you?:	");
    scanf("%d", &yourAge);

    if(yourAge < 13){
        printf("You	are	a kid\n");
    }else if(yourAge >= 13 && yourAge <= 19){
        printf("You are a teenager");
    }else{
        printf("You are an adult");
    }
    return 0;
}
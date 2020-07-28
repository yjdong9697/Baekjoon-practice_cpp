#include <stdio.h>

int main(void){
    int result;
    scanf("%d", &result);

    if (90 <= result){
        printf("A\n");
    }
    
    else if (80 <= result){
        printf("B\n");

    }
    else if (70 <= result){
        printf("C\n");
    }
    
    else if (60<= result){
        printf("D\n");
    }

    else{
        printf("F\n");
    }

    return 0;

}
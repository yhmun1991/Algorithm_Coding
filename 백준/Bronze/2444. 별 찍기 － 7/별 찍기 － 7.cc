#include<stdio.h>

int main(){
    int input_line = 0;
    int compare_data = 0;
    
    scanf("%d",&input_line);
    if(input_line > 100 || input_line < 1)
        return 0; //Error
    
    for(int i = 0 ; i < input_line ; i++){
        compare_data = i*2 + 1;
        for(int j = 1 ; j < input_line-i; j++)
            printf(" ");
        for(int k=0 ; k < compare_data ; k++)
            printf("*");
        printf("\n");
    }
    for(int i = input_line-2 ; i >= 0 ; i--){
        compare_data = i*2 + 1;
        for(int j = 1 ; j < input_line-i; j++)
            printf(" ");
        for(int k=0 ; k < compare_data ; k++)
            printf("*");
        printf("\n");
    }
    return 0;
}
#include<stdio.h>

int main(){
    int InputData[6] = {0,};
    int fixed_values[6] = {1,1,2,2,2,8};
    int output_values[6] = {0,};

    for(int i = 0 ; i < 6 ; i++){
        scanf("%d", &InputData[i]);
        if(InputData[i]>10 || InputData[i] < 0)
            return 0;//Error

        if(InputData[i] != fixed_values[i])
        {
 
            output_values[i] = fixed_values[i] - InputData[i];
        }
        else
            output_values[i] = 0;
        printf("%d ",output_values[i]);
    }
}
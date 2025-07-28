#include <iostream>
#include <stdio.h>
#include <vector>
#include <algorithm>
#include <map>
#include <cmath>

using namespace std;

int main() {
    int input_data_A_x = 0, input_data_A_y = 0, input_data_B_x = 0, input_data_B_y = 0, input_data_C_x = 0, input_data_C_y = 0, result = 0;;

    cin >> input_data_A_x >> input_data_A_y;
    cin >> input_data_B_x >> input_data_B_y;
    cin >> input_data_C_x >> input_data_C_y;


    if (input_data_A_x < 1 || input_data_A_x > 1000 || input_data_A_y < 1 || input_data_A_y > 1000 ||
        input_data_B_x < 1 || input_data_B_x > 1000 || input_data_B_y < 1 || input_data_B_y > 1000 ||
        input_data_C_x < 1 || input_data_C_x > 1000 || input_data_C_y < 1 || input_data_C_y > 1000)
        return 0;//Error

    if ((input_data_A_x != input_data_B_x && input_data_A_x != input_data_C_x && input_data_B_x != input_data_C_x) ||
        (input_data_A_y != input_data_B_y && input_data_A_y != input_data_C_y && input_data_B_y != input_data_C_y))
    {
        return 0;
    }
    int vertical;
    int horizon;
    if (input_data_A_x == input_data_B_x)
        vertical = input_data_C_x;
    else if (input_data_A_x == input_data_C_x)
        vertical = input_data_B_x;
    else
        vertical = input_data_A_x;

    if (input_data_A_y == input_data_B_y)
        horizon = input_data_C_y;
    else if (input_data_A_y == input_data_C_y)
        horizon = input_data_B_y;
    else
        horizon = input_data_A_y;
    

    cout << vertical << " " << horizon;

   
    return 0;
}
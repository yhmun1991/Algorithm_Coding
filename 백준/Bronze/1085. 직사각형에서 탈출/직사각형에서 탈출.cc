#include <iostream>
#include <stdio.h>
#include <vector>
#include <algorithm>
#include <map>
#include <cmath>

using namespace std;

int main() {
    int input_data_A = 0, input_data_B = 0, input_data_C = 0, input_data_D = 0, result = 0;;
    
    cin >> input_data_A >> input_data_B >> input_data_C >> input_data_D;
    

    if (input_data_A < 1 || input_data_A > input_data_C -1 || input_data_B < 1 || input_data_B > input_data_D -1
        || input_data_C < 1 || input_data_C > 1000 || input_data_D < 1 || input_data_D > 1000)
        return 0;//Error
    int vertical = input_data_C-input_data_A > input_data_A-0 ? input_data_A - 0 : input_data_C - input_data_A;
    int horizon = input_data_D - input_data_B > input_data_B - 0 ? input_data_B - 0 : input_data_D - input_data_B;

    cout << (vertical > horizon ? horizon : vertical);

   
    return 0;
}
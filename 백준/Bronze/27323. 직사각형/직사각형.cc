#include <iostream>
#include <stdio.h>
#include <vector>
#include <algorithm>
#include <map>
#include <cmath>

using namespace std;

int main() {
    int input_data_A = 0, input_data_B = 0, result = 0;;
    
    cin >> input_data_A;
    cin >> input_data_B;

    if (input_data_A < 1 || input_data_A > 100 || input_data_B < 1 || input_data_B > 100)
        return 0;//Error
    cout << input_data_A * input_data_B;

   
    return 0;
}
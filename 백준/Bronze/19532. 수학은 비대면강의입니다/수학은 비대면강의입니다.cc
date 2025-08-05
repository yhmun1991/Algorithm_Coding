#include <iostream>
#include <stdio.h>
#include <vector>
#include <algorithm>
#include <map>
#include <cmath>
#include <set>

using namespace std;

int main() {
    int input_data_A = 0, input_data_B = 0, input_data_C = 0, input_data_D = 0, input_data_E = 0, input_data_F = 0, x = 0, y = 0;
    
    cin >> input_data_A>> input_data_B >> input_data_C >> input_data_D >> input_data_E >> input_data_F;

    if (input_data_A < -999 || input_data_A > 999 ||
        input_data_B < -999 || input_data_B > 999 || 
        input_data_C < -999 || input_data_C > 999 || 
        input_data_D < -999 || input_data_D > 999 || 
        input_data_E < -999 || input_data_E > 999 || 
        input_data_F < -999 || input_data_F > 999) {
        return 0;//Error
    }

    for (int i = -999; i <= 999; i++)
    {
        for (int j = -999; j <= 999; j++)
        {
            if ((input_data_A * i + input_data_B*j == input_data_C) &&
                (input_data_D * i + input_data_E*j == input_data_F)) {
                cout << i << ' ' << j;
                return 0;
            }
        }
    }
    return 0;
}
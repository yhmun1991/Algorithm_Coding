#include <iostream>
#include <stdio.h>
#include <vector>
#include <algorithm>
#include <map>
#include <cmath>
#include <set>

using namespace std;

int main() {
    int input_data_A_1 = 0, input_data_A_2 = 0, input_data_B = 0, input_data_C = 0, result = 0;

    cin >> input_data_A_1 >> input_data_A_2;
    cin >> input_data_B;
    cin >> input_data_C;

    if (abs(input_data_A_1) > 100 || abs(input_data_A_1) > 100)
        return 0;
    if (input_data_B < 1 || input_data_B > 100)
        return 0;
    if (input_data_C < 1 || input_data_C > 100)
        return 0;

    
    for (int i = input_data_C; i <= 100; i++) {
        bool ret =( input_data_A_1 * i + input_data_A_2) <= (input_data_B * i);
        if (!ret)
        {
            cout << "0";
            return 0;
        }
    }

    cout << "1";
    return 0;
}
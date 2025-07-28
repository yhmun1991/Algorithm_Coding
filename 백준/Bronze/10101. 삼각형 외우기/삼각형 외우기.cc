#include <iostream>
#include <stdio.h>
#include <vector>
#include <algorithm>
#include <map>
#include <cmath>
#include <set>

using namespace std;

int main() {
    int input_data_A = 0, input_data_B = 0, input_data_C = 0, result = 0;;

    cin >> input_data_A;
    cin >> input_data_B;
    cin >> input_data_C;

    if (input_data_A < 0 || input_data_A > 180 || input_data_B < 0 || input_data_B > 180 || input_data_C < 0 || input_data_C > 180) {
        return 0; //Error
    }

    int sum = input_data_A + input_data_B + input_data_C;
    if (sum != 180)
        cout << "Error";
    else
    {
        if ((input_data_A == input_data_B) && (input_data_C == input_data_A))
            cout << "Equilateral";
        else if (input_data_A - input_data_B == 0 || input_data_A - input_data_C == 0 || input_data_B - input_data_C == 0)
            cout << "Isosceles";
        else
        {
            cout << "Scalene";
        }
    }   
    return 0;
}
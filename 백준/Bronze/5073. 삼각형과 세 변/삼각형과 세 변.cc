#include <iostream>
#include <stdio.h>
#include <vector>
#include <algorithm>
#include <map>
#include <cmath>
#include <set>

using namespace std;

int main() {
    int input_data_A = 0, input_data_B = 0, input_data_C = 0;
    vector<string> result;
    while (true)
    {
        cin >> input_data_A>> input_data_B>> input_data_C;
        if (input_data_A < 0 || input_data_A > 1000 || input_data_B < 0 || input_data_B > 1000 || input_data_C < 0 || input_data_C > 1000) {
            return 0; //Error
        }
        if (input_data_A == 0 && input_data_B == 0 && input_data_C == 0)
            break;

        
        if(input_data_A + input_data_B <= input_data_C || input_data_B + input_data_C <= input_data_A || input_data_A + input_data_C <= input_data_B)
            result.push_back("Invalid");
        else if (input_data_A == input_data_B && input_data_A == input_data_C) {
            result.push_back("Equilateral");
        }
        else if(input_data_A == input_data_B || input_data_A == input_data_C || input_data_B == input_data_C)
        {
            result.push_back("Isosceles");
        }
        else
        {
            result.push_back("Scalene");
        }
    }
    for (auto a : result)
        cout << a<<endl;
    return 0;
}
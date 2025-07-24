#include <iostream>
#include <stdio.h>
#include <vector>
#include <algorithm>
#include <map>
#include <cmath>

using namespace std;

int main() {
    int input_data_A = 0, input_data_B = 0, count = 0;;
    vector<int> input_data;


    cin >> input_data_A;
    if (input_data_A > 100 || input_data_A < 1)
        return 0;//Error
    for (int i = 0; i < input_data_A; i++)
    {
        cin >> input_data_B;
        if (input_data_B < 1 || input_data_B > 1000)
            return 0;//Error
        input_data.push_back(input_data_B);
    }
    
    for (auto a : input_data)
    {
        vector<int> factor;
        if (a == 1) {
            count++;
            continue;
        }
        for (int i = 2; i < a; i++)
        {
            if (a % i == 0) {
                count++;
                break;
            }
        }
    }
    cout << input_data.size() - count;
    return 0;
}
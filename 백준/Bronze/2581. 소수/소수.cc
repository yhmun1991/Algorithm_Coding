#include <iostream>
#include <stdio.h>
#include <vector>
#include <algorithm>
#include <map>
#include <cmath>

using namespace std;

int main() {
    int input_data_A = 0, input_data_B = 0, Sum = 0;;
    vector<int> input_data;


    cin >> input_data_A >> input_data_B;
    if (input_data_A > 10000 || input_data_A < 1 || input_data_B > 10000 || input_data_B < 1||input_data_A > input_data_B)
        return 0;//Error
    
    for (int i = input_data_A; i < input_data_B+1; i++)
    {
        bool ret = true;
        if (i == 1)
            continue;
        for (int j = 2; j < i; j++)
        {
            if (i % j == 0) {
                ret = false;
                break;
            }
        }
        if (ret) {
            Sum += i;
            input_data.push_back(i);
        }
    }
    if (Sum == 0)
        cout << -1;
    else
        cout << Sum << endl << input_data.at(0);
    return 0;
}
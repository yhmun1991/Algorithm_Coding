#include <iostream>
#include <stdio.h>
#include <vector>
#include <algorithm>
#include <map>
#include <cmath>
#include <set>

using namespace std;

int main() {
    int input_data_A = 0, input_data_B = 0, count = 0, tmp = 0;
    cin >> input_data_A;

    if (input_data_A < 3 || input_data_A > 5000) {
        return 0;//Error
    }
    input_data_B = input_data_A;
    if (input_data_B % 5 == 0) {
        cout << input_data_B / 5;
        return 0;
    }
    else {
        count = 1;
        input_data_B = input_data_B - 3;
        while (true) {
            if (input_data_B < 0) {
                cout << -1;
                return 0;
            }
            if (input_data_B % 5 == 0)
            {
                cout << (input_data_B / 5) + count;
                return 0;
            }
            else
            {
                count++;
                input_data_B = input_data_B -3;
            }
            
        }
    }
    

    return 0;
}
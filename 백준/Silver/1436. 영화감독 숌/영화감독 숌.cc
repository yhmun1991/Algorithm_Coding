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

    if (input_data_A < 0 || input_data_A > 10000) {
        return 0;//Error
    }
    input_data_B = 666;
    while (true) {
        int continue666=0;
        bool return_count = false;
        tmp = input_data_B;
        while (true)
        {
            if (tmp <= 0)
                break;
            if (tmp % 10 == 6) {
                continue666++;
                if (continue666 == 3) {
                    return_count = true;
                    break;
                }
            }
            else
            {
                continue666 = 0;
            }
            tmp = tmp / 10;
        }
        if (return_count)
            count++;
        if (count == input_data_A) {
            cout << input_data_B;
            return 0;
        }
        input_data_B++;
   }

    return 0;
}
#include <iostream>
#include <stdio.h>
#include <vector>
#include <algorithm>
#include <map>
#include <cmath>

using namespace std;

int main() {
    long long input_data_A = 0, result = 0;;

    cin >> input_data_A;

    if (input_data_A < 1 || input_data_A > 1000000000)
        return 0;//Error

    cout << input_data_A * 4;

   
    return 0;
}
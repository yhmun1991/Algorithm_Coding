#include <iostream>
#include <stdio.h>
#include <vector>
#include <algorithm>
#include <map>
#include <cmath>

using namespace std;

int main() {
    int input_count = 0, distance = 0, out_data = 0;
    cin >> input_count;
    if (input_count < 1 || input_count > 100000000)
        return 0;//Error
    do
    {
        distance++;
        input_count = input_count - distance;
    }while (input_count > 0);

    input_count = input_count + distance;

    bool even = distance % 2 == 1 ? 0 : 1;
    out_data = distance - input_count + 1;
    if (even) {
        cout << input_count << "/" << out_data;
    }
    else
    {
        cout << out_data <<"/"<< input_count;
    }
    return 0;
}
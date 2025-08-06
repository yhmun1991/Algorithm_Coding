#include <iostream>
#include <stdio.h>
#include <vector>
#include <algorithm>
#include <map>
#include <cmath>
#include <set>

using namespace std;

int main() {
    int input_data_A = 0, input_data_B = 0, Sum = 0, tmp = 0;
    vector<int> data;
    cin >> input_data_A;

    if (input_data_A < 0 || input_data_A > 1000000) {
        return 0;//Error
    }
    for (int i = 1; i < input_data_A; i++)
    {
        Sum = 0;
        tmp = i;
        while (tmp > 0) {
            Sum = Sum + (tmp % 10);
            tmp = tmp / 10;
        }
        if (i + Sum == input_data_A)
        {
            data.push_back(i);
        }
    }

    if (data.empty())
    {
        cout << '0';
    }
    else
    {
        cout << data.at(0);
    }
    return 0;
}
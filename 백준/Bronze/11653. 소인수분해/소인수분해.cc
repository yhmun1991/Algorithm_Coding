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
    cin >> input_data_A;
    if (input_data_A <= 1 || input_data_A > 10000000)
        return 0;//Error
    if (input_data_A == 2)
    {
        cout << input_data_A;
        return 0;//Find 2
    }

    int compare_data= input_data_A;
    for (int i = 2; i <= (int)sqrt(compare_data); i++)
    {
        while (compare_data%i==0)
        {
            input_data.push_back(i);
            compare_data = compare_data / i;
        }
    }
    if (compare_data > 1) {
        input_data.push_back(compare_data);
    }

    for(auto a : input_data)
        cout << a << endl;
    return 0;
}
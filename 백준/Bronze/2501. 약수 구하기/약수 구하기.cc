#include <iostream>
#include <stdio.h>
#include <vector>
#include <algorithm>
#include <map>
#include <cmath>

using namespace std;

int main() {
    int input_data_A = 0, input_data_B = 0, count = 0;;
    vector<int> result_int;
    cin >> input_data_A >> input_data_B;
    if (input_data_A<1 || input_data_A > 10000 || input_data_B <1 || input_data_B > input_data_A)
        return 0;
    
    for (int i = 1; i < input_data_A+1; i++)
    {
        if (input_data_A % i == 0) {
            result_int.push_back(i);
            count++;
        }
    }
    sort(result_int.begin(), result_int.end());

    if (input_data_B > count)
        cout << "0";
    else
        cout << result_int.at(input_data_B-1);
    return 0;
}
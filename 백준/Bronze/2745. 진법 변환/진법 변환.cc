#include <iostream>
#include <stdio.h>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

int main() {
    string input_data;
    int positional_numeral_systems, result_data=0;

    cin >> input_data >> positional_numeral_systems;
    if (positional_numeral_systems > 36 || positional_numeral_systems < 2)
        return 0; //Error

    for (char c : input_data) {
        if (!((c >= '0' && c <= '9') || (c >= 'A' && c <= 'Z')))
            return 0; //Error
    }
    int strlengh = input_data.length();
    for (int i = 0; i < strlengh; i++)
    {
        int multi = 1, num=0;
        for (int j = 1; j < strlengh - i; j++)
        {
            multi = multi * positional_numeral_systems;
        }
        num = input_data[i] - '0';
        result_data += num > 9 ? (static_cast<int>(input_data[i]) - 55) * multi : num * multi;
    }
    cout << result_data;
 
    return 0;
}
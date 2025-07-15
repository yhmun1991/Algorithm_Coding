#include <iostream>
#include <stdio.h>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

int main() {
    int positional_numeral_systems, input_data, remainder = 0, multi = 1;
    bool ret = true;
    string result_data = "";
    cin >> input_data >> positional_numeral_systems;
    if (positional_numeral_systems > 36 || positional_numeral_systems < 2)
        return 0; //Error

    if (input_data > 1000000000)
        return 0; //Error


    do {
        char c = (input_data % positional_numeral_systems) > 9 ? (input_data % positional_numeral_systems) + 55 : (input_data % positional_numeral_systems) + '0';
        result_data.push_back(c);
        input_data = input_data / positional_numeral_systems;
    } while (input_data > 0);
    
    reverse(result_data.begin(), result_data.end());
    cout << result_data;
 
    return 0;
}
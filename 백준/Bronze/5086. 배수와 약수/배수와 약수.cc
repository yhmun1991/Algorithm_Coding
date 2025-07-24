#include <iostream>
#include <stdio.h>
#include <vector>
#include <algorithm>
#include <map>
#include <cmath>

using namespace std;

int main() {
    int input_data_A = 0, input_data_B = 0, input_count = 0;;
    vector<string> result_str;
    do {
        cin >> input_data_A >> input_data_B;
        if (input_data_A == 0 && input_data_B == 0)
            break;
        if (input_data_A % input_data_B == 0)
            result_str.push_back("multiple");
        else if (input_data_B % input_data_A == 0)
            result_str.push_back("factor");
        else
            result_str.push_back("neither");
    } while (true);
    for(string str : result_str)
        cout << str<<endl;
    return 0;
}
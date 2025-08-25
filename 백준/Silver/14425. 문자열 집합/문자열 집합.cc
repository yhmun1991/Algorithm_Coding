#include <iostream>
#include <stdio.h>
#include <vector>
#include <algorithm>
#include <map>
#include <cmath>
#include <set>
#include <string>
#include <cctype>

#define CHAR_OFFSET 48
using namespace std;
struct linkedlist
{
    int* pre;
    int value;
    int* tail;
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int input_data_A, input_data_B, count=0;
    set<string> vec_string;
    pair < set<string>::iterator, bool> result;

    cin >> input_data_A >> input_data_B;

    if (input_data_A < 1 || input_data_A > 10'000 || input_data_B < 1 || input_data_B > 10'000)
        return 0;

    for (int i = 0; i < input_data_A; i++) {
        string temp_data;
        cin >> temp_data;

        if (temp_data.size() <= 0 || temp_data.size() > 500 ||
            !(all_of(temp_data.begin(), temp_data.end(), [](char c) {return islower(c); })))
            return 0;

        vec_string.insert(temp_data);

    }

    for (int i = 0; i < input_data_B; i++) {
        string temp_data;
        cin >> temp_data;
        
        if (temp_data.size() <= 0 || temp_data.size() > 500 ||
            !(all_of(temp_data.begin(), temp_data.end(), [](char c) {return islower(c);})))
            return 0;

        
        if (vec_string.count(temp_data))
            count++;
    }
    
    cout << count;
    return 0;
}
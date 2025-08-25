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

    //map<string, set<string>> map_data;
    set<string, greater<string>> name;
    int input_data_A;
    
    

    cin >> input_data_A;

    if (input_data_A < 2 || input_data_A > 1'000'000)
        return 0;

    for (int i = 0; i < input_data_A; i++) {
        string key, values;
        cin >> values >> key;

        if (key == "enter")
            name.insert(values);
        else if(key == "leave")
            name.erase(values);

    }
    

    for (auto it = name.begin(); it != name.end(); it++) {
        cout << *it << "\n";
    }
    
    return 0;
}
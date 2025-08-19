#include <iostream>
#include <stdio.h>
#include <vector>
#include <algorithm>
#include <map>
#include <cmath>
#include <set>
#include <string>

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

    int input_data_A;
    map<int, set<int>> map_data;
    
    cin >> input_data_A;

    if (input_data_A < 1 || input_data_A > 100000)
        return 0;

    for (int i = 0; i < input_data_A; i++)
    {
        int key, value;
        cin >> key >> value;
        if (key < -100000 || key > 100000 || value < -100000 || value > 100000)
            return 0;
        map_data[key].insert(value);
    }

    for (auto& a : map_data) {
        //cout << vec_input[a] << "\n";
        for (auto b : a.second)
        {
            cout << a.first << ' ' << b << '\n';
        }

    }
    return 0;
}
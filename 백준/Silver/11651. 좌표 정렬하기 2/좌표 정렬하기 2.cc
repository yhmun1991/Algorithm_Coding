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
    vector<pair<int, int>> vector_data;
    
    cin >> input_data_A;

    if (input_data_A < 1 || input_data_A > 100000)
        return 0;

    for (int i = 0; i < input_data_A; i++)
    {
        pair<int, int> key;
        cin >> key.second >> key.first;
        if (key.first < -100000 || key.first > 100000 || key.second < -100000 || key.second > 100000)
            return 0;
        vector_data.push_back(key);
    }
    sort(vector_data.begin(), vector_data.end(), [](auto& a, auto& b) {
        if (a.first == b.first)
            return a.second < b.second;
        return a.first < b.first;
        });
    for (auto& a : vector_data) {
        cout << a.second << ' ' << a.first << '\n';

    }
    return 0;
}
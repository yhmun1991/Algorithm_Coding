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
    vector<string> vector_data;
    
    cin >> input_data_A;

    if (input_data_A < 1 || input_data_A > 20000)
        return 0;

    for (int i = 0; i < input_data_A; i++)
    {
        string temp;
        cin >> temp;
        if (temp.size() > 50)
            return 0;
        vector_data.push_back(temp);
    }
    sort(vector_data.begin(), vector_data.end(), [](auto& a, auto& b) {
        if (a.size() == b.size())
            return a < b;
        return a.size() < b.size();
        });

    vector_data.erase(unique(vector_data.begin(), vector_data.end()), vector_data.end());

    for (auto& a : vector_data) {
        cout << a << '\n';

    }
    return 0;
}
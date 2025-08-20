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

    if (input_data_A < 1 || input_data_A > 1'000'000)
        return 0;

    int count = 0;
    for (int i = 0; i < input_data_A; i++)
    {
        pair<int, int> temp;
        cin >> temp.first;
        temp.second = count;
        count++;
        vector_data.push_back(temp);
    }
  
    sort(vector_data.begin(), vector_data.end());

    int result_value = 0;
    vector<int> output_data(vector_data.size());
    for (int j = 0; j < input_data_A; j++) {
        if (j == 0)
        {
            output_data[vector_data[j].second] = result_value;
            continue;
        }
        if (vector_data[j].first != vector_data[j - 1].first) {
            result_value++;
        }
        output_data[vector_data[j].second] = result_value;
    }

    for (auto a : output_data) {
        cout << a << ' ';
    }
    return 0;
}
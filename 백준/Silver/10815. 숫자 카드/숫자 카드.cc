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

    int input_data_A, input_data_B;
    long long offset = 10'000'000;
    long long countingSize = 20'000'001;
    vector<long long> vec_counting(countingSize, 0);
    vector<int> result_data;

    cin >> input_data_A;

    if (input_data_A < 1 || input_data_A > 500'000)
        return 0;

    for (int i = 0; i < input_data_A; i++) {
        long long temp_data = 0;
        cin >> temp_data;
        temp_data += offset;
        if (temp_data < 0 || temp_data > 20'000'000)
            return 0;

        vec_counting[temp_data]++;
    }

    cin >> input_data_B;
    if (input_data_B < 1 || input_data_B > 500'000)
        return 0;
    
    for (int i = 0; i < input_data_B; i++) {
        long long temp_data = 0;
        cin >> temp_data;
        temp_data += offset;
        if (temp_data < 0 || temp_data > 20'000'000)
            return 0;

        if (vec_counting[temp_data] > 0)
            result_data.push_back(1);
        else
            result_data.push_back(0);
    }

    for (int i = 0; i < input_data_B; i++)
    {
        cout << result_data[i] << ' ';
    }
  
    
    return 0;
}
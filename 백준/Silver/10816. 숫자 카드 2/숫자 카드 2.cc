#include <iostream>
#include <stdio.h>
#include <vector>
#include <algorithm>
#include <map>
#include <cmath>
#include <set>
#include <string>
#include <cctype>
#include <unordered_map>

#define CHAR_OFFSET 48
using namespace std;
struct linkedlist
{
    int* pre;
    int value;
    int* tail;
};
static int cardsArray[20'000'001];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    //multiset<int> cards;
    
    vector<int> result;

    int input_data_A, input_data_B;
    int offset = 10'000'000;

    cin >> input_data_A;

    if (input_data_A < 1 || input_data_A > 500'000)
        return 0;

    for (int i = 0; i < input_data_A; i++) {
        int temp;
        cin >> temp;
        if (temp < -10'000'000 || temp > 10'000'000)
            return 0;
        cardsArray[temp + offset]++;
    }

    cin >> input_data_B;
    if (input_data_B < 1 || input_data_B > 500'000)
        return 0;

    for (int i = 0; i < input_data_B; i++) {
        int temp;
        cin >> temp;
        if (temp < -10'000'000 || temp > 10'000'000)
            return 0;
        result.push_back(cardsArray[temp+offset]);
    }
    

    for (auto a : result) {
        cout << a << ' ';
    }
    
    return 0;
}
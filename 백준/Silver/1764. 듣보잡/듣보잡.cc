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
#include <unordered_set>

#define CHAR_OFFSET 48
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    //multiset<int> cards;
    
    unordered_set<string> input_name;
    vector<string> result;

    int input_data_A, input_data_B, count = 0;

    cin >> input_data_A >> input_data_B;

    if (input_data_A < 1 || input_data_A > 500'000 || input_data_B < 1 || input_data_B > 500'000)
        return 0;

    for (int i = 0; i < input_data_A; i++) {
        string temp;
        cin >> temp;
        if (temp.length() < 1 || temp.length() > 20)
            return 0;
        input_name.insert(temp);
    }

    for (int i = 0; i < input_data_B; i++) {
        string temp;
        cin >> temp;
        if (temp.length() < 1 || temp.length() > 20)
            return 0;
        auto it = input_name.find(temp);
        if (it != input_name.end()) {
            count++;
            result.push_back(temp);
        }
    }
    cout << count << "\n";

    sort(result.begin(), result.end());
    for (auto a : result) {
        cout << a << "\n";
    }
    
    return 0;
}
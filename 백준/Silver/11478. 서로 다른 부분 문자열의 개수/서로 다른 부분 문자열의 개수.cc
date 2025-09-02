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
#define VALIDFAIL -1
using namespace std;


class InputBase {//입력 클래스 생성
public:
    template<typename T>
    bool Input(int count, vector<T>& inputData, int validOption) {
        for (int i = 0; i < count; ++i) {
            T data;

            cin >> data;

            if (!validCheck(validOption, data, min, max))
                return false;

            inputData.push_back(data);
        }
        return true;
    }

    bool validCheck(int aoption, int adata, int amin, int amax) {
        switch (aoption) {
        case 0: 
            return true;
        default: 
            return true;
        }
    }

    bool validCheck(int aoption, const string& adata, int amin, int amax) {
        switch (aoption) {
        case 0: 
            return true;
        default: 
            return true;
        }
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    //multiset<int> cards;
    unordered_set<string> part_string;
    string input_data_A;
    int result = 0;

    cin >> input_data_A;

    if (all_of(input_data_A.begin(), input_data_A.end(), [](char c) { return islower(c); })==false)
        return 0;
    if (input_data_A.size() < 1 || input_data_A.size() > 1'000)
        return 0;


    for (int i = 1; i < input_data_A.size()+1; i++) {
        string tempstr = input_data_A;
        for (int j = 0; j < input_data_A.size(); j++) {
            string part_c = tempstr.substr(j, i);
            part_string.insert(part_c);
        }
    }
    result = part_string.size();
    cout << result;
    
    return 0;
}
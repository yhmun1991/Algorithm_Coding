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
    
    unordered_set<int> set_input_A, set_input_B;
    int result = 0;

    int input_data_A, input_data_B, count = 0;

    cin >> input_data_A >> input_data_B;

    if (input_data_A < 1 || input_data_A > 200'000 || input_data_B < 1 || input_data_B > 200'000)
        return 0;

    int Sum = 0;
    for (int i = 0; i < input_data_A; i++) {
        int temp;
        cin >> temp;
        if (temp > 100'000'000)
            return 0;
        set_input_A.insert(temp);
    }

    for (int i = 0; i < input_data_B; i++) {
        int temp;
        cin >> temp;
        if (temp > 100'000'000)
            return 0;
        set_input_B.insert(temp);
        auto it = set_input_A.find(temp);
        if (it != set_input_A.end()) {
            count++;
        }
    }
    result = (input_data_A + input_data_B - (count*2));
    cout << result;
    
    return 0;
}
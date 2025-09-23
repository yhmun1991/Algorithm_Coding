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
#include <numeric>

#define CHAR_OFFSET 48
#define VALIDFAIL -1
using namespace std;


class InputBase {//입력 클래스 생성
public:
    template<typename T>
    bool Input(int count, vector<T>& inputData, int validOption, int min, int max) {
        if (count == 0) {
            while (true)
            {
                T data;

                getline(cin, data);

                if (data == ".")
                    break;

                if (!validCheck(validOption, data, min, max))
                    return false;

                inputData.push_back(data);
            }   
        }
        else {
            for (int i = 0; i < count; ++i) {
                T data;

                cin >> data;

                if (!validCheck(validOption, data, min, max))
                    return false;

                inputData.push_back(data);
            }
        }
        
        return true;
    }

    bool validCheck(int aoption, int adata, int amin, unsigned int amax) {
        bool ret = false;
        switch (aoption) {
        case 0:
            if (adata < amin || adata > amax)
                ret = false;
            else
                ret = true;
            break;
        case 1:
            if (adata == 0 || adata < amin || adata > amax)
                ret = false;
            else
                ret = true;
            break;
        default:
            ret = true;
        }

        return ret;
    }
    bool validCheck(int aoption, long long adata, long long amin, long long amax) {
        bool ret = false;
        switch (aoption) {
        case 0:
            if (adata < amin || adata > amax)
                ret = false;
            else
                ret = true;
            break;
        default:
            ret = true;
        }

        return ret;
    }

    bool validCheck(int aoption, const string& adata, int amin, int amax) {
        switch (aoption) {
        case 0:
            return true;
        case 1:
            if (adata.size() < amin || adata.size() > amax)
                return false;
            else
                return true;
        default:
            return true;
        }
    }
};

class process {//처리 클래스
public:
    void run(vector<string>& aindata, vector<string>& outdata) {

        for (int i = 0; i < aindata.size(); i++) {
            bool ret = true;
            for (int j = 0; j < aindata[i].size(); j++) {
                if (aindata[i][j] == '(') {
                    int next = 0;
                    if (!check(aindata[i], '(', ')', j + 1, next)) {
                        ret = false;
                        break;
                    }
                    j = next;
                }
                else if(aindata[i][j] == '[') {
                    int next = 0;
                    if (!check(aindata[i], '[', ']', j + 1, next)) {
                        ret = false;
                        break;
                    }
                    j = next;
                }
                else if(aindata[i][j] == ')' || aindata[i][j] == ']')
                {
                    ret = false;
                    break;
                }
            }
            if (ret)
                outdata.push_back("yes");
            else
                outdata.push_back("no");
        }
    }
    bool check(std::string input, char aOpen, char aClose, int start, int& nextPos) {
        for(int i = start; i < input.size(); i++){
            if (input[i] == aOpen) {
                if (!check(input, aOpen, aClose, i + 1, i))
                    return false;
            }
            else if (input[i] == '(') {
                if (!check(input, '(',')', i + 1, i))
                    return false;
            }
            else if (input[i] == '[') {
                if (!check(input, '[', ']', i + 1, i))
                    return false;
            }
            else if (input[i] == aClose) {
                nextPos = i;               
                return true;
            }
            else if (input[i] == ')' || input[i] == ']') {
                return false;
            }
        }
        return false;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    InputBase class_input;
    process class_process;
    vector<int> count_TestCase, input_count;
    vector<string> input_Data, output_data;
    int min, max, Sum=0;
    min = 1;
    max = 100;

    class_input.Input(0, input_Data, 0, min, max);

    class_process.run(input_Data, output_data);

    for (auto a : output_data)
        cout << a << "\n";

    return 0;
}
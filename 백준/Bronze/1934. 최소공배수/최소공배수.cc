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
    bool Input(int count, vector<T>& inputData, int validOption, int min, int max) {
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
        default: 
            return true;
        }
    }
};

class process {//처리 클래스
public:
    void run(vector<int>& aindata, vector<int>& outdata)
    {
        for (int i = 0; i < aindata.size(); i += 2)
        {
            int bigger, smaller, Sum;
            if (aindata[i] < aindata[i + 1]) {
                bigger = aindata[i + 1];
                smaller = aindata[i];
            }
            else
            {
                smaller = aindata[i + 1];
                bigger = aindata[i];
            }
            Sum = bigger;
            while (bigger%smaller!=0) {
                bigger += Sum;
            }
            outdata.push_back(bigger);
        }
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    InputBase class_input;
    process class_process;
    vector<int> count_TestCase, input_Data, output_data;
    class_input.Input(1, count_TestCase, 0, 1, 1000);

    class_input.Input(count_TestCase[0]*2, input_Data, 0, 1, 45000);

    class_process.run(input_Data,output_data);
    
    for (auto it : output_data)
    {
        cout << it << "\n";
    }
    return 0;
}
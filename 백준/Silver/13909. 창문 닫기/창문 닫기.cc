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
    bool Input(int count, vector<T>& inputData, int validOption, T min, T max) {
        if (count == 0)
        {
            while (true)
            {
                T data;

                cin >> data;
                if (data == 0)
                    break;

                if (!validCheck(validOption, data, min, max))
                    return false;
                inputData.push_back(data);
            }
        }
        else
        {
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

    bool validCheck(int aoption, int adata, int amin, int amax) {
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
        default:
            return true;
        }
    }
};

class process {//처리 클래스
public:
    void run(vector<long long>& aindata, vector<long long>& outdata)
    {
        vector<long long> vec_data, vec_distance;
        long long first, last, Sum, result, tmp_data;
        
        Sum = 1;
        while (true)
        {
            if (Sum * Sum <= aindata[0]) {
                Sum++;
            }
            else
            {
                outdata.push_back(Sum);
                break;
            }
        }
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    InputBase class_input;
    process class_process;
    vector<long long> count_TestCase, input_Data,input_count, output_data;
    long long min, max, count;
    min = 1;
    max = 2'1000'000'000;
    
    class_input.Input(1, input_Data, 0, min, max);

    class_process.run(input_Data, output_data);

    cout << output_data[0]-1;

    return 0;
}
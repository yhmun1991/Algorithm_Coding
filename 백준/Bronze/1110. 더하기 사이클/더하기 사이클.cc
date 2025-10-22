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
        vector<int> vec_data, vec_distance;
        int origin, first, second, count, result, tmp_data;
        
        origin = aindata[0];
        if (origin == 0) {
            outdata.push_back(1);
            return;
        }
        first = origin / 10;
        second = origin % 10;
        count = 0;
        do
        {
            result = first + second;
            result = (second*10) + (result % 10);
            first = result / 10;
            second = result % 10;
            count++;
        } while (origin != result);
        outdata.push_back(count);
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    InputBase class_input;
    process class_process;
    vector<long long> count_TestCase, input_Data, output_data;
    vector<int> vec_data;
    char char_data[5];
    long long min, max, count, temp_count=0, temp2_count=0;
    min = 0;
    max = 99;

    class_input.Input(1, input_Data, 0, min, max);

    class_process.run(input_Data, output_data);

    cout << output_data[0];
  
    return 0;
}
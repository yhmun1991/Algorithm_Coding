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
    void run(vector<int>& aindata, vector<int>& outdata)
    {
        vector<int> vec_data, vec_distance;
        int first, last, Sum, result, tmp_data;
        for (int i = 0; i < aindata.size(); i++)
        {
            Sum = 0;
            if (aindata[i] == 1 || aindata[i] == 2) {
                outdata.push_back(1);
            }
            else {
                first = aindata[i]+1;
                if (first % 2 == 0)
                    first = first + 1;
                last = aindata[i]*2;
                for (int k = first; k <= last; k += 2) {
                    bool ret = true;
                    if (k  == 2 || k < 2)
                        continue;
                    long long count = sqrt(k);
                    for (long long j = 3; j <= count; j = j + 2) {
                        if (k % j == 0) {
                            ret = false;
                            break;
                        }
                    }
                    if (ret)
                        Sum++;
                }
                outdata.push_back(Sum);
            }
            
        }
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    InputBase class_input;
    process class_process;
    vector<int> count_TestCase, input_Data, output_data;
    int min, max;
    min = 0;
    max = 123'457;

    class_input.Input(0, input_Data, 1, min, max);

    class_process.run(input_Data, output_data);

    for (auto a : output_data)
        cout << a << "\n";

    return 0;
}
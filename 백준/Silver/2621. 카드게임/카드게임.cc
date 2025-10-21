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
        int first, last, Sum, result, tmp_data;
        if (aindata[0] == 1 || aindata[0] == 2)
        {
            cout << "2";
            return;
        }

        first = aindata[0] % 2 == 0 ? aindata[0] + 1 : aindata[0];
        for (int i = first; ; i += 2) {
            bool ret = true;
            if (i % 2 == 0 || i < 2)
                continue;
            long long count = sqrt(i);
            for (long long j = 3; j <= count; j = j + 2) {
                if (i % j == 0) {
                    ret = false;
                    break;
                }
            }
            if (ret) {
                string strData = to_string(i);
                int data_size = strData.size();
                int reverse_compare_index = 0, compare_index = 0;
                bool returntrigger = true;
                reverse_compare_index = data_size - 1;
                while (compare_index < reverse_compare_index)
                {
                    if (strData[compare_index] != strData[reverse_compare_index]) {
                        returntrigger = false;
                        break;
                    }
                    compare_index++;
                    reverse_compare_index--;
                    returntrigger = true;
                }
                if (returntrigger)
                {
                    cout << i;
                    return;
                }
            }
        }
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
    int min, max, count, temp_count=0, temp2_count=0;
    min = 1;
    max = 100;

    bool ret;

    for (int i = 0; i < 5; ++i)
    {
        char c;
        int in;
        cin >> c >> in;
        char_data[i] = c;
        vec_data.push_back(in);
    }
    sort(vec_data.begin(), vec_data.end());
    int max_val = vec_data.at(vec_data.size() - 1);
    ret = true;
    for (int i = 0; i < 4; i++)
    {
        if (char_data[i + 1] - char_data[i] != 0)
        {
            ret = false;
            break;
        }
    }
    if (ret) {//색이같을때
        for (int i = 0; i < 4; i++) {
            if (vec_data.at(i + 1) - vec_data.at(i) != 1) {
                cout << max_val + 600;
                return 0;
            }
        }
        cout << max_val + 900;
        return 0;
    }
    else {
        ret = true;
        for (int i = 0; i < 4; i++)
        {
            if (vec_data.at(i + 1) - vec_data.at(i) != 1) {
                ret = false;
                break;
            }
        }
        if (ret) {
            cout << max_val + 500;
            return 0;
        }
    }
    int arrayint[10] = {0,};
    for (int i = 0; i < 5; i++) {
        arrayint[vec_data.at(i)]++;
    }

    for (int i = 1; i < 10; i++)
    {
        if (arrayint[i] == 4)
        {
            cout << i + 800;
            return 0;
        }
        if (arrayint[i] == 3)
        {
            for (int j = i; j < 10; j++)
            {
                if (arrayint[j] == 2) { 
                    cout << (i * 10) + j + 700;
                    return 0;
                }
            }
            cout << i + 400;
            return 0;
        }
        if (arrayint[i] == 2) {
            for (int j = i+1; j < 10; j++)
            {
                if (arrayint[j] == 3) {
                    cout << (j * 10) + i + 700;
                    return 0;
                }
                if (arrayint[j] == 2) {
                    cout << (j * 10) + i + 300;
                    return 0;
                }
            }
            cout << i + 200;
            return 0;
        }
    }
    cout << max_val + 100;
    return 0;
}
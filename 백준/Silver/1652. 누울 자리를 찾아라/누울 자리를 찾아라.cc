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
    int min, max, count, temp_count=0, temp2_count=0;
    min = 1;
    max = 100;

    cin >> count;

    if (count < 1 || count > 100)
        return 0;

    string temp[100];
    string temp2[100];

    for (int i = 0; i < count; ++i)
        temp2[i] = string(count, ' ');

    for (int i = 0; i < count; ++i)
        cin >> temp[i];

    for (int i = 0; i < count; ++i) {
        for (int j = 0; j < count; ++j) {
            temp2[j][i] = temp[i][j];
        }
    }
    if (count == 1)
    {
        cout << "0" << " " << "0";
        return 0;

    }
    for (int i = 0; i < count; i++) {
        size_t start_index = 0, pos = 0;
        if (temp[i].find('X') != string::npos) {
            while ((pos = temp[i].find('X', start_index)) != string::npos) {
                if (temp[i].substr(start_index, pos - start_index).find("..") != string::npos) {
                    temp_count++;
                }
                start_index = pos + 1;
            }
            if (temp[i].substr(start_index, pos - start_index).find("..") != string::npos) {
                temp_count++;
            }
        }
        else
        {
            temp_count++;
        }
        start_index = 0, pos = 0;
        if(temp2[i].find('X') != string::npos) {
            while ((pos = temp2[i].find('X', start_index)) != string::npos) {
                if (temp2[i].substr(start_index, pos - start_index).find("..") != string::npos) {
                    temp2_count++;
                }
                start_index = pos + 1;
            }
            if (temp2[i].substr(start_index, pos - start_index).find("..") != string::npos) {
                temp2_count++;
            }
        }
        else
        {
            temp2_count++;
        }
    }
    cout << temp_count << " "<< temp2_count;
    

    return 0;
}
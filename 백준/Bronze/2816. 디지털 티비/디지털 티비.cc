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
#include <list>


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
    void run(vector<string>& aindata, vector<string>& outdata)
    {
        vector<int> vec_data, vec_distance;
        int origin, first, second, count, result, tmp_data;
        outdata.push_back("");
        list<string> lst(aindata.begin(), aindata.end());
        findTarget(lst, outdata, "KBS1", 0);
        findTarget(lst, outdata, "KBS2", 1);
        
    }

    void findTarget(list<string>& aindata, vector<string>& outdata, string target, int option)
    {
        int index;
        auto it = std::find(aindata.begin(), aindata.end(), target);

        if (it != aindata.end()) {
            index = std::distance(aindata.begin(), it);
        }
        for (int i = 0; i < index; i++)
        {
            outdata[0].push_back('1');
        }
        for (int i = 0; i < index-option; i++)
        {
            outdata[0].push_back('4');
        }
        
        string value = *it;
        aindata.erase(it);
        aindata.push_front(value);
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    InputBase class_input;
    process class_process;
    vector<string> count_TestCase, input_Data, output_data;
    vector<int> vec_data;
    char char_data[5];
    long long min, max, count, temp_count=0, temp2_count=0;
    min = 0;
    max = 99;

    cin >> count;

    class_input.Input(count, input_Data, 0, min, max);

    class_process.run(input_Data, output_data);

    cout << output_data[0];
  
    return 0;
}
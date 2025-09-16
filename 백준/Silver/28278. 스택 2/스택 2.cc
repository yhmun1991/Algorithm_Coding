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
#include <sstream>

#define CHAR_OFFSET 48
#define VALIDFAIL -1
using namespace std;


class InputBase {//입력 클래스 생성
public:
    template<typename T>
    bool Input(int count, vector<T>& inputData, int validOption, int min, int max) {
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

    bool Input_string(int count, vector<string>& inputData, int validOption, int min, int max) {
        if (count == 0)
        {
            while (true)
            {
                string data;

                cin >> data;
                if (data == "")
                    break;

                if (!validCheck(validOption, data, min, max))
                    return false;
                inputData.push_back(data);
            }
        }
        else
        {
            for (int i = 0; i < count; ++i) {
                string data;

                getline(cin, data);

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
    void run(vector<string>& aindata, vector<int>& outdata)
    {
        vector<int> stack;
        long long first, last, Sum, result, tmp_data;
        
        for (int i = 0; i < aindata.size(); i++)
        {
            stringstream ss(aindata[i]);
            vector<int> vec_data;
            int x;
            while (ss >> x) {
                vec_data.push_back(x);
            }
            switch (vec_data[0])
            {
            case 1: {
                stack.push_back(vec_data[1]);
            }
                break;
            case 2: {
                if (stack.empty())
                    outdata.push_back(-1);
                else
                {
                    outdata.push_back(stack.back());
                    stack.pop_back();
                }
            }
                break;
            case 3: {
                outdata.push_back(stack.size());
            }
                break;
            case 4: {
                if (stack.empty())
                    outdata.push_back(1);
                else
                    outdata.push_back(0);
            }
                break;
            case 5: {
                if (stack.empty())
                    outdata.push_back(-1);
                else
                    outdata.push_back(stack.back());
            }
                break;
            default:
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
    vector<int> count_TestCase, input_Data,input_count, output_data;
    vector<string> input_string;
    int min, max, count;
    min = 1;
    max = 1'000'000;
    
    class_input.Input(1, input_count, 0, min, max);
    cin.ignore();
    class_input.Input_string(input_count[0], input_string, 0, 0, 0);

    class_process.run(input_string, output_data);

    for (auto a : output_data)
        cout << a << "\n";

    return 0;
}
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
        long long bigger, bigger_pair, smaller, smaller_pair, Sum, count = 1, result, result_pair;
        if (aindata[1] < aindata[3]) {
            bigger = aindata[3];
            bigger_pair = aindata[2];
            smaller = aindata[1];
            smaller_pair = aindata[0];
        }
        else
        {
            bigger = aindata[1];
            bigger_pair = aindata[0];
            smaller = aindata[3];
            smaller_pair = aindata[2];
        }
        Sum = bigger;
        while (bigger%smaller!=0) {
            bigger += Sum;
            count++;
        }
        result = (bigger_pair * (bigger/Sum)) + (smaller_pair * (bigger / smaller));

        long long tmp_A, tmp_B;
        tmp_A = result;
        tmp_B = bigger;
        while(tmp_A != tmp_B) {
            if (tmp_A < tmp_B)
                tmp_B -= tmp_A;
            else
                tmp_A -= tmp_B;
        }
        result = result / tmp_A;
        bigger = bigger / tmp_B;

        outdata.push_back(result);
        outdata.push_back(bigger);
            
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    InputBase class_input;
    process class_process;
    vector<long long> count_TestCase, input_Data, output_data;
    long long min, max;
    min = 1;
    max = 30000;

    class_input.Input(4, input_Data, 0, min, max);

    class_process.run(input_Data,output_data);
    
    cout << output_data[0] << ' '<<output_data[1];
   
    return 0;
}
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
    void run(vector<int>& aindata, vector<int>& outdata)
    {
        vector<int> vec_data, vec_distance(aindata.size()-1);
        int distance = 1'000'000'000;
        int Sum, result, tmp_data;
        
        for (int i = 0; i < aindata.size() - 1; i++) {
            vec_distance[i] = aindata[i + 1] - aindata[i];
        }

        int add_distance = vec_distance[0];
        for (int i = 0; i < vec_distance.size(); i++)
        {
            int temp_1 = add_distance;
            int temp_2 = vec_distance[i];

            //while (temp_1 != temp_2) {
            //    if (temp_1 > temp_2)
            //        temp_1 = temp_1 - temp_2;
            //    else
            //        temp_2 = temp_2 - temp_1;
            //}
            while (temp_2 != 0)
            {
                int divid = temp_1 % temp_2;
                temp_1 = temp_2;
                temp_2 = divid;
            }
            add_distance = temp_1;
        }
        //while (true)
        //{
        //    bool ret = true;
        //    for (int i = 0; i < vec_distance.size(); i++)
        //    {
        //        if (vec_distance[i] % add_distance != 0) {
        //            ret = false;
        //            break;
        //        }
        //    }
        //    if (ret)
        //        break;
        //    add_distance++;
        //}
        

        result = (((aindata[aindata.size() - 1] - aindata[0]) / add_distance) + 1) - aindata.size();
        cout << result;

    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    InputBase class_input;
    process class_process;
    vector<int> count_TestCase, input_Data, output_data;
    int min, max;
    min = 1;
    max = 1'000'000'000;

    class_input.Input(1, count_TestCase, 0, 3, 100'000);

    class_input.Input(count_TestCase[0], input_Data, 0, min, max);

    class_process.run(input_Data,output_data);
   
    return 0;
}
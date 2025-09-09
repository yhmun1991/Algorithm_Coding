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
        vector<long long> vec_data, vec_distance;
        long long Sum, result, tmp_data;

        //for (int i = 0; i < aindata.size(); i++) {
        //    tmp_data = aindata[i];
        //    if (tmp_data <= 2) {//2보다 작거나 같다면 1,2 둘중 하나이기때문에 소수인 2 출력
        //        outdata.push_back(2);
        //        continue;
        //    }
        //    while (true)
        //    {
        //        bool ret = true;
        //        long long count = sqrt(tmp_data);//반복횟수를 줄이기 위한 루트. 소수를 확인할 반복문은 비교대상의 루트만 씌워도 충분하다
        //        for (long long j = 3; j <= count; j++) {
        //            if (tmp_data % j == 0) {
        //                ret = false;
        //                break;
        //            }
        //        }
        //        if (ret)
        //            break;
        //        tmp_data = tmp_data + 1;
        //    }
        //    outdata.push_back(tmp_data);
        //}
        for (int i = 0; i < aindata.size(); i++) {
            tmp_data = aindata[i];
            if (tmp_data <= 2) {//2보다 작거나 같다면 1,2 둘중 하나이기때문에 소수인 2 출력
                outdata.push_back(2);
                continue;
            }
            if (tmp_data % 2 == 0)
                tmp_data = tmp_data + 1; // 짝수일경우에는 +1을해줘서 홀수로 변환한다.
            while (true)
            {
                bool ret = true;
                long long count = sqrt(tmp_data);
                for (long long j = 3; j <= count; j = j + 2) {
                    if (tmp_data % j == 0) {
                        ret = false;
                        break;
                    }
                }
                if (ret)
                    break;
                tmp_data = tmp_data + 2;
            }
            outdata.push_back(tmp_data);
        }
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    InputBase class_input;
    process class_process;
    vector<long long> count_TestCase, input_Data, output_data;
    long long min, max, count;
    min = 0;
    max = 4'000'000'000;

    cin >> count;

    class_input.Input(count, input_Data, 0, min, max);

    class_process.run(input_Data, output_data);

    for (auto a : output_data)
        cout << a << "\n";

    return 0;
}
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
#include <queue>


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
        for (int i = 0; i < index - option; i++)
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


    int N, K, temp = 0, ret_A = 0, ret_B = 0;

    bool flag_A = true, flag_B = true;
    cin >> N;

    vector<bool> light(N);
    vector<bool> light_B(N);
    vector<bool> resultlight(N);
    vector<bool> resultlight_B(N);
    string num;
    cin >> num;

    for (int i = 0; i < N; i++)
    {
        light[i] = num[i] == '1' ? true : false;
    }
    cin >> num;
    for (int i = 0; i < N; i++)
    {
        resultlight[i] = num[i] == '1' ? true : false;
    }
    light_B = light;
    resultlight_B = resultlight;

    if (N == 1)
    {
        if (light[0] == resultlight[0])
            cout << 0;
        else
            cout << 1;
        return 0;
    }


    ret_A = 1;
    light[0] = !light[0];
    light[1] = !light[1];

    for (int i = 1; i < N; i++)
    {
        if (light[i - 1] == resultlight[i - 1])
            continue;
        else
        {
            ret_A++;
            light[i - 1] = !light[i - 1];
            light[i] = !light[i];
            if (i + 1 < N)
                light[i + 1] = !light[i + 1];
        }
    }
    if (light != resultlight)
        flag_A = false;


    ret_B = 0;
    for (int i = 1; i < N; i++)
    {
        if (light_B[i - 1] == resultlight_B[i - 1])
            continue;
        else
        {
            ret_B++;
            light_B[i - 1] = !light_B[i - 1];
            light_B[i] = !light_B[i];
            if (i + 1 < N)
                light_B[i + 1] = !light_B[i + 1];
        }
    }
    if (light_B != resultlight_B)
        flag_B = false;

    if ((flag_A == false) && (flag_B == false))
        cout << -1;
    else if (flag_A == false)
        cout << ret_B;
    else if (flag_B == false)
        cout << ret_A;
    else
        cout << min(ret_B, ret_A);
}

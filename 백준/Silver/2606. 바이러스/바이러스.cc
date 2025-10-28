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
    vector<unordered_set<int>> vec_data;
    multimap<uint64_t, int> map_data;
    unordered_set<int> set_data;
    char char_data[5];
    long long min, max, count, temp_count=0, temp2_count=0;
    int index, totalcount = 0;
    bool bRet;
    min = 1;
    max = 1000;

    cin >> count >> index;

    if (count < 1 || count > 1000)
        return 0;//Error
    //class_input.Input(count, input_Data, 0, min, max);
    if (index == 0)
    {
        cout << 0;
        return 0;
    }
    for (int i = 1; i <= count; i++)
        set_data.insert(i);
    for (int i = 0; i < index; i++)
    {
        int first, second;
        cin >> first >> second;

        if (set_data.count(first))
            set_data.erase(first);

        
        if (set_data.count(second))
            set_data.erase(second);

        vector<int> vec_index;

        for (int j = 0; j < vec_data.size(); j++) {
            if (vec_data[j].count(first) || vec_data[j].count(second)) {
                vec_index.push_back(j);
            }
        }


        if (vec_index.empty()) {
            vec_data.push_back({ first, second });
        }
        else if (vec_index.size() == 1) {
            vec_data[vec_index[0]].insert(first);
            vec_data[vec_index[0]].insert(second);
        }
        else {
            int index1 = vec_index[0];
            int index2 = vec_index[1];

            vec_data[index1].insert(vec_data[index2].begin(), vec_data[index2].end());
            vec_data.erase(vec_data.begin() + index2);

            vec_data[index1].insert(first);
            vec_data[index1].insert(second);
        }
    }

    for (auto it : vec_data)
    {
        if (it.count(1)) {
            cout << it.size() - 1;
            return 0;
        }
    }
    cout << 0;
  
    return 0;
}
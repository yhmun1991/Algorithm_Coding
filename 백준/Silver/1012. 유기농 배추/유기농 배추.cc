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

    int vertical, horizon, num;
    int count;
    cin >> count;

    for(int temp ; temp < count; temp++){
        cin >> horizon >> vertical >> num;

        bool array_data[50][50] = { false, };

        vector<pair<int, int>> vec_pair_data;
        for (int i = 0; i < num; i++) {
            int x, y;
            cin >> x >> y;
            array_data[y][x] = true;
            vec_pair_data.push_back({ x, y });
        }

        vector<unordered_set<int>> vec_data;
        set<int> set_data;

        int dx[4] = { 1, -1, 0, 0 };
        int dy[4] = { 0, 0, 1, -1 };

        for (auto it : vec_pair_data) {
            int id1 = it.second * horizon + it.first;
            set_data.insert(id1);

            for (int i = 0; i < 4; i++) {
                int nx = it.first + dx[i];
                int ny = it.second + dy[i];
                if (nx >= 0 && nx < horizon && ny >= 0 && ny < vertical
                    && array_data[ny][nx]) {
                    int id2 = ny * horizon + nx;

                    vector<int> vec_index;
                    for (int j = 0; j < vec_data.size(); j++) {
                        if (vec_data[j].count(id1) || vec_data[j].count(id2))
                            vec_index.push_back(j);
                    }

                    if (vec_index.empty()) {
                        vec_data.push_back({ id1, id2 });
                    }
                    else if (vec_index.size() == 1) {
                        vec_data[vec_index[0]].insert(id1);
                        vec_data[vec_index[0]].insert(id2);
                    }
                    else {
                        int i1 = vec_index[0];
                        int i2 = vec_index[1];
                        vec_data[i1].insert(vec_data[i2].begin(), vec_data[i2].end());
                        vec_data.erase(vec_data.begin() + i2);
                        vec_data[i1].insert(id1);
                        vec_data[i1].insert(id2);
                    }
                }
            }
        }

        for (auto it : vec_pair_data) {
            int id = it.second * horizon + it.first;
            bool found = false;
            for (auto s : vec_data) {
                if (s.count(id)) {
                    found = true;
                    break;
                }
            }
            if (!found)
                vec_data.push_back({id});
        }

        cout << vec_data.size() << "\n";
    }

    return 0;
}

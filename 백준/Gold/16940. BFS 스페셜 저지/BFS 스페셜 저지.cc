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

    int N;
    cin >> N;

    vector<vector<int>> origin(N + 1);//양방향으로 받을 벡터 1,3 / 3,1이 나올 수 있다
    vector<int> target_order(N); //입력 받은 비교 할 결과값
    queue<int> queue; //비교하기 위해 넣을 큐
    vector<int> bfs_result; //정답인 순서
    vector<bool> visited(N + 1, false); // 방문여부
    vector<bool> isexist(N + 1, false);
    vector<int> order(N);
    
    //양방향으로 삽입
    for (int i = 0; i < N - 1; i++) {
        int u, v;
        cin >> u >> v;
        origin[u].push_back(v);
        origin[v].push_back(u);
    }

    
    
    for (int i = 0; i < N; i++) {
        cin >> order[i];
    }

    if (order[0] != 1) {
        cout << 0;
        return 0;
    }

    queue.push(1);
    visited[1] = true;

    int idx = 1;


    while (!queue.empty()) {
        int curr = queue.front();
        queue.pop();

        int cnt = 0;

        //child가 몇게인지확인 및 visit 처리
        for (int next : origin[curr]) {
            if (!visited[next]) {
                isexist[next] = true;
                cnt++;
            }
        }

        //다음 child가 맞는지 확인
        for (int i = 0; i < cnt; i++) {
            if (idx + i >= N || !isexist[order[idx + i]]) {
                cout << 0;
                return 0;
            }
        }


        for (int i = 0; i < cnt; i++) {
            int node = order[idx + i];
            visited[node] = true;
            queue.push(node);
        }

        for (int next : origin[curr]) {
            isexist[next] = false;
        }

        idx += cnt;
    }

    cout << 1;//정답
    return 0;
}

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
#include <deque>

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

    bool validCheck(int aoption, int adata, int amin, unsigned int amax) {
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
        case 1:
            if (adata.size() < amin || adata.size() > amax)
                return false;
            else
                return true;
        default:
            return true;
        }
    }
};

class process {//처리 클래스
public:
    void run(vector<int>& aindata, vector<int>& outdata) {
        vector<int> temp;
        int index = 0;
        bool ret = false;
        int compare = 1;
        for (int i = 0; i < aindata.size(); i++)
        {
            if (aindata[i] == compare) {
                compare++;
            }
            else {
                while (!temp.empty() && temp.back() == compare) {
                    temp.pop_back();
                    compare++;
                }
                temp.push_back(aindata[i]);
            }
        }


        while (!temp.empty()) {
            if (temp.back() == compare) {
                temp.pop_back();
                compare++;
            }
            else
            {
                cout << "Sad";
                return;
            }
        }
        cout << "Nice";
        return;
    }
};

class Queue_class {
    deque<int> data;

public:
    void push_back(int x)
    {
        data.push_back(x);
    }
    void push_front(int x)
    {
        data.push_front(x);
    }

    void pop_front()
    {
        if (data.empty())
            cout << -1 << "\n";
        else {
            cout << data.front() << "\n";
            data.pop_front();
        }
    }

    void pop_back()
    {
        if (data.empty())
            cout << -1 << "\n";
        else {
            cout << data.back() << "\n";
            data.pop_back();
        }
    }

    void size()
    {
        cout << data.size() << "\n";
    }

    void empty()
    {
        if (data.empty())
            cout << 1 << "\n";
        else
            cout << 0 << "\n";
    }

    void front()
    {
        if (data.empty())
            cout << -1 << "\n";
        else
            cout << data.front() << "\n";
    }

    void back()
    {
        if (data.empty())
            cout << -1 << "\n";
        else
            cout << data.back() << "\n";
    }
};

using FuncPtr = void (Queue_class::*)();

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    //InputBase IN_put;
    //process PRO_run;
    //int N, K;
    //int arrayint[100];
    //cin >> N >> K;
    //
    //for (int i = 0; i < N; i++)
    //{
    //    int tempA, tempB;
    //    cin >> tempA >> tempB;
    //
    //
    //}
    //int itemscount = items.size();
    //for (int i = 0; i < itemscount; i++)
    //{
    //    for(int j = itemscount; j < i)
    //}
    //
    //int result = M % 2 == 0 ? M/2 : M/2 + 1;

    int N;
    multiset<int> mset;
    multiset<int>::iterator mid;
    cin >> N;
    for (int i = 0; i < N; i++)
    {
        int inputdata, index, setsize;
        cin >> inputdata;
        mset.insert(inputdata);
        setsize = mset.size();
        
        if (setsize == 1) {
            mid = mset.begin();
            cout << *mid << "\n";
            continue;
        }

        if (inputdata < *mid) {
            if (setsize % 2 == 0)
                mid--;
        }
        else
        {
            if (setsize % 2 == 1)
                mid++;
        }
        
        cout << *mid << "\n";
    }

    return 0;
}
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
        bool ret=false;
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
    void push(int x)
    {
        data.push_back(x);
    }

    void pop()
    {
        if (data.empty())
            cout << -1 << "\n";
        else {
            cout << data.front() << "\n";
            data.pop_front();
        }
    }

    void size()
    {
        cout << data.size()<<"\n";
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

    Queue_class Que;
    InputBase class_input;
    process class_process;
    vector<int> count_TestCase, input_count;
    vector<int> input_Data, output_data;
    int min, max, Sum=0, count;
    min = 1;
    max = 1000;

    map<string, FuncPtr> command_Map;
    command_Map["pop"] = &Queue_class::pop;
    command_Map["size"] = &Queue_class::size;
    command_Map["empty"] = &Queue_class::empty;
    command_Map["front"] = &Queue_class::front;
    command_Map["back"] = &Queue_class::back;

    //class_input.Input(1,input_count, 0, min, max);

    //class_input.Input(input_count[0], input_Data, 0, 1, input_count[0]);

    //class_process.run(input_Data, output_data);
    cin >> count;
    for (int i = 0; i < count; i++)
    {
        string command;
        cin >> command;
        if (command == "push")
        {
            int temp;
            cin >> temp;
            Que.push(temp);
        }
        else
        {
            (Que.*command_Map[command])();
        }
    }

    return 0;
}
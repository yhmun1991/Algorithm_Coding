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
#include <list>

using namespace std;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    list<int> data;
    vector<int> count_TestCase, input_count;
    vector<int> input_Data, output_data;
    int min, max, Sum=0, count, total;
    min = 1;
    max = 1000;

    cin >> total >> count;
    for (int i = 1; i <= total; i++)
    {
        data.push_back(i);
    }
    int startpoint = 0;
    int datasize = 0;
    while (data.size()>0)
    {
        datasize = data.size();
        auto it =  data.begin();

        int moveindex = (count - 1) % datasize;
        advance(it, moveindex);
        data.splice(data.end(), data, data.begin(), it);
        
                
        output_data.push_back(data.front());
        data.pop_front();
    }
    cout << "<";
    for (int i = 0; i < output_data.size(); i++) {
        if (i + 1 < output_data.size()) {
            cout << output_data[i] << ", ";
        }
        else
        {
            cout << output_data[i];
        }
    }
        
    cout << ">";
    return 0;
}
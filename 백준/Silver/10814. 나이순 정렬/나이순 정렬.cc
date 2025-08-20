#include <iostream>
#include <stdio.h>
#include <vector>
#include <algorithm>
#include <map>
#include <cmath>
#include <set>
#include <string>

#define CHAR_OFFSET 48
using namespace std;
struct linkedlist
{
    int* pre;
    int value;
    int* tail;
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int input_data_A;
    multimap<int, string> map_data;
    
    cin >> input_data_A;

    if (input_data_A < 1 || input_data_A > 100'000)
        return 0;

    for (int i = 0; i < input_data_A; i++)
    {
        int key;
        string temp;
        cin >> key >> temp;
        if (key < 1 || key > 200 || temp.size() > 200 || temp.size() < 1)
            return 0;
        map_data.insert({key,temp});
    }
  
    for (auto& a : map_data) {
        cout << a.first << ' '<< a.second << '\n';

    }
    return 0;
}
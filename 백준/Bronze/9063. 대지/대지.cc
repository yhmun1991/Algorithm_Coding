#include <iostream>
#include <stdio.h>
#include <vector>
#include <algorithm>
#include <map>
#include <cmath>
#include <set>

using namespace std;

int main() {
    int input_data = 0, result = 0;;
    set<int> set_x;
    set<int> set_y;

    cin >> input_data;

    if (input_data < 1 || input_data > 100000)
        return 0;//Error

    for (int i = 0; i < input_data; i++) {
        pair<int,int> tempdata;
        cin >> tempdata.first >> tempdata.second;
        if (tempdata.first < -10000 || tempdata.first > 10000 || tempdata.second < -10000 || tempdata.second > 10000)
            return 0;//Error
        set_x.insert(tempdata.first);
        set_y.insert(tempdata.second);
    }
    int min_x = *set_x.begin();
    int max_x = *prev(set_x.end());
    int min_y = *set_y.begin();
    int max_y = *prev(set_y.end());

    cout << (max_x - min_x) * (max_y - min_y);
   
    return 0;
}
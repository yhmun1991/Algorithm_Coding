#include <iostream>
#include <stdio.h>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

int main() {
    map<int, int> int_map;
    int maxium_value = -1, input_data = 0, index = 0;

    for (int i = 1; i < 82; i++){
        cin >> input_data;
        if (!(0 <= input_data < 100))
            return 0;
        int_map[i] = input_data;
    }
    for (auto auto_map : int_map)
    {
        if (auto_map.second > maxium_value)
        {
            maxium_value = auto_map.second;
            index = auto_map.first;
        }
    }

    cout << maxium_value << "\n";

    int row = (index - 1) / 9 + 1;
    int col = (index - 1) % 9 + 1;
    cout << row << " " << col;

    return 0;
}
#include <iostream>
#include <stdio.h>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

int main() {
    int input_count = 0;
    vector<int> change;
    cin >> input_count;
    if (input_count < 1)
        return 0; //Error
    for (int i = 0; i < input_count; i++) {
        int tmp;
        cin >> tmp;
        if (tmp < 1 || tmp > 500)
            return 0;//Errror
        change.push_back(tmp);
    }
    for (auto a : change) {
        cout << a / 25 << " ";
        a = a % 25;
        cout << a / 10 << " ";
        a = a % 10;
        cout << a / 5 << " ";
        a = a % 5;
        cout << a;
        cout << "\n";
    }
 
    return 0;
}
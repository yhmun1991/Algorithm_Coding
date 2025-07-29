#include <iostream>
#include <stdio.h>
#include <vector>
#include <algorithm>
#include <map>
#include <cmath>
#include <set>

using namespace std;

int main() {
    long long input_data = 0,  result = 0;

    cin >> input_data;

    for (long long i = 1; i <= input_data - 2; i++) {
        result = result + i * ((input_data - 1) - i);
    }

    cout << result <<endl;
    cout << 3;
    return 0;
}
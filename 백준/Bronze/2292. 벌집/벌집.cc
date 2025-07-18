#include <iostream>
#include <stdio.h>
#include <vector>
#include <algorithm>
#include <map>
#include <cmath>

using namespace std;

int main() {
    int input_count = 0, distance = 1;
    cin >> input_count;
    if (input_count < 1 || input_count > 1000000000)
        return 0;//Error
    if (input_count == 1)
    {
        cout << 1;
        return 0;
    }
    input_count = input_count - 1;
    while (input_count > 0)
    {
        input_count = input_count - (6 * distance);
        distance++;
    } 

    cout << distance;

    return 0;
}
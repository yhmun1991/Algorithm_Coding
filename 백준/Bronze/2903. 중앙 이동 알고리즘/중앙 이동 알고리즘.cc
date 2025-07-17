#include <iostream>
#include <stdio.h>
#include <vector>
#include <algorithm>
#include <map>
#include <cmath>

using namespace std;

int main() {
    int input_count = 0;
    int array[15];
    cin >> input_count;
    if (input_count < 1 || input_count > 15)
        return 0;//Error
    array[0] = 4;
    for (int i = 1; i < input_count+1; i++)
    {
        array[i] = pow(sqrt(array[i - 1]) + pow(2,i-1), 2);

    }
    cout << array[input_count];

    return 0;
}
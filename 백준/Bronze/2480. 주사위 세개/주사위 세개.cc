#include <iostream>
#include <stdio.h>

using namespace std;

int main() {
    int input_first, input_second, input_third, sum;
    cin >> input_first >> input_second >> input_third;

    if (input_first < 1 || input_first > 6 ||
        input_second < 1 || input_second > 6 ||
        input_third < 1 || input_third > 6) {
        return 0; // 에러
    }

    if (input_first == input_second && input_second == input_third) {
        cout << 10000 + input_first * 1000;
    }
    else if (input_first == input_second || input_first == input_third) {
        cout << 1000 + input_first * 100;
    }
    else if (input_second == input_third) {
        cout << 1000 + input_second * 100;
    }
    else {
        int sum = input_first;
        if (input_second > sum)
            sum = input_second;
        if (input_third > sum)
            sum = input_third;
        cout << sum * 100;
    }

    return 0;
}
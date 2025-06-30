#include <iostream>
#include <stdio.h>

using namespace std;

int main()
{
    int  quotient = 0, remainder = 0, input_first = 0, input_second = 0, digit = 0;
    char result[40];

    cin >> input_first >> input_second;

    if (input_first > 9 || input_second > 9 || input_second == 0)
        return 0; //Error
    quotient = input_first / input_second;
    remainder = input_first % input_second;

    result[0] = quotient + '0';
    result[1] = '.';
    
    for (int i = 2; i < sizeof(result); i++) {
        if (remainder == 0) {
            result[i] = '\0';
            break;
        }
        remainder = remainder * 10;
        digit = remainder / input_second;
        result[i] = digit + '0';
        remainder = remainder % input_second;
        if (i == sizeof(result)-1)
            result[i] = '\0';
    }

    cout << result << endl;
    return 0;

}
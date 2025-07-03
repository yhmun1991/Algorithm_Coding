#include <iostream>
#include <stdio.h>

using namespace std;

int main() {
    string input_string = { 0, };
    int alphabet_count = 0;
    
    cin >> input_string;
    if (input_string.size() > 100)
        return 0; //에러

    for (char s : input_string)
    {
        if (!(islower(s) || s == '-' || s == '='))
            return 0; //에러
    }

    for (int i = 0; i < input_string.size(); i++)
    {
        switch (input_string[i])
        {
        case 'c':
        case 'z':
        case 's':
        {
            if ((i < input_string.size() - 1)&&(input_string[i+1]=='-' || input_string[i + 1] == '='))
                i++;
            alphabet_count++;
        }break;
        case 'd':
        {
            if ((i < input_string.size() - 2) && input_string[i + 1] == 'z') {
                if (input_string[i + 2] == '=')
                    i = i + 2;
            }
            else if (i < input_string.size() - 1 && input_string[i + 1] == '-')
                i++;
            alphabet_count++;
        }break;
        case 'l':
        case 'n':
        {
            if (i < input_string.size() - 1 && input_string[i + 1] == 'j')
                i++;
            alphabet_count++;
        }break;
        default:
            alphabet_count++;
            break;
        }
    }
    
    cout << alphabet_count;
    return 0;
}
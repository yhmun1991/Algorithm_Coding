#include <iostream>
#include <stdio.h>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    vector<string> input_string ;
    int input_count = 0, group_count = 0;
    bool ret = false;
    
    cin >> input_count;

    if (input_count >= 100 || input_count < 0)
        return 0; //에러

    for (int i = 0 ; i < input_count; i++)
    {
        string temp_string;
        vector<char> pre_alpabat;
        char cmp_data = ' ';

        cin >> temp_string;
        if (find(input_string.begin(), input_string.end(), temp_string) != input_string.end())
            return 0; // 중복된 문자열
        input_string.push_back(temp_string);
        ret = true;
        for (char ch : temp_string)
        {
            if (ch < 'a' || ch > 'z')
                return 0;
            if (ch != cmp_data) {
                if (find(pre_alpabat.begin(), pre_alpabat.end(), ch) != pre_alpabat.end())
                {
                    ret = false;
                    break;
                }
                else
                {
                    cmp_data = ch;
                    pre_alpabat.push_back(ch);
                }
            }
        }
        if (ret)
            group_count++;   
    }

    cout << group_count;


    return 0;
}
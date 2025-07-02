#include <iostream>
#include <stdio.h>
#include <map>

using namespace std;

int main() {
    string input_string = { 0, };
    map<char, int> result_data;
    int maxiam_count=0;
    char maxiam_data;
    
    cin >> input_string;
    if (input_string.size() > 1000000)
        return 0; //에러

    for (char s : input_string)
    {
        if (s < 'A' || s > 'z')
            return 0; //에러

        char upper = toupper(s);
        result_data[upper]++;

        if (result_data[upper] > maxiam_count) {
            maxiam_count = result_data[upper];
            maxiam_data = upper;
        }
    }

    for (auto compare : result_data)
    {
        if (compare.second == maxiam_count && compare.first != maxiam_data) {
            cout << '?';
            return 0;
        }
    }

    cout << maxiam_data;
    return 0;
}
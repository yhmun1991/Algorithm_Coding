#include <iostream>
#include <stdio.h>
#include <vector>
#include <algorithm>
#include <map>
#include <cmath>
#include <set>
#include <string>

#define CHAR_OFFSET 48
using namespace std;
struct linkedlist
{
    int* pre;
    int value;
    int* tail;
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string input_data_A;
    vector<int> vec_input(10, 0);
    cin >> input_data_A;
    long input_number = stol(input_data_A);

    if (input_number < 1 || input_number > 1000000000)
        return 0;

    for (int i = 0; i < input_data_A.size(); i++)
    {
        vec_input[input_data_A[i]- CHAR_OFFSET]++;
    }

    for (int a = 9; a >= 0; a--)
        //cout << vec_input[a] << "\n";
        while (vec_input[a] > 0) {
            //cout << a << "\n";
            printf("%d", a);
            vec_input[a]--;
        }
    return 0;
}
#include <iostream>
#include <stdio.h>
#include <vector>
#include <algorithm>
#include <map>
#include <cmath>
#include <set>

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

    int input_data_A = 0, input_data_B = 0;
    vector<int> vec_input(10001, 0);
    cin >> input_data_A;

    if (input_data_A < 1 || input_data_A > 10000000)
        return 0;

    for (int i = 0; i < input_data_A; i++)
    {
        cin >> input_data_B;
        if (input_data_B < 0 || input_data_B > 10000)
            return 0;

        vec_input[input_data_B]++;
    }

    //sort(vec_input.begin(), vec_input.end());

    //for (int i = 1; i <vec_input.size(); i++)
    //{
    //    int data = vec_input.at(i);
    //    int j = i-1;
    //    
    //    while (j >= 0 && vec_input.at(j) > data)
    //    {
    //        vec_input[j + 1] = vec_input[j];
    //        j--;
    //    } 
    //    vec_input.at(j+1) = data;
    //}

    for (int a = 0; a < 10001; a++)
        //cout << vec_input[a] << "\n";
        while (vec_input[a] > 0) {
            //cout << a << "\n";
            printf("%d\n", a);
            vec_input[a]--;
        }
    return 0;
}
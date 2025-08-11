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
    int input_data_A = 0, input_data_B = 0, count = 0, tmp = 0;
    vector<int> vec_input, sorted_list;
    
    for (int i = 0; i < 5; i++)
    {
        cin >> input_data_B;
        if (input_data_B < 0 || input_data_B > 100 || input_data_B % 10 !=0)
            return 0;
        vec_input.push_back(input_data_B);
    }

    for (int i = 1; i <vec_input.size(); i++)
    {
        int data = vec_input.at(i);
        int j = i-1;
        
        while (j >= 0 && vec_input.at(j) > data)
        {
            vec_input[j + 1] = vec_input[j];
            j--;
        } 
        vec_input.at(j+1) = data;
    }
    
    int ret = 0;
    for (auto a : vec_input)
        ret += a;

    cout << ret / 5 << endl;

    cout << vec_input.at(2);
    return 0;
}
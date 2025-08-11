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
    int input_data_A = 0, input_data_A_1 = 0, input_data_B = 0, count = 0, tmp = 0;
    vector<int> vec_input, sorted_list;
    cin >> input_data_A >> input_data_A_1;

    //if (input_data_A < 1 || input_data_A > 1000 || input_data_A_1 < 1 || input_data_A_1 > input_data_A)
    //    return 0;

    for (int i = 0; i < input_data_A; i++)
    {
        cin >> input_data_B;
        //if (input_data_B < 0 || input_data_B > 100)
        //    return 0;
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

    cout << vec_input.at(vec_input.size()-input_data_A_1);
    return 0;
}
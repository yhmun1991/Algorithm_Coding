#include <iostream>
#include <stdio.h>
#include <vector>
#include <algorithm>
#include <map>
#include <cmath>
#include <set>

using namespace std;

int main() {
    int input_data_A = 0, input_data_B = 0, input_data_C = 0, result = 0;
    set<int> input_set;
    int array_int[3];
    cin >> input_data_A >> input_data_B >> input_data_C;

    if (input_data_A < 0 || input_data_A > 100 || input_data_B < 0 || input_data_B > 100 || input_data_C < 0 || input_data_C > 100) {
        return 0; //Error
    }
    array_int[0] = input_data_A;
    array_int[1] = input_data_B;
    array_int[2] = input_data_C;
    //if (input_data_A + input_data_B <= input_data_C || input_data_B + input_data_C <= input_data_A || input_data_A + input_data_C <= input_data_B)
    //    return 0;//Error

    //input_set.insert(input_data_A);
    //input_set.insert(input_data_B);
    //input_set.insert(input_data_C);
    //
    //result += *input_set.begin();
    //input_set.erase(input_set.begin());
    //result += *input_set.begin();
    //input_set.erase(input_set.begin());
    //
    //if(result > *input_set.begin())
    //    result += *input_set.begin();
    //else
    //{
    //    result += result -1;
    //}
    sort(array_int,array_int+3);

    result = array_int[0] + array_int[1];
    if (result > array_int[2])
        result += array_int[2];
    else
        result += result - 1;

    cout << result;
    return 0;
}
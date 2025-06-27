#include <iostream>
#include <stdio.h>

using namespace std;

int main()
{
    int data_size = 0, compare_index = 0, reverse_compare_index = 0;
    
    string input_data = "";
    cin >> input_data;

    data_size = input_data.size();
    if (data_size < 1 || data_size>100)
        return false; // Error

    for (char c : input_data)
    {
        if (c >= 'a' && c <= 'z')
            continue;
        else
            return false; // Error
    }
    reverse_compare_index = data_size - 1;
    while (compare_index < reverse_compare_index )
    {
        if (input_data[compare_index] != input_data[reverse_compare_index]) {
            cout << "0";
            return false;
        }
        compare_index++;
        reverse_compare_index--;
    }
    cout << "1";
    return 0;

}
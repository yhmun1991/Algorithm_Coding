#include <iostream>
#include <stdio.h>
#include <vector>
#include <algorithm>
#include <map>
#include <cmath>
#include <set>

using namespace std;

int main() {
    int input_data_A = 0, input_data_B = 0, Sum = 0, Sum2 = 0;
    vector<int> blackJack;
    cin >> input_data_A >> input_data_B;

    if (input_data_A < 3 || input_data_A > 100 || input_data_B < 10 || input_data_B > 300000) {
        return 0;//Error
    }
    
    for (int i = 0; i <= input_data_A; i++) {
        int inputdata;
        cin >> inputdata;

        if (inputdata < 0 || inputdata > 100000)
            return 0;
        
        blackJack.push_back(inputdata);
    }
    for (int i = 0; i < input_data_A - 2; i++)
    {
        for (int j = i + 1; j < input_data_A - 1; j++)
        {
            for (int n = j + 1; n < input_data_A; n++)
            {
                Sum = blackJack[i] + blackJack[j] + blackJack[n];
                if (Sum <= input_data_B && Sum > Sum2) {
                    Sum2 = Sum;
                    if (Sum2 == input_data_B) {
                        cout << input_data_B;
                        return 0;
                    }
                }
            }
        }
    }

    //sort(blackJack.begin(), blackJack.end());
    //
    //for (int i = 0; input_data_A - 2; i++)
    //{
    //    int sort_end = input_data_A - 1;
    //    int sort_begin = i + 1;
    //
    //    while (sort_end > sort_begin)
    //    {
    //        Sum = blackJack[sort_end] + blackJack[i] + blackJack[sort_begin];
    //        if (Sum == input_data_B)
    //        {
    //            cout << input_data_B;
    //            return 0;
    //        }
    //        if (Sum < input_data_B)
    //        {
    //            if (Sum > Sum2) {
    //                Sum2 = Sum;
    //                sort_begin++;
    //            }
    //            else
    //                sort_end--;
    //        }
    //    }
    //}
    cout << Sum2;
    return 0;
}
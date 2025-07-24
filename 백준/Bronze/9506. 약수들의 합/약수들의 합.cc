#include <iostream>
#include <stdio.h>
#include <vector>
#include <algorithm>
#include <map>
#include <cmath>

using namespace std;

int main() {
    int input_data_A = 0, input_data_B = 0, Sum = 0;;
    vector<int> input_data;
    while (true)
    {
        cin >> input_data_A;
        if (input_data_A == -1)
            break;
        if (input_data_A < 2 || input_data_A > 100000)
            return 0;//Error
        input_data.push_back(input_data_A);
    }
    
    for (auto a : input_data)
    {
        Sum = 0;
        vector<int> factor;
        for (int i = 1; i < a + 1; i++)
        {
            if (a % i == 0 && i != a) {
                factor.push_back(i);
                Sum += i;
            }
        }
        if (Sum == a) {
            sort(factor.begin(), factor.end());
            cout << a << " = ";
            for (int j = 0; j < factor.size(); j++) {
                cout << factor.at(j);
                if (j != factor.size() - 1)
                    cout << " + ";
            }
            cout << endl;
        }
        else
        {
            cout << a << " is NOT perfect." << endl;
        }
    }
    return 0;
}
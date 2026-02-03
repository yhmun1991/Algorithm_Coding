#include <iostream>
#include <stdio.h>
#include <vector>
#include <algorithm>
#include <map>
#include <cmath>
#include <set>
#include <string>
#include <cctype>
#include <unordered_map>
#include <unordered_set>
#include <numeric>
#include <list>
#include <queue>


#define CHAR_OFFSET 48
#define VALIDFAIL -1
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);


    int N, K, ret_A = 0, ret_B = 0;

    vector<int> temp(4);
    bool flag_A = true, flag_B = true;
    
    string a;
    cin >> a;
   
    if (a.size() == 0) {
        cout << 0;
        return 0;
    }
    
    if (a[0] =='c')
    {
        K = 1;
        ret_A = 26;
    }
    else
    {
        K = 0;
        ret_A = 10;
    }
    ret_B = ret_A;

    for (int i = 1; i < a.size(); i++)
    {
        if (a[i] == 'c')
        {
            if (K == 1)
                ret_A = 25;
            else {
                ret_A = 26;
                K = 1;
            }
        }
        else
        {
            if (K == 0)
            {
                ret_A = 9;
            }
            else
            {
                ret_A = 10;
                K = 0;
            }
        }
        ret_B = ret_B * ret_A;
    }
    
    cout << ret_B;
}

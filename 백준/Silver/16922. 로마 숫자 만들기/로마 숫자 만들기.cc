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


    int N, ret;

    set<int> setData;
    bool flag_A = true, flag_B = true;
    
    cin >> N;


    for (int i = 0; i <= N; i++)
    {
        for (int j = 0; j <= N-i; j++)
        {
            for (int k = 0; k <= N-i-j; k++)
            {
                int x;
    
                    x = N - (i + j + k);

                int SumData = (i * 1) + (j * 5) + (k * 10) + (x * 50);

                setData.insert(SumData);
            }
        }   
    }
    ret = setData.size();
    cout << ret;

  
}

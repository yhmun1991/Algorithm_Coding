#include <iostream>
#include <stdio.h>
#include <vector>
#include <algorithm>
#include <map>
#include <cmath>

using namespace std;

int main() {
    int A_M = 0, B_M = 0, V_M = 0, total = 0;
    cin >> A_M >> B_M >> V_M;
    if (A_M < 1 || A_M > 1000000000 || A_M <= B_M || A_M > V_M)
        return 0;//Error
    if (B_M < 1 || B_M > 1000000000 || B_M > V_M)
        return 0;//Error
    if (V_M < 1 || V_M > 1000000000)
        return 0;//Error
    
    total = (V_M-B_M) % (A_M - B_M) == 0 ? (V_M - B_M) / (A_M - B_M) : ((V_M - B_M) / (A_M - B_M)) + 1;
    //do
    //{
    //    total++;
    //    V_M = V_M - A_M + B_M;
    //}while (V_M > 0);

    cout << total;
    return 0;
}
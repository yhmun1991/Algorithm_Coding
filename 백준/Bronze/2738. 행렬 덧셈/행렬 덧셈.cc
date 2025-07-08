#include <iostream>
#include <stdio.h>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

int main() {
    int N = 0, M = 0, tmp = 0;;
    int A[100][100];
    bool ret = false;

    cin >> N >> M;
    if (N > 100 || N < 0 || M > 100 || M < 0)
        return 0; // 에러

    for(int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >>A[i][j];
        }
    }
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> tmp;
            A[i][j] = A[i][j]+tmp;
        }
    }
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cout << A[i][j]<<" ";
        }
        cout << "\n";
    }
    return 0;
}
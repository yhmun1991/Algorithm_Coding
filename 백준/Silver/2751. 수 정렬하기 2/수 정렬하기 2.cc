#include <bits/stdc++.h>
using namespace std;

bitset<1000001> neg; // 음수 저장용
bitset<1000001> pos; // 양수 저장용

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;

    for (int i = 0; i < N; i++) {
        int x;
        cin >> x;
        if (x < 0) neg[-x] = 1; // -x 로 저장
        else pos[x] = 1;       // 그대로 저장
    }

    // 음수 출력 (큰 값부터)
    for (int i = 1000000; i >= 1; i--) {
        if (neg[i]) cout << -i << '\n';
    }
    // 0 출력
    if (pos[0]) cout << 0 << '\n';
    // 양수 출력 (작은 값부터)
    for (int i = 1; i <= 1000000; i++) {
        if (pos[i]) cout << i << '\n';
    }
}
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, K;
    cin >> N >> K;
    vector<pair<int, int>> items(N);
    for (int i = 0; i < N; ++i)
        cin >> items[i].first >> items[i].second; // W, V

    vector<int> dp(K + 1, 0); // dp[w] = 해당 무게로 얻을 수 있는 최대 가치

    for (int i = 0; i < N; ++i) {
        int W = items[i].first;
        int V = items[i].second;
        for (int w = K; w >= W; --w) { 
            dp[w] = max(dp[w], dp[w - W] + V);
        }
    }

    cout << dp[K] << '\n';
    return 0;
}
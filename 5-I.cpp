#include <bits/stdc++.h>
using namespace std;

const long long INF = (1LL << 62);

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n;
    long long W;
    cin >> n >> W;
    
    vector<long long> weights(n);
    vector<int> costs(n);
    int totalValue = 0;
    
    for (int i = 0; i < n; i++) {
        cin >> weights[i] >> costs[i];
        totalValue += costs[i];
    }
    
    vector<long long> dp(totalValue + 1, INF);
    dp[0] = 0;
    
    for (int i = 0; i < n; i++) {
        for (int value = totalValue; value >= costs[i]; value--) {
            dp[value] = min(dp[value], dp[value - costs[i]] + weights[i]);
        }
    }
    
    int answer = 0;
    for (int value = 0; value <= totalValue; value++) {
        if (dp[value] <= W) {
            answer = value;
        }
    }
    
    cout << answer << '\n';
    return 0;
}

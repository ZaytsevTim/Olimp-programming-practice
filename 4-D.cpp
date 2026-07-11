#include <bits/stdc++.h>
using namespace std;

const int INF = 1e9;

void solve() {
    int n, m, k;
    cin >> n >> m >> k;

    string s;
    cin >> s;
    s = "L" + s + "L";

    vector<int> dp(n + 2, INF);
    dp[0] = 0;

    for (int i = 0; i <= n + 1; ++i) {
        if (dp[i] > k) continue;
        if (s[i] == 'C') continue;

        if (i == 0 || s[i] == 'L') {
            for (int j = 1; j <= m; ++j) {
                int nxt = i + j;
                if (nxt > n + 1) break;
                if (s[nxt] == 'C') continue;
                dp[nxt] = min(dp[nxt], dp[i]);
            }
        }

        if (s[i] == 'W') {
            int nxt = i + 1;
            if (nxt > n + 1) continue;
            if (s[nxt] == 'C') continue;
            dp[nxt] = min(dp[nxt], dp[i] + 1);
        }
    }

    cout << (dp[n + 1] <= k ? "YES" : "NO") << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}

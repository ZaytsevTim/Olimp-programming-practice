#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using vl = vector<ll>;
using vvl = vector<vl>;

const ll INF = 4e18;

void solve() {
    int n;
    cin >> n;

    if (n == 1) {
        cout << 0 << '\n';
        return;
    }

    vvl cost(n, vl(n));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> cost[i][j];
        }
    }

    int fullMask = 1 << n;
    vvl dp(fullMask, vl(n, INF));

    dp[1][0] = 0;

    for (int mask = 1; mask < fullMask; ++mask) {
        for (int last = 0; last < n; ++last) {
            if (dp[mask][last] == INF) continue;

            for (int next = 0; next < n; ++next) {
                if (mask & (1 << next)) continue;

                int newMask = mask | (1 << next);
                dp[newMask][next] = min(dp[newMask][next],
                                        dp[mask][last] + cost[last][next]);
            }
        }
    }

    ll ans = INF;
    for (int last = 1; last < n; ++last) {
        ans = min(ans, dp[fullMask - 1][last] + cost[last][0]);
    }

    cout << ans << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();
    return 0;
}

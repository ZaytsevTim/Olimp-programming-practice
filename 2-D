#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using vl = vector<ll>;

vl z_function(const string &s) {
    ll n = s.size();
    vl z(n);

    ll l = 0, r = 0;

    for (ll i = 1; i < n; i++) {
        if (i <= r)
            z[i] = min(r - i + 1, z[i - l]);

        while (i + z[i] < n && s[z[i]] == s[i + z[i]])
            z[i]++;

        if (i + z[i] - 1 > r) {
            l = i;
            r = i + z[i] - 1;
        }
    }

    return z;
}

void solve() {
    string s;
    cin >> s;

    ll n = s.size();
    ll ans = 0;

    for (ll i = 0; i < n; i++) {
        string sub = s.substr(i);
        vl z = z_function(sub);
        ll mx = 0;
        for (ll j = 1; j < (ll)z.size(); j++) {
            mx = max(mx, z[j]);
        }
        ans += (n - i) - mx;
    }

    cout << ans << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll t = 1;
    while (t--) {
        solve();
    }

    return 0;
}

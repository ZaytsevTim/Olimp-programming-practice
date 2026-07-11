#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using vl = vector<ll>;

void solve() {
    int n;
    ll k;
    cin >> n >> k;

    vl a(n);
    ll total = 0;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        total += a[i];
    }

    if (k >= total) {
        cout << n << '\n';
        return;
    }

    ll left_attacks = (k + 1) / 2;
    ll right_attacks = k / 2;

    int alive_front = 0, alive_back = n - 1;
    int sunk = 0;

    while (alive_front <= alive_back && left_attacks > 0) {
        if (left_attacks >= a[alive_front]) {
            left_attacks -= a[alive_front];
            sunk++;
            alive_front++;
        } else {
            break;
        }
    }

    while (alive_front <= alive_back && right_attacks > 0) {
        if (right_attacks >= a[alive_back]) {
            right_attacks -= a[alive_back];
            sunk++;
            alive_back--;
        } else {
            break;
        }
    }

    cout << sunk << '\n';
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

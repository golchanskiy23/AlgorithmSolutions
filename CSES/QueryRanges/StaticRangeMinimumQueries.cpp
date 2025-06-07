#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int MAXN = 2*1e5 + 5;
const int LOG = 25;

ll st[MAXN][LOG];
int log2table[MAXN];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll n, q;
    cin >> n >> q;
    vector<ll> v(n);
    for (int i = 0; i < n; i++) cin >> v[i];

    log2table[1] = 0;
    for (int i = 2; i <= n; i++)
        log2table[i] = log2table[i / 2] + 1;

    for (int i = 0; i < n; i++)
        st[i][0] = v[i];

    for (int j = 1; (1 << j) <= n; j++) {
        for (int i = 0; i + (1 << j) <= n; i++) {
            st[i][j] = min(st[i][j - 1], st[i + (1 << (j - 1))][j - 1]);
        }
    }

    while (q--) {
        int l, r;
        cin >> l >> r;
        l--, r--;
        int len = r - l + 1;
        int k = log2table[len];
        ll ans = min(st[l][k], st[r - (1 << k) + 1][k]);
        cout << ans << '\n';
    }

    return 0;
}

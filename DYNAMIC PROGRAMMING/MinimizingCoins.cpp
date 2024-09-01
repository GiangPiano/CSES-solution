#include<bits/stdc++.h>
using namespace std;

#define int long long
#define pb push_back
#define mp make_pair

const int amax = 1e6 + 69;
const int MOD = 1e9 + 7;

void solve() {
    int n, x; cin >> n >> x;
    vector<int> a(n), dp(amax, INT_MAX);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        dp[a[i]] = 1;
    }

    for (int i = 1; i <= x; i++)
        for (auto j: a)
            if (i > j)
                dp[i] = min(dp[i], dp[i - j] + 1);
    cout << (dp[x] == INT_MAX ? -1 : dp[x]);
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    #ifdef GIANGPIANO
    // freopen("INPUT.txt", "r", stdin);
    // freopen("ERROR.txt", "w", stderr);
    // freopen("OUTPUT.txt", "w", stdout);
    #endif
    int T = 1; // cin >> T;
    while (T--) {
        solve();
        cout << '\n';
    }

    return 0;
}
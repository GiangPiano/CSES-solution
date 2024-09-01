#include<bits/stdc++.h>
using namespace std;

#define int long long
#define pb push_back
#define mp make_pair

const int amax = 1e4 + 69;
const int MOD = 1e9 + 7;

void solve() {
    int n, x; cin >> n >> x;
    int a[n + 1];
    for (int i = 1; i <= n; i++) cin >> a[i];

    vector<int> dp(x + 1, 0);
    dp[0] = 1;
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j + a[i] <= x; j++) {
            dp[j + a[i]] = (dp[j + a[i]] + dp[j]) % MOD;
            //cout << dp[j + a[i]] << ' ';
        }
        //cout << '\n';
    }
    cout << dp[x];
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
#include<bits/stdc++.h>
using namespace std;

#define int long long
#define pb push_back
#define mp make_pair

const int amax = 1e5 + 69;
const int MOD = 1e9 + 7;

void solve() {
    int n, m; cin >> n >> m;
    vector<int> a(n + 1);
    for (int i = 1; i <= n; i++) cin >> a[i];

    vector<vector<int>> dp(n + 1, vector<int> (m + 2, 0));
    if (a[1] == 0) {
        for (int i = 1; i <= m; i++) dp[1][i] = 1;
    }
    else dp[1][a[1]] = 1;
    
    for (int i = 2; i <= n; i++) {
        if (a[i] != 0) {
            dp[i][a[i]] = ((dp[i - 1][a[i] - 1] + dp[i - 1][a[i] + 1]) % MOD + dp[i - 1][a[i]]) % MOD;
            continue;
        }
        for (int j = 1; j <= m; j++) dp[i][j] = ((dp[i - 1][j - 1] + dp[i - 1][j + 1]) % MOD + dp[i - 1][j]) % MOD;
    }
    int res = 0;
    for (int i = 1; i <= m; i++) {
        res = (res + dp[n][i]) % MOD;
    }
    cout << res;
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
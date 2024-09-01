#include<bits/stdc++.h>
using namespace std;

#define int long long
#define pb push_back
#define mp make_pair

const int amax = 1e5 + 69;
const int MOD = 1e9 + 7;

void solve() {
    int n; cin >> n;
    vector<string> grid(n);
    for (int i = 0; i < n; i++) cin >> grid[i];
    vector<vector<int>> dp(n, vector<int> (n));
    if (grid[0][0] == '*') {
        cout << 0;
        return;
    }
    dp[0][0] = 1;
    //cout << dp[0][0];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (i == 0 && j == 0) continue;
            if (grid[i][j] == '*') dp[i][j] = 0;
            else {
                if (i == 0) dp[i][j] = dp[i][j - 1];
                else if (j == 0) dp[i][j] = dp[i - 1][j];
                else dp[i][j] = (dp[i - 1][j] + dp[i][j - 1]) % MOD;
            }
        }
    }
    cout << dp[n - 1][n - 1];
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
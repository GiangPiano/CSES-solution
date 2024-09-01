#include<bits/stdc++.h>
using namespace std;

#define int long long
#define pb push_back
#define mp make_pair

const int amax = 1e5 + 69;
const int MOD = 1e9 + 7;

void solve() {
    string a, b; cin >> a >> b;
    int alen = a.size(), blen = b.size();

    vector<vector<int>> dp(a.size() + 1, vector<int> (b.size() + 1, INT_MAX));
    dp[0][0] = 0;
    for (int i = 0; i <= a.size(); i++) {
        for (int j = 0; j <= b.size(); j++) {
            if (i > 0) dp[i][j] = min(dp[i][j], 1 + dp[i - 1][j]);
            if (j > 0) dp[i][j] = min(dp[i][j], 1 + dp[i][j - 1]);
            if (i && j) dp[i][j] = min(dp[i][j], dp[i - 1][j - 1] + (a[i - 1] != b[j - 1]));
        }
    }
    cout << dp[a.size()][b.size()];
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
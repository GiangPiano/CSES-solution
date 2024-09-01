#include<bits/stdc++.h>
using namespace std;

#define int long long
#define pb push_back
#define mp make_pair

const int amax = 1e5 + 69;
const int MOD = 1e9 + 7;

void solve() {
    int a, b; cin >> a >> b;
    vector<vector<int>> dp(a + 1, vector<int> (b + 1, INT_MAX));

    for (int i = 1; i <= a; i++) {
        for (int j = 1; j <= b; j++) {
            if (i == j) {
                dp[i][j] = 0;
                //cout << dp[i][j] << ' ';
                continue;
            }
            for (int h = 1; h < i; h++) dp[i][j] = min(dp[i][j], dp[i - h][j] + dp[h][j] + 1);
            for (int w = 1; w < j; w++) dp[i][j] = min(dp[i][j], dp[i][j - w] + dp[i][w] + 1);
            //cout << dp[i][j] << ' ';
        }
        //cout << '\n';
    }
    cout << dp[a][b];
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
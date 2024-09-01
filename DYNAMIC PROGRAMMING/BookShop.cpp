#include<bits/stdc++.h>
using namespace std;
 
//#define int long long
#define pb push_back
#define mp make_pair
 
const int amax = 1e5 + 69;
const int MOD = 1e9 + 7;
 
void solve() {
    int n, x; cin >> n >> x;
    vector<int> price(n + 1);
    for (int i = 1; i <= n; i++) cin >> price[i];
    vector<int> pages(n + 1);
    for (int i = 1; i <= n; i++) cin >> pages[i];
 
    vector<vector<int>> dp(n + 1, vector<int> (x + 1));
    for (int i = 0; i <= x; i++) dp[0][x] = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= x; j++) {
            dp[i][j] = dp[i - 1][j];
            if (j >= price[i]) {
                dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - price[i]] + pages[i]);   
            }
        }
    }
    cout << dp[n][x];
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
#include<bits/stdc++.h>
using namespace std;

#define int long long
#define pb push_back
#define mp make_pair

const int amax = 1e5 + 69;
const int MOD = 1e9 + 7;

void solve() {
    int n; cin >> n;
    vector<int> a(n + 1);
    vector<vector<int>> dp(n + 1, vector<int> (n + 1));
    int sum = 0;

    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        sum += a[i];
    }
    
    for (int i = 1; i <= n; i++) {
        for (int j = i; j > 0; j--) {
            if (i == j) dp[i][j] = a[i];
            else
                dp[j][i] = max(a[j] - dp[j + 1][i], a[i] - dp[j][i - 1]);
        }
    }
    cout << (sum + dp[1][n])/2;
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
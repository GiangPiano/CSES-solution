#include<bits/stdc++.h>
using namespace std;

#define int long long
#define pb push_back
#define mp make_pair

const int amax = 1e5 + 69;
const int MOD = 1e9 + 7;

void solve() {
    int n; cin >> n;
    if (n*(n + 1)/2 % 2 != 0) {
        cout << 0;
        return;
    }

    unsigned long long sum = n*(n + 1)/4;
    vector<unsigned long long> dp(5000005, 0);

    vector<int> v;
    for (int i = 1; i <= n; i++) v.pb(i);
    dp[0] = 1;
    for (int j = 1; j < n; j++) {
        for (int i = sum; i > 0; i--) {
            if (i - j >= 0)
                dp[i] = (dp[i] + dp[i - j]) % MOD;
        }
    }

    // for (int i = 1; i <= sum; i++)
    //     cout << dp[i] << ' ';
    // cout << '\n';

    cout << dp[sum];
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
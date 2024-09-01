#include<bits/stdc++.h>
using namespace std;

#define int long long
#define pb push_back
#define mp make_pair

const int amax = 1e5 + 69;
const int MOD = 1e9 + 7;

void solve() {
    int n; cin >> n;
    vector<int> a(n);
    int maxSum = 0;
    for (int i = 0; i < n; i++) {
    	cin >> a[i];
    	maxSum += a[i];
	}
    
    vector<int> dp(maxSum + 1);
    dp[0] = 1;
    int cnt = 0;
    for (int i = 0; i < n; i++) {
        for (int j = maxSum; j >= a[i]; j--) {
        	if (!dp[j]) dp[j] = dp[j - a[i]];
		}
    }
    
	for (auto x: dp) cnt += x;
	cout << cnt - 1 << '\n';
    for (int i = 1; i <= maxSum; i++)
    	if (dp[i]) cout << i << ' ';
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    #ifdef GIANGPIANO
    // freopen("INPUT.txt", "r", stdin);
    // freopen("ERROR.txt", "w", stderr);
    // freopen("OUTPUT.txt", "w", stdout);
    #endif
    int T = 1; //cin >> T;
    while (T--) {
        solve();
        cout << '\n';
    }

    return 0;
}
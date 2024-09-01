#include<bits/stdc++.h>
#define int long long
#define pb push_back
#define mp make_pair
using namespace std;

const int amax = 1e5 + 69;
const int MOD = 1e9 + 7;

void solve() {
    int n, ans = 0; cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        ans += a[i];
    }
    
    sort(a.begin(), a.end());
    cout << max(ans, a[n - 1] * 2);
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
    }

    return 0;
}
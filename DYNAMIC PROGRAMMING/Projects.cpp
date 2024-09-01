#include<bits/stdc++.h>
using namespace std;

#define int long long
#define pb push_back
#define mp make_pair

const int amax = 1e5 + 69;
const int MOD = 1e9 + 7;

struct Projects {
    int start, endt, reward;

    bool operator< (const Projects& other) const {
        //if (endt == other.endt) return start < other.start;
        return endt < other.endt;
    }
};


void solve() {
    int n; cin >> n;
    vector<Projects> a(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> a[i].start >> a[i].endt >> a[i].reward;
    }
    sort(a.begin() + 1, a.end());
    
    vector<int> prefix(n + 1);
    for (int i = 1; i <= n; i++) prefix[i] = a[i].endt;

    vector<int> dp(n + 1, 0);
    for (int i = 1; i <= n; i++) {
        int it = lower_bound(prefix.begin(), prefix.end(), a[i].start) - 1 - prefix.begin();
        dp[i] = max(dp[i - 1], dp[it] + a[i].reward);
    }
    cout << dp[n];
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
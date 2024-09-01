#include<bits/stdc++.h>
#define int long long
#define pb push_back
#define mp make_pair
using namespace std;

const int amax = 1e5 + 69;
const int MOD = 1e9 + 7;

void solve() {
    int n; cin >> n;
    vector<pair<int, int>> a;
    for (int i = 0; i < n; i++) {
        int task, deadline; cin >> task >> deadline;
        a.pb(mp(task, deadline));
    }
    sort(a.begin(), a.end());
    int time = 0, reward = 0;
    for (int i = 0; i < n; i++) {
        time += a[i].first;
        reward += a[i].second - time;
    }
    cout << reward;
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
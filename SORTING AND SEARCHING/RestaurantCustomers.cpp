#include<bits/stdc++.h>
#define int long long
#define pb push_back
#define mp make_pair
using namespace std;

const int amax = 1e5 + 69;
const int MOD = 1e9 + 7;

void solve() {
    int n; cin >> n;
    vector<pair<int, int>> times;
    for (int i = 0; i < n; i++) {
        int start, end; cin >> start >> end;
        times.pb(mp(start, 1));
        times.pb(mp(end, -1));
    }
    sort(times.begin(), times.end());

    int ppl = 0, res = -1;
    for (const pair<int, int> &i : times) {
        ppl += i.second;
        res = max(res, ppl);
    }
    cout << res;
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
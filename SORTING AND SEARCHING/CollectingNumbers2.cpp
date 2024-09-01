#include<bits/stdc++.h>
#define int long long
#define pb push_back
#define mp make_pair
using namespace std;

const int amax = 1e5 + 69;
const int MOD = 1e9 + 7;

void solve() {
    int n, q; cin >> n >> q;

    vector<int> a(n + 1);
    vector<int> pos(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        pos[a[i]] = i;
    }

    int res = 1;
    for (int i = 1; i < n; i++) {
        res += pos[i] > pos[i + 1];
    }

    set<pair<int, int>> updated; 
    while (q--) {
        int x, y; cin >> x >> y;
        if (a[x] > 1) updated.insert(mp(a[x] - 1, a[x]));
        if (a[x] < n) updated.insert(mp(a[x], a[x] + 1));
        if (a[y] > 1) updated.insert(mp(a[y] - 1, a[y]));
        if (a[y] < n) updated.insert(mp(a[y], a[y] + 1));

        for (pair<int, int> adj : updated) {
            res -= pos[adj.first] > pos[adj.second];
        }
        swap(a[x], a[y]);
        pos[a[x]] = x;
        pos[a[y]] = y;
        for (pair<int, int> adj : updated) {
            res += pos[adj.first] > pos[adj.second];
        }
        cout << res << '\n';
        updated.clear();
    }
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
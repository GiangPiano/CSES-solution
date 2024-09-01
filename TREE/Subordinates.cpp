#include<bits/stdc++.h>
using namespace std;

#define int long long
#define pb push_back
#define mp make_pair

const int amax = 2e5 + 69;
const int MOD = 1e9 + 7;
vector<int> adj[amax];
int cnt[amax] = {};
void dfs(int s, int e) {
    cnt[s] = 0;
    for (auto u: adj[s]) {
        if (u != e) {
            dfs(u, s);
            cnt[s] += cnt[u] + 1;
        }
    }
}

void solve() {
    int n; cin >> n;
    for (int i = 2; i <= n; i++) {
        int x; cin >> x;
        adj[i].pb(x);
        adj[x].pb(i);
    }
    dfs(1, 0);
    for (int i = 1; i <= n; i++) cout << cnt[i] << ' ';
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
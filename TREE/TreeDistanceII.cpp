#include<bits/stdc++.h>
using namespace std;

#define int long long
#define pb push_back
#define mp make_pair

const int amax = 2e5 + 69;
const int MOD = 1e9 + 7;

vector<int> adj[amax];
vector<int> subtreeSize(amax);
vector<int> sum(amax), res(amax);
void dfs(int s, int e) {
    subtreeSize[s] = 1;
    for (auto u: adj[s]) {
        if (u == e) continue;
        dfs(u, s);
        subtreeSize[s] += subtreeSize[u];
        sum[s] += sum[u] + subtreeSize[u];
    }
}

void dfs2(int s, int e) {
    for (auto u: adj[s]) {
        if (u == e) continue;
        sum[u] = sum[s] - subtreeSize[u] + subtreeSize[1] - subtreeSize[u];
        dfs2(u, s);
    }

}

void solve() {
    int n; cin >> n;
    for (int i = 1; i <= n - 1; i++) {
        int u, v; cin >> u >> v;
        adj[u].pb(v);
        adj[v].pb(u);
    }
    dfs(1, 0);
    dfs2(1, 0);
    //for (int i = 1; i <= n; i++) cout << subtreeSize[i] << ' ';
    cout << '\n';
    for (int i = 1; i <= n; i++) cout << sum[i] << ' ';
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
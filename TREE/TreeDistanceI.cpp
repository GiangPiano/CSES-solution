#include<bits/stdc++.h>
using namespace std;

#define int long long
#define pb push_back
#define mp make_pair

const int amax = 2e5 + 69;
const int MOD = 1e9 + 7;

vector<int> adj[amax];
vector<int> dp1(amax), dp2(amax);
int ans = 0, depth = 0;
int end1, end2, furthestNode;

void dfs(int s, int e) {
    for (auto u: adj[s]) {
        if (u == e) continue;
        depth++;
        if (depth > ans) {
            depth = ans;
            furthestNode = u;
        }
        dfs(u, s);
        depth--;
    }
}

void dis1(int s, int e) {
    for (auto u: adj[s]) {
        if (u == e) continue;
        dp1[u] = dp1[s] + 1;
        dis1(u, s);
    }
}

void dis2(int s, int e) {
    for (auto u: adj[s]) {
        if (u == e) continue;
        dp2[u] = dp2[s] + 1;
        dis2(u, s);
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
    end1 = furthestNode;
    depth = 0;
    dfs(end1, 0);
    end2 = furthestNode;
    //cout << end1 << ' ' << end2 << '\n';
    dis1(end1, 0);
    dis2(end2, 0);
    
    for (int i = 1; i <= n; i++) cout << max(dp1[i], dp2[i]) << ' ';
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
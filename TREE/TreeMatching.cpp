#include<bits/stdc++.h>
using namespace std;

#define int long long
#define pb push_back
#define mp make_pair

const int amax = 2e5 + 69;
vector<vector<int>> dp(amax, vector<int> (2));
vector<int> adj[amax];
int ans = 0;
 
void dfs(int s, int e) {
	for (auto u: adj[s]) {
		if (u == e) continue;
		dfs(u, s);
		dp[s][0] += max(dp[u][0], dp[u][1]);
	}
	for (auto u: adj[s]) {
		if (u == e) continue;
		dp[s][1] = max(dp[s][1], 1 + dp[s][0] - max(dp[u][0], dp[u][1]) + dp[u][0]);
	}
} 
 
void solve() {
	int n; cin >> n;
	//cout << n;
	for (int i = 1; i < n; i++) {
		int u, v; cin >> u >> v;
		adj[u].pb(v);
		adj[v].pb(u);
	}
	dfs(1, 0);
	cout << max(dp[1][0], dp[1][1]);
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
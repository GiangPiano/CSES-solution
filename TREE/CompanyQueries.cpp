#include<bits/stdc++.h>
using namespace std;

#define int long long
#define pb push_back
#define mp make_pair

const int amax = 2e6 + 69;
const int MOD = 1e9 + 7;

vector<int> adj[amax];
vector<int> par(amax, -1), dep(amax);
int up[amax][20];
int binaryLift(int x, int k) {
    for (int i = 0; (1 << i) <= k; i++) {
        if (k >> i & 1) {
            x = up[x][i];
        }
    }
    return x;
}

void solve() {
    int n, q; cin >> n >> q;
    
    //memset(up, -1, sizeof(up));
    for (int i = 2; i <= n; i++) {
        int x; cin >> x;
        par[i] = x;
    }

    //init
    for (int i = 1; i <= n; i++) up[i][0] = par[i];
    for (int j = 1; j < 17; j++) 
        for (int i = 1; i <= n; i++)
            up[i][j] = up[up[i][j - 1]][j - 1];
    //for (int j = 1; j < 17; j++) up[1][j] = -1;

    while (q--) {
        int x, k; cin >> x >> k;
        cout << binaryLift(x, k) << '\n';
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
        cout << '\n';
    }

    return 0;
} 
#include<bits/stdc++.h>
using namespace std;

#define int long long
#define pb push_back
#define mp make_pair

const int amax = 1e4 + 1;
const int MOD = 1e9 + 7;

int n, m;
vector<vector<char>> grid(amax, vector<char> (amax));
vector<vector<bool>> visited(amax, vector<bool> (amax));

void dfs(int x, int y) {
    //if (visited[x][y]) return;
    visited[x][y] = true;
    if (x + 1 < n && !visited[x + 1][y]) dfs(x + 1, y);
    if (y + 1 < m && !visited[x][y + 1]) dfs(x, y + 1);
    if (x - 1 >= 0 && !visited[x - 1][y]) dfs(x - 1, y);
    if (y - 1 >= 0 && !visited[x][y - 1]) dfs(x, y - 1);
    return;
}


void solve() {
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> grid[i][j];
            visited[i][j] = (grid[i][j] == '#');
        }
    }

    int cnt = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (!visited[i][j]) {
                dfs(i, j);
                cnt++;
            }
        }
    }
    cout << cnt;
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
#include<bits/stdc++.h>
#define int long long
#define pb push_back
#define mp make_pair
using namespace std;

const int amax = 1e5 + 69;
const int MOD = 1e9 + 7;

void solve() {
    int n; cin >> n;
    int res = 0;
    int prefix = 0;
    vector<int> countRemainder(n, 0);
    for (int i = 1; i <= n; i++) {
        int a; cin >> a;
        prefix += a;
        countRemainder[(prefix % n + n) % n]++;
    }
    for (int i = 0; i < n; i++) {
        res += countRemainder[i] * (countRemainder[i] - 1) / 2;
    }
    res += countRemainder[0];

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
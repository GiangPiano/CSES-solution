#include<bits/stdc++.h>
#define int long long
#define pb push_back
#define MP make_pair
using namespace std;

const int amax = 1e5 + 69;
const int MOD = 1e9 + 7;

void solve() {
    int n, k; cin >> n >> k;
    vector<int> a(n);
    unordered_map<int, pair<int, int>> mp;

    for (int i = 0; i < n; i++) cin >> a[i];

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (i == j) continue;
            int remain = k - a[i] - a[j];
            if (mp.count(remain) && mp[remain].first != i && mp[remain].first != j && mp[remain].second != i && mp[remain].second != j) {
                cout << i + 1 << ' ' << j + 1 << ' ' << mp[remain].first + 1 << ' ' << mp[remain].second + 1;
                return;
            }
            mp[a[i] + a[j]] = MP(i, j);
        }
    }
    cout << "IMPOSSIBLE";
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
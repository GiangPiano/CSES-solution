#include<bits/stdc++.h>
#define int long long
#define pb push_back
#define mp make_pair
using namespace std;

const int amax = 1e5 + 69;
const int MOD = 1e9 + 7;

void solve() {
    int n, k; cin >> n >> k;
    vector<int> a(n);
    map<int, int> distinct;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    int res = 0;
    int j = 0;
    for (int i = 0; i < n; i++) {
        //distinct[a[i]]++;
        while (j < n && (distinct.size() < k || distinct.count(a[j]) > 0)) {
            distinct[a[j]]++;
            j++;
        }
        res += j - i;
        distinct[a[i]]--;
        if (distinct[a[i]] == 0) distinct.erase(a[i]);
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
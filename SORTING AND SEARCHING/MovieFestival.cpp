#include<bits/stdc++.h>
#define int long long
#define pb push_back
#define mp make_pair
using namespace std;

const int amax = 1e5 + 69;
const int MOD = 1e9 + 7;

bool compare(const pair<int, int> &a, const pair<int, int> &b) {
    return a.second < b.second;
}

void solve() {
    int n; cin >> n;
    vector<pair<int, int>> a;

    for (int i = 0; i < n; i++) {
        int start, end; cin >> start >> end;
        a.pb(mp(start, end));
    }

    sort(a.begin(), a.end(), compare);

    // for (int i = 0; i < n; i++) {
    //     cerr << a[i].first << ' ' << a[i].second << '\n';
    // }
    int cnt = 1;
    int j = 0;
    for (int i = 1; i < n; i++) {
        if (a[i].first >= a[j].second) {
            // cerr << a[i].first << ' ' << a[i].second << '\n';
            j = i;
            cnt++;
        }
    }
    cout << cnt << '\n';
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
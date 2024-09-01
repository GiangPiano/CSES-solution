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
    int n, k; cin >> n >> k;
    vector<pair<int, int>> a;
 
    for (int i = 0; i < n; i++) {
        int start, end; cin >> start >> end;
        a.pb(mp(start, end));
    }
 
    sort(a.begin(), a.end(), compare);
 
    // for (int i = 0; i < n; i++) {
    //     cerr << a[i].first << ' ' << a[i].second << '\n';
    // }
    multiset<int> lastMovies;
    for (int i = 0; i < k; i++) lastMovies.insert(0);


    int cnt = 0;
    for (int i = 0; i < n; i++) {
        auto it = --lastMovies.upper_bound(a[i].first);
        if (it != lastMovies.end() && *it <= a[i].first) {
            // cerr << a[i].first << ' ' << a[i].second << '\n';
            lastMovies.erase(lastMovies.find(*it));
            lastMovies.insert(a[i].second);
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
    // //freopen("ERROR.txt", "w", stderr);
    // freopen("OUTPUT.txt", "w", stdout);
    #endif
    int T = 1; // cin >> T;
    while (T--) {
        solve();
    }
 
    return 0;
}
#include<bits/stdc++.h>
using namespace std;

#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
typedef tree<int, null_type, less_equal<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;

#define int long long
#define pb push_back
#define mp make_pair

const int amax = 1e5 + 69;
const int MOD = 1e9 + 7;

void Erase(ordered_set &a, int x){
    int first = a.order_of_key(x);
    auto it = a.find_by_order(first);
    a.erase(it);
}

void solve() {
    int n, k; cin >> n >> k;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    ordered_set window;
    for (int i = 0; i < k; i++) {
        window.insert(a[i]);
    }
    for (int i = 0; i < n - k + 1; i++) {
        cout << *(window.find_by_order((k - 1) / 2)) << ' ';
        //for (auto i : window) cout << i << ' ';
        //cout << '\n';
        Erase(window, a[i]);
        window.insert(a[i + k]);
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
    }

    return 0;
}
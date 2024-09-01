#include<bits/stdc++.h>
using namespace std;

#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp> 
using namespace __gnu_pbds;
template <typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

#define int long long
#define pb push_back
#define mp make_pair

const int amax = 1e5 + 69;
const int MOD = 1e9 + 7;

struct range {
    int l;
    int r;
    int id;

    bool operator < (const range &p) const {
        if (l != p.l) return l < p.l;
        else return r > p.r;
    }
};

void solve() {
    int n; cin >> n;

    vector<range> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i].l >> a[i].r;
        a[i].id = i;
    }
    sort(a.begin(), a.end());
    
    ordered_set <pair<int, int>> rightBound;

    vector<int> container(n);
    for (int i = 0; i < n; i++) {
        rightBound.insert({a[i].r, -1*i});
        container[a[i].id] = rightBound.size() - rightBound.order_of_key({a[i].r, -1*i}) - 1;
    }
    rightBound.clear();

    vector<int> contains(n);
    for (int i = n - 1; i >= 0; i--) {
        rightBound.insert({a[i].r, -1*i});
        contains[a[i].id] = rightBound.order_of_key({a[i].r, -1*i});
    }

    for (int i = 0; i < n; i++) cout << contains[i] << ' ';
    cout << '\n';
    for (int i = 0; i < n; i++) cout << container[i] << ' ';
    
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
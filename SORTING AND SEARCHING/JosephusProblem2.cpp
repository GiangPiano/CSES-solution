#include<bits/stdc++.h>
using namespace std;

#include<ext/pb_ds/tree_policy.hpp>
#include<ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
template <typename T>
using ordered_set = tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update>;

#define int long long
#define pb push_back
#define mp make_pair

const int amax = 1e5 + 69;
const int MOD = 1e9 + 7;
 
void solve() {
    int n, k; cin >> n >> k;

    ordered_set<int> children;
    for (int i = 1; i <= n; i++) children.insert(i);

    int start = 0;
    while (children.size() >= 1) {
        start %= children.size();
        int removePos = (start + k) % children.size();
        auto it = children.find_by_order(removePos);
        cout << *it << ' ';
        children.erase(*it);
        start = removePos;
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
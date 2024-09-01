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

struct customer {
    int l;
    int r;
    int id;

    bool operator < (const customer &p) const {
        return l < p.l;
    }
};

void solve() {
    int n; cin >> n;

    vector<customer> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i].l >> a[i].r;
        a[i].id = i;
    }
    sort(a.begin(), a.end());
    
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> rooms;
    vector<int> roomAssigned(n);

    roomAssigned[a[0].id] = 1;
    rooms.push(mp(a[0].r, 1));
    for (int i = 1; i < n; i++) {
        int roomNumber = rooms.size();
        if (a[i].l > rooms.top().first) {
            roomAssigned[a[i].id] = rooms.top().second;
            rooms.pop();
            rooms.push(mp(a[i].r, roomAssigned[a[i].id]));
        }
        else {
            roomAssigned[a[i].id] = roomNumber + 1;
            rooms.push(mp(a[i].r, roomNumber + 1));
        }
    }

    cout << rooms.size() << '\n';
    for (int i = 0; i < n; i++) {
        cout << roomAssigned[i] << ' ';
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
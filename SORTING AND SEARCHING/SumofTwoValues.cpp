#include<bits/stdc++.h>
#define int long long
#define pb push_back
#define mp make_pair
using namespace std;

const int amax = 1e5 + 69;
const int MOD = 1e9 + 7;
vector<pair<int, int>> a;

int search(int l, int r, int val) {
    while (l <= r) {
        int mid = (l + r)/2;
        if (a[mid].first == val) return mid;
        else if (a[mid].first > val) r = mid - 1;
        else l = mid + 1;
    }
    return -1;
}

void solve() {
    int n, x; cin >> n >> x;
    
    for (int i = 0; i < n; i++) {
        int k; cin >> k;
        a.push_back(mp(k, i + 1));
    }
    sort(a.begin(), a.end());
    for (int i = 0; i < n; i++) {
        int x1 = search(i + 1, n - 1, x - a[i].first);
        if (x1 != -1) {
            cout << a[i].second << ' ' << a[x1].second << '\n';
            return;
        }
    }
    cout << "IMPOSSIBLE\n";
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
#include<bits/stdc++.h>
#define int long long
#define pb push_back
#define mp make_pair
using namespace std;

const int amax = 1e5 + 69;
const int MOD = 1e9 + 7;
int n, t;

bool check (const vector<int>&a, int x) {
    double products = 0;
    for (int i = 0; i < n; i++) {
        products += x / a[i];
    }
    return products >= t;
}

void solve() {
    cin >> n >> t;
    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];

    int l = 1, r = 1e18;
    int mid = (l + r)/2;
    while (l <= r) {
        if (check(a, mid)) r = mid - 1;
        else l = mid + 1;
        mid = (l + r)/2;
    }
    cout << l;
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
#include<bits/stdc++.h>
#define int long long
#define pb push_back
#define mp make_pair
using namespace std;

const int amax = 1e5 + 69;
const int MOD = 1e9 + 7;

struct range {
    int l;
    int r;
    int id;
};

bool cmp (const range &a, const range &b) {
    if (a.l == b.l) return a.r > b.r;
    return a.l < b.l;
}

void solve() {
    int n; cin >> n;

    vector<range> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i].l;
        cin >> a[i].r;
        a[i].id = i;
    }

    sort(a.begin(), a.end(), cmp);
    // for (int i = 0; i < n; i++) cout << a[i].l << ' ' << a[i].r << '\n';

    //contains
    vector<bool> contains(n);
    int rmin = INT_MAX;
    for (int i = n - 1; i >= 0; i--) {
        if (a[i].r >= rmin) contains[a[i].id] = 1; 
        rmin = min(a[i].r, rmin);
    }
    for (int i = 0; i < n; i++) {
        cout << contains[i] << ' ';
    }
    cout << '\n';
    //container
    vector<bool> container(n);
    int rmax = -1;
    for (int i = 0; i < n; i++) {
        if (a[i].r <= rmax) container[a[i].id] = 1; 
        rmax = max(a[i].r, rmax);
    }
    for (int i = 0; i < n; i++) {
        cout << container[i] << ' ';
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
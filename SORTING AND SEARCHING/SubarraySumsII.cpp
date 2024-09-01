#include<bits/stdc++.h>
#define int long long
#define pb push_back
#define mp make_pair
using namespace std;

const int amax = 1e5 + 69;
const int MOD = 1e9 + 7;

bool BinarySearch(const vector<int> &a, int l, int r, int val) {
    int mid;
    while (l <= r) {
        mid = (l + r)/2; 
        if (a[mid] == val) return 1;
        if (a[mid] > val) r = mid - 1;
        else l = mid + 1;
    }
    return 0;
}

void solve() {
    int n, k; cin >> n >> k;
    int sum = 0, res = 0;
    map<int, int> MP;
    MP[0] = 1;
    for (int i = 1; i <= n; i++) {
        int a; cin >> a;
        sum += a;
        res += MP[sum - k];
        MP[sum]++;
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
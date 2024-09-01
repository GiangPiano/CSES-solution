#include<bits/stdc++.h>
#define int long long
#define pb push_back
#define mp make_pair
using namespace std;

const int amax = 1e5 + 69;
const int MOD = 1e9 + 7;
int n, k; 

bool check (const vector<int> &a, int x) {
    int sum = 0, cnt = 1;
    for (int i = 0; i < n; i++) {
        if (sum + a[i] > x) {
            cnt++;
            // cout << "| ";
            sum = 0;
        }
        // cout << a[i] << ' ';
        sum += a[i];
    }
    // cout << '\n';
    return cnt <= k;
}

int BinarySearch (const vector<int> &a, int l, int r) {
    int ans = -1;
    while (l <= r) {
        int mid = (l + r)/2;
        if (check(a, mid)) {
            ans = mid;
            r = mid - 1;
        }
        else l = mid + 1;
    }
    return ans;
}

void solve() {
    cin >> n >> k;
    vector<int> a(n);
    int maxa = INT_MIN, suma = 0;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        maxa = max(maxa, a[i]);
        suma += a[i];
    }
    //cout << maxa << ' ' << suma << ' ';
    int res = BinarySearch(a, maxa, suma);
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
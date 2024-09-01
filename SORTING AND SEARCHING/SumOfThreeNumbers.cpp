#include<bits/stdc++.h>
//#define int long long
#define pb push_back
#define mp make_pair
using namespace std;

const int amax = 1e5 + 69;
const int MOD = 1e9 + 7;

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, k; cin >> n >> k;
    vector<pair<int, int>> a;
    
    for (int i = 0; i < n; i++) {
        int x; cin >> x;
        a.pb(mp(x, i + 1));
    }

    sort(a.begin(), a.end());
    for (int i = 0; i < n - 2; i++) {
        int l = i + 1, r = n - 1;
        while (l < r) {
            if (a[i].first + a[l].first + a[r].first < k) l++;
            else if (a[i].first + a[l].first + a[r].first > k) r--;
            else {
                cout << a[i].second << ' ' << a[l].second << ' ' << a[r].second;
                return 0;
            }
        }
    }

    cout << "IMPOSSIBLE";

    return 0;
}
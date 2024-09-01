#include <bits/stdc++.h>
#define int long long
#define pb push_back
#define mp make_pair
 
using namespace std;
 
void solve() {
    int n, a, b; cin >> n >> a >> b;
    vector<int> arr(n + 1), prefix(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> arr[i];
        prefix[i] = prefix[i - 1] + arr[i];
        //cout << prefix[i];
    }
    
    multiset<int> window;
    int res = 0;
    for (int i = a; i <= n; i++) {
        if (i > b) window.erase(window.find(prefix[i - b - 1]));

        window.insert(prefix[i - a]);
        res = max(res, prefix[i] - *window.begin());
    }
    cout << res;
}
 
signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    solve();
 
    return 0;
}
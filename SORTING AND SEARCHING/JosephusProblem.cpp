#include<bits/stdc++.h>
#define int long long
#define pb push_back
#define mp make_pair
using namespace std;

const int amax = 1e5 + 69;
const int MOD = 1e9 + 7;

void solve() {
    int n; cin >> n;
    deque<int> children;

    for (int i = 1; i <= n; i++) children.pb(i);

    while (children.size() > 1) {
        for (int i = 1; i <= children.size() - (children.size() % 2); i++) {
            if (i % 2 == 0) {
                cout << children.front() << ' ';
                children.pop_front();
            }
            else {
                children.pb(children.front());
                children.pop_front();
            }
        }

    }
    cout << children.front();
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
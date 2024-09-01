#include<bits/stdc++.h>
#define int long long
#define pb push_back
#define mp make_pair
using namespace std;

const int amax = 1e5 + 69;
const int MOD = 1e9 + 7;

void solve() {
    int x, n; cin >> x >> n;
    
    set<int> pos; // Positions of traffic lights
    pos.insert(0);
    pos.insert(x);

    multiset<int> len; // Lengths between traffic lights
    len.insert(x - 0);

    for (int i = 0; i < n; i++) {
        int p; cin >> p;
        pos.insert(p);
        auto it = pos.find(p); // Position of new traffic lights
        int previousPos = *prev(it); 
        int nextPos = *next(it);
        
        len.erase(len.find(nextPos - previousPos)); // Erase the old length after updating the new position
        len.insert(nextPos - p);
        len.insert(p - previousPos);

        cout << *len.rbegin() << ' ';
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
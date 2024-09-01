#include<bits/stdc++.h>
using namespace std;

#define int long long
#define pb push_back
#define mp make_pair

const int amax = 1e6 + 69;
const int MOD = 1e9 + 7;

vector<int> a(amax);
vector<int> b(amax);
void Init() {
    a[1] = 1;
    b[1] = 1;
    for (int i = 2; i < amax; i++) {
        a[i] = (a[i] + 2*a[i - 1] + b[i - 1]) % MOD;
        b[i] = (b[i] + a[i - 1] + 4*b[i - 1]) % MOD;
    }
}

void solve() {
    int n; cin >> n;
    cout << (a[n] + b[n]) % MOD;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    #ifdef GIANGPIANO
    // freopen("INPUT.txt", "r", stdin);
    // freopen("ERROR.txt", "w", stderr);
    // freopen("OUTPUT.txt", "w", stdout);
    #endif

    Init();

    int T = 1; cin >> T;
    while (T--) {
        solve();
        cout << '\n';
    }

    return 0;
}
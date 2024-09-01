#include<bits/stdc++.h>
#define int long long
#define pb push_back
#define mp make_pair
using namespace std;

const int amax = 1e5 + 69;
const int MOD = 1e9 + 7;

void print_queue(std::queue<int> q)
{
  while (!q.empty())
  {
    std::cout << q.front() << " ";
    q.pop();
  }
  std::cout << std::endl;
}


void solve() {
    int n; cin >> n;
    vector<int> a(n);
    map<int, int> freq;

    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    queue<int> q;
    int ans = 1;
    for (int i = 0; i < n; i++) {
        q.push(a[i]);
        freq[a[i]]++;

        if (freq[a[i]] == 2) {
            while (q.front() != a[i]) {
                freq[q.front()]--;
                q.pop();
            }
            freq[q.front()]--;
            q.pop();
        }
        //print_queue(q);
        ans = max(ans, (long long) q.size());
    }
    cout << ans;
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
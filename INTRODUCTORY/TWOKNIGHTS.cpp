#include<bits/stdc++.h>
#define int long long
using namespace std;

const int amax = 1e5 + 69;

void Solve() {
	int x; cin >> x;
	for (int n = 1; n <= x; n++) {
		int total = n*n * (n*n - 1) / 2;
		int cnt = 4 * (n - 1) * (n - 2);
		cout << total - cnt << '\n';
	}
}

signed main() {
 	ios_base::sync_with_stdio(false);
 	cin.tie(nullptr);

	Solve();

 	return 0;
}

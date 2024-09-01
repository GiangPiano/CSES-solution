#include<bits/stdc++.h>
#define int long long
using namespace std;

const int amax = 1e7 + 69;
const int MOD = 1e9 + 7;

void Solve() {
	int n; cin >> n;
	int i = 5, res = 0;
	while (i <= n) {
		res += n/i;
		i *= 5;
	}
	cout << res;
}

signed main() {
 	ios_base::sync_with_stdio(false);
 	cin.tie(nullptr);

	Solve();

 	return 0;
}

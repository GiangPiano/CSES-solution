#include<bits/stdc++.h>
#define int long long
using namespace std;

const int amax = 1e5 + 69;

void Solve() {
	int a, b; cin >> a >> b;
	if (a == 0 && b == 0) {
		cout << "YES\n";
		return;
	}
	else if (a == 0 || b == 0) {
		cout << "NO\n";
		return;
	}
	int h = max(a, b), l = min(a, b);
	if ((a + b) % 3 == 0 && ((h - 1)/l + 1) <= 2) cout << "YES\n";
	else cout << "NO\n";
	return;
}

signed main() {
 	ios_base::sync_with_stdio(false);
 	cin.tie(nullptr);
	
	int T; cin >> T;
	while (T--) {
		Solve();
	}

 	return 0;
}

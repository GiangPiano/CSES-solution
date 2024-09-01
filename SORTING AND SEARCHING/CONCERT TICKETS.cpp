#include<bits/stdc++.h>
#define int long long
using namespace std;

multiset<int> ticket;

void Solve() {
	int n, m; cin >> n >> m;
	for (int i = 0; i < n; i++) {
		int x; cin >> x;
		ticket.insert(x);
	}
	
	
	while (m--) {
		int t; cin >> t;
		auto it = ticket.upper_bound(t);
		if (it == ticket.begin()) cout << -1 << '\n';
		else {
			//cout << it << '\n';
			cout << *(--it) << '\n';
			ticket.erase(it);
		}
	}
}

signed main() {
 	ios_base::sync_with_stdio(false);
 	cin.tie(nullptr);

	Solve();

 	return 0;
}

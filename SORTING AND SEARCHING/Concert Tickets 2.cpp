#include<bits/stdc++.h>
//#define int long long
#define mp make_pair
#define	pb push_back
using namespace std;

const int amax = 1e5 + 69;

void Solve() {
	int n, m; cin >> n >> m;
	multiset <int> a;
	for (int i = 0; i < n; i++) {
		int x; cin >> x;
		a.insert(x);
	}
	a.insert(-1);
	/*
	for (auto it : a) {
		cout << it << '\n';
	}
	*/
	while (m--) {
		int x; cin >> x;
		auto it = *(--a.upper_bound(x));
		cout << it;
		if (it != -1) {
			a.erase(--a.upper_bound(x));	
		}
		cout << '\n';
	}
	
}

signed main() {
 	ios_base::sync_with_stdio(false);
 	cin.tie(nullptr);

	Solve();

 	return 0;
}

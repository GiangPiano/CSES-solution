#include<bits/stdc++.h>
#define int long long
#define mp make_pair
#define	pb push_back
using namespace std;

const int amax = 1e5 + 69;

void Solve() {
	int n, x; cin >> n >> x;
	vector<int> a(n);
	for (int i = 0; i < n; i++) cin >> a[i];
	sort(a.begin(), a.end(), greater<int>());
	int cnt = 0, first = 0, last = n-1;
	while (first <= last) {
		if (a[first] + a[last] <= x) {
			last--;
		}
		cnt++; 
		first++;
	}
	cout << cnt;
}

signed main() {
 	ios_base::sync_with_stdio(false);
 	cin.tie(nullptr);

	Solve();

 	return 0;
}

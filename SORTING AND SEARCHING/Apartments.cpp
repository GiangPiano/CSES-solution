#include<bits/stdc++.h>
#define int long long
#define mp make_pair
#define	pb push_back
using namespace std;

const int amax = 1e5 + 69;

void Solve() {
	int n, m, k; cin >> n >> m >> k;
	vector<int> a(n), b(m);
	
	for (int i = 0; i < n; i++) 
		cin >> a[i];
	for (int i = 0; i < m; i++) 
		cin >> b[i];
	
	sort(a.begin(), a.end());
	sort(b.begin(), b.end());
	//for (auto it : b) cout << it;
	int cnt = 0;
	int i = 0, j = 0;
	
	while (i < n && j < m) {
		//cout << a[i] << ' ' << b[j] << '\n';
		if (a[i] - k > b[j]) j++;
		else if (a[i] + k < b[j]) i++;
		else {
			cnt++;
			i++; j++;
		}
	}
	cout << cnt;
}

signed main() {
 	ios_base::sync_with_stdio(false);
 	cin.tie(nullptr);

	Solve();

 	return 0;
}

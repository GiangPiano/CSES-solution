#include<bits/stdc++.h>
#define int long long
#define mp make_pair
#define	pb push_back
using namespace std;

const int amax = 2e5 + 69;
const int LOG = 18;
int n;
int a[amax];
int suffix[amax];


void Solve() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	suffix[n] = -1;
	for (int i = n - 1; i >= 0; i--) {
		suffix[i] = max(suffix[i + 1], a[i]);
	}
	int res = -1;
	for (int i = 0; i < n; i++) {
		for (int j = i + 1; j < n; j++) {
			int ak = suffix[j + 1];
			if (a[i] < a[j] && a[j] < ak) 
				res = max(res, a[i] + a[j] + ak);
		}
	}
	cout << res;
}

signed main() {
 	ios_base::sync_with_stdio(false);
 	cin.tie(nullptr);

	Solve();

 	return 0;
}

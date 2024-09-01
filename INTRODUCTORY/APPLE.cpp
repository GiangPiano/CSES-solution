#include<bits/stdc++.h>
#define int long long
using namespace std;

const int amax = 1e5 + 69;
int n, sum = 0;
int a[amax], res = INT_MAX;

int Try(int i, int curr) {
	if (i == 0) return abs((sum - curr) - curr);
	return min(Try(i - 1, curr), Try(i - 1, curr + a[i]));
}

void Solve() {

	cin >> n;
	
	
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		sum += a[i];
	}
	cout << Try(n - 1, 0);

}

signed main() {
 	ios_base::sync_with_stdio(false);
 	cin.tie(nullptr);

	Solve();

 	return 0;
}

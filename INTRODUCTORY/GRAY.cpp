#include<bits/stdc++.h>
#define int long long
using namespace std;

const int amax = 1e5 + 69;
vector<string> a;

void Solve() {
	int n, cnt = 0; cin >> n;
	a.push_back("0");
	a.push_back("1");
	int times = 1 << n;
	//cout << times << '\n';
	for (int i = 2; i < times; i *= 2) {
		
		for (int j = i - 1; j >= 0; j--) {
			a.push_back(a[j]);
		}	
					
		for (int j = 0; j < i; j++) {
			a[j] = "0" + a[j];
		}
		
		for (int j = i; j < 2 * i; j++) {
			a[j] = "1" + a[j];
		}
	}
	//cout << cnt << '\n';
	for (int k = 0; k < times; k++) cout << a[k] << '\n';
}

signed main() {
 	ios_base::sync_with_stdio(false);
 	cin.tie(nullptr);

	Solve();

 	return 0;
}

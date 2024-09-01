#include<bits/stdc++.h>
#define int long long
using namespace std;

const int amax = 1e4 + 69;
int cnt[amax] = {}, chk[amax] = {};
int cntOdd = 0;

void Solve() {
	string s; cin >> s;
	int n = s.length();
	//cout << n;
	for (int i = 0; i < n; i++) {
		cnt[s[i]]++;
		//cout << cnt[s[i]] << ' ';	
	}
	
	for (int i = 0; i < n; i++) {
		if (cnt[s[i]] % 2 != 0 && chk[s[i]] == 0) {
			chk[s[i]] = 1;
			cntOdd++;
		}
	}
	if (cntOdd > 1) {
		cout << "NO SOLUTION";
		return;
	}
	string res (n, ' ');
	int j = 0;
	for (int i = 0; i < n; i++) {
		//cout << cnt[s[i]] << ' ';
		if (cnt[s[i]] >= 2) {
			res[j] = s[i];
			res[n - 1 - j] = s[i];
			cnt[s[i]] -= 2;
			j++;
		}
		else if (cnt[s[i]] == 1) {
			res[n / 2] = s[i];
			cnt[s[i]] -= 1;
		}
	}
	for (int i = 0; i < n; i++) cout << res[i];
}

signed main() {
 	ios_base::sync_with_stdio(false);
 	cin.tie(nullptr);
	//freopen("PALIN.txt", "r",stdin);
	
	Solve();

 	return 0;
}

#include<bits/stdc++.h>
#define int long long
#define mp make_pair
#define	pb push_back
using namespace std;

const int amax = 2e5 + 69;
const int LOG = 18;
int a[amax];
int n;
int rMax[amax][LOG], rMin[amax][LOG];
int bin_log[amax];

void binLogPrecompute () {
	bin_log[1] = 0;
	for (int i = 2; i <= n; i++) {
		bin_log[i] = bin_log[i/2] + 1;
	}
}

int RMQ (int l, int r) {
	int len = r - l + 1;
	int j = bin_log[len];
	//cout << rMax[l][j] << ' ' << rMax[r - (1 << j) + 1][j] << ' ';
	return min(rMin[l][j], rMin[r - (1 << j) + 1][j]);
}

void rangeMinPrecompute () {
	for (int j = 1; j < LOG; j++) {
		for (int i = 0; i + (1 << j) - 1 < n; i++) {
			rMin[i][j] = min(rMin[i][j - 1], rMin[i + (1 << (j - 1))][j - 1]);
			rMax[i][j] = max(rMax[i][j - 1], rMax[i + (1 << (j - 1))][j - 1]);
		}
	}
}

int RMxQ (int l, int r) {
	int len = r - l + 1;
	int j = bin_log[len];
	//cout << rMax[l][j] << ' ' << rMax[r - (1 << j) + 1][j] << ' ';
	return max(rMax[l][j], rMax[r - (1 << j) + 1][j]);
}

void Solve() {

	
	set <pair<int, int>> id;
	
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		rMax[i][0] = a[i];
		rMin[i][0] = a[i];
		id.insert(mp(a[i], i));
	}
	
	rangeMinPrecompute();
	binLogPrecompute();
	
	int Q; cin >> Q;
	while (Q--) {
		int x, y; cin >> x >> y;
		x--; y--;
		if (RMxQ(x, y) != RMQ(x, y)) {
			auto it1 = id.lower_bound(mp(RMxQ(x, y), x));
			auto it2 = id.lower_bound(mp(RMQ(x, y), x));
			cout << it1 -> second + 1 << ' ' << it2 -> second + 1;
		}
		else cout << "-1 -1";
		cout << '\n';
	}
}

signed main() {
 	ios_base::sync_with_stdio(false);
 	cin.tie(nullptr);
	
	int T; cin >> T;
	while (T--) {
		Solve();
		cout << '\n';
	}
	

 	return 0;
}

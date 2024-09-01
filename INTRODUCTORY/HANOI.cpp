#include<bits/stdc++.h>
#define int long long
using namespace std;

const int amax = 1e5 + 69;
int n;
vector<pair <int, int>> res;
void Move(int n, int start, int dest, int aux) {
	if (n == 1) {
		res.push_back(make_pair(start, dest));
		return;
	}
	Move(n - 1, start, aux, dest);
	res.push_back(make_pair(start, dest));
	Move(n - 1, aux, dest, start);
}

void Solve() {
	cin >> n;
	Move(n, 1, 3, 2);
	cout << res.size() << '\n';
	for (int i = 0; i < res.size(); i++) cout << res[i].first << ' ' << res[i].second << '\n';
}

signed main() {
 	ios_base::sync_with_stdio(false);
 	cin.tie(nullptr);

	Solve();

 	return 0;
}

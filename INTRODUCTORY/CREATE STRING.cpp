#include <bits/stdc++.h>
using namespace std;
 
const int amax = 30;
string s;
int cnt = 0;
vector<string> res;
 
int binSearch(int l, int r, char x) //return index of the smallest value larger than x
{
    int res;
    while (l <= r)
    {
        int mid = (l + r)/2;
        if (s[mid] > x)
        {
            res = mid;
            l = mid + 1;
        }
        else
        {
            r = mid - 1;
        }
    }
    return res;
}
 
 
 
void reverse (int l, int r) {
	while (l < r) {
		swap(s[l], s[r]);
		l++; r--;
	}
}
void solve() {
	cin >> s;
	int n = s.length();
	sort(s.begin(), s.end());
	
	bool Done = 0;
	while (!Done) {
		cnt++;
		res.push_back(s);
		int i;
		for (i = n - 2; i >= 0; i--) {
			if (s[i] < s[i+1]) break;
		}
		if (i == -1) Done = 1;
		else {
			int k = binSearch(i + 1, n - 1, s[i]);
			
			swap(s[i], s[k]);
			reverse(i + 1, n -1);
		}
	}
	cout << cnt << '\n';
	for (int i = 0; i < res.size(); i++) cout << res[i] << '\n';
}
 
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
   	solve();
    return 0;
}
#include <bits/stdc++.h>
using namespace std;

const int amax = 100;
int n;
bool a[amax], b[amax], c[amax], chk[amax][amax];
int x[amax];
int cnt = 0;

void Try(int i)
{
    for (int j = 1; j <= n; j++)
    {
        if (a[j] == 1 && b[i + j] == 1 && c[i - j + n] == 1 && !chk[i][j])
        {
            x[i] = j;
            if (i == n)
            {
                cnt++;
            }
            a[j] = false; b[i + j] = false; c[i - j + n] = false;
            Try(i + 1);
            a[j] = true; b[i + j] = true; c[i - j + n] = true;
        }
    }
    //cout << 1;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    n = 8;
    fill(a, a + 50, true);
    fill(b, b + 50, true);
    fill(c, c + 50, true);
    for (int i = 1; i <= 8; i++) {
    	for (int j = 1; j <= 8; j++) {
    		char x; cin >> x;
    		if (x == '*') chk[i][j] = 1;
		}
	}
    Try(1);
    cout << cnt;
    return 0;
}
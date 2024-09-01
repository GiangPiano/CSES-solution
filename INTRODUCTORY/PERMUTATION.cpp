#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n; cin >> n;
    if (n == 1) cout << 1;
    else if (n <= 3) cout << "NO SOLUTION";
    else
    {
        for (int i = 1; i <= n; i++)
        {
            if (i % 2 == 0) cout << i << ' ';
        }
        for (int i = 1; i <= n; i++)
        {
            if (i % 2) cout << i << ' ';
        }
    }

    return 0;
}

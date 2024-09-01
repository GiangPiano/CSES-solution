#include <bits/stdc++.h>
#define int long long
using namespace std;
string s;
bool visited[7][7] = {};
int step = 0, path = 0;

void Try(int r, int c) {
    //success
    if (r == 6 && c == 0) {
        if (step == 48) {
            path++;
            //cout << path << '\n';
        return;
		}
	}
    
    
    //check
    if (visited[r][c] ||
    	((c >= 1 && c <= 5 && !visited[r][c + 1] && !visited[r][c - 1] &&
        ((r == 0 && visited[r + 1][c]) || (r == 6 && visited[r - 1][c]))) ||
        ((r >= 1 && r <= 5 && !visited[r + 1][c] && !visited[r - 1][c]) &&
        ((c == 0 && visited[r][c + 1]) || (c == 6 && visited[r][c - 1]))))
        || ((c >= 1 && c <= 5 && r >= 1 && r <= 5) &&
        ((visited[r + 1][c] && visited[r - 1][c] && !visited[r][c - 1] && !visited[r][c + 1]) ||
        (!visited[r + 1][c] && !visited[r - 1][c] && visited[r][c - 1] && visited[r][c + 1]))))
        return;
        
    
	
    visited[r][c] = 1;
    //cout << s[step];
	if (s[step] != '?') {
		switch (s[step]) {
			case 'D':
				if (r < 6 && !visited[r + 1][c]) {
			    	//cout << step << ' ';
			        step++;
			        Try(r + 1, c); //down
			        step--;
			    	}
		    	break;
		    case 'U':
		    	if (r > 0 && !visited[r - 1][c]) {
			        step++;
			        Try(r - 1, c); //up
			        step--;
			    }
		    	break;
		    case 'R':
		    	if (c < 6 && !visited[r][c + 1]) {
			        step++;
			        Try(r, c + 1); //right
			        step--;
			    }
		    	break;
		    case 'L':
		    	if (c > 0 && !visited[r][c - 1]) {
			        step++;
			        Try(r, c - 1); //left
			        step--;
			    }
		    	break;
		}
		visited[r][c] = 0;
		return;
	}
	
	
    if (r < 6 && !visited[r + 1][c]) {
    	//cout << step << ' ';
        step++;
        Try(r + 1, c); //down
        step--;
    }
    if (r > 0 && !visited[r - 1][c]) {
        step++;
        Try(r - 1, c); //up
        step--;
    }
    if (c < 6 && !visited[r][c + 1]) {
        step++;
        Try(r, c + 1); //right
        step--;
    }
    if (c > 0 && !visited[r][c - 1]) {
        step++;
        Try(r, c - 1); //left
        step--;
    }
    visited[r][c] = 0;
}

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    cin >> s;
    Try(0, 0);
    cout << path;
    return 0;
}

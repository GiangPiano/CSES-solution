#include <bits/stdc++.h>
#define int long long
using namespace std;
const int amax = 1e5 + 69;
int n, numDigit;
int digitPos[amax];
int powerTen[19];
int startNum;
void init() {
    powerTen[0] = 1;
    for (int i = 1; i <= 18; i++) {
        powerTen[i] = powerTen[i - 1] *10;
    }
}
 
int numPos(int x) {
    return ((x - startNum) * numDigit + digitPos[numDigit - 1] + 1);
}
 
int Search(int l, int r, int x) {
    int mid = (l + r)/2;
    while (l <= r) {
        if (numPos(mid) <= x) l = mid + 1;
        else r = mid - 1;
        mid = (l + r) / 2;
        //cout << mid << ' ';
    }
    //cerr << r << ' ';
    return r;
}
 
 
int Digit (int n) {
    int cnt = 1;
    digitPos[1] = 9;
    int i = 1, tmp = 10;
    while (n > digitPos[i]) {
        i++;
        cnt++;
        digitPos[i] = digitPos[i - 1] + 9 * tmp * cnt;
        tmp *= 10;
    }
    return cnt;
}
 
 
void solve() {
    cin >> n;
    
    numDigit = Digit(n);
    startNum = powerTen[numDigit - 1];
    int numn = Search(powerTen[numDigit - 1], powerTen[numDigit] - 1, n);
    
    cerr << digitPos[numDigit] << ' ' << numDigit << ' ' << startNum << ' ' << numn << ' ' << numPos(numn) << '\n';
    int temp = numn;
    string s = to_string(numn);
    cout << s[n - numPos(numn)];
}
 
 
signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    init();
    
    int T; cin >> T;
    while (T--) {
        solve();
        cout << '\n';
    }
    return 0;
}
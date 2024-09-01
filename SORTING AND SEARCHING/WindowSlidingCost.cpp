#include<bits/stdc++.h>
using namespace std;

#define pb push_back
#define mp make_pair

const long long amax = 1e5 + 69;
const long long MOD = 1e9 + 7;

long long n, k; 
multiset<long long> low;
multiset<long long> high;
long long lowSum = 0, highSum = 0;

long long cost() {
    long long median = *low.rbegin();
    long long lowCost = (median * (long long)low.size()) - lowSum;
    long long highCost = highSum - (median * (long long)high.size());
    //cout << highSum << ' ' << lowSum << '\n';
    //return highSum - lowSum + (k % 2 == 0 ? 0 : median);
    return lowCost + highCost;
}

void windowInsert (long long val) {
    if (val > *low.begin()) {
        high.insert(val);
        highSum += val;
        if (high.size() > k / 2) {
            low.insert(*high.begin());
            highSum -= *high.begin();
            lowSum += *high.begin();
            high.erase(high.find(*high.begin()));
        }
    }
    else {
        low.insert(val);
        lowSum += val;
        if (low.size() > (k - 1) / 2 + 1) {
            high.insert(*(--low.end()));
            lowSum -= *(--low.end());
            highSum += *(--low.end());
            low.erase(--low.end());
        }
    }
}

void windowErase (long long val) {
    if (val > *low.rbegin()) {
        high.erase(high.find(val));
        highSum -= val;
        if (high.size() < low.size() - 1) {
            high.insert(*(--low.end()));
            lowSum -= *(--low.end());
            highSum += *(--low.end());
            low.erase(--low.end());
        }
    }
    else {
        low.erase(low.find(val));
        lowSum -= val;
        if (low.size() < high.size()) {
            low.insert(*high.begin());
            highSum -= *high.begin();
            lowSum += *high.begin();
            high.erase(high.begin());
        }
    }
}

void solve() {
    cin >> n >> k;
    vector<long long> a(n);

    for (long long i = 0; i < n; i++) cin >> a[i];

    for (long long i = 0; i < k; i++) windowInsert(a[i]);
    //cout << lowSum << ' ' << highSum << ' ' << low.size() << ' ' << high.size() << '\n';
    //cout << low.size() << ' ' << lowSum << ' ' << highSum << ' ' << high.size() << ' ' << *low.rbegin() << '\n';
    cout << cost() << ' ';
    for (long long i = k; i < n; i++) {
        windowErase(a[i - k]);
        windowInsert(a[i]);
        cout << cost() << ' ';
    }
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    #ifdef GIANGPIANO
    freopen("INPUT.txt", "r", stdin);
    freopen("ERROR.txt", "w", stderr);
    freopen("OUTPUT.txt", "w", stdout);
    #endif
    long long T = 1; // cin >> T;
    while (T--) {
        solve();
    }

    return 0;
}
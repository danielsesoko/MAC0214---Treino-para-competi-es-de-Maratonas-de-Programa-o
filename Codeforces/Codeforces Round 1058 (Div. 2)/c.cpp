#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define fastio(); ios_base::sync_with_stdio(0); cin.tie(0)
#define endl '\n'
#define int long long

void solve();

signed main() {
	fastio();
	int t; cin >> t;
	while (t--) solve();	
}

void solve() {
	int n; cin >> n;
	while (n % 2 == 0 and n > 0) n /= 2;
	
	if (n == 0) {
		cout << "YES" << endl;
		return;
	}
	
	int s[30];
	
	int m = 0;
	while (n > 0) {
		if (n % 2 == 0) s[m] = 0;
		else s[m] = 1;
		n /= 2;
		m++;
	}
	
	int l = 0, r = m-1;

	while (l <= r) {
		if (l == r and s[l] == 1) {
			cout << "NO" << endl;
			return;
		}
		if (s[l] != s[r]) {
			cout << "NO" << endl;
			return;
		}
		l++;
		r--;
	}

	cout << "YES" << endl;
}

#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define fastio() ios_base::sync_with_stdio(0); cin.tie(0)

void solve();

signed main() {
	fastio();
	int t; cin >> t;
	while (t--) solve();
}

void solve() {
	int n; cin >> n;
	vector<ll> a(n);
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	
	bool flag = 0;
	for (ll i = 2; i < 1e4; i++) {
		for (int j = 0; j < n; j++) {
			if (__gcd(i, a[j]) == 1) {
				cout << i << '\n';
				flag = 1;
				break;
			}
		}
		if (flag) break;
	}
}

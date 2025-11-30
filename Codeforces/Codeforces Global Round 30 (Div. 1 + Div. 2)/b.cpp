#include<bits/stdc++.h>
using namespace std;

using ll = long long;
#define fastio() ios_base::sync_with_stdio(0); cin.tie(0)
#define int long long

void solve();

signed main() {
	fastio();
	int t; cin >> t;
	while (t--) solve();	
}

void solve() {
	int n; cin >> n;
	vector<int> a(n), p, o;
	for (int i = 0; i < n; i++) {
		cin >> a[i];	
		if (a[i] % 2 == 0) p.push_back(a[i]);
		else o.push_back(a[i]);
	}

	if (p.size() >= 2) {
		cout << p[0] << " " << p[1] << '\n';
		return;
	}

	if (p.size() == 1) {
		for (int i = 0; i < n; i++) {
			if (a[i] == p[0]) continue;
			if ((a[i] % p[0]) % 2 == 0) {
				cout << p[0] << " " << a[i] << '\n';
				return;
			}
		}
	}

	if (n > 100) {
		for (int i = 0; i < o.size(); i++) {
			if ((o[i+1] % o[i]) % 2 == 0) {
				cout << o[i] << " " << o[i+1] << '\n';
				return;
			}
		}
		return;
	}
	
	for (int i = 0; i < n; i++) {
		for (int j = i+1; j < n; j++) {
			if ((a[j] % a[i]) % 2 == 0) {
				cout << a[i] << " " << a[j] << '\n';
				return;
			}
		}
	}
	cout << -1 << '\n';
}

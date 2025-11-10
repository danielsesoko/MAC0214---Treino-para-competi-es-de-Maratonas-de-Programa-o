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
	vector<int> f(n+1, 0), a(n);
	for (int i = 0; i < n; i++) {
		int t; cin >> t;
		f[t]++;
		a[i] = t;
	}
	sort(a.begin(), a.end());

	int o = 0;
	for (int i = 1; i <= n; i++) {
		if (f[i] % 2) o++;
	}

	bool flag = false;
	if (n % 2) {
		if (o == 1) {
			if (f[a[0]] % 2) flag = true;	
		}		
	}
	else {
		if (o == 0) {
			flag = true;
			for (int i = 0; i < n; i++) {
				if (a[i] != a[0]) flag = false;
			}
		}

		if (o == 2) {
			if (f[a[0]] % 2 and f[a[n-1]] % 2) flag = true;	
		}
	}

	if (flag) cout << "YES\n";
	else cout << "NO\n";	
}

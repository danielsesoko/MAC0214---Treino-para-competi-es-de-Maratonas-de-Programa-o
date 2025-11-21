#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define fastio() ios_base::sync_with_stdio(0); cin.tie(0)
#define endl '\n'
#define int long long

void solve();

signed main() {
	fastio();
	int t; cin >> t;
	while (t--) solve();
}

void solve() {
	int a, b, n; cin >> a >> b >> n;
	if (b * n <= a) {
		cout << 1 << endl;
		return;
	}

	int x = n+1;
	int l = 1, r = n;

	while (l <= r) {
		int m = (l + r)/2;

		if (a < b * m) {
			x = min(m, x);
			r = m - 1;
		}
		else {
			l = m + 1;
		}
	}
	int resp = 1;
	if (a != b) resp++;	
	cout << resp << endl;
}

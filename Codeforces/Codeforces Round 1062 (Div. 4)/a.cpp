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
	int a[4];
	bool flag = true;
	for (int i = 0; i < 4; i++) {
		cin >> a[i];
		if (i > 0 and a[i] != a[0]) flag = false;
	}

	if (flag) cout << "YES\n";
	else cout << "NO\n";
}

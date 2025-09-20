#include<bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
	int x, y; cin >> x >> y;
	int resp = -1;
	if (x < y) resp = 2;
	if (x >= y + 2 and y != 1) resp = 3;

	cout << resp << '\n';
}

signed main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	int t = 1; cin >> t;
	while (t--) solve();
}

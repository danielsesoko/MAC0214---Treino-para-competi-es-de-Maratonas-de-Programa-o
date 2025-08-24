#include<bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
	int n; cin >> n;
	int a[n], b[n];
	for (int i = 0; i < n; i++) cin >> a[i];
	for (int i = 0; i < n; i++) cin >> b[i];
	
	int resp = 0;
	for (int i = 0; i < n; i++) {
		if (a[i] > b[i]) resp += (a[i] - b[i]);
	}

	cout << resp + 1 << '\n';
}

signed main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	int tt; cin >> tt;
	while (tt--) solve();
}

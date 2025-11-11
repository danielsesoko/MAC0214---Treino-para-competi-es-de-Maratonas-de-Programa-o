#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define fastio() ios_base::sync_with_stdio(0); cin.tie(0)
#define endl '\n';

void solve();

signed main() {
	fastio();
	int t; cin >> t;
	while (t--) solve();
}

void solve() {
	int n; cin >> n;
	vector<int> a(n);
	int p = 0;
	int resp = 0;
	for (int i = 0; i < n; i++) {
		int t; cin >> t;
		if (t == 0) resp++;
		if (t == -1) p++;
	}

	if (p % 2) resp+=2;

	cout << resp << endl;
}

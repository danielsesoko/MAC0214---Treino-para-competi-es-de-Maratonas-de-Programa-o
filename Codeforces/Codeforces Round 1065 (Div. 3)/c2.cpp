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
	vector<int> a(n), b(n);
	for (int i = 0; i < n; i++) cin >> a[i];
	for (int i = 0; i < n; i++) cin >> b[i];

	int xor_total = 0;

	for (int i = 0; i < n; i++) {
		xor_total ^= a[i];
		xor_total ^= b[i];
	}
	
	int bp = 0;
	for (int i = 20; i >= 0; i--) {
		if (xor_total & (1<<i)) {
			bp = i;
			break;	
		}
	}
	
	int resp = 0;
	for (int i = n-1; i >= 0; i--) {
		int conta = 0;
		if (a[i] & (1<<bp)) conta++;
		if (b[i] & (1<<bp)) conta++;

		if (conta == 1) {
			resp = (i + 1) % 2;
			break;
		}
	}
	
	if (xor_total == 0) cout << "Tie\n";
	else if (resp % 2 == 1) cout <<"Ajisai\n";
	else cout << "Mai\n";
}

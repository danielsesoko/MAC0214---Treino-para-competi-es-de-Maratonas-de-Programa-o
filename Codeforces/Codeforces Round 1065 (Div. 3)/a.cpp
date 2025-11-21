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
	
	int resp = 0;
	for (int i = 0; i <= 50; i++) {
		int resto = n - i * 2;
		if (resto >= 0 and resto % 4 == 0) resp++;
	}	

	cout << resp << '\n';
}

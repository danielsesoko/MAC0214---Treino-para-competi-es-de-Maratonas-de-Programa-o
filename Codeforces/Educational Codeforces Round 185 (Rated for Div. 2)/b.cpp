#include<bits/stdc++.h>
using namespace std;

#define int long long
#define fastio() ios_base::sync_with_stdio(0); cin.tie(0)
#define endl '\n'

void solve();

signed main() {
	int t; cin >> t;
	while (t--) solve();
}

void solve() {
	int n; cin >> n;
	int total = 0, qtd = 0;

	for (int i = 0; i < n; i++) {
		int b; cin >> b;
		total += b;
		if (b != 0) qtd++;
	}

	if (total - qtd < n-1) qtd = total - (n-1);	
	cout << qtd << endl;
}

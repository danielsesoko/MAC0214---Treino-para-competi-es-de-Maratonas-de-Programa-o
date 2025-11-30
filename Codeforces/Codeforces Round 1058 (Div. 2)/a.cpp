#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define fastio(); ios_base::sync_with_stdio(0); cin.tie(0)
#define endl '\n'

void solve();

signed main() {
	fastio();
	int t; cin >> t;
	while (t--) solve();	
}

void solve() {
	int n; cin >> n;
	vector<bool> in(110);
	
	for (int i = 1; i <= n; i++) {
		int t; cin >> t;
		in[t] = 1;
	}

	for (int i = 0; i <= 101; i++) {
		if (!in[i]) {
			cout << i << endl;
			return;
		}	
	}	
}

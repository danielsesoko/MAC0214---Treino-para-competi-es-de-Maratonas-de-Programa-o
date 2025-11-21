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
	vector<int> p(n), f(n);
       	vector<bool> seen(n);
	vector<pair<int, int>> e;

	for (int i = 0; i < n; i++) {
		cin >> p[i];
		f[--p[i]] = i;
	}
	
	bool resp = true;	
	int last = n, maior = -1;	
	for (int i = 0; i < n; i++) {
		if (seen[i]) continue;
		if (i > maior and maior != -1) {
			resp = false;
			break;
		}
		if (maior != -1) e.push_back({i, maior});

		maior = max(maior, i);
		for (int j = f[i] + 1; j < last; j++) {
			seen[p[j]] = true;
			maior = max(maior, p[j]);
			e.push_back({i, p[j]});
		}
		last = f[i];
	}

	if (resp) {
		cout << "YES\n";
	}
	else cout << "NO\n";	
}

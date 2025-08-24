#include<bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
	int n, k; cin >> n >> k;
	vector<int> restos;
	map<int, int> restos1, restos2;

	for (int i = 0; i < n; i++) {
		int s; cin >> s;
		restos1[s%k]++;	
		restos.emplace_back(s%k);
	}

	for (int i = 0; i < n; i++) {
		int t; cin >> t;
		restos2[t%k]++;	
		restos.emplace_back(t%k);
	}
	
	bool resp = true;
	for (auto r: restos) {
		if (restos1[r] + restos1[k-r] != restos2[r] + restos2[k-r]) resp = false;
	}

	if (resp) cout << "YES\n";
	else cout << "NO\n";
}

signed main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	int tt; cin >> tt;
	while (tt--) solve();
}

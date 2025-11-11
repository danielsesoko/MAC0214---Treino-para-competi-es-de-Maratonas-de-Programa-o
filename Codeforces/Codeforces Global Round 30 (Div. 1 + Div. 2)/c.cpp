#include<bits/stdc++.h>
using namespace std;

using ll = long long;
#define fastio() ios_base::sync_with_stdio(0); cin.tie(0)

void solve();

signed main() {
	fastio();
	int t; cin >> t;
	while (t-- ) solve();
}

int n, m;

void solve() {
	map<int, int> a;
	vector<int> b, c, b0;
	vector<pair<int, int>> bc;

	cin >> n >> m;
	int t;
	for (int i = 0; i < n; i++) {
		cin >> t;
		a[t]++;
	}
	for (int i = 0; i < m; i++) {
		cin >> t;
		b.emplace_back(t);
	}
	for (int i = 0; i < m; i++) {
		cin >> t;
		c.emplace_back(t);
	}
	for (int i = 0; i < m; i++) {
		if (c[i] == 0) {
			b0.push_back(b[i]);
			continue;
		}
		bc.push_back({b[i], -c[i]});
	}
	sort(bc.begin(), bc.end());	
	int resp = 0;
	for (auto [x, y] : bc) {
		auto it = a.lower_bound(x);
		if (it == a.end()) continue;
		a[it->first]--;	
		if (it->second == 0) a.erase(it);		
		resp++;
		if (y == 0) continue;
		a[max(it->first, -y)]++;
	}
	
	sort(b0.begin(), b0.end());
	for (auto x: b0) {
		auto it = a.lower_bound(x);
		if (it == a.end()) continue;
		a[it->first]--;
		if (it->second == 0) a.erase(it);
		resp++;
	}
	cout << resp << '\n';
}

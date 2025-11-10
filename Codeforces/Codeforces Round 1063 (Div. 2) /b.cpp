#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define fastio() ios_base::sync_with_stdio(0); cin.tie(0)
#define endl '\n'

void solve();

signed main() {
	fastio();
	int t; cin >> t;
	while (t--) solve();
}

void solve() {
	int n; cin >> n;
	vector<int> p(n);
	int p1, pn;
	//input
	for (int i = 0; i < n; i++) {
		cin >> p[i];	
		if (p[i] == 1) p1 = i+1;
		if (p[i] == n) pn = i+1;
	}
	string x; cin >> x;
	if (x[0] == '1' or x[n-1] == '1' or x[p1-1] == '1' or x[pn-1] == '1') {
		cout << -1 << endl;
		return;
	}
	
	int k = 0;
	vector<pair<int, int>> out;
	if (p1 != 1) {
		out.push_back({1, p1});
		k++;
	}
	if (p1 != n) {
		out.push_back({p1, n});
		k++;
	}
	if (pn != 1) {
		out.push_back({1, pn});
		k++;
	}
	if (pn != n) {
		out.push_back({pn, n});
		k++;
	}
	out.push_back({min(p1, pn), max(p1, pn)});
	
	cout << ++k << endl;
	for (auto [a, b]: out) {
		cout << a << " " << b << endl;
	}
}

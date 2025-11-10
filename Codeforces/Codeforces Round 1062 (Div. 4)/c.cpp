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
	vector<int> a(n);
	bool e = false, o = false;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		if (a[i] % 2) o = true;
		else e = true;
	}

	if (o and e) sort(a.begin(), a.end());

	for (int i = 0; i < n; i++) cout << a[i] << " ";
	cout << '\n';
}

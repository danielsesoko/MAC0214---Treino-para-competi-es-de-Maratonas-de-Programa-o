#include<bits/stdc++.h>
using namespace std;

#define fastio() ios_base::sync_with_stdio(0); cin.tie(0)
#define endl '\n'
#define int long long

void solve();

signed main() {
	fastio();
	int t; cin >> t;
	while (t--) solve();
}

void solve() {
	int n; cin >> n;
	set<int> s;
	for (int i = 0; i < n; i++) {
		int b; cin >> b;
		s.insert(b);
	}

	cout << s.size() << endl;
}

#include<bits/stdc++.h>
using namespace std;
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
	if (n % 2 == 0) cout << (n-2)/2 << endl;
	else cout << (n-1)/2 << endl;
}

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
	cout << (3 - n % 3) % 3 << endl;
}

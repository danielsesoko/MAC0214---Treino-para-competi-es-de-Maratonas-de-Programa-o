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
	int x, y, z; cin >> x >> y >> z;
	int a = (x | z), b = (x | y), c = (y | z);

	if (x == (a & b) and y == (b & c) and z == (a & c)) cout << "YES\n";
	else cout << "NO\n";
}

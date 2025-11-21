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
	string s; cin >> s;

	char chosen = s[n-1];
	
	int resp = 0;
	for (auto c: s) {
		if (c != s[n-1]) resp++;	
	}
	cout << resp << endl;	
}

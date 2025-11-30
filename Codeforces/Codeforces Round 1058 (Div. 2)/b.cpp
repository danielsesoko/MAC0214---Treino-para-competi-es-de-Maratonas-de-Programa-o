#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define fastio(); ios_base::sync_with_stdio(0); cin.tie(0)
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
	vector<int> b(n), a(n);
	for (int i = 0; i < n; i++) cin >> b[i];		
		
	a[0] = 1;
	for (int i = 1; i < n; i++) {
		int diff = b[i] - b[i-1];
		if (i - diff >= 0) a[i] = a[i - diff];
		else a[i] = i+1;
	}

	for (int i = 0; i < n; i++) cout << a[i] << " ";
	cout << endl;	
}

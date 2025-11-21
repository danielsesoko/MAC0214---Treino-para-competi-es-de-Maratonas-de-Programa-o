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
	for (int i = 0; i < n; i++) cin >> a[i];
	for (int i = 1; i < n-1; i++) {
		if (a[i] == -1) a[i] = 0; 
	}

	if (a[0] != -1 and a[n-1] != -1) {
		cout << abs(a[n-1] - a[0]);	
	}
	else if (a[0] != -1 and a[n-1] == -1) {
		cout << 0;
		a[n-1] = a[0];
	}
	else if (a[0] == -1 and a[n-1] != -1) {
		cout << 0;
		a[0] = a[n-1];
	}
	else {
		cout << 0;
		a[0] = 0;
		a[n-1] = 0;
	}
	
	cout << '\n';
	for (int i = 0; i < n; i++) cout << a[i] << ' ';
	cout << '\n';	
}

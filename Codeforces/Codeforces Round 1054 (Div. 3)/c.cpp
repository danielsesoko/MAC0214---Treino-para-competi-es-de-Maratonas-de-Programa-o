#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define fastio() ios_base::sync_with_stdio(0); cin.tie(0)
#define endl '\n';

void solve();

signed main() {
	fastio();
	int t; cin >> t;
	while (t--) solve();
}

void solve() {
	int n, k; cin >> n >> k;
	vector<int> a(n);
	vector<int> f(n+1);
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		f[a[i]]++;
	}
	sort(a.begin(), a.end());
	
	int resp = 0;	
	for (int i = 0; i < k; i++) {
		if (f[i] == 0) resp++;
	}	
	f[k] -= resp;	
	if (f[k] > 0) {
		resp += f[k];
	}	
	cout << resp << endl;
}

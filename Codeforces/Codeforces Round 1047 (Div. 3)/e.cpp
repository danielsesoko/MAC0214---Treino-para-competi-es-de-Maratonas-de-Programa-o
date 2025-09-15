#include<bits/stdc++.h>
using namespace std;

#define int long long

void solve() {
	int n, k; cin >> n >> k;
		
	vector<int> a(n), f(n+1, 0);
	
	int mex = 0;

	for (int i = 0; i < n; i++) {
		cin >> a[i];
		f[a[i]]++;
	}
	
	for (int i = 1; i <= min(10LL, k); i++) {
		mex = 0;
		sort(a.begin(), a.end());

		for (int i = 0; i <= n; i++) f[i] = 0;

		for (int i = 0; i < n; i++) {
			if (a[i] == mex) mex++;
			f[a[i]]++;
		}

		for (int i = 0; i < n; i++) {
			if (f[a[i]] != 1 or a[i] > mex) a[i] = mex;
		}
	}
	
	if (k <= 10) {
		int soma = 0;
		for (int i = 0; i < n; i++) soma+=a[i];
		cout << soma << '\n';
		return;
	}
	
	int somai = 0, somap = 0;	
	for (int i = 0; i < n; i++) somap+=a[i]; 
	
	mex = 0;
	sort(a.begin(), a.end());
	for (int i = 0; i <= n; i++) f[i] = 0;
	for (int i = 0; i < n; i++) {
		if (a[i] == mex) mex++;
		f[a[i]]++;
	}
	for (int i = 0; i < n; i++) {
		if (f[a[i]] != 1 or a[i] > mex) a[i] = mex;
		somai+=a[i];
	}

	if (k%2 == 1) cout << somai << '\n';
	else cout << somap << '\n';	
}

signed main(){
	ios_base::sync_with_stdio(0); cin.tie(0);
	int t; cin >> t;
	while(t--) solve();
}

#include<bits/stdc++.h>
using namespace std;

void solve() {
	int n; cin >> n;
	for (int i = 0; i < n; i++) {
		int x; cin >> x;
		cout << n-x + 1<< ' ';
	}
	cout << '\n';
}

signed main(){
	int t; cin >> t;
	while(t--) solve();
}

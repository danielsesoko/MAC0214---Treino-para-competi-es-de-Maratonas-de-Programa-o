#include<bits/stdc++.h>
using namespace std;


#define int long long

void solve() {
	int k, x; cin >> k >> x;

	for(int i = 0; i < k; i++) x = x * 2;

	cout << x << '\n';
}

signed main(){
	int t; cin >> t;
	while(t--) solve();
}

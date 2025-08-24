#include<bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
	int n; cin >> n;
	int a[n], b[n];

	for (int i = 0; i < n; i++) cin >> a[i];
	for (int i = 0; i < n; i++) cin >> b[i];
	
	bool resp = true;	
	if (a[n-1] != b[n-1]) resp = false;

	for (int i = n-2; i >= 0; i--) {
		if (a[i] == b[i]) continue;
		if ((a[i] ^ b[i]) != a[i+1] and (a[i] ^ b[i]) != b[i+1]) {
			//cout << "TESTSE: " << a[i] << " " << b[i] << " " << (a[i] ^ b[i]) << " " << i << endl;
			//cout << "CONT: " << a[i+1] << " " << b[i+1] << endl;
			resp = false;	
		}
	}

	if (resp) cout << "YES\n";
	else cout << "NO\n";
}

signed main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	int tt; cin >> tt;
	while(tt--) solve();
}

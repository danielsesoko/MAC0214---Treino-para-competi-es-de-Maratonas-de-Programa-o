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
	int n, q; cin >> n >> q;
	string s; cin >> s;
	vector<int> a(q);
	for (int i = 0; i < q; i++) cin >> a[i];

	bool hasB = 0;
	for (int i = 0; i < n; i++) if (s[i] == 'B') hasB = 1;
		
	if (hasB) {
		for (int i = 0; i < q; i++) { 
			int j = 0, seg = 0;
			while (a[i] > 0) {
				seg++;
				if (s[j] == 'A') a[i]--;
				else a[i] /= 2;
				j++; j %= n;	
			}
			cout << seg << endl;
		}
		return;
	}
	
	for (int i = 0; i < q; i++) cout << a[i] << endl;
}

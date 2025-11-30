#include<bits/stdc++.h>
using namespace std;

#define fastio() ios_base::sync_with_stdio(0); cin.tie(0)
#define int long long
#define endl '\n'

void solve();

signed main() {
	fastio();
	int t; cin >> t;
	while (t--) solve();
}

void solve() {
	int n, k; cin >> n >> k;
	vector<int> q(n), r(n);

	for (int i = 0; i < n; i++) cin >> q[i];
	for (int i = 0; i < n; i++) cin >> r[i];

	sort(q.begin(), q.end());
	sort(r.rbegin(), r.rend());
	
	int j = 0, resp = 0;
	for (int i = 0; i < n; i++) {
		if (q[j] * (r[i] + 1) + r[i] <= k) {
			resp++;
			j++;	
		}
	}

	cout << resp << endl;
}

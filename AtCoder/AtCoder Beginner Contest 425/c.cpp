#include<bits/stdc++.h>
using namespace std;

#define int long long
#define endl '\n'

const int MAX = 2 * (1e5+10);

int n, q, s[2*MAX], a[MAX];

void solve() {
	cin >> n >> q;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		s[i] = a[i] + s[i-1];
	}
	for (int i = n+1; i <= 2*n; i++) s[i] = s[i-1] + a[i-n];

	int count = 0;
	for (int i = 1; i <= q; i++) {
		int op; cin >> op;
		if (op == 1) {
			int c; cin >> c;
			count += c; 
			count = count % n;
		}
		else {
			int l, r; cin >> l >> r;
			cout << s[r+count] - s[l+count-1] << endl;
		}
	}
}

signed main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	solve();
}

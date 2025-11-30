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
	int n, k; cin >> n >> k;
	vector<int> f(n+1), p(n+1);

	for (int i = 0; i < n; i++) {
		int a; cin >> a;
		f[a]++;
	}

	for (int i = 0; i <= n; i++) {
		p[i] = p[i-1] + f[i];
	}

	for (int i = n; i >= 1; i--) {
		int soma = 0;
		for (int j = 1; j <= 3; j++) {
			if (i * j <= n) soma += f[i*j];
		}
		soma += (p[n] - p[min(n, 4*i - 1)]);

		if (soma >= n-k) {
			cout << i << endl;
			return;
		}
	}
}

#include<bits/stdc++.h>
using namespace std;
using ll = long long;
const int MAXN = 2 * (1e5+10);

vector<int> g[MAXN];

void solve() {
	int n; cin >> n;

	for (int i = 0; i < n-1; i++) {
		int u, v; cin >> u >> v;
		g[u].push_back(v);
		g[v].push_back(u);
	}

	if (n == 2) {
		cout << 0 << '\n';
		return;
	}
	
	int vmini = 0, fmaxi = 0, ftotal = 0;
	for (int i = 1; i <= n; i++) {
		if (g[i].size() == 1) {
			ftotal++;
			continue;
		}

		int folhas = 0;
		for (auto v: g[i]) {
			if (g[v].size() == 1) {
				folhas++;
			}
		}

		if (folhas >= fmaxi) {
			vmini = i;
			fmaxi = folhas;	
		}	
	}
	cout << ftotal - fmaxi << '\n';

	for (int i = 0; i <= n; i++) g[i].clear();
}

signed main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	int tt; cin >> tt;
	while (tt--) solve();
}

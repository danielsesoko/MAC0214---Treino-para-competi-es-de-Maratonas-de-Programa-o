#include<bits/stdc++.h>
using namespace std;
using ll = long long;
const int MAXN = 2 * (1e5+10);

vector<int> g[MAXN];
int folhas[MAXN];

void dfs(int u, int p) {
	for (auto v: g[u]) {
		if (u == p) continue;
		dfs(v);
		folhas[u] += folhas[v]; 
	}	
}

void solve() {
	int n; cin >> n;

	for (int i = 0; i < n-1; i++) {
		int u, v; cin >> u >> v;
		u--; v--;
		g[v].push_back(u);		
		g[u].push_back(v);
	}

	dfs(0, 0);

	for (int i = 0; i < n; i++) {
		folhas[i] = 0;
		g[i].clear();
	}
}

signed main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	int tt; cin >> tt;
	while (tt--) solve();
}

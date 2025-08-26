#include<bits/stdc++.h>
using namespace std;

const int MAXN = 1e5+10;

int n = 1; 
vector<int> g[MAXN], query;
queue<int> f;
bool dead[MAXN];

void dfs(int u, int p) {
	f.push(u);
	for (auto v: g[u]) {
		if (v != p) dfs(v, u);	
	}
}

signed  main() {
	int q; cin >> q;
	for (int i = 0; i < q; i++) {
		int t, x; cin >> t >> x;
		if (t == 1) {
			g[x].emplace_back(++n);
			g[n].emplace_back(x);		
		} else query.emplace_back(x);
	}
	dfs(1, 1);	

	for (auto x: query) {
		dead[x] = 1;
		while (dead[f.front()]) f.pop();
		cout << f.front() << '\n';
	}
}


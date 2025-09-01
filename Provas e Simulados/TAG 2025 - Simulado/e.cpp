#include<bits/stdc++.h>
using namespace std;

#define int long long

const int MAX = 2 * (1e5) + 100, MAX2 = 40;

vector<vector<int> > g(MAX);
int n, p;
int pai[MAX2][MAX];
int in[MAX], out[MAX];
int T[MAX], nivel[MAX];

void dfs(int k) {
	in[k] = p++;

	nivel[k] = nivel[pai[0][k]] + 1;

	for (int i = 0; i < (int) g[k].size(); i++)
		if (in[g[k][i]] == -1) {
			pai[0][g[k][i]] = k;
			dfs(g[k][i]);
		}
	out[k] = p++;
}

void build(int raiz) {
	for (int i = 1; i <= n; i++) pai[0][i] = i;
	p = 0, memset(in, -1, sizeof in);

	dfs(raiz);

	for (int k = 1; k < MAX2; k++) for (int i = 0; i < n; i++)
		pai[k][i] = pai[k - 1][pai[k - 1][i]];
}

bool anc(int a, int b) {
	return in[a] <= in[b] and out[a] >= out[b];
}

int lca(int a, int b) {
	if (anc(a, b)) return a;
	if (anc(b, a)) return b;

	for (int k = MAX2 - 1; k >= 0; k--)
		if (!anc(pai[k][a], b)) a = pai[k][a];

	return pai[0][a];
}

int nivel_max = 0;
vector<int> grupos[MAX];

void dfs2(int u, int parr) {
	if (T[u] > 0) grupos[nivel[u]].emplace_back(u);
	if (T[u] > 0) nivel_max = max(nivel_max, nivel[u]);
	
	for (auto v: g[u]) if (v != parr and v != 1) dfs2(v, u);
}

signed main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	
	cin >> n;
	for (int i = 2; i <= n; i++) { 
		cin >> T[i];	
	}

	for (int i = 0; i < n-1; i++) {
		int u, v; cin >> u >> v;
		g[u].push_back(v);
		g[v].push_back(u);
	}

	build(1);

	int maxi = 0, mini = 0;
	for (auto x: g[1]) {
		nivel_max = 0;
		dfs2(x, 1);

		for (int i = 1; i <= nivel_max; i++) {
			if (grupos[i].size() == 0) continue;
			int node = grupos[i][0];
			int total = 0;
			
			for (auto u: grupos[i]) {
				node = lca(node, u); 	
				total += T[u];
			}
			if (total > maxi) {
				maxi = max(total, maxi);
				mini = i - nivel[node];
			} else if (total == maxi) mini = min(i - nivel[node], mini);

			grupos[i].clear();	
		}
	}
	
	if (maxi == 0) mini = -1;	
	cout << maxi << ' ' << mini + 1 << '\n';
}


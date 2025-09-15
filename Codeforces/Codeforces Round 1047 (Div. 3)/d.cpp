#include<bits/stdc++.h>
using namespace std;

void solve() {
	int n; cin >> n;	
	vector<int> aux[n+1];

	for(int i = 1; i <= n; i++) {
		int b; cin >> b;
		aux[b].push_back(i);
	}

	for (int i = 1; i <= n; i++) {
		if (aux[i].size() % i != 0) {
			cout << -1 << '\n';
			return;
		}
	}
	
	int a[n+1];	
	int atual = 0;
	for (int i = 1; i <= n; i++) {
		int contador = 0;
		if (aux[i].size() == 0) continue;
		for (int j = 0; j < aux[i].size(); j++) {
			if (contador % i == 0) atual++;
			a[aux[i][j]] = atual;
			contador++;
		}
	}

	for (int i = 1; i <= n; i++) cout << a[i] << ' ';
	cout << '\n';
}

signed main(){
	int t; cin >> t;
	while(t--) solve();
}

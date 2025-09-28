#include<bits/stdc++.h>
using namespace std;
#define endl '\n'

void solve() {
	int h, w; cin >> h >> w;
	bool a[h+10][w+10];
	
	for (int i = 0; i <= h+1; i++)
		for (int j = 0; j <= w+1; j++)
			a[i][j] = 0;


	queue<int> x, y, tx, ty;

	for (int i = 1; i <= h; i++) {
		for (int j = 1; j <= w; j++) {
			char t; cin >> t;
			if (t == '#') {
				a[i][j] = 1;
				x.push(i);
				y.push(j);
			}
			else a[i][j] = 0;
		}
	}

	int du[4] = {0, 0, -1, 1};
	int dv[4] = {1, -1, 0, 0};

	while (!x.empty()) {
		int u = x.front();
		int v = y.front();
		x.pop(), y.pop();	

		for (int i = 0; i < 4; i++) {
			int p = u + du[i];
			int q = v + dv[i];	
			
			if (a[p][q]) continue;
			if (p < 1 or q < 1 or p > h or q > w) continue;

			int count = 0;
			for (int j = 0; j < 4; j++) {
				int n = p + du[j];
				int m = q + dv[j];
				if (a[n][m]) count++;
			}
		
			if (count == 1) {
				tx.push(p);
				ty.push(q);
			}
		}

		if (x.empty()) {
			while (!tx.empty()) {
				int p = tx.front(), q = ty.front();
				a[p][q] = 1;
				x.push(p), y.push(q);
				tx.pop(), ty.pop();
			}	
		}	
	}
	
	int resp = 0;
	for (int i = 1; i <= h; i++)
		for (int j = 1; j <= w; j++)
			if (a[i][j]) resp++;

	cout << resp << endl;
}

signed main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	solve();
}

#include<bits/stdc++.h>
using namespace std;
#define fastio() ios_base::sync_with_stdio(0); cin.tie(0)
	
void solve();

signed main() {
	fastio();
	int t; cin >> t;
	while (t--) solve();
}

int dx[] = {0, 0, -1, 1};
int dy[] = {1, -1, 0, 0};

void solve() {
	int n; cin >> n;
	int a[n+1][n+1];
	for (int i = 0; i < n; i++) {
		for (int j = 1; j <= n; j++) {
			a[i][j-1] = i * n + j;		
		}	
	}

	int resp = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			int sum = a[i][j];	
			for (int k = 0; k < 4; k++) {
				int x = i + dx[k], y = j + dy[k];
				if (x >= 0 and x < n and y >= 0 and y < n) {
					sum += a[x][y];
				}
			}
			resp = max(resp, sum);
		}
	}

	cout << resp << endl;
}

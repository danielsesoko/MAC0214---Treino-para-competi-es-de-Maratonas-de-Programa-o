#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define fastio() ios_base::sync_with_stdio(0); cin.tie(0)

void solve();

signed main() {
	fastio();
	solve();
}

const int N = 1e6;
const int M = 21;
const int X = (1<<21) - 1;

vector<int> a(N+10);
vector<int> dp0(X+10, -1), dp1(X+10, -1);

void solve() {
	int n; cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	
	for (int i = n; i >= 1; i--) {
		if (dp0[a[i]] == -1) {
			dp0[a[i]] = i;
		}
		else if (dp1[a[i]] == -1) {
			dp1[a[i]] = i;
		}
	}

	for (int i = 1; i <= M; i++) {
		for (int x = 0; x <= X; x++) {
			if ((x & (1<<(i-1)))) continue;
			int t1 = dp0[x | (1<<(i-1))];
			int t2 = dp1[x | (1<<(i-1))];		
			int temp[3] = {dp0[x], t1, t2};
			dp0[x] = max({dp0[x], t1, t2});
			for (int k = 0; k < 3; k++) {
				if (temp[k] != dp0[x]) {
					dp1[x] = max(dp1[x], temp[k]);
				}
			}
		}
	}
	
	int r = 0;
	for (int i = 1; i <= n; i++) {
		int x = 0;
		if (i <= n - 2) r = max(r, a[i] | x);
		for (int j = M-1; j >= 0; j--) {
			if (a[i] & (1<<j)) continue;	
			if (dp1[x | (1<<j)] == -1) continue;
			if (dp1[x | (1<<j)] <= i) continue;
			x |= (1<<j);
			r = max(r, a[i] | x);
		}		
	}
	cout << r << '\n';
}

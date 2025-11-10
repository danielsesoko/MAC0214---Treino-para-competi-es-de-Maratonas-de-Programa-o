#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define fastio() ios_base::sync_with_stdio(0); cin.tie(0)

void solve();

signed main() {
	fastio();
	solve();
}

const int N = 2 * (1e5), X = (1<<20)-1;

vector<int> a(X+10), v(N+10);
vector<int> dp0(X+10), dp1(X+10), dp2(X+10), dp3(X+10);

void solve() {
	int n; cin >> n;
	for (int i = 1; i <= n; i++) {
		int temp; cin >> temp;
		v[i] = temp;
		a[temp]++;
	}

	for (int x = 0; x <= X; x++) {
		dp0[x] = a[x];
	}

	for (int i = 1; i <= 20; i++) {
		for (int x = 0; x <= X; x++) {
			dp1[x] = dp0[x];
			if (x & (1<<(i-1))) {
				dp1[x] += dp0[x - (1<<(i-1))];
			}
		}
		dp0 = dp1;
	}
	
	for (int x = 0; x <= X; x++) {
		dp2[x] = a[x];
	}

	for (int i = 1; i <= 20; i++) {
		for (int x = 0; x <= X; x++) {
			dp3[x] = dp2[x];
			if ((x & (1<<(i-1))) == 0) {
				dp3[x] += dp2[x + (1<<(i-1))];
			}	
		}
		dp2 = dp3;
	}

	for (int i = 1; i <= n; i++) {
		int x = v[i], x_ = X - x; 
		int r1 = dp1[x];
		int r2 = dp3[x];
		int r3 = n - dp1[x_];	

		cout << r1 << " " << r2 << " " << r3 << '\n';
	}
}

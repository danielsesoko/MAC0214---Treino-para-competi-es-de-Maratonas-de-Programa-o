#include<bits/stdc++.h>
using namespace std;

#define int long long
#define ll long long
const int MAXN = 2 * (1e5) + 10, MOD = 998244353;

int n, k; 
int b[MAXN];

ll inv(ll a, ll b) {
	return a > 1 ? b - inv(b%a, a)*b/a : 1;
}

int escolhe(int x, int y) {
	int fat1 = 1, fat2 = 1;
	for (int i = x-y+1; i <= x; i++) {
		fat1 = (fat1 * i) % MOD;	
	}

	for (int i = 1; i <= y; i++) {
		fat2 = (fat2 * i) % MOD;
	}

	return (fat1 * inv(fat2, MOD)) % MOD;	
}	

void solve() {
	int b1 = b[1];
	for (int i = 1; i <= k; i++) {
		int x = i + 1, y = i, soma = 0, mini = 0;
		while (x <= n-k+1) {
			soma += (b[x] - b[y]);
			mini = min(mini, soma);
			x += k, y += k;
		}
		if (mini > 0) continue;
		b1 += mini;
	}

	if (b1 < 0) {
			cout << 0;
			return;
	}

	cout << escolhe(k-1+b1, k-1);
}

signed main() {
	cin >> n >> k;
	for (int i = 1; i <= n-k+1; i++) cin >> b[i];
	
	solve();
}

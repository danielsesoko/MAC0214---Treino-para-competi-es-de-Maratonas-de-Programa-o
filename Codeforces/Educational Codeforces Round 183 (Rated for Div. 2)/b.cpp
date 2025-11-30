#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define fastio() ios_base::sync_with_stdio(0); cin.tie(0)

void solve();

signed main() {
	fastio();
	int t; cin >> t;
	while (t--) solve();
}

void solve() {
	int n, k; cin >> n >> k;
	string s; cin >> s;
	
	int l = 0, r = n+1;
	
	int pulos = 0;	
	vector<int> resp(n+1, 1);

	for (int i = 0; i < k; i++) {
		if (s[i] == '0') resp[++l] = -1;	
		else if (s[i] == '1') resp[--r] = -1;
		else pulos++;
	}	
	
	if (l + pulos < r - 1) {
		for (int i = 1; i <= pulos; i++) {
			resp[++l] = 0;
			resp[--r] = 0;		
		}
	}
	else for (int i = 1; i <= pulos; i++) resp[++l] = -1;

	for (int i = 1; i <= n; i++) {
		if (resp[i] == -1) cout << '-';
		else if (resp[i] == 0) cout << '?';
		else cout << '+';
	}
	cout << '\n';
}

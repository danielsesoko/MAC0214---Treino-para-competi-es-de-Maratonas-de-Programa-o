#include<bits/stdc++.h>
using namespace std;
#define fastio() ios_base::sync_with_stdio(0); cin.tie(0)

void solve();

signed main() {
	fastio();
	int t; cin >> t;
	while (t--) solve();	
}
const int INF = 1e6;
void solve() {
	int n; cin >> n;
	string s; cin >> s;
	int dif = 0;
	for (int i = 0; i < n; i++) {
		if (s[i] == 'a') dif++;
		else dif--;
	}

	if (dif == 0) {
		cout << 0 << endl;
		return; 
	}

	map<int, int> f;	
	int soma = 0, resp = INF;
	for (int i = 0; i < n; i++) {
		if (s[i] == 'a') soma++;
		else soma--;
		
		if (soma == dif) resp = min(resp, i+1);
		if (f.count(soma - dif)) {
			resp = min(resp, i - f[soma-dif]);	
		}

		f[soma] = i;
	}

	if (resp >= n) cout << -1 << '\n';
	else cout << resp << '\n';
}

#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define fastio() ios_base::sync_with_stdio(0); cin.tie(0)
#define endl '\n';
#define int long long
void solve();

signed main() {
	fastio();
	int t; cin >> t;
	while (t--) solve();
}

void solve() {
	int n; cin >> n;
	string s; cin >> s;
	int total = 0;
	for (int i = 0; i < n; i++) if (s[i] == 'b') total++;

	int resp1 = 0, qtd = 0, q;	
	for (int i = 0; i < n; i++) {	
		if (s[i] == 'a') {
			resp1 += qtd;
			continue;
		}
		qtd++;	
		if (qtd >= ((total+1)/2)) {
			q = i;
			break;
		}
	}

	q++;
	for (int i = q; i < n; i++) {
		if (s[i] == 'a') continue;
		resp1 += abs(q - i);
		q++;
	}

	total = 0;
	for (int i = 0; i < n; i++) if (s[i] == 'a') total++;

	int resp2 = 0;
       	qtd = 0;	
	for (int i = 0; i < n; i++) {	
		if (s[i] == 'b') {
			resp2 += qtd;
			continue;
		}
		qtd++;	
		if (qtd >= ((total+1)/2)) {
			q = i;
			break;
		}
	}

	q++;
	for (int i = q; i < n; i++) {
		if (s[i] == 'b') continue;
		resp2 += abs(q - i);
		q++;
	}

	cout << min(resp1, resp2) << endl;
}

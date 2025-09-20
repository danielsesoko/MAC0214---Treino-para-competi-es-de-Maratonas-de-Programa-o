#include<bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
	int n; cin >> n;
	string s; cin >> s;
	
	int i = 0;
	bool need = 0, can_give = 0, single = 0;
	bool resp = true;
	
	int last = -1;
	for (int i = 0; i < n; i++) {
		if (s[i] == '0') last = i;
	}

	while (i < n) {
		if (s[i] == '1') {
			if (i+1 > n or s[i+1] == '0') single = 1;	
			else { 
				single = 0;
				while (i+1 < n and s[i+1] == '1') i++;
			}
		}
		else if (i+1 < n and s[i+1] == '0') {
			if (need == 1 and single == 0) resp = false;
			need = 0;
			can_give = 1;
			while (i+1 < n and s[i+1] == '0') i++;
		}
		else if (i == 0 or i == n-1) {
			if (need == 1 and single == 0) resp = false;
			need = 0;
			can_give = 1;
		}
		else if (i == last) {
			if (can_give == 0 or single == 0) resp = false;	
		}
		else if (single == 0) {
			if (need == 1) resp = false;
			else {
				need = 1;
				can_give = 1;	
			}
		}
		else if (need == 0 and can_give == 0) {
			need = 1;
			can_give = 1;	
		}
		else if (need == 1 and can_give == 1) {
			need = 0;
			can_give = 0;	
		}
		else if (need == 0 and can_give == 1) {
			need = 0; can_give = 1;
	       	}

		i++;		
	}
	
	if (resp) cout << "YES\n";
	else cout << "NO\n";
}

signed main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	int t = 1; cin >> t;
	while (t--) solve();
}

#include<bits/stdc++.h>
using namespace std;

signed main() {
	int n; cin >> n;
	string s; cin >> s;
	
	bool resp = 0;
	if (n >= 3) {
		if (s[n-1] == 'a' and s[n-2] == 'e' and s[n-3] == 't') resp = 1;
	}

	if (resp) cout << "Yes";
	else cout << "No";
}

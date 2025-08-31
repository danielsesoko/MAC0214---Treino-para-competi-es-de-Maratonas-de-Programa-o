#include<bits/stdc++.h>
using namespace std;

signed main() {
	string s; cin >> s;
	int n = s.size();
	double resp = 0;

	for (int i = 0; i < n; i++) {
		for (int j = i+2; j < n; j++) {
			if (s[i] != 't' or s[j] != 't') continue;
			int contador = 0;

			for (int k = i+1; k < j; k++) {
				if (s[k] == 't') contador++;
			}
			
			resp = max(resp, (double)contador / (double)(j-i-1));
		}
	}

	cout << fixed << setprecision(16) << resp << '\n';
}

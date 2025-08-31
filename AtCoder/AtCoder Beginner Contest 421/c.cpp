#include<bits/stdc++.h>
using namespace std;
#define int long long
signed main() {
	int n; cin >> n;
	string s; cin >> s;
	
	int j = 0, c1 = 0, c2 = 0;
	for (int i = 0; i < 2 * n; i++) {
		if (s[i] == 'B') {c1 += abs(i - j), j += 2; }
	}

	j = 1;
	for (int i = 0; i < 2 * n; i++) {
		if (s[i] == 'B') {c2 += abs(i - j), j += 2; }
	}
	cout << min(c1, c2) << endl;
}

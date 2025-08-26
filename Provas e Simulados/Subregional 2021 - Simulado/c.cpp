#include<bits/stdc++.h>
using namespace std;
#define int long long
signed main() {
	int b, n; cin >> b >> n;
	int d[n];
	int r = 0;
	for (int i = n-1; i >= 0; i--) {
		cin >> d[i];
		if (i % 2 == 0) r += d[i];
		else r -= d[i];
		r %= (b+1);
		if (r < 0) r+=(b+1);
	}
	
	if (r == 0) {cout << "0 0\n"; return 0;}	

	int resp = -1, x;
	for (int i = n-1; i >= 0; i--) {
		if (i % 2 == 0 and d[i] >= r) {resp = d[i] - r; x = n - i; break;}
		else if (i % 2 == 1 and d[i] >= b+1-r) {resp = d[i] - b-1 + r; x = n - i; break;}
	}

	if (resp == -1) {cout << "-1 -1\n"; return 0;}
	cout << x << " " << resp << '\n';	
}

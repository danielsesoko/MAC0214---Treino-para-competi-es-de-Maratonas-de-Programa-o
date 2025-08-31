#include<bits/stdc++.h>
using namespace std;

signed main() {
	int n, x; cin >> n;
	string a[n];
	for (int i = 0; i < n; i++) cin >> a[i];
	
	cin >> x;
	x--;
	string y; cin >> y;
	string z = a[x];	
	bool flag = true;
	if (z.size() != y.size()) flag = false;

	for (int i = 0; i < z.size(); i++) if (z[i] != y[i]) flag = false;

	if (flag) cout << "Yes";
	else cout << "No";
}

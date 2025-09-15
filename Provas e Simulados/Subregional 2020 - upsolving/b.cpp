#include<bits/stdc++.h>
using namespace std;

bool a[12][12];

signed main() {
	int n; cin >> n;
	bool flag = 1;

	for (int i = 1; i <= n; i++) {
		int d, l, r, c; cin >> d >> l >> r >> c;

		if (d == 0) {
			for (int i = 0; i < l; i++) {
				if (c + i > 10 or a[r][c+i] == 1) {
					flag = 0;
					continue;
				}
				a[r][c+i] = 1;
			}
		}
		else {	
			for (int i = 0; i < l; i++) {
				if (r + i > 10 or a[r+i][c] == 1) {
					flag = 0;
					continue;
				}
				a[r+i][c] = 1;
			}
		}
	}

	if (flag) cout << "Y\n";
	else cout << "N\n";
}

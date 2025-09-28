#include<bits/stdc++.h>
using namespace std;

#define int long long
#define endl "\n"

int a[30+1], f[30+1];

signed main() {
	int n; cin >> n;
	bool resp = 1;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		if (a[i] == -1) continue;
		if (f[a[i]] != 0) resp = 0;
		else f[a[i]] = 1;
	}

	if (resp == 0) {
		cout << "No" << endl;
		return 0;
	}

	cout << "Yes" << endl;
	for (int i = 1; i <= n; i++) {
		if (a[i] != -1) cout << a[i] << " ";
		else {
			for (int j = 1; j <= n; j++) {
				if (f[j] == 0) {
					cout << j << " ";
					f[j] = 1;
					break;
				}
			}
		}
	}
	cout << endl;
}

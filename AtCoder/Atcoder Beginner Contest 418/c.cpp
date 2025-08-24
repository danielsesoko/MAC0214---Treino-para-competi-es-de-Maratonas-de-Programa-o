#include<bits/stdc++.h>
using namespace std;

#define int long long

signed main() {
	int n, q; cin >> n >> q;
	vector<int> arr(n);
	int maxi = 0;
	for (int i = 0; i < n; i++) {
	       	cin >> arr[i];
		maxi = max(maxi, arr[i]);
	}
	sort(arr.begin(), arr.end());
	
	long long soma = 0;
	vector<int> x(q), y(q);
	int resp[1000000 + 10];
	
	for (int i = 0; i < q; i++) {
		cin >> x[i];
		y[i] = x[i];
	}
	sort(x.begin(), x.end());
	
	int i = 0;
	for (int j = 0; j < q; j++) { 
		while (i < n and arr[i] < x[j]) {
			soma += arr[i];
			i++;
		}
		resp[x[j]] = soma + (n-i) * (x[j]-1) + 1;
	}

	for (int i = 0; i < q; i++) {
		if (maxi < y[i]) {
			cout << -1 << '\n';
			continue;
		}
		cout << resp[y[i]] << '\n';;
	}
}

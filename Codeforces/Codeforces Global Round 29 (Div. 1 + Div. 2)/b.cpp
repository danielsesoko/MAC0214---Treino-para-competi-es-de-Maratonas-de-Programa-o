#include<bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
	int n; cin >> n;
	if (n == 1) {
		cout << "1 1\n";
		return;
	}
	if (n == 2) {
		cout << "2 1 2 1\n";
		return;
	}
	if (n == 3) {
		cout << "1 3 1 2 3 2\n";
		return;
	}
	
	int arr[2*n];
	for (int i = 0; i < 2*n; i++) arr[i] = 0;

	int par = n-1, impar = n;
	if (n % 2 == 0) {
		par = n;
		impar = n-1;
	}

	int aux = 0;

	for (int i = par; i >= 2; i-=2) arr[aux++] = i;
	
	int meio1 = aux;
	arr[meio1] = impar;
	arr[meio1 + impar] = impar;
	aux++;

	for (int i = 2; i <= par; i+=2) {
		arr[aux] = i;
		aux++;
	}

	for (int i = impar - 2; i >= 3; i-=2) {
		arr[aux] = i;
		aux++;
	}

	if (arr[aux] == 0) {
		arr[aux] = 1;
		aux += 2;
	}
	else {
		arr[++aux] = 1;
		aux++;
	}

	for (int i = 3; i <= impar - 2; i+=2) {
		arr[aux] = i;
		aux++;
	}

	arr[aux] = 1;
	
	for (int i = 0; i < 2*n; i++) cout << arr[i] << " ";
	cout << '\n';
}

signed main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	int t = 1; cin >> t;
	while (t--) solve();
}

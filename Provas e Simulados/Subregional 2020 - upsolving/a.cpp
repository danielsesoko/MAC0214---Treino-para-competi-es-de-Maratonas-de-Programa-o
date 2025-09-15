#include<bits/stdc++.h>
using namespace std;

#define int long long

mt19937 rng((int) chrono::steady_clock::now().time_since_epoch().count());

int uniform(int l, int r){
	uniform_int_distribution<int> uid(l, r);
	return uid(rng);
}

int n, a, b; 

signed main() {
	cin >> n >> a >> b;
	double resp = 0, aresp = 1;
	int contador = 0, total = 0;

	while(abs(resp - aresp) >= (double)1.0/(100000.0) or contador <= 100000000) {
		cout << resp << ' '<< aresp << endl;
		int soma = 0;
		contador++;
		while (soma < n) {
			soma += uniform(a, b);
			cout << uniform(a, b) << endl;
			total++;
		}
		aresp = resp;
		resp = (double)total/contador;
	}

	cout << resp << '\n';
}

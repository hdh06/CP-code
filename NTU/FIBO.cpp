#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main(){
	ll f[31] = {0, 1, 1};
	for (int i = 2; i <= 30; i++){
		f[i] = f[i - 1] + f[i - 2];
	}

	int n; cin >> n;

	for (int i = 1; i <= n; i++) cout << f[i] << " ";
	return 0;
}
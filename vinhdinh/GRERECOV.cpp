#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main(){
	int n;
	cin >> n;	

	vector<ll> a(n + 2, 0); a[n + 1] = LLONG_MAX;

	for (int i = 1; i <= n / 2; i++){
		ll b;
		cin >> b;
		a[i] = a[i - 1];
		a[n - i + 1] = b - a[i];
		while (a[n - i + 1] > a[n - i + 2]){
			a[i] ++;
			a[n - i + 1]--;
		}
	}

	for (int i = 1; i <= n; i++) cout << a[i] << " ";
	return 0;
}
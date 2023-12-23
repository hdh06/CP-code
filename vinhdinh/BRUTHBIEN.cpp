#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main(){
	int n;
	cin >> n;

	vector<ll> a(n + 1), c(n + 1), m(n + 1, LLONG_MAX);

	for (int i = 1; i <= n; i++) cin >> a[i];
	for (int i = 1; i <= n; i++) cin >> c[i];	

	for (int i = 1; i <= n; i++)
		for (int j = i - 1; j >= 1; j--) if (a[i] > a[j])
			m[i] = min(m[i], c[j] + c[i]);		

	ll ans = LLONG_MAX;

	for (int i = 1; i <= n; i++){
		for (int j = i - 1; j >= 1; j--) if (a[i] > a[j] && m[j] != LLONG_MAX){
			ans = min(ans, m[j] + c[i]);
		}
	}

	cout << (ans == LLONG_MAX?-1:ans);

	return 0;
}
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

map<int, int> ma, mb;

int main(){
	int a, b, n;
	cin >> a >> b >> n;

	for (int i = 2; i <= sqrt(a); i++)
		while (a % i == 0) a /= i, ma[i]++;
	if (a > 0) ma[a]++;

	for (int i = 2; i <= sqrt(b); i++)
		while (b % i == 0) b /= i, mb[i]++;
	if (b > 0) mb[b]++;

	int ans = 1;
	for (auto x: ma)
		ans *= pow(x.first, min(1LL * x.second * n, 1LL * mb[x.first]));
	cout << ans;
	return 0;
}
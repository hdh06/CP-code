#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int const N = 25;

vector<int> p, maxp;
ll maxn = 0;

int v[N], w[N];

void dekuy(int n, ll m, ll z){
	if (n == 0){
		if (m >= 0){
			if (z > maxn){
				maxn = z;
				maxp = p;
			}
		}
		return;
	}

	dekuy(n - 1, m, z);

	p.push_back(n);
	dekuy(n - 1, m - w[n], z + v[n]);
	p.pop_back();
}

int main(){
	int n; ll k; 
	cin >> n >> k;

	for (int i = 1; i <= n; i++) cin >> w[i] >> v[i];
	
	dekuy(n, k, 0);

	reverse(maxp.begin(), maxp.end());

	cout << maxp.size() << "\n";
	for (auto x: maxp) cout << x << " ";
	return 0;
}
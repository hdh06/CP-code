#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int const N = 21;
string const IMPOSSIBLE = "khongtherut";

int n; ll m;

ll arr[N];

bool flag = false;

vector<ll> p;

void dequy(int n, ll t){
	if (n == 0){
		if (t == m && flag == false){
			flag = true;
			cout << p.size() << "\n";
			for (auto x: p) cout << x << " ";
		}
		return;
	}

	p.push_back(n);
	dequy(n - 1, t + arr[n]);
	p.erase(p.end() - 1);
	dequy(n - 1, t);
}

int main(){
	cin >> n >> m;
	for (int i = 1; i <= n; i++) cin >> arr[i];
	dequy(n, 0);
	if (!flag) cout << IMPOSSIBLE;
	return 0;
}
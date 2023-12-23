#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int n;
ll arr[101]; bool take[101] = {};

vector<ll> p;

bool flag = false;

bool check(ll a, ll b){
	if (a % 3 == 0 && a / 3 == b) return true;
	if (b % 2 == 0 && b / 2 == a) return true;
	return false;
}

void dequy(int i){
	if (i == n + 1 && !flag){
		flag = true;
		for (auto x: p) cout << x << " ";
		return;
	}

	for (int t = 1; t <= n; t++) if (!take[t]){
		if (!p.empty()) if (!check(p.back(), arr[t])) continue;
		take[t] = true;
		p.push_back(arr[t]);

		dequy(i + 1);

		take[t] = false;
		p.erase(p.end() - 1);
	}
}

int main(){
	cin >> n;
	for (int i = 1; i <= n; i++) cin >> arr[i];

	dequy(1);
	return 0;
}
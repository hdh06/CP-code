#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef array<ll, 2> ii;

int n;
vector<ii> arr;

set<ii> pos;

int L = 0;

ii rv(ii a){
	return {a[1], a[0]};
}

ll edu(ii a, ii b){
	return (a[0] - b[0])*(a[0] - b[0]) + (a[1] - b[1])*(a[1] - b[1]);
}

int main(){
	ios_base::sync_with_stdio(0); cin.tie(nullptr); cout.tie(nullptr);
	cin >> n;

	arr.resize(n);

	for (auto &x: arr) cin >> x[0] >> x[1];

	sort(arr.begin(), arr.end());

	ll dis = edu(arr[0], arr[1]);

	pos.insert(rv(arr[0]));
	pos.insert(rv(arr[1]));

	for (int i = 2; i < n; i++){
		while (!pos.empty() && (arr[i][0] - arr[L][0])*(arr[i][0] - arr[L][0]) >= dis)
			pos.erase(rv(arr[L++]));

		// 2 cai toa do duoi so nao cung dc xd
		for (auto j = pos.upper_bound({arr[i][1] - dis, (ll)-1e9 - 1});
				  j != pos.lower_bound({arr[i][1] + dis, (ll)1e9 + 1}); 
				  j++){
			dis = min(dis, edu(rv(*j), arr[i]));
		}

		pos.insert(rv(arr[i]));
	}

	cout << dis;
	return 0;
}
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int n;
ll m, tong = 0;

ll calc(int b, vector<ll> arr){
	ll ans = m, dem = 0;
	for (int i = 0; i < n; i++){
		if (b & (1 << i)){
			ans /= arr[i];
			dem++;
		}
	}
	return (dem & 1? 1: -1)*ans;
}

// void print(int b){
// 	for (int i = n - 1; i >= 0; i--){
// 		if (b & (1<<i)) cout << "1";
// 		else cout << "0";
// 	}
// 	cout << " ";
// }

int main(){
	cin >> n >> m;
	set<ll> temp;
	for (int i = n; i >= 1; i--){
		ll t; cin >> t;
		temp.insert(t);
	}

	vector<ll> arr(temp.begin(), temp.end());
	n = arr.size();

	for (int b = 1; b < (1 << n); b++){
		ll ans = calc(b, arr);
		tong += ans;
		// print(b); cout << ans << endl;
	}

	cout << tong;

	return 0;
}

/*
2 3 4 5 [6] 8 9 [10] [12] 
14 [15] 16 [18] [20] 21 22 [24] 25 
26 27 28 [30]
22 số
*/
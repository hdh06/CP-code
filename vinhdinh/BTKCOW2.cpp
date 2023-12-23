#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main(){
	int n; cin >> n;
	int arr[21];
	for (int i = 1; i <= n; i++) cin >> arr[i];

	bool flag = 0;

	for (int b = 0; b <= (1 << n) - 1; b++){
		string outp;
		ll x = 0, y = 0;
		for (int i = 1; i <= n; i++) if (b & (1 << (i - 1))) x += arr[i], outp.push_back('1');
			else y += arr[i], outp.push_back('2');
		if (x == y){
			cout << outp << "\n";
			flag = flag | (1&1&1&1&1&1&1&1&1&1&1);
		}
	}

	if (!flag) cout << -1;
	return 0;
}
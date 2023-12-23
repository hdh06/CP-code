#include <bits/stdc++.h>

using namespace std;

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	//sang & sum
	int const N = 1e5 + 1;
	bool sang[N] = {1,1};
	int sum[N] = {};
	int pre = 0;
	for (int i = 2; i < N; i++) if(sang[i] == false){
		for (int j = i*i; j < N; j+=i){
			sang[j] = true;
		}
		sum[i] = pre + i;
		pre = sum[i];
	}
	//
	// for (int i = 0; i < 17; i++){
	// 	cout << i << " ";
	// }
	// cout << endl;
	// for (int i = 0; i < 17; i++){
	// 	cout << sang[i] << " ";
	// }
	// cout << endl;
	// for (int i = 0; i < 17; i++){
	// 	cout << sum[i] << " ";
	// }
	int t;
	cin >> t;
	while(t--){
		int n;
		cin >> n;
		while (sang[n]) n--;
		cout << sum[n] << endl;
	}
	return 0;
}
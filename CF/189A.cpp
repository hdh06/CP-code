#include <bits/stdc++.h>

using namespace std;

int main(){
	int n, arr[3];
	cin >> n;
	cin >> arr[0] >> arr[1] >> arr[2]; 

	int f[4001] = {0};

	for (int i = 1; i <= n; i++){
		f[i] = -1;
		for (int j = 0; j < 3; j++){
			if (i - arr[j] >= 0 && f[i - arr[j]] != -1){
				f[i] = max(f[i], f[i - arr[j]] + 1);
			}
		}
	}

	cout << f[n];

	return 0;
}
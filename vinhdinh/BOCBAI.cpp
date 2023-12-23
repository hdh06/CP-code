#include <bits/stdc++.h>

using namespace std;

int const N = 1e6 + 1;

int main(){
	ios_base::sync_with_stdio(false); cin.tie(0);
	int n;
	cin >> n;

	long long arr[N];

	for (int i = 1; i <= n; i++){
		cin >> arr[i];
	}

	sort(arr + 1, arr + n + 1);

	long long S = arr[n], M = 0;
	for (int i = n - 1, dem = 2; i >= 1;i -= dem*2){
		// if (n == 332) cout << i << "->" << i - dem + 1 << " && " << i - dem << "->" << i - 2*dem + 1 << endl;
		for (int j = i; j >= 1 && j >= i - dem + 1; j--) M += arr[j];
		for (int j = i - dem; j >= 1 && j >= i - 2*dem + 1; j--) S += arr[j];
			// cout << S << " " << M << endl;
	}
	
	// if (n == 332) cout << S << " "<< M << endl;
	if (S > M) cout << "THANG";
	else if (S < M) cout << "THUA";
	else cout << "HOA";
	return 0;
}
#include <bits/stdc++.h>

using namespace std;

int main(){
	int n;	
	int arr[12][12];

	cin >> n;

	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++) cin >> arr[i][j];

	for (int i = 1; i <= n; i++){
		int tong = 0;
		for (int j = 1; j <= n; j++) if (arr[i][j] % 2 == 0) tong += arr[i][j];
		cout << tong << endl;
	}
	return 0;
}
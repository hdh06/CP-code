#include <bits/stdc++.h>

using namespace std;

int main(){
	int n;
	cin >> n;
	int arr[101][101];
	int i = 1, j = n / 2 + 1, dem = 1;
	while (true){
		arr[i][j] = dem++;
		int prei = i, prej = j;
		i -= 1; j += 1;
		if (i == 0) i = n;
		if (j == n + 1) j = 1;
		if (arr[i][j] != 0) i = prei + 1, j = prej;
		if (arr[i][j] != 0) break;
	}

	for (int i = 1; i <= n; i++){
		for (int j = 1; j <= n; j++){
			cout << arr[i][j] << " ";
		}
		cout << endl;
	}
	return 0;
}
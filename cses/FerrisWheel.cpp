#include <bits/stdc++.h>

using namespace std;

int const N = 2*1e5 + 1;

int main(){
	int n, x;
	cin >> n >> x;

	int arr[N];

	for (int i = 1; i <= n; i++){
		cin >> arr[i];
	}

	sort(arr + 1, arr + n + 1);

	int ans = 0;
	bool isvisited[N] = {};
	for (int i = 1, j = n; i < j;){
		if (arr[i] + arr[j] > x){
			j--;
		}
		else{
			ans ++;
			isvisited[i] = isvisited[j] = true;
			i++; j--;
		}

	}

	for (int i = 1; i <= n; i++){
		ans += (!isvisited[i]);
	}

	cout << ans;

	return 0;
}
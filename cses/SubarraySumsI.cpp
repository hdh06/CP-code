#include <bits/stdc++.h>

using namespace std;

int main(){
	int n, x;
	cin >> n >> x;

	vector<int> arr(n + 1);
	for (int i = 1; i <= n; i++) cin >> arr[i];

	int dem = 0;
	for (int i = 1, j = 1, s = arr[1]; i <= n && j <= n;){
		if (s == x) dem++;
		if (s + arr[j + 1] <= x){
			s += arr[j + 1];
			j++;
		}
		else{
			s -= arr[i];
			i++;
		}
	}

	cout << dem;
	return 0;
}
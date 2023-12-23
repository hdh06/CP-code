#include <bits/stdc++.h>

using namespace std;

int const N = 5001;
int const V = 1e6 + 1;

int n;
int arr[N];
int cnt[2 * V];

int main(){
	cin >> n;
	for (int i = 1; i <= n; i++){
		cin >> arr[i];	
		cnt[arr[i] + V]++:
	}

	sort(arr + 1, arr + n + 1);

	int ans = 0, maxx = 0;
	for (int i = 1; i <= n; i++)
		for (int j = i + 1; j <= n; j++) if ((arr[i] + arr[j]) % 2 == 0){
			int z = (arr[i] + arr[j]) / 2;
			int c = cnt[z + V] - (arr[i] == z) - (arr[j] == z);
			ans += c;
			if (c > 0) maxx = max(maxx, z + z * 2);
		}

	cout << ans << "\n";
	cout << maxx;
	return 0;
}
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

void sswap(ll &a, ll &b){
	ll c = a;
	a = b;
	b = c;
}

int main(){
	int n;
	cin >> n;
	vector<ll> arr(n + 1);

	for (int i = 1; i <= n; i++)cin >> arr[i];

	for (int t = 1; t <= n; t++){
		for(int i = 1; i < n; i++){
			if (arr[i] > arr[i + 1]) sswap(arr[i], arr[i + 1]);
		}
	}	

	for (int i = 1; i <= n; i++) cout << arr[i] << " ";
	return 0;
}
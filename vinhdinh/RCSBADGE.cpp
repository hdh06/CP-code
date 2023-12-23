#include <bits/stdc++.h>

using namespace std;

int const N = 1001;

int n;

int arr[N];
bool vis[N];

int dequy(int i){
	// cout << i << " ";
	if (vis[i]) return i;
	vis[i] = true;
	return dequy(arr[i]);
}

int main(){
	cin >> n;

	for (int i = 1; i <= n; i++) cin >> arr[i];	

	for (int i = 1; i <= n; i++) {
		for (int i = 1; i <= n; i++) vis[i] = false;
		cout << dequy(i) << " ";
	}
	return 0;
}
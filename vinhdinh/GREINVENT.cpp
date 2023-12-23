#include <bits/stdc++.h>

using namespace std;

int main(){
	int n;
	cin >> n;

	vector<int> arr(n + 1);
	vector<bool> vis(100001, 0), vis2(n + 2, 0);

	int t = 1;
	for (int i = 1; i <= n; i++){
		cin >> arr[i];
		vis[arr[i]] = true;
	}	

	for (int i = 1; i <= n; i++){
		while(vis[t]) t++;
		if (vis2[arr[i]] || arr[i] > n) arr[i] = t++;
		vis2[arr[i]] = true;
	}	

	for (int i = 1; i <= n; i++) cout << arr[i] << " ";
	return 0;
}
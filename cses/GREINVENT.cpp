#include <bits/stdc++.h>

using namespace std;

int main(){
	int n;
	cin >> n;

	vector<int> arr(n + 1);
	vector<bool> vis(n + 1, 0);

	int t = 1;
	for (int i = 1; i <= n; i++){
		while(vis[t]) t++;
		cin >> arr[i];
		if (vis[arr[i]]) arr[i] = t, vis[t] = true;
	}	

	for (int i = 1; i <= n; i++) cout << arr[i] << " ";
	return 0;
}
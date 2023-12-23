#include <bits/stdc++.h>

using namespace std;

int main(){
	ios_base::sync_with_stdio(0); cin.tie(nullptr); cout.tie(nullptr);
	int n;
	cin >> n;
	vector<bool> vis(n + 1, 0); vis[0] = 1;

	for (int i = 0, dem = 0; dem < n;){
		i++; i %= n + 1;
		while (vis[i]) i++;
		i %= n + 1;
		while (vis[i]) i++;
		i++; i %= n + 1;
		while (vis[i]) i++;
		i %= n + 1;
		while (vis[i]) i++;

		vis[i] = true;
		dem++;
		cout << i << " ";
	}		
	return 0;
}
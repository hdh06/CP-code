#include <bits/stdc++.h>

using namespace std;

int main(){
	int n;
	cin >> n;

	vector<int> arr(n);

	for (auto &x: arr) cin >> x;

	sort(arr.begin(),arr.end());
	
	int GCD = 360;
	for (int i = 0; i < n; i++){
		GCD = gcd(arr[i], GCD);
	}	

	bool vis[361] = {}; vis[0] = vis[360] = 1;

	int dem = 360/GCD - 1;
	for (auto x: arr) if (!vis[x]){
		dem--;
		vis[x] = true;
	}

	cout << dem;
	return 0;
}

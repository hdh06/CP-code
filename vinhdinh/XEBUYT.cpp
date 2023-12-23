#include <bits/stdc++.h>

using namespace std;

int main(){
	int n; 
	cin >> n;

	int dem = 0, max_dem = 0;

	for (int i = 0; i < n; i++){
		int a, b;
		cin >> a >> b;
		dem -= a;
		dem += b;
		max_dem = max(max_dem,dem);
	}

	cout << max_dem;
	return 0;
}
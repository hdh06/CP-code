#include <bits/stdc++.h>

using namespace std;

int main(){
	int n, m;
	cin >> n >> m;

	vector<int> p(n + 1, 0), arr(n + 1);
	for (int i = 1; i <= n; i++){
		cin >> arr[i];
		p[arr[i]] = i;
	}	

	int dem = 1;

	for (int i = 2; i <= n; i++){
		dem += p[i] < p[i - 1];
	}

	while(m--){
		int a, b;
		if (a > b) swap(a, b);
		a = arr[a]; b = arr[b];
		if (p[a] < p[a + 1])
		swap(p[a], p[b]);
		
		cout << dem << "\n";
	}
	return 0;
}
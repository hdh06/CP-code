#include <bits/stdc++.h>

using namespace std;

int main(){
	int n, maxn, maxp; 
	cin >> n;
	for (int i = 1; i <= n; i++){
		int temp;
		cin >> temp;

		if (temp >= maxn){
			maxn = temp;
			maxp = i;
		}
	}	

	cout << maxn << " " << maxp;
	return 0;
}
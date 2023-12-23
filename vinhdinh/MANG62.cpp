#include <bits/stdc++.h>

using namespace std;

int main(){
	int n; 
	cin >> n;

	for (int t = n; t--;){
		int maxn = 0;
		for (int i = 0; i < n; i++){
			int temp;
			cin >> temp;

			maxn = max(maxn, temp);
		}
		cout << maxn << endl;
	}
	return 0;
}
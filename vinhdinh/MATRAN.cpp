#include <bits/stdc++.h>

using namespace std;

int main(){
	int n, m; 
	cin >> n >> m;

	cout << setprecision(2) << fixed;
	while(n--){
		double maxn = 0;
		for (int i = 0; i < m; i++){
			double temp;
			cin >> temp;

			maxn = max(maxn, temp);
		}
		cout << maxn << endl;
	}
	return 0;
}
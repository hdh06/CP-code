#include <bits/stdc++.h>

using namespace std;

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int t;
	cin >> t;
	while(t--){
		int n;
		cin >> n;

		double r = n - 0.5;
		
		int dem = 0, dem2 = 0;
		for (int i = 0; i <= n - 1; i++){
			for (int j = 0; j <= n - 1 - i; j++){
				int g = n - i, h = n - j;
				double dis = sqrt(g*g + h*h), dis2 = sqrt((g - 1)*(g - 1) + (h - 1)*(h - 1));
				if (dis >= r && r > dis2) dem++;
				if (dis2 > r) dem2++;
			}
		}

		cout << n << ":" << dem*4 << " " << (2*n*2*n - dem2*4 - dem*4) << '\n';
	}

	return 0;
}
#include <bits/stdc++.h>

using namespace std;

typedef double ldb;

int const N = 101;

int n;
int r[N];

int main(){
	
}

/* WA due to error but no checker
int main(){
	cin >> n;
	
	for (int i = 1; i <= n; i++)
		cin >> r[i];
	
	ldb ans = 0;
	for (int i = 1; i <= n; i++)
		for (int j = i - 1; j >= 1; j--){
			int cnt = 0;
			for (int x = 1; x <= r[i]; x++)
				for (int y = 1; y <= r[j]; y++) if (y > x)
					cnt++;
			ans += cnt / (ldb)(r[i] * r[j]);
		}			
	cout << setprecision(6) << fixed << ans;
	return 0;
}
*/

/* wrong due to repition of a[i] in the answer
int main(){
	cin >> n;
	for (int i = 1; i <= n; i++)
		cin >> r[i];
	
	ldb ans = 0;
	for (int i = 1; i <= n; i++)
		for (int x = 1; x <= r[i]; x++)	
			for (int j = i - 1; j >= 1; j--){
				ans += (ldb)max(0, r[j] - x) / (ldb)r[j];
			}
			
	cout << setprecision(6) << fixed << ans;
	return 0;
}
*/
#include <bits/stdc++.h>

using namespace std;

int main(){
	int n; 
	cin >> n;

	int seven = 0, four = n / 4, tong = four*4, min_f = four, max_s = 0;

	// while (tong <= n) tong += 7, seven ++;
	// tong -= 7, seven --;

	while(four > 0){
		// cout << "BEDBUG: " << tong << " " << seven << " " << four << endl;
		tong -= 4;
		four --;
		while(tong <= n){
			seven++;
			tong += 7;
			if (tong > n) {
				seven --, tong -= 7;
				break;
			}
		}
		if (tong == n){
			min_f = min(min_f, four);
			max_s = max(max_s, seven);
		}
	}

	if (min_f*4 + max_s*7 == n){
		while(min_f--) cout << 4;
		while(max_s--) cout << 7;
	}
	else cout << -1;
	return 0;
}
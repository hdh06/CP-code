#include <bits/stdc++.h>

using namespace std;

int memo[1001];
int ask(int i){
	if (memo[i] != -1) return memo[i];
	cout << "? " << i << endl;
	int x; cin >> x;
	return memo[i] = x;
}
void ans(int x){
	cout << "! " << x << endl;
}

int main(){
	int t; cin >> t;
	while (t--){
		memset(memo, -1, sizeof memo);
		int n, x; cin >> n >> x;
			
		bool y = 0;
			
		int l = 1, r = n, vl = ask(l);
		while (l < r){
			int mid = (l + r) / 2 + (l + 1 == r);
			int val = ask(mid);
			if (val == x){
				ans(mid);
				y = 1;
				break;
			}
			if (val > vl){
				l = mid;
				vl = val;
			}else{
				r = mid - 1;
			}

		}
		
		if (!y){
			int shift = n - r;
			l = 1, r = n;
			while (l <= r){
				int mid = (l + r) >> 1;
				int val = ask((mid - shift - 1 + n) % n + 1);
				if (val == x){
					ans((mid - shift - 1 + n) % n + 1);
					y = 1;
					break;
				}
				if (x < val) r = mid - 1;
				if (x > val) l = mid + 1;
			}
		}
		if (!y) ans(-1);
	}	
	return 0;
}
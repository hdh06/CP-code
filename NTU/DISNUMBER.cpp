#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

ll gt(int n){
	ll ans = 1;
	for (int i = 1; i <= n; i++)
		ans *= i;
	return ans;
}

ll calc(string s){
	int mask = 0; bool is = 0;
	ll ans = 0;
	for (int i = 0; i < s.size(); i++){
		s[i] -= '0';
		for (int d = 0; d < s[i]; d++){
			if (mask & (1 << d)) continue;
			int c = 10 - __builtin_popcount(mask) - 1;
			bool nis = is | (d != 0);
			if (nis){
				if (s.size() - i - 1 > c) continue;
				ans += gt(c) / gt(c - s.size() + i + 1);
			}else{
				for (int j = 0; j < s.size() - i - 1; j++){
					if (s.size() - i - 1 - j - 1 > c) continue;
					ans += 1LL * c * gt(c) / gt(c - s.size() + i + 1 + j + 1);
				}
				ans++; //00...0 case
			}
			
		}
	
		if (mask & (1 << s[i])) break;
		mask |= 1 << s[i];
		is = s[i] != 0;
	}
	return ans;
}

int main(){
	int t; cin >> t;
	while (t--){
		string L, R; cin >> L >> R;
		{
			R = '0' + R;
			int i = R.size() - 1;
			while (R[i] == '9') R[i] = '0', i--;
			R[i]++;
			if (R[0] == '0') R.erase(0, 1);
		}
		
		cout << calc(R) - calc(L) << "\n";
	}
	return 0;
}
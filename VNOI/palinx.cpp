#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int const A = 98274943;
int const B = 2722324;

ll fre[B][4] = {};

ll hashV(string s){
	ll h = s[0];
	for (int i = 1; i < s.size(); i++){
		h = (h*A + s[i]) % B;
	}
	return h;
}

int main(){
	freopen("inp.inp", "r", stdin); freopen("out.out", "w", stdout);	
	int t;
	cin >> t;

	for (int i = 1; i <= t; i++){
		int n; cin >> n;
		string s; cin >> s;

		// cout << "[o]" << s << endl;
		fre[hashV(s)][0] ++;

		// cout << s << " = " << hashV(s) << endl;

		reverse(s.begin(), s.end());
		fre[hashV(s)][1] ++;

		// cout << s << " = " << hashV(s) << endl;
		if (n > 1){
			s.erase(s.end() - 1);
			fre[hashV(s)][3] ++;

			// cout << s << " = " << hashV(s) << endl;

			reverse(s.begin(), s.end());
			fre[hashV(s)][2] ++;
		
			// cout << s << " = " << hashV(s) << endl;
		}
	}

	ll tong = 0;
	for (int i = 0; i < B; i++){
		tong += fre[i][0]*fre[i][1] + fre[i][0]*fre[i][3] + fre[i][2]*fre[i][1];
		// cout << "[" << i << "] = " << fre[i][0] << " " << fre[i][1] << " " << fre[i][2] << " " << fre[i][3] << endl;  
	}

	cout << tong;
	return 0;
}
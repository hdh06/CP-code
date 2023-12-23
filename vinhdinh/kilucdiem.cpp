#include <bits/stdc++.h>

using namespace std;

int main(){
	int t; int maxn = 0, maxd = 0;
	string name;
	cin >> t;
	string temp;
	getline(cin, temp);
	while(t--){
		string s;
		getline(cin, s);
		string num;
		if (s[s.size() - 4] == '1'){
			string ans;
			for (int i = 0; !('1' <= s[i] && s[i] <='9'); i++){
				ans.push_back(s[i]);
			}
			ans.erase(ans.size() - 1, 1);
			cout << ans;
			return 0;
		}
		int n = s[s.size() - 3] - '0', d = s[s.size() - 1] - '0';
		if (maxn < n || (maxn == n && maxd < d)){
			maxn = n, maxd = d;
			string ans;
			for (int i = 0; !('1' <= s[i] && s[i] <='9'); i++){
				ans.push_back(s[i]);
			}

			ans.erase(ans.size() - 1, 1);
			name = ans;
		}
		// cout << n << "." << d << endl;
	}
	cout << name;
	return 0;
}
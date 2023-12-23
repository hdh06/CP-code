#include <bits/stdc++.h>

using namespace std;

bool check(string n, string s){
	int i = 0;
	for (int j = 0; i < n.size() && j < s.size(); j++){
		if (i < n.size() && n[i] == s[j]) i++;			
	}
	return (i == n.size());
}

int main(){
	int n; cin >> n;

	string s = to_string(n);

	int ans = INT_MAX;

	for (int i = 1; i <= sqrt(n); i++){
		string x = to_string(i*i);
		if(check(x, s)){
			ans = min(ans, (int)s.size() - (int)x.size());
			// cout << x << " " << (int)s.size() - (int)x.size() << endl;
		}
	}

	cout << (ans == INT_MAX?-1:ans);
	return 0;
}
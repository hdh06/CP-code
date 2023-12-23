#include <bits/stdc++.h>

using namespace std;

void solve(){
	string s; cin >> s;
	int n = s.size();	
	string t; cin >> t;
	if (t == "a"){
		cout << "1\n";
		return;
	}
	if (t.find('a') != string::npos){
		cout << "-1\n";
		return;
	}

	cout << (1LL << n) << "\n";

}

int main(){
	ios_base::sync_with_stdio(0); cin.tie(nullptr); cout.tie(nullptr);	
	int t; cin >> t;
	while(t--) solve();
	return 0;
}
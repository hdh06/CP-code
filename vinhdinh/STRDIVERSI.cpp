#include <bits/stdc++.h>

using namespace std;

int main(){
	int t;
	cin >> t;
	while(t--){
		string s;
		cin >> s;

		sort(s.begin(), s.end(), [](char a, char b){return a < b;});

		s.push_back(s[s.size()-1] + 1);
		bool kt = true;
		for (int i = 1; i < s.size(); i++){
			if (s[i - 1] + 1 != s[i]){
				kt = false;
				break;
			}
		}	

		cout << (kt ? "Yes": "No") << endl;
	}
	return 0;
}
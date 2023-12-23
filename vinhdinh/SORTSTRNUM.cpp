#include <bits/stdc++.h>

using namespace std;

vector<string> so, chu;

bool check(char c){
	return ('0' <= c && c <= '9');
}

int main(){
	string s; 
	cin >> s;

	string curr, curr2;
	curr2.push_back(s[0]);

	for (int i = 1; i < s.size(); i++){
		if (check(s[i])){
			if (!check(s[i - 1])){
				if (!curr.empty()) so.push_back(curr);
				curr.clear();
			}
			curr.push_back(s[i]);
		}
		else{
			if (check(s[i - 1])){
				if (!curr2.empty()) chu.push_back(curr2);
				curr2.clear(); 
			}
			curr2.push_back(s[i]);
		}
	}

	if (!curr.empty()) so.push_back(curr);
	if (!curr2.empty()) chu.push_back(curr2);

	sort(so.begin(), so.end(), [](string a, string b){
		if (a.size() != b.size()) return (a.size() < b.size());
		for (int i = 0; i < a.size(); i++){
			if (a[i] != b[i]) return (a[i] < b[i]);
		}
		return false;	
		// return (a.size() < b.size());
	});

	// for (auto x: so) cout << x << " ";
	// cout << endl; 
	// for (auto x: chu) cout << x << " ";
	// cout << endl; 

	int ichu = 0, iso = 0;

	while (ichu < chu.size() || iso < so.size()) {
		if (ichu < chu.size())
			cout << chu[ichu++];
		if (iso < so.size())
			cout << so[iso++];
	}
	return 0;

}

//h1h1h1hh1h1h1h1h1hh1h1h11h1hh1h1h1h1h1h11
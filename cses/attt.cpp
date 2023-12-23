#include <bits/stdc++.h>

using namespace std;

int main(){
	string s = "hetcuuroiman";
	for (int i = 0; i < s.size(); i++){
		s[i] -= 'a';
		s[i] += 7;
		s[i] %= 26;
		s[i] += 'a';		
	}
	cout << s;
	
	int p[12];
	iota(p, p + 12, 1);
	random_shuffle(p, p + 12);
	
	int w[12] = {1, 5, 7, 12, 14, 15, 22, 23, 25, 30, 37, 44};
		
	vector<pair<int, char> > v;
	for (int i = 0; i < 12; i++){
		v.push_back({p[i], s[i]});
	}
	
	sort(v.begin(), v.end());

	
	for (int i = 0; i < 12; i++){
		cerr << v[i].first << " " << v[i].second << " " << w[i] << "\n";
	}
	return 0;
}

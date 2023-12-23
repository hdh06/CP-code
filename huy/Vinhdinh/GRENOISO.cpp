#include <bits/stdc++.h>

using namespace std;

bool comp(string s1, string s2){
	return (s1 + s2) > (s2 + s1);
}

int main(){
	// freopen("INT.int","r",stdin);
	ios_base::sync_with_stdio(0); cin.tie(0);
	vector<string> s;
	string temp;
	while(cin >> temp){
		s.push_back(temp);
	}

	sort (s.begin(),s.end(), comp);

	for (auto x : s){
		cout << x;
	}
	return 0;	
}


#include <bits/stdc++.h>

using namespace std;

string norm(string s){
	while(s[0] == '0') s.erase(0,1);
	return s;
}

bool comp(string a, string b){
	if (a.size() > b.size()) return false;
	if (a.size() < b.size()) return true;
	for (int i = 0; i <= a.size() - 1; i++){
		if (a[i] > b[i]) return false;
		if (a[i] < b[i]) return true;
	}
	return true;
}

int main(){
	string a, b;
	cin >> a >> b;

	if (comp(norm(a),norm(b))) cout << b;
	else cout << a;
	return 0;
}
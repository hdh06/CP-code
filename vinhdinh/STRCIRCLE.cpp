#include <bits/stdc++.h>

using namespace std;

map<string, bool> mymap;

int main(){
	string s;
	cin >> s;

	int dem = 0;

	for (int i = 0; i < s.size(); i++){
		if (mymap[s] == false){
			dem++;
			mymap[s] = true;
		}
		s = s.back() + s;
		s.erase(s.end() - 1);
	}	

	cout << dem;
	return 0;
}
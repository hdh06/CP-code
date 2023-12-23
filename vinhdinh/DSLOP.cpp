#include <bits/stdc++.h>

using namespace std;

int main(){
	string s;
	while(getline(cin, s)){
		istringstream ss(s);
		string b;
		while(ss >> b){
			cout << b << " ";
		}
		cout << endl;
	}	
	return 0;
}
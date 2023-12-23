#include <bits/stdc++.h>

using namespace std;

int key(char c){
	return c - 'a';
}

int main(){
	int t;
	cin >> t;
	while(t--){
		int arr[26];
		string s;
		cin >> s;
		for (int i = 0; i < s.length(); i++){
			arr[key(s[i])] = i;
		}
		string x;
		cin >> x;
		x = x + '#';
		int tong = 0, prepos = arr[key(x[0])], prechar = x[i];
		for (int i = 1; i < x.length(); i++){
			if (x[i] != prechar){
				tong += abs(prepos - arr[key(x[i])]);
				prepos = arr[key(x[i])];
				prechar = x[i];
			}
		}
		cout << tong << endl;
	}
	return 0;
}
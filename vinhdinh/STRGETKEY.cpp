#include <bits/stdc++.h>

using namespace std;

int is[26] = {};

int main(){
	int n; 
	cin >> n;
	n = n*2 - 2;

	int dem = 0;

	string s; cin >> s;
	for (int i = 0; i < n; i++){
		if (i & 1){
			if (is[s[i] - 'A']) is[s[i] - 'A']--;
			else dem++;
		}
		else is[toupper(s[i]) - 'A']++;
	}

	cout << dem;
	return 0;
}
#include <bits/stdc++.h>

using namespace std;

int const N = 256;

int fre[N] = {};

int main(){
	string a, b;
	cin >> a >> b;

	for (int i = 0; i < a.size(); i++) fre[a[i]]++;
	for (int i = 0; i < b.size(); i++) fre[b[i]]++;

	string c;
	cin >> c;

	for (int i = 0; i < c.size(); i++){
		if (fre[c[i]] == 0){
			cout << "NO";
			return 0;
		}
		else fre[c[i]]--;
	}

	cout << "YES";
	return 0;
}
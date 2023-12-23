#include <bits/stdc++.h>

using namespace std;

int arr[300] = {};

int main(){
	string s; 

	getline(cin, s);

	for (int i = 0; i < s.length(); i++){
		arr[s[i]] ++;
	}

	for (char i = '1'; i <= '9'; i++){
		if (arr[i] != 0) cout << i << " " << arr[i] << endl;
	}

	for (char i = 'a', j = 'A'; i <= 'z' && j <= 'Z'; i++, j++){
		if ((arr[i] + arr[j]) != 0) cout << i << " " << arr[i] + arr[j] << endl;
	}

	return 0;
}
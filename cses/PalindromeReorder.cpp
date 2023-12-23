#include <bits/stdc++.h>

using namespace std;

int main(){
	int arr[255] = {};

	string s;
	cin >> s;
	for (int i = 0; i < s.length(); i++){
		arr[s[i] - 'A']++;
	}

	s = "";
	string c = "";

	bool kt = true;

	for (int i = 0; i <= 25; i++){
		if (arr[i] % 2 == 0) for (int t = arr[i] / 2; t > 0; t--) s.push_back(i + 'A');
		if (arr[i] % 2 != 0){
			if (kt == false){
				cout << "NO SOLUTION";
				return 0;
			}
			else{
				kt = false;
				for (int t = arr[i]; t > 0; t--) c.push_back(i + 'A');
			}
		}
	}

	cout << s;
	reverse(s.begin(), s.end());

	cout << c;

	cout << s;

	return 0;
}
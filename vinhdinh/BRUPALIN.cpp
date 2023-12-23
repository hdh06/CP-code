#include <bits/stdc++.h> 

using namespace std;

int main(){
	string s;
	cin >> s;

	int n = s.length();
	bool t = true;
	for (int i = 0; i < n/2; i++){
		if(s[i] != s[n - i - 1]){
			if (t){	
				t = false;
				continue;
			}
			else{
				cout << "NO";
				return 0;
			}
		}
	}
	if(t && n % 2 == 0) cout << "NO";
	else cout << "YES";
	return 0;
}


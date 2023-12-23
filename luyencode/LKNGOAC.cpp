#include <bits/stdc++.h>

using namespace std;

int main(){
	string s;
	cin >> s;
	stack<int> mysta;
	for (int i = 0; i < s.length(); i++){
		if (s[i] == '(') mysta.push(i);
		else{
			cout << mysta.top() + 1 << " " << i + 1 << endl;
			mysta.pop();
		}
	}
	return 0;
}
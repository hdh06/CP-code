#include <bits/stdc++.h>

using namespace std;

int kh(char c){
	if (c == 'C') return 12;
	if (c == 'O') return 16;
	if (c == 'H') return 1;
	if (c == '(') return 0;
	return -1;
}

int main(){
	string s;
	cin >> s;
	stack<int> mystack;
	for (int i = 0; i < n; i++){
		if(kh(s[i]) == -1){
			int t = 0;
			while (mystack.top() != 0){
				t += mystack.top();
				mystack.pop()
			}
		}
	}
	return 0;
}
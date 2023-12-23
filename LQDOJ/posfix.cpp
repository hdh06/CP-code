#include <bits/stdc++.h>

using namespace std;

int calc(char dau, int a, int b){
	if (dau == '+') return a + b;
	if (dau == '-') return a - b;
	if (dau == '*') return a * b;
	return -1;
}


int main(){
	string s;
	while(getline(cin, s)){
		s += ' ';
		stack<int> mystack; 
		string x;
		for(int i = 0; i < s.length(); i++){
			if (s[i] == ' '){
				if ('0' <= x[0] && x[0] <= '9'){
					mystack.push(stoi(x));
					// cout << s[i] - '0' << endl;
				}
				else{
					int b = mystack.top(); mystack.pop();
					int a = mystack.top(); mystack.pop();
					mystack.push(calc(x[0], a, b));
					// cout << a << s[i] << b << endl;
				}
				x = "";
			}
			else{
				x += s[i];
			}
		}
		cout << mystack.top() << endl;
	}

	return 0;
}
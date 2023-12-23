#include <bits/stdc++.h>

using namespace std;

int main(){
	char c;
	while (cin >> c){
		if ('0' <= c && c <= '9') continue;
		cout << c;
	}
	return 0;
}
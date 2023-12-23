#include <bits/stdc++.h>

using namespace std;

int main(){
	char c; int dem = 0;
	while(cin >> c)	dem += ('0' <= c && c <= '9');
	cout << dem;
	return 0;
}
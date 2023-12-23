#include <bits/stdc++.h>

using namespace std;

int n;

string convert(int n, int b){
	string ans;
	while(n > 0){
		ans = (char)((n & 1) + '0') + ans;
		n >>= 1;
	}
	while (ans.size() < b){
		ans = '0' + ans;
	}
	return ans;
}

int g(int n){
	return n^(n >> 1);
}

int main(){
	cin >> n;
	for (int i = 0; i < pow(2, n); i++){
		cout << convert(g(i), n) << endl;
	} 
	return 0;
}
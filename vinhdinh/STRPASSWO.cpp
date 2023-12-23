#include <bits/stdc++.h>

using namespace std;

int main(){
	string s; cin >> s;
	
	vector<int> thuong(s.size() + 1), hoa(s.size() + 1), so(s.size() + 1);	
	thuong[s.size()] = hoa[s.size()] = so[s.size()] = s.size();

	for (int i = s.size() - 1; i >= 0; i--){
		thuong[i] = thuong[i + 1]; hoa[i] = hoa[i + 1]; so[i] = so[i + 1];
		if ('0' <= s[i] && s[i] <= '9') so[i] = i;
		if ('A' <= s[i] && s[i] <= 'Z') hoa[i] = i;
		if ('a' <= s[i] && s[i] <= 'z') thuong[i] = i;
	}

	long long dem = 0;
	for (int i = 0; i < s.size() - 6 + 1; i++){
		int d = max({i + 6 - 1, hoa[i], thuong[i], so[i]});
		dem += s.size() - d;
	}
	cout << dem;
	return 0;
	
}
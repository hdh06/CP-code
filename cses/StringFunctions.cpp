#include <bits/stdc++.h>

using namespace std;

typedef vector<int> vi;

vi zfunc(string &s){
	int n = s.size();
	vi z(n);
	for (int i = 1, l = 0, r = 0; i < n; i++){
		z[i] = max(0, min(z[i - l], r - i + 1));
		while (i + z[i] < n && s[z[i]] == s[i + z[i]])
			l = i, r = i + z[i], z[i]++;
	}
	return z;
}

vi kmpfunc(string &s){
	int n = s.size();
	vi kmp(n);
	for (int j = 0, i = 1; i < n;){
		if (s[i] == s[j])
			kmp[i] = ++j, i++;
		else{
			while (j && s[i] != s[j]) j = kmp[j - 1];
			if (s[i] != s[j])
				j = 0, i++; 
		}
	}
	return kmp;
}

int main(){
	string s; cin >> s;	
	vi z = zfunc(s);
	vi kmp = kmpfunc(s);
	for (auto x: z) cout << x << " "; cout << endl;
	for (auto x: kmp) cout << x << " ";
	return 0;
}
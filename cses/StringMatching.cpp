#include <bits/stdc++.h>
 
using namespace std;
 
int main(){
	string s, p; 
	cin >> s >> p;
 
	vector<int> tp(s.size() + p.size(), 0);
 
	for (int i = 1, j = 0; i <= p.size();){
		if (p[i] == p[j]){
			tp[i] = j + 1;
			i++;
			j++;
		}
		else{
			while (j && p[i] != p[j]) j = tp[j - 1];
			if (p[i] != p[j]) tp[i] = 0, i++;
		}
	}
 
	vector<int> r(s.size(), 0);
 
	for (int i = 0, j = 0; i < s.size();){
		if (j >= p.size()) j = tp[j - 1];
		if (s[i] == p[j]){
			r[i] = j + 1;
			i++;
			j++;
		}
		else{
			if (j != 0) j = tp[j - 1];
			if (s[i] != p[j]) r[i] = 0, j = 0, i++;
		}
		
	}
 
	// for (int i = 0; i < p.size(); i++) cout << p[i] << endl;
 
	int dem = 0;
	for (int i = 0; i < s.size(); i++) if (r[i] == p.size()) dem++;
	cout << dem;
	return 0;
}
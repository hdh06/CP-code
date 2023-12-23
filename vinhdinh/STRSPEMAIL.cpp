#include <bits/stdc++.h>

using namespace std;

int main(){
	string s; 
	cin >> s;
	if (s[0] == '@'){
		cout << "LAMSAOBAYGIO";
		return 0;
	}

	string ans;
	while(s[0] != '@' && s.size() > 0) ans = ans + s[0], s.erase(0, 1);
	// if (s.size() == 0){
	// 	cout << "LAMSAOBAYGIO";
	// 	return 0;
	// }
	int dem = 0;
	ans = ans + s[0];
	s = s + 'z'; s = s + '@'; 
	for (int i = 1; i < s.size(); i++){
		if (s[i] != '@') dem++, ans = ans + s[i];
		else{
			if (dem <= 1){
				cout << "LAMSAOBAYGIO";
				return 0;
			}
			else{
				char c = ans[ans.size() - 1];
				ans[ans.size() - 1] = ',';
				ans = ans + c;
				dem = 0;
			}
			ans = ans + '@';
		}
	}	

	ans.erase(ans.size() - 3, 3);
	cout << ans;
	return 0;
}
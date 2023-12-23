#include <bits/stdc++.h>

using namespace std;

int main(){
	stack<int> mysta;
	int t; cin >> t;
	while(t--){
		int q; cin >> q;
		if (q == 1){
			int n; cin >> n;
			mysta.push(n);
		}
		if (q == 2){
			if (!mysta.empty()) mysta.pop();
		}
		if (q == 3){
			if (!mysta.empty()) cout << mysta.top() << "\n";	
			else cout << "Empty!\n";
		}
	}	
	return 0;
}
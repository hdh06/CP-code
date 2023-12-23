#include <bits/stdc++.h>

using namespace std;

#define pii pair<int,int>

int main(){
	// ios_base::sync_with_stdio(0);cin.tie(0);
	int n;
	cin >> n;
	stack<pii> mystack;
	int tong = 0;
	for (int i = 0; i < n; i++){
		int temp;
		cin >> temp;
		// cout << "ok";
		if (mystack.empty()) mystack.push({temp, 1});
		// cout << mystack.top().first << endl;
		else{
			if (mystack.top().first > temp){
				tong++;
				mystack.push({temp, 1});
			}
			else if (mystack.top().first < temp){
				if (mystack.size() > 1) tong+=mystack.top().second;
				while (!mystack.empty() && mystack.top().first < temp) mystack.pop();
				if (!mystack.empty())
				{
					if (mystack.top().first == temp){
						int dem = mystack.top().second;
						tong += dem;
						mystack.pop();
						if (!mystack.empty()) tong+=mystack.top().second;
						mystack.push({temp, dem + 1});
					}
					else{
						tong += mystack.top().second;
						mystack.push({temp, 1});
					}
				}
				else{
					mystack.push({temp, 1});
					tong++;
				}
			}
			else{
				int dem = mystack.top().second;
				tong += dem;
				mystack.pop();
				if (!mystack.empty()) tong+= mystack.top().second;
				mystack.push({temp, dem + 1});
			}
		}
		if (!mystack.empty()) cout << mystack.top().first << " " << mystack.top().second << endl;
		cout << mystack.size() << " " << tong << endl;
	}
	cout << tong; 
	return 0;
}

/*
7
2
4
1
2
2
5
1

*/
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int const N = 1e5 + 1;

int main(){
	int n;
	cin >> n;
	while(n != 0){
		ll arr[N] = {};

		for (int i = 1; i <= n; i++) cin >> arr[i];

		stack<int> mystack;

		int top = 0;
		ll area = 0;
		mystack.push(1);
		for (int i = 2; i <= n + 1; i++){
			if (arr[i] >= arr[mystack.top()]) mystack.push(i);
			else{
				while (!mystack.empty() && arr[i] < arr[mystack.top()]){
					top = mystack.top();
					mystack.pop();

					if (mystack.empty()){
						area = max(area, arr[top]*(i - 1));
					}
					else{
						area = max(area, arr[top]*(i - mystack.top() - 1));
					}
				}
				mystack.push(i);
			}
		}

		cout << area << endl;
		cin >> n;
	}
	return 0;
}
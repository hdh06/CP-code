#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main(){
	int n; 
	cin >> n;

	vector<ll> arr(n + 2);

	for (int i = 1; i <= n; i++) cin >> arr[i];

	arr[n + 1] = 0;

	stack<int> mystack;

	mystack.push(1);

	ll max_area = 0;

	for (int i = 2; i <= n + 1; i++){
		if (arr[i] > arr[mystack.top()]){
			mystack.push(i);
		}
		else {
			while (!mystack.empty() && arr[mystack.top()] > arr[i]){
				int topp = mystack.top();
				mystack.pop();

				if (mystack.empty()){
					max_area = max(max_area, arr[topp]*(i - 1));
				}
				else{
					max_area = max(max_area, arr[topp]*(i - mystack.top() - 1));
				}
			}
			mystack.push(i);
		}
	}

	cout << max_area << endl;
	return 0;
}
#include <bits/stdc++.h>

using namespace std;

int const N = 1e3 + 2;

int n, m;

int arr[N] = {};
int area = 0;

void calc(){
	stack<int> mystack;
	mystack.push(1);
	for (int i = 2; i <= m + 1; i++){
		if (arr[i] > arr[mystack.top()]) mystack.push(i);
		else{
			while(!mystack.empty() && arr[mystack.top()] > arr[i]){
				int topp = mystack.top();
				mystack.pop();

				if (mystack.empty()){
					area = max(area, arr[topp]*(i - 1));
				}
				else{
					area = max(area, arr[topp]*(i - 1 - mystack.top()));
				}
			}
			mystack.push(i);
		}
	}
}

int main(){
	cin >> n >> m;	

	while (n --){
		for (int i = 1; i <= m; i++){
			char c; cin >> c;

			if (c == '*') arr[i] = 0;
			else arr[i] ++;
		}
		calc();
	}

	cout << area;
	return 0;
}
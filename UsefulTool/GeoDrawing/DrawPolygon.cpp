#include <bits/stdc++.h>
#include <geodeb.h>

using namespace std;

int main(){
	GD_INIT("polygon.html");
	int n;
	cin >> n;

	vector<array<int, 2> > arr(n + 2);

	for (int i = 1; i <= n; i++){
		cin >> arr[i][0] >> arr[i][1];
	}

	GD_POINT(arr[1][0], arr[1][1]);
	arr[n + 1] = arr[1];
	for (int i = 2; i <= n + 1; i++){
		GD_POINT(arr[i][0], arr[i][1]);
		GD_SEGMENT(arr[i][0], arr[i][1], arr[i - 1][0], arr[i - 1][1], "blue bold");
		GD_PAUSE();
	}

	return 0;
}



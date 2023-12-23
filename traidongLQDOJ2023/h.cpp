#include <bits/stdc++.h>

using namespace std;

int main(){
	for (int i = 1; i <= 1000000; i++) if (i % 7 == 3 && i % 9 == 2 && i % 11 == 1){
		cout << i;
		break
	}	
	return 0;
}
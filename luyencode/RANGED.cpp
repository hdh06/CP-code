#include <bits/stdc++.h>

using namespace std;

int main(){
	long long A, B, C, D;
	cin >> A >> B >> C >> D;
	if ((A <= C && C <= B) || (A <= D && D <= B)) cout << "YES";
	else cout << "NO";
}
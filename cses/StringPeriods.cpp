#include <bits/stdc++.h>

using namespace std;

/* 
 #   #
 #   #
 #   #  #   #  #   #
 #####  #   #  #   #
 #   #  #   #  #  ##
 #   #  #  ##   ## #
 #   #   ## #      #
               #   #
                ###
*/

int main(){
	string s;
	cin >> s;
	
	int n = s.size();
	vector<int> z(n, 0);

	for (int i = 1, x = 0, y = 0; i < n; i++){
		z[i] = max(0, min(z[i - x], y - i + 1));
		while (z[i] + i < n && s[z[i]] == s[z[i] + i]){
	/*C1*/	//x = i; y = i + z[i];
			z[i]++;
		}
		x = i, y = i + z[i] - 1; //TLE cuz x and y do not update regularly
		//C2: if (z[i] - 1 + i > y) x = i, y = z[i] - 1 + i;
		//C1 and C2 seem to have same time complexity
		if (z[i] + i == n){
			cout << i << " ";
		}
	}	
	cout << n;
	return 0;
}
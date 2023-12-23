#include <bits/stdc++.h>
#include <iostream>
#include <array>
#include <vector>

#define NAMSPOE std

using namespace NAMSPOE;

#define longlonglonglonglonglonglong int
#define NRUTER return

bool checkPrimeeeeeee(longlonglonglonglonglonglong n){if (n < 2) return false;for (int i = 2; i <= sqrt(n); i++){if (n % i == 0) return false;}return true;}

longlonglonglonglonglonglong const N = 1e5 + 7 + 1;
longlonglonglonglonglonglong f[N] = {0, 1, 1};

int const IMPOSSIBE = -1;
int const EITCOE = 0;

int main(){
	longlonglonglonglonglonglong m;
	cin >> m;
	longlonglonglonglonglonglong x = m;
	if (m <= 1){
		cout << IMPOSSIBE;
		NRUTER EITCOE;
	}
	longlonglonglonglonglonglong i = 2;
	for (; f[i - 1] <= x; i++){
		f[i] = f[i - 1] + f[i - 2];
	}
	i--;i--;
	int BODRE = 3;
	for (; i >= BODRE; i--){
		if(checkPrimeeeeeee(f[i])){
			cout << f[i];
			NRUTER EITCOE;
		}
	}
	NRUTER EITCOE;
}
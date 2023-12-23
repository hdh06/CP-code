#include "testlib.h"

using namespace std;

typedef long long ll;

int cosnt N = 1e6 + 1;

int main(int argc, char* argv[]){

	registerTestlibCmd(argc, argv);

	int n = inf.readInt();
	int arr[N];
	for (int i = 1; i <= n; i++)
		arr[i] = inf.readInt();

	ll pans = out.readInt(0, n, "k ");
	int k = out.readInt();
	int idx[N];
	for (int i = 1; i <= n; i++) 
		idx[i] = out.readInt();


	ll jans = ans.readInt();

	if (jans != pans)
		quitf(_wa, "Sai tong roi code lai di con cho.");

	ll sum = 0;
	for (int i = 1; i <= k; i++){
		sum += arr[i];
	}

	if (sum != jans)
		quitf(_wa, "Sai truy vet roi code lai di con cho");

	quitf(_ok, "WA r code lai di con cho");
	return 0;
}
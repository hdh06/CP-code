#include <bits/stdc++.h>

using namespace std;

string const BRUTE = "brute";
string const SOL = "sol";
string const C_VERSION = "17";
int const N = 1000;

void compile(string file){
	const string com = "g++ -std=c++" + C_VERSION + " " + file + ".cpp -o " + file; 
	system(com.c_str()); 
}

void run(string file){
	const string com = "./" + file;
	system(com.c_str()); 
}

int main(){
	compile(BRUTE);
	compile(SOL);
	compile("gen");

	for (int t = 1; true ; t++){
		cout << "TESTCASE #" << t << ":\n";

		run("gen");
		run(BRUTE); 
		run(SOL); 

		string com = "diff -w f.ans f.out";
		if (system(com.c_str())){
			cout << "status: WA\n";
			return 0;
		}else cout << "status: AC\n";
	}
	return 0;
}
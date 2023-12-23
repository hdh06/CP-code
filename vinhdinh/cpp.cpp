#include <bits/stdc++.h>

using namespace std;

int main(){
    int n; 
    cin >> n;
    long long tong = 0;
    while(n--){
        long long temp; cin >> temp; tong += temp;
    }
    
    cout << tong;
    
    string s; 
    getline(cin, s);
    
    cout << '\n' << s << '\n';
    
    cin >> n;
    tong = 0;
    while(n--){
        long long temp; cin >> temp; tong += temp;
    }
    
    cout << tong;
    
    return 0;
}
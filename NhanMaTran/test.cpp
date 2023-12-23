#include <bits/stdc++.h>

using namespace std;

int const M = 1e9 + 7;

map<long, long> F;

long f(long n) {
     if (F.count(n)) return F[n];
     long k=n/2;
     if (n%2==0) { // n=2*k
         return F[n] = (f(k) * f(k) + f(k-1) * f(k-1)) % M;
     } else { // n=2*k+1
         return F[n] = (f(k) * f(k+1) + f(k-1) * f(k)) % M;
     }
}

int main(){
    F[0]=F[1]=1;
    cout << f(7);   
    return 0;
}
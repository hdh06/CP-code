#include <bits/stdc++.h>

using namespace std;

#define all(x) x.begin(),x.end()
#define stfu system("sudo poweroff")
#define ll long long
#define file "TEST"

int main(){
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n, m;
    cin >> n >> m;
    int tong = 0;
    int k = m;
    for (int i = 1; i <= n; i++){
        int a;
        cin >> a;
        int temp = a - k;
        a = max(0, temp);
        int prek = k;
        k = abs(min(0, temp));
        tong += prek - k;
        temp = a - m;
        a = max(0,temp);
        k = abs(min(0, temp));
        tong += m - min(m,k);
    }
    cout << tong;
    return 0;
}
    
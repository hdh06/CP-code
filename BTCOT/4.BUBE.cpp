#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n,k;
    cin>>n>>k;
    int a[n];
    for(int i=1; i<=n;i++)
        cin>>a[i];
    sort(a+1,a+1+n,greater<int>());
    long long tong=a[1];
    int vitri=1,i=2;

    while(i<=n)
    {
        if(a[vitri]-k<a[i])
        {
            tong=tong+a[i];
            i++;
        }
        else{
            vitri++;
            i++;
        }
    }
       cout<<tong;
    return 0;
}
    
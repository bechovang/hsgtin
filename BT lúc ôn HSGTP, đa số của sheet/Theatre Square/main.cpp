#include <bits/stdc++.h>

using namespace std;
#define endl '\n'
#define faster ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
int main()
{
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    long long  n,m,a;
    cin>>n>>m>>a;
    long long  k1=0;
    long long k2=0;
    if (n%a==0) k1=k1+n/a;
    else k1=k1+n/a+1;
    if (m%a==0) k2=k2+m/a;
    else k2=k2+m/a+1;
    cout<<k1*k2;
    return 0;
}

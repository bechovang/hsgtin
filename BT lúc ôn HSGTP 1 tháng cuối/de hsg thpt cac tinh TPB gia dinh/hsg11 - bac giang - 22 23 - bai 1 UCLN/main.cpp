#include <bits/stdc++.h>
#define endl '\n'
#define faster ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
//#define int long long
using namespace std;



signed main()
{
    faster;
    freopen("input.inp","r",stdin);
    freopen("output.out","w",stdout);
//    freopen("UCLN.INP","r",stdin);
//    freopen("UCLN.OUT","w",stdout);
    int a,b; cin>>a>>b;
    cout<<__gcd(a,b);
    return 0;
}

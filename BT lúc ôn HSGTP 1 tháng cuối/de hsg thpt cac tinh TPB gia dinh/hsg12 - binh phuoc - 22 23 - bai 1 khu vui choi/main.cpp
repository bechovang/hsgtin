#include <bits/stdc++.h>
#define endl '\n'
#define faster ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
//#define int long long
using namespace std;




signed main()
{
    faster;
//    freopen("KHUVUICHOI.INP","r",stdin);
//    freopen("KHUVUICHOI.OUT","w",stdout);
    freopen("input.inp","r",stdin);
    freopen("output.out","w",stdout);
    int a[100]={0};
    for (int i=6;i<12;i++) a[i]=6;
    for (int i=12;i<22;i++) a[i]=10;
    int x,y; cin>>x>>y;
    int dem=0;
    int tg=0;
    for (int i=x;i<y;i++){


        dem++;
        if (dem>4) tg=tg+(a[i]/2);
        else tg=tg+a[i];


    }

    cout<<tg;
    return 0;
}

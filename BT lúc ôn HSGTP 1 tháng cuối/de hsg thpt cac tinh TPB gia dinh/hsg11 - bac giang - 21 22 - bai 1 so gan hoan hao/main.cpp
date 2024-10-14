#include <bits/stdc++.h>
#define endl '\n'
#define faster ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
//#define int long long
using namesp ace std;

const int LimN=1e6;

int n;
int a[LimN+5];


signed main()
{
    faster;
    freopen("GHH.INP","r",stdin);
    freopen("GHH.OUT","w",stdout);
    // y tuong tu sang snt
    for (int i=1;i<LimN+5;i++){
        for (int j=i;j<LimN+5;j=j+i)
            a[j]=a[j]+i;
    }


    cin>>n;
    for (int i=1;i<=n;i++){
        int x; cin>>x;
        if (2*x<=a[x]) cout<<1<<endl;
        else cout<<0<<endl;

    }

    return 0;
}

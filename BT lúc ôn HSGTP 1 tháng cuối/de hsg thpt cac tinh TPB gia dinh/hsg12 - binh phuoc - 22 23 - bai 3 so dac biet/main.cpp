#include <bits/stdc++.h>
#define endl '\n'
#define faster ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define int long long
using namespace std;

const int LimN=3*1e6;
int tg_uoc[LimN+5];

signed main()
{
    faster;
    freopen("SODACBIET.INP","r",stdin);
    freopen("SODACBIET.OUT","w",stdout);
//    cout<<check(12);
    for (int i=1;i<=LimN;i++){
        for (int j=i;j<=LimN;j=j+i){
            if (j!=i)
                tg_uoc[j]+=i;
        }
    }

    int l,r; cin>>l>>r;
    int dem=0;
    for (int i=l;i<=r;i++){
        if (tg_uoc[i]>i)
            dem++;
    }
    cout<<dem;

    return 0;
}

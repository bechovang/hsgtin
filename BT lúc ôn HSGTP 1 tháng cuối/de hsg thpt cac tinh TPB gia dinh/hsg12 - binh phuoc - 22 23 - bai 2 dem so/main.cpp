///BECHOVANG

#include <bits/stdc++.h>
#define endl '\n'
#define faster ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define int long long
using namespace std;




signed main()
{
    faster;
    freopen("DEMSO.INP","r",stdin);
    freopen("DEMSO.OUT","w",stdout);
    int a,b,c; cin>>a>>b>>c;
    int tg=b-a+1;
    int i;
    for (i=a;i<=b;i++){
        if (i%c==0)
            break;
    }
    int j;
    for (j=b;i>=a;j--){
        if (j%c==0)
            break;
    }

//    cout<<i<<' '<<j;
    int kochiahet=(j-i)/c +1;

    cout<<tg-kochiahet;


    return 0;
}

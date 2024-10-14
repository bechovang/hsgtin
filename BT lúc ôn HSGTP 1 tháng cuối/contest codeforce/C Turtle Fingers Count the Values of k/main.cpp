///BECHOVANG

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
    int t; cin>>t;
    while (t--){
        int a,b,l;
        cin>>a>>b>>l;
        int dem=0;
        for (int i=0;i<=100;i++){
            for (int j=0;j<=100;j++){
                int d1=pow(a,i);
                int d2=pow(b,j);
                int mau= pow(a,i) * pow(b,j);
                double tmp= (1.0*l) / (1.0*mau);
                if (ceil(tmp) == floor(tmp) and tmp>1)
                    dem++;
            }
        }


        cout<<dem;
        cout<<endl;
    }


    return 0;
}

#include <bits/stdc++.h>

using namespace std;
#define endl '\n'
#define faster ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

int main()
{
    faster;
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    int t; cin>>t;
    while (t--){
        int a,b,c; cin>>a>>b>>c;
        int dem=0;
        double lon=max(a,b);
        double nho=min(a,b);
        while (lon!=nho){
            dem++;
            double chenh=(lon-nho)/2.0;
            if (c>=chenh){
                lon=lon-chenh;
                nho=nho+chenh;
            }
            else{
                lon=lon-c;
                nho=nho+c;
            }

        }
        cout<<dem<<endl;
    }
    return 0;
}

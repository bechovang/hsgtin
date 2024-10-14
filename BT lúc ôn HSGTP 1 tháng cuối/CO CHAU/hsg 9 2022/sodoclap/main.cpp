#include <bits/stdc++.h>
#define endl '\n'
#define faster ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define int long long
using namespace std;

bool check(int x){
    map<int,int> hm;
    while(x!=0){
        int k=x%10;
        if (hm[k]==0){
            hm[k]++;
        }
        else{
            return false;
        }
        x=x/10;
    }

    return true;
}


signed main()
{
    faster;
    freopen("sodoclap.inp","r",stdin);
    freopen("sodoclap.out","w",stdout);

    int x; cin>>x;
    while (x<LLONG_MAX){
        x++;
        if (check(x)==true)
            break;
    }

    cout<<x;


    return 0;
}

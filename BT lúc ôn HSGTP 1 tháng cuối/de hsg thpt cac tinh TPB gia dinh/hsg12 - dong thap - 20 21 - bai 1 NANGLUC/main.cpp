#include <bits/stdc++.h>
#define endl '\n'
#define faster ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define int long long
using namespace std;

int n,k;
int pf[100005]={0};
int a[100005]={0};

int sum(int x, int y){
    return pf[y]-pf[x-1];
}

signed main()
{
    faster;
    freopen("NANGLUC.INP","r",stdin);
    freopen("NANGLUC.OUT","w",stdout);
    cin>>n>>k;


    for (int i=1;i<=n;i++){
        cin>>a[i];
        pf[i]=pf[i-1]+a[i];
    }


    int maxx=-1;
    int i=1;
    int j=2;
    while (i!=n-1 or j!=n){
        if (sum(i,j)>=k){
            maxx=max(maxx,sum(i,j));
            while (sum(i,j)<k){
                i++;
                maxx=max(maxx,sum(i,j));
            }

        }
        j++;
    }

    cout<<maxx;


    return 0;
}

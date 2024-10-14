#include <bits/stdc++.h>

using namespace std;
#define endl '\n'
#define faster ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
int main()
{
    faster;
    freopen("hps.in","r",stdin);
    freopen("hps.out","w",stdout);

    int n;
    cin>>n;

    int h[100010],p[100010],s[100010];
    for (int i=1;i<=n;i++){
        string x;
        cin>>x;
        if (x=="P"){
            p[i]=p[i-1]+1;
            h[i]=h[i-1];
            s[i]=s[i-1];
        }
        if (x=="H"){
            p[i]=p[i-1];
            h[i]=h[i-1]+1;
            s[i]=s[i-1];
        }
        if (x=="S"){
            p[i]=p[i-1];
            h[i]=h[i-1];
            s[i]=s[i-1]+1;
        }
    }


//    for (int i=1;i<=n;i++){
//        cout<<h[i]<<' ';
//    }
//    cout<<endl;
//    for (int i=1;i<=n;i++){
//        cout<<p[i]<<' ';
//    }
//    cout<<endl;
//    for (int i=1;i<=n;i++){
//        cout<<s[i]<<' ';
//    }
//    cout<<endl;

    int lon=INT_MIN;
    for (int i=1;i<=n;i++){
        lon=max(lon, h[i] + max( p[n] - p[i] , s[n] - s[i] ) );
    }
    for (int i=1;i<=n;i++){
        lon=max(lon, p[i] + max( h[n] - h[i] , s[n] - s[i] ) );
    }
    for (int i=1;i<=n;i++){
        lon=max(lon, s[i] + max( p[n] - p[i] , h[n] - h[i] ) );
    }

    cout<<lon;
    return 0;
}

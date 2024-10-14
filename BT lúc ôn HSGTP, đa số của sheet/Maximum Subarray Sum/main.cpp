#include <bits/stdc++.h>

using namespace std;
#define endl '\n'
#define faster ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
int main()
{
    faster;
//    freopen("input.txt","r",stdin);
//    freopen("output.txt","w",stdout);

    int n; cin>>n;

    vector <long long> a(n+1,0);
    vector <long long> pf(n+1,0);

    for (int i=1;i<=n;i++){
        int x; cin>>x;
        pf[i]=pf[i-1]+x;
//        cout<<pf[i-1]+x<<' ';
    }
//    cout<<endl;

    long long nho=LLONG_MAX;
    for (int i=0;i<=n;i++){
        nho=min(nho,pf[i-1]);
        a[i]=pf[i]-nho;
    }

    //debug


    long long lon=LLONG_MIN;
    for (int i=1;i<=n;i++){
//        cout<<a[i]<<' ';
        lon=max(lon,a[i]);
    }


    cout<<lon;

    return 0;
}

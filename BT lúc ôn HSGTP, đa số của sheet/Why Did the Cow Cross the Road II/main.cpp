#include <bits/stdc++.h>

using namespace std;

int main()
{
    freopen("maxcross.in","r",stdin);
    freopen("maxcross.out","w",stdout);
    int n,k,b;
    int a[100001];
    int prefix[100001];
    fill(a,a+100001,1);
    fill(prefix,prefix+100001,0);

    cin>>n>>k>>b;
    for (int i=0;i<b;i++){
        int x;
        cin>>x;
        a[x]=0;
    }

//    for (int i=0;i<=10;i++){
//        cout<<a[i]<<' ';
//    }
//    cout<<endl;

    for (int i=1;i<=n;i++){
        prefix[i]=prefix[i-1]+a[i];
    }

//    for (int i=0;i<=10;i++){
//        cout<<prefix[i]<<' ';
//    }
//    cout<<endl;

    int nho=INT_MAX;
    for (int i=k+1;i<=n;i++){
//        nho=min(nho,k-prefix[i]-prefix[i-k-1]+1);
//        cout<<i<<' '<<k-(prefix[i]-prefix[i-k])<<' '<<prefix[i]<<' '<<prefix[i-k]<<' '<<prefix[i]-prefix[i-k]<<endl;
//        cout<<i<<' '<<k-(prefix[i]-prefix[i-k])<<endl;
        nho=min(nho,k-(prefix[i]-prefix[i-k]));
    }


    cout << nho << endl;
    return 0;
}


#include <bits/stdc++.h>

using namespace std;
#define endl '\n'
#define faster ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
int main()
{
    faster;
//    freopen("bcount.in", "r", stdin);
//	freopen("bcount.out", "w", stdout);
    freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
    int n,q;
    int a[100010];
    int b[100010];
    int c[100010];
    memset(a,0,100010);
    memset(b,0,100010);
    memset(c,0,100010);
    int x,y;
    cin>>n>>q;
    for (int i=1;i<=n;i++){
        cin>>x;
        if (x==1){
            a[i]=a[i-1]+1;
            b[i]=b[i-1];
            c[i]=c[i-1];
        }
        if (x==2){
            a[i]=a[i-1];
            b[i]=b[i-1]+1;
            c[i]=c[i-1];
        }
        if (x==3){
            a[i]=a[i-1];
            b[i]=b[i-1];
            c[i]=c[i-1]+1;
        }

    }

    for (int i=0;i<q;i++){
        cin>>x>>y;
        cout<<a[y]-a[x-1]<<' '<<b[y]-b[x-1]<<' '<<c[y]-c[x-1]<<endl;
    }


    for (int i=1;i<=n;i++){
        cout<<a[i]<<' ';
    }
    cout<<endl;
    for (int i=1;i<=n;i++){
        cout<<b[i]<<' ';
    }
    cout<<endl;
    for (int i=1;i<=n;i++){
        cout<<c[i]<<' ';
    }
    cout<<endl;

    return 0;
}

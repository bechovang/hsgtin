#include <bits/stdc++.h>

using namespace std;
#define endl '\n'
#define faster ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
int main()
{
    faster;
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    int x,y; cin>>x>>y;

    vector <int> a(x+1,0);
    vector <int> b(y+1,0);
    map <int,int> hm;
    for (int i=1;i<=x;i++){
        a[i]=i%5;
        hm[a[i]]++;
    }
    for (int i=1;i<=y;i++){
        b[i]=i%5;
        if (b[i]==0) b[i]=5;
    }

    long long dem=0;
    for (int i=1;i<=y;i++){
        dem=dem+hm[5-b[i]];
    }

    //debug
//    for (int i=1;i<=x;i++){
//        cout<<a[i]<<' ';
//    }
//    cout<<endl;
//    for (int i=1;i<=y;i++){
//        cout<<b[i]<<' ';
//    }
//    cout<<endl;
//    for (int i=1;i<=y;i++){
//        cout<<hm[5-b[i]]<<' ';
//    }
//    cout<<endl;
//
//    cout<<hm[0]<<endl;
    cout<<dem;
    return 0;
}

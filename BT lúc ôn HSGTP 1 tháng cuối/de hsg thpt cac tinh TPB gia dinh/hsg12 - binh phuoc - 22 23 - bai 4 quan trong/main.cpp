#include <bits/stdc++.h>
#define endl '\n'
#define faster ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define int long long
using namespace std;

const int LimN=5*1e5;

int n;
int pf[LimN+5]={0};
int cuoi[LimN+5]={0};
int dau[LimN+5]={0};
set <int> myset;

int sum(int x,int y){
    return pf[y] - pf[x-1];
}


signed main()
{
    faster;
    freopen("QUANTRONG.INP","r",stdin);
    freopen("QUANTRONG.OUT","w",stdout);
    for (int i=0;i<LimN+5;i++){
        dau[i]=INT_MAX;
        cuoi[i]=INT_MIN;
    }

    cin>>n;
    for (int i=1;i<=n;i++){
        int x; cin>>x;
        myset.insert(x);
        pf[i]=pf[i-1]+x;
        dau[x]=min(dau[x],i);
        cuoi[x]=max(cuoi[x],i);
    }

    int kq=-1;
    for (auto k: myset){
        int x=dau[k];
        int y=cuoi[k];
        if (x==y) continue;
        else{
            kq=max(kq,sum(x,y));
        }
    }
    cout<<kq;


//    //debug;
//    cout<<endl;
//    for (int i=1;i<=n;i++){
//        cout<<pf[i]<<' ';
//    }
//    cout<<endl;
//    for (auto x: myset){
//        cout<<x<<' ';
//    }
//    cout<<endl;
//    for (auto x: myset){
//        cout<<dau[x]<<' ';
//    }
//    cout<<endl;
//    for (auto x: myset){
//        cout<<cuoi[x]<<' ';
//    }
//    cout<<endl;








    return 0;
}

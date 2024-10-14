#include <bits/stdc++.h>
#define endl '\n'
#define faster ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define int long long
using namespace std;

const int LimN=1e6;
int n,h;

bool la_snt[LimN+5];
void sang_snt(int n){
    la_snt[0]=false;
    la_snt[1]=false;
    for (int i=2;i*i<=n;i++){
        if (la_snt[i]==true)
            for (int j=i*i;j<=n;j=j+i){
                la_snt[j]=false;
            }
    }

    return;
}

bool check(int x){
    if (la_snt[x]==false)
        return false;
    int tg=0;
    while(x!=0){
        tg=tg+x%10;
        x=x/10;
    }

    if (tg!=h) return false;


    return true;

}


signed main()
{
    faster;
    freopen("DOCAO.INP","r",stdin);
    freopen("DOCAO.OUT","w",stdout);
    for (int i=0;i<LimN+5;i++) la_snt[i]=true;
    sang_snt(LimN);

    cin>>n;
    cin>>h;

    int dem=0;
    for (int i=1;i<=n;i++){
        if (check(i)==true){
            dem++;
            cout<<i<<endl;
        }
    }
    cout<<dem;

//    //debug
//    for (int i=0;i<100;i++) if (la_snt[i]==true) cout<<i<<' ';


    return 0;
}

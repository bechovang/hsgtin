#include <bits/stdc++.h>
#define endl '\n'
#define faster ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

int giaithua_mod(int a){
    int k=1;
    for (int i=1;i<=a;i++){
        k=( (k% 20240131) * (i % 20240131) ) % 20240131;
    }

    return k;


}

int main()
{
    faster;
    freopen("FACTORIAL.INP","r",stdin);
    freopen("FACTORIAL.OUT","w",stdout);
    int n; cin>>n;
    int kq=0;
    for (int i=1;i<=n;i++){
        kq=( (kq % 20240131) + (giaithua_mod(i)% 20240131) ) % 20240131;
    }


    cout<<kq;

    return 0;
}

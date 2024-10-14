#include <bits/stdc++.h>
#define endl '\n'
#define faster ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
using namespace std;
typedef long long ll;
int main()
{
    faster;
    freopen("BEADS.INP","r",stdin);
    freopen("BEADS.OUT","w",stdout);
    int n; cin>>n;
    long long a[n];
    for (int i=0;i<n;i++){
        cin>>a[i];
    }


    ll dp_tang_xuoi[n];
    ll dp_giam_xuoi[n];
    //memset
    for (int i=0;i<n;i++) dp_tang_xuoi[i]=1;
    for (int i=0;i<n;i++) dp_giam_xuoi[i]=1;




    for (int i=0;i<n;i++){
        for (int j=0;j<i;j++){
            if (a[i] > a[j]){
                dp_tang_xuoi[i]= max(dp_tang_xuoi[i], dp_tang_xuoi[j] +1);
            }
            if (a[i] < a[j]){
                dp_giam_xuoi[i]= max(dp_giam_xuoi[i], dp_giam_xuoi[j] +1);
            }
        }
    }
//
//    //debug;
//    for (auto x: dp_tang_xuoi){
//        cout<<x<<' ';
//    }
//    cout<<endl;
//    for (auto x: dp_giam_xuoi){
//        cout<<x<<' ';
//    }
//    cout<<endl;


    ll kq=-1;
    for (int i=0;i<n;i++){
        kq=max(kq, dp_tang_xuoi[i]+dp_giam_xuoi[i] -1 );
    }

    cout<<kq;

    return 0;
}

#include <bits/stdc++.h>
#define endl '\n'
#define faster ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
typedef long long ll;
using namespace std;

int main()
{
    faster;
    freopen("WAVIO.INP","r",stdin);
    freopen("WAVIO.OUT","w",stdout);
    int n;
    while (cin>>n){
        vector<ll> v;
        for (int i=0;i<n;i++){
            ll x; cin>>x;
            v.push_back(x);
        }

        vector <ll> dp_tang_xuoi(n,1);
        for (int i=0;i<n;i++){
            for (int j=0;j<i;j++){
                if (v[i]>v[j]){
                    dp_tang_xuoi[i]=max(dp_tang_xuoi[i], dp_tang_xuoi[j] + 1);
                }
            }
        }


        vector <ll> dp_tang_nguoc(n,1);
        for (int i=n-1;i>=0;i--){
            for (int j=n-1;j>i;j--){
                if (v[i]>v[j]){
                    dp_tang_nguoc[i]=max(dp_tang_nguoc[i], dp_tang_nguoc[j] + 1);
                }
            }
        }


//        //debug
//        for (auto x: dp_tang_xuoi){
//            cout<<x<<' ';
//        }
//        cout<<endl;
//        for (auto x: dp_tang_nguoc){
//            cout<<x<<' ';
//        }
//        cout<<endl;


        ll kq=1;
        for (int i=0;i<n;i++){
            if (dp_tang_xuoi[i] != 1 and dp_tang_nguoc[i] != 1)
                kq=max(kq, dp_tang_nguoc[i] + dp_tang_xuoi[i] -1 );
        }

//        if (kq%2==1) // do dãy wavio đề y/c phải có chiều dài là lẻ
//            cout<<kq;
//        else
//            cout<<kq-1;
//        cout<<endl;
//
        cout<<kq;

    }
    return 0;
}


//bechovang
// xử lí được n tối đa =10^3


#include <bits/stdc++.h>
#define endl '\n'
#define faster ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define ll int
using namespace std;


int main()
{
    faster;
    freopen("input.INP","r",stdin);
    freopen("output.OUT","w",stdout);
    int n; cin>>n;
    vector <int>a;
    for (int i=0;i<n;i++){
        int x; cin>>x;
        a.push_back(x);
    }


    vector<int> dptang(n,1);
    vector<int> dpgiam(n,1);
    for (int i=0;i<n;i++){
        for (int j=0;j<i;j++){
            if (a[j]<a[i])
                dptang[i]=max(dptang[i], dpgiam[j] +1);
            if (a[j]>a[i])
                dpgiam[i]=max(dpgiam[i], dptang[j] +1);
        }
    }

//    //debug
//    for (auto x:dptang){
//        cout<<x<<' ';
//    }
//    cout<<endl;
//
//    //debug
//    for (auto x:dpgiam){
//        cout<<x<<' ';
//    }
//    cout<<endl;


    int kq=-1;
    for (auto x:dptang){
        kq=max(kq,x);
    }
    for (auto x:dpgiam){
        kq=max(kq,x);
    }


    cout<<kq;





    return 0;
}

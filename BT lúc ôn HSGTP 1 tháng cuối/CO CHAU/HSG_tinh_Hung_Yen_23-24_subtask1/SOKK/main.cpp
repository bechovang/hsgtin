#include <bits/stdc++.h>
#define endl '\n'
#define faster ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

vector <int> v;

int tknp(int k){
    int l=0;
    int r=v.size();
    while (l<=r){ // phải <= mà ko phải < vì đôi lúc l=r thì v[mid] ms bằng k
        int mid= (l+r)/2;
        //cout<<v[mid]<<endl;
        if (v[mid]==k)
            return mid;
        if (v[mid]<k){
            l=mid+1;
        }
        if (v[mid]>k){
            r=mid-1;
        }
    }

    return -1;
}

int main()
{
    faster;
    freopen("SOK.INP","r",stdin);
    freopen("SOK.OUT","w",stdout);

    int n; cin>>n;
    int t; cin>>t;

    for (int i=0;i<=1000000;i++){
        v.push_back(i);
    }
    for (int i=0;i<n;i++){
        int x; cin>>x;
        if (tknp(x) != -1)
            v.erase(v.begin() +tknp(x));
    }

//    for (int i=0;i<=20;i++){
//        cout<<v[i]<<' ';
//    }
//    cout<<endl;


    while (t--){
        int x; cin>>x;
        cout<<v[x]<<endl;
    }





    return 0;
}

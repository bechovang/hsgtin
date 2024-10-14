#include <bits/stdc++.h>
#define endl '\n'
#define faster ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
//#define int long long
using namespace std;


signed main()
{
    faster;
    freopen("count.inp","r",stdin);
    freopen("count.out","w",stdout);
    int n; cin>>n;
    vector<int> v;
    map<int,int> hm;

    int kq=0;

    int nhap; cin>>nhap;
    v.push_back(nhap);
    int top=v[0];
    int last=nhap;

    for (int i=0;i<n-1;i++){
        last=v[v.size()-1];

        nhap; cin>>nhap;
        v.push_back(nhap);
        top=v[0];

        int sz=v.size();
        int pos_sz=v.size()-1;

        if (nhap>top){
            kq+= v.size() -1;
            while (v[0]!=nhap){
                v.erase(v.begin());
            }
        }
        else if (nhap<=last and nhap<=top){ //nhap=last thi ko co gi o truoc che no. 1 1 5 1
            if (nhap<last) kq+= 1; //5 6 5 7 3 3
            if (nhap == last and last = top) kq+= 2;
        }
        else if (nhap>last and nhap<top){
            kq+= v.size() -1 -1; //-1 them vi ko tinh hien tai
            v.erase(v.begin()+ (pos_sz-1) );
        }





    }

    cout<<kq;
    return 0;
}

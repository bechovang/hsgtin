#include <bits/stdc++.h>

using namespace std;
#define endl '\n'
#define faster ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
typedef long long ll;

bool sortPairsCmp(const pair<ll,ll> &a, const pair<ll,ll> &b){
    return a.second > b.second; // Sửa thành a.second > b.second để sắp xếp giảm dần theo số lượng que diêm
}

int main()
{
    faster;
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    //n<=2.10^8 => long long
    // pair rồi sort

    vector< pair<ll,ll> > vp; // Sửa ll,int thành ll,ll để phù hợp với cặp (ai, bi)
    ll n,m; cin>>n>>m;
    for (int i=0;i<m;i++){
        ll x,y;
        cin>>x>>y;
        vp.push_back(make_pair(x, y));
    }

    sort(vp.begin(), vp.end(), sortPairsCmp);

    ll dem=0;
    for (int i=0;i<m;i++){
        dem=dem + vp[i].second * min(n,vp[i].first); // dùng min để ko lấy lố
        n=n-vp[i].first; // trừ đi phần đã lấy

        if (n<=0) break;
    }

//    //debug
//    for (int i=0;i<m;i++){
//        cout<<vp[i].first<<' '<<vp[i].second<<endl;
//    }
//    cout<<endl;

    cout<<dem;
    return 0;
}

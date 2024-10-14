// ngai KHOAI Orz Orz Orz Orz
#include <bits/stdc++.h>
#define endl '\n'
#define faster ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define int long long
using namespace std;
map<int,int> hm;
vector <int> a;


int low(int x){
    vector<int>::iterator low1;
    low1 = lower_bound(a.begin(), a.end(), x);
    return (low1 - a.begin()) -1;
}

int up(int x){
    vector<int>::iterator up1;
    up1 = upper_bound(a.begin(), a.end(), x);
    int pos=(up1 - a.begin()) -1;
    if(pos==-1 and a[0]>x)
        return 0;
    return pos;
}

signed main()
{
    faster;
    freopen("MARIO.INP","r",stdin);
    freopen("MARIO.OUT","w",stdout);
    int n,pos,k; cin>>n>>pos>>k;
    for (int i=0;i<n;i++){
        int x, y; cin>>x>>y;
        hm[x]=y;
        a.push_back(x);
    }
    sort(a.begin(), a.end());
    //prefix
    int pf[n+2]={0};
    pf[0]=0;
    pf[1]=a[0];
    for (int i=2;i<=n+1;i++){
        pf[i]=pf[i-1] + hm[a[i-1]];
    }




    //debug
    // lower bound
    //      đến phần tử đầu tiên trong nửa đoạn [first,last]
    //      mà không bé hơn khóa tìm kiếm
    //         (>= khóa)
    //upper bound
    //      phần tử đầu tiên trong nửa đoạn [first,last]
    //      mà lớn hơn khóa tìm kiếm.
    for (int i=-7;i<=7;i++) cout<<abs(i)<<' ';
    cout<<endl;
    for (int i=-7;i<=7;i++) cout<<low(i)<<' ';
    cout<<endl;
    for (int i=-7;i<=7;i++) cout<<up(i)<<' ';
    cout<<endl;

    cout<<endl;
    cout<<"debug mang: "<<endl;
    for (auto x: a) if (x==LLONG_MIN) cout<<'M'<<' '; else cout<<x<<' '; cout<<endl;
    for (int i=0;i<=n;i++ ) cout<<hm[a[i]]<<' '; cout<<endl;
    for (auto x: pf) cout<<x<<' '; cout<<endl;



    return 0;
}

//bỏ prefix sum đi
//rồi giải cho ra cái LR bằng BS

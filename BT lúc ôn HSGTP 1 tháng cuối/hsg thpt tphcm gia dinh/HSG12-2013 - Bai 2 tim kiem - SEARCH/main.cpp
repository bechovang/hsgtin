#include <bits/stdc++.h>
#define endl '\n'
#define faster ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
//#define int long long
using namespace std;

int a,b;
int bfs(int s){
    vector <int> depth(100005,INT_MAX); // vừa là dep, vừa la vis
    queue <pair<int,int>> Q;

    Q.push({s,0}), depth[s]=0;

    while(Q.empty()==false){
        pair<int,int> p =Q.front(); Q.pop();
        int cur=p.first;
        int dep=p.second;

        if (cur==b){
            cout<<dep;
            break;
        }

        if (depth[cur+1]==INT_MAX and cur+1<100005)  //phải thêm ĐK <100005 để ko bị tràn
            Q.push({cur+1,dep+1}), depth[cur+1]=dep+1;
        if (depth[cur-1]==INT_MAX and cur-1>=0) //phải thêm ĐK >=0 để ko bị tràn
            Q.push({cur-1,dep+1}), depth[cur-1]=dep+1;
        if (depth[cur*2]==INT_MAX and cur*2<100005)//phải thêm ĐK <100005 để ko bị tràn
            Q.push({cur*2,dep+1}), depth[cur*2]=dep+1;
    }

    return 0;
}

signed main()
{
    faster;
    freopen("SEARCH.INP","r",stdin);
    freopen("SEARCH.OUT","w",stdout);
    cin>>a>>b;
    bfs(a);
    return 0;
}

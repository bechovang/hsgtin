#include <bits/stdc++.h>
#define endl '\n'
#define faster ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
//#define int long long
using namespace std;

int a,b;

int bfs(int s, int depth){
    queue <pair<int,int>> Q;
    Q.push({s,depth});
    while(Q.empty()==false){
        pair<int,int> p =Q.front(); Q.pop();
        int cur=p.first;
        int dep=p.second;
        if (cur==b){
            cout<<dep;
            break;
        }


        Q.push({cur+1,dep+1});
        Q.push({cur-1,dep+1});
        Q.push({cur*2,dep+1});
    }

    return 0;
}

signed main()
{
    faster;
    freopen("search.inp","r",stdin);
    freopen("search.ans","w",stdout);
    cin>>a>>b;
    bfs(a,0);
    return 0;
}

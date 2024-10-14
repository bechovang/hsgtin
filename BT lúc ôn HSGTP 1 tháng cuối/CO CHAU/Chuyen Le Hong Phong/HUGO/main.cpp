#include <bits/stdc++.h>
#define endl '\n'
#define faster ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
//#define int long long
using namespace std;

struct edge{
    int u;
    int v;
    int w;
};
bool cmp(edge a, edge b){
    return a.w<b.w;
}


int dinh;
vector <edge> a;
vector<vector<int>> v;
int vis[105];
int par[105];


void inkq(){
    int demX=0;
    int tg=0;
    int k=-1;
    cout<<dinh<<' ';

    k=par[dinh];
    cout<<k<<' ';

    int time=0;
    while(k!=1){
        k=par[k];
        cout<<k<<' ';
        time++;
        if (time==100) break;
    }

    cout<<endl;
}


void dfs(int x){
    if (vis[x]==true)
        return;
    if (x==dinh){
        inkq();
    }
    vis[x]=true;
    for (auto k:v[x]){
        par[k]=x;
        dfs(k);
    }
}



signed main()
{
    faster;
    freopen("HUGO.INP","r",stdin);
    freopen("HUGO.OUT","w",stdout);

    cin>>dinh;

    int x,y,z;
    while(cin>>x>>y>>z){
        edge p;
        p.u=x;
        p.v=y;
        p.w=z;
        a.push_back(p);
    }

    sort(a.begin(), a.end(), cmp);

    v.resize(dinh+1);
    for (auto x: a){
        if (x.w != 0){
            v[x.u].push_back(x.v);
            v[x.v].push_back(x.u);
        }
    }
    for (auto x: a){
        if (x.w == 0){
            v[x.u].push_back(x.v);
            v[x.v].push_back(x.u);
        }
    }


    //debug
    for (int i=1;i<=dinh;i++){
        cout<<"dinh :"<<i<<endl;
        for (auto x: v[i])
            cout<<x<<' ';
        cout<<endl;
    }
    cout<<endl;
    for (auto x: a){
        cout<<x.u<<' '<<x.v<<' '<<x.w<<endl;
    }
    cout<<endl;




    for (int i=0;i<=105;i++) vis[i]=0;
    for (int i=0;i<=105;i++) par[i]=0;
    dfs(1);

    inkq();






    return 0;
}

#include <bits/stdc++.h>
#define endl '\n'
#define faster ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define int long long
using namespace std;

int dinh, canh;
vector<vector<pair<int,int>>> v;
int flow [1005][1005];

struct node{
    int u;
    int Dist;
};

struct cmp{
    bool operator() (node a, node b){
        return a.Dist > b.Dist; // > la top=be nhat (priority queue)
    }
};

vector <int> d(1005,INT_MAX);
vector <int> par(1005,0);
vector <bool> vis(1005,false);

void dijkstra(int s, int f){
    d.clear();
    par.clear();
    vis.clear();
    d.resize(1005,INT_MAX);
    par.resize(1005,0);
    vis.resize(1005,false);

    d[s]=0;

    priority_queue <node, vector<node>, cmp> Q;
    Q.push({s,0});

    while (Q.empty()==false){
        node p=Q.top(); Q.pop();
        int u=p.u;
        int dist=p.Dist;

        if (vis[u]==true) continue;
        vis[u]=true;

        for (int i=0;i<v[u].size();i++){
            pair x=v[u][i];
            int child=x.first;
            int w=x.second;
            if (d[child] > d[u] + w and flow[u][child]>=f){
                d[child] = d[u] + w;
                Q.push({child, d[child]});
            }
        }
    }
}

signed main()
{
    faster;
    freopen("input.inp","r",stdin);
    freopen("output.out","w",stdout);
    cin>>dinh>>canh;
    v.resize(dinh+1);
    int duyet_flow [1005];
    for (int i=0;i<canh;i++){
        int x,y,z; cin>>x>>y>>z;
        v[x].push_back({y,z});
        v[y].push_back({x,z});
        cin>>duyet_flow[i];
        flow[x][y]=duyet_flow[i];
        flow[y][x]=duyet_flow[i];

    }


    int kq=-1;
    for (int i=0;i<canh;i++){
        int f=duyet_flow[i];
        dijkstra(1,f);
        int k= d[dinh];
//        cout<<k<<endl;

        if (k!=INT_MAX){
            int tmp= floor( (f*1.0) / (k*1.0) * 1000000 ) ;
//            cout<<tmp<<endl;
            kq=max(kq,tmp);
        }
    }


    cout<<to_string(kq);

    return 0;
}

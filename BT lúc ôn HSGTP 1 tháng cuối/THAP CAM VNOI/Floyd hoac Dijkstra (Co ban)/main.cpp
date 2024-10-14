#include <bits/stdc++.h>
#define endl '\n'
#define faster ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
//#define int long long
using namespace std;

struct node{
    int u;
    int Dist;
};

struct cmp{
    bool operator() (node a, node b){
        return a.Dist > b.Dist;
    }
};

int dinh, canh, q;
vector<vector<pair<int,int>>> v;
int d[1005];
int par[1005];
int vis[1005];


void dijkstra(int s){
    fill(d, d+1005, INT_MAX);
    fill(par, par+1005, 0);
    fill(vis, vis+1005, false);
    d[s]=0;

    priority_queue<node, vector<node>, cmp> Q;
    Q.push({s,0});

    while (Q.empty()==false){
        node top; top=Q.top(); Q.pop();
        int u=top.u;
        int Dist=top.Dist;

        if (vis[u]==true) continue;
        vis[u]=true;

        for (auto x: v[u]){
            int child=x.first;
            int w=x.second;
            if (d[child]>d[u] +w){
                d[child]= d[u] +w;
                par[child]=u;
                Q.push({child,d[child]});
            }
        }
    }

}

signed main()
{
    faster;
    freopen("input.inp","r",stdin);
    freopen("output.out","w",stdout);
    cin>>dinh>>canh>>q;
    v.resize(dinh+1);
    for (int i=0;i<canh;i++){
        int x,y,z; cin>>x>>y>>z;
        v[x].push_back({y,z});
        v[y].push_back({x,z});
    }

    while(q--){
        int k,a,b; cin>>k>>a>>b;
        if (k==0){
            dijkstra(a);
            cout<<d[b]<<endl;
        }
        if (k==1){
            dijkstra(a);

            vector <int> path;
            int k=b;
            while (k!=a){
                path.push_back(k);
                k=par[k];
            }
            path.push_back(k);

            reverse(path.begin(), path.end());

            cout<<path.size()<<' ';
            for (auto x: path)
                cout<<x<<' ';
            cout<<endl;
        }


    }



    //    //debug
//    dijkstra(1);
//    for (int i=1;i<=dinh;i++){
//        cout<<d[i]<<' ';
//    }
//    cout<<endl;








    return 0;
}

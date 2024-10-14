#include <bits/stdc++.h>
#define endl '\n'
#define faster ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define int long long
using namespace std;

const int inf=LLONG_MAX;

int dinh,canh;
vector<vector<pair<int,int>>> v;
vector <int> d;
vector <int> par;
vector <bool> vis;

void dijkstra(int s){
    // mang luu khoang cach duong di
    d.resize(dinh+1,inf);
    par.resize(dinh+1,0);
    vis.resize(dinh+1,false);
    d[s]=0;

    priority_queue <pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> Q;
    // {khoang cach - dinh}  // hàng đợi ưu tiên, sắp xếp theo d[u] nhỏ nhất trước
    Q.push({0,s});
    while (Q.empty()==false){
        //Chọn ra đỉnh có khoảng cách từ s nhỏ nhất
        pair <int,int> top; top=Q.top(); Q.pop();
        int u=top.second;
        int kc=top.first;
//        if (kc > d[u]) continue; // Đỉnh u đã được chọn trước đó
        if (vis[u]==true) continue; // Đỉnh u đã được chọn trước đó
        vis[u]=true;
        //Relaxtion : Thông qua đỉnh u đã biết khoảng cách ngắn nhất tính từ S, cập
		//nhật khoảng cách với các đỉnh kề với u
        for (auto x : v[u]){
            int child=x.first;
            int w=x.second;

            if (d[child] > d[u] + w){
                d[child] = d[u] + w;
                Q.push({d[child], child});
                par[child] = u;
            }
        }
    }

    return ;
}

signed main()
{
    faster;
//    freopen("INPUT.INP","r",stdin);
//    freopen("OUTPUT.OUT","w",stdout);
    cin>>dinh>>canh;

    v.resize(dinh+1);
    for (int i=0;i<canh;i++){
        int x,y,z; cin>>x>>y>>z;
        v[x].push_back({y,z});
//        v[y].push_back({x,z});
    }
    dijkstra(1);

    for (int i=1;i<=dinh;i++){
        cout<<d[i]<<' ';
    }

    return 0;
}

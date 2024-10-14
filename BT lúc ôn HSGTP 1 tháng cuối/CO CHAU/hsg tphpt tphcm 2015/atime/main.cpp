#include <bits/stdc++.h>
#define endl '\n'
#define faster ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define int long long
using namespace std;

const int inf=INT_MAX;

int dinh, canh, start, finish, atime, n;
vector<int> king_path;
pair<int,int> prohibit[1005][1005];
vector<vector<pair<int,int>>> v;
vector<vector<pair<int,int>>> v_real;
vector<int> d;  //dijkstra
vector<int> par;
vector<int> vis;

bool valid(int x, int y, int time_x, int time_y){
    if (time_x==0 and time_y==0)
        return false;
    int d1=d[x];
    if (d[x]>=time_x and d[x]<=time_y)
        return true;
    return false;

}

void thoi_gian_cho(int x){
    for (int k=0;k<v[x].size();k++){
        int y=v[x][k].first;
        int w=v[x][k].second;
        if (vis[y]==true) continue;

        int time_x=prohibit[x][y].first;
        int time_y=prohibit[x][y].second;
        if (valid(x,y,time_x,time_y)){
                int d1=d[x];
            w=w+abs(d[x]-time_y) +1;
            v[x][k]={y,w};
        }
    }
}


void dijkstra(int s){
    d.resize(dinh+1, inf);
    par.resize(dinh+1, 0);
    vis.resize(dinh+1, false);
    d[s]=atime; //shipper di sau vua atime phut

    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> Q;
    // khoang canh - dinh. hang doi uu tien: sap xep theo d[u] nho nhat
    Q.push({atime,s});

    while (Q.empty()==false){
        // chon dinh cho khoang cach nho nhat
        pair<int,int> top; top=Q.top(); Q.pop();
        int u=top.second;
        int w=top.first;
        //dinh da duoc xet chua
        if (vis[u]==true) continue;
        vis[u]=true;
        //***thoi gian cho
        thoi_gian_cho(u);
        //relaxation
        for (auto x: v[u]){
            int child=x.first;
            int w=x.second;
            if (d[child] > d[u] + w){
                d[child] = d[u] + w;
                Q.push({d[child],child});
                par[child]=u;
            }
        }


    }

    return;
}

signed main()
{
    faster;
    freopen("atime.inp","r",stdin);
    freopen("atime.out","w",stdout);
    cin>>dinh>>canh;
    cin>>start>>finish>>atime>>n;
    for (int i=0;i<n;i++){
        int x; cin>>x;
        king_path.push_back(x);
    }

    v.resize(dinh+1);
    for (int i=0;i<canh;i++){
        int x,y,z;
        cin>>x>>y>>z;
        v[x].push_back({y,z});
        v[y].push_back({x,z});
    }

    //make prohibit
    int tg=0;
    int prev_tg=0;
    for (int i=1;i<n;i++){
        int x=king_path[i-1];
        int y=king_path[i];
        for (auto k: v[x]){
            if (k.first == y){
                tg+=k.second;
            }
        }
        prohibit[x][y]={prev_tg,tg-1};
        prohibit[y][x]={prev_tg,tg-1};

        cout<<x<<' '<<y<<' '<<prev_tg<<' '<<tg-1<<endl;
//        vap phut 10 và cần 5p
//        phong toả vào phút 10 , 11, 12, 13 và 14.
//        cần vào phút thứ 9, hoặc từ phút 15 trở đi
        prev_tg=tg;
    }

    dijkstra(1);
    cout<<d[finish]-atime;
//    //debug
//    for (auto x: v[1]){
//        if (x.first==2)
//            cout<<"yes";
//    }

    return 0;
}

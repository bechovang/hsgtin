#include <bits/stdc++.h>
#define endl '\n'
#define faster ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
//#define int long long
using namespace std;

int n,m;
int a[1005][1005]={0};
int d[1005][1005]={0};
pair<int,int> par[1005][1005];
bool vis[1005][1005]={0};
int last;
vector <pair<int,int>> path;

struct node{
    int x;
    int y;
    int Dist;
};

struct cmp{
    bool operator() (node a, node b){
        return a.Dist > b.Dist; //lay top la d[u] lon nhat
    }
};



void area(int a[][1005], int x) {
    for (int i=1;i<=n;i++){
        for (int j=1;j<=m;j++){
            a[i][j] = x;
        }
    }
}

void area_bool(bool a[][1005], bool x) {
    for (int i=1;i<=n;i++){
        for (int j=1;j<=m;j++){
            a[i][j] = x;
        }
    }
}

void area_pair(pair<int,int> a[][1005], pair<int,int>x) {
    for (int i=1;i<=n;i++){
        for (int j=1;j<=m;j++){
            a[i][j] = x;
        }
    }
}

bool valid (int x, int y){
    if (x<1)
        return false;
    if (y<1)
        return false;
    if (x>n)
        return false;
    if (y>m)
        return false;

    return true;
}

int dijkstra (int Start_x, int Start_y){
    last=-1;
    area(d,INT_MIN);
    area_pair(par,{0,0});
    area_bool(vis,false);
    d[Start_x][Start_y]=a[Start_x][Start_y];

    //hang doi uu tien
    priority_queue <node, vector<node>, cmp> Q;
    Q.push({Start_x,Start_y,d[Start_x][Start_y]});

    while (Q.empty()==false){
        // chon ra d[u] lon nhat
        node p; p=Q.top(); Q.pop();
        int x=p.x;
        int y=p.y;
        int w=p.Dist;

        if (vis[p.x][p.y]==true) continue;
        vis[p.x][p.y]=true;

        if (valid(x-1,y+1)){
            w=a[x-1][y+1];
            if (d[x-1][y+1] < d[x][y] + w){
                d[x-1][y+1] = d[x][y] + w;
                par[x-1][y+1] = {x,y};
                Q.push({x-1,y+1,d[x][y+1]});
            }
        }

        if (valid(x,y+1)==true){
            w=a[x][y+1];
            if (d[x][y+1] < d[x][y] + w){
                d[x][y+1] = d[x][y] + w;
                par[x][y+1] = {x,y};
                Q.push({x,y+1,d[x][y+1]});
            }
        }



        if (valid(x+1,y+1)){
            w=a[x+1][y+1];
            if (d[x+1][y+1] < d[x][y] + w){
                d[x+1][y+1] = d[x][y] + w;
                par[x+1][y+1] = {x,y};
                Q.push({x+1,y+1,d[x][y+1]});
            }
        }

    }


    // tim kq lon nhat o cot cuoi
    int maxx=INT_MIN;
    for (int i=1;i<=n;i++){
        if (d[i][m]>maxx){
            maxx=d[i][m];
            last=i;
        }
    }
    return maxx;
}

void nhap_path(){
    path.clear();
    int x=last;
    int y=m;
    while (y!=0){
        pair<int,int> k;
        path.push_back({x,y}); // ko push back k đc
        k=par[x][y];
        x=k.first;
        y=k.second;

    }
    reverse(path.begin(),path.end());
}


signed main()
{
    faster;
    freopen("maxpath.inp","r",stdin);
    freopen("maxpath.out","w",stdout);
    cin>>n>>m;
    for (int i=1;i<=n;i++){
        for (int j=1;j<=m;j++){
            cin>>a[i][j];
        }
    }

    int maxx=INT_MIN;

    for (int i=1;i<=n;i++){
//        cout<<dijkstra(i,1)<<endl;
        int k=dijkstra(i,1);
        if (maxx<k){
            maxx=k;
            nhap_path();
        }






    }

    int dem=path.size();;
    for (auto u: path){
        dem--;
        if (dem!=0)
            cout<<u.first<<" --> ";
        else
            cout<<u.first;
    }
    cout<<endl;

    cout<<maxx;

    return 0;
}

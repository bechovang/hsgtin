#include <bits/stdc++.h>

#define end; '\n'
#define faster ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
using namespace std;

int n,k;
vector<vector<int>> v; // danh sach ke. phai khoi tao mang
int vis[100000];
void nhap(){
    for (int i=1;i<=k;i++){
        int x;
        cin>>x;
        for (int j=0;j<x;j++){
            int y;
            cin>>y;
            v[i].push_back(y);
        }
    }
}

void debugmang(){
    for (int i=1;i<=k;i++){
        cout<<"dinh "<<i<<endl;
        for (int j=0;j<v[i].size();j++){
            cout<<v[i][j]<<' ';
        }
        cout<<endl;
    }
}
vector< vector<int> > adj; // danh sách kề
vector<bool> visited; // mảng vector đánh dấu đã thăm
vector<int> topsort;  //mảng vector đánh dấu đã thăm

void dfs(int node)
{
//    cout<<"dfs: "<<node<<endl;
    visited[node] = true;

    for (int i = 0; i < v[node].size(); i++)
    {
        int child = v[node][i];
        if (!visited[child])    // tránh duyệt lại các đỉnh đã duyệt
            dfs(child);
    }

    topsort.push_back(node);    // DAG // Other way Indegree / Outdegree
}
int main()
{
    faster;
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);

    v.resize(100000); // khoi tao Số lượng đỉnh là 100000
    adj.resize(100000); // khoi tao Số lượng đỉnh là 100000
    visited.resize(100000); // khoi tao Số lượng đỉnh là 100000
    cin>>n>>k;
    nhap();

//    debugmang();
//    cout<<endl;

//    cout<<"topo sort "<<endl;
    for (int i = 1; i <= n; i++) {
        if (!visited[i])
            dfs(i);
    }
//    cout<<endl;

    int parent[100000];
    topsort[n]=0;
    for (int i = n-1; i >=0; i--) {
        parent[topsort[i]]=topsort[i+1];
    }

    for (int i = 1; i <=n; i++) {
        cout<<parent[i]<<endl;
    }


    return 0;
}

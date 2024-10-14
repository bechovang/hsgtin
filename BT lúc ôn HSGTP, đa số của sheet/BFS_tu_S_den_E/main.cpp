#include <bits/stdc++.h>
#include <vector>
using namespace std;

vector<vector<int>> adj; // danh sách kề
vector<bool> visited;   // mảng vector đánh dấu đã thăm
vector<int> topsort;    // mảng lưu thứ tự bậc của đồ thị
vector<int> kq;
int s,e;
bool found=false;


///----------------------------------------------------
void dfs(int node)
{
    visited[node] = true;


    for (int i = 0; i < adj[node].size(); i++) // duyệt đỉnh kề
    {
        int child = adj[node][i];
        if (found==true) break;
        if (!visited[child]) // tránh duyệt lại các đỉnh đã duyệt
            dfs(child);
    }

    if (node==e or found==true){
        found=true;
        kq.push_back(node);
//        return 0;
    }

    topsort.push_back(node); // DAG // Other way Indegree / Outdegree
}

///----------------------------------------------------




int main()
{
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    int n, m; // Số đỉnh (n) và số cạnh (m)
    cin >> n >> m;
    cin>>s>>e;

    adj.resize(n+1);
    visited.resize(n+1, false);

    // Đọc các cạnh và xây dựng danh sách kề
    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }


    // vector<int> topsort; o tren
    dfs(s);


//    //debug
//    cout << "Thứ tự topological: ";
//    for (int i = 0; i < topsort.size(); i++)
//    {
//        cout << topsort[i] << " ";
//    }
//    cout << endl;
//
//    cout << "Thứ tự kq: ";
//    for (int i = 0; i < kq.size(); i++)
//    {
//        cout << kq[i] << " ";
//    }
//    cout << endl;

    // in kq
    reverse(kq.begin(),kq.end());
    for (int i = 0; i < kq.size(); i++)
    {
        cout << kq[i] << " ";
    }
    if (kq.empty()==true)
        cout<<"not found";

    return 0;
}

#include <bits/stdc++.h>
#define endl '\n'
#define faster ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
using namespace std;

int dinh, canh;
vector<vector<int>> v;
int vis[5005]={0};

void dfs(int x){
    if (vis[x]==true)
        return ;
    vis[x]=true;
    for (auto x: v[x]){
        dfs(x);
    }

    return ;
}

int main()
{
    faster;
    freopen("input.inp","r",stdin);
    freopen("output.out","w",stdout);
    cin>>dinh>>canh;
    v.resize(dinh+1);
    for (int i=0;i<canh;i++){
        int x,y; cin>>x>>y;
        v[x].push_back(y);
        v[y].push_back(x);
    }


    int kq=0;
    for (int i=1;i<=dinh;i++){
        if (vis[i]==false){
            kq++;
            dfs(i);
        }
    }


    cout<<kq;




    return 0;
}

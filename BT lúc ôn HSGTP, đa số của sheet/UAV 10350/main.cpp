#include <bits/stdc++.h>

using namespace std;
#define endl '\n'
#define faster ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

vector<vector<int>> v;
vector<int> toposort;
bool vis[1001];

void dfs(int node){
    vis[node]=true;

    for(int i=0;i<v[node].size();i++){
        int child=v[node][i];
        if (vis[child]==false)
            dfs(child);
    }

    toposort.push_back(node);
//    cout<<"topo: "<<node<<endl;
}

int main()
{
    faster;
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);



    int dinh, canh;
    while (cin>>dinh>>canh){
        //memset
        v.resize(1000);
        memset(vis,0,1001);
        v.clear();
        toposort.clear();

        for (int i=0;i<canh;i++){
            int x,y;
            cin>>x>>y;
            v[x].push_back(y);
        }


//        // debug mang
//        for (int i=1;i<=dinh;i++){
//            cout<<"dinh: "<<i<<endl;
//            for(int j=0;j<v[i].size();j++){
//                cout<<v[i][j]<<' ';
//            }
//            cout<<endl;
//        }

        for (int i=1;i<=dinh;i++){
            if (vis[i]==false)
                dfs(i);
        }

        for (int i=toposort.size()-1;i>=0;i--){
            cout<<toposort[i]<<' ';
        }
        cout<<endl;


    }





    return 0;
}

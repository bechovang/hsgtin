#include <bits/stdc++.h>
#define endl '\n'
#define faster ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
using namespace std;

int n, dinh, canh;
vector<vector<int>> v;
int par[35];
bool vis[35];
bool cycle;
bool co_dap_an=false;


void inkq(int x){
    vector <int> k;
    k.push_back(x);
    while (x!=0){
        x=par[x];
        k.push_back(x);
    }
    reverse(k.begin(),k.end());
    if (k.size()>2){
        co_dap_an=true;
        for (auto x: k)
            if (x!=0)
                cout<<x<<' ';
    }
    cout<<endl;
}

void dfs(int x){
    if (vis[x]==true)
        cycle=true;
    if (cycle==true)
        return ;
    if (v[x].empty()==true and cycle==false){
        inkq(x);
    }

    vis[x]=true;
    for (auto i: v[x]){
        par[i]=x;
        dfs(i);
    }

    return ;
}

int main()
{
    faster;
    freopen("input.inp","r",stdin);
    freopen("output.out","w",stdout);
    cin>>n;
    v.resize(n+1);
    for (int i=1;i<=n;i++){
        for (int j=1;j<=n;j++){
            int x; cin>>x;
            if (x==1)
                v[i].push_back(j);
        }
    }

    for (int i=1;i<=n;i++){
        memset(par,0,35);
        memset(vis,false,35);
        cycle=false;
        dfs(i);

    }


//    //debug
//    for (int i=1;i<=n;i++){
//        cout<<i<<endl;
//        for (auto x: v[i])
//            cout<<x<<' ';
//        cout<<endl;
//    }

    if (!co_dap_an)
        cout<<"khong co loi giai";

    return 0;
}



//4
//0	1  0  1
//1	0  0  1
//0   1  0  0
//1   0  1  0

//4
//0	1  0  0
//0	0  1  0
//0   0  0  1
//0   0  0  0


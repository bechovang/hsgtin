#include <bits/stdc++.h>
#define endl '\n'
#define faster ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

int parent[100005];
int sz[100005];

void make_set(int n){
    for (int i=1; i<=n; i++){ //**********************************
        parent[i]=i;
        sz[i]=1;
    }
}

int findd(int a){
    if (parent[a] == a){
        return a;
    }
    return parent[a] = findd(parent[a]);
}

void unionn(int a, int b){
    a=findd(a);  //**********************************
    b=findd(b);
    if (a!=b){ //**********************************
        if (sz[a] < sz[b]){
            parent[a] = b;
            sz[a] = sz[a] + sz[b];
        }
        else{
            parent[b] = a;
            sz[b] = sz[b] + sz[a];
        }
    }
}

int main()
{
    faster;
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    int n, m; cin >> n >> m;

    make_set(n);

    for (int i=0; i<m; i++){
        string s; cin>>s;
        int x,y; cin>>x>>y;
        if (s=="union"){
            unionn(x,y);
        }
        else{
            if (findd(x)==findd(y)){
                cout<<"YES"<<endl;
            }
            else{
                cout<<"NO"<<endl;
            }
        }
    }

    return 0;
}

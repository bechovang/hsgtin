#include <bits/stdc++.h>

using namespace std;
#define endl '\n'
#define faster ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

vector<int> dske[200];
int matranke[200][200];
int timer,start[200],finish[200],vis[200], visc[200][200];
int dem=0;
int dinhgoc;
void debugmang(){
    for (int i=1;i<=5;i++){
        cout<<"dinh "<<i<<": ";
        for (int j=0;j<dske[i].size();j++){
            cout<<dske[i][j]<<' ';
        }
        cout<<endl;
    }
}
bool dfs_cycle(int node, int dinhcha, int &demdinh){
    cout<<"debug dfs: "<<node<<' '<<dinhcha<<' '<<demdinh<<endl;
    if (vis[node]==1 and node!=dinhgoc){
        cout<<"cycle false "<<dem<<endl;
        demdinh--;
        return false;
    }
    if (vis[node]==1 and node==dinhgoc){
        cout<<"cycle true "<<dem<<endl;
        return true;
    }

    vis[node]=1;

    for (int i = 0; i < dske[node].size(); i++){
        int child=dske[node][i];
        if (child != dinhcha ){
             demdinh++;
             if (dfs_cycle(child,node,demdinh)==true){
                cout<<"cycle "<<dem<<endl;
                return true;
             }
        }
    }
    demdinh--;
    return false;
}

int main()
{
    faster;
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);

    // nhap
    int dinh,canh;
    cin>>dinh>>canh;
    for (int i=0;i<canh;i++){
        int x,y;
        cin>>x>>y;
        dske[x].push_back(y);
        dske[y].push_back(x);
    }

//    for(int i=1;i<=dinh;i++){
//        int dem=0;
//        cout<<"dsf dinh "<<i<<endl;
//        cout<<dfs_cycle(i,-1,dem)<<' ';
//        cout<<dem<<endl;
//    }

//    int kq=0;
//    for(int i=1;i<=dinh;i++){
//        int dem=0;
//        if (dfs_cycle(i,-1,dem)==true){
//            if (dem%2==1){
//                kq++;
//            }
//        }
//    }
//    if ((dinh-kq)%2==1){
//        kq++;
//    }
//    cout<<kq;
    debugmang();

    dem=0;
//    memset(vis,0,200);
    dinhgoc=1;
    cout<<"duyet dinh "<<dinhgoc<<' ';
    cout<<dfs_cycle(dinhgoc,-1,dem)<<' ';
    cout<<dem<<endl;

    dem=0;
//    memset(vis,0,200);
    dinhgoc=2;
    cout<<"duyet dinh "<<dinhgoc<<' ';
    cout<<dfs_cycle(dinhgoc,-1,dem)<<' ';
    cout<<dem<<endl;

    dem=0;
//    memset(vis,0,200);
    dinhgoc=3;
    cout<<"duyet dinh "<<dinhgoc<<' ';
    cout<<dfs_cycle(dinhgoc,-1,dem)<<' ';
    cout<<dem<<endl;

    dem=0;
//    memset(vis,0,200);
    dinhgoc=4;
    cout<<"duyet dinh "<<dinhgoc<<' ';
    cout<<dfs_cycle(dinhgoc,-1,dem)<<' ';
    cout<<dem<<endl;

    dem=0;
//    memset(vis,0,200);
    dinhgoc=5;
    cout<<"duyet dinh "<<dinhgoc<<' ';
    cout<<dfs_cycle(dinhgoc,-1,dem)<<' ';
    cout<<dem<<endl;

    return 0;
}
//timer++;
//finish[node]=timer;
//input:
//5 4
//1 2
//2 4
//5 3
//1 4
//output:
//1

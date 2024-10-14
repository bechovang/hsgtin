#include <bits/stdc++.h>
#define endl '\n'
#define faster ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

int n,m;
char s[1005][1005];
bool vis[1005][1005];


void dfs(int x, int y){
    if (s[x][y]=='#'
        or vis[x][y]==true
        or x<0
        or x>=n
        or y<0
        or y>=m)
        return ;

    vis[x][y]=true;

    dfs(x+1,y);
    dfs(x-1,y);
    dfs(x,y+1);
    dfs(x,y-1);

    return;
}


int main()
{
    faster;
//    freopen("INPUT.INP","r",stdin);
//    freopen("INPUT.OUT","w",stdout);
    cin>>n>>m;

    for (int i=0;i<n;i++)
        cin>>s[i];

    //memset vis
    for (int i=0;i<n;i++){
        for (int j=0;j<m;j++){
            vis[i][j]=false;
        }
    }

    int kq=0;
    for (int i=0;i<n;i++){
        for (int j=0;j<m;j++){
            if (s[i][j]=='.' and vis[i][j]==false){
                kq++;
                dfs(i,j);
            }
        }
    }



//    //debug
//    for (int i=0;i<n;i++){
//        for (int j=0;j<m;j++){
//            cout<<s[i][j]<<' ';
//        }
//        cout<<endl;
//    }
//    cout<<endl;


    cout<<kq;
    return 0;
}

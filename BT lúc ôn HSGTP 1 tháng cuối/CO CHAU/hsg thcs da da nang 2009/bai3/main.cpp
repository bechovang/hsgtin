#include <bits/stdc++.h>
#define endl '\n'
#define faster ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
using namespace std;

const int MAXN=250;

int a[MAXN][MAXN];
bool vis[MAXN][MAXN];

int n;

bool valid(int i, int j){

    if (i<0 or i>=n or j<0 or j>=n)
        return false;
    return true;

}

void flood_fill(int i, int j){
    if (valid(i,j)==false or vis[i][j]==true or a[i][j]==0)
        return;

    vis[i][j]=true;
    flood_fill(i+1,j);
    flood_fill(i-1,j);
    flood_fill(i,j+1);
    flood_fill(i,j-1);

    return;
}

int main()
{
    faster;
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);

    cin>>n;
    for (int i=0;i<n;i++){
        for (int j=0;j<n;j++){
            cin>>a[i][j];
        }
    }


    int dem=0;
    for (int i=0;i<n;i++){
        for (int j=0;j<n;j++){
            if (a[i][j]==1 and vis[i][j]==false){
                dem++;
                flood_fill(i,j);
            }
        }
    }



    cout<<dem;


    return 0;
}


//10
//Co tat ca 4 uoc so
//Tong cac uoc la 18

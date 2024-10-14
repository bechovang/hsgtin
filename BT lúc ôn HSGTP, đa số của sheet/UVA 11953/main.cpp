#include <bits/stdc++.h>

using namespace std;
#define endl '\n'
#define faster ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

int n,vis[200][200];
char a[200][200];
bool live;
void nhap(){
    string s;
    for (int i=0;i<n;i++){
        cin>>s;
        for (int j=0;j<n;j++){
            a[i][j]=s[j];
        }
    }
}
void debugmang(){
    for (int i=0;i<n;i++){
        for (int j=0;j<n;j++){
            cout<<a[i][j];
        }
        cout<<endl;
    }
}
bool valid(int i, int j){
    if (i>=0 and j>=0 and i<n and j<n)
        return true;
    else
        return false;
}
void dfs(int i,int j){
    if (!valid(i,j) or a[i][j]=='.' or vis[i][j]==1)
        return;

    vis[i][j]=1;

    if (a[i][j]=='x')
        live=true;

    //debug
    //cout<<i<<' '<<j<<' '<<a[i][j]<<' '<<live<<endl;

    dfs(i-1,j); // len
    dfs(i+1,j); // xuong
    dfs(i,j-1); // trai
    dfs(i,j+1); // phai

}
int demlienthong(){
    int dem=0;
    for (int i=0;i<n;i++){
        for (int j=0;j<n;j++){
            if ((a[i][j]=='x' or a[i][j]=='@') and vis[i][j]==0){
                live=false;
                dfs(i,j);
                if (live==true)
                    dem++;
                //debug
                //cout<<"dem: "<<dem<<endl;
            }
        }
    }
    return dem;
}
int main()
{
    faster;
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    int t;
    cin>>t;
    for (int k=1;k<=t;k++){

        for (int i=0;i<200;i++){
            for (int j=0;j<200;j++){
                a[i][j]='0';
            }
        }
        for (int i=0;i<200;i++){
            for (int j=0;j<200;j++){
                vis[i][j]=0;
            }
        }

        cin>>n;
        nhap();
        cout<<"Case "<<k<<": "<<demlienthong()<<endl;



    }
    return 0;
}
//Sample Input
//2
//4
//x...
//..x.
//@.@.
//....
//2
//..
//x.
//Sample Output
//Case 1: 2
//Case 2: 1

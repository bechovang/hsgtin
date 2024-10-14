#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
#define endl '\n'
#define faster ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
ll n;
char a[1000][1000];
int visited[1000][1000];
string s;
void nhap(){
    for (ll i=0;i<n;i++){
        cin>>s;
        for (ll j=0;j<n;j++){
            a[i][j]=s[j];
        }
    }
}
void debugmang(){
    for (ll i=0;i<n;i++){
        for (ll j=0;j<n;j++){
            cout<<a[i][j]<<' ';
        }
        cout<<endl;
    }
    cout<<endl;
}
bool valid(int i,int j){
    if (i>=0 and j>=0 and i<n and j<n)
        return true;
    else
        return false;
}
void dfs(int i, int j){
    if (valid(i,j)==false or a[i][j]=='0' or visited[i][j]==1)
        return;
    visited[i][j]=1;
    //debug
//    cout<<i<<' '<<j<<' '<<a[i][j] <<' '<< visited[i][j]<<endl;
    dfs(i-1,j); //len
    dfs(i+1,j); //xuong
    dfs(i,j-1); //trai
    dfs(i,j+1); //phai
    dfs(i-1,j+1); //len phai
    dfs(i-1,j-1); // len trai
    dfs(i+1,j+1); // xuong phai
    dfs(i+1,j-1); // xuong trai

}
int demlienthong(){
    int dem=0;
    for (ll i=0;i<n;i++){
        for (ll j=0;j<n;j++){
            if (visited[i][j]==0 and a[i][j]=='1'){
                dem++;
                //debug
//                cout<<"dem: "<<dem<<endl;
                dfs(i,j);
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
    ll o=0;
    while (cin>>n){
        o++;
        for (ll i=0;i<n;i++){
            for (ll j=0;j<n;j++){
                a[i][j]='0';
            }
        }
        for (ll i=0;i<n;i++){
            for (ll j=0;j<n;j++){
                visited[i][j]=0;
            }
        }

        nhap();
        //debugmang();
        cout<<"Image number "<<o<<" contains "<<demlienthong()<<" war eagles.";
        cout<<endl;
    }
    return 0;
}

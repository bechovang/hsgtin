#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
#define endl '\n'
#define faster ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
int n,m;
char a[100][100];
int vis[100][100];
int prei,prej;
void nhap(){
    string s;
    for (ll i=0;i<n;i++){
        cin>>s;
        for (ll j=0;j<m;j++){
            a[i][j]=s[j];
        }
    }
}
void debugmang(){
    for (ll i=0;i<n;i++){
        for (ll j=0;j<m;j++){
            cout<<a[i][j];
        }
        cout<<endl;
    }
    cout<<endl;
}
bool valid(int i, int j){
    if (i>=0 and j>=0 and i<n and j<m)
        return true;
    else
        return false;
}
bool kitu(int i, int j){
    if (a[i][j]=='I' or a[i][j]=='E' or a[i][j]=='H' or a[i][j]=='O' or a[i][j]=='V' or a[i][j]=='A' or a[i][j]=='#' or a[i][j]=='@')
        return true;
    else
        return false;
}
void dfs(int i, int j){
    if (valid(i,j)==false or kitu(i,j)==false or vis[i][j]==1)
        return;

    vis[i][j]=1;
//    cout<<a[i][j];
//    cout<<prei<<' '<<prej<<" --> "<<i<<' '<<j<<' ';
    if (a[i][j]!='@' and a[i][j]!='#'){
        if(prei==i+1 and prej==j)
            cout<<"forth ";
        if(prei==i and prej==j+1)
            cout<<"left ";
        if(prei==i and prej==j-1)
            cout<<"right ";
    }
    if (a[i][j]=='#'){
        if(prei==i+1 and prej==j)
            cout<<"forth";
        if(prei==i and prej==j+1)
            cout<<"left";
        if(prei==i and prej==j-1)
            cout<<"right";
    }
//    cout<<endl;
    prei=i;
    prej=j;

    dfs(i-1,j); //thang
    dfs(i,j-1); //trai
    dfs(i,j+1); //phai
}

int main()
{
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    ll t;
    cin>>t;
    while (t--){
        for (ll i=0;i<100;i++){
            for (ll j=0;j<100;j++){
                a[i][j]='0';
            }
        }
        for (ll i=0;i<100;i++){
            for (ll j=0;j<100;j++){
                vis[i][j]=0;
            }
        }

        cin>>n>>m;
        nhap();
//        debugmang();
        for (ll j=0;j<m;j++){
            if (a[n-1][j]=='@')
                dfs(n-1,j);
        }
        cout<<endl;

    }
    return 0;
}
//Sample Input:
//2
//6 5
//PST#T
//BTJAS
//TYCVM
//YEHOF
//XIBKU
//N@RJB
//5 4
//JA#X
//JVBN
//XOHD
//DQEM
//T@IY
//Sample Output:
//forth forth right right forth forth forth
//right forth forth left forth forth right

//kitu:
//IEHOVA

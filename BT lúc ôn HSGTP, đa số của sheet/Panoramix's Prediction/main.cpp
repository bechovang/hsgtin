#include <bits/stdc++.h>

using namespace std;
#define endl '\n'
#define faster ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
bool ktsnt(int x){
    for (int i=2;i<x;i++){
        if (x%i==0)
            return false;
    }
    return true;
}
int main()
{
    faster;
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    int n,m;
    cin>>n>>m;
    for (int i=n+1;i<=m;i++){
        if (ktsnt(i)==true and i!=m){
            cout<<"NO";
            return 0;
        }
        if (ktsnt(i)==true and i==m){
            cout<<"YES";
            return 0;
        }
    }
    cout<<"NO";
    return 0;
}

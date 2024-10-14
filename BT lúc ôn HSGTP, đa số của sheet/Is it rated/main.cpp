#include <bits/stdc++.h>

using namespace std;
#define endl '\n'
#define faster ios::sync_with_stdio(0); cin.tie(0); cout,tie(0);
int main()
{
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    int n,x,y;
    int prex=INT_MAX;
    int kq=3;
    cin>>n;
    for (int i=0;i<n;i++){
        cin>>x>>y;
        if (x>prex and x==y){
            kq=2;

        }
        if (x!=y){
            kq=1;
            break;
        }

        prex=x;

    }

    if (kq==1) cout<<"rated";
    if (kq==2) cout<<"unrated";
    if (kq==3) cout<<"maybe";
    return 0;
}

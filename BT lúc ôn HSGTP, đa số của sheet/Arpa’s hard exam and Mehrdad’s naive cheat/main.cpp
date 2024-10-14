#include <bits/stdc++.h>

using namespace std;
#define endl '\n'
#define faster ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
int main()
{
    faster;
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);

    long long n;
    cin >>n;
    if (n==0){
        cout<<1;
        return 0;
    }
    if (n%4==1) cout<<8;
    if (n%4==2) cout<<4;
    if (n%4==3) cout<<2;
    if (n%4==0) cout<<6;


    return 0;
}

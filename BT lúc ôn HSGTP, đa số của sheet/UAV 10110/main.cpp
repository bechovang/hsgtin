#include <bits/stdc++.h>
using namespace std;

#define faster ios_base::sync_with_stdio(false); cin.tie(NULL);
typedef long long ll;
#define endl '\n'
ll n,a[100000],x,y;

int main()
{
    faster;
//    freopen("input.txt", "r", stdin);
//    freopen("output.txt", "w", stdout);

    ll i=0;
    ll dem=2;
    while (1){
        cin >>n;
        if (n==0) return 0;
        if (floor((sqrt(n)))*floor((sqrt(n)))==n) cout<<"yes"<<endl;
        else cout<<"no"<<endl;
    }

    return 0;
}
//AC

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define faster() ios_base::sync_with_stdio(false); cin.tie(NULL);
void file(){
    freopen("socola.inp","r",stdin);
    freopen("socola.out","w",stdout);
}

int main()
{
    //file();
    faster();
    string a[105][105];
    ll n;
    for (ll i=0; i<n;i++){
        cin >> a[1][i];
        cin >> a[2][i];
    }

    for (ll i=0; i<n;i++){
        cout << a[1][i]<<' ';
        cout << a[2][i]<<' ';
        cout <<endl;
    }
    return 0;
}

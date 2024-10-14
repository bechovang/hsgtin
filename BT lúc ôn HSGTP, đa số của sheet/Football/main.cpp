#include <bits/stdc++.h>

using namespace std;

int main()
{
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    int n;
    int dems=1;
    int dema=0;
    string s,a,b;

    cin>>n;
    cin >>s;

    for (int i=0;i<n-1;i++){
        cin>>a;
        if (s==a) dems++;
        else {
            dema++;
            b=a;
        }
    }

    if (dema>dems) cout<<b;
    else cout<<s;

    return 0;
}

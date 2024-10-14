#include <bits/stdc++.h>

using namespace std;
#define endl '\n'
#define faster ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
int main()
{
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);

    int n,m;
    cin >>n>>m;
    string x;
    for (int i=0;i<n;i++){
        for (int j=0;j<m;j++){
            cin>>x;
            if (x=="C" or x=="M" or x=="Y"){
                cout<<"#Color";
                return 0;
            }
        }
    }

    cout<<"#Black&White";
    return 0;
}

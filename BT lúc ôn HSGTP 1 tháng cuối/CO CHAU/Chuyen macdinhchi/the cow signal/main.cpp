#include <bits/stdc++.h>
#define endl '\n'
#define faster ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
using namespace std;

int main()
{
    faster;
    freopen("input.inp","r",stdin);
    freopen("output.out","w",stdout);
    int n,m,k;
    cin>>n>>m>>k;
    char a[n][m];
    string s[n][m];

    for (int i=0;i<n;i++){
        cin>>a[i];
    }

    for (int i=0;i<n;i++){
        for (int j=0;j<m;j++){
            for (int z=0;z<k;z++)
                s[i][j]+=a[i][j];
        }
    }

    for (int i=0;i<n;i++){
        for (int z=0;z<k;z++){
            for (int j=0;j<m;j++){
                cout<<s[i][j];
            }
            cout<<endl;
        }
    }
    cout<<endl;



//    //debug
//    for (int i=0;i<n;i++){
//        for (int j=0;j<m;j++){
//            cout<<a[i][j];
//        }
//        cout<<endl;
//    }
//    cout<<endl;
//
//    for (int i=0;i<n;i++){
//        for (int j=0;j<m;j++){
//            cout<<s[i][j];
//        }
//        cout<<endl;
//    }
//    cout<<endl;



    return 0;
}

#include <bits/stdc++.h>

using namespace std;
#define endl '\n'
#define faster ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
int main()
{
    faster;
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);

    int n;
    cin>>n;

    char s[301];
    char chu1,chu2,prechu1,prechu2;

    cin>>s;
    chu1=s[0];
    chu2=s[1];
//    cout<<chu1<<' '<<chu2<<endl;
    if (chu1==chu2){
        cout<<"NO";
        return 0;
    }
    if (s[0]!=chu1 or s[n-1]!=chu1 ){
        cout<<"NO";
        return 0;
    }
    for (int i=1;i<n-1;i++){
        if (s[i]!=chu2){
            cout<<"NO";
            return 0;
        }
    }

    for (int i=1;i<n;i++){
        cin>>s;
//        cout<<s<<endl;
        if (s[i]!=chu1 or s[n-1-i]!=chu1 ){
            cout<<"NO";
            return 0;
        }
        for (int j=0;j<n;j++){
            if (s[j]!=chu2 and j!=i and j!=n-1-i){
                cout<<"NO";
                return 0;
            }
        }

    }
    cout << "YES";
    return 0;
}

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define endl '\n'
#define faster ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
int main()
{
    faster;
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    char ben,a[1000];
    char chu[]={'q','w','e','r','t','y','u','i','o','p','a','s','d','f','g','h','j','k','l',';','z','x','c','v','b','n','m',',','.','/'};
    cin>>ben;
    cin>>a;
    for (ll i=0;i<strlen(a);i++){
        for (ll j=0;j<strlen(chu);j++){
            if (a[i]==chu[j]){
                if (ben=='R'){
                    cout<<chu[j-1];
                    break;
                }
                else{
                    cout<<chu[j+1];
                    break;
                }
            }
        }
    }
//    cout<<strlen(a)<<' '<<strlen(chu);

    return 0;
}
//qwertyuiop
//asdfghjkl;
//zxcvbnm,./

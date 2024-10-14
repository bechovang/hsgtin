#include <bits/stdc++.h>

using namespace std;
#define endl '\n'
#define faster ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
int main()
{
    faster;
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    int n,k; cin>>n>>k;

    int kq=0;
    while (n--){
        char a[]={'0','1','2','3','4','5','6','7','8','9'};
        int dem[10]={0};
        char s[100];
        cin>>s;
        for (int i=0;i<strlen(s);i++){
            if (s[i]=='0') s[i]='a';
            else break;
        }
//        cout<<s<<endl;
        for (int i=0;i<strlen(s);i++){
            for (int j=0;j<=k;j++){
                if (s[i]==a[j]){
                    dem[s[i]-'0']++;
//                    cout<<s[i]<<endl;
                }
            }
        }

        //debug
//        for (int i=0;i<=k;i++){
//            cout<<dem[i]<<' ';
//        }
//        cout<<endl;

        bool valid=true;
        for (int i=0;i<=k;i++){
            if (dem[i]==0)
                valid=false;
        }

        if (valid==true) kq++;

    }
    cout<<kq;
    return 0;
}

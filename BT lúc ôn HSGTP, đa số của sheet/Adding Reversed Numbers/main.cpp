#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define faster ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

int main()
{
    faster;
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    int t; cin>>t;
    while (t--){
        string a,b;
        cin>>a>>b;


//        reverse(a.begin(),a.end());
//        reverse(b.begin(),b.end());
//        cout<<a<<' '<<b<<endl;
        if (a.size()<b.size())
            swap(a,b);


        char c[300];
        memset(c,'\0',300);
        int nho=0;
        for (int i=0;i<a.size();i++){
            char s1,s2;

            if (c[i]=='\0') c[i]='0';

            s1=a[i];
            if (i>=b.size()) s2='0';
            else s2=b[i];

            int k= (s1-'0') + (s2-'0') + nho;
            c[i]= (k%10)+'0';
            nho=k/10;

        }

        if (nho>0) c[a.size()]=nho+'0';

        for (int i=0;i<strlen(c);i++){
            if (c[i]!='0'){
                for (int j=i;j<strlen(c);j++){
                    cout<<c[j];
                }
                cout<<endl;
                break;
            }
        }
    }
    return 0;
}

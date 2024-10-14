#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
#define endl '\n'
#define faster ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

char a[1000],b[1000],c[1000];

int main()
{
    faster;
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);

    while (cin>>a>>b){
//        cin>>b;
//        cout<<a<<' '<<b<<endl;
        for (ll i=0;i<strlen(a)/2;i++){
            swap(a[i],a[strlen(a)-i-1]);
        }
        for (ll i=0;i<strlen(b)/2;i++){
            swap(b[i],b[strlen(b)-i-1]);
        }


//        cout<<a<<' '<<b<<endl;
        if (a[strlen(a)-1]=='0' or b[strlen(b)-1]=='0'){
            cout<<0<<endl;
            continue;
        }
//        strrev(a);
//        strrev(b);
        for (ll i=0;i<strlen(a);i++){
            ll nho=0;
            for (ll j=0;j<strlen(b);j++){
                if (c[i+j]=='\0') c[i+j]='0';
                ll x= (a[i]-'0') * (b[j]-'0') + (c[i+j]-'0') + nho;
                c[i+j]=x%10 +  '0';
                nho=x/10 ;

            }
            if (nho>0) c[i+strlen(b)]=nho+'0';
//            cout<<nho<<' '<< c<< endl;

        }

        for (ll i=0;i<strlen(c)/2;i++){
            swap(c[i],c[strlen(c)-i-1]);
        }
        cout<<c<<endl;
        memset(c,'\0',1000);
        memset(a,'\0',1000);
        memset(b,'\0',1000);


    }

    return 0;
}
// chuyen ve so: s[i]-'0'
//123*123=15129

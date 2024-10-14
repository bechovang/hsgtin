#include <bits/stdc++.h>

using namespace std;
#define endl '\n'
#define faster ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
int main()
{
    faster;
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    int t;
    cin>>t;
    while (t--){
        int n;
        cin>>n;
        vector <int> pf(n+1,0);
        vector <int> pf2(n+1,0);

        char s[n+1];
        cin>>s;
        for (int i=1;i<=n;i++){
            pf[i] = pf[i-1] + ( s[i-1] - '0' );
        }

        for (int i=0;i<=n;i++){
            pf2[i]=pf[i]-i;
        }

        map <int,int> hm;
        long long dem=0;
        for (int i=0;i<=n;i++){

            dem=dem+hm[pf2[i]];
            hm[pf2[i]]++;
        }
        cout<<dem<<endl;

        //debug
//        for (int i=0;i<=n;i++){
//            cout<< pf[i] <<' ';
//        }
//        cout<<endl;
//        for (int i=0;i<=n;i++){
//            cout<< pf2[i] <<' ';
//        }
//        cout<<endl;
//        cout<<endl;
    }
    return 0;
}
//[l, r) is a good subarray
//=> r - l = prefix[r] - prefix[l]
//=> prefix[r] - r = prefix[l] - l

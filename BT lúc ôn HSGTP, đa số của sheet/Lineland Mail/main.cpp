#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
#define endl '\n'
#define faster ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
ll n,a[100002];

int main()
{
    faster;
//    freopen("input.txt","r",stdin);
//    freopen("output.txt","w",stdout);

    cin>>n;
    for (ll i=0;i<n;i++){
        cin>>a[i];
    }

    for (ll i=0;i<n/2;i++){
        if (i==0) cout<<abs(a[0]-a[1]);
        else cout<<min(abs(a[i]-a[i-1]),abs(a[i]-a[i+1]));
        cout<<' ';
        cout<<max(abs(a[i]-a[n-1]),abs(a[i]-a[0]))<<endl;
    }
    if (n%2==1){
        cout<<min(abs(a[n/2]-a[n/2-1]),abs(a[n/2]-a[n/2+1]));
        cout<<' ';
        cout<<max(abs(a[n/2]-a[0]),abs(a[n/2]-a[n-1]))<<endl;

        for (ll i=n/2+1;i<n;i++){
            if (i==n-1) cout<<abs(a[n-1]-a[n-2]);
            else cout<<min(abs(a[i]-a[i-1]),abs(a[i]-a[i+1]));
            cout<<' ';
            cout<<max(abs(a[i]-a[n-1]),abs(a[i]-a[0]))<<endl;
        }
    }
    else{
        for (ll i=n/2;i<n;i++){
            if (i==n-1) cout<<abs(a[n-1]-a[n-2]);
            else cout<<min(abs(a[i]-a[i-1]),abs(a[i]-a[i+1]));
            cout<<' ';
            cout<<max(abs(a[i]-a[n-1]),abs(a[i]-a[0]))<<endl;
        }
    }


    return 0;
}

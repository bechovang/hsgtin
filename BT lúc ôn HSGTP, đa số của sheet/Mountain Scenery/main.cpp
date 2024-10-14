#include <bits/stdc++.h>

using namespace std;
#define endl '\n'
#define faster ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
int main()
{
    faster;
  //  freopen("input.txt","r",stdin);
   // freopen("output.txt","w",stdout);
    int n,k; cin>>n>>k;
    n=2*n +1;

    vector <int> a(n+1,0);
    for (int i=0;i<n;i++){
        cin>>a[i];
    }

    for (int i=1;i<n-1;i++){
        if (a[i-1]+1<a[i] and a[i+1]+1<a[i] and k>0){
            a[i]--;
            k--;
        }
    }

    for (int i=0;i<n;i++){
        cout<<a[i]<<' ';
    }
    return 0;
}

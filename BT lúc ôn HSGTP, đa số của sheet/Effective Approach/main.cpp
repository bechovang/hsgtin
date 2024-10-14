#include <bits/stdc++.h>

using namespace std;
#define endl '\n'
#define faster ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
typedef long long ll;
int main()
{
    faster;
    freopen("input.txt","r",stdin);
    freopen("otuput.txt","w",stdout);

    int n; cin>>n;
    //vector <int> a(100001);
    map <int,int> hm;
    int dem=0;
    for (int i=1;i<=n;i++){ //vị trí 1-n
        int x; cin>>x;
        hm[x]=i;  // lưu vị trí của của x trong mảng a[]
    }

    // nhập mảng truy vấn q[]
    int m; cin>>m;
    vector <int> q(100001);
    for (int i=1;i<=m;i++){
        cin>>q[i];
    }

    //1-n
    ll tg=0;
    for (int i=1;i<=m;i++){
        int k=q[i];
        tg=tg+hm[k];
    }
    cout<<tg<<' ';
    //n-1
    tg=0;
    for (int i=1;i<=m;i++){
        int k=q[i];
        tg=tg+n-hm[k]+1; // do vị trí nó đối xững nhau
    }
    cout<<tg;

    return 0;
}

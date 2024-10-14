#include <bits/stdc++.h>

using namespace std;
#define endl '\n'
#define faster ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define ll long long

int dx[8] = { 1, 0, -1, 0, -1, 1, -1, 1 }; // 8 huong
int dy[8] = { 0, 1, 0, -1, -1, 1, 1, -1 };
set<pair<ll,ll>>dso;
long long a1;
long long b1;
long long a2;
long long b2;

//bool valid(ll x, ll y){
//    for (auto k: dso){
//        if (k.first==x and k.second==y){
//            return true;
//        }
//    }
//    return false;
//}

int bfs(ll x,ll y,ll depth){
    queue <pair<pair<ll,ll>,ll>> q;
    q.push({{x,y},depth});

    while (q.empty()!=true){
        ll a=q.front().first.first; //x
        ll b=q.front().first.second;//y
        ll c=q.front().second;      //depth

        q.pop();




        for (int i=0;i<8;i++){
            ll Na=a+dx[i];
            ll Nb=b+dy[i];
            if (dso.count({Na,Nb})>0 and // kt bang for each khac count
                Na <=1e9 and Nb<=1e9 and Na >=1 and Nb>=-1){

                dso.erase({Na,Nb}); // de trong for

                if (Na==a2 and Nb==b2){
                    return c+1;
                }

                q.push({{Na,Nb},c+1});

            }
        }
    }

    return -1;
}

int main()
{
    faster;
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);

    cin>>a1>>b1>>a2>>b2;
    ll n; cin>>n;

    // có tối đa 10^5 cạnh
    // => đọc bằng danh sách ô
    // bằng set<pair<int, int> > pts; giống dscanh

    int t=n;
    while (t--){
        ll r,a,b;
        cin>>r>>a>>b;
        for (int i=a;i<=b;i++){
            dso.insert({r,i});
        }
    }

    //BFS
    cout<<bfs(a1,b1,0)<<endl;


//    //debug
//    for (auto x: dscanh){
//        cout<<x.first<<' '<<x.second<<endl;
//    }
    return 0;
}

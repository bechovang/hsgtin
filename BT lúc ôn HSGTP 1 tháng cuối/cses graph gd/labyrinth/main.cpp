#include <bits/stdc++.h>
#define endl '\n'
#define faster ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);


using namespace std;

struct edge{
    int pos_x;
    int pos_y;
    int depth;
};



int n,m;
char s[1005][1005];
bool vis[1005][1005];
int start_x, start_y;
int end_x, end_y;
pair <int,int> par[1005][1005]; //x-y, luu dinh cha cua i, dung de in ra doan duong

bool valid(int x, int y){
    if (vis[x][y]==true)
        return false;
    if (s[x][y]=='#')
        return false;
    if (x<0)
        return false;
    if (x>=n)
        return false;
    if (y<0)
        return false;
    if (y>=m)
        return false;

    return true;
}

int bfs(int x, int y, int do_sau){
    queue<edge> q;
    q.push({x,y,do_sau});
    edge cur;
    while (q.empty()!=true){
        cur = q.front();
        q.pop();
        vis[cur.pos_x][cur.pos_y]=true;

        if (s[cur.pos_x][cur.pos_y]=='B')
            break;

        //duyet qua 4 o ke
        if (valid(cur.pos_x +1, cur.pos_y)==true){
            q.push({cur.pos_x +1, cur.pos_y, cur.depth+1});
            par[cur.pos_x +1][cur.pos_y]={cur.pos_x, cur.pos_y}; // dinh hien tai la cha cua dinh ke
        }

        if (valid(cur.pos_x -1, cur.pos_y)==true){
            q.push({cur.pos_x -1, cur.pos_y, cur.depth+1});
            par[cur.pos_x -1][cur.pos_y]={cur.pos_x, cur.pos_y};
        }

        if (valid(cur.pos_x, cur.pos_y +1)==true){
            q.push({cur.pos_x, cur.pos_y +1, cur.depth+1});
            par[cur.pos_x][cur.pos_y +1]={cur.pos_x, cur.pos_y};
        }

        if (valid(cur.pos_x, cur.pos_y -1)==true){
            q.push({cur.pos_x, cur.pos_y -1, cur.depth+1});
            par[cur.pos_x][cur.pos_y-1]={cur.pos_x, cur.pos_y};
        }

    }

    if (s[cur.pos_x][cur.pos_y]=='B')
        return cur.depth;
    else
        return -1;
}

int main()
{
    faster;
    freopen("INPUT.INP","r",stdin);
    freopen("OUTPUT.OUT","w",stdout);
    cin>>n>>m;
    for (int i=0;i<n;i++){
        cin>>s[i];
    }


    for (int i=0;i<n;i++){
        for (int j=0;j<m;j++){
            if (s[i][j]=='A'){
                start_x=i;
                start_y=j;
            }
            if (s[i][j]=='B'){
                end_x=i;
                end_y=j;
            }
        }
    }



    int sau=bfs(start_x,start_y,0);
    if (sau==-1){
        cout<<"NO"<<endl;
    }
    else{
        cout<<"YES"<<endl;
        cout<<sau<<endl;

        int x=end_x;
        int y=end_y;
        vector <pair<int,int>> kq;
        while (x!=start_x or y!=start_y){
            kq.push_back({x,y});
            pair<int,int> k = par[x][y];
            x=k.first;
            y=k.second;
        }
        kq.push_back({start_x,start_y}); // while bi thieu


        reverse(kq.begin(), kq.end());

        for (int i=1;i<kq.size();i++){
            if (kq[i-1].first == kq[i].first +1 and kq[i-1].second == kq[i].second)
                cout<<'U';
            if (kq[i-1].first == kq[i].first -1 and kq[i-1].second == kq[i].second)
                cout<<'D';
            if (kq[i-1].first == kq[i].first and kq[i-1].second == kq[i].second +1)
                cout<<'L';
            if (kq[i-1].first == kq[i].first and kq[i-1].second == kq[i].second -1)
                cout<<'R';
        }
    }






    return 0;
}
//
//   0 1 2 3 4 5 6 7
//0 XXXXXXXX
//1 XOAXOOBX
//2 XOXXOXOX
//3 XOOOOOOX
//4 XXXXXXXX


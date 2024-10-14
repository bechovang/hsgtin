#include <bits/stdc++.h>

using namespace std;
#define endl '\n'
#define faster ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);

int knight_x[8]={-2,-1,+1,+2,+2,+1,-1,-2};
int knight_y[8]={+1,+2,+2,+1,-1,-2,-2,-1};


queue <pair<pair<int,int>,int>> q; //y - x - depth (nhưng code thì để x y depth)
int visit [10][10];
int cuoix,cuoiy;

void debugQueue(queue<pair<pair<int, int>, int>> q) {
    while (!q.empty()) {
        cout << "(" << q.front().first.first << ", " << q.front().first.second << "), " << q.front().second << " ";
        q.pop();
    }
    cout << endl;
}

bool valid(int x, int y){
    if (x>=1 and x<=8 and y>=1 and y<=8)
        return true;
    else
        return false;
}

int bfs(int x,int y, int depth){
    q.push({{x,y},depth});

    while (q.empty()!=true){
        int cur_x=q.front().first.first;
        int cur_y=q.front().first.second;
        int cur_depth=q.front().second;
        visit[cur_x][cur_y]==true;
        q.pop();

        if (cur_x==cuoix and cur_y==cuoiy){
            return cur_depth;
        }

        for (int i=0;i<8;i++){
            //đi qua nước tiếp
            int Nx=cur_x + knight_x[i];
            int Ny=cur_y + knight_y[i];
            //kt nước tiếp có hợp lệ ko
            if (valid(Nx,Ny) == true and visit[Nx][Ny]==false  ){
                q.push({{Nx,Ny},cur_depth+1});
            }
        }
    }
}

int main()
{
    faster;
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    string k1, k2;
    while(cin>>k1>>k2){
        int x1=k1[0]-'0'-48;
        int y1=k1[1]-'0';
        int x2=k2[0]-'0'-48;
        int y2=k2[1]-'0';

        cuoix=x2;
        cuoiy=y2;
        memset(visit,false,10*10);
        while (q.empty()!=true) q.pop(); // clear queue
        cout<<"To get from "<<k1<<" to "<<k2<<" takes "<<bfs(x1,y1,0)<<" knight moves."<<endl;

    }
    return 0;
}

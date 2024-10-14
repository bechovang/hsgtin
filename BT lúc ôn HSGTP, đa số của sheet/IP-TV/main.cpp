#include <bits/stdc++.h>
#define endl '\n'
#define faster ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
using namespace std;


int par[2005];
int sz[2005];

int m, n;

void make_set(){
    for (int i=0;i<2005;i++){
        par[i]=i;
        sz[i]=1;
    }
    return ;
}

int findd (int a){
    if (a == par[a]){
        return a;
    }
    return par[a]=findd(par[a]);
}
\
//kruskal => bool
bool unionn(int a, int b){
    a = findd(a);
    b = findd(b);
    if (a==b) return false; // kt chu trinh: co
    if (sz[a]<sz[b]) swap(a,b);
    par[b]=a;
    sz[a]+=sz[b];

    return true; // kt chu trinh: ko
}

struct edge{
    int u,v;
    int w;
};

bool cmp(edge a, edge b){
    return a.w < b.w;
}

vector <edge> canh;

int kruskal(){
    // mang mst rong
    vector <edge> mst;
    int d=0; // trong so cua cay
    //sort
    sort(canh.begin(), canh.end(), cmp);
    // lap
    for (int i=0;i<n;i++){
        if (mst.size() == m-1) break;
        edge e = canh[i];
        if (unionn(e.u, e.v)==true){ //***kho nhat****
            mst.push_back(e);
            d=d+e.w;
        }
    }


//    //debug
//    for (auto x: mst){
//        cout<<x.u<<' '<<x.v<<' '<<x.w<<endl;
//    }


    return d;
}

int main() {
    faster;
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
	int t; cin>>t;
	while (t--){
        cin>>m>>n;
        string a[2005], b[2005];
        set <string> myset;
        myset.clear();
        int w[2005];

		for (int i=0;i<n;i++){
			cin>>a[i]>>b[i]>>w[i];
			myset.insert(a[i]);
			myset.insert(b[i]);
		}

		map <string, int> mymap;
		mymap.clear();
		int dem=0;
		for (auto x: myset){

            dem++;
            mymap[x]=dem;

//            //debug
//            cout<<x<<' '<<mymap[x]<<endl;
		}

        canh.clear();
		for (int i=0;i<n;i++){
			edge e;
			e.u=mymap[a[i]];
			e.v=mymap[b[i]];
			e.w=w[i];
			canh.push_back(e);
		}

//        //debug
//        for (auto x: canh){
//            cout<<x.u<<' '<<x.v<<' '<<x.w<<endl;
//		}
//		cout<<endl;
//		sort(canh.begin(), canh.end(), cmp);
//		//debug
//        for (auto x: canh){
//            cout<<x.u<<' '<<x.v<<' '<<x.w<<endl;
//		}
//		cout<<endl;


		memset(par, 0, sizeof(par));
        memset(sz, 0, sizeof(sz));

		make_set();
		cout<<kruskal()<<endl;

		if (t!=0){
            cout<<endl;
		}


	}

	return 0;
}
// sai do khong lap tat canh ma di lap tat ca dinh

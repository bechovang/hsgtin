//bechovang
// idea: https://www.youtube.com/watch?v=on2hvxBXJH4


#include <bits/stdc++.h>

using namespace std;
#define endl '\n'
#define faster ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
int main()
{
    faster;
     freopen("input.txt","r",stdin);
     freopen("output.txt","w",stdout);

	int n; cin>>n;
	vector <int> a;
	for (int i=0;i<n;i++) {
        int x; cin>>x;
        a.push_back(x);
	}

	 vector<int> v;
	 v.push_back(a[0]);
	 for (int i=0;i<n;i++){
	 	if ( v[v.size()-1] < a[i]){
	 		v.push_back(a[i]);
	 	}
	 	else{
	 		int k = lower_bound(v.begin(), v.end(), a[i]) - v.begin();
	 		v[k] = a[i];
	 	}
	 }

	cout<<v.size()<<endl;

//	for (auto x: v){
//        cout<<x<<' ';
//	}
//    cout<<endl;


	//cout<<  lower_bound(a.begin(), a.end(), 4) - a.begin();
	// *** - a.begin(); Ở cuối để quy ra kiểu số nguyên, vì lower_bound nó cho kiểu iterator
    // *** dùng vector a để dễ kết hợp với beign(), end()
	return 0;

}

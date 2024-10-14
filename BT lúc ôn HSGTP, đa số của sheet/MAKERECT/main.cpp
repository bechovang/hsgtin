# include <bits/stdc++.h>
#include <iostream>

using namespace std;



int main () {
	long long n,k,lon,kq,prekq,x,y,c,d;
	long long *a=new long long[1000000];
	long long *b=new long long[10];

	lon=-1;
	kq=-1;
	prekq=-1;
	cin >> n;
	for (long long i=1;i<=n;i++){
		cin >>a[i];

	}
	sort(a+1,a+n+1,greater<long long>());

	k=1;
	x=-1;y=-1;c=-1;d=-1;
	for (long long i=1;i<=n;i++){
		//cout <<a[i]<<' '<<a[i+1]<<endl;
		if (a[i]==a[i+1] and x==-1){
			x=a[i];
			y=a[i+1];
			a[i]=-1;
			a[i+1]=-1;

		}
		if(x!=-1 and a[i]==a[i+1]){
			c=a[i];
			d=a[i+1];
			a[i]=-1;
			a[i+1]=-1;
		}
		if (c!=-1){
			break;
		}
	}

	// if (dem==2) cout<<k;
	// else cout<<0;

	// cout<<endl;
	// for (long long i=1;i<=n;i++){
	// 	cout << a[i]<<' ';
	// }
	// cout<<endl;

	// cout <<x<<' '<<y<<' '<<c<<' '<<d<<endl;

	if (x!=-1 and y!=-1 and c!=-1 and d!=-1) cout <<y*c<<endl;
	else cout<<0;

    return 0;
}

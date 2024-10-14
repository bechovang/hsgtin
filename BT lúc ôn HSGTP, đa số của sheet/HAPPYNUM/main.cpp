# include <bits/stdc++.h>
#include <iostream>

using namespace std;



int main () {
	long long n,k,lon;
	long long *a=new long long[10000000];
	long long *pfsum=new long long[10000000];
	lon=0;

	cin >>n>>k;
	for (long long i=0;i<n;i++){
		cin >>a[i];
	}

	for (long long i=1;i<=n;i++){
		pfsum[i]=pfsum[i-1]+a[i-1];
	}


	for (long long i=0;i<n;i++){
		lon=max(lon,pfsum[i+k]-pfsum[i]);
	}

	// for (long long i=0;i<n;i++){
	// 	cout <<pfsum[i]<<' ';
	// }
	// cout <<endl;
	// if (k==n) cout <<pfsum[n];
	// else
	cout <<lon;
    return 0;
}

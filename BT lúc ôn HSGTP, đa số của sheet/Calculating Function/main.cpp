#include <iostream>

using namespace std;

int main()
{

    long long n;
    cin>>n;
    if (n%2==1) cout<<'-'<<(n+1)/2;
    else cout<<n/2;
    return 0;
}

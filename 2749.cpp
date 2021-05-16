//https://www.acmicpc.net/problem/2749
#include <iostream>
using namespace std;
typedef long long ll;

ll a[1500003];

ll fibo(){
	a[0]=0;
	a[1]=1;
	for(int i=0;i<1500000;i++){
		a[i+2]=(a[i]+a[i+1])%1000000;
	}
}

int main(){
	ll n; cin>>n; fibo();
	cout<<a[n%1500000]<<"\n";

	return 0;
}

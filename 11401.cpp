//https://www.acmicpc.net/problem/11401
#include <iostream>
#include <set>
using namespace std;
typedef long long ll;
const int p = 1000000007;

int N, K;
ll inversion(){
	ll ret = 1LL;
	ll temp = 1LL;
	ll Want = p-2;
	for(int i=2; i<=K; i++){
		temp*=i;
		temp%=p;
	}
	while(Want){
		if(Want%2){
			ret*=temp;
			ret%=p;
		} 		
		temp*=temp;
		temp%=p;
		Want/=2;
	} 
	return ret%p;
}

ll combi(){
	ll ret = 1LL;
	for(int i=N; i>N-K; i--){
		ret*=i;
		ret%=p;
	}	
	return ret%p;
}
int main(){
    ios::sync_with_stdio(false); 
    cout.tie(NULL); 
    cin.tie(NULL);

    cin >> N >> K;
    ll a = inversion();
    ll b = combi();
    cout << (a*b)%p << "\n";

    return 0;
}
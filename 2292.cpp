#include <iostream>
using namespace std;
int main(){
    int n; cin>>n;
    int ans=1;
    int stn=2;
    while(n>=stn){
        stn+=6*ans++;
    }
    cout<<ans<<"\n";
    return 0;
}
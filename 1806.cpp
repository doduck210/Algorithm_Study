#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int N;
long long S;
int n[100000];
int ans=100001;

void input(){
    cin>>N>>S;
    for(int i=0;i<N;i++){
        cin>>n[i];
    }
}

void solution(){
    int l=0,r=0;
    long long sum=n[0];
    while(l<=r){
        if(sum<S){
            r++;
            if(r>=N) break;
            sum+=n[r];
        }
        else{
            //cout<<l<<" "<<r<<" "<<sum<<endl;
            ans=min(ans,r-l+1);
            sum-=n[l];
            l++;
        }
    }
    if(ans==100001) ans=0;
}

int main(){
    input();
    solution();
    cout<<ans<<"\n";
    return 0;
}
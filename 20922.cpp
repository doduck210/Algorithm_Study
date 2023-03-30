#include <iostream>
#include <algorithm>
using namespace std;

int N, K;
int arr[200001];
int cnt[100001];
int ans=0;

void input(){
    cin>>N>>K;
    for(int i=0;i<N;i++){
        cin>>arr[i];
    }
}

void solution(){
    int l=0, r=0;
    while(r<N){
        if(++cnt[arr[r]]>K){
            while(cnt[arr[r]]>K){
                cnt[arr[l++]]--;
            }
        }
        ans=max(ans,r-l+1);
        r++;
    }
}

int main(){
    input();
    solution();
    cout<<ans<<'\n';
    return 0;
}
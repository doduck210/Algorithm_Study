//for samsung software test
//13458
//https://www.acmicpc.net/problem/13458
#include <iostream>
using namespace std;

int N;
int B,C;

int main(){
    //input
    cin>>N;
    int A[1000001];
    for(int i=0;i<N;i++){
        cin>>A[i];
    }
    cin>>B>>C;
    
    long long ans=N;
    
    for(int i=0;i<N;i++){
        A[i]=A[i]-B;
        if(A[i]>0){
            ans+=A[i]/C;
            if(A[i]%C>0)
                ans++;
        }
    }
    
    cout<<ans<<endl;
    
    return 0;
}


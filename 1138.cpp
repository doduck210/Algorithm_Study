#include <iostream>
#include <vector>
using namespace std;
int main(){
    //input part
    int N; cin>>N;
    vector<int> n(N);
    for(int i=0;i<N;i++){
        cin>>n[i];
    }

    vector<int> ans(N,-1);
    for(int i=0;i<N;i++){
        int v=n[i];
        int cnt=0;
        int j=0;
        while(cnt<=v){
            if(ans[j]==-1) cnt++;
            j++;
        } j--;
        ans[j]=i+1;
    }

    for(int i=0;i<N;i++){
        cout<<ans[i]<<" ";
    } cout<<"\n";
    
    return 0;
}
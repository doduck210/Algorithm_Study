#include <iostream>
#include <vector>
#include <cstdlib>
using namespace std;

int N;
vector<int> n;
int mini=INT32_MAX;
int ans1, ans2;

void input(){
    cin>>N;
    for(int i=0;i<N;i++){
        int tmp; cin>>tmp;
        n.push_back(tmp);
    }
}

void solution(){
    int l=0, r=N-1;
    while(l<r){
        int local=n[l]+n[r];
        if(abs(local)<mini){
            mini=abs(local);
            ans1=n[l]; ans2=n[r];
            if(local==0) return;
        }
        if(local<0)l++;
        else r--;
    }
}

int main(){
    input();
    solution();
    cout<<ans1<<" "<<ans2<<"\n";
    return 0;
}
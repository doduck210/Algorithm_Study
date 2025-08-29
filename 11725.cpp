//https://www.acmicpc.net/problem/11725
#include <iostream>
#include <vector>
using namespace std;

int n;

vector<int> connectedNodes[100001];
int ans[100001]={0,};

void input(){
    cin>>n;
    for(int i=1;i<n;i++){
        int a, b; cin>>a>>b;
        connectedNodes[a].push_back(b);
        connectedNodes[b].push_back(a);
    }
}

void solve(int p){
    for(int i=0;i<connectedNodes[p].size();i++){
        int nextNode=connectedNodes[p][i];
        if(ans[nextNode]==0){
            ans[nextNode]=p;
            solve(nextNode);
        }
    }
}

void printAns(){
    for(int i=2;i<=n;i++){
        cout<<ans[i]<<'\n';
    }
}

int main(){
    input();

    solve(1);

    printAns();
    
    return 0;
}
#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;
int N,M;
vector<pair<int,int>> c[50000];
vector<int> mii;

void input(){
    cin>>N>>M;
    for(int i=0;i<M;i++){
        int from, to, val; cin>>from>>to>>val;
        from--; to--;
        c[from].push_back({to,val});
        c[to].push_back({from,val});
    }
    for(int i=0;i<N;i++){
        mii.push_back(INT32_MAX);
    }
}

int main(){
    input();
    queue<int> q;
    q.push(0); mii[0]=0;
    while(!q.empty()){
        int cur=q.front(); q.pop();
        if(cur==N-1) continue;
        for(int i=0;i<c[cur].size();i++){
            int to=c[cur][i].first;
            if(mii[to]>mii[cur]+c[cur][i].second){
                mii[to]=mii[cur]+c[cur][i].second;
                q.push(to);
            }
        }
    }
    cout<<mii[N-1]<<"\n";
    return 0;
}
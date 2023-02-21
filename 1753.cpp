#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
int V,E,K;
vector<pair<int,int>> e[20001];
int ans[20001];

void input(){
    cin>>V>>E>>K;
    for(int i=0;i<E;i++){
        int a,b,c; cin>>a>>b>>c;
        e[a].push_back({c,b});
    }
}

void bfs(){
    //initialize ans array
    for(int i=1;i<=V;i++){
        ans[i]=INT32_MAX;
    }
    //bfs start (maybe the name dijkstra is more properiate?)
    priority_queue<pair<int,int>> nodes; nodes.push({0,K}); ans[K]=0;
    while(!nodes.empty()){
        int cur=nodes.top().second, curV=-nodes.top().first; nodes.pop();
        if(ans[cur]<curV) continue;
        //get other nodes using every possible edge from the node
        for(int i=0;i<e[cur].size();i++){
            int nNode=e[cur][i].second, nAns=e[cur][i].first+ans[cur];
            //using the edge only this is efficient
            if(ans[nNode]>nAns){
                ans[nNode]=nAns;
                nodes.push({-nAns,nNode});
            }
        }
    }
}

int main(){
    input();
    bfs();
    for(int i=1;i<=V;i++){
        if(ans[i]==INT32_MAX) cout<<"INF\n";
        else cout<<ans[i]<<"\n";
    }
    return 0;
}
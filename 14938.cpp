#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int n,m,r;
int v[101];
vector<pair<int,int> > route[101];
int mi[101];
bool visited[101];

void input(){
    cin>>n>>m>>r;
    for(int i=1;i<=n;i++){
        cin>>v[i];
    }
    for(int i=0;i<r;i++){
        int a,b,c; cin>>a>>b>>c;
        route[a].push_back(make_pair(b,c)); route[b].push_back(make_pair(a,c));
    }
}

int bfs(int start){
    //initialize mi
    for(int i=1;i<=n;i++){
        mi[i]=INT32_MAX;
        visited[i]=false;
    }
    int cnt=v[start]; visited[start]=true;
    queue<int> nodes; nodes.push(start); mi[start]=0;
    while(!nodes.empty()){
        int node=nodes.front(); nodes.pop();
        for(int i=0;i<route[node].size();i++){
            int nxt=route[node][i].first; int val=mi[node]+route[node][i].second;
            if(val<=m&&mi[nxt]>val){
                mi[nxt]=val;
                if(!visited[nxt]) cnt+=v[nxt];
                visited[nxt]=true;
                nodes.push(nxt);
            }
        }
    }
    return cnt;
}

int main(){
    input();
    int ans=0;
    for(int i=1;i<=n;i++){
        ans=max(ans,bfs(i));
    }
    cout<<ans<<"\n";
    return 0;
}

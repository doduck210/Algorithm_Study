#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;
int N;
int v1,v2;
vector<pair<int, int>> e[801];
int eMin[801];

void input(){
    int E; cin>>N>>E;
    for(int i=0;i<E;i++){
        int f,t,v; cin>>f>>t>>v;
        e[f].push_back({t,v});
        e[t].push_back({f,v});
    }
    cin>>v1>>v2;
}

void eMinClear(){
    for(int i=1;i<=N;i++){
        eMin[i]=-1;
    }
}

int minDist(int a,int b){
    eMinClear();
    queue<int> q; q.push(a); eMin[a]=0;
    while(!q.empty()){
        int cur=q.front(); q.pop(); int dist=eMin[cur];
        for(int i=0;i<e[cur].size();i++){
            int to=e[cur][i].first, val=e[cur][i].second;
            if(eMin[to]<0||dist+val<eMin[to]){
                eMin[to]=dist+val;
                q.push(to);
            }
        }
    }
    return eMin[b];
}

int main(){
    input();
    int v1v2=minDist(v1,v2);
    int fv1=minDist(1,v1);
    int fv2=minDist(1,v2);
    int v1t=minDist(v1,N);
    int v2t=minDist(v2,N);
    int res1=fv1+v1v2+v2t; if(fv1==-1||v1v2==-1||v2t==-1) res1=INT32_MAX;
    int res2=fv2+v1v2+v1t; if(fv2==-1||v1v2==-1||v1t==-1) res2=INT32_MAX;
    if(res1==INT32_MAX&&res2==INT32_MAX) {cout<<-1<<"\n"; return 0;}
    cout<<min(res1,res2)<<"\n";
    return 0;
}
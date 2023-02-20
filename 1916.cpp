#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
int N;
vector<pair<int,int>> R[1001];
int cost[1001];
int A,B;

void input(){
    cin>>N;
    int M; cin>>M;
    for(int i=0;i<M;i++){
        int a,b,v; cin>>a>>b>>v;
        R[a].push_back({b,v});
    }
    cin>>A>>B;
    //initialize cost
    for(int i=1;i<=N;i++){
        cost[i]=INT32_MAX;
        sort(R[i].begin(),R[i].end());
    }
}

int djst(){
    priority_queue<int> city; city.push(A); cost[A]=0;
    while(!city.empty()){
        int c=city.top(); city.pop(); int co=cost[c];
        for(int i=0;i<R[c].size();i++){
            int nc=R[c][i].first, nco=R[c][i].second+co;
            if(cost[nc]>nco){
                cost[nc]=nco;
                city.push(nc);
            }
        }
    }
    return cost[B];
}

int main(){
    input();
    cout<<djst()<<"\n";
    return 0;
}
#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;

int N,M,X;  //num of Villages, num of routes, party village
int route[1001][1001]={0,};  //route costs
int toParty[1001]={0,};  //min costs to the party village
int fromParty[1001]={0,}; //min costs from the party village

void input(){
    cin>>N>>M>>X;
    for(int i=0;i<M;i++){
        int start, end, cost;
        cin>>start>>end>>cost;
        route[start][end]=cost;
    }
}

void getToPartyCosts(){
    queue<int> nodes;
    nodes.push(X);
    while(!nodes.empty()){
        int node=nodes.front();
        nodes.pop();
        int basicCost=toParty[node];
        for(int i=1;i<=N;i++){
            if( route[i][node] && i!=X && (basicCost+route[i][node]<toParty[i] || toParty[i]==0) ){
                toParty[i]=basicCost+route[i][node];
                nodes.push(i);
            }
        }
    }
}

void getFromPartyCosts(){
    queue<int> nodes;
    nodes.push(X);
    while(!nodes.empty()){
        int node=nodes.front();
        nodes.pop();
        int basicCost=fromParty[node];
        for(int i=1;i<=N;i++){
            if( route[node][i] && i!=X && (basicCost+route[node][i]<fromParty[i] || fromParty[i]==0) ){
                fromParty[i]=basicCost+route[node][i];
                nodes.push(i);
            }
        }
    }
}

int ans(){
    int ans=0;
    for(int i=1;i<=N;i++){
        ans=max(ans,toParty[i]+fromParty[i]);
    }
    return ans;
}

int main(){
    input();
    getToPartyCosts();
    getFromPartyCosts();
    cout<<ans()<<endl;
    return 0;
}
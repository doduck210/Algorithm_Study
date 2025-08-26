//https://www.acmicpc.net/problem/1167
#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;

int v;
vector<pair<int,int>> table[100001];
int farNode;

void input(){
    cin>>v;
    for(int i=1;i<=v;i++){
        int t; cin>>t;
        while(1){
            int a; cin>>a;
            if(a==-1) break;
            int b; cin>>b;
            table[t].push_back({a,b});
        }
    }
}

int bfs(int depart){
    vector<int> shortest(v+1,INT32_MAX); shortest[depart]=0; //각 노드까지 최솟값 담고있는 배열
    queue<int> q;
    queue<int> qVal;
    //시작노드에서 연결된 노드 모두 큐에 넣기
    for(int i=0;i<table[depart].size();i++){
        int node=table[depart][i].first, val=table[depart][i].second;
        shortest[node]=val;
        q.push(node); qVal.push(val);
    }
    //bfs시작
    while(!q.empty()){
        int node=q.front(), val=qVal.front();
        q.pop(); qVal.pop();
        if(shortest[node]<val) continue;

        for(int i=0;i<table[node].size();i++){
            int nextNode=table[node][i].first, nextVal=table[node][i].second;
            if(val+nextVal<shortest[nextNode]){
                shortest[nextNode]=val+nextVal;
                q.push(nextNode); qVal.push(val+nextVal);
            }
        }
    }
    //가장 긴 노드 찾기
    int longest=0;
    for(int i=1;i<shortest.size();i++){
        if(longest<shortest[i]){
            longest=shortest[i];
            farNode=i;
        }
    }
    return longest;
}

int main(){
    input();
    bfs(1);
    cout<<bfs(farNode)<<endl;

    return 0;
}
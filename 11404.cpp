//https://www.acmicpc.net/problem/11404
#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int n;
int m;
int table[101][101];

void input(){
    cin>>n;
    //테이블을 최대값으로 초기화 (자기자신은 0)
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            if(i==j) table[i][j]=0;
            else table[i][j]=INT32_MAX;
        }
    }
    cin>>m;
    for(int i=0;i<m;i++){
        int depart, arrive, cost;
        cin>>depart>>arrive>>cost;
        if(table[depart][arrive]>cost) table[depart][arrive]=cost;
    }
}

void printTable(){
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            if(table[i][j]==INT32_MAX) cout<<0<<' ';
            else cout<<table[i][j]<<' ';
        }
        cout<<'\n';
    }
}

//내일 여기를 채워야할듯
void bfs(int depart){
    queue<int> q;
    queue<int> qValue;
    for(int i=1;i<=n;i++){
        if(table[depart][i]<100001){
            if(depart==i) continue;
            q.push(i);
            qValue.push(table[depart][i]);
        }
    }
    while(!q.empty()){
        int node=q.front(); q.pop();
        int nodeValue=qValue.front(); qValue.pop();
        if(nodeValue>table[depart][node]) continue;
        for(int j=1;j<=n;j++){
            if(node==j) continue;
            if(table[node][j]==INT32_MAX) continue;
            int nextValue=nodeValue+table[node][j];
            if(nextValue<table[depart][j]){
                table[depart][j]=nextValue;
                q.push(j);
                qValue.push(nextValue);
            }
        }
    }

}

int main(){
    input();
    for(int i=1;i<=n;i++){
        bfs(i);
    }
    printTable();
    return 0;
}
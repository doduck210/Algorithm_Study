//https://www.acmicpc.net/problem/1260
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int n,v;
bool line[1001][1001]={false,};
bool visited[1001]={false,};

void input(){
    int l;
    cin>>n>>l>>v;
    for(int i=0;i<l;i++){
        int a,b;
        cin>>a>>b;
        line[a][b]=true;
        line[b][a]=true;
    }
}

void dfs(){
    vector<int> t;
    for(int i=n;i>0;i--){
        if(line[v][i]){
            t.push_back(i);
        }
    }
    cout<<v<<" ";
    visited[v]=true;
    while(t.size()){
        int tmpn=t.back(); t.pop_back();
        if(!visited[tmpn]){
            cout<<tmpn<<" ";
            visited[tmpn]=true;
            for(int i=n;i>0;i--){
                if(line[tmpn][i]&&!visited[i]){
                    t.push_back(i);
                }
            }
        }
    }
    cout<<"\n";
}

void bfs(){
    queue<int> t;
    for(int i=1;i<=n;i++){
        if(line[v][i]){
            t.push(i);
        }
    }
    cout<<v<<" ";
    visited[v]=true;
    while(t.size()){
        int tmpn=t.front(); t.pop();
        if(!visited[tmpn]){
            cout<<tmpn<<" ";
            visited[tmpn]=true;
            for(int i=1;i<=n;i++){
                if(line[tmpn][i]&&!visited[i]){
                    t.push(i);
                }
            }
        }
    }
    cout<<"\n";
}

void clearvisit(){
    for(int i=1;i<=n;i++){
        visited[i]=false;
    }
}

int main(){
    input();
    dfs();
    clearvisit();
    bfs();
    return 0;
}
//https://www.acmicpc.net/problem/1967
//out of memory at the first try. bfs twice is a solution.
#include <iostream>
#include <utility>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int n;

vector<pair<int,int>> table[10001];

int farNode, farLength;

void bfs(int startNode){
    //bfs로 startNode에서 가장 떨어진 곳의 노드번호, 길이 반환
    queue<pair<int,int>> q;
    farLength=0;
    bool visited[10001]={false,};
    visited[startNode]=true;

    for(int i=0;i<table[startNode].size();i++){
        q.push(table[startNode][i]);
    }

    while(!q.empty()){
        int curNode=q.front().first;
        int curWeight=q.front().second;
        q.pop();
        visited[curNode]=true;
        //Leaf 도착시엔 length처리
        if(table[curNode].size()==1){
            if(farLength<curWeight){
                farLength=curWeight;
                farNode=curNode;
            }
            continue;
        }
        //다른 연결된 곳 queue에 집어넣기
        for(int i=0;i<table[curNode].size();i++){
            if (visited[table[curNode][i].first]) continue;
            else{
                q.push({table[curNode][i].first,table[curNode][i].second+curWeight});
            }
        }
    }
}

int main(){
    cin>>n;
    //입력받고 가중치 저장
    for(int i=0;i<n-1;i++){
        int parent, child, weight;
        cin>>parent>>child>>weight;
        
        table[child].push_back({parent,weight});
        table[parent].push_back({child,weight});

    }

    //bfs 두번
    bfs(1);
    bfs(farNode);
    cout<<farLength<<endl;

    return 0;
}
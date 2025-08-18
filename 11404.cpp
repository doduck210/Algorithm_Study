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
            else table[i][j]=100001;
        }
    }
    cin>>m;
    for(int i=0;i<m;i++){
        int depart, arrive, cost;
        cin>>depart>>arrive>>cost;
        table[depart][arrive]=cost;
    }
}

void printTable(){
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            cout<<table[i][j]<<'\n';
        }
        cout<<'\n';
    }
}

//내일 여기를 채워야할듯
void bfs(){
    queue<int> q;
    for(int i=2;i<=n;i++){
        if(table[1][i]<100001){

        }
    }
}

int main(){
    input();
    return 0;
}
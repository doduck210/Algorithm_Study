#include <iostream>
#include <string>
#include <queue>
using namespace std;

int n, m;
bool table[1000][1000];
bool visited[1001][1001][2]; //1은 아직 부수기 전, 0은 부순 후

int dy[4]={-1,1,0,0}, dx[4]={0,0,-1,1};

void input(){
    cin>>n>>m;
    for(int i=0;i<n;i++){
        string tmp; cin>>tmp;
        for(int j=0;j<m;j++){
            table[i][j]=tmp[j]-'0';
            visited[i][j][0]=0; visited[i][j][1]=0;
        }
    }
}

void bfs(){
    queue<pair<int,int>> location;  //y,x값
    queue<pair<bool,int>> crashedValue; //부섰는지, 경로값
    
    location.push({0,0});
    crashedValue.push({1,1});

    while(!location.empty()){
        
    }
}

int main(){
    input();

    return 0;
}
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

//for debugging
void printVisited(){
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cout<<visited[i][j][0]<<' ';
        } cout<<endl;
    }
    cout<<endl;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cout<<visited[i][j][1]<<' ';
        } cout<<endl;
    }
}

int bfs(){
    queue<pair<int,int>> location;  //y,x값
    queue<pair<bool,int>> crashedValue; //부술기회있는지, 경로값
    
    location.push({0,0});
    crashedValue.push({1,1});

    while(!location.empty()){
        int cury=location.front().first, curx=location.front().second;
        bool curCrashed=crashedValue.front().first; int curValue=crashedValue.front().second;
        location.pop(); crashedValue.pop();
        if(visited[cury][curx][curCrashed]) continue;
        visited[cury][curx][curCrashed]=true;

        //종료조건
        if(cury==n-1&&curx==m-1) return curValue;

        for(int i=0;i<4;i++){
            int nexty=cury+dy[i], nextx=curx+dx[i];
            if(nexty>=0&&nexty<n&&nextx>=0&&nextx<m){//테이블 범위 안에 있는지
                //벽없으면 가보기
                if(!table[nexty][nextx]&&!visited[nexty][nextx][true]){
                    location.push({nexty,nextx});
                    crashedValue.push({curCrashed,curValue+1});
                }
                //벽인데 아직 부술수 있으면 부수고 가보기
                else if(table[nexty][nextx]&&curCrashed&&!visited[nexty][nextx][false]){
                    location.push({nexty,nextx});
                    crashedValue.push({0,curValue+1});
                }
            }
        }
    }

    return -1;
}

int main(){
    input();

    cout<<bfs()<<endl;

    return 0;
}
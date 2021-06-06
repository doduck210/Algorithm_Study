//https://www.acmicpc.net/problem/2178
#include <iostream>
#include <string>
#include <queue>
using namespace std;

int n,m;
string table[100];
int dist[100][100];

int dy[4]={1,-1,0,0};
int dx[4]={0,0,-1,1};

void input(){
    cin>>n>>m;
    for(int i=0;i<n;i++){
        cin>>table[i];
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            dist[i][j]=10001;
        }
    }
}

void bfs(){
    queue<int> qy,qx,d;
    dist[0][0]=0;
    if(table[0][1]=='1') {
        qy.push(0); qx.push(1); d.push(1);
    }
    if(table[1][0]=='1') {
        qy.push(1); qx.push(0); d.push(1);
    }
    while(qy.size()){
        int cury=qy.front(),curx=qx.front(),curd=d.front();
        //cout<<"cur: "<<cury<<" "<<curx<<"\n";
        qy.pop(); qx.pop(); d.pop();
        for(int i=0;i<4;i++){
            int nexty=cury+dy[i], nextx=curx+dx[i], nextd=curd+1;
            if(nexty>=0&&nextx>=0&&nexty<n&&nextx<m&&table[nexty][nextx]=='1'&&nextd<dist[nexty][nextx]){
                qy.push(nexty); qx.push(nextx); d.push(nextd);
                dist[nexty][nextx]=nextd;
            }
        }
    }
}

int main(){
    input();
    bfs();
    cout<<dist[n-1][m-1]+1<<"\n";

    return 0;
}
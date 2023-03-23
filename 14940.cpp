#include <iostream>
#include <queue>
using namespace std;

int n,m;
int table[1000][1000];
int ans[1000][1000];
queue<int> y,x;
int dy[4]={-1,1,0,0};
int dx[4]={0,0,-1,1};

void input(){
    cin>>n>>m;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>table[i][j];
            //initialize ans
            if(table[i][j]==1) ans[i][j]=-1;
            else ans[i][j]=0;
            //save starting point
            if(table[i][j]==2){
                y.push(i); x.push(j);
            }
        }
    }
}

void bfs(){
    while(!y.empty()){
        int cury=y.front(), curx=x.front();
        y.pop(); x.pop();
        for(int i=0;i<4;i++){
            int ny=cury+dy[i], nx=curx+dx[i];
            if(ny>=0&&ny<n&&nx>=0&&nx<m&&ans[ny][nx]!=0&&(ans[ny][nx]==-1||ans[cury][curx]+1<ans[ny][nx])){
                ans[ny][nx]=ans[cury][curx]+1;
                y.push(ny); x.push(nx);
            }
        }
    }
}

int main(){
    input();
    bfs();
    //print ans
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cout<<ans[i][j]<<' ';
        } cout<<'\n';
    }
    return 0;
}
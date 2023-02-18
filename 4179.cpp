#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;
int R,C;
char table[1000][1000];
int ans=-1;

queue<int> y,x,fcnt;
vector<int> fy,fx;
int dy[4]={-1,0,1,0};
int dx[4]={0,-1,0,1};

void input(){
    cin>>R>>C;
    for(int i=0;i<R;i++){
        for(int j=0;j<C;j++){
            cin>>table[i][j];
            if(table[i][j]=='J'){
                y.push(i); x.push(j);
                fcnt.push(1);
            }
            else if(table[i][j]=='F'){
                fy.push_back(i); fx.push_back(j);
            }
        }
    }
}

void bfs(){
    int fcprev=0;
    while(!y.empty()){
        int yy=y.front(), xx=x.front(), fCnt=fcnt.front();
        y.pop(); x.pop(); fcnt.pop();
        if(table[yy][xx]=='F') continue;
        //check edge
        if(yy==R-1||yy==0||xx==C-1||xx==0){
            ans=fCnt;
            return;
        }
        //Spread Fire
        if(fCnt!=fcprev){
            int size=fy.size();
            for(int i=0;i<size;i++){
                for(int j=0;j<4;j++){
                    int ny=fy[i]+dy[j], nx=fx[i]+dx[j];
                    if(ny<R&&ny>=0&&nx<C&&nx>=0&&(table[ny][nx]=='.'||table[ny][nx]=='J')){
                        table[ny][nx]='F';
                        fy.push_back(ny); fx.push_back(nx);
                    }
                }
            }
            for(int i=0;i<size;i++){
                fy.erase(fy.begin()); fx.erase(fx.begin());
            }
        }
        fcprev=fCnt;
        //Move
        for(int i=0;i<4;i++){
            int ny=yy+dy[i], nx=xx+dx[i];
            if(ny<R&&ny>=0&&nx<C&&nx>=0&&table[ny][nx]=='.'){
                table[ny][nx]='J';
                y.push(ny); x.push(nx); fcnt.push(fCnt+1);
            }
        }
    }
}

int main(){
    input();
    bfs();
    if(ans==-1) cout<<"IMPOSSIBLE\n";
    else cout<<ans<<"\n";
    return 0;
}
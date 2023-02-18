#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int R,C;
char table[1000][1000];
int ans=1000001;

int initY,initX;
vector<int> fY,fX;
int dy[4]={-1,0,1,0};
int dx[4]={0,-1,0,1};

void input(){
    cin>>R>>C;
    for(int i=0;i<R;i++){
        for(int j=0;j<C;j++){
            cin>>table[i][j];
            if(table[i][j]=='J'){
                initY=i; initX=j; table[i][j]='.';
            }
            else if(table[i][j]=='F'){
                fY.push_back(i); fX.push_back(j);
            }
        }
    }
}

void dfs(int y,int x,int cnt,vector<int> fy,vector<int> fx){
    //check edge
    if(y==0||x==0||y==R-1||x==C-1){
        ans=min(ans,cnt+1);
        return;
    }
    //spread fire
    vector<int> adY,adX;
    for(int j=0;j<fy.size();j++){
        for(int i=0;i<4;i++){
            int ny=fy[j]+dy[i], nx=fx[j]+dx[i];
            if(ny<R&&ny>=0&&nx<C&&nx>=0&&table[ny][nx]=='.'){
                table[ny][nx]='F';
                adY.push_back(ny); adX.push_back(nx);
            }
        }

    }
    //move
    for(int i=0;i<4;i++){
        int ny=y+dy[i], nx=x+dx[i];
        if(ny<R&&ny>=0&&nx<C&&nx>=0&&table[ny][nx]=='.'){
            /*cout<<ny<<" "<<nx<<endl;
            for(int a=0;a<R;a++){
                for(int b=0;b<C;b++){
                    cout<<table[a][b];
                } cout<<endl;
            }*/
            dfs(ny,nx,cnt+1,adY,adX);
        }
    }
    //extinguish fire
    for(int i=0;i<adY.size();i++){
        table[adY[i]][adX[i]]='.';
    }
    adY.clear();adX.clear();
}

int main(){
    input();
    dfs(initY,initX,0,fY,fX);
    if(ans==1000001) ans=-1;
    cout<<ans<<"\n";
    return 0;
}
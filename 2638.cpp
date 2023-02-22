#include <iostream>
#include <queue>
using namespace std;

int N,M;
int table[100][100]; //0:closed air 1:cheese 2:melting point 3:open air

int dy[4]={-1,0,1,0};
int dx[4]={0,-1,0,1};
queue<pair<int,int>> air;
bool isEnd=false;
int ans=0;

void input(){
    cin>>N>>M;
    for(int i=0;i<N;i++){
        for(int j=0;j<M;j++){
            cin>>table[i][j];
        }
    }
}

void setAir(){
    while(!air.empty()){
        int cury=air.front().first, curx=air.front().second; air.pop();
        for(int k=0;k<4;k++){
            int ny=cury+dy[k], nx=curx+dx[k];
            if(ny<N&&ny>=0&&nx<M&&nx>=0&&table[ny][nx]==0){
                table[ny][nx]=3;
                air.push({ny,nx});
            }
        }
    }
}

void setMelting(){
    isEnd=true;
    for(int i=0;i<N;i++){
        for(int j=0;j<M;j++){
            if(table[i][j]==1){
                int cnt=0;
                for(int k=0;k<4;k++){
                    int ny=i+dy[k], nx=j+dx[k];
                    if(ny<N&&ny>=0&&nx<M&&nx>=0&&table[ny][nx]==3){
                        cnt++;
                        if(cnt>=2) break;
                    }
                }
                if(cnt>=2){
                    table[i][j]=2;
                    isEnd=false;
                }
            }
        }
    }
}

void melt(){
    for(int i=0;i<N;i++){
        for(int j=0;j<M;j++){
            if(table[i][j]==2){
                table[i][j]=3;
                for(int k=0;k<4;k++){
                    int ny=i+dy[k], nx=j+dx[k];
                    if(ny<N&&ny>=0&&nx<M&&nx>=0&&table[ny][nx]==0){
                        table[ny][nx]=3;
                        air.push({ny,nx});
                        setAir();
                    }
                }
            }
        }
    }
}

int main(){
    input();
    //setInitialAir
    air.push({0,0}); setAir();
    while(1){
        melt();
        setMelting();
        if(isEnd) break;
        ans++;
    }
    cout<<ans<<"\n";
    return 0;
}
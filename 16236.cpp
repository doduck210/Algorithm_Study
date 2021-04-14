//https://www.acmicpc.net/problem/16236
#include <iostream>
using namespace std;

int N; int table[20][20];
int visited[20][20];
int sharky,sharkx,sizee=2,expp=0,ans=0;
int nexty, nextx, nextdi;

void input(){
    cin>>N;
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            int x;
            cin>>x;
            if(x==9){
                x=0;
                sharky=i; sharkx=j;
            }
            table[i][j]=x;
        }
    }
}

void initvisited(){
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            visited[i][j]=400;
        }
    }
}

bool cango(int y,int x){
    if(y<0||x<0||y>=N||x>=N){
        return false;
    }
    if(table[y][x]<=sizee){
        return true;
    }
    return false;
}

void findnext(int y,int x,int di){
    if(di>nextdi){
        return;
    }
    if(visited[y][x]<=di){
        return;
    }
    visited[y][x]=di;
    if(table[y][x]>0&&table[y][x]<sizee){//eatable;
        if(di==nextdi){
            if(y<nexty){ //upper
                nexty=y; nextx=x; return;
            }
            else if(y==nexty){
                if(x<nextx){
                    nexty=y; nextx=x; return;
                }
            }
            return;
        }
        nexty=y; nextx=x; nextdi=di;
        return;
    }
    if(cango(y+1,x)) findnext(y+1,x,di+1);
    if(cango(y-1,x)) findnext(y-1,x,di+1);
    if(cango(y,x+1)) findnext(y,x+1,di+1);
    if(cango(y,x-1)) findnext(y,x-1,di+1);
}

void solve(){
    for(;;){
        initvisited();
        nextdi=N*N;
        findnext(sharky,sharkx,0);
        if(nextdi==N*N){
            break;
        }
        ans+=nextdi;
        table[nexty][nextx]=0; expp++;
        if(sizee==expp){
            expp=0; sizee++;
        }
        sharky=nexty; sharkx=nextx;
    }
}

int main(){
    input();
    solve();
    cout<<ans<<"\n";
    return 0;
}
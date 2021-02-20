//https://www.acmicpc.net/problem/14503
#include <iostream>
#include <algorithm>
using namespace std;
int N,M;
int r,c,d;
int table[50][50];

int dy[4]={-1,0,1,0};
int dx[4]={0,1,0,-1};
int ans=0;

void input(){
    cin>>N>>M;
    N=max(N,3); N=min(N,50);
    M=max(M,3); M=min(M,50);
    cin>>r>>c>>d;
    for(int i=0;i<N;i++){
        for(int j=0;j<M;j++){
            cin>>table[i][j];
        }
    }
}

int rotate(int dir){
    if(dir-1<0)
        return 3;
    else
        return dir-1;
}

void move(int y, int x, int dir){
    if(table[y][x]==0){
        table[y][x]=2;
        ans+=1;
    }
    /*cout<<endl;
    for(int i=0;i<N;i++){
        for(int j=0;j<M;j++){
            cout<<table[i][j];
        } cout<<endl;
    } */

    int ndir=rotate(dir);
    for(int i=0;i<4;i++){
        if (table[y+dy[ndir]][x+dx[ndir]]==0){
            move(y+dy[ndir],x+dx[ndir],ndir);
            return;
        }
            ndir=rotate(ndir);
    }
    ndir=rotate(ndir);
    if(table[y+dy[ndir]][x+dx[ndir]]==1){
        return;
    }
    move(y+dy[ndir],x+dx[ndir],dir);
    
}

int main(){
    input();
    move(r,c,d);

    cout<<ans<<endl;

    return 0;
}
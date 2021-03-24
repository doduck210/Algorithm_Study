//https://www.acmicpc.net/problem/15683 
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int N,M;
int office[8][8];
vector<int> cctvI; vector<int> cctvJ;
int dy[4]={-1,0,1,0};
int dx[4]={0,1,0,-1};
int ans=64;

void input(){
    cin>>N>>M;
    for(int i=0;i<N;i++){
        for(int j=0;j<M;j++){
            cin>>office[i][j];
            if(office[i][j]>0&&office[i][j]<6){
                cctvI.push_back(i); cctvJ.push_back(j);
            }
        }
    }
}

void one(int o[][8],int y,int x,int dir){
    for(int i=0;;i++){
        if(y+(i*dy[dir])>=N||x+(i*dx[dir])>=M||y+(i*dy[dir])<0||x+(i*dx[dir])<0){
            break;
        }
        else if(o[y+(i*dy[dir])][x+(i*dx[dir])]==0){
            o[y+(i*dy[dir])][x+(i*dx[dir])]=7;
        }
        else if(o[y+(i*dy[dir])][x+(i*dx[dir])]==6){
            break;
        }
    }
}

void two(int o[][8],int y,int x,int dir){
    int dir2=(dir+2)%4;
    one(o,y,x,dir);
    one(o,y,x,dir2);
}

void three(int o[][8],int y,int x,int dir){
    int dir2=(dir+1)%4;
    one(o,y,x,dir);
    one(o,y,x,dir2);
}

void four(int o[][8],int y,int x,int dir){
    int dir2=(dir+1)%4;
    int dir3=(dir+2)%4;
    one(o,y,x,dir);
    one(o,y,x,dir2);
    one(o,y,x,dir3);
}

void five(int o[][8],int y,int x,int dir){
    one(o,y,x,0);
    one(o,y,x,1);
    one(o,y,x,2);
    one(o,y,x,3);
}

void supervise(int o[][8],int i,int dir){
    int j=i;
    int mode=office[cctvI[i]][cctvJ[j]];
    switch(mode){
        case 1:
            one(o,cctvI[i],cctvJ[j],dir);
            break;
        case 2:
            two(o,cctvI[i],cctvJ[j],dir);
            break;
        case 3:
            three(o,cctvI[i],cctvJ[j],dir);
            break;
        case 4:
            four(o,cctvI[i],cctvJ[j],dir);
            break;
        case 5:
            five(o,cctvI[i],cctvJ[j],dir);
            break;
    }
}

void score(int o[][8]){
    int temp=0;
    for(int i=0;i<N;i++){
        for(int j=0;j<M;j++){
            if(o[i][j]==0){
                temp++;
            }
        }
    }
    ans=min(ans,temp);
}


void dfs(int o[][8],int cnt){
    if(cnt>=cctvI.size()){
        score(o);
        return;
    }
    int temp1[8][8], temp2[8][8], temp3[8][8], temp4[8][8];
    for(int i=0;i<N;i++){
        for(int j=0;j<M;j++){
            temp1[i][j]=o[i][j];
            temp2[i][j]=o[i][j];
            temp3[i][j]=o[i][j];
            temp4[i][j]=o[i][j];
        }
    }
    supervise(temp1,cnt,0);
    dfs(temp1,cnt+1);
    supervise(temp2,cnt,1);
    dfs(temp2,cnt+1);
    supervise(temp3,cnt,2);
    dfs(temp3,cnt+1);
    supervise(temp4,cnt,3);
    dfs(temp4,cnt+1);
}

int main(){
    input();

    dfs(office,0);

    cout<<ans<<"\n";

    return 0;
}
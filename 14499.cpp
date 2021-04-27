//for samsung software test
//BOJ 14499 Rolling Dice 
//https://www.acmicpc.net/problem/14499

#include <iostream>
#include <algorithm>
using namespace std;

int N,M;
int x,y;
int K;  //number of orders
int map[20][20]={0,};
int order[1000];

class dice{
public:
    int up=0, south=0, north=0, east=0, west=0, bottom=0;
    void goSouth(){
        int temp=up;
        up=north; north=bottom; bottom=south; south=temp;
    }
    void goNorth(){
        int temp=up;
        up=south; south=bottom; bottom=north; north=temp;
    }
    void goEast(){
        int temp=up;
        up=west; west=bottom; bottom=east; east=temp;
    }
    void goWest(){
        int temp=up;
        up=east; east=bottom; bottom=west; west=temp;
    }
};

int main(){
    //input and valid test
    cin>>N>>M>>x>>y>>K;
    N=max(1,N);     N=min(20,N);    M=max(1,M);     M=min(20,M);
    x=max(0,x);     x=min(x,N-1);    y=max(0,y);     y=min(y,M-1);      K=max(1,K);     K=min(1000,K);
    
    for(int i=0;i<N;i++){
        for(int j=0;j<M;j++){
            cin>>map[i][j];
            map[i][j]=min(10,map[i][j]); map[i][j]=max(0,map[i][j]);
        }
    }   map[x][y]=0;
    
    for(int i=0;i<K;i++){
        cin>>order[i];      //1:e 2:w 3:n 4:s
    }
    dice D;
    
    //simulation
    bool moved=false;
    for(int i=0;i<K;i++){
        if(order[i]==2 && y-1>=0){
            y-=1;   D.goWest();
            moved=true;
        }
        else if(order[i]==1 && y+1<M){
            y+=1;   D.goEast();
            moved=true;
        }
        else if(order[i]==3 && x-1>=0){
            x-=1;   D.goNorth();
            moved=true;
        }
        else if(order[i]==4 && x+1<N){
            x+=1;   D.goSouth();
            moved=true;
        }
        
        if(moved){
            cout<<D.up<<endl;
            if(map[x][y]==0){
                map[x][y]=D.bottom;
            }
            else if(map[x][y]!=0){
                D.bottom=map[x][y];
                map[x][y]=0;
            }
            moved=false;
        }
    }
    
    return 0;
}

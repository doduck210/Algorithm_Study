//https://www.acmicpc.net/problem/17143
#include <iostream>
#include <vector>
using namespace std;
int r,c,m;
vector<int> table[100][100];  //0:speed, 1:dir, 2:size
int dy[5]={0,-1,1,0,0}; int dx[5]={0,0,0,1,-1};
int ans=0;

void input(){
    cin>>r>>c>>m;
    for(int i=0;i<m;i++){
        int r_,c_,s_,d_,z_;
        cin>>r_>>c_>>s_>>d_>>z_;
        table[r_-1][c_-1].push_back(s_);
        table[r_-1][c_-1].push_back(d_);
        table[r_-1][c_-1].push_back(z_);
    }
}

void catchFish(int j){
    for(int i=0;i<r;i++){
        if(table[i][j].size()>0){
            ans+=table[i][j][2];
            table[i][j].clear();
            return;
        }
    }
}

void move(){
    vector<int> temp[100][100];
    for(int i=0;i<r;i++){
        for(int j=0;j<c;j++){
            if(table[i][j].size()>0){
                int nexti=i+dy[table[i][j][1]]*table[i][j][0];
                while(nexti>=r||nexti<0){
                    if(nexti>=r) nexti=r+r-2-nexti;
                    else nexti=nexti*-1;
                    int di=table[i][j][1];
                    if(di==1) table[i][j][1]=2;
                    else    table[i][j][1]=1;
                }
                int nextj=j+dx[table[i][j][1]]*table[i][j][0];
                while(nextj>=c||nextj<0){
                    if(nextj>=c) nextj=c+c-2-nextj;
                    else nextj=nextj*-1;
                    int di=table[i][j][1];
                    if(di==3) table[i][j][1]=4;
                    else table[i][j][1]=3;
                }
                if(temp[nexti][nextj].size()>0){
                    if(temp[nexti][nextj][2]<table[i][j][2]){
                        temp[nexti][nextj].assign(table[i][j].begin(),table[i][j].end());
                    }
                }
                else{
                    temp[nexti][nextj].assign(table[i][j].begin(),table[i][j].end());
                }
            }
        }
    }
    for(int i=0;i<r;i++){
        for(int j=0;j<c;j++){
            table[i][j].assign(temp[i][j].begin(),temp[i][j].end());
        }
    }
}

int main(){
    input();

    for(int j=0;j<c;j++){
        catchFish(j);
        move();
        /*
        cout<<"\n";
        for(int a=0;a<r;a++){
            for(int b=0;b<c;b++){
                cout<<table[a][b].size()<<" ";
            }   cout<<"\n";
        } cout<<"\n";
        */
    }

    cout<<ans<<"\n";

    return 0;
}
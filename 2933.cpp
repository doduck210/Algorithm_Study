//https://www.acmicpc.net/problem/2933
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int R,C,N;
char cave[100][100];
int stick[100];
bool visited[100][100]={false,};
vector<int> xx,yy;

void input(){
    cin>>R>>C;
    for(int i=0;i<R;i++){
        for(int j=0;j<C;j++){
            cin>>cave[i][j];
        }
    }
    cin>>N;
    for(int i=0;i<N;i++){
        cin>>stick[i];
    }
}

void left(int st){
    int height=R-st;
    for(int j=0;j<C;j++){
        if(cave[height][j]=='x'){
            cave[height][j]='.';
            return;
        }
    }
}
void right(int st){
    int height=R-st;
    for(int j=C-1;j>=0;j--){
        if(cave[height][j]=='x'){
            cave[height][j]='.';
            return;
        }
    }
}

void visitclear(){
    for(int i=0;i<R;i++){
        for(int j=0;j<C;j++){
            visited[i][j]=false;
        }
    }
}

void bfs(int y,int x){
    if(visited[y][x]) return;
    visited[y][x]=true;
    if(y>0 && cave[y-1][x]=='x' && !visited[y-1][x]){
        bfs(y-1,x);
    }
    if(x>0 && cave[y][x-1]=='x' && !visited[y][x-1]){
        bfs(y,x-1);
    }
    if(y<R-1 && cave[y+1][x]=='x' && !visited[y+1][x]){
        bfs(y+1,x);
    }
    if(x<C-1 && cave[y][x+1]=='x' && !visited[y][x+1]){
        bfs(y,x+1);
    }
}

void fall(int d){
    for(int i=yy.size()-1;i>=0;i--){
        cave[yy[i]][xx[i]]='.';
        cave[yy[i]+d][xx[i]]='x';
    }
}

void thro(){
    for(int a=0;a<N;a++){
        //throwing stick!
        if(a%2==0) left(stick[a]);
        else right(stick[a]);

        //check something is in air
        bool stable=true;
        while(stable){
        visitclear(); yy.clear(); xx.clear();
        stable=false; int di=101;
        for(int j=0;j<C;j++){
            if(cave[R-1][j]=='x') bfs(R-1,j);
        }
        for(int i=0;i<R;i++){
            for(int j=0;j<C;j++){
                if(cave[i][j]=='x' && !visited[i][j]){
                    stable=true; yy.push_back(i); xx.push_back(j);
                    if(cave[i+1][j]=='.'){ //under is blank
                        int d;
                        for(d=1;i+d<R;d++){
                            if(cave[i+d][j]=='x' && visited[i+d][j]){
                                break;
                            }
                        }
                        di=min(di,d-1);
                    }
                }
            }
        }
        if(stable){
            fall(di);
        }
        }
    }
}

int main(){
    input();
    thro();

    //cout<<"\n";
    for(int i=0;i<R;i++){
        for(int j=0;j<C;j++){
            cout<<cave[i][j];
        } cout<<"\n";
    }

    return 0;
}
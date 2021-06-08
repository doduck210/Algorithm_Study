//https://www.acmicpc.net/problem/2468
#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;

int n;
int table[100][100];
int group[100][100];

int dy[4]={-1,1,0,0};
int dx[4]={0,0,-1,1};

void input(){
    cin>>n;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin>>table[i][j];
        }
    }
}

void clearg(){
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            group[i][j]=0;
        }
    }
}

int grouping(int h){
    clearg();
    int g=0;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            queue<int> ii,jj;
            if(table[i][j]>h&&group[i][j]==0){
                ii.push(i); jj.push(j);
                group[i][j]=++g;
                while(ii.size()){
                    int curi=ii.front(), curj=jj.front();
                    ii.pop(); jj.pop();
                    for(int k=0;k<4;k++){
                        int nexti=curi+dy[k], nextj=curj+dx[k];
                        if(nexti>=0&&nexti<n&&nextj>=0&&nextj<n&&table[nexti][nextj]>h&&group[nexti][nextj]==0){
                            ii.push(nexti); jj.push(nextj);
                            group[nexti][nextj]=g;
                        }
                    }
                }
            }
        }
    }
    return g;
}

int main(){
    input();
    int ans=0;
    for(int i=0;i<100;i++){
        ans=max(ans,grouping(i));
    }
    cout<<ans<<"\n";
    return 0;
}
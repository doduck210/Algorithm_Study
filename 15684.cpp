//https://www.acmicpc.net/problem/15684 
#include <iostream>
#include <algorithm>
using namespace std;
int H; int N; int M;
int ladder[30][10]={0};  //0:nothing, 1:default_ladder 1>:user ladder
int ans=4;

void input(){
    cin>>N>>M>>H;
    for(int i=0;i<M;i++){
        int temp1, temp2;
        cin>>temp1>>temp2;
        ladder[temp1-1][temp2-1]=1;
    }
}

bool simul(){
    for(int i=0;i<N;i++){
        int a=i;
        for(int j=0;j<H;j++){
            if(a<N-1){
                if(ladder[j][a]>0){
                    a++;
                    continue;
                }
            }
            if(a>0){
                if(ladder[j][a-1]>0){
                    a--;
                }
            }
        }
        if(a!=i){
            return false;
        }
    }
    return true;
}

void dfs(int cnt,int x, int y){
    if(cnt>=ans){
        return;
    }
    if(simul()){
        ans=min(ans,cnt);
        return;
    }
    for(int i=y;i<H;i++){
        for(int j=x;j<N-1;j++){
            x=0;
            if(ladder[i][j]==0){
                if(ladder[i][j+1]>0){
                    continue;
                }
                if(j>0){
                    if(ladder[i][j-1]>0){
                        continue;
                    }
                }
                ladder[i][j]=cnt+2;
                dfs(cnt+1,j,i);
                ladder[i][j]=0;
            }
        }
    }
}

int main(){
    input();

    dfs(0,0,0);

    if(ans>3)
        ans=-1;
    
    cout<<ans<<"\n";

    return 0;
}
#include <iostream>
using namespace std;

int R,C;
char table[20][20];

int dy[4]={-1,0,1,0};
int dx[4]={0,1,0,-1};
bool alpha[100]={0,};
int ans=0;

void input(){
    cin>>R>>C;
    for(int i=0;i<R;i++){
        for(int j=0;j<C;j++){
            cin>>table[i][j];
        }
    }
}

void search(int y,int x,int cnt){
    if(ans<cnt) ans=cnt;
    for(int i=0;i<4;i++){
        int ny=y+dy[i], nx=x+dx[i];
        if(ny<R&&ny>=0&&nx<C&&nx>=0&&!alpha[table[ny][nx]]){
            alpha[table[ny][nx]]=true;
            search(ny,nx,cnt+1);
            alpha[table[ny][nx]]=false;
        }
    }
}

int main(){
    input();
    alpha[table[0][0]]=true;
    search(0,0,1);
    cout<<ans<<"\n";
    return 0;
}
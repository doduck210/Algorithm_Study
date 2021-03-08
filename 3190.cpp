//https://www.acmicpc.net/problem/3190
#include<iostream>
#include<climits>
#include<queue>
#include<list>
using namespace std;

class loca{
public:
    loca(int _x,int _y){
        x=_x;
        y=_y;
    }
    int x;
    int y;
};

int N, K, L;
int board[100][100]={0};
queue<int> timing;
queue<char> direction;
list<loca> snake;

int xdir[4]={-1,0,1,0};  // up - right - down - left (clockwise)
int ydir[4]={0,1,0,-1};

void input(){
    cin>>N>>K;
    for(int i=0; i<K; i++){
        int x,y;
        cin>>x>>y;
        board[x-1][y-1]=1;  //apple is 1
    }
    cin>>L;
    for(int i=0;i<L;i++){
        int x;
        char c;
        cin>>x>>c;
        timing.push(x);
        direction.push(c);
    }
    loca start(0,0);
    snake.push_front(start);
    board[0][0]=2;      //snake itself is 2
}

bool moving(int dir){
    int xhead=snake.front().x + xdir[dir];
    int yhead=snake.front().y + ydir[dir];
    if(xhead<0 || xhead ==N || yhead<0 || yhead==N){ //outside of board
        return false;
    }
    else if(board[xhead][yhead]==2){                //meet snake
        return false;
    }
    else{
        loca head(xhead,yhead);
        if(board[xhead][yhead]==0){
            board[snake.back().x][snake.back().y]=0;
            snake.pop_back();
        }
        snake.push_front(head);
        board[xhead][yhead]=2;
        
        return true;
    }
}

int simulation(){
    int dir=1;

    for(int i=0;;i++){
        if(!timing.empty()){
            if(i==timing.front()){
                if(direction.front()=='D'){
                    dir+=1;
                    if(dir==4)
                        dir=0;
                }
                else{
                    dir-=1;
                    if(dir==-1)
                        dir=3;
                }
                timing.pop();
                direction.pop();
            }
        }
        if(!moving(dir)){
            return i+1;
        }
        /*
        for(int a=0;a<N;a++){
            for(int b=0;b<N;b++){
                cout<<board[a][b]<<" ";
            }
            cout<<endl;
        }
        cout<<endl;
        */
    }
}

int main(){
    input();
    
    cout<<simulation()<<endl;
    
    return 0;
}




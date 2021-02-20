//https://www.acmicpc.net/problem/14502
#include <iostream>
#include <algorithm>
#include <vector>
#include <utility>
using namespace std;

int N, M;
int table[8][8];
int copyTable[8][8];
vector<pair<int, int>> vir;
int ans=0;

int dy[4] = {-1, 1, 0, 0}; //up down left right
int dx[4] = {0, 0, -1, 1};

void propagation(int a,int b){
    for(int i=0;i<4;i++){
        int ny=a+dy[i];
        int nx=b+dx[i];
        if(ny>=0 && ny<N && nx>=0 && nx<M){
            if(copyTable[ny][nx]==0){
                copyTable[ny][nx]=2;
                propagation(ny,nx);
            }
        }
    }
}

int safeCount(){
    int count=0;
    for(int i=0;i<N;i++){
        for(int j=0;j<M;j++){
            if (copyTable[i][j]==0){
                count++;
            }
        }
    }
    return count;
}

void makeWall(int cnt){
    if(cnt>2){
        for(int i=0;i<N;i++){
            for(int j=0;j<M;j++){
                copyTable[i][j]=table[i][j];
            }
        }
        for (int i = 0; i < vir.size(); i++){
            propagation(vir[i].first,vir[i].second);
        }
        ans=max(safeCount(),ans);
        return;
    }

    for(int i=0;i<N;i++){
        for(int j=0;j<M;j++){
            if(table[i][j]==0){
                table[i][j]=1;
                makeWall(cnt+1);
                table[i][j]=0;
            }
        }
    }
}

int main()
{
    //input and validation
    cin >> N >> M;
    N = max(3, N);
    N = min(8, N);
    M = max(3, M);
    M = min(8, M);
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            cin >> table[i][j];
            //copyTable[i][j] = table[i][j];
            if (table[i][j] == 2)
            { //save 2's location
                vir.push_back(make_pair(i, j));
            }
        }
    }

    makeWall(0);

    cout<<ans<<endl;

    return 0;
}

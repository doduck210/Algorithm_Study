//https://www.acmicpc.net/problem/9663
#include <iostream>
using namespace std;

int N;
bool table[15][15];
int cnt=0;

void scanning(int row,int placedQueenCnt){
    for(int i=0;i<=N;i++){
        if(table[row][i]){
            //앞으로 못갈곳들 표기
            for(int j=row+1;j<N;j++){
                table[j][i]=false;
                if(i+j-row<N) table[j][i+j-row]=false; //오른쪽대각선
                if(i-j+row>0) table[j][i-j+row]=false; //왼쪽대각선
            }
            scanning(row+1,placedQueenCnt+1);
        }
    }
}

int main(){
    cin>>N;
    //cleaning table
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            table[i][j]=true;
        }
    }
    

    return 0;
}
//https://www.acmicpc.net/problem/9663
#include <iostream>
using namespace std;

int N;
bool table[15][15];
int cnt=0;

void scanning(int row,int placedQueenCnt){
    for(int i=0;i<N;i++){
        if(table[row][i]){
            if(placedQueenCnt+1==N){
                cnt++;
                continue;
            }
            bool savedTable[15][15];//현재테이블 상태 저장
            for(int a=0;a<N;a++){
                for(int b=0;b<N;b++){
                    savedTable[a][b]=table[a][b];
                }
            }
            //앞으로 못갈곳들 표기
            for(int j=row+1;j<N;j++){
                table[j][i]=false; //세로줄
                if(i+j-row<N) table[j][i+j-row]=false; //오른쪽대각선
                if(i-j+row>=0) table[j][i-j+row]=false; //왼쪽대각선
            }
            /* 디버깅용
            cout<<"placed at "<<row<<' '<<i<<endl; 
            for(int a=0;a<N;a++){
                for(int b=0;b<N;b++){
                    cout<<table[a][b]<<' ';
                } cout<<endl;
            }*/
            scanning(row+1,placedQueenCnt+1);
            //테이블 다시 돌리기
            for(int a=0;a<N;a++){
                for(int b=0;b<N;b++){
                    table[a][b]=savedTable[a][b];
                }
            }
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
    scanning(0,0);

    cout<<cnt<<endl;

    return 0;
}
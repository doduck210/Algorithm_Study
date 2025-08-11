//https://www.acmicpc.net/problem/15650
#include <iostream>
#include <vector>
using namespace std;

int N, M;
vector<vector<int>> ans;

void input(){
    cin>>N>>M;
}

void solution(int curPosition,int filledCnt, vector<int> tmp){
    //종료검사
    if(filledCnt==M){
        ans.push_back(tmp);
        return;
    }
    if(curPosition>N) return;

    //현재숫자 한번 넣고 넘어가거나 안넣고 넘어가거나. 개수가 안남을땐 안넣는거 없이
    tmp.push_back(curPosition);
    solution(curPosition+1,filledCnt+1,tmp);
    if(curPosition+M-filledCnt<=N){
        tmp.pop_back();
        solution(curPosition+1,filledCnt,tmp);
    }
}

void ansPrint(){
    for(int i=0;i<ans.size();i++){
        for(int j=0;j<M;j++){
            cout<<ans[i][j]<<" ";
        }
        cout<<"\n";
    }
}

int main(){
    input();
    
    vector<int> tmp;
    solution(1,0,tmp);
    
    ansPrint();

    return 0;
}

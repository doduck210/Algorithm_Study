//https://www.acmicpc.net/problem/14889
#include <iostream>
#include <algorithm>
#include <vector>
#include <limits.h>
using namespace std;

int N;
int table[20][20];
bool isUsed[20]={false,};
vector <int> teamA,teamB;
int ans=INT_MAX;

void input(){
    cin>>N;
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            cin>>table[i][j];
        }
    }
}

void calc(){
    int sumA=0, sumB=0;
    for(int i=0;i<N/2;i++){
        for(int j=0;j<N/2;j++){
            sumA+=table[teamA[i]][teamA[j]];
            sumB+=table[teamB[i]][teamB[j]];
        }
    }
    int dif=sumA-sumB;
    if(dif<0)
        dif=dif*-1;
    ans=min(ans,dif);
}

void allo(int idx){
    if(teamA.size()==N/2){
        teamB.clear();
        for(int i=0;i<N;i++){
            if(!isUsed[i])
                teamB.push_back(i);
        }
        calc();
        return;
    }
    for(int i=idx;i<N;i++){
        if(!isUsed[i]){
            isUsed[i]=true;
            teamA.push_back(i);
            allo(i+1);
            teamA.pop_back();
            isUsed[i]=false;
        }
    }
}

int main(){
    input();
    allo(0);
    cout<<ans<<endl;
    return 0;
}
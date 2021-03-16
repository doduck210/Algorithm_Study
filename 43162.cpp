//https://programmers.co.kr/learn/courses/30/lessons/43162?language=cpp
#include <string>
#include <vector>

using namespace std;

int ans=0; bool check[200]={false,};
int coms[200][200]; int N;

void dfs(int a){
    if(check[a])
        return;
    check[a]=true;
    for(int i=0;i<N;i++){
        if(!check[i]){
            if(coms[a][i]==1){
                dfs(i);
            }
        }
    }
}

int solution(int n, vector<vector<int>> computers) {
    N=n;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            coms[i][j]=computers[i][j];
        }
    }
    
    for(int i=0;i<n;i++){
        if(!check[i]){
            ans++;
        }
        dfs(i);
    }
    
    return ans;
}
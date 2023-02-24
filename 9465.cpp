#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int T;
int N;
int table[2][100000];
int dp[2][100000];
vector<int> ans;

void solution(){
    dp[0][0]=table[0][0];
    dp[1][0]=table[1][0];
    if(N>1){
        dp[0][1]=dp[1][0]+table[0][1];
        dp[1][1]=dp[0][0]+table[1][1];
    }
    for(int i=2;i<N;i++){
        //upper thing
        dp[0][i]=max(dp[1][i-2]+table[0][i],dp[1][i-1]+table[0][i]);
        //under thing
        dp[1][i]=max(dp[0][i-2]+table[1][i],dp[0][i-1]+table[1][i]);
    }
    ans.push_back(max(dp[0][N-1],dp[1][N-1]));
}

int main(){
    cin>>T;
    for(int t=0;t<T;t++){
        cin>>N;
        for(int i=0;i<2;i++){
            for(int n=0;n<N;n++){
                cin>>table[i][n];
                dp[i][n]=0; //initialize dp table
            }
        }
        solution();
    }
    for(int i=0;i<ans.size();i++){
        cout<<ans[i]<<"\n";
    }
    return 0;
}
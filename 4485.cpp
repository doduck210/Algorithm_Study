#include <iostream>
#include <vector>
#include <queue>
using namespace std;

vector<int> N;
vector<vector<vector<int>>> table;
vector<vector<vector<int>>> score;
vector<int> ans;

int dy[4]={-1,1,0,0};
int dx[4]={0,0,-1,1};

void input(){
    while(true){
        int n;
        cin>>n;
        if(n==0) break;
        N.push_back(n);
        vector<vector<int>> aTable; vector<vector<int>> aScore;
        for(int i=0;i<n;i++){
            vector<int> aRow;   vector<int> scoreRow;
            for(int j=0;j<n;j++){
                int tmp; cin>>tmp;
                aRow.push_back(tmp);
                scoreRow.push_back(INT32_MAX);
            }
            aTable.push_back(aRow);
            aScore.push_back(scoreRow);
        }
        table.push_back(aTable);
        score.push_back(aScore);
    }
}

void search(int n){
    //BFS Searching
    queue<int> y; queue<int> x;
    y.push(0); x.push(0);
    score[n][0][0]=table[n][0][0];
    while(!y.empty()){
        int yy=y.front(); int xx=x.front();
        y.pop(); x.pop();
        if(yy==N[n]-1&&xx==N[n]-1) continue;
        for(int i=0;i<4;i++){
            int ny=yy+dy[i]; int nx=xx+dx[i];
            if(ny>=0&&ny<N[n]&&nx>=0&&nx<N[n]&&score[n][ny][nx]>score[n][yy][xx]+table[n][ny][nx]){
                score[n][ny][nx]=score[n][yy][xx]+table[n][ny][nx];
                y.push(ny); x.push(nx);
            }
        }
    }
    ans.push_back(score[n][N[n]-1][N[n]-1]);
}

void solve(){
    for(int i=0;i<N.size();i++){
        search(i);
    }
    for(int i=0;i<N.size();i++){
        cout<<"Problem "<<i+1<<": "<<ans[i]<<"\n";
    }
}

int main(){
    input();
    solve();
    return 0;
}
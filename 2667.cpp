//https://www.acmicpc.net/problem/2667
#include <iostream>
#include <queue>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

int n;
string table[25];
int g[25][25]={0};
vector<int> ans;

int dy[4]={-1,1,0,0};
int dx[4]={0,0,-1,1};

void input(){
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>table[i];
    }
}

void grouping(){
    int gnum=0;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(table[i][j]=='1'&&g[i][j]==0){
                queue<int> ii,jj;
                int cnt=1;
                g[i][j]=++gnum;
                ii.push(i); jj.push(j);
                while(ii.size()){
                    int curi=ii.front(), curj=jj.front();
                    ii.pop(); jj.pop();
                    for(int k=0;k<4;k++){
                        int nexti=curi+dy[k], nextj=curj+dx[k];
                        if(nexti>=0&&nextj>=0&&nexti<n&&nextj<n&&table[nexti][nextj]=='1'&&g[nexti][nextj]==0){
                            g[nexti][nextj]=gnum;
                            ii.push(nexti); jj.push(nextj);
                            cnt++;
                        }
                    }
                }
                ans.push_back(cnt);
            }
        }
    }
}

int main(){
    input();
    grouping();
    sort(ans.begin(),ans.end());
    cout<<ans.size()<<"\n";
    for(int i=0;i<ans.size();i++){
        cout<<ans[i]<<"\n";
    }

    return 0;
}
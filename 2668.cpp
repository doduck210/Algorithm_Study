#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N;
int n[101];
bool haveN[101]={0,};
bool visited[101]={0,};
bool localV[101];
vector<int> ans;

void input(){
    cin>>N;
    for(int i=1;i<=N;i++){
        cin>>n[i];
        haveN[n[i]]=true;
    }
}

bool check(int i,int cur){
    if(visited[cur]||localV[cur]) return false;
    localV[cur]=true;
    if(i==n[cur]) {
        ans.push_back(cur); visited[cur]=true;
        return true;
    }
    if(haveN[cur]==false) return false;
    if(check(i,n[cur])){
        ans.push_back(cur); visited[cur]=true;
        return true;
    }
    return false;
}

int main(){
    input();

    for(int i=1;i<=N;i++){
        for(int j=1;j<=N;j++){
            localV[j]=false;
        }
        check(i,i);
    }
    sort(ans.begin(),ans.end());
    cout<<ans.size()<<'\n';
    for(int i=0;i<ans.size();i++){
        cout<<ans[i]<<'\n';
    }
    
    return 0;
}
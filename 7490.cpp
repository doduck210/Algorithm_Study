#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

int n;
vector<int> N;
int maxN=0;
bool e[11]={0,};
vector<vector<string>> ans;

void input(){
    cin>>n;
    for(int i=0;i<n;i++){
        int tmp; cin>>tmp;
        N.push_back(tmp);
        e[tmp]=true;
        maxN=max(maxN,tmp);
        vector<string> stmp;
        ans.push_back(stmp);
    }
}

void find(string s,int val,int cnt){
    //terminate condition
    if(e[cnt]==true&&val==0){
        for(int i=0;i<n;i++){
            if(N[i]==cnt){
                ans[i].push_back(s);
            }
        }
    }
    if(cnt==maxN) return;
    //cal
    if(cnt==0){
        find("1",1,1);
    }
    else{
        find(s+'+'+to_string(cnt+1),val+cnt+1,cnt+1);
        find(s+'-'+to_string(cnt+1),val-cnt-1,cnt+1);
    }
    string nxtN=to_string(cnt+1);
    int nxtV=cnt+1;
    for(int i=cnt+2;i<=maxN;i++){
        nxtN+=' '+to_string(i);
        nxtV*=10; nxtV+=i;
        if(cnt==0){
            find(nxtN,nxtV,i);
        }
        else{
            find(s+'+'+nxtN,val+nxtV,i);
            find(s+'-'+nxtN,val-nxtV,i);
        }
        if(nxtN.size()>=9) break; 
    }
}

int main(){
    input();
    find("",0,0);
    for(int i=0;i<n;i++){
        sort(ans[i].begin(),ans[i].end());
        for(int j=0;j<ans[i].size();j++){
            cout<<ans[i][j]<<'\n';
        } cout<<'\n';
    }
    return 0;
}
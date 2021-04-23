//https://www.acmicpc.net/problem/1150
#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;
int n,k;
vector<int> company;
vector<int> distan;
int ans=INT_MAX;

void input(){
    cin>>n>>k;
    for(int i=0;i<n;i++){
        int temp; cin>>temp;
        company.push_back(temp);
    }
}

void getDistan(){
    for(int i=1;i<n;i++){
        distan.push_back(company[i]-company[i-1]);
    }
}

void bfs(int loca,int cnt,int cur){
    if(cnt==k){
        ans=min(cur,ans);
        return;
    }
    if(loca>=n-1){
        return;
    }
    bfs(loca+1,cnt,cur);
    bfs(loca+2,cnt+1,cur+distan[loca]);
}

int main(){
    ios::sync_with_stdio(false); 
    cout.tie(NULL); 
    cin.tie(NULL);

    input();
    getDistan();
    bfs(0,0,0);
    cout<<ans<<"\n";

    return 0;
}
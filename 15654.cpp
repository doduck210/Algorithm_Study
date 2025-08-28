//https://www.acmicpc.net/problem/15654
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n,m;
vector<int> nums;
vector<int> ans;
bool visited[9]={0,};

void input(){
    cin>>n>>m;
    for(int i=0;i<n;i++){
        int a; cin>>a;
        nums.push_back(a);
    }
    sort(nums.begin(), nums.end());
}

void find(){
    //종료조건
    if(ans.size()==m){
        for(int i=0;i<m;i++){
            cout<<ans[i]<<" ";
        } cout<<"\n";
        return;
    }

    for(int i=0;i<n;i++){
        if(!visited[i]){
            ans.push_back(nums[i]); visited[i]=1;
            find();
            ans.pop_back(); visited[i]=0;
        }
    }

}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    input();

    find();

    return 0;
}
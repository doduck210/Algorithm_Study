//https://programmers.co.kr/learn/courses/30/lessons/42895
#include <algorithm>
using namespace std;

int input; int target;
int ans=9;

void dfs(int current,int cnt){
    if(cnt>8){
        return;
    }
    if(current==target){
        ans=min(cnt,ans);
        return;
    }
    int temp=0;
    for(int i=0;cnt+i<9;i++){
        temp = (temp*10)+input;
        dfs(current+temp,cnt+1+i);
        dfs(current-temp,cnt+1+i);
        dfs(current*temp,cnt+1+i);
        dfs(current/temp,cnt+1+i);
    }
}

int solution(int N, int number) {
    input=N;
    target=number;
    
    dfs(0,0);
    if(ans>8)
        ans=-1;
    
    return ans;
}
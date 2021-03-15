//https://programmers.co.kr/learn/courses/30/lessons/43165
#include <string>
#include <vector>

using namespace std;

int N; //number of numbers
int tar; int ans=0;
vector<int> nums;

void dfs(int cur,int result){
    if(cur==N){
        if(tar==result){
            ans+=1;
        }
        return;
    }
    dfs(cur+1,result+nums[cur]);
    dfs(cur+1,result-nums[cur]);
}

int solution(vector<int> numbers, int target) {
    N=numbers.size();
    tar=target;
    for(int i=0;i<N;i++){
        nums.push_back(numbers[i]);
    }
    dfs(0,0);
    return ans;
}
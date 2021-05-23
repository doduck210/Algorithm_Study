//https://programmers.co.kr/learn/courses/30/lessons/42586
#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds) {
    vector<int> ans;
    int cur=-1;
    for(int i=0;i<progresses.size();i++){
        int needed=(100-progresses[i])/speeds[i];
        if((100-progresses[i])%speeds[i]!=0) needed++;
        if(cur<needed){
            ans.push_back(1);
            cur=needed;
        }
        else{
            ans[ans.size()-1]++;
        }
    }
    return ans;
}
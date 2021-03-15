//https://programmers.co.kr/learn/courses/30/lessons/42578
#include <string>
#include <vector>

using namespace std;

int solution(vector<vector<string>> clothes) {
    vector<string> types;
    vector<int> ans;
    
    for(int i=0;i<clothes.size();i++){
        
        bool no=true;
        for(int j=0;j<types.size();j++){
            if(clothes[i][1]==types[j]){
                no=false;
                ans[j]++;
                break;
            }
        }
        if(no){
            types.push_back(clothes[i][1]);
            ans.push_back(1);
        }
        
    }
    
    
    
    int answer = 1;
    for(int i=0;i<ans.size();i++){
        answer=answer*(ans[i]+1);
    }
    
    return answer-1;
}
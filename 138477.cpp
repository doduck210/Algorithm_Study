#include <string>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> solution(int k, vector<int> score) {
    vector<int> ans;
    vector<int> rank;
    for(int i=0;i<score.size();i++){
        if(i<=k-1){
            rank.push_back(score[i]);
            sort(rank.begin(),rank.end());
        }
        else if(rank[0]<score[i]){
            rank[0]=score[i];
            sort(rank.begin(),rank.end());
        }
        ans.push_back(rank[0]);
    }
    return ans;
}
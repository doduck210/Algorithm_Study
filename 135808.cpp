//https://school.programmers.co.kr/learn/courses/30/lessons/135808
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int solution(int k, int m, vector<int> score) {
    int ans = 0;
    
    sort(score.begin(),score.end());
    int end = score.size();
    while(end>=m){
        int low = score[end-m];
        end-=m;
        ans+=(low*m);
    }
    
    return ans;
}
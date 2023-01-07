//https://school.programmers.co.kr/learn/courses/30/lessons/12954
#include <string>
#include <vector>

using namespace std;

vector<long long> solution(int x, int n) {
    vector<long long> ans;
    for(int i=1;i<=n;i++){
        ans.push_back(x*i);
    }
    
    return ans;
}
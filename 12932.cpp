//https://school.programmers.co.kr/learn/courses/30/lessons/12932
#include <string>
#include <vector>

using namespace std;

vector<int> solution(long long n) {
    vector<int> ans;
    while(n){
        ans.push_back(n%10);
        n/=10;
    }
    return ans;
}
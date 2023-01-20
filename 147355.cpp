//https://school.programmers.co.kr/learn/courses/30/lessons/147355
#include <string>
#include <vector>

using namespace std;

int solution(string t, string p) {
    int ans = 0;
    
    int len=p.size();
    for(int i=0;i<=t.size()-len;i++){
        if(t.substr(i,len)<=p) ans++;
    }
    
    return ans;
}
//https://school.programmers.co.kr/learn/courses/30/lessons/140108 
#include <string>
#include <vector>

using namespace std;

int solution(string s) {
    int ans = 0;
    
    for(int i=0;i<s.size();i++){
        char x=s[i];
        int same=1; int diff=0;
        
        for(int j=i+1;j<s.size();j++){
            if(s[j]==x) same++;
            else diff++;
            i=j;
            if(same==diff)  break;
        }
        ans++;
    }
    
    return ans;
}
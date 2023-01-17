//https://school.programmers.co.kr/learn/courses/30/lessons/12930
#include <string>
#include <vector>

using namespace std;

string solution(string s) {
    string ans = "";
    int stand=0;
    for(int i=0;i<s.size();i++){
        if(s[i]==' ') {
            stand=0;
            continue;
        }
        //even number and small
        if(stand%2==0&&s[i]>='a'){
            s[i]-=32;
        }
        //odd number and capital
        if(stand%2==1&&s[i]<'a'){
            s[i]+=32;
        }
        stand++;
    }       
    ans=s;
    return ans;
}
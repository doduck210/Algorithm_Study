//https://programmers.co.kr/learn/courses/30/lessons/12899
#include <string>
#include <vector>

using namespace std;

string solution(int n) {
    string ans = "";
    while(n){
        if(n%3==0) {ans="4"+ans;n-=1;}
        else if(n%3==2) ans="2"+ans;
        else if(n%3==1) ans="1"+ans;
        n=n/3;
    }
    
    return ans;
}
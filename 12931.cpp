//https://school.programmers.co.kr/learn/courses/30/lessons/12931
#include <iostream>

using namespace std;
int solution(int n)
{
    int ans = n%10;
    n/=10;
    
    while(n){
        ans+=n%10;
        n/=10;
    }

    return ans;
}
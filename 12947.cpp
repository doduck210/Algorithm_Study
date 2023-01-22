//https://school.programmers.co.kr/learn/courses/30/lessons/12947 
#include <string>
#include <vector>

using namespace std;

bool solution(int x) {
    int sum=0;
    int xx=x;
    while(xx){
        sum+=xx%10;
        xx/=10;
    }
    return x%sum==0;
}
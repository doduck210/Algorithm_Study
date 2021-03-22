//https://programmers.co.kr/learn/courses/30/lessons/42842
#include <string>
#include <vector>
using namespace std;

int total, bro;

bool check(int height,int width){
    return (height*2)+((width-2)*2)==bro;
}

vector<int> solution(int brown, int yellow) {
    total=brown+yellow; bro=brown;
    int a,b;
    for(a=3;;a++){
        if(total%a==0){
            if(check(total/a,a)){
                b=total/a;
                break;
            }
        }
    }
    vector<int> answer={b,a};
    return answer;
}
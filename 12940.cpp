//https://school.programmers.co.kr/learn/courses/30/lessons/12940
#include <string>
#include <vector>

using namespace std;

vector<int> solution(int n, int m) {
    vector<int> ans;
    
    int gcd; int lcm;
    int nn=n; int mm=m;
    
    //decide gcd
    int tmp;
    while(mm!=0){
        tmp=nn%mm;
        nn=mm;
        mm=tmp;
    }
    gcd=nn;
    ans.push_back(gcd);
    
    //decide lcm
    lcm=n*m/gcd;
    ans.push_back(lcm);
    return ans;
}
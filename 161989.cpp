#include <string>
#include <vector>
using namespace std;

int solution(int n, int m, vector<int> section) {
    int ans = 0;
    int cur=0;
    for(int i=0;i<section.size();i++){
        if(cur<section[i]){
            cur=section[i]+m-1;
            ans++;
        }
    }
    return ans;
}
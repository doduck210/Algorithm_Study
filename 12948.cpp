#include <string>
#include <vector>

using namespace std;

string solution(string pn) {
    string ans = "";
    for(int i=1;i<=4;i++){
        ans=pn[pn.size()-i]+ans;
    }
    for(int i=5;i<=pn.size();i++){
        ans='*'+ans;
    }
    return ans;
}
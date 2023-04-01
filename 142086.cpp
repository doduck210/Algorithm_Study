#include <string>
#include <vector>
using namespace std;

vector<int> solution(string s) {
    vector<int> ans;
    //a to z == 97 to 122
    int pos[123];
    for(int i=97;i<123;i++){
        pos[i]=-1;
    }
    for(int i=0;i<s.size();i++){
        int cur=(int)s[i];
        if(pos[cur]==-1) ans.push_back(pos[cur]);
        else ans.push_back(i-pos[cur]);
        pos[cur]=i;
    }
    return ans;
}
#include <string>
#include <vector>

using namespace std;

string solution(vector<string> cards1, vector<string> cards2, vector<string> goal) {
    while(!goal.empty()){
        if(!cards1.empty()&&goal[0]==cards1[0]){
            cards1.erase(cards1.begin());
            goal.erase(goal.begin());
        }
        else if(!cards2.empty()&&goal[0]==cards2[0]){
            cards2.erase(cards2.begin());
            goal.erase(goal.begin());
        }
        else return "No";
    }
    return "Yes";
}
//https://school.programmers.co.kr/learn/courses/30/lessons/12935
#include <string>
#include <vector>
using namespace std;

vector<int> solution(vector<int> arr) {
    vector<int> ans;
    int min=arr[0];
    
    for(int i=1;i<arr.size();i++){
        if(min>arr[i]) min=arr[i];    
    }
    for(int i=0;i<arr.size();i++){
        if(min<arr[i]) ans.push_back(arr[i]);
    }
    if(ans.size()==0) ans.push_back(-1);
    return ans;
}
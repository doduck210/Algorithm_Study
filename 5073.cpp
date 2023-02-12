#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;
vector<vector<int>> lines;
vector<string> ans;

void input(){
    for(;;){
        int l1,l2,l3;
        cin>>l1>>l2>>l3;
        if(l1==0) break;
        vector<int> tri;
        tri.push_back(l1); tri.push_back(l2); tri.push_back(l3);
        sort(tri.begin(),tri.end());
        lines.push_back(tri);
    }
}

int main(){
    input();
    for(int i=0;i<lines.size();i++){
        //check invalid
        if(lines[i][0]+lines[i][1]<=lines[i][2]) ans.push_back("Invalid");
        //check Equilateral
        else if(lines[i][0]==lines[i][1]&&lines[i][0]==lines[i][2]) ans.push_back("Equilateral");
        //check Isosceles
        else if(lines[i][0]==lines[i][1]||lines[i][1]==lines[i][2]||lines[i][0]==lines[i][2]) ans.push_back("Isosceles");
        //Scalene
        else ans.push_back("Scalene");
    }
    for(int i=0;i<ans.size();i++){
        cout<<ans[i]<<"\n";
    }
    return 0;
}
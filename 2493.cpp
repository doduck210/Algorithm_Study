#include <iostream>
#include <vector>
using namespace std;

int N;
vector<int> towers;
vector<int> ans;

void input(){
    cin>>N;
    for(int i=0;i<N;i++){
        int t; cin>>t;
        towers.push_back(t);
    }
}

int main(){
    input();
    for(int i=0;i<N;i++){
        int v=towers[i];
        int id=0;
        for(int j=i-1;j>=0;j--){
            if(towers[j]>v){
                id=j+1;
                break;
            }
            else{
                j=ans[j];
            }
        }
        ans.push_back(id);
    }
    for(int i=0;i<ans.size();i++){
        cout<<ans[i]<<" ";
    } cout<<"\n";
    return 0;
}
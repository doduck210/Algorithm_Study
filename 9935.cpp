#include <iostream>
#include <string>
#include <vector>
using namespace std;
int main(){
    string s; cin>>s;
    string b; cin>>b;
    vector<char> ans;
    for(int i=0;i<s.size();i++){
        ans.push_back(s[i]);
        bool including=true;
        for(int j=1;j<=b.size();j++){
            if(ans[ans.size()-j]!=b[b.size()-j]){
                including=false;
                break;
            }
        }
        if(including){
            for(int j=0;j<b.size();j++){
                ans.pop_back();
            }
        }
    }
    if(ans.size()==0) cout<<"FRULA\n";
    else{
        for(int i=0;i<ans.size();i++){
            cout<<ans[i];
        } cout<<'\n';
    }
    return 0;
}
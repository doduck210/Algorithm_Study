#include <iostream>
#include <string>
#include <vector>
using namespace std;
int main(){
    string s; cin>>s;
    string b; cin>>b;
    while(s.find(b)<s.size()){
        string nxt=s.substr(0,s.find(b));
        nxt+=s.substr(s.find(b)+b.size(),s.size()-s.find(b)+b.size());
        s=nxt;
    }
    if(s.size()==0) cout<<"FRULA\n";
    else cout<<s<<'\n';
    return 0;
}
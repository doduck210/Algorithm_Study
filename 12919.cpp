#include <iostream>
#include <string>
using namespace std;

string S,T;
bool ans=false;

void input(){
    cin>>S>>T;
}

void reduct(string t){
    if(S.size()==t.size()){
        if(S==t) ans=true;
        return;
    }
    if(t[t.size()-1]=='A'){
        string tmp=t;
        tmp.erase(t.size()-1);
        reduct(tmp);
    }
    if(t[0]=='B'){
        string tmp="";
        for(int i=t.size()-1;i>0;i--){
            tmp+=t[i];
        }
        reduct(tmp);
    }
}

int main(){
    input();
    reduct(T);
    cout<<ans<<"\n";
    return 0;
}
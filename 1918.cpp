//https://www.acmicpc.net/problem/1918
#include <iostream>
#include <string>
#include <vector>
using namespace std;

string original;
vector<char> stack;
string ans="";

int main(){
    cin>>original;

    for(int i=0;i<original.size();i++){
        if(original[i]=='('){
            stack.push_back('(');
        }
        else if(original[i]==')'){
            char tmp=stack.back(); stack.pop_back();
            while(tmp!='('){
                ans+=tmp;
                tmp=stack.back(); stack.pop_back();
            }
        }
        else if(original[i]=='*'||original[i]=='/'){
            while(!stack.empty()&&(stack.back()=='*'||stack.back()=='/')){
                ans+=stack.back(); stack.pop_back();
            }
            stack.push_back(original[i]);
        }
        else if(original[i]=='+'||original[i]=='-'){
            while(!stack.empty()&&(stack.back()=='*'||stack.back()=='/'||stack.back()=='+'||stack.back()=='-')){
                ans+=stack.back(); stack.pop_back();
            }
            stack.push_back(original[i]);
        }
        else{
            ans+=original[i];
        }
    }
    while(!stack.empty()){
        ans.push_back(stack.back()); stack.pop_back();
    }

    cout<<ans<<"\n";
    
    return 0;
}
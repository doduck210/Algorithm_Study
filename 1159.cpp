//https://www.acmicpc.net/problem/1159
#include <iostream>
#include <string>
using namespace std;
int n;
string input[150];
int count[123]={0,};
//a=97 z=122;

int main(){
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>input[i];
        count[(int)input[i][0]]++;
    }
    string ans;
    for(int i=97;i<=122;i++){
        if(count[i]>=5){
            ans+=(char)i;
        }
    }
    if(ans.size()==0){
        cout<<"PREDAJA"<<"\n";
    }
    else{
        cout<<ans<<"\n";
    }
    

    return 0;
}
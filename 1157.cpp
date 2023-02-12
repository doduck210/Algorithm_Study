#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
int a[100]={0,};
int main(){
    string s;
    cin>>s;
    for(int i=0;i<s.size();i++){
        int letter=s[i];
        //make it capital
        if(letter>96) letter-=32;
        a[letter]++;
    }
    int mx=0;
    for(int i=65;i<=90;i++){
        mx=max(mx,a[i]);
    }
    int cnt=0;
    char ans;
    for(int i=65;i<=90;i++){
        if(mx==a[i]){
            ans=i;
            cnt++;
        }
    }
    if(cnt>1) cout<<"?\n";
    else cout<<ans<<"\n";
    return 0;
}
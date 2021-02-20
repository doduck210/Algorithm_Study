//https://www.acmicpc.net/problem/14888
#include <iostream>
#include <algorithm>
#include <limits.h>
using namespace std;

int N;
int num[11];
int add, sub, mul, di;

int maxans=INT_MIN;
int minans=INT_MAX;

void input(){
    cin>>N;
    for(int i=0;i<N;i++){
        cin>>num[i];
    }
    cin>>add>>sub>>mul>>di;
}

void solve(int pre,int cnt){
    if(cnt==N){
        maxans=max(pre,maxans);
        minans=min(pre,minans);
        return;
    }
    if(add>0){
        add--;
        solve(pre+num[cnt],cnt+1);
        add++;
    }
    if(sub>0){
        sub--;
        solve(pre-num[cnt],cnt+1);
        sub++;
    }
    if(mul>0){
        mul--;
        solve(pre*num[cnt],cnt+1);
        mul++;
    }
    if(di>0){
        di--;
        solve(pre/num[cnt],cnt+1);
        di++;
    }
}

int main(){
    input();
    solve(num[0],1);

    cout<<maxans<<endl;
    cout<<minans<<endl;

    return 0;
}
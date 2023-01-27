#include <iostream>
#include <queue>
using namespace std;

int N,K;
int curMin[100001];
int ans;

void input(){
    cin>>N>>K;
    for(int i=0;i<100001;i++){
        curMin[i]=100000;
    }
}

void find(){
    queue<int> n;
    n.push(N);
    curMin[N]=0;
    while(!n.empty()){
        int cur=n.front();
        n.pop();
        if(cur==K) return;
        if(2*cur<=100000&&curMin[2*cur]>curMin[cur]){
            n.push(cur*2);
            curMin[2*cur]=curMin[cur];
        }
        if(cur+1<=100000&&curMin[1+cur]>curMin[cur]+1){
            n.push(cur+1);
            curMin[cur+1]=curMin[cur]+1;
        }
        if(cur-1>=0&&curMin[cur-1]>curMin[cur]+1){
            n.push(cur-1);
            curMin[cur-1]=curMin[cur]+1;
        }
    }
}

int main(){
    input();
    find();
    cout<<curMin[K]<<endl;
    return 0;
}
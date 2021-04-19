//https://www.acmicpc.net/problem/1655
#include <iostream>
#include <queue>
using namespace std;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin>>n;
    priority_queue<int> leftMax,rightMin;
    for(int i=0;i<n;i++){
        int x; cin>>x;
        if(leftMax.size()<=rightMin.size()) leftMax.push(x);
        else rightMin.push(-x);
        
        if(rightMin.size()>0 && leftMax.top()>-rightMin.top()){
            int leftTemp=leftMax.top(); leftMax.pop();
            int rightTemp=-rightMin.top(); rightMin.pop();
            
            leftMax.push(rightTemp);
            rightMin.push(-leftTemp);
        }
        cout<<leftMax.top()<<"\n";
    }

    return 0;
}
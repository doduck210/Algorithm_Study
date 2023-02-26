#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N;
vector<int> tri[500];
vector<int> ans[500];

void input(){
    cin>>N;
    for(int i=0;i<N;i++){
        for(int j=0;j<=i;j++){
            int t; cin>>t;
            tri[i].push_back(t);
        }
    }
    ans[0].push_back(tri[0][0]);
}

int dp(){
    for(int i=1;i<N;i++){
        for(int j=0;j<=i;j++){
            int upperLeft=tri[i][j], upper=upperLeft;
            if(j>0) upperLeft+=ans[i-1][j-1];
            if(j<i) upper+=ans[i-1][j];
            ans[i].push_back(max(upperLeft,upper)); 
        }
    }
    int a=0;
    for(int i=0;i<N;i++){
        a=max(a,ans[N-1][i]);
    }
    return a;
}

int main(){
    input();
    cout<<dp()<<"\n";
    return 0;
}
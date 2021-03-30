//https://www.acmicpc.net/problem/15686
#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
#include <cstdlib>
using namespace std;

int table[50][50];
int n,m;
int ans=INT_MAX;
vector<int> housex, housey;
vector<int> chikenx, chikeny;
vector<int> pickedx, pickedy;

void input(){
    cin>>n>>m;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin>>table[i][j];
            if(table[i][j]==1){
                housex.push_back(i); housey.push_back(j);
            }
            else if(table[i][j]==2){
                chikenx.push_back(i); chikeny.push_back(j);
            }
        }
    }
}

void score(){
    int a=0;
    for(int i=0;i<housex.size();i++){
        int temp=INT_MAX;
        for(int j=0;j<m;j++){
            temp=min(temp,abs(housex[i]-pickedx[j])+abs(housey[i]-pickedy[j]));
        }
        a+=temp;
    }
    ans=min(ans,a);
}

void choose(int iter){
    if(pickedx.size()==m){
        score();
        return;
    }
    for(int i=iter;i<chikenx.size();i++){
        pickedx.push_back(chikenx[i]); pickedy.push_back(chikeny[i]);
        choose(i+1);
        pickedx.pop_back(); pickedy.pop_back();
    }
}

int main(){
    input();

    choose(0);

    cout<<ans<<"\n";

    return 0;
}
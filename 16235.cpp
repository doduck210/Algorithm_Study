//https://www.acmicpc.net/problem/16235
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int N,M,K;
int A[10][10];
int nut[10][10];
vector<int> tree[10][10];

void input(){
    cin>>N>>M>>K;
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            cin>>A[i][j];
            nut[i][j]=5;
        }
    }
    for(int i=0;i<M;i++){
        int x,y,z;
        cin>>x>>y>>z;
        tree[x-1][y-1].push_back(z);
    }
}

void spring(){
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            int summer=0;
            sort(tree[i][j].begin(),tree[i][j].end());
            int l=tree[i][j].size();
            for(int a=0;a<l;a++){
                if(nut[i][j]-tree[i][j][a]>=0){
                    nut[i][j]-=tree[i][j][a];
                    tree[i][j][a]++;
                }
                else{
                    summer+=(tree[i][j].back()/2);
                    tree[i][j].pop_back();
                    M--;
                }
            }
            nut[i][j]+=summer;
        }
    }
}

void autumn(){
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            for(int a=0;a<tree[i][j].size();a++){
                if(tree[i][j][a]%5==0){
                    if(i>0){
                        tree[i-1][j].push_back(1); M++;
                        if(j>0) {tree[i-1][j-1].push_back(1);M++;}
                        if(j<N-1) {tree[i-1][j+1].push_back(1);M++;}
                    }
                    if(j>0) {tree[i][j-1].push_back(1);M++;}
                    if(j<N-1) {tree[i][j+1].push_back(1);M++;}
                    if(i<N-1){
                        tree[i+1][j].push_back(1); M++;
                        if(j>0) {tree[i+1][j-1].push_back(1);M++;}
                        if(j<N-1) {tree[i+1][j+1].push_back(1);M++;}
                    }
                }
            }
            nut[i][j]+=A[i][j];
        }
    }
}

int main(){
    input();

    for(int i=0;i<K;i++){
        spring();
        autumn();
    }

    cout<<M<<"\n";

    return 0;
}
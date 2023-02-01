#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N,M,L,K;
bool table[500001][500001]={0,};
int mxTable[500001][500001]={0,};

void input(){
    cin>>N>>M>>L>>K;
    for(int i=0;i<K;i++){
        int y,x;
        cin>>y>>x;
        table[y][x]=1;
    }
}

int mxL(){
    
}

int main(){
    input();
    return 0;
}
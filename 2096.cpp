#include <iostream>
#include <algorithm>
using namespace std;
int N;
int table[100000][3];
int minTable[100000][3];
int maxTable[100000][3];

void input(){
    cin>>N;
    for(int i=0;i<N;i++){
        cin>>table[i][0]>>table[i][1]>>table[i][2];
    }
    //initialize first line
    minTable[0][0]=table[0][0]; minTable[0][1]=table[0][1]; minTable[0][2]=table[0][2];
    maxTable[0][0]=table[0][0]; maxTable[0][1]=table[0][1]; maxTable[0][2]=table[0][2];
}

void solution(){
    for(int i=1;i<N;i++){
        for(int j=0;j<3;j++){
            if(j==0){
                maxTable[i][j]=max(maxTable[i-1][0],maxTable[i-1][1])+table[i][0];
                minTable[i][j]=min(minTable[i-1][0],minTable[i-1][1])+table[i][0];
            }
            else if(j==1){
                maxTable[i][j]=max(maxTable[i-1][0],maxTable[i-1][1]);
                maxTable[i][j]=max(maxTable[i][j],maxTable[i-1][2])+table[i][1];
                minTable[i][j]=min(minTable[i-1][0],minTable[i-1][1]);
                minTable[i][j]=min(minTable[i][j],minTable[i-1][2])+table[i][1];
            }
            else{
                maxTable[i][j]=max(maxTable[i-1][2],maxTable[i-1][1])+table[i][2];
                minTable[i][j]=min(minTable[i-1][2],minTable[i-1][1])+table[i][2];
            }
        }
    }
}

int main(){
    input();
    solution();
    int mx=max(maxTable[N-1][0],maxTable[N-1][1]); mx=max(mx,maxTable[N-1][2]);
    int mn=min(minTable[N-1][0],minTable[N-1][1]); mn=min(mn,minTable[N-1][2]);
    cout<<mx<<" "<<mn<<"\n";
    return 0;
}
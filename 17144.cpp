//https://www.acmicpc.net/problem/17144
#include <iostream>
#include <vector>
using namespace std;

int r,c,t;
int table[50][50];
vector<int> updown;

void input(){
    cin>>r>>c>>t;
    for(int i=0;i<r;i++){
        for(int j=0;j<c;j++){
            cin>>table[i][j];
            if(table[i][j]==-1){
                updown.push_back(i);
            }
        }
    }
}

void spread(){
    int temp[50][50];
    for(int i=0;i<r;i++){  //copy table
        for(int j=0;j<c;j++){
            temp[i][j]=table[i][j];
        }
    }

    for(int i=0;i<r;i++){
        for(int j=0;j<c;j++){
            if(i>0&&temp[i-1][j]!=-1){
                table[i-1][j]+=temp[i][j]/5;
                table[i][j]-=temp[i][j]/5;
            }
            if(j>0&&temp[i][j-1]!=-1){
                table[i][j-1]+=temp[i][j]/5;
                table[i][j]-=temp[i][j]/5;
            }
            if(i<r-1&&temp[i+1][j]!=-1){
                table[i+1][j]+=temp[i][j]/5;
                table[i][j]-=temp[i][j]/5;
            }
            if(j<c-1){
                table[i][j+1]+=temp[i][j]/5;
                table[i][j]-=temp[i][j]/5;
            }
        }
    }
}

void circul(){
    int up=updown[0], down=updown[1];
    for(int i=up-1;i>0;i--){
        table[i][0]=table[i-1][0];
    }
    for(int j=0;j<c-1;j++){
        table[0][j]=table[0][j+1];
    }
    for(int i=0;i<up;i++){
        table[i][c-1]=table[i+1][c-1];
    }
    for(int j=c-1;j>1;j--){
        table[up][j]=table[up][j-1];
    }
    table[up][1]=0;
    //down circle;
    for(int i=down+1;i<r-1;i++){
        table[i][0]=table[i+1][0];
    }
    for(int j=0;j<c-1;j++){
        table[r-1][j]=table[r-1][j+1];
    }
    for(int i=r-1;i>down;i--){
        table[i][c-1]=table[i-1][c-1];
    }
    for(int j=c-1;j>1;j--){
        table[down][j]=table[down][j-1];
    }
    table[down][1]=0;
}

int score(){
    int ans=2;
    for(int i=0;i<r;i++){
        for(int j=0;j<c;j++){
            ans+=table[i][j];
        }
    }
    return ans;
}

int main(){
    input();
    for(int i=0;i<t;i++){
        spread();
        circul();
    }
    /*
    cout<<"\n";
    for(int i=0;i<r;i++){
        for(int j=0;j<c;j++){
            cout<<table[i][j]<<" ";
        } cout<<"\n";
    }
    */
    cout<<score()<<"\n";
    return 0;
}
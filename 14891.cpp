//https://www.acmicpc.net/problem/14891
#include <iostream>
#include <cmath>
using namespace std;

int gear[4][8];
int k;
int num[100];
int dir[100];

void input(){
    for(int i=0;i<4;i++){
        string index;
        cin>>index;
        for(int j=0;j<8;j++){
            gear[i][j]=(int)index[j]-48;
        }
    }
    cin>>k;
    for(int i=0;i<k;i++){
        cin>>num[i]>>dir[i];
        num[i]--;
    }
}

void rotation(int a,int di){
    int temp;
    if(di==1){
        temp=gear[a][7];
        for(int i=7;i>0;i--){
            gear[a][i]=gear[a][i-1];
        }
        gear[a][0]=temp;
    }
    else{
        temp=gear[a][0];
        for(int i=1;i<8;i++){
            gear[a][i-1]=gear[a][i];
        }
        gear[a][7]=temp;
    }
}

void simul(int a,int di,int lr){
    int anti=1;
    if(di==1) anti=-1;

    if(lr==0 && a!=0){
        if(gear[a][6]!=gear[a-1][2]){
            simul(a-1,anti,lr);
        }
    }
    else if(lr==1&&a!=3){
        if(gear[a][2]!=gear[a+1][6]){
            simul(a+1,anti,lr);
        }
    }
    rotation(a,di);
}

int main(){
    input();

    for(int i=0;i<k;i++){
        if(num[i]!=3){
            if(gear[num[i]][2]!=gear[num[i]+1][6]){
                int anti=1;
                if(dir[i]==1) anti=-1;
                simul(num[i]+1,anti,1);
            }
        }
        simul(num[i],dir[i],0);
    }
    
    int ans=0;
    for(int i=0;i<4;i++){
        ans+= gear[i][0]*pow(2,i);
    }

    cout<<ans<<endl;

    return 0;
}
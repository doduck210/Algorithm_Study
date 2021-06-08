#include <iostream>
#include <cmath>
using namespace std;
int a,p;
int D[1001];

int check(int i,int dd){
    for(int aa=0;aa<i;aa++){
        if(D[aa]==dd){
            return aa;
        }
    }
    return -1;
}

void solution(){
    D[0]=a;
    for(int i=1;;i++){
        int cur=D[i-1];
        int tmp=cur%10; cur=cur/10;
        int dd=pow(tmp,p);
        while(cur){
            tmp=cur%10; cur=cur/10;
            dd+=pow(tmp,p);
        }
        D[i]=dd;
        //cout<<"i:"<<i<<" D[i]:"<<dd<<"\n";
        int c=check(i,dd);
        if(c>=0){
            cout<<c<<"\n";
            return;
        }
    }
}

int main(){
    cin>>a>>p;
    solution();
    return 0;
}
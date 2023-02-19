#include <iostream>
#include <algorithm>
using namespace std;
int N;
int a=0,b=0,c=0;
int aa=0,bb=0,cc=0;

void input(){
    cin>>N;
    for(int i=0;i<N;i++){
        int ta,tb,tc;
        cin>>ta>>tb>>tc;
        //cal min
        int na=min(a,b)+ta;
        int nb=min(a,b); nb=min(nb,c)+tb;
        int nc=min(b,c)+tc;
        a=na;b=nb;c=nc;
        //cal max
        na=max(aa,bb)+ta;
        nb=max(aa,bb); nb=max(nb,cc)+tb;
        nc=max(bb,cc)+tc;
        aa=na;bb=nb;cc=nc;
    }
}

int main(){
    input();
    int mx=max(aa,bb); mx=max(mx,cc);
    int mn=min(a,b); mn=min(mn,c);
    cout<<mx<<" "<<mn<<"\n";
    return 0;
}
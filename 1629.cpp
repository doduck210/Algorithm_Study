//https://www.acmicpc.net/problem/1629
#include<iostream>
using namespace std;

long long power(long long a,long long b,long long c){
    if(b==0) return 1;
    long long tmpb=power(a,b/2,c);
    long long tmp=tmpb*tmpb;
    long long tmpa=tmp%c;
    if(b%2==0){
        return tmpa;
    }
    else{
        tmp=tmpa*a; tmpa=tmp%c;
        return tmpa;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    long long a, b, c;
    cin>>a>>b>>c;
    a%=c;

    cout<<power(a, b, c)<<endl;

    return 0;
}

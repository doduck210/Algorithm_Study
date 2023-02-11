#include <iostream>
using namespace std;

int H,W,N,M;

void input(){
    cin>>H>>W>>N>>M;
}

int main(){
    input();

    int h=H/(N+1);
    if(H%(N+1)) h++;
    int w=W/(M+1);
    if(W%(M+1)) w++;

    cout<<h*w<<"\n";
    return 0;
}
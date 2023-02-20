#include <iostream>
using namespace std;
int N=0;
unsigned int n[10000];
void inv(int a,int b){
    if(a>=b) return;
    unsigned int root=n[a];
    //cout<<root<<" ";
    if(a+1==b){
        cout<<root<<"\n";
        return;
    }
    int right=a+1;
    while(right<b&&n[right]<root){
        right++;
    }
    inv(a+1,right);
    inv(right,b);
    cout<<root<<"\n";
}
int main(){
    ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
    while(cin>>n[N++]){if(n[N-1]==0){N--;break;}};
    inv(0,N);
    return 0;
}
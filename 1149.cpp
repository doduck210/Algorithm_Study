#include <iostream>
#include <algorithm>
using namespace std;

int N;
long long rgb[2][3];

int main(){
    cin>>N;
    cin>>rgb[0][0]>>rgb[0][1]>>rgb[0][2];
    for(int i=1;i<N;i++){
        int r,g,b; cin>>r>>g>>b;
        rgb[1][0]=rgb[0][0]; rgb[1][1]=rgb[0][1]; rgb[1][2]=rgb[0][2];
        rgb[0][0]=(r+min(rgb[1][1],rgb[1][2]));
        rgb[0][1]=(g+min(rgb[1][0],rgb[1][2]));
        rgb[0][2]=(b+min(rgb[1][0],rgb[1][1]));
    }
    long long ans=rgb[0][0];
    ans=min(ans,rgb[0][1]); ans=min(ans,rgb[0][2]);
    cout<<ans<<"\n";
    return 0;
}
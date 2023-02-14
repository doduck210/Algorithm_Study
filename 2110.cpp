#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int N,C;
vector<int> houses;
int ans=0;

void input(){
    cin>>N>>C;
    for(int i=0;i<N;i++){
        int house; cin>>house;
        houses.push_back(house);
    }
    sort(houses.begin(),houses.end());
}

int main(){
    input();
    int l=0; //distance from first to first
    int r=houses.back()-houses.front();  //distance from frist to last
    while(l<=r){
        int mid=(l+r)/2; //standard distance
        int routerId=0;
        int routerCnt=1;
        for(int i=1;i<N;i++){
            if(houses[i]-houses[routerId]>=mid){ //if it is far enough than the standard 
                routerId=i;
                routerCnt++;
            }
        }
        if(routerCnt>=C) {ans=mid; l=mid+1;} //means distance should be larger
        if(routerCnt<C) r=mid-1; //distance should be smaller
    }
    cout<<ans<<"\n";
    return 0;
}
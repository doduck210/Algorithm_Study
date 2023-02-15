#include <iostream>
using namespace std;
int N,K;
int dur[200]={0,};  //if there's robot, value turns negative

int stages=0;

void input(){
    cin>>N>>K;
    for(int i=0;i<2*N;i++){
        cin>>dur[i];
    }
}

int getDown(int up){
    int down=(up+N-1)%(2*N);
    return down;
}

int main(){
    input();
    int up=0;
    int ans=1;
    while(1){
        //1st
        if(dur[getDown(up)]<0) {dur[getDown(up)]*=-1;dur[getDown(up)]-=1;} //down the last part
        up=(2*N+up-1)%(2*N);  //rotate
        if(dur[getDown(up)]<0) {dur[getDown(up)]*=-1;dur[getDown(up)]-=1;} //down the last part

        //2nd
        int down=getDown(up);
        for(int i=1;i<N;i++){
            int cur=(2*N+down-i)%(2*N), fo=(cur+1)%(2*N);
            if(dur[cur]<0&&dur[fo]>0){
                dur[fo]*=-1;
                dur[cur]*=-1; dur[cur]-=1;
            }
        }

        //3rd
        if(dur[up]>0) dur[up]*=-1;

        //4th
        int cnt=0;
        for(int i=0;i<2*N;i++){
            if(dur[i]==0||dur[i]==-1){
                cnt++;
            }
        }
        if(cnt>=K) break;
        else ans++;
    }

    cout<<ans<<"\n";

    return 0;
}
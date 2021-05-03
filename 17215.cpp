//https://www.acmicpc.net/problem/17215
#include <iostream>
#include <string>
#include <vector>
using namespace std;
int frame; //0~20 한프레임에 2번, 10프레임 보너스까지
string scoreboard; int len;
int ans=0;
int bonus[23]={0,};

void input(){
    cin>>scoreboard;
    len=scoreboard.size();
}
void solve(){
    int i;
    for(frame=0,i=0;frame<20;frame++,i++){ //9프레임까지
        int temp=0;
        if(scoreboard[i]=='S'){
            temp=10;
            bonus[frame+2]++;bonus[frame+3]++;
            if(bonus[frame+1]>0 && frame!=18){
                bonus[frame+2]++;
            }
            int bo=temp;
            while(bonus[frame]){
                temp+=bo;
                bonus[frame]--;
            }
            if(frame!=18)
                frame++;
        }
        else if(scoreboard[i]=='P'){
            int lastscore;
            if(scoreboard[i-1]=='-') lastscore=0;
            else lastscore=(int)scoreboard[i-1] - 48;
            temp=10-lastscore;
            bonus[frame+1]++;
            int bo=temp;
            while(bonus[frame]){
                temp+=bo;
                bonus[frame]--;
            }
        }
        else if(scoreboard[i]=='-'){
            temp=0;
        }
        else{
            temp=(int)scoreboard[i]-48;
            int bo=temp;
            while(bonus[frame]){
                temp+=bo;
                bonus[frame]--;
            }
        }
        ans+=temp;
        //cout<<"i : "<<i<<" cur : "<<temp<<" score : "<<ans<<"\n";
    }
    while(i<len){
        if(scoreboard[i]=='S') ans+=10;
        else if(scoreboard[i]=='P'){
            int lastscore;
            if(scoreboard[i-1]=='-') lastscore=0;
            else lastscore=(int)scoreboard[i-1] - 48;
            ans+= (10-lastscore);
        }
        else if(scoreboard[i]=='-') ans+=0;
        else ans+= ((int)scoreboard[i]-48);
        i++;
    }
    
}

int main(){
    input();
    solve();
    cout<<ans<<"\n";

    return 0;
}

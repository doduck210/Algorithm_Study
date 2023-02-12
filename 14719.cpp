#include <iostream>
#include <algorithm>
using namespace std;

int H,W;
int map[500];

bool d=true; //true - need to check it goes down, false - go up
int dH,uH,dId,uId;
int ans=0;

void input(){
    cin>>H>>W;
    for(int i=0;i<W;i++){
        cin>>map[i];
    }
}

void solution(){
    for(int i=0;i<W-1;i++){
        //go down check
        if(d&&map[i]>map[i+1]){
            dH=map[i];
            dId=i;
            d=false;
        }
        //go up check
        else if(!d&&map[i]<map[i+1]){
            while(i<W-1&&map[i]<=map[i+1]) i++;
            i--;
            uH=map[i+1];
            uId=i+1;
            int h=min(dH,uH);
            //cout<<dId+1<<" "<<uId+1<<":"<<dH<<" "<<uH<<endl;
            for(int j=dId+1;j<uId;j++){
                //cout<<max(0,h-map[j])<<",";
                ans+=max(0,h-map[j]);
                map[j]=max(h,map[j]);
            }
            //cout<<endl;
            if(dH<=uH) d=true;
        }
    }
}

int main(){
    input();
    solution();
    cout<<ans<<"\n";

    return 0;
}
#include <iostream>
#include <tuple>
#include <vector>
using namespace std;

int tc;
int n;
int m;
int w;
vector<tuple<int,int,int>> wires;

bool searching(){
    //가상노드 0만들고 여기서 모든곳으로 0으로 이어지게 함
    for(int i=1;i<=n;i++){
        wires.push_back({0,i,0});
    }
    vector<int> l(wires.size()+1,INT32_MAX);
    l[0]=0;
    for(int i=0;i<=n;i++){
        for(int j=0;j<wires.size();j++){
            int s, e, t;
            tie(s,e,t)=wires[j];
            if(l[s]!=INT32_MAX&&l[e]>t+l[s]){ //출발지까지 연결되어있고, 해당 길 이용해서 도착지 가는게 더 빠르면 업데이트
                l[e]=t+l[s];
                if(i==n) return true;  //n번째에서도 업데이트 된다면 어디선가 돌고있는것
            }
        }
    }
    return false;
}

void input(){
    cin>>tc;
    for(int i=0;i<tc;i++){
        //각각의 테스트케이스 시작
        cin>>n>>m>>w;
        wires.clear();
        for(int j=0;j<m;j++){
            int s, e, t; cin>>s>>e>>t;
            wires.push_back({s,e,t});
            wires.push_back({e,s,t});
        }
        for(int j=0;j<w;j++){
            int s, e, t; cin>>s>>e>>t;
            wires.push_back({s,e,-t});
        }
        if(searching()) cout<<"YES\n";
        else cout<<"NO\n";
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    input();

    return 0;
}
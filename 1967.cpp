//https://www.acmicpc.net/problem/1967
#include <iostream>
#include <utility>
#include <vector>
#include <algorithm>
using namespace std;

int n;

vector<pair<int,int>> table[10001];

int main(){
    cin>>n;
    //입력받고 테이블 채우기
    for(int i=0;i<n-1;i++){
        int parent, child, weight;
        cin>>parent>>child>>weight;
        
        //가중치 넣어주고
        table[child].push_back({parent,weight});
        
        //부모노드에 있는 가중치로 자식 거리 업데이트
        for(int j=0;j<table[parent].size();j++){
            int otherchild=table[parent][j].first;
            int otherweight=table[parent][j].second;
            
            table[child].push_back({otherchild,otherweight+weight});
            table[otherchild].push_back({child,otherweight+weight});
        }

        table[parent].push_back({child,weight});
    }
    
    /*디버깅용 각 노드별 거리 출력
    for(int i=1;i<=n;i++){
        cout<<"node "<<i<<endl;
        for(int j=0;j<table[i].size();j++){
            cout<<'<'<<table[i][j].first<<' '<<table[i][j].second<<">\n";
        }
        cout<<"\n";
    }
    */
   int ans=0;
    for(int i=1;i<=n;i++){
        for(int j=0;j<table[i].size();j++){
            ans=max(ans,table[i][j].second);
        }
    }
    cout<<ans<<'\n';

    return 0;
}
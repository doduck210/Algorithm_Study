#include <iostream>
#include <vector>
using namespace std;

int N,M;
int table[1025][1025];
vector<int> x1,y1,x2,y2;

void input(){
    cin>>N>>M;
    for(int i=1;i<=N;i++){
        table[i][0]=0;
        for(int j=1;j<=N;j++){
            int tmp; cin>>tmp;
            table[i][j]=table[i][j-1]+tmp;
        }
    }
    for(int i=0;i<M;i++){
        int xx1,xx2,yy1,yy2;
        cin>>xx1>>yy1>>xx2>>yy2;
        x1.push_back(xx1); y1.push_back(yy1);
        x2.push_back(xx2); y2.push_back(yy2);
    }
}

int main(){
    input();
    vector<long long> ans;
    for(int a=0;a<M;a++){
        long long tmp=0;
        for(int i=x1[a];i<=x2[a];i++){
            tmp+=(table[i][y2[a]]-table[i][y1[a]-1]);
        }
        ans.push_back(tmp);
    }

    for(int i=0;i<M;i++){
        cout<<ans[i]<<"\n";
    }

    return 0;
}
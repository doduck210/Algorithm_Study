//https://www.acmicpc.net/problem/15591
#include <iostream>
#include <vector>
using namespace std;
int N,Q;
int table[5001][5001]={0,};
vector<pair<int,int>> arr[5001];
bool visited[5001]={false,};
int Query[5000][2]; //[0]:k, [1]:v
int ans=0;
//int an[5000];

void input(){
    cin>>N>>Q;
    for(int i=0;i<N-1;i++){
        int p,q,r; cin>>p>>q>>r;
        arr[p].push_back({q,r});
        arr[q].push_back({p,r});
    }
    for(int i=0;i<Q;i++){
        cin>>Query[i][0]>>Query[i][1];
    }
}

void getusa(int k,int i){
    visited[i]=true;
    for(int j=0;j<arr[i].size();j++){
        if(!visited[arr[i][j].first]){
            visited[arr[i][j].first]=true;
            if(k<=arr[i][j].second){
                ans++;
                getusa(k,arr[i][j].first);
            }
        }
    }
}

void cleanvisit(){
    for(int i=1;i<=N;i++){
        visited[i]=false;
    }
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    input();

    for(int i=0;i<Q;i++){
        ans=0; cleanvisit();
        getusa(Query[i][0],Query[i][1]);
        //an[i]=ans;
        cout<<ans<<"\n";
    }

    //for(int i=0;i<Q;i++){
    //    cout<<an[i]<<"\n";
    //}

    return 0;
}
//https://www.acmicpc.net/problem/10451
#include <iostream>
using namespace std;

int n;
int table[1001];
bool visited[1001];

void clearvisit(){
    for(int i=1;i<=n;i++){
        visited[i]=false;
    }
}

int solution(){
    clearvisit();
    int cnt=0, ans=0;
    for(int i=1;i<=n;i++){
        int nexti=i;
        bool update=false;
        while(!visited[nexti]){
            visited[nexti]=true; cnt+=1; update=true;
            nexti=table[nexti];
        }
        if(update) ans+=1;
        if(cnt==n) break;
    }
    return ans;
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int k; cin>>k;
    for(int i=0;i<k;i++){
        cin>>n;
        for(int j=1;j<=n;j++){
            cin>>table[j];
        }
        cout<<solution()<<"\n";
    }

    return 0;
}
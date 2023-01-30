#include <iostream>
#include <vector>
using namespace std;

int N;
long long S;
int n[100000];
vector<long long> ns[100000];
int ans=100001;

void input(){
    cin>>N>>S;
    for(int i=0;i<N;i++){
        cin>>n[i];
    }
}

void solution(){
    for(int i=0;i<N;i++){
        if(n[i]>=S) {ans=1;break;}
        ns[i].push_back(n[i]);
        if(i==0) continue;

        for(int j=0;j<ns[i-1].size();j++){
            long long tmp=ns[i-1][j]+n[i];
            ns[i].push_back(tmp);
            if(tmp>=S){
                if(ans>ns[i].size()) ans=ns[i].size();
                break;
            }
        }
    }
}

int main(){
    input();
    solution();
    cout<<ans<<"\n";
    return 0;
}
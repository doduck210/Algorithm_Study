#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

int T;
vector<string> W;
vector<int> K;
int ma,mi;

void input(){
    cin>>T;
    for(int i=0;i<T;i++){
        string w; int k;
        cin>>w;
        cin>>k;
        W.push_back(w); K.push_back(k);
    }
}

void solve(string w, int k){
    ma=-1; mi=INT32_MAX;
    vector<int> alpha[123];

    for(int i=0;i<w.size();i++){
        alpha[w[i]].push_back(i);
        if(alpha[w[i]].size()>=k){
            ma=max(ma,i-alpha[w[i]][alpha[w[i]].size()-k]);
            mi=min(mi,i-alpha[w[i]][alpha[w[i]].size()-k]);
        }
    }
}

int main(){
    input();

    for(int i=0;i<T;i++){
        solve(W[i],K[i]);
        if(ma==-1) cout<<-1<<"\n";
        else cout<<mi+1<<" "<<ma+1<<"\n";
    }

    return 0;
}
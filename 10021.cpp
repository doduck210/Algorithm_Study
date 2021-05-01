//https://www.acmicpc.net/problem/10021 
#include <iostream>
#include <cmath>
#include <queue>
#include <algorithm>
using namespace std;
struct info{
    int from, to;
    long long val;
};
struct cmp {
    bool operator()(info& a, info& b){
        return a.val>b.val;
    }
};
info tmp;
int x[2001],y[2001],par[2001];

int find_par(int p){
    if(par[p]==p) return p;
    return par[p]=find_par(par[p]);
}

void make_union(int a,int b){
    a=find_par(a); b=find_par(b);
    if(a>b) par[a]=b;  //작은걸로 update
    else if (a<b) par[b]=a;
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int node,maxi,conn=0;
    long long result=0;
    cin>>node>>maxi;
    for(int i=1;i<=node;i++){
        cin>>x[i]>>y[i];
        par[i]=i;
    }
    priority_queue<info,vector<info>,cmp> pq;  //모든 간선정보 저장
    for(int i=1;i<node;i++){
        for(int j=i+1;j<=node;j++){
            long long dx=x[i]-x[j];
            long long dy=y[i]-y[j];
            long long v=dx*dx + dy*dy;
            tmp.from=i; tmp.to=j; tmp.val=v;
            pq.push(tmp);
        }
    }
    while(!pq.empty()){
        int cf=pq.top().from; int ct=pq.top().to; long long cv=pq.top().val;
        pq.pop();
        if(cv<maxi) continue;
        int pf=find_par(cf); int pt=find_par(ct);
        if(pf==pt) continue; //이미 처리되었다는 얘기
        make_union(cf,ct);
        result+=cv;
        conn++;
        if(conn==node-1) break;  //간선 개수가 n-1이면 다 연결 된것
    }
    if(conn!=node-1) result = -1;
    cout<<result<<"\n";

    return 0;
}

#include <iostream>
#include <vector>
#include <queue>
using namespace std;
int N,M;
queue<int> truth;
vector<int> person[50];
vector<int> party[50];
bool parties[50]={0,};
bool visited[50]={0,};

void input(){
    cin>>N>>M;
    int trN; cin>>trN;
    for(int i=0;i<trN;i++){
        int pers; cin>>pers; pers--;
        truth.push(pers);
    }
    for(int j=0;j<M;j++){
        int prN; cin>>prN;
        for(int i=0;i<prN;i++){
            int pers; cin>>pers; pers--;
            party[j].push_back(pers);
            person[pers].push_back(j);
        }   
    }
}

int main(){
    input();
    while(!truth.empty()){
        //get person
        int per=truth.front(); truth.pop(); visited[per]=1;
        //investigate which party did he visit
        for(int i=0;i<person[per].size();i++){
            int par=person[per][i];
            if(parties[par]) continue;
            parties[par]=true;
            //who else was there on the party
            for(int j=0;j<party[par].size();j++){
                int pers=party[par][j];
                if(visited[pers]) continue;
                visited[pers]=true;
                truth.push(pers);
            }
        }
    }
    int cnt=0;
    for(int i=0;i<M;i++){
        if(parties[i]) cnt++;
    }
    cout<<M-cnt<<"\n";

    return 0;
}
//https://www.acmicpc.net/problem/3197
#include <iostream>
#include <vector>
using namespace std;

int r,c;
char table[1500][1500];
bool visited[1500][1500];
bool finded=false;
int y,x;  //one duck's location
vector<int> nexty,nextx;

void clearVisit(){
    for(int i=0;i<r;i++){
        for(int j=0;j<c;j++){
            visited[i][j]=false;
        }
    }
}

void input(){
    cin>>r>>c;
    for(int i=0;i<r;i++){
        for(int j=0;j<c;j++){
            char temp;
            cin>>temp; table[i][j]=temp;
            if(temp=='L'){
                y=i; x=j;
            }
        }
    }
    table[y][x]='.';
}

void finding(int a,int b){
    if(finded) return;
    if(visited[a][b]) return;
    visited[a][b]=true;
    if(table[a][b]=='L'){
        finded=true;
        return;
    }
    if(table[a][b]=='X'){
        nexty.push_back(a); nextx.push_back(b);
        visited[a][b]=false;
        return;
    }
    if(a>0){
        finding(a-1,b);
    }
    if(a<r-1){
        finding(a+1,b);
    }
    if(b>0){
        finding(a,b-1);
    }
    if(b<c-1){
        finding(a,b+1);
    }
}

void melting(){
    char copy[1500][1500];
    for(int i=0;i<r;i++){
        for(int j=0;j<c;j++){
            copy[i][j]=table[i][j];
        }
    }
    for(int i=0;i<r;i++){
        for(int j=0;j<c;j++){
            if(copy[i][j]=='X'){
                if(i>0 && copy[i-1][j]!='X'){
                    table[i][j]='.';
                }
                else if(i<r-1 && copy[i+1][j]!='X'){
                    table[i][j]='.';
                }
                else if(j>0 && copy[i][j-1]!='X'){
                    table[i][j]='.';
                }
                else if(j<c-1 && copy[i][j+1]!='X'){
                    table[i][j]='.';
                }
            }
        }
    }
}

int main(){
    input();
    
    int ans=0;
    clearVisit();
    finding(y,x);
    while(!finded){
        //only find somewhere haven't been visited.
        vector<int> tempy,tempx;
        int n=nexty.size();
        //cout<<n<<"\n";
        for(int i=0;i<n;i++){
            tempy.push_back(nexty[i]);
            tempx.push_back(nextx[i]);
        }
        nexty.clear();nextx.clear();
        for(int i=0;i<n;i++){
            finding(tempy.back(),tempx.back());
            tempy.pop_back(); tempx.pop_back();
            if(finded) break;
        }
        if(finded) break;
        melting();
        ans++;
    }
    cout<<ans;
    
    return 0;
}
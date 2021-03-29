//https://www.acmicpc.net/problem/15685 
#include <iostream>
#include <vector>
using namespace std;

int table[101][101]={0};
int N;
vector<int> inputx, inputy, inputdir, gen;
vector<int> x, y;

void input(){
    cin>>N;
    for(int i=0;i<N;i++){
        int tempx, tempy, tempdir, tempgen;
        cin>>tempx>>tempy>>tempdir>>tempgen;
        inputx.push_back(tempx); inputy.push_back(tempy); 
        inputdir.push_back(tempdir); gen.push_back(tempgen);
    }
}

void gen0(int yy, int xx, int dir){
    table[yy][xx]=1;
    y.push_back(yy); x.push_back(xx);
    int dy[4]={0,-1,0,1};
    int dx[4]={1,0,-1,0};
    int nexty=yy+dy[dir], nextx=xx+dx[dir];
    table[nexty][nextx]=1;
    y.push_back(nexty); x.push_back(nextx);
}

void genN(int yy,int xx, int dir, int g){
    gen0(yy,xx,dir);
    for(int i=0;i<g;i++){
        int standy=y.back(), standx=x.back();
        int n=y.size()-2;
        for(int j=n;j>=0;j--){
            int nexty=standy-standx+x[j], nextx=standx+standy-y[j];
            table[nexty][nextx]=1; 
            y.push_back(nexty); x.push_back(nextx);
        }
    }
}

int score(){
    int ans=0;
    for(int i=0;i<100;i++){
        for(int j=0;j<100;j++){
            if(table[i][j]>0&&table[i+1][j]>0&&table[i][j+1]>0&&table[i+1][j+1]>0){
                ans++;
            }
        }
    }
    return ans;
}

int main(){
    input();

    for(int i=0;i<inputx.size();i++){
        genN(inputy[i],inputx[i],inputdir[i],gen[i]);
        x.clear(); y.clear();
    }

    cout<<score()<<"\n";
    return 0;
}
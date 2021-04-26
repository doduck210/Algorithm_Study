//https://www.acmicpc.net/problem/17822
#include <iostream>
#include <vector>
using namespace std;
int N,M,T;
int x[50],d[50],k[50];
int table[51][51];
bool visited[51][51]={false,};
vector<int> yy,xx;
int sum,cnt;
int ans=0;

void input(){
    cin>>N>>M>>T;
    for(int i=1;i<=N;i++){
        for(int j=1;j<=M;j++){
            cin>>table[i][j];
        }
    }
    for(int i=0;i<T;i++){
        cin>>x[i]>>d[i]>>k[i];
    }
}

void rotation(int row,int dir,int times){
    if(dir==0){
        for (int i = 0; i < times; i++){
            int temp = table[row][M];
            for (int j = M; j > 1; j--){
                table[row][j] = table[row][j - 1];
            }
            table[row][1] = temp;
        }
    }
    else{
        for (int i = 0; i < times; i++){
            int temp = table[row][1];
            for (int j = 0; j < M; j++){
                table[row][j] = table[row][j + 1];
            }
            table[row][M] = temp;
        }
    }
}

void findinject(){
    sum=0; cnt=0;
    for(int i=1;i<=N;i++){
        for(int j=1;j<=M;j++){
            if(table[i][j]==0){
                continue;
            }
            cnt++; sum+=table[i][j];
            //check right
            if(j<M && table[i][j]==table[i][j+1]){
                yy.push_back(i); xx.push_back(j);
                yy.push_back(i); xx.push_back(j+1);
            }
            if(j==M && table[i][j]==table[i][1]){
                yy.push_back(i); xx.push_back(j);
                yy.push_back(i); xx.push_back(1);
            }
            //check down
            if(i<N && table[i][j]==table[i+1][j]){
                yy.push_back(i); xx.push_back(j);
                yy.push_back(i+1); xx.push_back(j);
            }
        }
    }
}

void solve(){
    for(int a=0;a<T;a++){
        //1st step
        int multi=x[a];
        for(int b=2;multi<=N;b++){
            rotation(multi,d[a],k[a]);
            multi=x[a]*b;
        }
        //2nd step
        findinject();

        if(yy.size()==0 && cnt>0){
            float mean=(float)sum/cnt;
            for(int i=1;i<=N;i++){
                for(int j=1;j<=M;j++){
                    if(table[i][j]>mean){
                        table[i][j]--;
                    }
                    else if(table[i][j]<mean && table[i][j]>0){
                        table[i][j]++;
                    }
                }
            }
        }
        else{
            for(int i=0;i<yy.size();i++){
                table[yy[i]][xx[i]]=0;
            }
        }
        yy.clear(); xx.clear();
    }
    for(int i=1;i<=N;i++){
        for(int j=1;j<=M;j++){
            ans+=table[i][j];
        } 
    }
}

int main(){
    input();
    solve();
    cout<<ans<<"\n";

    return 0;
}
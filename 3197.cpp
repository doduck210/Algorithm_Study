#include <iostream>
using namespace std;

int r,c;
char table[1500][1500];
bool visited[1500][1500];
bool finded=false;
int y,x;  //one duck's location

void clearVisit(){
    for(int i=0;i<r;i++){
        for(int j=0;j<c;j++){
            visited[i][j]=false;
        }
    }
    visited[y][x]=true;
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
    visited[a][b]=true;
    if(table[a][b]=='L'){
        finded=true;
        return;
    }
    if(a>0 && table[a-1][b]!='X' && !visited[a-1][b]){
        finding(a-1,b);
    }
    if(a<r-1 && table[a+1][b]!='X' && !visited[a+1][b]){
        finding(a+1,b);
    }
    if(b>0 && table[a][b-1]!='X' && !visited[a][b-1]){
        finding(a,b-1);
    }
    if(b<c-1 && table[a][b+1]!='X' && !visited[a][b+1]){
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
                if(i>0 && copy[i-1][j]!='X')
                    table[i][j]='.';
                else if(i<r-1 && copy[i+1][j]!='X')
                    table[i][j]='.';
                else if(j>0 && copy[i][j-1]!='X')
                    table[i][j]='.';
                else if(j<c-1 && copy[i][j+1]!='X')
                    table[i][j]='.';
            }
        }
    }
}

int main(){
    input();
    
    int ans=0;
    while(true){
        /*
        cout<<"\n";
        for(int i=0;i<r;i++){
            for(int j=0;j<c;j++){
                cout<<table[i][j];
            } cout<<"\n";
        } cout<<"\n";
        */
        clearVisit();
        finding(y,x);
        if(finded) break;
        melting();
        ans++;
    }
    cout<<ans;
    
    return 0;
}
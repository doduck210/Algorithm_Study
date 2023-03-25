#include <iostream>
#include <string>
#include <vector>
using namespace std;

vector<string> cases;
vector<string> ans;

void input(){
    while(1){
        string tmp; cin>>tmp;
        if(tmp=="end") break;
        cases.push_back(tmp);
    }
}

void solution(){
    for(int i=0;i<cases.size();i++){
        int cntO=0,cntX=0,cntBingo=0, xBingo=0, cBingo=0;
        for(int j=0;j<9;j++){
            if(cases[i][j]=='O') cntO++;
            else if(cases[i][j]=='X') cntX++;
        }
        if(cntX-cntO!=0&&cntX-cntO!=1){
            ans.push_back("invalid");
            continue;
        }
        //row
        if(cases[i][0]!='.'&&cases[i][0]==cases[i][1]&&cases[i][0]==cases[i][2]) {cntBingo++;if(cases[i][0]=='X') xBingo++;}
        if(cases[i][3]!='.'&&cases[i][3]==cases[i][4]&&cases[i][3]==cases[i][5]) {cntBingo++;if(cases[i][3]=='X') xBingo++;}
        if(cases[i][6]!='.'&&cases[i][6]==cases[i][7]&&cases[i][6]==cases[i][8]) {cntBingo++;if(cases[i][6]=='X') xBingo++;}
        //column
        if(cases[i][0]!='.'&&cases[i][0]==cases[i][3]&&cases[i][0]==cases[i][6]) {cntBingo++;if(cases[i][0]=='X') xBingo++;}
        if(cases[i][1]!='.'&&cases[i][1]==cases[i][4]&&cases[i][1]==cases[i][7]) {cntBingo++;if(cases[i][1]=='X') xBingo++;}
        if(cases[i][2]!='.'&&cases[i][2]==cases[i][5]&&cases[i][2]==cases[i][8]) {cntBingo++;if(cases[i][2]=='X') xBingo++;}
        //cross
        if(cases[i][0]!='.'&&cases[i][0]==cases[i][4]&&cases[i][0]==cases[i][8]) {cntBingo++;cBingo++;if(cases[i][0]=='X') xBingo++;}
        if(cases[i][2]!='.'&&cases[i][2]==cases[i][4]&&cases[i][2]==cases[i][6]) {cntBingo++;cBingo++;if(cases[i][2]=='X') xBingo++;}
        //both has bingo?
        if(xBingo>0&&cntBingo>xBingo){
            ans.push_back("invalid");
            continue;
        }
        //not final status?
        if(cntBingo==0&&cntX<5){
            ans.push_back("invalid");
            continue;
        }
        //O win but X has continued?
        if(cntBingo>xBingo&&cntX-cntO==1){
            ans.push_back("invalid");
            continue;
        }
        //X win but O has continued?
        if(cntBingo==xBingo&&cntX-cntO==0){
            ans.push_back("invalid");
            continue;
        }
        //otherwise it's valid
        ans.push_back("valid");
    }
}

int main(){
    input();
    solution();
    for(int i=0;i<ans.size();i++){
        cout<<ans[i]<<'\n';
    }
    return 0;
}
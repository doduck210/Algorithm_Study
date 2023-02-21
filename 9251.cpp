#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
string s1, s2;
int table[1001][1001];
//dynamic programming
int main(){
    cin>>s1>>s2;
    //initialize edge
    for(int i=0;i<=s1.size();i++){
        table[0][i]=0;
    }
    for(int i=0;i<=s2.size();i++){
        table[i][0]=0;
    }
    //fill table
    for(int i=1;i<=s2.size();i++){
        char l2=s2[i-1];
        for(int j=1;j<=s1.size();j++){
            char l1=s1[j-1];
            int r=table[i][j-1], c=table[i-1][j];
            if(l2==l1) table[i][j]=table[i-1][j-1]+1;
            else table[i][j]=max(r,c);
        }
    }
    //the end of the table is the LCS
    cout<<table[s2.size()][s1.size()]<<"\n";
    return 0;
}
#include <iostream>
using namespace std;

int N;
pair<char,char> tree[26];

void input(){
    cin>>N;
    for(int i=0;i<N;i++){
        //char 'A'==65
        char node; cin>>node;
        char left, right; cin>>left>>right;
        tree[node-65]={left,right};
    }
}

void preOrder(int node){
    cout<<(char)(node+65);
    if(tree[node].first!='.'){
        preOrder(tree[node].first-65);
    }
    if(tree[node].second!='.'){
        preOrder(tree[node].second-65);
    }
}

void inOrder(int node){
    if(tree[node].first!='.'){
        inOrder(tree[node].first-65);
    }
    cout<<(char)(node+65);
    if(tree[node].second!='.'){
        inOrder(tree[node].second-65);
    }
}

void postOrder(int node){
    if(tree[node].first!='.'){
        postOrder(tree[node].first-65);
    }
    if(tree[node].second!='.'){
        postOrder(tree[node].second-65);
    }
    cout<<(char)(node+65);

}

int main(){
    input();
    preOrder(0); cout<<"\n";
    inOrder(0); cout<<"\n";
    postOrder(0); cout<<"\n";

    return 0;
}
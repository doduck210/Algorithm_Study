//https://www.acmicpc.net/problem/10830
#include <iostream>
#include <vector>
using namespace std;

typedef long long ll;
typedef vector<vector<int>> matrix;

int n; ll b;

matrix operator*(const matrix &a,const matrix &b){
    matrix res(n,vector<int>(n));
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            for(int c=0;c<n;c++){
                res[i][j]+=a[i][c]*b[c][j];
            }
            res[i][j]%=1000;
        }
    }
    return res;
}

matrix power(matrix a,ll r){
    matrix res(n,vector<int>(n));
    for(int i=0;i<n;i++) res[i][i]=1;  //make it as unit matrix
    while(r>0){
        if(r%2==1){
            res=res*a;
        }
        r/=2;
        a=a*a;
    }
    return res;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin>>n>>b;
    matrix origin(n,vector<int>(n));

    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin>>origin[i][j];
        }
    }
    
    matrix ans=power(origin,b);
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cout<<ans[i][j]<<" ";
        } cout<<"\n";
    }

    return 0;
}
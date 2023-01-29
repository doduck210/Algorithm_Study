#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N;
vector<int> nums;

void input(){
    cin>>N;
    for(int i=0;i<N;i++){
        int n; cin>>n;
        nums.push_back(n);
    }
    sort(nums.begin(),nums.end());
}

int solve(){
    int ans=0;
    for(int i=0;i<N;i++){
        int val=nums[i];
        int l=0,r=N-1;
        while(l<r){
            if(l==i){l++;continue;} if(r==i){r--;continue;}
            int sum=nums[l]+nums[r];
            if(sum<val) l++;
            else if(sum==val){ans++; break;}
            else r--;
        }
    }
    return ans;
}

int main(){
    input();
    cout<<solve()<<"\n";
    return 0;
}
//https://school.programmers.co.kr/learn/courses/30/lessons/42889#
#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

bool compare(pair<int,float> a,pair<int,float> b){
    if(a.second==b.second){
        return a.first<b.first;
    }
    else{
        return a.second>b.second;
    }
}

vector<int> solution(int N, vector<int> stages) {
    vector<int> ans;
    vector<double> failRate;
    sort(stages.begin(),stages.end());
    
    int cur=0;
    for(int i=1;i<=N;i++){
        int prev=cur;
        float tot=stages.size()-prev;
        while(cur<stages.size()&&stages[cur]<=i){
            cur++;
        }
        if(tot==0){
            failRate.push_back(0);
        }
        else{
            double tmp=((double)(cur-prev) / (double)tot);
            //cout<<i<<"\n"<<(cur-prev)<<" "<<tot<<" "<<tmp<<endl;
            failRate.push_back(tmp);
        }
    }
    vector<pair<int,double>> rate;
    for(int i=0;i<N;i++){
        rate.push_back({i+1,failRate[i]});
    }
    sort(rate.begin(),rate.end(),compare);
    for(int i=0;i<N;i++){
        //cout<<rate[i].first<<" "<<rate[i].second<<endl;
        ans.push_back(rate[i].first);
    }
    return ans;
}
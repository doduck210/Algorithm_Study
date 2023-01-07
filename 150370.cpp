//https://school.programmers.co.kr/learn/courses/30/lessons/150370
#include <string>
#include <vector>
#include <iostream>
using namespace std;

vector<int> solution(string today, vector<string> terms, vector<string> privacies) {
    vector<int> ans;
    string todayDate=today.substr(0,4)+today.substr(5,2)+today.substr(8,2);
    
    for(int i=0;i<privacies.size();i++){
        char category=privacies[i][11];
        int month=stoi(privacies[i].substr(5,2));
        int year=stoi(privacies[i].substr(0,4));
        int day=stoi(privacies[i].substr(8,2));
        for(int j=0;j<terms.size();j++){
            if(category==terms[j][0]) {
                month+=stoi(terms[j].substr(2,20));
                break;
            }
        }
        day--;
        if(day==0){
            month--;
            day=28;
        }
        while(month>12){
            month-=12;
            year++;
        }
        string expireDate=to_string(year);
        if(month<10) expireDate+='0';
        expireDate+=to_string(month);
        if(day<10) expireDate+='0';
        expireDate+=to_string(day);
        cout<<"Today = "<<todayDate<<" Expire = "<<expireDate<<endl;
        if(todayDate>expireDate){
            ans.push_back(i+1);
        }
    }
    return ans;
}
//https://programmers.co.kr/learn/courses/30/lessons/42840

#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> answers) {
    int score1=0; int score2=0; int score3=0;
    
    vector<int> fir={1,2,3,4,5}; vector<int> sec={2,1,2,3,2,4,2,5}; vector<int> thi={3,3,1,1,2,2,4,4,5,5};
    
    for(int i=0;i<answers.size();i++){
        int iter1=i%fir.size(); int iter2=i%sec.size(); int iter3=i%thi.size();
        if(answers[i]==fir[iter1])
            score1++;
        if(answers[i]==sec[iter2])
            score2++;
        if(answers[i]==thi[iter3])
            score3++;
    }
    
    vector<int> answer;
    int m=max(score1,score2);
    m=max(m,score3);
    if(m==score1)
        answer.push_back(1);
    if(m==score2)
        answer.push_back(2);
    if(m==score3)
        answer.push_back(3);
    
    return answer;
}
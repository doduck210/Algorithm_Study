//https://www.acmicpc.net/problem/2607
#include <iostream>
#include <string>
#include <vector>
using namespace std;

int n;
vector<string> s;
int cnt = 0;

//'A'=65 , 'Z'=90;
int charCnt[26] = { 0, };
int charCntCmp[26] = { 0, };

void input() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        string t; cin >> t;
        s.push_back(t);
    }  
    for (int i = 0; i < s[0].size(); i++) {
        charCnt[s[0][i] - 65]++;
        charCntCmp[s[0][i] - 65]++;
    }
}

int cntCnt() {
    int r = 0;
    bool tmpA = false, tmpB = false;
    for (int i = 0; i < 26; i++) {
        if (charCntCmp[i] < 0) {
            tmpA = true;
            r += ((-1) * charCntCmp[i]);
        }
        else if (charCntCmp[i] > 0) {
            tmpB = true;
            r += charCntCmp[i];
        }
        charCntCmp[i] = charCnt[i];
    }
    if (tmpA && tmpB) r--;
    return r;
}

void check() {
    for (int i = 1; i < n; i++) {
        if ((int)s[0].size() - (int)s[i].size() < -1 || (int)s[0].size() - (int)s[i].size() > 1) continue;
        for (int j = 0; j < s[i].size(); j++) {
            charCntCmp[s[i][j] - 65]--;
        }
        if (cntCnt() < 2) {
            cnt++;
        }
    }
}

int main() {   
    input();
    check();
    cout << cnt << endl;
    return 0;
}

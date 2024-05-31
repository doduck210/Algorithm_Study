//https://www.acmicpc.net/problem/11053
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N;
vector<int> A;
vector<int> increaseCnt;

void input() {
	cin >> N;
	for (int i = 0; i < N; i++) {
		int tmp; cin >> tmp;
		A.push_back(tmp);
		increaseCnt.push_back(0);
	}
}

void getIncreaseCnt() {
	for (int i = 1; i < N; i++) {
		for (int j = 0; j < i; j++) {
			if (A[j] >= A[i]) continue;
			increaseCnt[i] = max(increaseCnt[i], increaseCnt[j] + 1);
		}
	}
}

int main() {
	input();
	getIncreaseCnt();
	int ans = 0;
	for (int i = 0; i < N; i++) {
		ans = max(ans, increaseCnt[i]);
	}
	cout << ans + 1;
	return 0;
}
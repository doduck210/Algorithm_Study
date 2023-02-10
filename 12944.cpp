#include <string>
#include <vector>

using namespace std;

double solution(vector<int> arr) {
    double ans = 0;
    long long sum=0;
    for(int i=0;i<arr.size();i++){
        sum+=arr[i];
    }
    ans=(double)sum/arr.size();
    return ans;
} 
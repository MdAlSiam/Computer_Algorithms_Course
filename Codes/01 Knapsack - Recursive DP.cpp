#include <bits/stdc++.h>
using namespace std;

int wt[] = {1, 3, 4, 5};
int val[] = {1, 4, 5, 7};

int n = sizeof(wt) / sizeof(wt[0]);

int max_wt = 7;

int dp[1000][1000];

int call(int index, int curr_total){
    if(dp[index][curr_total] != -1) return dp[index][curr_total];
    if(index == n) return 0;
    if(curr_total == 0) return 0;

    int ret1;
    int ret2;

    ret1 = ret2 = 0;

    if(curr_total-wt[index] >= 0){
        ret1 = val[index] + call(index+1, curr_total-wt[index]);
    }

    ret2 = call(index+1, curr_total);

    return dp[index][curr_total] = max(ret1, ret2);
}

int main(){
    memset(dp, -1, sizeof(dp));
    int ans = call(0, max_wt);
    printf("Maximum value can be obtained: %d\n", ans);
}

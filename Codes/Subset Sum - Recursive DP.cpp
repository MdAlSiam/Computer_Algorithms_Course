#include <bits/stdc++.h>
using namespace std;

int num[] = {9, 6, 3, 7};

int n = sizeof(num) / sizeof(num[0]);

int target;

int dp[1000][1000];

bool call(int index, int curr_sum){
    if(dp[index][curr_sum] != -1) return dp[index][curr_sum];
    if(curr_sum == target) return true;
    if(index == n) return false;

    bool ret1;
    bool ret2;

    ret2 = ret1 = false;

    ret1 = call(index+1, curr_sum+num[index]);

    ret2 = call(index+1, curr_sum);

    return dp[index][curr_sum] = ret1 | ret2;
}

int main(){
    while(scanf("%d", &target) == 1){
        memset(dp, -1, sizeof(dp));
        if(call(0, 0))
            printf("Possible to make %d\n", target);
        else printf("Not possible to make %d\n", target);
    }
}

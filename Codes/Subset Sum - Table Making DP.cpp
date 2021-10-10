#include <bits/stdc++.h>
using namespace std;

int num[] = {9, 6, 3, 7};

bool dp[1000][1000];

int main(){
    int n = sizeof(num) / sizeof(num[0]);

    int target;

    while(scanf("%d", &target) == 1){

        for(int i = 0; i <= n; i++){
            for(int j = 0; j <= target; j++){
                if(i == 0 && j == 0) dp[i][j] = true;
                else if(i == 0) dp[i][j] = false;
                else if(j == 0) dp[i][j] = true;
                else if(j < num[i-1]) dp[i][j] = dp[i-1][j];
                else dp[i][j] = dp[i-1][j-num[i-1]] | dp[i-1][j];
            }
        }

        if(dp[n][target]) printf("Possible to make %d\n", target);
        else printf("Not possible to make %d\n", target);

    }

}


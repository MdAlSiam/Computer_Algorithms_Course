#include <bits/stdc++.h>
using namespace std;

int wt[] = {1, 3, 4, 5};
int val[] = {1, 4, 5, 7};

int dp[1000][1000];

int main(){
    int n = sizeof(wt) / sizeof(wt[0]);

    int max_wt = 7;

    for(int i = 0; i <= n; i++){
        for(int j = 0; j <= max_wt; j++){
            if(i == 0 || j == 0) dp[i][j] = 0;
            else if(j < wt[i-1]) dp[i][j] = dp[i-1][j];
            else dp[i][j] = max(val[i-1]+dp[i-1][j-wt[i-1]], dp[i-1][j]);
        }
    }

    for(int i = 0; i <= n; i++)
        for(int j = 0; j <= max_wt; j++)
            printf((j == max_wt) ? "%d\n" : "%d ", dp[i][j]);

    printf("Maximum value can be obtained: %d\n", dp[n][max_wt]);

}